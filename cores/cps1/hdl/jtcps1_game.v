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

module jtcps1_game(
    input           rst,
    input           clk,      // SDRAM
    input           clk48,    // 48   MHz
    `ifdef JTFRAME_CLK96
    input           clk96,    // 96   MHz
    `endif
    output          pxl2_cen,   // 12   MHz
    output          pxl_cen,    //  6   MHz
    output   [7:0]  red,
    output   [7:0]  green,
    output   [7:0]  blue,
    output          LHBL_dly,
    output          LVBL_dly,
    output          HS,
    output          VS,
    // cabinet I/O
    input   [ 3:0]  start_button,
    input   [ 3:0]  coin_input,
    input   [ 9:0]  joystick1,
    input   [ 9:0]  joystick2,
    input   [ 9:0]  joystick3,
    input   [ 9:0]  joystick4,
    // SDRAM interface
    input           downloading,
    output          dwnld_busy,

    // Bank 0: allows R/W
    output   [21:0] ba0_addr,
    output          ba0_rd,
    output          ba0_wr,
    output   [15:0] ba0_din,
    output   [ 1:0] ba0_din_m,  // write mask
    input           ba0_rdy,
    input           ba0_ack,

    // Bank 1: Read only
    output   [21:0] ba1_addr,
    output          ba1_rd,
    input           ba1_rdy,
    input           ba1_ack,

    // Bank 2: Read only
    output   [21:0] ba2_addr,
    output          ba2_rd,
    input           ba2_rdy,
    input           ba2_ack,

    // Bank 3: Read only
    output   [21:0] ba3_addr,
    output          ba3_rd,
    input           ba3_rdy,
    input           ba3_ack,

    input   [31:0]  data_read,
    output          refresh_en,

    // ROM LOAD
    input   [24:0]  ioctl_addr,
    input   [ 7:0]  ioctl_data,
    input           ioctl_wr,
    output  [ 7:0]  ioctl_data2sd,
    input           ioctl_ram, // 0 - ROM, 1 - RAM(EEPROM)
    output  [21:0]  prog_addr,
    output  [15:0]  prog_data,
    output  [ 1:0]  prog_mask,
    output  [ 1:0]  prog_ba,
    output          prog_we,
    output          prog_rd,
    input           prog_ack,
    input           prog_rdy,
    // DIP switches
    input   [31:0]  status,     // only bits 31:16 are looked at
    input           service,
    input           dip_pause,
    inout           dip_flip,
    input           dip_test,
    input   [ 1:0]  dip_fxlevel, // Not a DIP on the original PCB
    input   [31:0]  dipsw,
    // Sound output
    output  signed [15:0] snd_left,
    output  signed [15:0] snd_right,
    output          sample,
    input           enable_psg,
    input           enable_fm,
    output          game_led,
    // Debug
    input   [3:0]   gfx_en
);

wire        clk_gfx;
wire        LHBL, LVBL; // internal blanking signals
wire        snd_cs, adpcm_cs, main_ram_cs, main_vram_cs, main_rom_cs,
            rom0_cs, rom1_cs,
            vram_dma_cs;
wire        HB, VB;
wire [15:0] snd_addr;
wire [17:0] adpcm_addr;
wire [ 7:0] snd_data, adpcm_data;
wire [17:1] ram_addr;
wire [21:1] main_rom_addr;
wire [15:0] main_ram_data, main_rom_data, main_dout, mmr_dout;
wire        main_rom_ok, main_ram_ok;
wire        ppu1_cs, ppu2_cs, ppu_rstn;
wire [19:0] rom1_addr, rom0_addr;
wire [31:0] rom0_data, rom1_data;
// Video RAM interface
wire [17:1] vram_dma_addr;
wire [15:0] vram_dma_data;
wire        vram_dma_ok, rom0_ok, rom1_ok, snd_ok, adpcm_ok;
wire [15:0] cpu_dout;
wire        cpu_speed;

wire        main_rnw, busreq, busack;
wire [ 7:0] snd_latch0, snd_latch1;
wire [ 7:0] dipsw_a, dipsw_b, dipsw_c;

