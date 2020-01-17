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