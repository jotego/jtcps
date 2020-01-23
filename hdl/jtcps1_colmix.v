/*  This file is part of JTCPS1.
    JTCPS1 program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    JTCPS1 program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with JTCPS1.  If not, see <http://www.gnu.org/licenses/>.

    Author: Jose Tejada Gomez. Twitter: @topapate
    Version: 1.0
    Date: 13-1-2020 */
    
`timescale 1ns/1ps

// Brightness only affects the gain of the signal, not the offset
// Depending on the impedance of the 74'07 device, the maximum
// attenuation can be as much as 40% for brightness setting of 15
// If NMOS RON is comparable to the R2R ladder, attenuation will be
// lower (~27%)

module jtcps1_colmix(
    input              rst,
    input              clk,
    input              pxl_cen,

    input              VB,
    input              HB,

    input   [8:0]      scr1_pxl,
    input   [8:0]      scr2_pxl,
    input   [8:0]      scr3_pxl,

    output reg [7:0]  red,
    output reg [7:0]  green,
    output reg [7:0]  blue
);

reg [ 8:0] pxl;
reg [11:0] pal_addr;

// Palette
reg [15:0] pal[0:(2**12)-1]; // 4096?
reg [15:0] raw;
wire [3:0] raw_r, raw_g, raw_b, raw_br;

assign raw_br = raw[15:12];
assign raw_r  = raw[11: 8];
assign raw_g  = raw[ 7: 4];
assign raw_b  = raw[ 3: 0];

// These are the top four bits written by CPS-B to each
// pixel of the frame buffer. These are likely sent by CPS-A
// via pins XS[4:0] and CPS-B encodes them
// 000 = OBJ ?
// 001 = SCROLL 1
// 010 = SCROLL 2
// 011 = SCROLL 3
// 000 = STAR FIELD?
reg [2:0] pxl_type;

// simple layer priority for now:
always @(*) begin
    //pxl      = scr1_pxl;
    //pxl_type = 3'b01;
    //pxl      = scr2_pxl;
    //pxl_type = 3'b10;

    if( scr1_pxl[3:0] != 4'hf ) begin
        pxl      = scr1_pxl;
        pxl_type = 3'b1;
    end else if(scr2_pxl[3:0] != 4'hf ) begin
        pxl      = scr2_pxl;
        pxl_type = 3'b10;
    end else begin
        pxl = scr3_pxl;
        pxl_type = 3'b011;
    end
    pal_addr = { pxl_type, pxl };
end

`ifdef SIMULATION
initial begin
    $readmemh("pal16.hex",pal);
end
`endif

always @(posedge clk ) begin
    raw <= pal[pal_addr];
end

reg [7:0] mul_r, mul_g, mul_b;
wire [3:0] inv_br = ~raw_br; // if operator ~ is mixed in the multiplication
    // it seems to extend the sign or the bit width and
    // the result is wrong

// Use multiplier for brightness as these
// are cheap in most FPGAs
always @(posedge clk, posedge rst) begin
    if(rst) begin
        mul_r <= 8'd0;
        mul_g <= 8'd0;
        mul_b <= 8'd0;
    end else begin
        mul_r <= raw_r * inv_br; // mul = signal * 15
        mul_g <= raw_g * inv_br;
        mul_b <= raw_b * inv_br;
    end
end

always @(posedge clk, posedge rst) begin
    if(rst) begin
        red   <= 8'd0;
        green <= 8'd0;
        blue  <= 8'd0;
    end else if(pxl_cen) begin
        // signal * 17 - signal*15/4 = signal * (17-15/4-15/8)
        // 33% max attenuation for brightness
        red   <= {2{raw_r}} - (mul_r>>2) - (mul_r>>3); // - (mul_r>>4);
        green <= {2{raw_g}} - (mul_g>>2) - (mul_g>>3); // - (mul_g>>4);
        blue  <= {2{raw_b}} - (mul_b>>2) - (mul_b>>3); // - (mul_b>>4);
    end
end

endmodule
