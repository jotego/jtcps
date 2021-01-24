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


// Scroll 1 is 512x512, 8x8 tiles
// Scroll 2 is 1024x1024 16x16 tiles
// Scroll 3 is 2048x2048 32x32 tiles

module jtcps1_video(
    input              rst,
    input              clk,
    input              clk_cpu,
    input              pxl2_cen,        // pixel clock enable
    input              pxl_cen,        // pixel clock enable

    output     [ 8:0]  vdump,
    output     [ 8:0]  vrender,
    output     [ 8:0]  hdump,
    input      [ 3:0]  gfx_en,

    `ifdef CPS2
    input              obank,
    input              objram_cs,
    `endif

    // CPU interface
    input              ppu_rstn,
    input              ppu1_cs,
    input              ppu2_cs,
    input   [13:1]     addr,
    input   [ 1:0]     dsn,      // data select, active low
    input   [15:0]     cpu_dout,
    output  [15:0]     mmr_dout,
    output             cpu_speed,
    output             charger,
    output             kabuki_en,
    // BUS sharing
    output             busreq,
    input              busack,

    // CPS-B Registers
    input              cfg_we,
    input      [ 7:0]  cfg_data,

    // Extra inputs read through the C-Board
    input   [ 3:0]  start_button,
    input   [ 3:0]  coin_input,
    input   [ 9:0]  joystick1,
    input   [ 9:0]  joystick2,
    input   [ 9:0]  joystick3,
    input   [ 9:0]  joystick4,

    // Video RAM interface
    output     [17:1]  vram_dma_addr,
    input      [15:0]  vram_dma_data,
    input              vram_dma_ok,
    output             vram_dma_cs,
    output             vram_dma_clr,
    output             vram_rfsh_en,

    // Video signal
    output             HS,
    output             VS,
    output             HB,
    output             VB,
    output             LHBL_dly,
    output             LVBL_dly,
    output     [ 7:0]  red,
    output     [ 7:0]  green,
    output     [ 7:0]  blue,

    // GFX ROM interface
    output     [19:0]  rom1_addr,
    output             rom1_half,    // selects which half to read
    input      [31:0]  rom1_data,
    output             rom1_cs,
    input              rom1_ok,

    output     [19:0]  rom0_addr,
    output             rom0_half,    // selects which half to read
    input      [31:0]  rom0_data,
    output             rom0_cs,
    input              rom0_ok
    // To frame buffer
    // output     [11:0]  line_data,
    // output     [ 8:0]  line_addr,
    // output             line_wr,
    // input              line_wr_ok

    `ifdef CPS1
    // EEPROM
    ,output            sclk,
    output             sdi,
    output             scs,
    input              sdo
    `endif
);

parameter REGSIZE=24;

