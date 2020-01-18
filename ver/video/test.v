`timescale 1ns/1ps

module test;

// Register configuration
reg        [15:0]  vram1_base, vram2_base, vram3_base;
// Video RAM interface
wire       [23:1]  vram1_addr, vram2_addr, vram3_addr;
reg        [15:0]  vram1_data, vram2_data, vram3_data;
reg                vram1_ok, vram2_ok, vram3_ok;
wire               vram1_cs, vram2_cs, vram3_cs;

// GFX ROM interface
wire       [22:0]  rom1_addr, rom2_addr, rom3_addr;
reg        [31:0]  rom1_data, rom2_data, rom3_data;
wire               rom1_half, rom2_half, rom3_half;
wire               rom1_cs, rom2_cs, rom3_cs;
reg                rom1_ok, rom2_ok, rom3_ok;
// To frame buffer
wire       [8:0]   line_data;
wire       [8:0]   line_addr;
wire               line_wr, line_wr_ok, line_done;

jtcps1_video UUT (
    .rst        ( rst           ),
    .clk        ( clk           ),
    .v          ( v             ),

    // Register configuration
    .vram1_base ( vram1_base    ),
    .vram2_base ( vram2_base    ),
    .vram3_base ( vram3_base    ),
    // Video RAM interface
    .vram1_addr ( vram1_addr    ),
    .vram1_data ( vram1_data    ),
    .vram1_ok   ( vram1_ok      ),
    .vram1_cs   ( vram1_cs      ),

    .vram2_addr ( vram2_addr    ),
    .vram2_data ( vram2_data    ),
    .vram2_ok   ( vram2_ok      ),
    .vram2_cs   ( vram2_cs      ),

    .vram3_addr ( vram3_addr    ),
    .vram3_data ( vram3_data    ),
    .vram3_ok   ( vram3_ok      ),
    .vram3_cs   ( vram3_cs      ),

    // GFX ROM interface
    .rom1_addr  ( rom1_addr     ),
    .rom1_half  ( rom1_half     ),
    .rom1_data  ( rom1_data     ),
    .rom1_cs    ( rom1_cs       ),
    .rom1_ok    ( rom1_ok       ),

    .rom2_addr  ( rom2_addr     ),
    .rom2_half  ( rom2_half     ),
    .rom2_data  ( rom2_data     ),
    .rom2_cs    ( rom2_cs       ),
    .rom2_ok    ( rom2_ok       ),

    .rom3_addr  ( rom3_addr     ),
    .rom3_half  ( rom3_half     ),
    .rom3_data  ( rom3_data     ),
    .rom3_cs    ( rom3_cs       ),
    .rom3_ok    ( rom3_ok       ),
    // To frame buffer
    .line_data  ( line_data     ),
    .line_addr  ( line_addr     ),
    .line_wr    ( line_wr       ),
    .line_wr_ok ( line_wr_ok    ),
    .line_done  ( line_done     )
);

// JTFRAME_ROM_RW slot types
// 0 = read only    ( default )
// 1 = write only
// 2 = R/W

localparam WO=1;

wire [9:0] slot_cs, slot_ok, slot_wr;
assign slot_cs[2] = fbrd_cs;
assign slot_cs[3] = vram1_cs;
assign slot_cs[4] = vram2_cs;
assign slot_cs[5] = vram3_cs;
assign slot_cs[6] = rom1_cs;
assign slot_cs[7] = rom2_cs;
assign slot_cs[8] = rom3_cs;
assign slot_cs[9] = fbwr_st;
assign slot_ok[2] = fbrd_ok;
assign slot_ok[3] = vram1_ok;
assign slot_ok[4] = vram2_ok;
assign slot_ok[5] = vram3_ok;
assign slot_ok[6] = rom1_ok;
assign slot_ok[7] = rom2_ok;
assign slot_ok[8] = rom3_ok;
assign slot_ok[9] = fbwr_ok;
assign slot_wr[9] = fbwr_st;

jtframe_sdram_mux #(
    // Frame buffer, read access
    .SLOT2_AW   ( 18    ),  //8
    .SLOT2_DW   ( 16    ),
    .SLOT2_CACHE( 0     ),
    // VRAM read access:
    .SLOT3_AW   ( 22    ),
    .SLOT3_DW   ( 16    ),
    .SLOT4_AW   ( 22    ),  //4
    .SLOT4_DW   ( 16    ),
    .SLOT5_AW   ( 22    ),  //5
    .SLOT5_DW   ( 16    ),
    // GFX ROM
    .SLOT6_AW   ( 20    ),  //6
    .SLOT6_DW   ( 32    ),
    .SLOT6_CACHE( 0     ),
    .SLOT7_AW   ( 20    ),  //7
    .SLOT7_DW   ( 32    ),
    .SLOT7_CACHE( 0     ),
    .SLOT8_AW   ( 20    ),  //8
    .SLOT8_DW   ( 32    ),
    .SLOT8_CACHE( 0     ),
    // Frame buffer, write access
    .SLOT9_AW   ( 18    ),  //8
    .SLOT9_DW   ( 16    ),
    .SLOT9_CACHE( 0     ),
    .SLOT9_TYPE ( WO    )
)
u_sdram_mux(
    // Frame buffer reads
    .slot2_offset   ( FB_OFFSET     ),
    .slot2_addr     ( fbrd_addr     ),
    .slot2_dout     ( fbrd_data     ),

    // VRAM read access only
    .slot3_offset   ( vram1_offset  ),
    .slot3_addr     ( vram1_addr    ),
    .slot3_dout     ( vram1_data    ),

    .slot4_offset   ( vram2_offset  ),
    .slot4_addr     ( vram2_addr    ),
    .slot4_dout     ( vram2_data    ),

    .slot5_offset   ( vram3_offset  ),
    .slot5_addr     ( vram3_addr    ),
    .slot5_dout     ( vram3_data    ),

    // GFX ROM
    .slot6_offset   ( rom1_offset   ),
    .slot6_addr     ( rom1_addr     ),
    .slot6_dout     ( rom1_data     ),

    .slot7_offset   ( rom2_offset   ),
    .slot7_addr     ( rom2_addr     ),
    .slot7_dout     ( rom2_data     ),

    .slot8_offset   ( rom3_offset   ),
    .slot8_addr     ( rom3_addr     ),
    .slot8_dout     ( rom3_data     ),

    // Frame buffer writes
    .slot9_offset   ( FB_OFFSET     ),
    .slot9_addr     ( fbwr_addr     ),
    .slot9_din      ( fbwr_data     ),

    // bus signals
    .slot_cs        ( slot_cs       ),
    .slot_ok        ( slot_ok       ),
    .slot_wr        ( slot_wr       )
);

initial begin
    rst = 1'b0;
    #20 rst = 1'b1;
    #400 rst = 1'b0;
end

initial begin
    clk = 1'b0;
    forever #10.417 clk = ~clk;
end

initial begin
    $readmemh("vram.hex",vram);
    $display("INFO: VRAM loaded");
end

endmodule