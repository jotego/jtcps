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

    input      [ 8:0]  vrender, // 1 line ahead of vdump
    input      [ 2:0]  size,    // hot one encoding. bit 0=8x8, bit 1=16x16, bit 2=32x32
    // control registers
    input      [15:0]  vram_base,
    input      [15:0]  hpos,
    input      [15:0]  vpos,

    // Row scroll
    input      [17:1]  vram_row,
    input              row_en,

    input              start,
    input              stop,
    output reg         done,

    // ROM banks
    input      [ 5:0]  game,
    input      [15:0]  bank_offset,
    input      [15:0]  bank_mask,

    output reg [17:1]  vram_addr,
    input      [15:0]  vram_data,
    input              vram_ok,
    output reg         vram_cs,

    output reg [19:0]  rom_addr,    // up to 1 MB
    output reg         rom_half,    // selects which half to read
    input      [31:0]  rom_data,
    output reg         rom_cs,
    input              rom_ok,

    output reg [ 8:0]  buf_addr,
    output reg [10:0]  buf_data,
    output reg         buf_wr
);

reg [10:0] vn;
reg [10:0] hn;
reg [31:0] pxl_data;

reg [ 5:0] st;

reg [21:0] tile_addr;
reg [15:0] code;

reg  [11:0] scan;
reg  [ 2:0] layer;
reg  [ 3:0] offset, mask;
reg         unmapped;

wire [ 3:0] pre_offset1, pre_mask1;
wire [ 3:0] pre_offset2, pre_mask2;
wire [ 3:0] pre_offset3, pre_mask3;
wire        pre_unmapped1;
wire        pre_unmapped2;
wire        pre_unmapped3;


always @(*) begin
    case(size)
        3'b1:  begin
            scan   = { vn[8],   hn[8:3], vn[7:3] };
            layer  = 3'b001;
        end
        3'b10: begin
            scan   = { vn[9:8], hn[9:4], vn[7:4] };
            layer  = 3'b010;
        end
        3'b100: begin
            scan   = { vn[10:8], hn[10:5], vn[7:5] };
            layer  = 3'b011;
        end
        default: begin
            scan   = 12'd0;
            layer  = 3'b000;
        end
    endcase
end

reg [9:0] mapper_in;

