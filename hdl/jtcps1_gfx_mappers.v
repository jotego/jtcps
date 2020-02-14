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

// A[22:20]   Usage
// 000        OBJ
// 001        SCROLL 1
// 010        SCROLL 2
// 011        SCROLL 3
// 100        Star field

module jtcps1_gfx_mappers(
    input              clk,
    input              rst,
    input              enable,

    input      [ 6:0]  game,
    input      [15:0]  bank_offset,
    input      [15:0]  bank_mask,

    input      [ 2:0]  layer,
    input      [ 9:0]  cin,    // pins 2-9, 11,13,15,17,18
    
    output     [ 3:0]  offset,
    output     [ 3:0]  mask,
);

reg  [ 3:0]  bank;
wire [22:10] a = {layer,cin};

always @(posedge clk, posedge rst) begin
    if( rst ) begin
        bank <= 4'd0;
    end else if(enable) begin
        bank <= {1'b0,
         {a[22:20],a[16]} == 4'b0001, // /i2 & /i3 & /i4 & i8
         {a[22:20],a[16]} == 4'b0110, // /i2 & i3 & i4 & /i8
         ~a[22] & ( (~a[21]&a[20]) | (~a[20]&~a[16]) | (a[21] & ~a[20])) };
    end
end

always @(*) begin
    case ( bank )
        4'b0001: { offset, mask } = { bank_offset[ 3: 0], bank_mask[ 3: 0] };
        4'b0010: { offset, mask } = { bank_offset[ 7: 4], bank_mask[ 7: 4] };
        4'b0100: { offset, mask } = { bank_offset[11: 8], bank_mask[11: 8] };
        4'b1000: { offset, mask } = { bank_offset[15:12], bank_mask[15:12] };
        default: { offset, mask } = { 4'h0, 4'hf };
    endcase
end

/*
always @(*) begin
    case( bank )
        4'b0100: cout={7'b0,cin[2:0]} + (16'ha000>>10); // bank 0
        4'b0010: cout={7'b0,cin[2:0]} + (16'h8000>>10); // bank 1
        4'b0001: cout={1'b0,cin[8:0]};                  // bank 2
    endcase
end
*/
endmodule