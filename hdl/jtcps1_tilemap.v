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

    input      [ 7:0]  vrender, // 1 line ahead of vdump
    input      [ 7:0]  vdump,
    input      [ 8:0]  hdump,
    // control registers
    input      [15:0]  vram_base,
    input      [15:0]  hpos,
    input      [15:0]  vpos,

    input              start,

    output reg [23:1]  vram_addr,
    input      [15:0]  vram_data,
    input              vram_ok,
    output reg         vram_cs,

    output reg [22:0]  rom_addr,    // up to 1 MB
    output             rom_half,    // selects which half to read
    input      [31:0]  rom_data,
    output reg         rom_cs,
    input              rom_ok,

    output reg [ 8:0]  pxl
);

parameter SIZE=8; // 8, 16 or 32

localparam CACHE_AW  = SIZE==8 ?  9 : ( SIZE==16 ? 8 : 7 );
localparam CACHE_XW  = SIZE==8 ?  3 : ( SIZE==16 ? 4 : 5 ); // ignore these bits from V
localparam TILECNTW  = SIZE==8 ?  6 : ( SIZE==16 ? 5 : 4 );
localparam TILEMAX   = SIZE==8 ? 57 : ( SIZE==16 ? 29: 15);
localparam SCRW      = CACHE_XW;

reg [10:0] vn;
reg [10:0] hn;
reg [31:0] pxl_data;

reg [ 5:0] st;
reg [TILECNTW-1:0] tilecnt;

reg [21:0] tile_addr;
reg [15:0] code,attr;

wire [11:0] scan;
wire [ 2:0] rom_id;

reg [ 9:0]  buf_mem[0:(2**10)-1];
reg [ 8:0]  buf_addr;
reg [ 8:0]  buf_data;
reg         buf_wr;

reg         done;

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

// Line buffer
// writes
always @(posedge clk) begin
    if( buf_wr ) buf_mem[ {vrender[0], buf_addr} ] <= buf_data;
    pxl <= hdump<9'd448 ? buf_mem[ {vdump[0], hdump} ] : 9'h1ff;
end

// reads

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

wire [CACHE_AW-2:0] cache_addr;
wire     cache_rd = vn[CACHE_XW-1:0] !=0;
reg      cache_half;
assign cache_addr = hn[10:CACHE_XW];

reg  [15:0] vram_cache[0:(2**CACHE_AW)-1];

// initial begin
//     $display("Size = %d, Cache = %d -> %d", SIZE, CACHE_AW, (2**CACHE_AW)-1);
//     vram_cache[9'h38] = 16'hdead;
//     $display("Test = %X ", vram_cache[9'h38] );
//     $finish;
// end

// always @(posedge clk) begin
//     if( cache_wr ) vram_cache[ cache_addr ] <= cache_din;
//     cache_dout = vram_cache[ cache_addr ];
// end

always @(posedge clk or posedge rst) begin
    if(rst) begin
        rom_cs          <= 1'b0;
        vram_cs         <= 1'b0;
        buf_wr          <= 1'b0;
        done            <= 1'b0;
        st              <= 0;
        rom_addr[22:20] <= rom_id; // constant value
        cache_half      <= 0;
    end else begin
        st <= st+1;
        case( st ) 
            0: begin
                rom_cs   <= 1'b0;
                vram_cs  <= 1'b0;
                /* verilator lint_off WIDTH */
                vn       <= vpos + {8'd0, vrender};
                /* verilator lint_on WIDTH */
                hn       <= { hpos[10:SCRW], {SCRW{1'b0}} };
                buf_addr <= 9'h1ff-hpos[SCRW-1:0];
                tilecnt  <= {TILECNTW{1'b0}};
                buf_wr   <= 1'b0;
                if(start) done<=1'b0;
                if(!start) begin
                    st   <= 0;
                end
            end
            1: begin
                cache_half <= 0;
                if( !cache_rd ) begin
                    vram_addr <= { vram_base, 7'd0 } + { 10'd0, scan, 1'b0};
                    vram_cs   <= 1'b1;
                end
                if( tilecnt==TILEMAX ) begin
                    buf_wr <= 1'b0;
                    done   <= 1'b1;
                    st     <= 0;
                end
            end
            3: if(!cache_rd) begin
                    if( vram_ok ) begin
                        code         <= vram_data;
                        vram_addr[1] <= 1'b1;
                        st <= 50;
                        // save the value for later
                        //cache_wr   <= 1;
                        //cache_din  <= vram_data;
                        vram_cache[ { 1'b0, cache_addr} ] <= vram_data;
                    end else st<=st;
                end else begin
                    code <= vram_cache[ {1'b0,cache_addr} ];// cache_dout;
                    st <= 50;
                end
            50: begin
                cache_half <= 1;
            end
            51: if(!cache_rd) begin
                    if( vram_ok ) begin
                        attr    <= vram_data;
                        vram_cs <= 1'b0;
                        st <= 4;
                        // save to cache
                        // cache_wr   <= 1;
                        // cache_din  <= vram_data;
                        vram_cache[ {1'b1,cache_addr} ] <= vram_data;
                    end else st<=st;
                end else begin
                    attr <= vram_cache[ {1'b1,cache_addr} ]; // cache_dout;
                    st <= 4;
                end
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
                    tilecnt <= tilecnt+1; // 8x tile done
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
                    tilecnt <= tilecnt+1; // 16x tile done
                end else if(rom_ok) begin
                    pxl_data <= rom_data;
                    hn <= hn + 10'd8; // pixels 16-23
                end else st<=st;
            end
            33: begin
                if(rom_ok) begin
                    pxl_data <= rom_data;
                    hn <= hn + 10'd8; // pixels 24-31
                end else st<=st;
            end
            42: begin
                st      <= 1; // 32x tile done
                tilecnt <= tilecnt+1;
            end
        endcase
    end
end

endmodule