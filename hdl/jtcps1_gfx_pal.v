/*  This file is part of JTCPS1.
    JTCPS1 program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    JTCPS1 program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR a PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with JTCPS1.  If not, see <http://www.gnu.org/licenses/>.

    Author: Jose Tejada Gomez. Twitter: @topapate
    Version: 1.0
    Date: 13-1-2020 */
    
`timescale 1ns/1ps

// pin a
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

// A[22:20]   Usage
// 000        OBJ
// 001        SCROLL 1
// 010        SCROLL 2
// 011        SCROLL 3
// 100        Star field

module jtcps1_gfx_pal(
    input      [22:10] scr1,    // pins 2-9, 11,13,15,17,18
    input      [22:10] scr2,    // pins 2-9, 11,13,15,17,18
    input      [22:10] scr3,    // pins 2-9, 11,13,15,17,18
    output reg [ 3: 0] offset1, // scr GFX offset
    output reg [ 3: 0] offset2,
    output reg [ 3: 0] offset3 
);

reg [ 4: 1] bank1;  // pins 12, 14, 16, 19
reg [ 4: 1] bank2;  // pins 12, 14, 16, 19
reg [ 4: 1] bank3;  // pins 12, 14, 16, 19

// Ghouls'n Ghosts (dm620.2a)
// jedutil -view dm620.2a  GAL16V8
function [4:1] cen_gfx;
    input [22:10] a;    
    cen_gfx = {1'b0,
             {a[22:20],a[16]} == 4'b0001, // /i2 & /i3 & /i4 & i8
             {a[22:20],a[16]} == 4'b0110, // /i2 & i3 & i4 & /i8
            // /i2 & /i3 & i4 +
            // /i2 & /i4 & /i8 +
            // /i2 & i3 & /i4
             ~a[22] & ( (~a[21]&a[20]) | (~a[20]&~a[16]) | (a[21] & ~a[20])) };
endfunction

function [3:0] bank2offset;
    input [4:1] cen;
    case( cen )
        4'd0: bank2offset = 4'h0;
        4'd1: bank2offset = 4'h4;
        4'd2: bank2offset = 4'h0;
        4'd4: bank2offset = 4'h0;
        default: bank2offset = 4'h0;
    endcase
endfunction

always @(*) begin
    bank1 = cen_gfx( scr1 );
    bank2 = cen_gfx( scr2 );
    bank3 = cen_gfx( scr3 );
    offset1 = bank2offset( bank1 );
    offset2 = bank2offset( bank2 );
    offset3 = bank2offset( bank3 );
end

endmodule