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

module jtcps1_timing(
    input              rst,
    input              clk,
    input              cen8,

    output reg [ 8:0]  hdump,
    output reg [ 8:0]  vdump,
    output reg [ 8:0]  vrender,
    output reg [ 8:0]  vrender1,
    output reg         start,
    // to video output
    output reg         HS,
    output reg         VS,
    output reg         VB,
    output reg         preVB,
    output reg         HB
);

`ifdef SIMULATION
initial begin
    hdump     = 9'd0;
    vdump     = 9'd261;
    vrender   = 8'd0;
    vrender1  = 8'd0;
    HS        = 1'b0;
    VS        = 1'b0;
    HB        = 1'b1;
    VB        = 1'b1;
    preVB     = 1'b0;
    start     = 1'b1;
end
`endif

always @(posedge clk) if(cen8) begin
    hdump     <= hdump+9'd1;
    //if ( vdump>=9'hf8  ) VB <= 1'b1;
    //if ( vdump==9'h0F  ) VB <= 1'b0;
    if ( vdump==9'h100 ) VS <= 1'b1;
    if ( vdump==9'h001 ) VS <= 1'b0;
    preVB  <= vdump<(9'd15) || vdump>9'd238; // 224 visible lines
    HB     <= hdump>=(9'd384+9'd64) || hdump<9'd64;
    HS     <= hdump>=9'h1cc && hdump<9'h1f0;    // 36 clock ticks
    start  <= hdump==9'h1ff;
    if(&hdump) begin
        hdump   <= 9'd0;
        vrender1<= vrender1==9'd261 ? 9'd0 : vrender1+9'd1;
        vrender <= vrender1;
        vdump   <= vrender;
        VB      <= preVB;
    end
end

endmodule