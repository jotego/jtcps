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

module jtcps1_dma(
    input              rst,
    input              clk,
    input              pxl_cen,

    input              br_obj,
    output reg         bg_obj,

    input              br_pal,
    output reg         bg_pal,

    output reg         br,
    input              bg
);

reg [1:0] bus_master;
reg       last_bg;

localparam OBJ=0, PAL=1;

always @(posedge clk, posedge rst) begin
    if( rst ) begin
        br         <= 1'b0;
        bus_master <= 2'b0;
        bg_obj     <= 1'b0;
        bg_pal     <= 1'b0;
    end else begin
        last_bg <= bg;
        br      <= bus_master != 2'b00;
        bg_obj  <= bus_master[OBJ] ? bg : 1'b0;
        bg_pal  <= bus_master[PAL] ? bg : 1'b0;
        if( !bus_master ) begin
            if( br_obj ) begin
                bus_master <= 2'b01 << OBJ;
            end else
            if( br_pal ) begin
                bus_master <= 2'b01 << PAL;
            end
        end else begin
            if( !br_obj && bus_master[OBJ] ) bus_master <= 2'b0;
            if( !br_pal && bus_master[PAL] ) bus_master <= 2'b0;
        end
    end
end

endmodule