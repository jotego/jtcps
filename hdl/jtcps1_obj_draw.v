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

    input      [ 7:0]  vrender, // 1 line ahead of vdump
    input      [ 7:0]  vdump,
    input      [ 8:0]  hdump,
    input              start,

    output reg [ 9:0]  table_addr,
    input      [15:0]  table_data,


    output reg [22:0]  rom_addr,    // up to 1 MB
    output reg         rom_half,    // selects which half to read
    input      [31:0]  rom_data,
    output reg         rom_cs,
    input              rom_ok,

    output reg [ 8:0]  pxl
);

integer st;
reg [15:0] obj_x, obj_y, obj_code, obj_attr;
reg [15:0] last_x, last_y, last_code, last_attr;

wire  repeated = (obj_x==last_x) && (obj_y==last_y) && 
                 (obj_code==last_code) && (obj_attr==last_attr);

reg  done;
reg  [3:0] n,m;  // tile expansion n==horizontal, m==verital
wire [3:0] tile_n, tile_m;

assign tile_n = obj_attr[11: 9];
assign tile_m = obj_attr[15:12];

always @(posedge clk, posedge rst) begin
    if( rst ) begin
        table_addr <= ~10'd0;
    end else begin
        case( st )
            0: begin
                if( !start ) st<=0;
                else begin
                    table_addr <= table_addr-10'd1; // start reading out the table
                    done       <= 0;
                end
            end
            1: begin
                last_attr  <= obj_attr;
                obj_attr   <= table_data;
                table_addr <= table_addr-10'd1;
            end
            2: begin
                last_code  <= obj_code;
                obj_code   <= table_data;
                table_addr <= table_addr-10'd1;
            end
            3: begin
                last_y     <= obj_y;
                obj_y      <= table_data;
                table_addr <= table_addr-10'd1;
            end
            4: begin
                last_x     <= obj_y;
                obj_x      <= table_data;
                table_addr <= table_addr-10'd1;
            end
            5: begin // check whether sprite is visible
                if( repeated || !inzone ) begin
                    if (table_addr==10'h3ff) begin
                        done <= 1'b1;
                        st   <= 0;
                    end
                    else st<= 1; // try next one
                end else begin // data request
                end
            end
        endcase

    end
end

endmodule