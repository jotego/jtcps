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

// Scroll 1 is 512x512, 8x8 tiles
// Scroll 2 is 1024x1024 16x16 tiles
// Scroll 3 is 2048x2048 32x32 tiles

module jtcps1_tilemap(
    input              rst,
    input              clk,

    input      [ 8:0]  v,
    // control registers
    input      [15:0]  vram_base,
    input      [15:0]  hpos,
    input      [15:0]  vpos,

    input              start,
    output reg         done,

    output reg [23:1]  vram_addr,
    input      [15:0]  vram_data,
    input              vram_ok,
    output reg         vram_cs,

    output reg [22:0]  rom_addr,    // up to 1 MB
    output             rom_half,    // selects which half to read
    input      [31:0]  rom_data,
    output reg         rom_cs,
    input              rom_ok,

    output reg [ 8:0]  buf_addr,
    output reg [ 8:0]  buf_data,
    output reg         buf_wr
);

parameter SIZE=8; // 8, 16 or 32

reg [10:0] vn;
reg [10:0] hn;
reg [31:0] pxl_data;

reg [ 5:0] st;

reg [21:0] tile_addr;
reg [15:0] code,attr;

wire [11:0] scan;
wire [ 2:0] rom_id;

case(SIZE)
    8:  begin
        assign scan = { vn[8],   hn[8:3], vn[7:3] };
        assign rom_id = 3'b001;
    end
    16: begin
        assign scan = { vn[9:8], hn[9:4], vn[7:4] };
        assign rom_id = 3'b010;
    end
    32: begin
        assign scan = { vn[10:8], hn[10:5], vn[7:5] };
        assign rom_id = 3'b011;
    end
endcase

function [3:0] colour;
    input [31:0] c;
    input        flip;
    colour = flip ? { c[24], c[16], c[ 8], c[0] } : 
                    { c[31], c[23], c[15], c[7] };
endfunction

wire     vflip = attr[6];
wire     hflip = attr[5];
wire [4:0] pal = attr[4:0];

assign rom_half = hn[3] ^ hflip;

always @(posedge clk or posedge rst) begin
    if(rst) begin
        rom_cs          <= 1'b0;
        vram_cs         <= 1'b0;
        buf_wr          <= 1'b0;
        done            <= 1'b0;
        st              <= 0;
        rom_addr[22:20] <= rom_id; // constant value
    end else begin
        st <= st+1;
        case( st ) 
            0: begin
                rom_cs   <= 1'b0;
                vram_cs  <= 1'b0;
                vn       <= vpos + v;
                hn       <= SIZE == 8 ? {hpos[10:3],3'd0} :
                    ( SIZE==16 ? { hpos[10:4], 4'd0 } :
                        { hpos [10:5], 5'd0 } );
                buf_addr <= 9'd0-hpos[2:0];
                buf_wr   <= 1'b0;
                if(!start) begin
                    st   <= 0;
                    done <= 1'b0;
                end
            end
            1: begin
                vram_addr <= { vram_base, 7'd0 } + { 11'd0, scan, 1'b0};
                vram_cs   <= 1'b1;
                if( buf_addr>= 9'd383+9'd64 ) begin
                    buf_wr <= 1'b0;
                    done   <= 1'b1;
                    st     <= 0;
                end
            end
            3: if( vram_ok ) begin
                code         <= vram_data;
                vram_addr[1] <= 1'b1;
                st <= 50;
            end else st<=st;
            51: if( vram_ok ) begin
                attr    <= vram_data;
                vram_cs <= 1'b0;
                st <= 4;
            end else st<=st;
            4: begin
                case (SIZE)
                    8:  begin
                        rom_addr[19:0] <= { 1'b0, code, vn[2:0] ^ {3{vflip}} };
                    end
                    16: begin
                        rom_addr[19:0] <= { code, vn[3:0] ^{4{vflip}} };
                    end
                    32: rom_addr[19:0] <= { code[13:0], vn[4:0] ^{5{vflip}}, ~hflip };
                endcase
                rom_cs    <= 1'b1;
            end
            6: if(rom_ok) begin
                pxl_data <= rom_data;   // 32 bits = 32/4 = 8 pixels
                hn <= hn + 10'd8;
            end else st<=6;
            7,8,9,10,    11,12,13,14, 
            16,17,18,19, 20,21,22,23,
            25,26,27,28, 29,30,31,32,
            34,35,36,37, 38,39,40,41: begin
                buf_wr   <= 1'b1;
                buf_addr <= buf_addr+9'd1;
                buf_data <= { pal, colour(pxl_data, hflip) };
                pxl_data <= hflip ? pxl_data>>1 : pxl_data<<1;
            end
            15: begin
                if( SIZE==8 ) begin
                    st <= 1; // scan again
                end else if(rom_ok) begin
                    pxl_data <= rom_data;
                    hn <= hn + 10'd8;    // pixels 8-15
                    if(SIZE==32)
                        rom_addr[19:0] <= { code[13:0], vn[4:0] ^{5{vflip}}, hflip };
                end else st<=st;
            end
            24: begin
                if( SIZE==16 ) begin
                    st <= 1; // scan again
                end else if(rom_ok) begin
                    pxl_data <= rom_data;
                    hn <= hn + 10'd8; // pixels 16-23
                end else st<=st;
            end
            33: begin
                pxl_data <= rom_data;
                hn <= hn + 10'd8; // pixels 24-31
            end
            42: st <= 1; // end
        endcase
    end
end

endmodule