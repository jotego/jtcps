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
    Date: 24-1-2021 */


module jtcps1_obj_tile_match(
    input             clk,

    input      [15:0] obj_code,
    input      [ 3:0] tile_n,
    input      [ 3:0] tile_m,
    input      [ 3:0] n,

    input             vflip,
    input      [ 8:0] vrenderf,
    input      [ 9:0] obj_y,

    output reg [ 3:0] vsub,
    output reg        inzone,
    output reg [15:0] code_mn
);

wire [15:0] match;
reg  [ 3:0] m, mflip;

reg  [ 9:0] bottom;
reg  [ 9:0] ycross;
wire [ 9:0] vs = { vrenderf[8], vrenderf };

always @(*) begin
    bottom = {1'b0, obj_y } + { 2'd0, tile_m, 4'd0 }+10'h10;
    ycross = vs-obj_y;
    m      = ycross[7:4];
    vsub   = vrenderf-obj_y[8:0];
    vsub   = vsub ^ {4{vflip}};
    mflip  = tile_m-m;
end

// the m,n sum carries on, at least for CPS2 games (SPF2T)
// The carry didn't seem to be needed for CPS1/1.5 games, so
// it might be a difference with the old CPS-A chip
always @(posedge clk) begin
    inzone <= (bottom>vs) && (vs >= obj_y);
    case( {tile_m!=4'd0, tile_n!=4'd0 } )
        2'b00: code_mn <= obj_code;
        2'b01: code_mn <= obj_code + { 12'd0, n };
        2'b10: code_mn <= obj_code + { 8'd0, vflip ? mflip : m, 4'd0};
        2'b11: code_mn <= obj_code + { 8'd0, vflip ? mflip : m, n};
    endcase
end

endmodule
