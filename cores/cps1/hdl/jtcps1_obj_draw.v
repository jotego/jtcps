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
    Version: 2.0
    Date: 23-1-2021 */

module jtcps1_obj_draw(
    input              rst,
    input              clk,

    input      [15:0]  obj_code,
    input      [15:0]  obj_attr,
    input      [ 8:0]  obj_hpos,

    input              start,
    output reg         idle,
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

wire [ 3:0] vsub;
wire [ 4:0] pal;
wire        hflip;
reg  [ 1:0] wait_cycle, read;
reg  [ 7:0] draw_cnt;
reg         draw;
reg  [31:0] pxl_data;
wire        rom_good;

assign vsub     = obj_attr[11:8];
//     vflip    = obj_attr[6];
assign hflip    = obj_attr[5];
assign pal      = obj_attr[4:0];
assign rom_good = rom_ok && wait_cycle==2'b0;

function [3:0] colour;
    input [31:0] c;
    input        flip;
    colour = flip ? { c[24], c[16], c[ 8], c[0] } :
                    { c[31], c[23], c[15], c[7] };
endfunction

always @(posedge clk, posedge rst) begin
    if( rst ) begin
        rom_addr   <= 20'd0;
        rom_half   <= 1'd0;
        buf_wr     <= 1'b0;
        buf_data   <= 9'd0;
        buf_addr   <= 9'd0;
        rom_cs     <= 1'b0;
        idle       <= 1;
        wait_cycle <= 0;
        draw_cnt   <= 8'h0;
    end else begin
        wait_cycle <= wait_cycle >> 1;
        if( idle ) begin
            if( start ) begin
                idle       <= 0;
                rom_cs     <= 1;
                rom_addr   <= { obj_code, vsub };
                buf_addr   <= obj_hpos;
                rom_half   <= hflip;
                wait_cycle <= 2'b11;
                read       <= 2'b11;
                draw       <= 0;
            end else begin
                rom_cs <= 0;
                draw   <= 0;
                buf_wr <= 0;
            end
        end else begin
            if( draw ) begin
                buf_wr   <= 1;
                buf_addr <= buf_addr+9'd1;
                buf_data <= { pal, colour(pxl_data, hflip) };
                pxl_data <= hflip ? pxl_data>>1 : pxl_data<<1;
                draw_cnt <= draw_cnt>>1;
                if( draw_cnt[0] ) begin
                    draw <= 0;
                    read <= read>>1;
                    if(!read[1]) idle<=1;
                end
            end else begin
                if( read ) begin
                    buf_wr <= 0;
                    if( rom_good ) begin
                        pxl_data <= rom_data;
                        if( read[1] )
                            rom_half <= ~rom_half;
                        else
                            rom_cs <= 0;

                        if( &rom_data ) begin
                            // skip blank pixels but waste two clock cycles for rom_ok
                            wait_cycle <= 2'b11;
                            buf_addr   <= buf_addr + 9'd8;
                            if( !read[1] )
                                idle <= 1;
                            else
                                read <= read>>1;
                        end else begin
                            draw <= 1;
                            draw_cnt <= 8'h80;
                        end
                    end
                end
            end
        end
    end
end

endmodule