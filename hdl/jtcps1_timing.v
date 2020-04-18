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
    output             preVB,
    output reg         HB
);

reg [1:0] shVB;

`ifdef SIMULATION
initial begin
    hdump     = 9'd0;
    vrender1  = 8'd2;
    vrender   = 8'd1;
    vdump     = 9'd0;
    HS        = 1'b0;
    VS        = 1'b0;
    HB        = 1'b1;
    VB        = 1'b1;
    shVB      = 2'b11;
    start     = 1'b1;
end
`endif

assign preVB = shVB[0];

localparam [8:0] VS_START = 9'd237+9'd8;
localparam [8:0] VS_END   = VS_START + 9'd4;
localparam [8:0] HS_START = 9'd488;
localparam [8:0] HS_END   = 9'd18;

always @(posedge clk) if(cen8) begin
    hdump     <= hdump+9'd1;
    //if ( vdump>=9'hf8  ) VB <= 1'b1;
    //if ( vdump==9'h0F  ) VB <= 1'b0;
    shVB[0] <= vdump<(9'd14) || vdump>9'd237; // 224 visible lines
    HB      <= hdump>=(9'd384+9'd64) || hdump<9'd64;
    // original HS reported to last for 36 clock ticks
    if( hdump== HS_START ) begin
        HS <= 1'b1;
        // VS must occur synchronized with HS for better compatibility
        // 250/261 wavy
        // 250/255 best
        // h100/h001 old
        if ( vdump==VS_START ) VS <= 1'b1;
        if ( vdump==VS_END   ) VS <= 1'b0;
    end
    if( hdump== HS_END ) HS <= 1'b0;
    start  <= hdump==9'h1ff;
    if(&hdump) begin
        hdump   <= 9'd0;
        vrender1<= vrender1==9'd261 ? 9'd0 : vrender1+9'd1;
        vrender <= vrender1;
        vdump   <= vrender;
        { VB, shVB[1] } <= shVB;
    end
end

endmodule