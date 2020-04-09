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

// Open questions
// Is SCR2 always 96 reads or does it get shorter if row scroll is disabled?

module jtcps1_dma(
    input              rst,
    input              clk,
    input              pxl_cen,

    input              HB,
    input      [ 8:0]  vrender, // 1 line ahead of vdump
    input              flip,

    // control registers
    input      [15:0]  vram1_base,
    input      [15:0]  hpos1,
    input      [15:0]  vpos1,

    input      [15:0]  vram2_base,
    input      [15:0]  hpos2,
    input      [15:0]  vpos2,

    input      [15:0]  vram3_base,
    input      [15:0]  hpos3,
    input      [15:0]  vpos3,

    input      [ 7:0]  tile_addr,
    output     [15:0]  tile_data,
    // input      [15:0]  vram3_base,
    // Row scroll
    // input      [15:0]  vram_row_base,
    // input      [15:0]  row_offset,
    // input              row_en,
    // Row scroll
    // input      [17:1]  vram_row,

    // OBJ
    input              br_obj,
    output reg         bg_obj,
    input      [17:1]  vram_obj_addr,

    // PAL
    input              br_pal,
    output reg         bg_pal,
    input      [17:1]  vram_pal_addr,

    output reg [17:1]  vram_addr,
    input      [15:0]  vram_data,
    input              vram_ok,
    output reg         vram_clr,
    output             vram_cs,
    output reg         br,
    input              bg
);

reg [4:0] bus_master;
reg [3:0] line_cnt;
reg [8:0] scr_cnt;
reg       last_HB;
wire      HB_edge = !last_HB && HB;

reg  [10:0] vn, hn;
reg  [11:0] scan;
reg  [15:0] vrenderf;

reg         cache_wr;
reg  [11:0] hstep;
reg  [ 7:0] scr_over;

reg  [15:0] vscr1, vscr2, vscr3;
reg  [15:0] vram_base, hpos2_row;
reg         rd_bank, wr_bank;
reg  [ 2:0] active, swap, set_data;

always @(*) begin
    casez( scr_cnt[8:6] )
        3'b0??:  wr_bank = ~active[0]; // SCR1
        3'b111:  wr_bank = ~active[2]; // SCR3
        default: wr_bank = ~active[1]; // SCR2
    endcase
    casez( tile_addr[7:5] )
        3'b0??:  rd_bank = active[0]; // SCR1
        3'b111:  rd_bank = active[2]; // SCR3
        default: rd_bank = active[1]; // SCR2
    endcase
end

