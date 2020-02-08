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

// Scroll 1 is 512x512, 8x8 tiles
// Scroll 2 is 1024x1024 16x16 tiles
// Scroll 3 is 2048x2048 32x32 tiles

module jtcps1_scroll(
    input              rst,
    input              clk,

    input      [ 8:0]  vrender, // 1 line ahead of vdump
    input      [ 8:0]  vdump,
    input      [ 8:0]  hdump,
    // control registers
    input      [15:0]  vram1_base,
    input      [15:0]  vram2_base,
    input      [15:0]  vram3_base,
    input      [15:0]  hpos1,
    input      [15:0]  vpos1,
    input      [15:0]  hpos2,
    input      [15:0]  vpos2,
    input      [15:0]  hpos3,
    input      [15:0]  vpos3,

    input              start,

    output     [17:1]  vram_addr,
    input      [15:0]  vram_data,
    input              vram_ok,
    output             vram_cs,

    output     [22:0]  rom_addr,    // up to 1 MB
    output             rom_half,    // selects which half to read
    input      [31:0]  rom_data,
    output             rom_cs,
    input              rom_ok,

    input      [ 3:0]  gfx_en,

    (*keep*)output reg [ 8:0]  scr1_pxl,
    (*keep*)output reg [ 8:0]  scr2_pxl,
    (*keep*)output reg [ 8:0]  scr3_pxl
);

reg         pre_start, sub_start, busy, done;
wire [ 8:0] buf_data;
wire [ 8:0] buf_addr;
wire        buf_wr;

reg  [15:0] hpos, vpos, vram_base;
reg  [ 2:0] st;
wire        sub_done;


wire [9:0] addr0 = {  vdump[0], buf_addr }; // write
wire [9:0] addr1 = { ~vdump[0], hdump    }; // read
wire [8:0] pre1_pxl, pre2_pxl, pre3_pxl;

wire       wr1 = buf_wr & st[0],
           wr2 = buf_wr & st[1],
           wr3 = buf_wr & st[2];

jtframe_dual_ram #(.dw(9), .aw(10)) u_line1(
    .clk0   ( clk       ),
    .clk1   ( clk       ),
    // Port 0: write
    .data0  ( buf_data  ),
    .addr0  ( addr0     ),
    .we0    ( wr1       ),
    .q0     (           ),
    // Port 1: read
    .data1  (           ),
    .addr1  ( addr1     ),
    .we1    ( 1'b0      ),
    .q1     ( pre1_pxl  )
);

jtframe_dual_ram #(.dw(9), .aw(10)) u_line2(
    .clk0   ( clk       ),
    .clk1   ( clk       ),
    // Port 0: write
    .data0  ( buf_data  ),
    .addr0  ( addr0     ),
    .we0    ( wr2       ),
    .q0     (           ),
    // Port 1: read
    .data1  (           ),
    .addr1  ( addr1     ),
    .we1    ( 1'b0      ),
    .q1     ( pre2_pxl  )
);

jtframe_dual_ram #(.dw(9), .aw(10)) u_line3(
    .clk0   ( clk       ),
    .clk1   ( clk       ),
    // Port 0: write
    .data0  ( buf_data  ),
    .addr0  ( addr0     ),
    .we0    ( wr3       ),
    .q0     (           ),
    // Port 1: read
    .data1  (           ),
    .addr1  ( addr1     ),
    .we1    ( 1'b0      ),
    .q1     ( pre3_pxl  )
);

// Line buffers
always @(posedge clk, posedge rst) begin
    if( rst ) begin
        scr1_pxl <= 9'h1ff;
        scr2_pxl <= 9'h1ff;
        scr3_pxl <= 9'h1ff;
    end else begin
        if( hdump>9'd63 && hdump<9'd448 ) begin // active area
            scr1_pxl <= pre1_pxl;
            scr2_pxl <= pre2_pxl;
            `ifndef NOSCROLL3
            scr3_pxl <= pre3_pxl;
            `endif
        end else begin
            scr1_pxl <= 9'h1ff;
            scr2_pxl <= 9'h1ff;
            scr3_pxl <= 9'h1ff;
        end
    end
end

// Tilemap sequencer
always @(posedge clk, posedge rst) begin
    if( rst ) begin
        busy      <= 1'b0;
        st        <= 3'b1;
        sub_start <= 1'b0;
        pre_start <= 1'b0;
        done      <= 1'b0;
    end else begin
        done      <= 1'b0;
        if( start ) begin
            busy      <= 1'b1;
            st        <= 3'b1;
            pre_start <= 1'b1;
            hpos      <= hpos1;
            vpos      <= vpos1;
            vram_base <= vram1_base;
        end else if( busy ) begin
            pre_start <= 1'b0;
            sub_start <= pre_start;
            case( st )
                3'b001: begin
                    if( sub_done ) begin
                        hpos      <= hpos2;
                        vpos      <= vpos2;
                        vram_base <= vram2_base;
                        pre_start <= 1'b1;
                        st        <= 3'b10;
                    end
                end
                3'b010: begin
                    if( sub_done ) begin
                        hpos      <= hpos3;
                        vpos      <= vpos3;
                        vram_base <= vram3_base;
                        pre_start <= 1'b1;
                        st        <= 3'b100;
                    end
                end
                3'b100: begin
                    if( sub_done ) begin
                        done <= 1'b1;
                        busy <= 1'b0;
                    end
                end
            endcase
        end
    end
end

jtcps1_tilemap u_tilemap(
    .rst        ( rst           ),
    .clk        ( clk           ),

    .vrender    ( vrender       ),
    .size       ( st            ),
    // control registers
    .vram_base  ( vram_base     ),
    .hpos       ( hpos          ),
    .vpos       ( vpos          ),

    .start      ( sub_start     ),
    .done       ( sub_done      ),

    .vram_addr  ( vram_addr     ),
    .vram_data  ( vram_data     ),
    .vram_ok    ( vram_ok       ),
    .vram_cs    ( vram_cs       ),

    .rom_addr   ( rom_addr      ),    // up to 1 MB
    .rom_half   ( rom_half      ),    // selects which half to read
    .rom_data   ( rom_data      ),
    .rom_cs     ( rom_cs        ),
    .rom_ok     ( rom_ok        ),

    .buf_addr   ( buf_addr      ),
    .buf_wr     ( buf_wr        ),
    .buf_data   ( buf_data      )
);

endmodule
