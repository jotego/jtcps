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
    Date: 28-1-2021 */


module jtcps2_obj_frame(
    input              rst,
    input              clk,
    input              pxl_cen,

    input      [ 8:0]  vdump,
    input              LVBL,
    input              obank,

    // Interface with SDRAM for ORAM data
    output     [12:0]  oram_addr,
    input              oram_ok,

    // Interface with ORAM frame buffer
    output reg         oframe_we,
    output reg         obank_frame
);

localparam W=5;

wire         frame, frame_edge;
reg          wtok, last_LVBL, last_frame;
reg  [ 11:0] oram_cnt;
reg  [W-1:0] line_cnt;
reg          wrbank;

assign frame      = vdump=='he;
assign frame_edge = frame && !last_frame;
assign oram_addr  = { obank, oram_cnt };

always @(posedge clk, posedge rst ) begin
    if( rst ) begin
        obank_frame <= 0;
    end else begin
        last_LVBL  <= LVBL;
        last_frame <= frame;
        if( frame_edge )
            obank_frame <= ~obank_frame;
    end
end

always @( posedge clk ) begin
    if( !LVBL ) begin
        oram_cnt    <= 12'd0;
        line_cnt    <= {W{1'd0}};
        oframe_we   <= 0;
        wtok        <= 1;
    end else begin
        if( oram_ok ) wtok <= 0;
        oframe_we <= oram_ok && !wtok && LVBL;
        if( pxl_cen & ~&line_cnt ) begin
            if( line_cnt == 'h1b ) begin
                line_cnt <= 0;
                wtok     <= 0;
                oram_cnt <= oram_cnt+1'b1;
            end else begin
                wtok <= 1;
                line_cnt <= line_cnt+1'b1;
            end
        end
    end
end

`ifdef SIMULATION
initial begin
    oram_cnt = 12'd0;
    line_cnt = 4'd0;
end
`endif

endmodule