jtframe_dual_ram #(.dw(16), .aw(9)) u_cache(
    .clk0   ( clk           ),
    .clk1   ( clk           ),
    // Port 0: write
    .data0  ( vram_data     ),
    .addr0  ( { wr_bank, scr_cnt[8:1] } ),
    .we0    ( cache_wr      ),
    .q0     (               ),
    // Port 1: read
    .data1  ( ~16'd0        ),
    .addr1  ( { rd_bank, tile_addr    } ),
    .we1    ( 1'b0          ),
    .q1     ( tile_data     )
);

localparam LINE=0, PAL=1, SCR1=2, SCR2=3, SCR3=4;
localparam OBJ_START=4'd3, OBJ_END=4'd11;

always @(*) begin
    if( bus_master[SCR1] ) begin
        scan   = { vn[8],   hn[8:3], vn[7:3] };
        hstep  = 11'd8;
    end else if( bus_master[SCR2] ) begin
        scan   = { vn[9:8], hn[9:4], vn[7:4] };
        hstep  = 11'd16;
    end else begin
        scan   = { vn[10:8], hn[10:5], vn[7:5] };
        hstep  = 11'd32;
    end
end

assign vram_cs = br;


always @(posedge clk, posedge rst) begin
    if( rst ) begin
        br         <= 1'b0;
        bus_master <= 5'b0;
        bg_obj     <= 1'b0;
        bg_pal     <= 1'b0;
        line_cnt   <= 4'd0;
        vram_addr  <= 17'd0;
        vram_clr   <= 1'b0;
        scr_cnt    <= 9'd0;
        active     <= 3'b0;
        swap       <= 3'b0;
        set_data   <= 3'b0;
    end else begin
        last_HB <= HB;
        br      <= |{bus_master, set_data};
        bg_pal  <= bus_master[PAL]  ? bg : 1'b0;

        vscr1  <= vpos1 + vrenderf;
        vscr2  <= vpos2 + vrenderf;
        vscr3  <= vpos3 + vrenderf;

        if( bus_master[PAL] ) vram_addr <= vram_pal_addr;
        else if( bus_master[LINE] ) vram_addr <= vram_obj_addr;

        if( HB_edge ) begin
            active <= active ^ swap;
            swap   <= 3'd0;
            vrenderf <= {7'd0, (vrender+9'd2) ^ { 1'b0, {8{flip}}} };
        end

        if( !bus_master ) begin
            if( br_pal ) begin
                bus_master <= 2'b01 << PAL;
            end else if( HB_edge) begin
                bus_master <= 2'b01 << LINE;
                line_cnt   <= 4'd0;
            end else begin
                if( set_data[0] ) begin
                    if( vscr1[2:0]==3'd0 ) begin
                        bus_master[SCR1]<=1'b1;
                        vn        <= vscr1;
                        hn        <= 11'h38 + { hpos1[10:3], 3'b0 };
                        scr_cnt   <= 9'd0;
                        scr_over  <= 8'd97;
                        vram_base <= vram1_base;
                        swap[0]   <= 1'b1;
                    end else set_data[0] <= 1'b0;
                end
                if( set_data[1] & ~set_data[0] ) begin
                    if( vscr2[3:0]==4'd0 ) begin
                        bus_master[SCR2]<=1'b1;
                        vn <= vscr2;
                        hn <= 11'h30 + { hpos2_row[10:4], 4'b0 };
                        scr_cnt   <= 9'd128<<1;
                        scr_over  <= 8'd223;
                        vram_base <= vram2_base;
                        swap[1]   <= 1'b1;
                    end else set_data[1] <= 1'b0;
                end
                if( set_data[2] && set_data[1:0]==2'b0 ) begin
                    if( vscr3[3:0]==4'd0 ) begin
                        bus_master[SCR3]<=1'b1;
                        vn <= vscr3;
                        hn <= 11'h20 + { hpos3[10:5], 5'b0 };
                        scr_cnt   <= 9'd224<<1;
                        scr_over  <= 8'd255;
                        vram_base <= vram3_base;
                        swap[2]   <= 1'b1;
                    end else set_data[2] <= 1'b0;
                end
            end
            cache_wr <= 1'b0;
        end else begin
            if( !br_pal && bus_master[PAL] ) bus_master[PAL] <= 1'b0;
            if( bg ) begin
                if( bus_master[LINE] && pxl_cen ) begin
                    // Line DMA transfer takes 2us
                    line_cnt <= line_cnt + 4'd1;
                    vram_clr <= line_cnt == 4'd0; // clear cache to prevent
                    // wrong readings that could trigger an end-of-table
                    // flag in OBJ controller
                    hpos2_row <= hpos2; // + vram_data;
                    if( line_cnt == OBJ_START && br_obj ) bg_obj <= 1'b1;
                    if( line_cnt == OBJ_END             ) bg_obj <= 1'b0;
                    if( &line_cnt ) begin
                        bus_master[LINE] <= 1'b0;
                        set_data         <= 3'b111;
                    end
                end
                ////////// Scroll 1
                if( bus_master[SCR1] || bus_master[SCR2] || bus_master[SCR3] ) begin
                    if( pxl_cen && (!scr_cnt[0] || (scr_cnt[0]&&cache_wr) ) ) begin
                        scr_cnt   <= scr_cnt + 1;
                        if( scr_cnt[8:1]==scr_over && scr_cnt[0] ) begin
                            bus_master[SCR3:SCR1] <= 3'b0;
                            set_data <= set_data & ~bus_master[SCR3:SCR1];
                        end
                    end                        
                    if( !scr_cnt[0] ) begin
                        vram_addr <= { vram_base[9:1], 8'd0 } + { 4'd0, scan, scr_cnt[1] };
                        cache_wr  <= 1'b0;
                    end else if( vram_ok && !cache_wr) begin
                        if( scr_cnt[1] ) hn <= hn + hstep;
                        cache_wr       <= 1'b1;
                    end
                end
            end
        end
    end
end

endmodule