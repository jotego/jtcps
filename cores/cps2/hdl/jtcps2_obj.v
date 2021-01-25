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
    Date: 24-1-2021 */


module jtcps2_obj(
    input              rst,
    input              clk,
    input              clk_cpu,
    input              pxl_cen,
    input              flip,

    // Interface with CPU
    input              objram_cs,
    input      [ 1:0]  main_dsn,
    input      [15:0]  main_dout,
    input      [13:1]  main_addr,

    input              obank,

    input              start,
    input      [ 8:0]  vrender,  // 1 line  ahead of vdump
    input      [ 8:0]  vdump,
    input      [ 8:0]  hdump,

    output     [19:0]  rom_addr,    // up to 1 MB
    output             rom_half,    // selects which half to read
    input      [31:0]  rom_data,
    output             rom_cs,
    input              rom_ok,

    output     [ 8:0]  pxl
);

wire [15:0] dr_code, dr_attr;
wire [ 8:0] dr_hpos;

wire        dr_start, dr_idle;

wire [15:0] line_data;
wire [ 8:0] line_addr;

wire [ 8:0] buf_addr, buf_data;
wire        buf_wr;

// shadow RAM interface
wire [ 9:0] table_attr;
wire [15:0] obj_x, obj_y, obj_code, obj_attr;

jtcps2_objram u_objram(
    .rst        ( rst           ),
    .clk_cpu    ( clk_cpu       ),
    .clk_gfx    ( clk           ),

    .obank      ( obank         ),

    // Interface with CPU
    .cs         ( objram_cs     ),
    .ok         (               ),
    .dsn        ( main_dsn      ),
    .main_dout  ( main_dout     ),
    .main_addr  ( main_addr     ),

    // Interface with OBJ engine
    .obj_addr   ( table_attr    ),
    .obj_x      ( obj_x         ),
    .obj_y      ( obj_y         ),
    .obj_code   ( obj_code      ),
    .obj_attr   ( obj_attr      )
);

jtcps2_obj_scan u_scan(
    .rst        ( rst           ),
    .clk        ( clk           ),
    .flip       ( flip          ),

    .start      ( start         ),
    .vrender    ( vrender       ),

    // interface with frame table
    .table_addr ( table_attr    ),
    .table_x    ( obj_x         ),
    .table_y    ( obj_y         ),
    .table_code ( obj_code      ),
    .table_attr ( obj_attr      ),

    // interface with renderer
    .dr_start   ( dr_start      ),
    .dr_idle    ( dr_idle       ),

    .dr_code    ( dr_code       ),
    .dr_attr    ( dr_attr       ),
    .dr_hpos    ( dr_hpos       )
);

jtcps1_obj_draw u_draw(
    .rst        ( rst           ),
    .clk        ( clk           ),

    .start      ( dr_start      ),
    .idle       ( dr_idle       ),

    .obj_code   ( dr_code       ),
    .obj_attr   ( dr_attr       ),
    .obj_hpos   ( dr_hpos       ),

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
    .flip       ( flip          ),

    .vdump      ( vdump[0]      ),
    .hdump      ( hdump         ),

    .buf_addr   ( buf_addr      ),
    .buf_data   ( buf_data      ),
    .buf_wr     ( buf_wr        ),

    .pxl        ( pxl           )
);

endmodule