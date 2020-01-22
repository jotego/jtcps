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

    output reg [ 7:0]  vdump,
    output reg [ 8:0]  hdump,
    output reg         frame,
    // Render interface
    output reg [ 7:0]  vrender,
    output reg         line_start,    // line line_start
    input              line_done,     // line done
    // to video output
    output reg         HS,
    output reg         VS,
    output reg         VB,
    output reg         HB
);

reg new_frame;

always @(posedge clk, posedge rst) begin
    if(rst) begin
        hdump     <= 9'd0;
        vdump     <= 8'd0;
        HS        <= 1'b0;
        VS        <= 1'b0;
        HB        <= 1'b0;
        VB        <= 1'b0;
        frame     <= 1'b0;
        new_frame <= 1'b0;
    end else if(cen8) begin
        hdump     <= hdump+9'd1;
        new_frame <= 1'b0;
        VB     <= vdump>=8'd224;// || vdump<8'h08; // VB end relates to new_frame register
        VS     <= vdump>=8'he8 && vdump<8'hf0;
        HB     <= hdump>=(9'd384+9'd64) || hdump<9'd64;
        HS     <= hdump>=9'h1da && hdump<9'h1f0;
        if(&hdump) begin
            hdump <= 9'd0;
            vdump <= vdump+1;
            new_frame<= vdump==8'hff;   // do not start new rendering until VB end
            if(&vdump) begin
                frame    <= ~frame;
            end
        end
    end
end

// render V counter
reg last_done;
always @(posedge clk, posedge rst) begin
    if( rst ) begin
        vrender      <= 8'd0;
        line_start   <= 1'b1;
        last_done    <= 1'b0;
    end else begin
        line_start <= 1'b0;
        last_done  <= line_done;
        if( (line_done && !last_done && vrender<8'hf8) || new_frame ) begin
            vrender <= vrender+8'd1;
            line_start   <= 1'b1;
        end
    end
end

endmodule