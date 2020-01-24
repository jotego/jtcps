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

module jtcps1_obj_line(
    input              clk,
    input              pxl_cen,

    input      [ 8:0]  hdump,
    input              vdump, // only LSB

    // Line buffer
    input      [ 8:0]  buf_addr,
    input      [ 8:0]  buf_data,
    input              buf_wr,

    output     [ 8:0]  pxl
);

reg [8:0] line_buffer[0:1023];
reg [8:0] last_h;

always @(posedge clk) begin
    if( buf_wr && buf_data[3:0]!=4'hf)
        line_buffer[ {vdump,buf_addr} ] <= buf_data;
end

always @(posedge clk) begin
    if( pxl_cen ) begin
        last_h <= hdump;
        pxl    <= line_buffer[ {~vdump, hdump} ];
    end else
        line_buffer[ {~vdump, last_h} ] <= 9'h1ff;
end

endmodule