wire        vram_clr, vram_rfsh_en;
wire [ 8:0] hdump;
wire [ 8:0] vdump, vrender;

wire        rom0_half, rom1_half;
wire        cfg_we;

// EEPROM
wire        sclk, sdi, sdo, scs;

`ifndef SIMULATION
    assign { dipsw_c, dipsw_b, dipsw_a } = dipsw[23:0];
`else
assign { dipsw_c, dipsw_b, dipsw_a } = ~24'd0;
`endif
assign dip_flip = dipsw_c[4];  // this is correct for all games except Mega Man
    // but it does not matter for horizontal games

assign LVBL         = ~VB;
assign LHBL         = ~HB;

wire [ 1:0] dsn;
wire        cen16, cen12, cen8, cen10b;
wire        cpu_cen, cpu_cenb;
wire        charger;
wire        turbo, pcmfilter_en;

`ifdef JTCPS_TURBO
assign turbo = 1;
`else
    `ifdef MISTER
        assign turbo = status[13];
    `else
        assign turbo = status[5];
    `endif
`endif

assign pcmfilter_en = status[1];

// CPU clock enable signals come from 48MHz domain
jtframe_cen48 u_cen48(
    .clk        ( clk48         ),
    .cen16      ( cen16         ),
    .cen12      ( cen12         ),
    .cen8       ( cen8          ),
    .cen6       (               ),
    .cen4       (               ),
    .cen4_12    (               ),
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

`ifdef JTFRAME_CLK96
    jtframe_cen96 u_pxl_cen(
        .clk    ( clk96     ),    // 96 MHz
        .cen16  ( pxl2_cen  ),
        .cen12  (           ),
        .cen8   ( pxl_cen   ),
        // Unused:
        .cen6   (           ),
        .cen6b  (           )
    );
    assign clk_gfx = clk96;
`else
    assign pxl2_cen = cen16;
    assign pxl_cen  = cen8;
    assign clk_gfx = clk;
`endif

jtcps1_cpucen u_cpucen(
    .clk        ( clk48              ),
    .cen12      ( cen12              ),
    .cpu_speed  ( cpu_speed /*| turbo*/  ),
    .cpu_cen    ( cpu_cen            ),
    .cpu_cenb   ( cpu_cenb           )
);

localparam REGSIZE=24;

// Turbo speed disables DMA
wire busreq_cpu = busreq & ~turbo;
wire busack_cpu;
assign busack = busack_cpu | turbo;

