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
    input              HB,

    input              br_obj,
    output reg         bg_obj,

    input              br_pal,
    output reg         bg_pal,

    output reg         br,
    input              bg
);

reg [1:0] bus_master;
reg [3:0] line_cnt;
reg       last_HB;
wire      HB_edge = !last_HB && HB;

localparam LINE=0, PAL=1;
localparam OBJ_START=4'd3, OBJ_END=4'd11;

always @(posedge clk, posedge rst) begin
    if( rst ) begin
        br         <= 1'b0;
        bus_master <= 2'b0;
        bg_obj     <= 1'b0;
        bg_pal     <= 1'b0;
        line_cnt   <= 4'd0;
    end else begin
        last_HB <= HB;
        br      <= bus_master != 2'b00;
        bg_pal  <= bus_master[PAL]  ? bg : 1'b0;
        if( !bus_master ) begin
            if( br_pal ) begin
                bus_master <= 2'b01 << PAL;
            end else if( HB_edge) begin
                bus_master <= 2'b01 << LINE;
                line_cnt   <= 4'd0;
            end
        end else begin
            if( !br_pal && bus_master[PAL] ) bus_master[PAL] <= 1'b0;
            if( bus_master[LINE] && pxl_cen && bg ) begin
                // Line DMA transfer takes 2us
                line_cnt <= line_cnt + 4'd1;
                if( &line_cnt ) bus_master[LINE] <= 1'b0;
                if( line_cnt == OBJ_START && br_obj ) bg_obj <= 1'b1;
                if( line_cnt == OBJ_END ) bg_obj <= 1'b0;
            end
        end
    end
end

endmodule