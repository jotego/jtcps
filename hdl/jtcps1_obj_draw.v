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

module jtcps1_obj_draw(
    input              rst,
    input              clk,

    input      [ 7:0]  vrender, // 1 line ahead of vdump
    input              start,

    output reg [ 9:0]  table_addr,
    input      [15:0]  table_data,

    // Line buffer
    output reg [ 8:0]  buf_addr,
    output reg [ 8:0]  buf_data,
    output reg         buf_wr,

    // ROM interface
    output reg [19:0]  rom_addr,    // up to 1 MB
    output reg         rom_half,    // selects which half to read
    input      [31:0]  rom_data,
    output reg         rom_cs,
    input              rom_ok
);

localparam [8:0] MAXH = 9'd448;

integer st;
reg [15:0] obj_x, obj_y, obj_code, obj_attr;
reg [15:0] last_x, last_y, last_code, last_attr;

wire  repeated = (obj_x==last_x) && (obj_y==last_y) && 
                 (obj_code==last_code) && (obj_attr==last_attr);

reg         done, inzone;
reg  [ 3:0] n, m;  // tile expansion n==horizontal, m==verital
reg  [ 3:0] suby, vsub, vsubf;
wire [ 3:0] tile_n, tile_m;
wire [ 4:0] pal;
wire        hflip, vflip;
reg  [31:0] pxl_data;
reg  [ 3:0] v10, v20, v30, v40, v50, v60, v80, v90,
            vA0, vB0, vC0, vD0, vE0, vF0;
reg  [15:0] code_mn;

assign tile_n = obj_attr[11: 9];
assign tile_m = obj_attr[15:12];
assign hflip  = obj_attr[5];
assign vflip  = obj_attr[6];
assign pal    = obj_attr[4:0];

function [3:0] colour;
    input [31:0] c;
    input        flip;
    colour = flip ? { c[24], c[16], c[ 8], c[0] } : 
                    { c[31], c[23], c[15], c[7] };
endfunction

function check_msb;
    input [3:0] obj_ymsb;
    input [3:0] vrender_msb;
    input [3:0] offset;
    input [3:0] tile_m;
    check_msb = (obj_ymsb+offset)==vrender_msb && (obj_ymsb<=vrender_msb)
        && tile_m <= offset;
endfunction

reg  [15:0] inzone_msb;

integer offset;

always @(*) begin
    for( offset=0; offset<16; offset=offset+1) begin
        inzone_msb[offset] = check_msb( obj_y[7:4], vrender[7:4], offset, tile_m );
    end
    inzone = inzone_msb!=16'd0 && vrender[3:0] == obj_y[3:0];
    // which m won?
    case( inzone )
        16'h1:     m = 0;
        16'h2:     m = 1;
        16'h4:     m = 2;
        16'h8:     m = 3;

        16'h10:    m = 4;
        16'h20:    m = 5;
        16'h40:    m = 6;
        16'h80:    m = 7;

        16'h100:   m = 8;
        16'h200:   m = 9;
        16'h400:   m = 10;
        16'h800:   m = 11;

        16'h10_00: m = 12;
        16'h20_00: m = 13;
        16'h40_00: m = 14;
        16'h80_00: m = 15;
        default: m=0;
    endcase
    vsub = vrender - obj_y;
end

always @(*) begin
    case( {tile_m!=4'd0, tile_n!=4'd0 } )
        2'b00: code_mn = obj_code;
        2'b01: code_mn = { obj_code[15:4], n };
        2'b10: code_mn = { obj_code[15:8], m, obj_code[3:0] };
        2'b11: code_mn = { obj_code[15:8], m, n };
    endcase
end

always @(posedge clk, posedge rst) begin
    if( rst ) begin
        table_addr <= ~10'd0;
        rom_addr   <= 20'd0;
        rom_half   <= 1'd0;
        buf_wr     <= 1'b0;
        buf_data   <= 9'd0;
        buf_addr   <= 9'd0;
        st         <= 0;
        rom_cs     <= 1'b0;
        done       <= 1'b0;
    end else begin
        st <= st+1;
        case( st )
            0: begin
                buf_wr <= 1'b0;
                rom_cs <= 1'b0;
                if( !start ) st<=0;
                else begin
                    table_addr <= table_addr-10'd1; // start reading out the table
                    done       <= 0;
                end
            end
            1: begin
                if (table_addr==10'h3ff) begin
                    done <= 1'b1;
                    st   <= 0;
                end else begin
                    n          <= 4'd0;
                    last_attr  <= obj_attr;
                    obj_attr   <= table_data;
                    table_addr <= table_addr-10'd1;
                end           
            end
            2: begin
                last_code  <= obj_code;
                obj_code   <= table_data;
                table_addr <= table_addr-10'd1;
            end
            3: begin
                last_y     <= obj_y;
                obj_y      <= table_data;
                suby       <= table_data-vrender;
                vsubf      <= vsub ^ {4{vflip}};
                inzone     <= table_data==vrender;
                table_addr <= table_addr-10'd1;
            end
            4: begin
                last_x     <= obj_x;
                obj_x      <= table_data;
                buf_addr   <= table_data[8:0]-9'd1;
                table_addr <= table_addr-10'd1;
            end
            5: begin // check whether sprite is visible
                if( repeated || !inzone ) begin
                    st<= 1; // try next one
                end else begin // data request
                    rom_cs   <= 1'b1;
                    rom_addr <= { code_mn, vsubf };
                    rom_half <= hflip;
                end
            end
            6: begin
                if( rom_ok ) begin
                    pxl_data <= rom_data;
                    rom_half <= ~rom_half;
                end else st<=st;
            end
            7,8,9,10,    11,12,13,14,
            16,17,18,19, 20,21,22,23: begin
                buf_wr   <= 1'b1;
                buf_addr <= buf_addr+9'd1;
                buf_data <= { pal, colour(pxl_data, hflip) };
                pxl_data <= hflip ? pxl_data>>1 : pxl_data<<1;
            end
            15: begin
                if(rom_ok) begin
                    pxl_data <= rom_data;
                    rom_half <= ~rom_half;
                    n        <= n+1;
                end else st<=st;
            end
            24: begin
                if( n > tile_n || buf_addr>=MAXH ) begin
                    st <= 1; // next element
                end else begin // prepare for next tile
                    pxl_data <= rom_data;
                    rom_half <= ~rom_half;
                    rom_addr <= { code_mn, vsubf };
                    st <= 6;
                end
            end
        endcase

    end
end

endmodule
