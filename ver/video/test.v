`timescale 1ns/1ps

module test;

reg                rst, clk, cen8;
wire       [ 7:0]  vdump, vrender;
wire       [ 8:0]  hdump;
// video signals
wire               HS, VS, HB, VB, frame;
wire       [ 7:0]  red, green, blue;

// Video RAM interface
wire       [23:1]  vram1_addr, vram2_addr, vram3_addr;
wire       [15:0]  vram1_data, vram2_data, vram3_data;
wire               vram1_ok, vram2_ok, vram3_ok;
wire               vram1_cs, vram2_cs, vram3_cs;

// GFX ROM interface
wire       [22:0]  rom1_addr, rom2_addr, rom3_addr;
wire       [31:0]  rom1_data, rom2_data, rom3_data;
wire       [ 3:0]  rom1_bank, rom2_bank, rom3_bank;
wire               rom1_half, rom2_half, rom3_half;
wire               rom1_cs, rom2_cs, rom3_cs;
wire               rom1_ok, rom2_ok, rom3_ok;

reg                downloading=1'b0, loop_rst=1'b0, sdram_ack;
reg        [31:0]  data_read;
wire               sdram_req, refresh_en;
wire       [21:0]  sdram_addr;
reg        [ 3:0]  sdram_ok4;
reg        [21:0]  last_sdram_addr;
reg                data_rdy;

reg        [15:0]  hpos1 = 16'hffc0;
reg        [15:0]  vpos1 = 16'h0000;
reg        [15:0]  hpos2 = 16'h03c0;
reg        [15:0]  vpos2 = 16'h0303;
reg        [15:0]  hpos3 = 16'h07c0;
reg        [15:0]  vpos3 = 16'h0700;

always @(negedge VB) begin
    // hpos2<=hpos2+1;
    //hpos3<=hpos3+1;
end

jtcps1_video UUT (
    .rst        ( rst           ),
    .clk        ( clk           ),
    .cen8       ( cen8          ),

    .hdump      ( hdump         ),
    .vdump      ( vdump         ),
    .vrender    ( vrender       ),
    .frame      ( frame         ),

    // Video signal
    .HS         ( HS            ),
    .VS         ( VS            ),
    .HB         ( HB            ),
    .VB         ( VB            ),
    .red        ( red           ),
    .green      ( green         ),
    .blue       ( blue          ),

    // Register configuration
    .hpos1      ( hpos1         ),
    .vpos1      ( vpos1         ),
    .hpos2      ( hpos2         ),
    .vpos2      ( vpos2         ),
    .hpos3      ( hpos3         ),
    .vpos3      ( vpos3         ),
    .vram1_base ( 16'h9000      ),
    .vram2_base ( 16'h9040      ),
    .vram3_base ( 16'h9080      ),
    .pal_base   ( 16'h9100      ),
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
    .rom3_ok    ( rom3_ok       )
);

//always @(posedge start) begin
//    if(!line_done) $display("WARNING: tilemap line did not complete at time %t", $time);
//end

// JTFRAME_ROM_RW slot types
// 0 = read only    ( default )
// 1 = write only
// 2 = R/W

localparam WO=1;

wire [9:0] slot_cs, slot_ok, slot_wr;
assign slot_cs[0] = 1'b0;
assign slot_cs[1] = 1'b0;
assign slot_cs[2] = 1'b1;
assign slot_cs[3] = vram1_cs;
assign slot_cs[4] = vram2_cs;
assign slot_cs[5] = vram3_cs;
assign slot_cs[6] = rom1_cs;
assign slot_cs[7] = rom2_cs;
assign slot_cs[8] = rom3_cs;
assign slot_cs[9] = 1'b0;

assign fbread_ok  = slot_ok[2];
assign vram1_ok   = slot_ok[3];
assign vram2_ok   = slot_ok[4];
assign vram3_ok   = slot_ok[5];
assign rom1_ok    = slot_ok[6];
assign rom2_ok    = slot_ok[7];
assign rom3_ok    = slot_ok[8];

assign slot_wr[9:0] = 9'd0;

wire [31:0] data_write;
wire        sdram_rnw;
wire [21:0] rom1_offset, rom2_offset, rom3_offset,
            frame0_offset, frame1_offset;

localparam [21:0] gfx_offset   = 22'h10_0000;
localparam [21:0] vram_offset  = 22'h32_0000;
localparam [21:0] frame_offset = 22'h36_0000;
assign rom1_offset   = gfx_offset;
assign rom2_offset   = gfx_offset;
assign rom3_offset   = gfx_offset;//+22'h10_0000;

wire [19:0] gfx3_addr_pre = rom3_addr[17:0] + 20'h4_0000;

wire [21:0] gfx1_addr = {rom1_addr[19:0], rom1_half, 1'b0 };
wire [21:0] gfx2_addr = {rom2_addr[19:0], rom2_half, 1'b0 };
wire [21:0] gfx3_addr = {gfx3_addr_pre, rom3_half, 1'b0 };

jtframe_sdram_mux #(
    // Frame buffer, read access
    .SLOT2_AW   ( 18    ),  //8
    .SLOT2_DW   ( 16    ),
    // VRAM read access:
    .SLOT3_AW   ( 18    ),
    .SLOT3_DW   ( 16    ),
    .SLOT4_AW   ( 18    ),  //4
    .SLOT4_DW   ( 16    ),
    .SLOT5_AW   ( 18    ),  //5
    .SLOT5_DW   ( 16    ),
    // GFX ROM
    .SLOT6_AW   ( 22    ),  //6
    .SLOT7_AW   ( 22    ),  //7
    .SLOT8_AW   ( 22    ),  //8
    .SLOT6_DW   ( 32    ),
    .SLOT7_DW   ( 32    ),
    .SLOT8_DW   ( 32    )
)
u_sdram_mux(
    .rst            ( rst           ),
    .clk            ( clk           ),
    .vblank         ( 1'b0          ),

    // VRAM read access only
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
    .slot6_offset   ( rom1_offset       ),
    .slot6_addr     ( gfx1_addr         ),
    .slot6_dout     ( rom1_data         ),

    .slot7_offset   ( rom2_offset       ),
    .slot7_addr     ( gfx2_addr         ),
    .slot7_dout     ( rom2_data         ),

    .slot8_offset   ( rom3_offset       ),
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

// Dump output frame buffer
integer dumpcnt=0, dumpv=0, fout;


reg dumpdly, dumplast;

initial fout=$fopen("video.raw","wb");

always @(posedge clk) if(cen8 && !HB && !VB) begin
    $fwrite(fout,"%u", { 8'hff, blue, green, red });
end

// SDRAM
reg [15:0] sdram[0:(2**22)-1];

initial begin
    $readmemh( "gfx16.hex",  sdram, gfx_offset, gfx_offset+1_572_875  );
    $readmemh( "vram16.hex", sdram, vram_offset, vram_offset+98303 );
end

localparam SDRAM_STCNT=5; // 6 Realistic, 5 Possible, less than 5 unrealistic
reg [SDRAM_STCNT-1:0] sdram_st;
reg       last_st0, last_HS;
integer  sdram_idle_cnt, total_cycles, line_idle;
wire     HS_negedge = !HS &&  last_HS;
wire     HS_posedge =  HS && !last_HS;

always @(posedge clk, posedge rst) begin
    if( rst ) begin
        sdram_st <= 1;
        data_rdy <= 1'b1;
        data_read<= 16'd0;
        last_st0 <= 1'b0;
        sdram_idle_cnt <= 0;
        total_cycles   <= 0;
        line_idle      <= 0;
    end else begin
        last_st0 <= sdram_st[0];
        last_HS  <= HS;
        if( last_st0 && sdram_st[0] ) begin
            sdram_idle_cnt=sdram_idle_cnt+1;
            line_idle <= line_idle+1;
        end
        if( HS_negedge ) line_idle <= 0;
        total_cycles = total_cycles+1;
        if(sdram_st!=1 || sdram_req ) sdram_st <= { sdram_st[SDRAM_STCNT-2:0], sdram_st[SDRAM_STCNT-1] };
        sdram_ack  <= 1'b0;
        data_rdy <= 1'b0;
        if( sdram_req ) begin
            sdram_ack <= 1'b1;
        end
        if( sdram_st[SDRAM_STCNT-1] ) begin
            data_rdy <= 1'b1;
            data_read  <= { sdram[sdram_addr+1], sdram[sdram_addr] };
            if( !sdram_rnw ) sdram[sdram_addr] <= data_write[15:0];
        end
    end
end

// Reset and clock

initial begin
    rst = 1'b0;
    #20 rst = 1'b1;
    #400 rst = 1'b0;
end

initial begin
    clk = 1'b0;
    forever #10.417 clk = ~clk;
end

integer cen_cnt=0;

always @(posedge clk) begin
    cen_cnt <= cen_cnt+1;
    if(cen_cnt>=5) cen_cnt<=0;
    cen8 <= cen_cnt==0;
end

integer framecnt;

always @(negedge VB, posedge rst) begin
    if(rst) begin
        framecnt <= 0;
    end else begin
        framecnt <= framecnt+1;
        $display("FRAME %d", framecnt);
        if ( framecnt==1 ) begin
            $display("%d%% SDRAM idle", (sdram_idle_cnt*100)/total_cycles);
            $finish;
        end
    end
end

always @(posedge HS, posedge rst) begin
    if( vdump[3:0]==0 ) $display("Line %d",vdump);
    if(vdump==8'd24 && 0) begin
        $display("%d%% SDRAM idle", (sdram_idle_cnt*100)/total_cycles);
        $finish;
    end
end

`define DUMP
`ifdef DUMP
`ifndef NCVERILOG
    initial begin
        $dumpfile("test.lxt");
        $dumpvars(0,test);
        $dumpon;
    end
`else
    initial begin
        $shm_open("test.shm");
        $shm_probe(test,"AS");
    end
`endif
`endif

endmodule