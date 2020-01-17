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

module jtcps1_colmix(
    input              rst,
    input              clk,

    input              start,

    input   [8:0]      scr1_data,
    input   [8:0]      scr2_data,
    input   [8:0]      scr3_data,
    input   [8:0]      scr1_addr,
    input   [8:0]      scr2_addr,
    input   [8:0]      scr3_addr,
    input              scr1_wr,
    input              scr2_wr,
    input              scr3_wr,

    input   [3:1]      scr_done,

    // To frame buffer
    output reg [8:0]   line_data,
    output reg [8:0]   line_addr,
    output reg         line_wr,
    input              line_wr_ok,
    output reg         line_done
);

reg [8:0] scr1_buf[0:511];
reg [8:0] scr2_buf[0:511];
reg [8:0] scr3_buf[0:511];

reg       dump;

reg [8:0] pxl, rd_addr, scr1_rd, scr2_rd, scr3_rd;

// simple layer priority for now:
always @(*) begin
    if( scr1_rd[3:0] != 4'hf )
        pxl = scr1_rd;
    else if(scr2_rd[3:0] != 4'hf )
        pxl = scr2_rd;
    else
        pxl = scr3_rd;
end

reg wr_dly, ok_dly;

always @(posedge clk, posedge rst) begin
    if( rst ) begin
        dump      <= 1'b0;
        line_addr <= 9'd0;
        line_data <= 9'd0;
        line_wr   <= 1'b0;
        line_done <= 1'b0;
    end else begin
        if( !dump ) begin
            if( scr1_wr ) scr1_buf[scr1_addr] <= scr1_data;
            if( scr2_wr ) scr2_buf[scr2_addr] <= scr2_data;
            if( scr3_wr ) scr3_buf[scr3_addr] <= scr3_data;
            dump <= &scr_done;
            line_done <= 1'b0;
            wr_dly    <= 1'b0;
            ok_dly    <= 1'b1;
            rd_addr   <= 9'd0;            
        end else begin
            dump <= start;
            if( !line_done ) begin                
                // Read memory
                ok_dly <= line_wr_ok;
                if( ok_dly ) begin
                    rd_addr <= rd_addr + 9'd1;
                    scr1_rd <= scr1_buf[ rd_addr ];
                    scr2_rd <= scr2_buf[ rd_addr ];
                    scr3_rd <= scr3_buf[ rd_addr ];
                    wr_dly  <= 1'b1;
                    line_wr <= 1'b0;
                end
                // Write line
                if( wr_dly ) begin
                    line_wr   <= 1'b1;
                    line_data <= pxl;
                    line_addr <= rd_addr;
                    ok_dly    <= 1'b0;
                end
            end
            line_done <= rd_addr>=9'd448;
        end        
    end
end

endmodule
