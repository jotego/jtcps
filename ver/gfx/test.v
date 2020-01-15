`timescale 1ns/1ps

module test;

reg         rst, clk, start, vram_ok, rom_ok;
reg  [ 8:0] v;

reg  [15:0] vram_base, hpos, vpos, vram_data, rom_data;
wire        done, vram_cs, rom_cs, buf_wr;
wire [21:0] rom_addr;
wire [23:0] vram_addr;
wire [ 8:0] buf_addr;
wire [ 7:0] buf_data;

jtcps1_tilemap UUT(
    .rst        ( rst           ),
    .clk        ( clk           ),
    .v          ( v             ),
    .vram_base  ( vram_base     ),
    .hpos       ( hpos          ),
    .vpos       ( vpos          ),
    .start      ( start         ),
    .done       ( done          ),
    .vram_addr  ( vram_addr     ),
    .vram_data  ( vram_data     ),
    .vram_ok    ( vram_ok       ),
    .vram_cs    ( vram_cs       ),
    .rom_addr   ( rom_addr      ),
    .rom_data   ( rom_data      ),
    .rom_cs     ( rom_cs        ),
    .rom_ok     ( rom_ok        ),
    .buf_addr   ( buf_addr      ),
    .buf_data   ( buf_data      ),
    .buf_wr     ( buf_wr        )
);

endmodule
