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

// I measured the line DMA header and found these values
// 604ns, 1.64us, 2.06us
// The first one would correspond to a line update with
// no OBJ and no row scroll
// The second, no row scroll, but OBJ is active
// The third, full row scroll and OBJ
// It seems that there is a minimum of ~600ns required
// by the original DMA controller even if no requests are
// in place.
// These three times are matched with this controller implementation
// a fourth case of no OBJ but row scroll active is implemented too
// but I couldn't measure it on the PCB. This fourth case is
// ~1.18us in simulation
//
// When all 6 palettes are enabled, the measured DMA interval is ~782us
// This fits well with copying the palette while still copying one
// OBJ entry per line. Row scrolling is ignored during this time, which
// should always be blanking anyway
// OBJ+PAL interval lasts for 784us in simulation. Given the accuracy of
// the measurement; this could be a perfect match.
// Copying OBJ during PAL is needed also in order to be able to transfer
// the whole OBJ table within one frame

module jtcps1_dma(
    input              rst,
    input              clk,
    input              pxl_cen,
    input              pxl2_cen,

    input              HB,
    input      [ 8:0]  vrender1, // 1 line ahead of vdump
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

    // Row scroll
    input      [15:0]  vram_row_base,
    input      [15:0]  row_offset,
    input              row_en,
    output reg [15:0]  row_scr,

    input      [ 7:0]  tile_addr,
    output     [15:0]  tile_data,

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
reg [4:0] line_cnt;
reg [8:0] scr_cnt;
reg       last_HB;
wire      HB_edge = !last_HB && HB;

reg  [10:0] vn, hn;
reg  [11:0] scan;
reg  [15:0] vrenderf;

reg         cache_wr;
reg  [11:0] hstep;
reg  [ 7:0] scr_over;

reg  [15:0] vscr1, vscr2, vscr3, row_scr_next;
reg  [15:0] vram_base;
reg         rd_bank, wr_bank;
reg  [ 2:0] active, swap, set_data;

localparam [7:0] LAST_SCR2 = 8'd225;

always @(*) begin
    casez( scr_cnt[8:6] )
        3'b0??:  wr_bank = ~active[0]; // SCR1
        3'b111:  wr_bank = ~active[2]; // SCR3
        default: wr_bank = ~active[1]; // SCR2
    endcase
    rd_bank = !tile_addr[7] ? active[0] : ( // SCR1
        tile_addr <= LAST_SCR2 ? active[1] : // SCR2
                            active[2]); // SCR3
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
localparam [5:0] OBJ_START=5'd7, OBJ_END=5'd22, OBJ_SKIP=5'd23;

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
        cache_wr   <= 1'b0;
    end else begin
        last_HB <= HB;
        br      <= |{bus_master, set_data};
        bg_pal  <= bus_master[PAL] & bg;

        vscr1  <= vpos1 + vrenderf;
        vscr2  <= vpos2 + vrenderf;
        vscr3  <= vpos3 + vrenderf;

        if( bus_master[PAL] ) vram_addr <= vram_pal_addr;   

        if( HB_edge ) begin
            active <= active ^ swap;
            swap   <= 3'd0;
            vrenderf <= {7'd0, (vrender1 ^ { 1'b0, {8{flip}}}) + (flip ? -9'd8 : 9'd1) };
            // It'd be better to use a vrender2 signal generated in the timing module
            // but adding 1 to vrender1 doesn't seem to create artifacts
            // note that adding 2 to vrender does create problems in the top horizontal line
        end

        if( HB_edge) begin
            bus_master <= 5'd1 << LINE;
            if( row_en && !bg_pal ) begin
                line_cnt <= 5'd0;
            end else begin
                row_scr_next <= {12'b0, hpos2[3:0] };
                line_cnt     <= br_obj ? OBJ_START : OBJ_SKIP;
            end
            row_scr    <= row_scr_next;
        end else if( br_pal && !bus_master ) begin
            bus_master <= 5'd1 << PAL;
        end else if(!bus_master) begin
            if( set_data[0] ) begin
                if( vscr1[2:0]==3'd0 ) begin
                    bus_master[SCR1]<=1'b1;
                    vn        <= vscr1;
                    hn        <= 11'h38 + { hpos1[10:3], 3'b0 };
                    scr_cnt   <= 9'd0;
                    scr_over  <= 8'd99;
                    vram_base <= vram1_base;
                    swap[0]   <= 1'b1;
                end else set_data[0] <= 1'b0;
            end
            if( set_data[1] & ~set_data[0] ) begin
                if( vscr2[3:0]=={ flip, 3'd0 } ) begin
                    bus_master[SCR2]<=1'b1;
                    vn <= vscr2;
                    hn <= 11'h30 + { hpos2[10:4], 4'b0 };
                    scr_cnt   <= 9'd128<<1;
                    scr_over  <= LAST_SCR2;
                    vram_base <= vram2_base;
                    swap[1]   <= 1'b1;
                end else set_data[1] <= 1'b0;
            end
            if( set_data[2] && set_data[1:0]==2'b0 ) begin
                if( vscr3[3:0]=={ flip, 3'd0 } ) begin
                    bus_master[SCR3]<=1'b1;
                    vn <= vscr3;
                    hn <= 11'h20 + { hpos3[10:5], 5'b0 };
                    scr_cnt   <= (LAST_SCR2+1)<<1;
                    scr_over  <= 8'd255;
                    vram_base <= vram3_base;
                    swap[2]   <= 1'b1;
                end else set_data[2] <= 1'b0;
            end
        end
        if( !br_pal && bus_master[PAL] ) bus_master[PAL] <= 1'b0;
        if( bg ) begin
            if( bus_master[LINE] && pxl2_cen ) begin
                // Line DMA transfer takes 2us
                line_cnt <= line_cnt + 5'd1;
                vram_clr <= line_cnt == OBJ_START; // clear cache to prevent
                // wrong readings that could trigger an end-of-table
                // flag in OBJ controller
                if( line_cnt == OBJ_START  ) begin
                    bg_obj  <= br_obj;
                    row_scr_next <= {12'b0, hpos2[3:0] } + 
                       (row_en ? vram_data : 16'h0); // this is collected
                        // without checking for vram_ok
                        // there should have been enough time
                        // for the read to get through
                    if( !br_obj ) line_cnt <= OBJ_END;
                end
                if( line_cnt == OBJ_END   ) bg_obj <= 1'b0;
                if( line_cnt >= OBJ_START )
                    vram_addr <= vram_obj_addr;
                else
                    vram_addr <= { vram_row_base[9:1], 8'd0 } + 
                                 { 7'd0, row_offset[9:0] + vrenderf };
                if( (&line_cnt) || (br_pal&&line_cnt==OBJ_END) ) begin
                    bus_master[LINE] <= 1'b0;
                    if(!br_pal ) set_data <= 3'b111;
                    // else bus_master[PAL] <= 1;
                end
            end
            ////////// Scroll tile cache
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
                    cache_wr <= 1'b1;
                end
            end
        end
    end
end

endmodule