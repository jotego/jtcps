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
    input      [ 8:0] obj_y,

    output reg [ 3:0] vsub,
    output reg        inzone,
    output reg [15:0] code_mn
);

wire [15:0] match;
reg  [ 3:0] m, mflip;

generate
    genvar mgen;
    for( mgen=0; mgen<16;mgen=mgen+1) begin : obj_matches
        jtcps1_obj_match #(mgen) u_match(
            .clk    ( clk           ),
            .tile_m ( tile_m        ),
            .vrender( vrenderf      ),
            .obj_y  (   obj_y       ),
            .match  ( match[mgen]   )
        );
    end
endgenerate

always @(*) begin
    inzone = match!=16'd0;
    vsub   = vrenderf-obj_y;
    vsub   = vsub ^ {4{vflip}};
    // which m won?
    case( match )
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
    mflip = tile_m-m;
end

always @(*) begin
    case( {tile_m!=4'd0, tile_n!=4'd0 } )
        2'b00: code_mn = obj_code;
        2'b01: code_mn = { obj_code[15:4], obj_code[3:0]+n };
        2'b10: code_mn = { obj_code[15:8],
                           obj_code[7:4]+ (vflip ? mflip : m),
                           obj_code[3:0] };
        2'b11: code_mn = { obj_code[15:8],
                           obj_code[7:4]+ (vflip ? mflip : m),
                           obj_code[3:0]+n };
    endcase
end

endmodule
