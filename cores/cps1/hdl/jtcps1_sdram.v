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
    Date: 5-12-2020 */

module jtcps1_sdram #( parameter
           CPS     = 1,
           REGSIZE = 24,
           Z80_AW  = CPS==1 ? 16 : 19,
           PCM_AW  = CPS==1 ? 18 : 23
) (
    input           rst,
    input           clk,        // SDRAM clock (48/96)
    input           clk_gfx,    // 96 MHz
    input           clk_cpu,    // 48 MHz
    input           LVBL,

    input           downloading,
    output          dwnld_busy,
    output          cfg_we,

    // ROM LOAD
    input   [25:0]  ioctl_addr,
    input   [ 7:0]  ioctl_data,
    output  [ 7:0]  ioctl_data2sd,
    input           ioctl_wr,
    input           ioctl_ram,
    output  [22:0]  prog_addr,
    output  [15:0]  prog_data,
    output  [ 1:0]  prog_mask,
    output  [ 1:0]  prog_ba,
    output          prog_we,
    output          prog_rd,
    input           prog_rdy,
    output          prog_qsnd,

    // EEPROM
    input           sclk,
    input           sdi,
    output          sdo,
    input           scs,

    // Kabuki decoder (CPS 1.5)
    output          kabuki_we,

    // CPS2 Keys
    output          cps2_key_we,
    output   [ 1:0] cps2_joymode,

    // Main CPU
    input           main_rom_cs,
    output          main_rom_ok,
    input    [20:0] main_rom_addr,
    output   [15:0] main_rom_data,

    // VRAM
    input           vram_clr,
    input           vram_dma_cs,
    input           main_ram_cs,
    input           main_vram_cs,
    input           main_oram_cs,
    `ifdef CPS2
    input           obank,
    input    [12:0] gfx_oram_addr,
    output   [15:0] gfx_oram_data,
    output          gfx_oram_ok,
    `endif
    input           vram_rfsh_en,

    input    [ 1:0] dsn,
    input    [15:0] main_dout,
    input           main_rnw,

    output          main_ram_ok,
    output          vram_dma_ok,

    input    [17:1] main_ram_addr,
    input    [17:1] vram_dma_addr,

    output   [15:0] main_ram_data,
    output   [15:0] vram_dma_data,

    // Sound CPU and PCM
    input           snd_cs,
    input           pcm_cs,

    output          snd_ok,
    output          pcm_ok,

    input [Z80_AW-1:0] snd_addr,
    input [PCM_AW-1:0] pcm_addr,

    output     [7:0] snd_data,
    output     [7:0] pcm_data,

    // Graphics
    input           rom0_cs,
    input           rom1_cs,

    output          rom0_ok,
    output          rom1_ok,

    input    [19:0] rom0_addr,
    input    [ 1:0] rom0_bank,
    input    [19:0] rom1_addr,

    input           rom0_half,
    input           rom1_half,

    output   [31:0] rom0_data,
    output   [31:0] rom1_data,

    // Bank 0: allows R/W
    output   [22:0] ba0_addr,
    output          ba0_rd,
    output          ba0_wr,
    output   [15:0] ba0_din,
    output   [ 1:0] ba0_din_m,  // write mask
    input           ba0_rdy,
    input           ba0_ack,

    // Bank 1: Read only
    output   [22:0] ba1_addr,
    output          ba1_rd,
    input           ba1_rdy,
    input           ba1_ack,

    // Bank 2: Read only
    output   [22:0] ba2_addr,
    output          ba2_rd,
    input           ba2_rdy,
    input           ba2_ack,

    // Bank 3: Read only
    output   [22:0] ba3_addr,
    output          ba3_rd,
    input           ba3_rdy,
    input           ba3_ack,

    input    [31:0] data_read,
    output    reg   refresh_en
);

