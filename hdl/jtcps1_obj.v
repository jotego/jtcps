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

module jtcps1_obj(
    input              rst,
    input              clk,
    input              pxl_cen,

    // input              HB,
    input              VB,

    input              start,
    input      [ 8:0]  vrender,  // 1 line  ahead of vdump
    input      [ 8:0]  vrender1, // 2 lines ahead of vdump
    input      [ 8:0]  vdump,
    input      [ 8:0]  hdump,

    // ROM banks
    input      [ 5:0]  game,
    input      [15:0]  bank_offset,
    input      [15:0]  bank_mask,

    // control registers
    input      [15:0]  vram_base,
    output     [17:1]  vram_addr,
    input      [15:0]  vram_data,
    input              vram_ok,
    output             vram_cs,

    output     [19:0]  rom_addr,    // up to 1 MB
    output             rom_half,    // selects which half to read
    input      [31:0]  rom_data,
    output             rom_cs,
    input              rom_ok,

    output     [ 8:0]  pxl
);

wire [15:0] frame_data, line_data;
wire [ 9:0] frame_addr;
wire [ 8:0] line_addr;

wire [ 8:0] buf_addr, buf_data;
wire        buf_wr;

jtcps1_obj_table u_table(
    .rst        ( rst           ),
    .clk        ( clk           ),
    .VB         ( VB            ),

    // OBJ renderization
    .table_addr ( frame_addr    ),
    .table_data ( frame_data    ),

    // VRAM
    .vram_base  ( vram_base     ),
    .vram_addr  ( vram_addr     ),
    .vram_data  ( vram_data     ),
    .vram_ok    ( vram_ok       ),
    .vram_cs    ( vram_cs       )

);

jtcps1_obj_line_table u_line_table(
    .rst        ( rst           ),
    .clk        ( clk           ),

    .start      ( start         ),
    .vrender1   ( vrender1      ),

    // ROM banks
    .game       ( game          ),
    .bank_offset( bank_offset   ),
    .bank_mask  ( bank_mask     ),

    // interface with frame table
    .frame_addr ( frame_addr    ),
    .frame_data ( frame_data    ),

    // interface with renderer
    .line_addr  ( line_addr     ),
    .line_data  ( line_data     )
);

jtcps1_obj_draw u_draw(
    .rst        ( rst           ),
    .clk        ( clk           ),

    .start      ( start         ),

    .table_addr ( line_addr     ),
    .table_data ( line_data     ),

    .buf_addr   ( buf_addr      ),
    .buf_data   ( buf_data      ),
    .buf_wr     ( buf_wr        ),

    .rom_addr   ( rom_addr[19:0]),
    .rom_half   ( rom_half      ),
    .rom_data   ( rom_data      ),
    .rom_cs     ( rom_cs        ),
    .rom_ok     ( rom_ok        )
);

jtcps1_obj_line u_line(
    .clk        ( clk           ),
    .pxl_cen    ( pxl_cen       ),

    .vdump      ( vdump[0]      ),
    .hdump      ( hdump         ),

    .buf_addr   ( buf_addr      ),
    .buf_data   ( buf_data      ),
    .buf_wr     ( buf_wr        ),

    .pxl        ( pxl           )
);

endmodule