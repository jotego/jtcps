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
    
`timescale 1ns/1ps

// Scroll 1 is 512x512, 8x8 tiles
// Scroll 2 is 1024x1024 16x16 tiles
// Scroll 3 is 2048x2048 32x32 tiles

module jtcps1_mmr(
    input              rst,
    input              clk,

    input              ppu_rstn,
    input              ppu1_cs,
    input              ppu2_cs,

    input   [ 5:1]     addr,
    input   [ 1:0]     dsn,      // data select, active low
    input   [15:0]     cpu_dout,
    output  reg [15:0] mmr_dout,
    // registers
    output reg [15:0]  ppu_ctrl,
    input              obj_dma_clr,
    output reg         obj_dma_ok,
    // Scroll
    output reg [15:0]  hpos1,
    output reg [15:0]  hpos2,
    output reg [15:0]  hpos3,
    output reg [15:0]  vpos1,
    output reg [15:0]  vpos2,
    output reg [15:0]  vpos3,

    output reg [15:0]  hstar1,
    output reg [15:0]  hstar2,

    output reg [15:0]  vstar1,
    output reg [15:0]  vstar2,

    // ROM banks
(*keep*)    output     [ 5:0]  game,
(*keep*)    output     [15:0]  bank_offset,
(*keep*)    output     [15:0]  bank_mask,

    // VRAM position
    output reg [15:0]  vram1_base,
    output reg [15:0]  vram2_base,
    output reg [15:0]  vram3_base,
    output reg [15:0]  vram_obj_base,
    output reg [15:0]  vram_row_base,
    output reg [15:0]  row_offset,
    output reg [15:0]  pal_base,
    output reg         pal_copy,

    // CPS-B Registers configuration
    input              cfg_we,
    input      [ 7:0]  cfg_data,

    output reg [15:0]  layer_ctrl,
    output reg [15:0]  prio0,
    output reg [15:0]  prio1,
    output reg [15:0]  prio2,
    output reg [15:0]  prio3,
    output reg [ 5:0]  pal_page_en, // which palette pages to copy
    output     [ 7:0]  layer_mask0,
    output     [ 7:0]  layer_mask1,
    output     [ 7:0]  layer_mask2,
    output     [ 7:0]  layer_mask3,
    output     [ 7:0]  layer_mask4
);

// Shift register configuration
parameter REGSIZE=21;
reg [8*REGSIZE-1:0] regs;

wire [5:1] addr_id,      
           addr_mult1,   
           addr_mult2,   
           addr_rslt0,   
           addr_rslt1,   
           addr_layer,   
           addr_prio0,   
           addr_prio1,   
           addr_prio2,   
           addr_prio3,   
           addr_pal_page,
           addr_in2,
           addr_in3;


wire [10:0] addrb = {
           addr == addr_pal_page,// 10
           addr == addr_prio3,   // 9  
           addr == addr_prio2,   // 8  
           addr == addr_prio1,   // 7  
           addr == addr_prio0,   // 6  
           addr == addr_layer,   // 5  
           addr == addr_rslt1,   // 4  
           addr == addr_rslt0,   // 3  
           addr == addr_mult2,   // 2
           addr == addr_mult1,   // 1   
           addr == addr_id       // 0
        };

wire [7:0]  cpsb_id;
reg  [15:0]  mult1, mult2;
reg  [15:0]  rslt1, rslt0;

always @(posedge clk) {rslt1,rslt0} <= mult1*mult2;

`define MMR(a) regs[8*(a+1)-1:8*a]

assign addr_id       = `MMR(0)>>1;
assign cpsb_id       = `MMR(1); // 16-bit value compressed in 8 bits
assign addr_mult1    = `MMR(2)>>1;
assign addr_mult2    = `MMR(3)>>1;
assign addr_rslt0    = `MMR(4)>>1;
assign addr_rslt1    = `MMR(5)>>1;
assign addr_layer    = `MMR(6)>>1;
assign addr_prio0    = `MMR(7)>>1;
assign addr_prio1    = `MMR(8)>>1;
assign addr_prio2    = `MMR(9)>>1;
assign addr_prio3    = `MMR(10)>>1;
assign addr_in2      = `MMR(11)>>1;
assign addr_in3      = `MMR(12)>>1;
assign addr_pal_page = `MMR(13)>>1;
assign layer_mask0   = `MMR(14);
assign layer_mask1   = `MMR(15);
assign addr_mult1    = `MMR(2)>>1;
assign addr_mult2    = `MMR(3)>>1;
assign addr_rslt0    = `MMR(4)>>1;
assign addr_rslt1    = `MMR(5)>>1;
assign addr_layer    = `MMR(6)>>1;
assign addr_prio0    = `MMR(7)>>1;
assign addr_prio1    = `MMR(8)>>1;
assign addr_prio2    = `MMR(9)>>1;
assign addr_prio3    = `MMR(10)>>1;
assign addr_in2      = `MMR(11)>>1;
assign addr_in3      = `MMR(12)>>1;
assign addr_pal_page = `MMR(13)>>1;
assign layer_mask0   = `MMR(14);
assign layer_mask1   = `MMR(15);
assign layer_mask2   = `MMR(16);
assign layer_mask3   = `MMR(17);
assign layer_mask4   = layer_mask3; // it is not well know what the
// mask bits are for layer 4. MAME uses the same values for layers 3 and 4
// so I just skip layer 4 from the configuration. This saves one MMR register
// which is what I need to make the MMR length 16 bytes. The length must be
// a multiple of 2 in order to work with the ROM downloading