// use for CPU only simulations:
`ifdef NOVIDEO
`define NOSCROLL
`define NOOBJ
`define NOCOLMIX
`endif

wire [11:0]     pal_addr;
wire [10:0]     scr1_pxl, scr2_pxl, scr3_pxl;
wire [ 8:0]     star1_pxl, star0_pxl;
wire [ 8:0]     obj_pxl;
wire [ 8:0]     vrender1;
wire [15:0]     ppu_ctrl, pal_raw;
wire [17:1]     vram_pal_addr;
wire            line_start, preVB;
wire            flip = ppu_ctrl[15];
wire            busack_obj, busack_pal;

// Register configuration
// Scroll
wire       [15:0]  hpos1, hpos2, hpos3, vpos1, vpos2, vpos3, hstar1, hstar0, vstar1, vstar0;
// VRAM position
wire       [15:0]  vram1_base, vram2_base, vram3_base, vram_obj_base, vram_row_base, row_offset;
// Layer priority
wire       [15:0]  layer_ctrl, prio0, prio1, prio2, prio3;
wire       [ 7:0]  layer_mask0, layer_mask1, layer_mask2, layer_mask3, layer_mask4;
// palette control
wire       [15:0]  pal_base;
wire               pal_dma_ok;
wire       [ 5:0]  pal_page_en; // which palette pages to copy
// ROM banks
wire       [ 5:0]  game;
wire       [15:0]  bank_offset;
wire       [15:0]  bank_mask;

wire       [ 7:0]  tile_addr;
wire       [15:0]  tile_data, row_scr;
wire       [ 9:0]  obj_cache_addr;
wire               obj_dma_ok;
wire       [15:0]  objtable_data;

`ifdef CPS2
assign obj_dma_ok = 0;
`endif

jtcps1_dma u_dma(
    .rst            ( rst               ),
    .clk            ( clk               ),
    .pxl2_cen       ( pxl2_cen          ),
    .pxl_cen        ( pxl_cen           ),
    .HB             ( HB                ),
    .vrender1       ( vrender1          ),
    .flip           ( flip              ),

    .tile_addr      ( tile_addr         ),
    .tile_data      ( tile_data         ),

    .vram1_base     ( vram1_base        ),
    .hpos1          ( hpos1             ),
    .vpos1          ( vpos1             ),

    .vram2_base     ( vram2_base        ),
    .hpos2          ( hpos2             ),
    .vpos2          ( vpos2             ),

    .vram3_base     ( vram3_base        ),
    .hpos3          ( hpos3             ),
    .vpos3          ( vpos3             ),

    // Row Scroll
    .vram_row_base  ( vram_row_base     ),
    .row_offset     ( row_offset        ),
    .row_en         ( ppu_ctrl[0]       ),
    .row_scr        ( row_scr           ),

    // Palette
    .vram_pal_base  ( pal_base          ),
    .pal_dma_ok     ( pal_dma_ok        ),
    .pal_page_en    ( pal_page_en       ),
    .pal_data       ( pal_raw           ),
    .colmix_addr    ( pal_addr          ),

    // Objects
    .vram_obj_base  ( vram_obj_base     ),
    `ifdef CPS2
        .obj_table_addr ( 10'd0         ),
    `else
        .obj_table_addr (obj_cache_addr ),
    `endif
    .obj_table_data ( objtable_data     ),
    .obj_dma_ok     ( obj_dma_ok        ),

    .br             ( busreq            ),
    .bg             ( busack            ),
    .vram_addr      ( vram_dma_addr     ),
    .vram_data      ( vram_dma_data     ),
    .vram_ok        ( vram_dma_ok       ),
    .vram_clr       ( vram_dma_clr      ),
    .vram_cs        ( vram_dma_cs       ),
    .rfsh_en        ( vram_rfsh_en      )
);

jtcps1_timing u_timing(
    .clk            ( clk               ),
    .cen8           ( pxl_cen           ),

    .vdump          ( vdump             ),
    .hdump          ( hdump             ),
    .vrender1       ( vrender1          ),
    .vrender        ( vrender           ),
    .start          ( line_start        ),
    // to video output
    .HS             ( HS                ),
    .VS             ( VS                ),
    .VB             ( VB                ),
    .preVB          ( preVB             ),
    .HB             ( HB                )
);

// initial begin
//     $display("OFFSET=%X",`OFFSET);
// end

jtcps1_mmr #(REGSIZE) u_mmr(
    .rst            ( rst               ),
    .clk            ( clk               ),
    .pxl_cen        ( pxl_cen           ),
    .ppu_rstn       ( ppu_rstn          ),  // controlled by CPU

    .ppu1_cs        ( ppu1_cs           ),
    .ppu2_cs        ( ppu2_cs           ),
    .addr           ( addr[5:1]         ),
    .dsn            ( dsn               ),      // data select, active low
    .cpu_dout       ( cpu_dout          ),
    .mmr_dout       ( mmr_dout          ),
    // registers
    .ppu_ctrl       ( ppu_ctrl          ),
    // Scroll
    .hpos1          ( hpos1             ),
    .hpos2          ( hpos2             ),
    .hpos3          ( hpos3             ),
    .vpos1          ( vpos1             ),
    .vpos2          ( vpos2             ),
    .vpos3          ( vpos3             ),
    .hstar1         ( hstar0            ),
    .hstar2         ( hstar1            ),
    .vstar1         ( vstar0            ),
    .vstar2         ( vstar1            ),

    .cpu_speed      ( cpu_speed         ),
    .charger        ( charger           ),
    .kabuki_en      ( kabuki_en         ),

    // OBJ DMA
    `ifndef CPS2
        `ifndef NOMAIN
            .obj_dma_ok ( obj_dma_ok    ),
        `else
            .obj_dma_ok (               ),
        `endif
    `else
        .obj_dma_ok (                   ),
    `endif

    .start_button   ( start_button      ),
    .coin_input     ( coin_input        ),
    .joystick1      ( joystick1         ),
    .joystick2      ( joystick2         ),
    .joystick3      ( joystick3         ),
    .joystick4      ( joystick4         ),

    // ROM banks
    .game           ( game              ),
    .bank_offset    ( bank_offset       ),
    .bank_mask      ( bank_mask         ),

    // VRAM position
    .vram1_base     ( vram1_base        ),
    .vram2_base     ( vram2_base        ),
    .vram3_base     ( vram3_base        ),
    .vram_obj_base  ( vram_obj_base     ),
    .vram_row_base  ( vram_row_base     ),
    .row_offset     ( row_offset        ),
    .pal_base       ( pal_base          ),
