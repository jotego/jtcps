`timescale 1ns/1ps

module test;

`define SIMULATION

reg                rst, clk, cen8;
wire       [ 8:0]  vdump, vrender;
wire       [ 8:0]  hdump;
// video signals
wire               HS, VS, HB, VB, LHBL_dly, LVBL_dly;
wire       [ 7:0]  red, green, blue;

// Video RAM interface
wire       [17:1]  vram1_addr, vram_obj_addr, vpal_addr;
wire       [15:0]  vram1_data, vram_obj_data, vpal_data;
wire               vram1_ok,   vram_obj_ok, vpal_ok;
wire               vram1_cs,   vram_obj_cs, vpal_cs;

// GFX ROM interface
wire       [19:0]  rom1_addr, rom0_addr;
wire       [31:0]  rom1_data, rom0_data;
wire       [ 3:0]  rom1_bank, rom0_bank;
wire               rom1_half, rom0_half;
wire               rom1_cs, rom0_cs;
wire               rom1_ok, rom0_ok;

reg                downloading=1'b0, loop_rst=1'b0, sdram_ack;
reg        [31:0]  data_read;
wire               sdram_req, refresh_en;
wire       [21:0]  sdram_addr;
reg        [ 3:0]  sdram_ok4;
reg        [21:0]  last_sdram_addr;
reg                data_rdy;

reg        [15:0]  hpos1, vpos1, hpos2, vpos2, hpos3, vpos3,
                   vobj_base, vram1_base, vram2_base, vram3_base, pal_base;

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
assign slot_cs[2] = rom0_cs;
assign slot_cs[3] = vram1_cs;
assign slot_cs[4] = vpal_cs;
assign slot_cs[5] = 1'b0;
assign slot_cs[6] = rom1_cs;
assign slot_cs[7] = 1'b0;
assign slot_cs[8] = 1'b0;
assign slot_cs[9] = vram_obj_cs;

assign rom0_ok     = slot_ok[2];
assign vram1_ok    = slot_ok[3];
assign vpal_ok     = slot_ok[4];
assign rom1_ok     = slot_ok[6];
assign vram_obj_ok = slot_ok[9];

assign slot_wr[9:0] = 9'd0;

wire [15:0] data_write;
wire        sdram_rnw;

localparam [21:0] gfx_offset   = 22'h0A_8000;
localparam [21:0] vram_offset  = 22'h3B_0000;

//wire [19:0] gfx3_addr_pre = rom3_addr[17:0] + 20'h4_0000;

