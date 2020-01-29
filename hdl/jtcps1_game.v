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
    Date: 28-1-2020 */
`timescale 1ns/1ps

module jtcps1_game(
    input           rst,
    input           clk,
    output          pxl2_cen,   // 12   MHz
    output          pxl_cen,    //  6   MHz
    output   [4:0]  red,
    output   [4:0]  green,
    output   [4:0]  blue,
    output          LHBL,
    output          LVBL,
    output          LHBL_dly,
    output          LVBL_dly,
    output          HS,
    output          VS,
    // cabinet I/O
    input   [ 1:0]  start_button,
    input   [ 1:0]  coin_input,
    input   [ 7:0]  joystick1,
    input   [ 7:0]  joystick2,
    // SDRAM interface
    input           downloading,
    output          dwnld_busy,
    input           loop_rst,
    output          sdram_req,
    output  [21:0]  sdram_addr,
    input   [31:0]  data_read,
    input           data_rdy,
    input           sdram_ack,
    output          refresh_en,
    // ROM LOAD
    input   [21:0]  ioctl_addr,
    input   [ 7:0]  ioctl_data,
    input           ioctl_wr,
    output  [21:0]  prog_addr,
    output  [ 7:0]  prog_data,
    output  [ 1:0]  prog_mask,
    output          prog_we,
    output          prog_rd,
    // DIP switches
    input   [31:0]  status,     // only bits 31:16 are looked at
    input           dip_pause,
    input           dip_flip,
    input           dip_test,
    input   [ 1:0]  dip_fxlevel, // Not a DIP on the original PCB    
    // Sound output
    output  signed [15:0] snd_left,
    output  signed [15:0] snd_right,
    output          sample,
    input           enable_psg,
    input           enable_fm,
    // Debug
    input   [3:0]   gfx_en
);

wire        snd_cs, main_ram_cs, main_rom_cs,
            rom0_cs, rom1_cs, rom2_cs, rom3_cs,
            vram1_cs, vram2_cs, vram3_cs, vram_obj_cs;
wire        HB, VB;
wire [15:1] ram_addr;
wire [23:1] main_addr; // common to RAM/ROM
wire [15:0] main_ram_data, main_rom_data;
wire        main_rom_ok, main_ram_ok;
wire        ppu1_cs, ppu_rstn;

wire        main_rnw, busreq, busack;
wire [ 7:0] snd0_latch, snd1_latch;
wire [ 7:0] dipsw_a, dipsw_b, dipsw_c;

wire [9:0] slot_cs, slot_ok, slot_wr;

assign snd_cs = 1'b0;
assign slot_cs[0] = main_rom_cs;
assign slot_cs[1] = main_ram_cs;
assign slot_cs[2] = rom0_cs;
assign slot_cs[3] = vram1_cs;
assign slot_cs[4] = vram2_cs;
assign slot_cs[5] = vram3_cs;
assign slot_cs[6] = rom1_cs;
assign slot_cs[7] = rom2_cs;
assign slot_cs[8] = rom3_cs;
assign slot_cs[9] = vram_obj_cs;

assign main_rom_ok = slot_ok[0];
assign main_ram_ok = slot_ok[1];
assign rom0_ok     = slot_ok[2];
assign vram1_ok    = slot_ok[3];
assign vram2_ok    = slot_ok[4];
assign vram3_ok    = slot_ok[5];
assign rom1_ok     = slot_ok[6];
assign rom2_ok     = slot_ok[7];
assign rom3_ok     = slot_ok[8];
assign vram_obj_ok = slot_ok[9];

assign slot_wr[9:2] = 7'd0;
assign slot_wr[1]   = main_rnw;
assign slot_wr[0]   = 1'd0;

assign LVBL         = ~VB;
assign LHBL         = ~HB;

wire [31:0] data_write;
wire        sdram_rnw;
wire [ 1:0] dsn;
wire        cen8, cen10, cen10b;

// Timing
jtframe_cen48 u_cen48(
    .clk        ( clk           ),
    .cen12      (               ),
    .cen8       ( cen8          ),
    .cen6       (               ),
    .cen4       (               ),
    .cen3       (               ),
    .cen3q      (               ),
    .cen1p5     (               ),
    // 180 shifted signals
    .cen12b     (               ),
    .cen6b      (               ),
    .cen3b      (               ),
    .cen3qb     (               ),
    .cen1p5b    (               )
);

jtframe_frac_cen #(.W(1))u_cen10(
    .clk        ( clk           ),
    .n          ( 10'd5         ),
    .m          ( 10'd24        ),
    .cen        ( cen10         ),
    .cenb       ( cen10b        ) // 180 shifted
);

jtcps1_main(
    .rst        ( rst               ),
    .clk        ( clk               ),
    .cen10      ( cen10             ),
    .cen10b     ( cen10b            ),
    // Timing
    // input   [8:0]      V,
    .LVBL       ( LVBL              ),
    // PPU
    .ppu1_cs    ( ppu1_cs           ),
    .ppu_rstn   ( ppu_rstn          ),
    // Sound
    .snd0_latch ( snd0_latch        ),
    .snd1_latch ( snd1_latch        ),
    .UDSWn      ( dsn[1]            ),
    .LDSWn      ( dsn[0]            ),
    // cabinet I/O
    // Cabinet input
    .start_button( start_button     ),
    .coin_input  ( coin_input       ),
    .joystick1   ( joystick1        ),
    .joystick2   ( joystick2        ),
    .service     ( 1'b1             ),
    .tilt        ( 1'b1             ),
    // BUS sharing
    .busreq      ( busreq           ),
    .busack      ( busack           ),
    .RnW         ( main_rnw         ),
    // RAM/VRAM access
    .ram_cs      ( main_ram_cs      ),
    .ram_addr    ( ram_addr         ),
    .ram_data    ( main_ram_data    ),
    .ram_ok      ( main_ram_ok      ),
    // ROM access
    .rom_cs      ( main_rom_cs      ),
    .rom_addr    ( main_addr        ),
    .rom_data    ( main_rom_data    ),
    .rom_ok      ( main_rom_ok      ),
    // DIP switches
    .dip_pause   ( dip_pause        ),
    .dip_test    ( dip_test         ),
    .dipsw_a     ( dipsw_a          ),
    .dipsw_b     ( dipsw_b          ),
    .dipsw_c     ( dipsw_c          )
);

jtcps1_video u_video(
    .rst            ( rst           ),
    .clk            ( clk           ),
    .pxl_cen        ( cen8          ),

    .hdump          ( hdump         ),
    .vdump          ( vdump         ),
    .vrender        ( vrender       ),
    .frame          ( frame         ),


    // CPU interface
    .ppu_rstn       ( ppu_rstn      ),
    .ppu1_cs        ( ppu1_cs       ),
    .ppu2_cs        ( ppu2_cs       ),
    .addr           ( addr          ),
    .dsn            ( dsn           ),      // data select, active low
    .cpu_dout       ( cpu_dout      ),
    .mmr_dout       ( mmr_dout      ),

    // Video signal
    .HS             ( HS            ),
    .VS             ( VS            ),
    .HB             ( HB            ),
    .VB             ( VB            ),
    .LHBL_dly       ( LHBL_dly      ),
    .LVBL_dly       ( LVBL_dly      ),
    .red            ( red           ),
    .green          ( green         ),
    .blue           ( blue          ),

    // Video RAM interface
    .vram1_addr     ( vram1_addr    ),
    .vram1_data     ( vram1_data    ),
    .vram1_ok       ( vram1_ok      ),
    .vram1_cs       ( vram1_cs      ),

    .vram2_addr     ( vram2_addr    ),
    .vram2_data     ( vram2_data    ),
    .vram2_ok       ( vram2_ok      ),
    .vram2_cs       ( vram2_cs      ),

    .vram3_addr     ( vram3_addr    ),
    .vram3_data     ( vram3_data    ),
    .vram3_ok       ( vram3_ok      ),
    .vram3_cs       ( vram3_cs      ),

    .vram_obj_addr  ( vram_obj_addr ),
    .vram_obj_data  ( vram_obj_data ),
    .vram_obj_ok    ( vram_obj_ok   ),
    .vram_obj_cs    ( vram_obj_cs   ),

    // GFX ROM interface
    .rom1_addr  ( rom1_addr     ),
    .rom1_bank  ( rom1_bank     ),
    .rom1_half  ( rom1_half     ),
    .rom1_data  ( rom1_data     ),
    .rom1_cs    ( rom1_cs       ),
    .rom1_ok    ( rom1_ok       ),

    .rom2_addr  ( rom2_addr     ),
    .rom2_bank  ( rom2_bank     ),
    .rom2_half  ( rom2_half     ),
    .rom2_data  ( rom2_data     ),
    .rom2_cs    ( rom2_cs       ),
    .rom2_ok    ( rom2_ok       ),

    .rom3_addr  ( rom3_addr     ),
    .rom3_bank  ( rom3_bank     ),
    .rom3_half  ( rom3_half     ),
    .rom3_data  ( rom3_data     ),
    .rom3_cs    ( rom3_cs       ),
    .rom3_ok    ( rom3_ok       ),

    .rom0_addr  ( rom0_addr      ),
    .rom0_bank  ( rom0_bank      ),
    .rom0_half  ( rom0_half      ),
    .rom0_data  ( rom0_data      ),
    .rom0_cs    ( rom0_cs        ),
    .rom0_ok    ( rom0_ok        )
);

jtframe_sdram_mux #(
    // Main CPU
    .SLOT0_AW   ( 19    ),  // Max 1 Megabyte
    .SLOT1_AW   ( 17    ),  // 64 kB RAM, 192 kB VRAM

    .SLOT0_DW   ( 16    ),
    .SLOT1_DW   ( 16    ),

    .SLOT1_TYPE ( 2     ), // R/W access
    // VRAM read access:
    .SLOT3_AW   ( 18    ),
    .SLOT4_AW   ( 18    ),  //4
    .SLOT5_AW   ( 18    ),  //5
    .SLOT9_AW   ( 18    ),  // OBJ VRAM

    .SLOT3_DW   ( 16    ),
    .SLOT4_DW   ( 16    ),
    .SLOT5_DW   ( 16    ),
    .SLOT9_DW   ( 16    ),
    // GFX ROM
    .SLOT2_AW   ( 22    ),  // OBJ VRAM
    .SLOT6_AW   ( 22    ),  //6
    .SLOT7_AW   ( 22    ),  //7
    .SLOT8_AW   ( 22    ),  //8

    .SLOT2_DW   ( 32    ),
    .SLOT6_DW   ( 32    ),
    .SLOT7_DW   ( 32    ),
    .SLOT8_DW   ( 32    )
)
u_sdram_mux(
    .rst            ( rst           ),
    .clk            ( clk           ),
    .vblank         ( 1'b0          ),

    // Main CPU
    .slot0_offset   ( main_rom_offset   ),
    .slot0_addr     ( main_addr         ),
    .slot0_dout     ( main_rom_data     ),

    .slot1_offset   ( main_ram_offset   ),
    .slot1_addr     ( main_addr         ),
    .slot1_dout     ( main_ram_data     ),

    // VRAM read access only
    .slot9_offset   ( vram_offset       ),
    .slot9_addr     ( vram_obj_addr[18:1]  ),
    .slot9_dout     ( vram_obj_data     ),

    .slot3_offset   ( vram_offset       ),
    .slot3_addr     ( vram1_addr[18:1]  ),
    .slot3_dout     ( vram1_data        ),

    .slot4_offset   ( vram_offset       ),
    .slot4_addr     ( vram2_addr[18:1]  ),
    .slot4_dout     ( vram2_data        ),

    .slot5_offset   ( vram_offset       ),
    .slot5_addr     ( vram3_addr[18:1]  ),
    .slot5_dout     ( vram3_data        ),

    // GFX ROM
    .slot2_offset   ( gfx_offset        ),
    .slot2_addr     ( gfx0_addr         ),
    .slot2_dout     ( rom0_data         ),

    .slot6_offset   ( gfx_offset        ),
    .slot6_addr     ( gfx1_addr         ),
    .slot6_dout     ( rom1_data         ),

    .slot7_offset   ( gfx_offset        ),
    .slot7_addr     ( gfx2_addr         ),
    .slot7_dout     ( rom2_data         ),

    .slot8_offset   ( gfx_offset        ),
    .slot8_addr     ( gfx3_addr         ),
    .slot8_dout     ( rom3_data         ),

    // bus signals
    .slot_cs        ( slot_cs       ),
    .slot_ok        ( slot_ok       ),
    .slot_wr        ( slot_wr       ),

    // SDRAM controller interface
    .downloading    ( downloading   ),
    .loop_rst       ( loop_rst      ),
    .sdram_ack      ( sdram_ack     ),
    .sdram_req      ( sdram_req     ),
    .refresh_en     ( refresh_en    ),
    .sdram_addr     ( sdram_addr    ),
    .sdram_rnw      ( sdram_rnw     ),
    .data_rdy       ( data_rdy      ),
    .data_read      ( data_read     ),   
    .data_write     ( data_write    )
);

endmodule
