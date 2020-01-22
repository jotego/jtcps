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

module jtcps1_pal(
    input              rst,
    input              clk,

    input      [10:0]  index,
    output reg [ 4:0]  red,
    output reg [ 4:0]  green,
    output reg [ 4:0]  blue
);

// Palette
reg [15:0] pal[0:(2**12)-1]; // 4096?
reg [15:0] raw;
wire [3:0] raw_r, raw_g, raw_b, raw_br;

assign raw_br = raw[15:12];
assign raw_r  = raw[11: 8];
assign raw_g  = raw[ 7: 4];
assign raw_b  = raw[ 3: 0];

`ifdef SIMULATION
initial begin
    $readmemh("pal16.hex",pal);
end
`endif

always @(posedge clk, posedge rst) begin
    if(rst) begin
        red   <= 5'd0;
        green <= 5'd0;
        blue  <= 5'd0;
    end else begin
        raw <= pal[index];
        // no brightness processing for now
        red   <= {1'b0, raw_r };
        green <= {1'b0, raw_g };
        blue  <= {1'b0, raw_b };
    end
end

endmodule