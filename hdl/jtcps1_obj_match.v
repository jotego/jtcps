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

module jtcps1_obj_match #(parameter [3:0] OFFSET=0)(
    input      [3:0] tile_m,
    input      [7:0] vrender,
    input      [7:0] obj_y,
    output reg       match
);

reg  [8:0]  vfinal, vfinal2;
reg         below, inzone;

always @(*) begin
    vfinal = obj_y  + {OFFSET,4'd0};
    vfinal2= vfinal + 9'h10;
    below  = vrender >= vfinal;
    inzone = vrender <= vfinal2;
    match  = below && inzone && (tile_m>=OFFSET);
end

endmodule