//wire [21:0] gfx0_addr = {rom0_addr[19:0], rom0_half, 1'b0 }; // OBJ
// 4+16 bits = 4+12+4
wire [21:0] gfx0_addr = {rom0_addr, rom0_half, 1'b0 }; // OBJ
wire [21:0] gfx1_addr = {rom1_addr[19:0], rom1_half, 1'b0 };

jtcps1_video UUT (
    .rst            ( rst           ),
    .clk            ( clk           ),
    .pxl_cen        ( cen8          ),

    .hdump          ( hdump         ),
    .vdump          ( vdump         ),
    .vrender        ( vrender       ),
    .gfx_en         ( 4'b1111       ),

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

    // CPU interface
    .ppu_rstn       ( 1'b1          ),
    .ppu1_cs        ( 1'b0          ),
    .ppu2_cs        ( 1'b0          ),

    // Video RAM interface
    .vram1_addr     ( vram1_addr    ),
    .vram1_data     ( vram1_data    ),
    .vram1_ok       ( vram1_ok      ),
    .vram1_cs       ( vram1_cs      ),

    .vram_obj_addr  ( vram_obj_addr ),
    .vram_obj_data  ( vram_obj_data ),
    .vram_obj_ok    ( vram_obj_ok   ),
    .vram_obj_cs    ( vram_obj_cs   ),

    .vpal_addr      ( vpal_addr     ),
    .vpal_data      ( vpal_data     ),
    .vpal_ok        ( vpal_ok       ),
    .vpal_cs        ( vpal_cs       ),
    
    // GFX ROM interface
    .rom1_addr  ( rom1_addr     ),
    .rom1_bank  ( rom1_bank     ),
    .rom1_half  ( rom1_half     ),
    .rom1_data  ( rom1_data     ),
    .rom1_cs    ( rom1_cs       ),
    .rom1_ok    ( rom1_ok       ),

    .rom0_addr  ( rom0_addr      ),
    .rom0_bank  ( rom0_bank      ),
    .rom0_half  ( rom0_half      ),
    .rom0_data  ( rom0_data      ),
    .rom0_cs    ( rom0_cs        ),
    .rom0_ok    ( rom0_ok        )
);

jtframe_sdram_mux #(
    // VRAM read access:
    .SLOT3_AW   ( 17    ),
    .SLOT4_AW   ( 17    ),  //4
    .SLOT5_AW   ( 17    ),  //5
    .SLOT9_AW   ( 17    ),  // OBJ VRAM

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

    // VRAM read access only
    .slot9_offset   ( vram_offset       ),
    .slot9_addr     ( vram_obj_addr     ),
    .slot9_dout     ( vram_obj_data     ),

    .slot3_offset   ( vram_offset       ),
    .slot3_addr     ( vram1_addr        ),
    .slot3_dout     ( vram1_data        ),


    .slot4_offset   ( vram_offset       ),
    .slot4_addr     ( vpal_addr         ),
    .slot4_dout     ( vpal_data         ),

    // GFX ROM
    .slot2_offset   ( gfx_offset/*^(22'b01_111<<17) */       ),
    .slot2_addr     ( gfx0_addr         ),
    .slot2_dout     ( rom0_data         ),

    .slot6_offset   ( gfx_offset        ),
    .slot6_addr     ( gfx1_addr         ),
    .slot6_dout     ( rom1_data         ),

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
reg [7:0] sdram[0:(2**23)-1];

`ifdef SDRAM_HEXFILE
initial begin
    $display("INFO: SDRAM read from sdram.hex");
    $readmemh("sdram.hex",sdram);
end
`else
integer fsdram, sdram_cnt, vram_offset_aux = vram_offset;

initial begin
    // load game ROM
    fsdram=$fopen("rom","rb");
    if(fsdram==0) begin
        $display("ERROR: cannot find ghouls.rom");
        $finish;
    end
    sdram_cnt=$fread(sdram,fsdram);
    $display("INFO: Read 0x%x x 64 kBytes for game ROM",sdram_cnt>>16);
    $display("           (0x%x bytes)",sdram_cnt);
    $fclose(fsdram);
    // load VRAM
    fsdram=$fopen("vram_sw.bin","rb");
    if(fsdram==0) begin
        $display("ERROR: cannot find vram_sw");
        $finish;
    end
    // not all simulator support a parameter used in the function arg list
    // that's why I need vram_offset_aux
    sdram_cnt=$fread(sdram,fsdram, vram_offset_aux<<1, 192*1024 );
    $display("INFO Read %d kB for VRAM",sdram_cnt>>10);
    $fclose(fsdram);
    //$display("VRAM[0]=%X", {sdram[vram_offset+1], sdram[vram_offset]});
    //$finish;
end
`endif

localparam SDRAM_STCNT=6; // 6 Realistic, 5 Possible, less than 5 unrealistic
reg [SDRAM_STCNT-1:0] sdram_st;
reg       last_st0, last_HS;
integer  sdram_idle_cnt, total_cycles, line_idle;
wire     HS_negedge = !HS &&  last_HS;
wire     HS_posedge =  HS && !last_HS;

wire [22:0] sdram8_addr = { sdram_addr, 1'b0 };

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
            data_read  <= { 
                sdram[ sdram8_addr+23'h3 ], 
                sdram[ sdram8_addr+23'h2 ],
                sdram[ sdram8_addr+23'h1 ],
                sdram[ sdram8_addr+23'h0 ] };
            if( !sdram_rnw ) begin
                sdram[{sdram_addr,1'b1}] <= data_write[15:8];
                sdram[{sdram_addr,1'b0}] <= data_write[ 7:0];
            end
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
    forever #(10.417) clk = ~clk;
end

integer cen_cnt=0;

always @(posedge clk) begin
    cen_cnt <= cen_cnt+1;
    if(cen_cnt>=5) cen_cnt<=0;
    cen8 <= cen_cnt==0;
end

integer framecnt;

`ifndef FRAMES
`define FRAMES 1
`endif

always @(negedge VB, posedge rst) begin
    if(rst) begin
        framecnt <= 0;
    end else begin
        framecnt <= framecnt+1;
        $display("FRAME %d", framecnt);
        if ( framecnt==`FRAMES ) begin
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