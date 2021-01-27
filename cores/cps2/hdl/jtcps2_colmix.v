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
    Date: 27-1-2021 */


module jtcps2_colmix(
    input              rst,
    input              clk,
    input              pxl_cen,

    input      [11:0]  scr_pxl,
    input      [11:0]  obj_pxl,
    output reg [11:0]  pxl
);

localparam [2:0] OBJ=3'b0, SCR1=3'b1, SCR2=3'd2, SCR3=3'd3, STA=3'd4;

wire [2:0] obj_prio = obj_pxl[11:9];

reg obj1st, mux_sel;

function blank;
    input [11:0] a;
    blank = a[3:0]==4'hf;
endfunction

always @(*) begin
    case( scr_pxl[11:9] )
        SCR1: obj1st = obj_prio[0];
        SCR2: obj1st = obj_prio[1];
        SCR3: obj1st = obj_prio[2];
        default: obj1st = 1;
    endcase
    mux_sel = obj1st ? blank(obj_pxl) : ~blank(scr_pxl);
end

always @(posedge clk) if(pxl_cen) begin
    pxl <= mux_sel ? scr_pxl : obj_pxl;
end

endmodule