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
    Date: 12-3-2020 */
    

// Star field generator
// Based on the circuit used for Side Arms, but without the ROM

module jtcps1_stars(
    input              rst,
    input              clk,
    input              pxl_cen,

    input              VB,
    input              HB,
    input      [ 8:0]  vdump,
    // control registers
    input      [15:0]  hpos0,
    input      [15:0]  vpos0,
    input      [15:0]  hpos1,
    input      [15:0]  vpos1,

    output     [ 8:0]  star0,
    output     [ 8:0]  star1
);

wire [22:0] poly1, poly0;
wire        load = HB | VB;

jtcps1_lfsr #(0) u_lfsr0(
    .clk        ( clk           ),
    .pxl_cen    ( pxl_cen       ),
    .load       ( load          ),
    .hpos       ( hpos0[ 8:0]   ),
    .vpos       ( vpos0[ 8:0]   ),
    .vdump      ( vdump         ),
    .poly       ( poly0         )
);

jtcps1_lfsr #(1) u_lfsr1(
    .clk        ( clk           ),
    .pxl_cen    ( pxl_cen       ),
    .load       ( load          ),
    .hpos       ( hpos1[ 8:0]   ),
    .vpos       ( vpos1[ 8:0]   ),
    .vdump      ( vdump         ),
    .poly       ( poly1         )
);

function bright;
    input [22:0] poly;
    bright = &poly[15:7];
endfunction

// Bits 8:7 must be zero
assign star0[8:4] = { 2'd0, poly0[6:4] };
assign star1[8:4] = { 2'd0, poly1[6:4] };

assign star0[3:0] = bright(poly0) ? poly0[3:0] : 4'hf;
assign star1[3:0] = bright(poly1) ? poly1[3:0] : 4'hf;

`ifdef SIMULATION
wire s0 = star0[3:0]!=4'hf;
wire s1 = star1[3:0]!=4'hf;
`endif

endmodule

module jtcps1_lfsr (
    input              clk,
    input              pxl_cen,
    input              load,
    input      [ 8:0]  hpos,
    input      [ 8:0]  vpos,
    input      [ 8:0]  vdump,
    output reg [22:0]  poly
);

parameter B=0;
wire bb = B;

reg last_load;
reg [8:0] cnt;
wire      cnthi = |cnt;
wire [8:0] v = vpos+vdump;

always @(posedge clk) begin
    last_load <= load;
    if( load && !last_load ) begin
        poly <= { {bb,~bb,~bb,bb}^{v[3:2],v[7:6]}, v[3:0], v[8:4], 10'h55 ^ {10{bb}} };
        cnt  <= hpos;
    end else if( (!load && pxl_cen) || (load&&cnthi) ) begin
        if(cnthi) cnt<=cnt-9'd1;
        poly <= { poly[21:0], ~(poly[21]^poly[17])};
    end
end

endmodule