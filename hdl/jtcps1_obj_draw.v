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

module jtcps1_obj_draw(
    input              rst,
    input              clk,

    input              start,

    output reg [ 8:0]  table_addr,
    input      [15:0]  table_data,

    // Line buffer
    output reg [ 8:0]  buf_addr,
    output reg [ 8:0]  buf_data,
    output reg         buf_wr,

    // ROM interface
    output reg [19:0]  rom_addr,    // up to 1 MB
    output reg         rom_half,    // selects which half to read
    input      [31:0]  rom_data,
    output reg         rom_cs,
    input              rom_ok
);

localparam [8:0] MAXH = 9'd448;

integer st;
reg [15:0] obj_attr;

reg         done;
wire [ 3:0] vsub;
wire [ 4:0] pal;
wire        hflip;
reg  [31:0] pxl_data;

assign vsub   = obj_attr[11:8];
//     vflip  = obj_attr[6];
assign hflip  = obj_attr[5];
assign pal    = obj_attr[4:0];

function [3:0] colour;
    input [31:0] c;
    input        flip;
    colour = flip ? { c[24], c[16], c[ 8], c[0] } : 
                    { c[31], c[23], c[15], c[7] };
endfunction

reg  [ 1:0] wait_cycle;
reg         last_tile;

`ifdef SIMULATION
reg busy;
reg busy_error;
reg last_start;

always @(posedge clk, posedge rst) begin
    if(rst) begin
        busy<=1'b0;
        busy_error<=1'b0;
        last_start<=1'b1;
    end else begin
        last_start <= start;
        if( start ) busy<=1'b1;
        if( done  ) busy<=1'b0;
        busy_error <= start && busy && !last_start;
    end
end
`endif

always @(posedge clk, posedge rst) begin
    if( rst ) begin
        table_addr <= 9'd0;
        rom_addr   <= 20'd0;
        rom_half   <= 1'd0;
        buf_wr     <= 1'b0;
        buf_data   <= 9'd0;
        buf_addr   <= 9'd0;
        st         <= 0;
        rom_cs     <= 1'b0;
        done       <= 1'b0;
    end else begin
        st <= st+1;
        case( st )
            0: begin
                buf_wr   <= 1'b0;
                rom_cs   <= 1'b0;
                if( !start ) st<=0;
                else begin
                    table_addr <= { 7'd0, 2'd0 };
                    wait_cycle <= 2'b1;
                    last_tile  <= 1'b0;
                    done       <= 0;
                end
            end
            1: begin
                wait_cycle <= { 1'b0, wait_cycle[1] };
                table_addr[1:0] <= table_addr[1:0]+2'd1;
                if( !wait_cycle ) begin
                    obj_attr   <= table_data;
                    wait_cycle <= 2'b1; // leave it on for next round
                end else st<=1;
            end
            2: begin
                // obj_code   <= table_data;
                //table_addr[1:0] <= table_addr[1:0]+2'd1;
                rom_cs   <= 1'b1;
                rom_addr <= { table_data, vsub };
                rom_half <= hflip;
            end
            3: begin
                buf_addr   <= table_data[8:0]-9'd1; // obj_x
                if( table_addr[8:2]==7'b111_0000 ) last_tile <= 1'b1; // some margin for SDRAM waits
                table_addr[8:2] <= table_addr[8:2]+7'd1;
                table_addr[1:0] <= 2'd0;
            end
            4: begin
                if( rom_ok ) begin
                    pxl_data <= rom_data;
                    rom_half <= ~rom_half;
                    if( &rom_data ) begin
                        st <= 10;// skip blank pixels but waste two clock cycles for rom_ok
                        // to renew
                        buf_addr <= buf_addr + 9'd5;
                    end
                end else st<=st;
            end
            5,6,7,8, 9,10,11,12,
            14,15,16,17, 18,19,20,21: begin
                buf_wr   <= 1'b1;
                buf_addr <= buf_addr+9'd1;
                buf_data <= { pal, colour(pxl_data, hflip) };
                pxl_data <= hflip ? pxl_data>>1 : pxl_data<<1;
            end
            13: begin
                if(rom_ok) begin
                    pxl_data <= rom_data;
                    rom_half <= ~rom_half;
                    if( &rom_data ) st <= 22; // skip blank pixels
                end else st<=st;
            end
            22: begin
                buf_wr <= 1'b0;
                if(last_tile) begin
                    done <= 1'b1;
                    st   <= 0;
                end
                else st<=1; // next element
            end
            default:;
        endcase

    end
end

endmodule
