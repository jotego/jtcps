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

// To do:
// 1. Copy only the marked pages
// 2. Bus arbitrion with main CPU --> check PCB

module jtcps1_colmix(
    input              rst,
    input              clk,
    input              pxl_cen,

    input              VB,
    input              HB,
    output  reg        LVBL_dly,
    output  reg        LHBL_dly,

    input   [8:0]      scr1_pxl,
    input   [8:0]      scr2_pxl,
    input   [8:0]      scr3_pxl,
    input   [8:0]      obj_pxl,

    // Palette copy
    input              pal_copy,
    input   [15:0]     pal_base,

    // VRAM access
    output reg [17:0]  vram_addr,
    input      [15:0]  vram_data,
    input              vram_ok,
    output reg         vram_cs,

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

    if( obj_pxl[3:0] != 4'hf ) begin
        pxl = obj_pxl;
        pxl_type=3'b0;
    end else if( scr1_pxl[3:0] != 4'hf ) begin
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
integer f, rd_cnt;
initial begin
    //$readmemh("pal16.hex",pal);
    f=$fopen("pal.bin","rb");
    if(f==0) begin
        $display("WARNING: cannot open file pal16.hex");
        // no palette file, initialize with zeros
        for( rd_cnt = 0; rd_cnt<4096; rd_cnt=rd_cnt+1 ) pal[rd_cnt] <= 16'd0;
    end else begin
        rd_cnt = $fread(pal,f);
        $display("INFO: read %d bytes from pal.bin",rd_cnt);
        $fclose(f);
        //$finish;
    end
end
`endif

// Palette copy
reg [11:0] pal_cnt;
reg [ 4:0] pal_st;
reg        wait_ok;

always @(posedge clk, posedge rst) begin
    if( rst ) begin
        raw       <= 16'h0;
        pal_cnt   <= 12'd0;
        pal_st    <= 4'd1;
        vram_cs   <= 1'b0;
        vram_addr <= 23'd0;
        wait_ok   <= 1'b0;
    end else begin
        raw <= pal[pal_addr];
        if( pal_copy && pal_st[0] ) begin
            vram_cs <= 1'b1;
            wait_ok <= 1'b0;
        end
        if( vram_cs ) begin
            pal_st <= { pal_st[3:0], pal_st[4] };
        end else pal_st <= 5'b1;
        case( pal_st )
            5'b0001: begin
                vram_addr <= { pal_base[10:0], 7'd0 } + pal_cnt;
            end
            // 4'b0010: wait for OK signal to go down in reaction to the change
            // in vram_addr
            5'b1000: if(vram_ok) begin
                pal[pal_cnt] <= vram_data;
                wait_ok <= 1'b0;
                if( &pal_cnt ) begin
                    vram_cs <= 1'b0;
                end
            end else pal_st <= pal_st;
            5'b1_0000: pal_cnt <= pal_cnt + 1;
        endcase

    end
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

reg vb1, hb1;

always @(posedge clk, posedge rst) begin
    if(rst) begin
        red   <= 8'd0;
        green <= 8'd0;
        blue  <= 8'd0;
        vb1   <= 1'b1;
        hb1   <= 1'b1;
    end else if(pxl_cen) begin
        vb1   <= VB;
        hb1   <= HB;
        LVBL_dly <= ~vb1;
        LHBL_dly <= ~hb1;
        // signal * 17 - signal*15/4 = signal * (17-15/4-15/8)
        // 33% max attenuation for brightness
        if( vb1 || hb1 ) begin
            red   <= 8'd0;
            green <= 8'd0;
            blue  <= 8'd0;
        end else begin
            red   <= {2{raw_r}} - (mul_r>>2) - (mul_r>>3); // - (mul_r>>4);
            green <= {2{raw_g}} - (mul_g>>2) - (mul_g>>3); // - (mul_g>>4);
            blue  <= {2{raw_b}} - (mul_b>>2) - (mul_b>>3); // - (mul_b>>4);
        end
    end
end

endmodule