localparam [22:0] ZERO_OFFSET  = 23'h0,
                  PCM_OFFSET   = ZERO_OFFSET,
                  VRAM_OFFSET  = 23'h20_0000,
                  ORAM_OFFSET  = 23'h28_0000,
                  WRAM_OFFSET  = 23'h30_0000,
                  SND_OFFSET   = 23'h38_0000,
                  ROM_OFFSET   = ZERO_OFFSET;

`ifdef CPS2
    localparam [22:0] SCR_OFFSET = 23'h00_0000; // change this when moving to 8MB+ GFX
    localparam        CPS2       = 1;
`else
    localparam [22:0] SCR_OFFSET = ZERO_OFFSET;
    localparam        CPS2       = 0;

    wire [12:0] gfx_oram_addr = 13'd0;
    wire [15:0] gfx_oram_data;
    wire        gfx_oram_ok;
`endif

`ifdef CPS15
localparam EEPROM_AW=7;
`else
localparam EEPROM_AW=6;
`endif

(*keep*) wire [22:0] cps2_gfx0;
wire [21:0] gfx1_addr, gfx0_addr;
wire [22:0] main_offset;
wire        ram_vram_cs;
wire        ba2_rdy_gfx, ba2_ack_gfx;
reg  [17:1] main_addr_x; // main addr modified for object bank access
reg         ocache_clr, obank_last;

// EEPROM
wire [EEPROM_AW-1:0] dump_addr;
wire [15:0] dump_din, dump_dout;
wire        dump_we;