`ifndef NOMAIN
jtcps1_main u_main(
    .rst        ( rst               ),
    .clk        ( clk48             ),
    .cen10      ( cpu_cen           ),
    .cen10b     ( cpu_cenb          ),
    .cpu_cen    (                   ),
    // Timing
    .V          ( vdump             ),
    .LVBL       ( LVBL              ),
    .LHBL       ( LHBL              ),
    // PPU
    .ppu1_cs    ( ppu1_cs           ),
    .ppu2_cs    ( ppu2_cs           ),
    .ppu_rstn   ( ppu_rstn          ),
    .mmr_dout   ( mmr_dout          ),
    // Sound
    .snd_latch0 ( snd_latch0        ),
    .snd_latch1 ( snd_latch1        ),
    .UDSWn      ( dsn[1]            ),
    .LDSWn      ( dsn[0]            ),
    // cabinet I/O
    // Cabinet input
    .charger     ( charger          ),
    .start_button( start_button[1:0]),
    .coin_input  ( coin_input[1:0]  ),
    .joystick1   ( joystick1        ),
    .joystick2   ( joystick2        ),
    .service     ( service          ),
    .tilt        ( 1'b1             ),
    // BUS sharing
    .busreq      ( busreq_cpu       ),
    .busack      ( busack_cpu       ),
    .RnW         ( main_rnw         ),
    // RAM/VRAM access
    .addr        ( ram_addr         ),
    .cpu_dout    ( main_dout        ),
    .ram_cs      ( main_ram_cs      ),
    .vram_cs     ( main_vram_cs     ),
    .ram_data    ( main_ram_data    ),
    .ram_ok      ( main_ram_ok      ),
    // ROM access
    .rom_cs      ( main_rom_cs      ),
    .rom_addr    ( main_rom_addr    ),
    .rom_data    ( main_rom_data    ),
    .rom_ok      ( main_rom_ok      ),
    // DIP switches
    .dip_pause   ( dip_pause        ),
    .dip_test    ( dip_test         ),
    .dipsw_a     ( dipsw_a          ),
    .dipsw_b     ( dipsw_b          ),
    .dipsw_c     ( dipsw_c          )
);
`else
assign ram_addr = 17'd0;
assign main_ram_cs = 1'b0;
assign main_vram_cs = 1'b0;
assign main_rom_cs = 1'b0;
assign dsn = 2'b11;
assign main_rnw = 1'b1;
assign busack_cpu = 1;
`endif

reg rst_video;

always @(negedge clk_gfx) begin
    rst_video <= rst;
end

jtcps1_video #(REGSIZE) u_video(
    .rst            ( rst_video     ),
    .clk            ( clk_gfx       ),
    .clk_cpu        ( clk48         ),
    .pxl2_cen       ( pxl2_cen      ),
    .pxl_cen        ( pxl_cen       ),

    .hdump          ( hdump         ),
    .vdump          ( vdump         ),
    .vrender        ( vrender       ),
    .gfx_en         ( gfx_en        ),
    .cpu_speed      ( cpu_speed     ),
    .charger        ( charger       ),
    .kabuki_en      (               ),
    .raster         (               ),

    // CPU interface
    .ppu_rstn       ( ppu_rstn      ),
    .ppu1_cs        ( ppu1_cs       ),
    .ppu2_cs        ( ppu2_cs       ),
    .addr           ( ram_addr[12:1]),
    .dsn            ( dsn           ),      // data select, active low
    .cpu_dout       ( main_dout     ),
    .mmr_dout       ( mmr_dout      ),
    // BUS sharing
    .busreq         ( busreq        ),
    .busack         ( busack        ),

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

    // CPS-B Registers
    .cfg_we         ( cfg_we        ),
    .cfg_data       ( prog_data[7:0]),

    // EEPROM
    .sclk           ( sclk          ),
    .sdi            ( sdi           ),
    .sdo            ( sdo           ),
    .scs            ( scs           ),

    // Extra inputs read through the C-Board
    .start_button   ( start_button  ),
    .coin_input     ( coin_input    ),
    .joystick1      ( joystick1     ),
    .joystick2      ( joystick2     ),
    .joystick3      ( joystick3     ),
    .joystick4      ( joystick4     ),

    // Video RAM interface
    .vram_dma_addr  ( vram_dma_addr ),
    .vram_dma_data  ( vram_dma_data ),
    .vram_dma_ok    ( vram_dma_ok   ),
    .vram_dma_cs    ( vram_dma_cs   ),
    .vram_dma_clr   ( vram_clr      ),
    .vram_rfsh_en   ( vram_rfsh_en  ),

    // GFX ROM interface
    .rom1_addr      ( rom1_addr     ),
    .rom1_half      ( rom1_half     ),
    .rom1_data      ( rom1_data     ),
    .rom1_cs        ( rom1_cs       ),
    .rom1_ok        ( rom1_ok       ),
    .rom0_addr      ( rom0_addr     ),
    .rom0_bank      (               ),
    .rom0_half      ( rom0_half     ),
    .rom0_data      ( rom0_data     ),
    .rom0_cs        ( rom0_cs       ),
    .rom0_ok        ( rom0_ok       )
);

`ifndef NOSOUND
`ifdef FAKE_LATCH
integer snd_frame_cnt=0;
reg [7:0] fake_latch0 = 8'h0, fake_latch1 = 8'h0;
assign snd_latch1 = fake_latch1;
assign snd_latch0 = fake_latch0;
localparam FAKE0=20;
localparam FAKE1=1000;
always @(posedge VB) begin
    snd_frame_cnt <= snd_frame_cnt+1;
    case( snd_frame_cnt )
        /* ffight
        FAKE0: fake_latch <= 8'hf0;
        FAKE0+5+2: fake_latch <= 8'hf7;
        FAKE0+5+4: fake_latch <= 8'hf2;
        FAKE0+5+6: fake_latch <= 8'h55;
        default: fake_latch <= 8'hff;
        */
        // Nemo
        //FAKE0: fake_latch <= 8'h2;
        //FAKE0+1: fake_latch <= 8'h2;
        //FAKE0+2: fake_latch <= 8'h0;
        // KOD
        //FAKE0: fake_latch <= 8'h6;
        // Magic Sword
        //FAKE0: fake_latch <= 8'h1e;
        //FAKE1: fake_latch <= 8'h0;
        //FAKE1+1: fake_latch <= 8'h4;
        //FAKE1+2: fake_latch <= 8'h0;
        // SF2, Chun Li
        FAKE0: begin
            fake_latch1 <= 8'h00;
            fake_latch0 <= 8'hf0;
        end

        FAKE0+10: begin
            fake_latch1 <= 8'h00;
            fake_latch0 <= 8'hff;
        end
        FAKE0+11: begin
            fake_latch1 <= 8'h00;
            fake_latch0 <= 8'hf7;
        end
        FAKE0+12: begin
            fake_latch1 <= 8'h00;
            fake_latch0 <= 8'hff;
        end
        FAKE0+13: begin
            fake_latch1 <= 8'h00;
            fake_latch0 <= 8'h06;
        end
        FAKE0+14: begin
            fake_latch1 <= 8'h00;
            fake_latch0 <= 8'hff;
        end

        //default: fake_latch <= 8'hff;
    endcase
end
`endif