// Mapper, last 5 bytes
assign game         = `MMR(18);
assign bank_offset  = { `MMR(20), `MMR(19) };
assign bank_mask    = { `MMR(22), `MMR(21) };


reg [15:0] pre_mux0, pre_mux1;
reg [ 1:0] sel;

always @(*) begin
    pre_mux0 = 16'hffff;
    pre_mux1 = 16'hffff;
    if( &addr ) sel=2'b00;
    else begin
        sel = { |addrb[10:6], |addrb[5:0] };
        case( addrb[5:0] )
            6'b000_001: pre_mux0 = {4'd0, cpsb_id[7:4], 4'd0, cpsb_id[3:0]};
            6'b000_010: pre_mux0 = mult1;
            6'b000_100: pre_mux0 = mult2;
            6'b001_000: pre_mux0 = rslt0;
            6'b010_000: pre_mux0 = rslt1;
            6'b100_000: pre_mux0 = layer_ctrl;
        endcase
        case( addrb[10:6] )
            5'b00_001: pre_mux1 = prio0;
            5'b00_010: pre_mux1 = prio1;
            5'b00_100: pre_mux1 = prio2;
            5'b01_000: pre_mux1 = prio3;
            5'b10_000: pre_mux1 = { 10'd0, pal_page_en };
        endcase
    end
end

`ifdef SIMULATION
    `ifndef CPSB_CONFIG
    //`define CPSB_CONFIG {REGSIZE{8'b0}}
    `define CPSB_CONFIG 16'hfff7, 16'h4440, 8'h07, 128'h00_08_04_02_2A_32_28_30_26_2E_FF_FF_FF_FF_04_20
        //{{16{8'b0}}} }
    // Ffight  FF F7 44 40 07
    // Ghouls  F1 17 65 40 0A
    // Strider FF 77 00 40 1D 
    `endif
`endif

always@(posedge clk) begin
    if( cfg_we ) begin
        regs[7:0] <= cfg_data;
        regs[8*REGSIZE-1:8] <= regs[8*(REGSIZE-1)-1:0];
    end
end

function [15:0] data_sel;
    input [15:0] olddata;
    input [15:0] newdata;
    input [ 1:0] dsn;
    data_sel = { dsn[1] ? olddata[15:8] : newdata[15:8], dsn[0] ? olddata[7:0] : newdata[7:0] };
endfunction

wire reg_rst;
reg  pre_copy;

// For quick simulation of the video alone
// it is possible to load the regs from a file
// defined by the macro MMR_FILE

`ifndef SIMULATION
`undef MMR_FILE
`endif

`ifdef MMR_FILE
reg [15:0] mmr_regs[0:15];
initial begin
    regs = { `CPSB_CONFIG };
    // $display("CPSB_CONFIG = %X", regs );
    $display("Layer control address: %X", `MMR(6) );
    $display("Palette page  address: %X", `MMR(11));    
    $display("INFO: MMR initial values read from %s", `MMR_FILE );
    $readmemh(`MMR_FILE,mmr_regs);
    vram_obj_base  = mmr_regs[0];
    vram1_base     = mmr_regs[1];
    vram2_base     = mmr_regs[2];
    vram3_base     = mmr_regs[3];
    pal_base       = mmr_regs[4];
    hpos1          = mmr_regs[5];
    vpos1          = mmr_regs[6];
    hpos2          = mmr_regs[7];
    vpos2          = mmr_regs[8];
    hpos3          = mmr_regs[9];
    vpos3          = mmr_regs[10];
    layer_ctrl     = mmr_regs[11]; //16'h12ce; // default
    pal_page_en    = mmr_regs[12];
    vram_row_base  = mmr_regs[13];
    row_offset     = mmr_regs[14];
    ppu_ctrl       = mmr_regs[15];
    // Default layer order = 4B = 01 00 10 11
    // Strider layer order = 4E = 01 00 11 10
    //layer_ctrl     = 16'h138e; // strider
    //layer_ctrl     = {2'b0,2'b01,2'b11,2'b10,2'b00,6'd0}; // strider
    prio0 = ~16'h0;
    prio1 = ~16'h7e01;
    prio2 = ~16'h7fff;
    prio3 = ~16'h7e02;
    obj_dma_ok = 1'b1; // so data is copied at the beginning of sim.
end
assign reg_rst = 1'b0;  // reset is skipped for this type of simulation
`else
// Normal synthesis:
assign reg_rst = rst | ~ppu_rstn;
`endif

always @(posedge clk, posedge reg_rst) begin
    if( reg_rst ) begin
        hpos1         <= 16'd0;
        hpos2         <= 16'd0;
        hpos3         <= 16'd0;
        vpos1         <= 16'd0;
        vpos2         <= 16'd0;
        vpos3         <= 16'd0;
        vram1_base    <= 16'd0;
        vram2_base    <= 16'd0;
        vram3_base    <= 16'd0;
        vram_obj_base <= 16'd0;
        pal_base      <= 16'd0;
        pal_page_en   <= 6'h3f;

        prio0         <= ~16'h0;
        prio1         <= ~16'h0;
        prio2         <= ~16'h0;
        prio3         <= ~16'h0;
        pal_page_en   <=  6'h3f;
        layer_ctrl    <=  {2'b0,2'b11,2'b10,2'b01,2'b00,5'd0};

        pal_copy      <= 1'b0;
        pre_copy      <= 1'b0;
        mmr_dout      <= 16'hffff;
    end else begin
        if( !ppu1_cs && pre_copy ) begin
            // The palette copy signal is delayed until after ppu1_cs has gone down
            // otherwise it would get a wrong pal_base value as pal_base is written
            // to a bit after ppu1_cs has gone high
            pal_copy <= 1'b1;
            pre_copy <= 1'b0;
        end
        else pal_copy <= 1'b0;
        if( obj_dma_clr ) obj_dma_ok <= 1'b0;
        if( ppu1_cs ) begin
            case( addr[5:1] )
                // CPS-A registers
                5'h00: begin
                    vram_obj_base <= data_sel(vram_obj_base , cpu_dout, dsn);
                    obj_dma_ok   <= 1'b1;
                end
                5'h01: vram1_base    <= data_sel(vram1_base    , cpu_dout, dsn);
                5'h02: vram2_base    <= data_sel(vram2_base    , cpu_dout, dsn);
                5'h03: vram3_base    <= data_sel(vram3_base    , cpu_dout, dsn);
                5'h04: vram_row_base <= data_sel(vram_row_base , cpu_dout, dsn);
                5'h05: begin
                    pal_base      <= data_sel(pal_base      , cpu_dout, dsn);
                    pre_copy      <= 1'b1;
                    //$display("PALETTE!");
                end
                5'h06: hpos1      <= data_sel(hpos1     , cpu_dout, dsn);
                5'h07: vpos1      <= data_sel(vpos1     , cpu_dout, dsn);
                5'h08: hpos2      <= data_sel(hpos2     , cpu_dout, dsn);
                5'h09: vpos2      <= data_sel(vpos2     , cpu_dout, dsn);
                5'h0a: hpos3      <= data_sel(hpos3     , cpu_dout, dsn);
                5'h0b: vpos3      <= data_sel(vpos3     , cpu_dout, dsn);
                5'h0c: hstar1     <= data_sel(hstar1    , cpu_dout, dsn);
                5'h0d: vstar1     <= data_sel(vstar1    , cpu_dout, dsn);
                5'h0e: hstar2     <= data_sel(hstar2    , cpu_dout, dsn);
                5'h0f: vstar2     <= data_sel(vstar2    , cpu_dout, dsn);
                5'h10: row_offset <= data_sel(row_offset, cpu_dout, dsn);
                5'h11: ppu_ctrl   <= data_sel(ppu_ctrl  , cpu_dout, dsn);
            endcase
        end
        if( ppu2_cs ) begin
            mmr_dout <= sel[0] ? pre_mux0 : (sel[1] ? pre_mux1 : 16'hffff);
            if( addrb[ 1] && !dsn) mult1      <= cpu_dout;
            if( addrb[ 2] && !dsn) mult2      <= cpu_dout;
            if( addrb[ 5] && !dsn) layer_ctrl <= cpu_dout;
            if( addrb[ 6] && !dsn) prio0      <= cpu_dout;
            if( addrb[ 7] && !dsn) prio1      <= cpu_dout;
            if( addrb[ 8] && !dsn) prio2      <= cpu_dout;
            if( addrb[ 9] && !dsn) prio3      <= cpu_dout;
            if( addrb[10] && !dsn) pal_page_en<= cpu_dout;
        end
    end
end


endmodule
