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

module jtcps1_tilemap(
    input              rst,
    input              clk,

    input    [8:0]     v,
    // control registers
    input    [15:0]    vram_base,
    input    [15:0]    hpos,
    input    [15:0]    vpos,

    input              start,
    output             done,

    output             vram_addr,
    input    [15:0]    vram_data,
    input              vram_ok,
    output             vram_cs,

    output reg [19:0]  rom_addr,    // up to 1 MB
    input      [15:0]  rom_data,
    output reg         rom_cs,
    input              rom_ok,

    output reg [ 8:0]  buf_addr,
    output reg [ 7:0]  buf_data,
    output reg         buf_wr
);

parameter SIZE=8; // 8, 16 or 32
reg [ 9:0] vn;
reg [ 8:0] hn;
reg [15:0] pxl_data;

reg [ 5:0] st;

reg [21:0] tile_addr;
reg [15:0] code,attr;

always @(posedge clk or posedge rst) begin
    if(rst) begin
        rom_cs  <= 1'b0;
        vram_cs <= 1'b0;
        buf_wr  <= 1'b0;
        st      <= 0;
    end else begin
        case( st ) begin
            0: begin
                rom_cs   <= 1'b0;
                vram_cs  <= 1'b0;
                vn       <= vpos + v;
                hn       <= hpos;
                buf_addr <= 9'd0;
                buf_wr   <= 1'b0;
                if(!start) st<=0;
            end
            1: begin
                vram_addr <= {scan, 1'b0};
                vram_cs   <= 1'b1;
                if( buf_addr== 9'd383 ) begin
                    buf_wr <= 1'b0;
                    done   <= 1'b1;
                    st     <= 1'b0;
                end
            end
            3: if( vram_ok ) begin
                code         <= vram_data;
                vram_addr[0] <= 1'b1;
                st <= 50
            end else st<=3;
            50: if( vram_ok ) begin
                attr    <= vram_data;
                vram_cs <= 1'b0;
                st <= 4
            end
            4: begin
                tile_addr <= 
                rom_cs    <= 1'b1;
            end
            6: if(rom_ok) begin
                pxl_data <= rom_data;   // 16 bits = 16/4 = 4 pixels
                hn <= hn + 9'd4;
            end
            7,8,9,10,    12,13,14,15, 
            17,18,19,20, 22,23,24,25,
            27,28,29,30, 32,33,34,35,
            37,38,39,40, 42,43,44,45: begin
                buf_wr   <= 1'b1;
                buf_addr <= buf_addr+9'd1;
                buf_data <= colour(pxl_data);
                pxl_data <= pxl_data>>1;
            end
            11, 21, 31, 36, 41: if(rom_ok) begin // next 4 pixels
                pxl_data <= rom_data;
                hn <= hn + 9'd4;
            end
            16: begin
                if( SIZE==8 ) begin
                    st <= 1; // scan again
                end else if(rom_ok) begin
                    pxl_data <= rom_data;
                    hn <= hn + 9'd4;    // pixels 8-12
                end
            end
            26: begin
                if( SIZE==16 ) begin
                    st <= 1; // scan again
                end else if(rom_ok) begin
                    pxl_data <= rom_data;
                    hn <= hn + 9'd4; // pixels 16-20
                end
            end
            46: st <= 1; // end
        end
    end
end

endmodule