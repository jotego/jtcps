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
    Date: 29-9-2021 */


// Star field generator
// Based on research work by Loic
// https://gitlab.com/loic.petit/cps2-reverse

module jtcps1_stars(
    input              rst,
    input              clk,
    input              pxl_cen,

    input              VB,
    input      [ 8:0]  hdump,
    input      [ 8:0]  vdump,
    // control registers
    input      [ 8:0]  hpos,
    input      [ 8:0]  vpos,

    output reg [12:0]  rom_addr,
    input      [31:0]  rom_data,
    input              rom_ok,

    output reg [ 6:0]  pxl
);

parameter FIELD=0;

reg  [3:0] cnt16, cnt15;
wire [2:0] pal_id;
wire [4:0] pos;
reg  [8:0] heff, veff;

assign pal_id   = rom_data[7:5];
assign pos      = rom_data[4:0];

always @* begin
    heff = hpos+hdump;
    rom_addr = { heff[8:5], veff };
end

always @(posedge clk, posedge rst) begin
    if( rst ) begin
        cnt15 <= 0;
        cnt16 <= 0;
        veff  <= 0;
    end else if( pxl_cen ) begin
        veff <= vpos+vdump;
        if( VB ) begin
            cnt15 <= 0;
            cnt16 <= 0;
        end else begin
            if( &hdump[4:0] ) begin
                cnt15 <= cnt15==14 ? 0 : cnt15+1'd1; // cnt15 will never be transparent
                cnt16 <= cnt16+1'd1; // transparent when cnt16==15
            end
        end
    end
end

always @(posedge clk, posedge rst) begin
    if( rst ) begin
        pxl <= 7'hf;
    end else if( pxl_cen ) begin
        pxl[6:4] <= pal_id;
        pxl[3:0] <= pos==heff[4:0] ? (pal_id[2] ? cnt15 : cnt16) : 4'hf;
    end
end

endmodule