`ifndef NOMAIN
    .pal_copy       ( pal_dma_ok        ),
`else
    .pal_copy       (                   ),
`endif

    // CPS-B Registers
    .cfg_we         ( cfg_we            ),
    .cfg_data       ( cfg_data          ),

    .layer_ctrl     ( layer_ctrl        ),
    .layer_mask0    ( layer_mask0       ),
    .layer_mask1    ( layer_mask1       ),
    .layer_mask2    ( layer_mask2       ),
    .layer_mask3    ( layer_mask3       ),
    .layer_mask4    ( layer_mask4       ),
    .prio0          ( prio0             ),
    .prio1          ( prio1             ),
    .prio2          ( prio2             ),
    .prio3          ( prio3             ),
    .pal_page_en    ( pal_page_en       )
    `ifdef CPS1
    ,.sclk          ( sclk              ),
    .sdi            ( sdi               ),
    .sdo            ( sdo               ),
    .scs            ( scs               )
    `endif
);

//`define NOSCROLL1
`ifndef NOSCROLL
jtcps1_scroll u_scroll(
    .rst        ( rst           ),
    .clk        ( clk           ),
    .pxl_cen    ( pxl_cen       ),
    .gfx_en     ( gfx_en        ),
    .flip       ( flip          ),

    .vrender    ( vrender       ),
    .vdump      ( vdump         ),
    .hdump      ( hdump         ),
    .preVB      ( preVB         ),
    .VB         ( VB            ),
    .HB         ( HB            ),

    .hpos1      ( hpos1         ),
    .vpos1      ( vpos1         ),

    .hpos2      ( row_scr       ),
    .vpos2      ( vpos2         ),

    .hpos3      ( hpos3         ),
    .vpos3      ( vpos3         ),

    .hstar0     ( hstar0        ),
    .vstar0     ( vstar0        ),
    .hstar1     ( hstar1        ),
    .vstar1     ( vstar1        ),

    // ROM banks
    .game       ( game          ),
    .bank_offset( bank_offset   ),
    .bank_mask  ( bank_mask     ),

    .start      ( line_start    ),

    .tile_addr  ( tile_addr     ),
    .tile_data  ( tile_data     ),

    .rom_addr   ( rom1_addr     ),
    .rom_data   ( rom1_data     ),
    .rom_cs     ( rom1_cs       ),
    .rom_ok     ( rom1_ok       ),
    .rom_half   ( rom1_half     ),

    .scr1_pxl   ( scr1_pxl      ),
    .scr2_pxl   ( scr2_pxl      ),
    .scr3_pxl   ( scr3_pxl      ),

    .star0_pxl  ( star0_pxl     ),
    .star1_pxl  ( star1_pxl     )
);
`else
assign rom1_cs    = 1'b0;
assign rom1_addr  = 20'd0;
assign scr1_pxl   = 11'h1ff;
assign scr2_pxl   = 11'h1ff;
assign scr3_pxl   = 11'h1ff;
`endif

// Objects
`ifndef CPS2
    jtcps1_obj u_obj(
        .rst        ( rst           ),
        .clk        ( clk           ),
        .pxl_cen    ( pxl_cen       ),
        .flip       ( flip          ),

        // Cache access
        .frame_addr ( obj_cache_addr),
        .frame_data ( objtable_data ),

        .start      ( line_start    ),
        .vrender    ( vrender       ),
        .vdump      ( vdump         ),
        .hdump      ( hdump         ),

        // ROM banks
        .game       ( game          ),
        .bank_offset( bank_offset   ),
        .bank_mask  ( bank_mask     ),

        // ROM data
        .rom_addr   ( rom0_addr     ),
        .rom_data   ( rom0_data     ),
        .rom_cs     ( rom0_cs       ),
        .rom_ok     ( rom0_ok       ),
        .rom_half   ( rom0_half     ),

        .pxl        ( obj_pxl       )
    );
