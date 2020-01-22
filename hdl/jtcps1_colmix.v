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
    output reg [11:0]  line_data,
    output reg [ 8:0]  line_addr,
    output reg         line_wr,
    input              line_wr_ok,
    output reg         line_done
);

// Scroll buffers
reg [ 8:0] scr1_buf[0:511];
reg [ 8:0] scr2_buf[0:511];
reg [ 8:0] scr3_buf[0:511];

reg       dump;

reg [ 8:0] pxl, rd_addr, scr1_rd, scr2_rd, scr3_rd;
reg [11:0] pal_addr;

// These are the top four bits written by CPS-B to each
// pixel of the frame buffer. These are likely sent by CPS-A
// via pins XS[4:0] and CPS-B encodes them
// 000 = OBJ ?
// 001 = SCROLL 1
// 010 = SCROLL 2
// 011 = SCROLL 3
// 000 = STAR FIELD?
reg [2:0] pxl_type;

// simple layer priority for now:
always @(*) begin
    //pxl      = scr1_rd;
    //pxl_type = 3'b01;
    //pxl      = scr2_rd;
    //pxl_type = 3'b10;

    if( scr1_rd[3:0] != 4'hf ) begin
        pxl      = scr1_rd;
        pxl_type = 3'b1;
    end else if(scr2_rd[3:0] != 4'hf ) begin
        pxl      = scr2_rd;
        pxl_type = 3'b10;
    end else begin
        pxl = scr3_rd;
        pxl_type = 3'b011;
    end
    pal_addr = { pxl_type, pxl };
end

reg pxl_ok, wait_ok;

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
            line_wr   <= 1'b0;
            wait_ok   <= 1'b0;
            pxl_ok    <= 1'b0;
            rd_addr   <= 9'd0;            
        end else begin
            if(start) begin
                dump      <= 1'b0;
                line_done <= 1'b0;
            end
            if( !line_done ) begin                
                // Read memory
                //ok_dly <= line_wr_ok;
                if( !pxl_ok ) begin
                    rd_addr <= rd_addr + 9'd1;
                    `ifndef NOSCROLL1
                    scr1_rd <= scr1_buf[ rd_addr ];
                    `else 
                    scr1_rd <= 9'h1ff;
                    `endif
                    scr2_rd <= scr2_buf[ rd_addr ];
                    scr3_rd <= scr3_buf[ rd_addr ];
                    pxl_ok  <= 1'b1;
                end
                // Write line
                if( pxl_ok && (!wait_ok || (wait_ok&&line_wr_ok))) begin
                    line_wr   <= 1'b1;
                    line_data <= pal_addr;
                    line_addr <= rd_addr;
                    wait_ok   <= 1'b1;
                    pxl_ok    <= 1'b0;
                end
                if( rd_addr>=9'd448 ) begin
                    line_done <= 1'b1;
                    line_wr   <= 1'b0;
                    wait_ok   <= 1'b0;
                end
            end
        end        
    end
end

endmodule
