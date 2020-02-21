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

// Brightness only affects the gain of the signal, not the offset
// Depending on the impedance of the 74'07 device, the maximum
// attenuation can be as much as 40% for brightness setting of 15
// If NMOS RON is comparable to the R2R ladder, attenuation will be
// lower (~27%)

// To do:
// 1. Copy only the marked pages
// 2. Bus arbitrion with main CPU --> check PCB

module jtcps1_colmix(
    input              rst,
    input              clk,
    input              pxl_cen,

    input              VB,
    input              HB,
    output  reg        LVBL_dly,
    output  reg        LHBL_dly,
    input   [ 3:0]     gfx_en,

    input   [10:0]     scr1_pxl,
    input   [10:0]     scr2_pxl,
    input   [10:0]     scr3_pxl,
    input   [ 8:0]     obj_pxl,

    // Layer priority
    input   [15:0]     layer_ctrl,
    input   [ 7:0]     layer_mask0, // mask for enable bits
    input   [ 7:0]     layer_mask1,
    input   [ 7:0]     layer_mask2,
    input   [ 7:0]     layer_mask3,
    input   [ 7:0]     layer_mask4,
    input   [15:0]     prio0,
    input   [15:0]     prio1,
    input   [15:0]     prio2,
    input   [15:0]     prio3,
    // Palette copy
    input              pal_copy,
    input   [15:0]     pal_base,
    input   [ 5:0]     pal_page_en, // which palette pages to copy

    // VRAM access
    output reg [17:1]  vram_addr,
    input      [15:0]  vram_data,
    input              vram_ok,
    output reg         vram_cs,

    (*keep*) output reg [7:0]  red,
    (*keep*) output reg [7:0]  green,
    (*keep*) output reg [7:0]  blue
);

reg  [11:0] pxl;
wire [11:0] pal_addr;

// Palette
reg [15:0] pal[0:(2**12)-1]; // 4096?
reg [15:0] raw;
wire [3:0] raw_r, raw_g, raw_b, raw_br;
reg  [3:0] dly_r, dly_g, dly_b;

// These are the top four bits written by CPS-B to each
// pixel of the frame buffer. These are likely sent by CPS-A
// via pins XS[4:0] and CPS-B encodes them
// 000 = OBJ ?
// 001 = SCROLL 1
// 010 = SCROLL 2
// 011 = SCROLL 3
// 100 = STAR FIELD

localparam [2:0] OBJ=3'b0, SCR1=3'b1, SCR2=3'd2, SCR3=3'd3;

assign raw_br   = raw[15:12]; // r
assign raw_r    = raw[11: 8]; // br
assign raw_g    = raw[ 7: 4]; // b
assign raw_b    = raw[ 3: 0]; // g
assign pal_addr = pxl;

function [13:0] layer_mux;
    input [ 8:0] obj;
    input [10:0] scr1;
    input [10:0] scr2;
    input [10:0] scr3;
    input [ 1:0] sel;

    layer_mux =  sel==2'b00 ? {      2'b00,  OBJ, obj }   :
                (sel==2'b01 ? { scr1[10:9], SCR1, scr1[8:0]}   :
                (sel==2'b10 ? { scr2[10:9], SCR2, scr2[8:0]}   :
                (sel==2'b11 ? { scr3[10:9], SCR3, scr3[8:0]}   : 13'h1fff )));
endfunction

wire [4:0] lyren = {
    |(layer_mask4[5:0] & layer_ctrl[5:0]), // Star layer 1
    |(layer_mask3[5:0] & layer_ctrl[5:0]), // Star layer 0
    |(layer_mask2[5:0] & layer_ctrl[5:0]),
    |(layer_mask1[5:0] & layer_ctrl[5:0]),
    |(layer_mask0[5:0] & layer_ctrl[5:0])
};

// OBJ layer cannot be disabled by hardware
wire [8:0] obj_mask   = { obj_pxl[8:4],   obj_pxl[3:0]  | {4{~gfx_en[3]}} };
wire [10:0] scr1_mask = { scr1_pxl[10:4], scr1_pxl[3:0] | {4{~(lyren[0]& gfx_en[0])}} };
wire [10:0] scr2_mask = { scr2_pxl[10:4], scr2_pxl[3:0] | {4{~(lyren[1]& gfx_en[1])}} };
wire [10:0] scr3_mask = { scr3_pxl[10:4], scr3_pxl[3:0] | {4{~(lyren[2]& gfx_en[2])}} };