assign gfx0_addr   = {rom0_addr, rom0_half, 1'b0 }; // OBJ
assign gfx1_addr   = {rom1_addr, rom1_half, 1'b0 };
assign ram_vram_cs = main_ram_cs | main_vram_cs | main_oram_cs;
assign main_offset = main_oram_cs ? ORAM_OFFSET :
                    (main_ram_cs  ? WRAM_OFFSET : VRAM_OFFSET );
assign prog_rd     = 0;

always @(*) begin
    main_addr_x = main_ram_addr;
    `ifdef CPS2
    if( main_oram_cs ) begin
        main_addr_x[17:14]  = 4'd0;
        main_addr_x[13] = main_ram_addr[15] ^ obank;
    end
    `endif
end

always @(posedge clk) begin
    refresh_en <= ~LVBL & vram_rfsh_en;
end

jtcps1_prom_we #(
    .CPS        ( CPS           ),
    .REGSIZE    ( REGSIZE       ),
    .CPU_OFFSET ( ZERO_OFFSET   ),
    .PCM_OFFSET ( PCM_OFFSET    ),
    .SND_OFFSET ( SND_OFFSET    ),
    .EEPROM_AW  ( EEPROM_AW     )
) u_prom_we(
    .clk            ( clk           ),
    .downloading    ( downloading   ),
`ifdef MIST
    // This prevents a 1'bz for MSB in simulation
    // Not important for implementation
    .ioctl_addr     ( {1'b0, ioctl_addr[24:0] } ),
`else
    .ioctl_addr     ( ioctl_addr    ),
`endif
    .ioctl_data     ( ioctl_data    ),
    .ioctl_data2sd  ( ioctl_data2sd ),
    .ioctl_wr       ( ioctl_wr      ),
    .ioctl_ram      ( ioctl_ram     ),
    .prog_addr      ( prog_addr     ),
    .prog_data      ( prog_data     ),
    .prog_mask      ( prog_mask     ),
    .prog_ba        ( prog_ba       ),
    .prog_we        ( prog_we       ),
    .prog_rdy       ( prog_rdy      ),
    .cfg_we         ( cfg_we        ),
    .dwnld_busy     ( dwnld_busy    ),
    // EEPROM
    .dump_din       ( dump_din      ),
    .dump_dout      ( dump_dout     ),
    .dump_addr      ( dump_addr     ),
    .dump_we        ( dump_we       ),
    // QSound & Kabuki keys
    .prom_we        ( prog_qsnd     ),
    .kabuki_we      ( kabuki_we     ),
    // CPS2
    .cps2_key_we    ( cps2_key_we   ),
    .joymode        ( cps2_joymode  )
);

jtframe_ram_5slots #(
    .SDRAMW      ( 23            ),
    .SLOT0_AW    ( 17            ), // Main CPU RAM
    .SLOT0_DW    ( 16            ),

    .SLOT1_AW    ( 17            ), // VRAM - read only access
    .SLOT1_DW    ( 16            ),

    .SLOT2_AW    ( 13            ), // VRAM - read only access
    .SLOT2_DW    ( 16            ),

    .SLOT3_AW    ( 21            ), // Main CPU ROM
    .SLOT3_DW    ( 16            ),
    .LATCH3      (  1            ),

    .SLOT4_AW    ( Z80_AW        ), // Sound CPU
    .SLOT4_DW    (  8            )
    //.SLOT4_REPACK(  1            )

) u_bank0 (
    .rst         ( rst           ),
    .clk         ( clk           ),

    .offset0     ( main_offset   ),
    .offset1     ( VRAM_OFFSET   ),
    .offset2     ( ORAM_OFFSET   ),
    .offset3     (  ROM_OFFSET   ),
    .offset4     (  SND_OFFSET   ),

    .slot0_cs    ( ram_vram_cs   ),
    .slot0_wen   ( !main_rnw     ),
    .slot1_cs    ( vram_dma_cs   ),
    .slot1_clr   ( vram_clr      ),
    .slot2_cs    ( CPS2[0]       ),
    .slot2_clr   ( vram_clr      ),
    .slot3_cs    ( main_rom_cs   ),
    .slot3_clr   ( 1'b0          ),
    .slot4_cs    ( snd_cs        ),
    .slot4_clr   ( 1'b0          ),

    .slot0_ok    ( main_ram_ok   ),
    .slot1_ok    ( vram_dma_ok   ),
    .slot2_ok    ( gfx_oram_ok   ),
    .slot3_ok    ( main_rom_ok   ),
    .slot4_ok    ( snd_ok        ),

    .slot0_din   ( main_dout     ),
    .slot0_wrmask( dsn           ),

    .slot0_addr  ( main_addr_x   ),
    .slot1_addr  ( vram_dma_addr ),
    .slot2_addr  ( gfx_oram_addr ),
    .slot3_addr  ( main_rom_addr ),
    .slot4_addr  ( snd_addr      ),

    .slot0_dout  ( main_ram_data ),
    .slot1_dout  ( vram_dma_data ),
    .slot2_dout  ( gfx_oram_data ),
    .slot3_dout  ( main_rom_data ),
    .slot4_dout  ( snd_data      ),

    // SDRAM interface
    .sdram_addr  ( ba0_addr      ),
    .sdram_rd    ( ba0_rd        ),
    .sdram_wr    ( ba0_wr        ),
    .sdram_ack   ( ba0_ack       ),
    .data_rdy    ( ba0_rdy       ),
    .data_write  ( ba0_din       ),
    .sdram_wrmask( ba0_din_m     ),
    .data_read   ( data_read     )
);

jtframe_rom_1slot #(
    .SDRAMW      ( 23            ),
    .SLOT0_AW    ( PCM_AW        ), // PCM
    .SLOT0_DW    (  8            ),
    .SLOT0_REPACK( 1             )
) u_bank1 (
    .rst         ( rst           ),
    .clk         ( clk           ),

    .slot0_cs    ( pcm_cs        ),
    .slot0_ok    ( pcm_ok        ),
    .slot0_addr  ( pcm_addr      ),
    .slot0_dout  ( pcm_data      ),

    .sdram_addr  ( ba1_addr      ),
    .sdram_req   ( ba1_rd        ),
    .sdram_ack   ( ba1_ack       ),
    .data_rdy    ( ba1_rdy       ),
    .data_read   ( data_read     )
);

wire [ 1:0] objgfx_cs, objgfx_ok;
wire [31:0] objgfx_dout0, objgfx_dout1;

`ifdef CPS2
    assign objgfx_cs = {2{rom0_cs}} & { rom0_bank[0], ~rom0_bank[0] };
    assign rom0_ok   = rom0_bank[0] ? objgfx_ok[1] : objgfx_ok[0];
    assign rom0_data = rom0_bank[0] ? objgfx_dout1 : objgfx_dout0;
    assign cps2_gfx0 = { rom0_bank[1], gfx0_addr };

    jtframe_rom_1slot #(
        .SDRAMW      ( 23            ),
        // Slot 0: Obj
        .SLOT0_AW    ( 23            ),
        .SLOT0_DW    ( 32            ),
        .LATCH0      ( 1             )
        //.SLOT0_REPACK( 1             ),
    ) u_bank2 (
        .rst         ( rst           ),
        .clk         ( clk_gfx       ), // do not use clk

        .slot0_cs    ( objgfx_cs[0]  ),
        .slot0_ok    ( objgfx_ok[0]  ),
        .slot0_addr  ( cps2_gfx0     ),
        .slot0_dout  ( objgfx_dout0  ),

        .sdram_addr  ( ba2_addr      ),
        .sdram_req   ( ba2_rd        ),
        .sdram_ack   ( ba2_ack       ),
        .data_rdy    ( ba2_rdy       ),
        .data_read   ( data_read     )
    );
`else
    assign objgfx_cs = 2'b10;
    assign rom0_ok   = objgfx_ok[1];
    assign rom0_data = objgfx_dout1;
    assign cps2_gfx0 = { 1'b0, gfx0_addr };
`endif

jtframe_rom_2slots #(
    .SDRAMW      ( 23            ),
    // Slot 0: Obj
    .SLOT0_AW    ( 23            ),
    .SLOT0_DW    ( 32            ),
    .SLOT0_OFFSET( ZERO_OFFSET   ),
    .LATCH0      ( 1             ),
    //.SLOT0_REPACK( 1             ),

    // Slot 1: Scroll
    .SLOT1_AW    ( 22            ),
    .SLOT1_DW    ( 32            ),
    .SLOT1_OFFSET( SCR_OFFSET    )
    //.SLOT1_REPACK( 1             )
) u_bank3 (
    .rst         ( rst           ),
    .clk         ( clk_gfx       ), // do not use clk

    .slot0_cs    ( objgfx_cs[1]  ),
    .slot1_cs    ( rom1_cs       ),

    .slot0_ok    ( objgfx_ok[1]  ),
    .slot1_ok    ( rom1_ok       ),

    .slot0_addr  ( cps2_gfx0     ),
    .slot1_addr  ( gfx1_addr     ),

    .slot0_dout  ( objgfx_dout1  ),
    .slot1_dout  ( rom1_data     ),

    .sdram_addr  ( ba3_addr      ),
    .sdram_req   ( ba3_rd        ),
    .sdram_ack   ( ba3_ack       ),
    .data_rdy    ( ba3_rdy       ),
    .data_read   ( data_read     )
);

// EEPROM used by Pang 3 and by CPS1.5/2
jt9346 #(.DW(16),.AW(EEPROM_AW)) u_eeprom(
    .rst        ( rst       ),  // system reset
    .clk        ( clk       ),  // system clock
    // chip interface
    .sclk       ( sclk      ),  // serial clock
    .sdi        ( sdi       ),  // serial data in
    .sdo        ( sdo       ),  // serial data out and ready/not busy signal
    .scs        ( scs       ),  // chip select, active high. Goes low in between instructions
    // Dump access
    .dump_clk   ( clk       ),  // same as prom_we module
    .dump_addr  ( dump_addr ),
    .dump_we    ( dump_we   ),
    .dump_din   ( dump_din  ),
    .dump_dout  ( dump_dout )
);

endmodule