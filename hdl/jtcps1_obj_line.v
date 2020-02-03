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

    output reg [ 8:0]  pxl
);

reg [8:0] line_buffer[0:1023];
reg [8:0] last_h;

wire [9:0] addr0 = {  vdump, buf_addr }; // write
wire [9:0] addr1 = erase ? {~vdump, last_h} : { ~vdump, hdump    }; // read
wire [8:0] pre_pxl;
wire       wr1 = buf_wr && buf_data[3:0]!=4'hf;
reg        erase;

jtframe_dual_ram #(.dw(9), .aw(10)) u_line(
    .clk0   ( clk       ),
    .clk1   ( clk       ),
    // Port 0: write
    .data0  ( buf_data  ),
    .addr0  ( addr0     ),
    .we0    ( wr1       ),
    .q0     (           ),
    // Port 1: read and erase
    .data1  ( 9'h1ff    ),
    .addr1  ( addr1     ),
    .we1    ( erase     ),
    .q1     ( pre_pxl   )
);

always @(posedge clk) begin
    if( pxl_cen ) begin
        last_h <= hdump;
        pxl    <= pre_pxl;
        erase  <= 1'b1;
    end else erase <= 1'b0;
end

endmodule