`else
    jtcps2_obj u_obj(
        .rst        ( rst           ),
        .clk        ( clk           ),
        .clk_cpu    ( clk_cpu       ),
        .pxl_cen    ( pxl_cen       ),
        .flip       ( flip          ),

        .obank      ( obank         ),
        // Interface with CPU
        .objram_cs  ( objram_cs     ),
        .main_dsn   ( dsn           ),
        .main_dout  ( cpu_dout      ),
        .main_addr  ( addr          ),

        .start      ( line_start    ),
        .vrender    ( vrender       ),
        .vdump      ( vdump         ),
        .hdump      ( hdump         ),

        // ROM data
        .rom_addr   ( rom0_addr     ),
        .rom_data   ( rom0_data     ),
        .rom_cs     ( rom0_cs       ),
        .rom_ok     ( rom0_ok       ),
        .rom_half   ( rom0_half     ),

        .pxl        ( obj_pxl       )
    );
`endif

`ifndef NOCOLMIX
jtcps1_colmix u_colmix(
    .rst        ( rst           ),
    .clk        ( clk           ),
    .pxl_cen    ( pxl_cen       ),

    .HB         ( HB            ),
    .VB         ( VB            ),
    .LHBL_dly   ( LHBL_dly      ),
    .LVBL_dly   ( LVBL_dly      ),
    .gfx_en     ( gfx_en        ),

    // Palette RAM
    .pal_addr   ( pal_addr      ),
    .pal_raw    ( pal_raw       ),

    // Layer priority
    .layer_ctrl ( layer_ctrl    ),
    .layer_mask0( layer_mask0   ),
    .layer_mask1( layer_mask1   ),
    .layer_mask2( layer_mask2   ),
    .layer_mask3( layer_mask3   ),
    .layer_mask4( layer_mask4   ),
    .prio0      ( prio0         ),
    .prio1      ( prio1         ),
    .prio2      ( prio2         ),
    .prio3      ( prio3         ),



    // Pixel layers data
    .scr1_pxl   ( scr1_pxl      ),
    .scr2_pxl   ( scr2_pxl      ),
    .scr3_pxl   ( scr3_pxl      ),
    .star0_pxl  ( star0_pxl     ),
    .star1_pxl  ( star1_pxl     ),
    .obj_pxl    ( obj_pxl       ),
    // Video
    .red        ( red           ),
    .green      ( green         ),
    .blue       ( blue          )
);
`else
assign red_colmix  = 8'b0;
assign green_colmix= 8'b0;
assign blue_colmix = 8'b0;
assign LHBL_colmix = ~HB;
assign LVBL_colmix = ~VB;
assign vpal_cs   = 1'b0;
assign vpal_addr = 17'd0;
assign LVBL_dly  = ~VB;
assign LHBL_dly  = ~HB;
`endif

// Fake DMA signals to allow for video-only simulation
`ifdef  NOMAIN
reg fake_pal, last_VB;

assign pal_dma_ok = fake_pal;
assign obj_dma_ok = fake_pal;

always @(posedge clk or posedge rst) begin
    if( rst ) begin
        fake_pal <= 0;
        last_VB  <= 1;
    end else if(pxl_cen) begin
        last_VB  <= VB;
        fake_pal <= VB && !last_VB;
    end
end
`endif

endmodule