localparam QW = 14*3;
reg [13:0] lyr3, lyr2, lyr1, lyr0;
reg [QW-1:0] lyr_queue;
reg [11:0] pre_pxl;
reg [ 1:0] group;

always @(posedge clk) if(pxl_cen) begin
    lyr3 <= layer_mux( obj_mask, scr1_mask, scr2_mask, scr3_mask, layer_ctrl[ 7: 6] );
    lyr2 <= layer_mux( obj_mask, scr1_mask, scr2_mask, scr3_mask, layer_ctrl[ 9: 8] );
    lyr1 <= layer_mux( obj_mask, scr1_mask, scr2_mask, scr3_mask, layer_ctrl[11:10] );
    lyr0 <= layer_mux( obj_mask, scr1_mask, scr2_mask, scr3_mask, layer_ctrl[13:12] );
    pxl  <= pre_pxl;
end

reg has_priority;

always @(*) begin
    case( group )
        2'd0: has_priority = prio0[ pre_pxl[3:0] ];
        2'd1: has_priority = prio1[ pre_pxl[3:0] ];
        2'd2: has_priority = prio2[ pre_pxl[3:0] ];
        2'd3: has_priority = prio3[ pre_pxl[3:0] ];
    endcase
end

// This take 6 clock cycles to process the 6 layers
always @(posedge clk) begin
    if(pxl_cen) begin
        {group, pre_pxl } <= lyr3;
        lyr_queue <= { lyr0, lyr1, lyr2 };
    end else begin
        if( pre_pxl[3:0]==4'hf ||  ( !(lyr_queue[11:9]==OBJ && has_priority ) && lyr_queue[3:0] != 4'hf) )
            { group, pre_pxl } <= lyr_queue[13:0];
        lyr_queue <= { ~14'd0, lyr_queue[QW-1:14] };
    end
    /*
    if( lyr0[3:0] != 4'hf ) begin
        pxl      <= lyr0;
    end else if( lyr1[3:0] != 4'hf ) begin
        pxl      <= lyr1;
    end else if( lyr2[3:0] != 4'hf ) begin
        pxl      <= lyr2;
    end else  begin
        pxl      <= lyr3;
    end*/
end

`ifdef SIMULATION
integer f, rd_cnt;
initial begin
    //$readmemh("pal16.hex",pal);
    f=$fopen("pal.bin","rb");
    if(f==0) begin
        $display("WARNING: cannot open file pal16.hex");
        // no palette file, initialize with zeros
        for( rd_cnt = 0; rd_cnt<4096; rd_cnt=rd_cnt+1 ) pal[rd_cnt] <= 16'd0;
    end else begin
        rd_cnt = $fread(pal,f);
        $display("INFO: read %d bytes from pal.bin",rd_cnt);
        $fclose(f);
        //$finish;
    end
end
`endif

// Palette copy
reg [11:0] pal_cnt;
reg [ 4:0] pal_st;

//wire pal_copy2;
//
//`ifdef SIMULATION
//reg last_VB;
//always @(posedge clk) last_VB <= VB;
//assign pal_copy2 = VB && !last_VB;
//`else

`ifdef SIMULATION
reg [15:0] cur_pal;
always @(pal_addr) begin
    cur_pal = pal[pal_addr];
end

integer fpal,fpal_cnt;
`endif

always @(posedge clk, posedge rst) begin
    if( rst ) begin
        raw       <= 16'h0;
        pal_cnt   <= 12'd0;
        pal_st    <= 4'd1;
        vram_cs   <= 1'b0;
        vram_addr <= 23'd0;
    end else begin
        raw <= pal[pal_addr];
        `ifdef FORCE_GRAY
        raw <= {4'hf, {3{pal_addr[3:0]}} }; // uses palette index as gray colour
        `endif
        `ifdef FORCE_RED
        raw <= {4'hf,pal[pal_addr][11:8],8'h0};
        `endif
        `ifdef FORCE_GREEN
        raw <= {4'hf,4'h0,pal[pal_addr][7:4],4'h0};
        `endif
        `ifdef FORCE_BLUE
        raw <= {4'hf,8'h0,pal[pal_addr][3:0]};
        `endif

        if( pal_copy && pal_st[0] ) begin
            vram_cs <= 1'b1;
        end
        if( vram_cs ) begin
            pal_st <= { pal_st[3:0], pal_st[4] };
        end else pal_st <= 5'b1;
        case( pal_st )
            5'b0001: begin
                vram_addr <= { pal_base[9:1], 8'd0 } + pal_cnt;
            end
            // 4'b0010: wait for OK signal to go down in reaction to the change
            // in vram_addr
            5'b1000: if(vram_ok) begin
                pal[pal_cnt] <= vram_data;
                if( &pal_cnt ) begin
                    vram_cs <= 1'b0;
                    // `ifdef SIMULATION
                    // $display("Palette base = %X",pal_base);
                    // fpal=$fopen("pal_dump.hex","w");
                    // for(fpal_cnt=0;fpal_cnt<4096;fpal_cnt=fpal_cnt+1) begin
                    //     $fwrite(fpal,"%x\n",pal[fpal_cnt]);
                    // end
                    // $fclose(fpal);
                    // `endif
                end
            end else pal_st <= pal_st;
            5'b1_0000: pal_cnt <= pal_cnt + 12'd1;
        endcase
    end
end

reg [7:0] mul_r, mul_g, mul_b;
wire [3:0] inv_br = ~raw_br; // if operator ~ is mixed in the multiplication
    // it seems to extend the sign or the bit width and
    // the result is wrong

// Use multiplier for brightness as these
// are cheap in most FPGAs
always @(posedge clk, posedge rst) begin
    if(rst) begin
        mul_r <= 8'd0;
        mul_g <= 8'd0;
        mul_b <= 8'd0;
    end else begin
        mul_r <= raw_r * inv_br; // mul = signal * 15
        mul_g <= raw_g * inv_br;
        mul_b <= raw_b * inv_br;
        { dly_r, dly_g, dly_b } <= { raw_r, raw_g, raw_b };
    end
end

reg vb1, hb1;

always @(posedge clk, posedge rst) begin
    if(rst) begin
        red   <= 8'd0;
        green <= 8'd0;
        blue  <= 8'd0;
        vb1   <= 1'b1;
        hb1   <= 1'b1;
    end else if(pxl_cen) begin
        vb1   <= VB;
        hb1   <= HB;
        LVBL_dly <= ~vb1;
        LHBL_dly <= ~hb1;
        // signal * 17 - signal*15/4 = signal * (17-15/4-15/8)
        // 33% max attenuation for brightness
        if( vb1 || hb1 ) begin
            red   <= 8'd0;
            green <= 8'd0;
            blue  <= 8'd0;
        end else begin
            `ifdef NOBRIGHT
            red   <= {2{raw_r}};
            green <= {2{raw_g}};
            blue  <= {2{raw_b}};
            `else
            red   <= {2{dly_r}} - (mul_r>>2) - (mul_r>>3); // - (mul_r>>4);
            green <= {2{dly_g}} - (mul_g>>2) - (mul_g>>3); // - (mul_g>>4);
            blue  <= {2{dly_b}} - (mul_b>>2) - (mul_b>>3); // - (mul_b>>4);
            `endif
        end
    end
end
/*
`ifdef SIMULATION
integer fvideo;
initial begin
    fvideo = $fopen("video_colmix.raw","wb");
end

wire [31:0] video_dump = { 8'hff, {2{raw_r}}, {2{raw_g}}, {2{raw_b}} };

// Define VIDEO_START with the first frame number for which
// video will be dumped. If undefined, it will start from frame 0
`ifndef VIDEO_START
`define VIDEO_START 0
`endif

always @(posedge clk) if(pxl_cen) begin
    if( LVBL_dly && LHBL_dly ) $fwrite(fvideo,"%u", video_dump);
end

`endif
*/
endmodule