(*keep*) reg [3:0] rst_snd;
always @(negedge clk) begin
    rst_snd <= { rst_snd[2:0], rst };
end

jtcps1_sound u_sound(
    .rst            ( rst_snd[3]    ),
    .clk            ( clk48         ),

    .enable_adpcm   ( enable_psg    ),
    .enable_fm      ( enable_fm     ),
    `ifdef MISTER
        .fxlevel    ( dip_fxlevel   ),
    `else
        .fxlevel    ( 2'd2          ), // not enough bits in MiST's OSD
    `endif
    .pcmfilter_en   ( pcmfilter_en  ),

    // Interface with main CPU
    .snd_latch0     ( snd_latch0    ),
    .snd_latch1     ( snd_latch1    ),

    // ROM
    .rom_addr       ( snd_addr      ),
    .rom_cs         ( snd_cs        ),
    .rom_data       ( snd_data      ),
    .rom_ok         ( snd_ok        ),

    // ADPCM ROM
    .adpcm_addr     ( adpcm_addr    ),
    .adpcm_cs       ( adpcm_cs      ),
    .adpcm_data     ( adpcm_data    ),
    .adpcm_ok       ( adpcm_ok      ),

    // Sound output
    .left           ( snd_left      ),
    .right          ( snd_right     ),
    .sample         ( sample        ),
    .peak           ( game_led      )
);
`else
assign snd_addr   = 16'd0;
assign snd_cs     = 1'b0;
assign snd_left   = 16'd0;
assign snd_right  = 16'd0;
assign adpcm_addr = 18'd0;
assign adpcm_cs   = 1'b0;
assign sample   = 1'b0;
`endif

jtcps1_sdram #(.REGSIZE(REGSIZE)) u_sdram (
    .rst         ( rst           ),
    .clk         ( clk           ),
    .clk_gfx     ( clk_gfx       ),
    .clk_cpu     ( clk48         ),
    .LVBL        ( LVBL          ),

    .downloading ( downloading   ),
    .dwnld_busy  ( dwnld_busy    ),
    .cfg_we      ( cfg_we        ),

    // ROM LOAD
    .ioctl_addr  ( ioctl_addr    ),
    .ioctl_data  ( ioctl_data    ),
    .ioctl_data2sd(ioctl_data2sd ),
    .ioctl_wr    ( ioctl_wr      ),
    .ioctl_ram   ( ioctl_ram     ),
    .prog_addr   ( prog_addr     ),
    .prog_data   ( prog_data     ),
    .prog_mask   ( prog_mask     ),
    .prog_ba     ( prog_ba       ),
    .prog_we     ( prog_we       ),
    .prog_rd     ( prog_rd       ),
    .prog_rdy    ( prog_rdy      ),
    // Unused QSound ports
    .prog_qsnd   (               ),
    .kabuki_we   (               ),

    // EEPROM
    .sclk           ( sclk          ),
    .sdi            ( sdi           ),
    .sdo            ( sdo           ),
    .scs            ( scs           ),

    // Main CPU
    .main_rom_cs    ( main_rom_cs   ),
    .main_rom_ok    ( main_rom_ok   ),
    .main_rom_addr  ( main_rom_addr ),
    .main_rom_data  ( main_rom_data ),

    // VRAM
    .vram_clr       ( vram_clr      ),
    .vram_dma_cs    ( vram_dma_cs   ),
    .main_ram_cs    ( main_ram_cs   ),
    .main_vram_cs   ( main_vram_cs  ),
    .vram_rfsh_en   ( vram_rfsh_en  ),

    // Object RAM (CPS2)
    .main_oram_cs   ( 1'b0          ),

    .dsn            ( dsn           ),
    .main_dout      ( main_dout     ),
    .main_rnw       ( main_rnw      ),

    .main_ram_ok    ( main_ram_ok   ),
    .vram_dma_ok    ( vram_dma_ok   ),

    .main_ram_addr  ( ram_addr      ),
    .vram_dma_addr  ( vram_dma_addr ),

    .main_ram_data  ( main_ram_data ),
    .vram_dma_data  ( vram_dma_data ),

    // Sound CPU and PCM
    .snd_cs      ( snd_cs        ),
    .pcm_cs      ( adpcm_cs      ),

    .snd_ok      ( snd_ok        ),
    .pcm_ok      ( adpcm_ok      ),

    .snd_addr    ( snd_addr      ),
    .pcm_addr    ( adpcm_addr    ),

    .snd_data    ( snd_data      ),
    .pcm_data    ( adpcm_data    ),

    // Graphics
    .rom0_cs     ( rom0_cs       ),
    .rom1_cs     ( rom1_cs       ),

    .rom0_ok     ( rom0_ok       ),
    .rom1_ok     ( rom1_ok       ),

    .rom0_addr   ( rom0_addr     ),
    .rom1_addr   ( rom1_addr     ),

    .rom0_half   ( rom0_half     ),
    .rom1_half   ( rom1_half     ),

    .rom0_data   ( rom0_data     ),
    .rom1_data   ( rom1_data     ),

    // Bank 0: allows R/W
    .ba0_addr    ( ba0_addr      ),
    .ba0_rd      ( ba0_rd        ),
    .ba0_wr      ( ba0_wr        ),
    .ba0_ack     ( ba0_ack       ),
    .ba0_rdy     ( ba0_rdy       ),
    .ba0_din     ( ba0_din       ),
    .ba0_din_m   ( ba0_din_m     ),

    // Bank 1: Read only
    .ba1_addr    ( ba1_addr      ),
    .ba1_rd      ( ba1_rd        ),
    .ba1_ack     ( ba1_ack       ),
    .ba1_rdy     ( ba1_rdy       ),

    // Bank 2: Read only
    .ba2_addr    ( ba2_addr      ),
    .ba2_rd      ( ba2_rd        ),
    .ba2_ack     ( ba2_ack       ),
    .ba2_rdy     ( ba2_rdy       ),

    // Bank 3: Read only
    .ba3_addr    ( ba3_addr      ),
    .ba3_rd      ( ba3_rd        ),
    .ba3_ack     ( ba3_ack       ),
    .ba3_rdy     ( ba3_rdy       ),

    .data_read   ( data_read     ),
    .refresh_en  ( refresh_en    )
);

endmodule