jtcps1_gfx_mappers u_mapper1(
    .clk        ( clk             ),
    .rst        ( rst             ),
    .game       ( game            ),
    .bank_offset( bank_offset     ),
    .bank_mask  ( bank_mask       ),

    .layer      ( 3'd1            ),
    .cin        ( mapper_in       ),    // pins 2-9, 11,13,15,17,18

    .offset     ( pre_offset1     ),
    .mask       ( pre_mask1       ),
    .unmapped   ( pre_unmapped1   )
);

jtcps1_gfx_mappers u_mapper2(
    .clk        ( clk             ),
    .rst        ( rst             ),
    .game       ( game            ),
    .bank_offset( bank_offset     ),
    .bank_mask  ( bank_mask       ),

    .layer      ( 3'd2            ),
    .cin        ( mapper_in       ),    // pins 2-9, 11,13,15,17,18

    .offset     ( pre_offset2     ),
    .mask       ( pre_mask2       ),
    .unmapped   ( pre_unmapped2   )
);

jtcps1_gfx_mappers u_mapper3(
    .clk        ( clk             ),
    .rst        ( rst             ),
    .game       ( game            ),
    .bank_offset( bank_offset     ),
    .bank_mask  ( bank_mask       ),

    .layer      ( 3'd3            ),
    .cin        ( mapper_in       ),    // pins 2-9, 11,13,15,17,18

    .offset     ( pre_offset3     ),
    .mask       ( pre_mask3       ),
    .unmapped   ( pre_unmapped3   )
);

reg  [1:0] group;
reg        vflip;
reg        hflip;
reg  [4:0] pal;
// assign rom_half = hn[3] ^ hflip;

reg [19:0] rom_pre_addr, rom_masked_addr, rom_offset_addr;

always @(*) begin
    case (size)
        3'b001: rom_pre_addr = { 1'b0, code, vn[2:0] ^ {3{vflip}} };
        3'b010: rom_pre_addr = { code, vn[3:0] ^{4{vflip}} };
        default: rom_pre_addr = { code[13:0], vn[4:0] ^{5{vflip}}, hflip }; // 3'b100
    endcase
    rom_masked_addr = { mask, ~16'h0 } & rom_pre_addr;
    rom_offset_addr = { offset, 16'h0} | rom_masked_addr;
end


function [3:0] colour;
    input [31:0] c;
    input        flip;
    colour = flip ? { c[24], c[16], c[ 8], c[0] } : 
                    { c[31], c[23], c[15], c[7] };
endfunction

wire [17:1] aux_addr = { vram_base[9:1], 8'd0 } + { 4'd0, scan, 1'b0 };
wire [15:0] row_hpos = hpos + vram_data;

// pixels in the blank area are not visible but it takes time to draw them
// so the start position is offset to avoid blanking
wire [10:0] hn0  = size[0] ? 11'h38 : (size[1] ? 11'h30 : 11'h20 );
wire [ 8:0] buf0 = size[0] ?  9'h38 : (size[1] ?  9'h30 :  9'h20 );

always @(posedge clk or posedge rst) begin
    if(rst) begin
        rom_cs          <= 1'b0;
        vram_cs         <= 1'b0;
        done            <= 1'b0;
        st              <= 6'd0;
        rom_addr        <= 23'd0;
        rom_half        <= 1'b0;
        vram_addr       <= 17'd0;
        code            <= 16'd0;
        buf_addr        <= 9'd0;
        buf_wr          <= 1'b0;
        buf_data        <= 11'd0;
    end else begin
        st <= st+6'd1;
        case( st ) 
            0: begin
                rom_cs   <= 1'b0;
                vram_cs  <= 1'b0;
                /* verilator lint_off WIDTH */
                vn       <= vpos + {7'd0, vrender};
                /* verilator lint_on WIDTH */
                hn       <= hn0 + (
                      size[0] ? { hpos[10:3], 3'b0 } :
                    ( size[1] ? { hpos[10:4], 4'b0 } : { hpos[10:5], 5'b0 } ));
                buf_addr <= buf0+9'h1ff- (
                    size[0] ? {2'b0, hpos[2:0]} : (size[1] ? {1'b0,hpos[3:0]} : hpos[4:0]) );
                buf_wr   <= 1'b0;
                done     <= 1'b0;
                if(!start) begin
                    st   <= 0;
                end else if( row_en && size[1] ) begin
                    st <= 53;
                end
            end
            ///////////////////////
            // Row scroll
            53:; // give extra time in case the SDRAM controller is processing
            // a request from the previous scroll layer
            62: begin
                vram_addr <= vram_row;
                vram_cs   <= 1'b1;
            end
            63: begin
                if( vram_ok) begin
                    //`ifdef SIMULATION
                    //$display("Row scroll: %X -> %X", vram_row, vram_data );
                    //`endif
                    hn       <= { row_hpos[10:4], 4'b0 };
                    buf_addr <= 9'h1ff- {1'b0,row_hpos[3:0]};
                    vram_cs  <= 1'b0;
                    st       <= 1; // continue with normal operation
                end else st<=st;
            end
            ///////////////////////
            1: begin
                vram_addr <= aux_addr;
                vram_cs   <= 1'b1;
            end
            3: begin
                if( vram_ok ) begin
                    mapper_in    <= vram_data[15:6];
                    code         <= vram_data;
                    vram_addr[1] <= 1'b1;
                    st <= 50;
                end else st<=st;
            end
            51: begin
                if( vram_ok ) begin // attributes
                    hflip   <= vram_data[5];
                    group   <= vram_data[8:7];
                    vflip   <= vram_data[6];
                    pal     <= vram_data[4:0];
                    st      <= 52;
                end else st<=st;
            end
            52: begin
                st <= 4;
                offset   <= size==3'd1 ? pre_offset1   : ( size==3'd2 ? pre_offset2   : pre_offset3    );
                mask     <= size==3'd1 ? pre_mask1     : ( size==3'd2 ? pre_mask2     : pre_mask3      );
                unmapped <= size==3'd1 ? pre_unmapped1 : ( size==3'd2 ? pre_unmapped2 : pre_unmapped3  );
            end
            4: begin
                rom_half <= hflip;
                rom_addr <= rom_offset_addr;
                rom_cs   <= 1'b1;
                hn <= hn + ( size[0] ? 11'h8 : (size[1] ? 11'h10 : 11'h20 ));
            end
            6: if(rom_ok) begin
                vram_addr <= aux_addr;
                pxl_data  <= rom_data;   // 32 bits = 32/4 = 8 pixels
                if(!size[0]) rom_half <= ~rom_half; // not needed for scroll1
            end else st<=6;
            7,8,9,10,    11,12,13,14, 
            16,17,18,19, 20,21,22,23,
            25,26,27,28, 29,30,31,32,
            34,35,36,37, 38,39,40,41: begin
                buf_wr   <= 1'b1;
                buf_addr <= buf_addr+9'd1;
                buf_data <= { group, pal, unmapped ? 4'hf : colour(pxl_data, hflip) };
                pxl_data <= hflip ? pxl_data>>1 : pxl_data<<1;
            end
            15: begin
                buf_wr <= 1'b0;
                if( size[0] /*8*/) begin
                    st <= 6'd2; // scan again. Jumps to 2 because vram_addr was already
                        // updated at 6
                end else if(rom_ok) begin
                    pxl_data <= rom_data;
                    rom_half <= ~rom_half;
                    if(size[2] /*32*/)
                        rom_addr[0] <= ~rom_addr[0];
                end else st<=st;
            end
            24: begin
                buf_wr <= 1'b0;
                if( size[1] /*16*/ ) begin
                    st <= 2; // scan again
                end else if(rom_ok) begin
                    pxl_data <= rom_data;
                    rom_half <= ~rom_half;
                end else st<=st;
            end
            33: begin
                if(rom_ok) begin
                    pxl_data <= rom_data;
                    rom_half <= ~rom_half;
                end else st<=st;
            end
            42: begin
                buf_wr <= 1'b0;
                st     <= 6'd2; // 32x tile done
            end
        endcase
        if( stop || buf_addr == 9'd447 ) begin
            // it is important to set vram_cs as soon as possible
            // in order to avoid the SDRAM controller to be processing
            // a request at the time the scroll controller moves to
            // the SCROLL 2 layer, as this could prevent the row scroll
            // values from reading correctly
            buf_addr<= 9'd0;
            buf_wr  <= 1'b0;
            done    <= 1'b1;
            st      <= 6'd0;
            vram_cs <= 1'b0;
        end
    end
end

endmodule