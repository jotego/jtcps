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
    input              obj_en,
    output reg [11:0]  pxl
);

localparam [2:0] OBJ=3'b0, SCR1=3'b1, SCR2=3'd2, SCR3=3'd3, STA=3'd4;

wire [2:0] obj_prio = obj_pxl[11:9],
           scr_lyr  = scr_pxl[11:9];

reg obj1st, mux_sel;

function blank;
    input [11:0] a;
    blank = a[3:0]==4'hf;
endfunction

always @(*) begin
    //obj1st  = ~obj_prio <= scr_lyr; // ok in SPF2T
    //obj1st  = obj_prio > scr_lyr; // ok in Sports Club
    casez( obj_prio[1:0] )
        default: obj1st = 1;        // 7
        2'b0?: obj1st = scr_lyr!=3'd1; // 4 or 5, verified
        2'b11: obj1st = 1;
    endcase
    mux_sel = obj1st ? blank(obj_pxl) : ~blank(scr_pxl);
end

always @(posedge clk) if(pxl_cen) begin
    //pxl <= obj_prio!=4 &&  obj_prio!=7 ? obj_pxl[8:0] : 9'd0;
    //pxl <= obj_prio==4 ? obj_pxl[8:0] : 9'd0;
    //pxl <= scr_lyr==3 ? scr_pxl : 9'd0;
    pxl <= !obj_en ? scr_pxl :
        ( mux_sel ? scr_pxl : {3'd0, obj_pxl[8:0]} );
end

endmodule