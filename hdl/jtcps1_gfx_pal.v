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

// pin A
// 1   output enable, ignored
// 2   22
// 3   21
// 4   20
// 5   19
// 6   18
// 7   17
// 8   16
// 9   15
// 11  14
// 13  13
// 15  12
// 17  11
// 18  10 

module jtcps1_gfx_pal(
    input   [22:10] a,  // pins 2-9, 11,13,15,17,18
    output  [4:1]   cen // pins 12, 14, 16, 19
);

// Ghouls'n Ghosts
assign cen[4] = 1'b1;
assign cen[3] = &{~a[22:20],a[16]}; // /i2 & /i3 & /i4 & i8
assign cen[2] = &{~a[22],a[21:20],a[16]}; // /i2 & i3 & i4 & /i8
// /i2 & /i3 & i4 +
// /i2 & /i4 & /i8 +
// /i2 & i3 & /i4
assign cen[1] = ~A[22] & (~A[21]&A[20] + ~A[20]&~A[16] + A[21] & ~A[20]);

endmodule