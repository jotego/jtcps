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
    input      [ 8:0]  vrender1, // 2 lines ahead of vdump
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
    input      [15:0]  vram_obj_base,
    input      [ 9:0]  obj_table_addr,
    input              obj_dma_ok,
    output     [15:0]  obj_table_data,

    // PAL
    input      [15:0]  vram_pal_base,
    input              pal_dma_ok,
    input      [11:0]  colmix_addr,
    output     [15:0]  pal_data,
    input      [ 5:0]  pal_page_en, // which palette pages to copy

    output reg [17:1]  vram_addr,
    input      [15:0]  vram_data,
    input              vram_ok,
    output reg         vram_clr,
    output             vram_cs,
    output reg         br,
    input              bg
);

localparam TASKW=1+1+3+6;
localparam [7:0] LAST_SCR1 = 8'd99, LAST_SCR2 = 8'd225, LAST_SCR3 = 8'd255;
localparam ROW=0, OBJ=1, SCR1=2, SCR2=3, SCR3=4,
           PAL0=5, PAL1=6,PAL2=7,PAL3=8,PAL4=9,PAL5=10;

reg  [15:0] vrenderf, vscr1, vscr2, vscr3, row_scr_next;
reg  [11:0] scan;
wire [11:0] wr_pal_addr;
reg  [10:0] vn, hn, hstep;
reg  [ 9:0] obj_cnt;
reg  [ 8:0] pal_cnt, vram_scr_base;
reg  [ 7:0] scr_cnt, scr_over;
reg  [ 4:0] misses;
reg  [ 3:0] step;
reg  [ 2:0] active, swap, pal_rd_page, pal_wr_page;

wire [ TASKW-1:0] next_step_task, next_task;
reg  [ TASKW-1:0] tasks, old_tasks, step_task, cur_task;

reg         last_HB, line_req, last_pal_dma_ok, pal_busy;
reg         rd_bank, wr_bank, adv, check_adv;
reg         rd_obj_bank, wr_obj_bank;
reg         scr_wr, obj_wr, pal_wr;
reg         obj_busy, obj_fill, obj_end, last_obj_dma_ok;

wire        HB_edge  = !last_HB && HB;
wire        tile_ok  = vrender1<9'd240 || vrender1>9'd257; // VB is 38 lines
wire        tile_vs  = vrender1== flip ? 9'd17 : 9'd12; // Vertical start, use for SCR3
    // 9'd17 was needed for 1941 logo screen on flip mode
    // 9'd12 was the previous value used for non flip images

// various addresses
wire [17:1] vrow_addr = { vram_row_base[9:3], row_offset[9:0] + vrenderf[9:0] },
            vscr_addr = { vram_scr_base[8:5], scan, scr_cnt[0] },
            vobj_addr = { vram_obj_base[9:3], obj_cnt },
            vpal_addr = { vram_pal_base[9:5], pal_rd_page , pal_cnt };

always @(*) begin
    casez( scr_cnt[7:5] )
        3'b0??:  wr_bank = ~active[0]; // SCR1
        3'b111:  wr_bank = ~active[2]; // SCR3
        default: wr_bank = ~active[1]; // SCR2
    endcase
    rd_bank = !tile_addr[7] ? active[0] : ( // SCR1
        tile_addr <= LAST_SCR2 ? active[1] : // SCR2
                            active[2]); // SCR3
end

reg [15:0] tile_din, obj_din, pal_din;
reg        vram_ok_dly;

always @(posedge clk) begin
    tile_din    <= vram_data;
    obj_din     <= vram_data & {16{~obj_fill}};
    pal_din     <= vram_data;
    vram_ok_dly <= vram_ok;
end


// Tile cache
jtframe_dual_ram #(.dw(16), .aw(9)) u_tile_cache(
    .clk0   ( clk           ),
    .clk1   ( clk           ),
    // Port 0: write
    .data0  ( tile_din      ),
    .addr0  ( { wr_bank, scr_cnt    } ),
    .we0    ( scr_wr        ),
    .q0     (               ),
    // Port 1: read
    .data1  ( ~16'd0        ),
    .addr1  ( { rd_bank, tile_addr  } ),
    .we1    ( 1'b0          ),
    .q1     ( tile_data     )
);

// OBJ table
jtframe_dual_ram #(.dw(16), .aw(11)) u_obj_cache(
    .clk0   ( clk           ),
    .clk1   ( clk           ),
    // Port 0: write
    .data0  ( obj_din       ),
    .addr0  ( { wr_obj_bank, obj_cnt } ),
    .we0    ( obj_wr        ),
    .q0     (               ),
    // Port 1: read
    .data1  ( ~16'd0        ),
    .addr1  ( { rd_obj_bank, obj_table_addr  } ),
    .we1    ( 1'b0          ),
    .q1     ( obj_table_data)
);

assign wr_pal_addr = { pal_wr_page, pal_cnt };

// Palette RAM (this was phisically outside of CPS-A/B chips)
jtframe_dual_ram #(.dw(16), .aw(12)) u_pal_ram(
    .clk0   ( clk           ),
    .clk1   ( clk           ),
    // Port 0: write
    .data0  ( pal_din       ),
    .addr0  ( wr_pal_addr   ),
    .we0    ( pal_wr        ),
    .q0     (               ),
    // Port 1: read
    .data1  ( ~16'd0        ),
    .addr1  ( colmix_addr   ),
    .we1    ( 1'b0          ),
    `ifndef FORCE_GRAY
    .q1     ( pal_data      )
    `endif
);

`ifdef FORCE_GRAY
assign pal_data = {4'hf, {3{colmix_addr[3:0]}} };
`endif

always @(*) begin
    if( cur_task[SCR1] ) begin
        scan   = { vn[8],   hn[8:3], vn[7:3] };
        hstep  = 11'd8;
    end else if( cur_task[SCR2] ) begin
        scan   = { vn[9:8], hn[9:4], vn[7:4] };
        hstep  = 11'd16;
    end else begin
        scan   = { vn[10:8], hn[10:5], vn[7:5] };
        hstep  = 11'd32;
    end
end

assign vram_cs        = br;
assign next_step_task = step_task<<1;
assign next_task      = step_task & tasks;

always @(posedge clk) begin
    vscr1 <= vpos1 + vrenderf;
    vscr2 <= vpos2 + vrenderf;
    vscr3 <= vpos3 + vrenderf;
end

`ifdef SIMULATION
wire on_scr1 = cur_task[SCR1];
wire on_scr2 = cur_task[SCR2];
wire on_scr3 = cur_task[SCR3];
wire on_row  = cur_task[ROW];
wire on_obj  = cur_task[OBJ];
wire on_pal  = |cur_task[PAL5:PAL0];
`endif

always @(posedge clk) begin
    if( rst ) begin
        tasks       <= {TASKW{1'b0}};
        cur_task    <= {TASKW{1'b0}};
        step_task   <= {TASKW{1'b0}};
        old_tasks   <= {TASKW{1'b0}};
        last_HB     <= 1;
        br          <= 0;
        adv         <= 0;
        check_adv   <= 0;
        step        <= 4'b1; // initial value is important
        line_req    <= 0;
        active      <= 3'b0;
        swap        <= 3'b0;
        last_obj_dma_ok <= 0;
        pal_cnt     <= 9'd0;
        misses      <= 5'd0;
        // banks
        rd_obj_bank <= 0;
        wr_obj_bank <= 1;
        scr_wr      <= 0;
        obj_wr      <= 0;
        pal_wr      <= 0;
        // OBJ
        obj_fill    <= 0;
        obj_end     <= 0;
        obj_cnt     <= 10'd0;
        obj_busy    <= 0;
        // SCR
        vrenderf    <= 16'd0;
    end else if(pxl2_cen) begin
        last_HB <= HB;
        last_obj_dma_ok <= obj_dma_ok;
        last_pal_dma_ok <= pal_dma_ok;


        if( obj_dma_ok && !last_obj_dma_ok ) begin
            obj_busy <= 1;
        end

        if( pal_dma_ok && !last_pal_dma_ok ) begin
            pal_busy <= 1;
        end

        if( HB_edge ) begin
            line_req <= 1;
            active   <= active ^ swap;
            swap     <= 3'd0;
            vrenderf <= {7'd0, (vrender1 ^ { 1'b0, {8{flip}}}) + (flip ? -9'd8 : 9'd1) };
            // It'd be better to use a vrender2 signal generated in the timing module
            // but adding 1 to vrender1 doesn't seem to create artifacts
            // note that adding 2 to vrender does create problems in the top horizontal line
        end

        if( line_req && step[0] ) begin
            line_req    <= 0;
            obj_busy    <= 0;
            pal_busy    <= 0;
            if( obj_busy ) begin
                wr_obj_bank <= ~wr_obj_bank;
                rd_obj_bank <= wr_obj_bank;
                obj_fill    <= 0;
                obj_end     <= 0;
            end
            if( pal_busy ) begin
                pal_rd_page      <= 3'd0;
                pal_wr_page      <= pal_page_en[0] ? 3'd0 : 3'd1;
                tasks[PAL5:PAL0] <= pal_page_en;
                pal_cnt          <= 9'd0;
            end
            tasks[OBJ]  <= obj_busy || (!obj_busy && !obj_end);
            tasks[ROW]  <= row_en & tile_ok;
            tasks[SCR1] <= vscr1[2:0]==3'd0 && tile_ok;
            tasks[SCR2] <=  vscr2[3:0]=={ flip, 3'd0 } && tile_ok;
            tasks[SCR3] <= (vscr3[3:0]=={ flip, 3'd0 } && tile_ok) || tile_vs;
            scr_cnt     <= 8'd0;
            check_adv   <= 1;
            row_scr     <= row_en ? row_scr_next : {12'b0, hpos2[3:0] };
            if( obj_busy ) obj_cnt <= 10'd0;
        end else
        if( check_adv ) begin
            cur_task  <= {TASKW{1'b0}};
            step_task <= { {TASKW-1{1'b0}}, 1'b1 };
            adv       <= |tasks[SCR3:0];
            check_adv <= 0;
            br        <= |tasks;
        end else
        if( bg && br ) begin
            if( adv ) begin
                step_task <= next_step_task;
                cur_task  <= next_task;
                if( ~|tasks )
                    br <= 0;
                else
                    step      <= 4'b1;
                adv <= ~|next_task;
                // Update SCR base pointer
                if( next_task[SCR1] ) begin
                    vn        <= vscr1[10:0];
                    hn        <= 11'h38 + { hpos1[10:3], 3'b0 };
                    scr_cnt   <= 8'd0;
                    scr_over  <= LAST_SCR1;
                    swap[0]   <= 1'b1;
                    vram_scr_base <= vram1_base[9:1];
                end
                if( next_task[SCR2] ) begin
                    vn        <= vscr2[10:0];
                    hn        <= 11'h30 + { hpos2[10:4], 4'b0 };
                    scr_cnt   <= 8'd128;
                    scr_over  <= LAST_SCR2;
                    swap[1]   <= 1'b1;
                    vram_scr_base <= vram2_base[9:1];
                end
                if( next_task[SCR3]) begin
                    vn        <= vscr3[10:0];
                    hn        <= 11'h20 + { hpos3[10:5], 5'b0 };
                    scr_cnt   <= LAST_SCR2+1;
                    scr_over  <= LAST_SCR3;
                    swap[2]   <= 1'b1;
                    vram_scr_base <= vram3_base[9:1];
                end
            end
            else begin
                if( step[2] && !vram_ok_dly ) begin
                    if( ~&misses ) misses <= misses + 5'd1;    // wait for SDRAM
                end else begin
                    if( step[1] && vram_ok_dly && misses>5'd0 ) begin
                        misses <= misses - 5'd1;
                        step <= 4'b1000; // skip one to recover a cycle
                    end else begin
                        step <= { step[2:0], step[3] }; // normal sequence
                    end
                end
                case( step ) // 250us to go through all four steps
                    4'd1: begin // request data
                        vram_addr <=  cur_task[ROW]       ? vrow_addr : (
                                     |cur_task[SCR3:SCR1] ? vscr_addr : (
                                      cur_task[OBJ]       ? vobj_addr :
                                      vpal_addr ));
                    end
                    default: if(vram_ok_dly) begin // collect data
                        scr_wr <= |cur_task[SCR3:SCR1];
                        obj_wr <= cur_task[OBJ] | obj_fill;
                        pal_wr <= |cur_task[PAL5:PAL0];
                        if( cur_task[ROW] )
                            row_scr_next <= {12'b0, hpos2[3:0] } + vram_data;
                        if( cur_task[OBJ] && obj_cnt[1:0]==2'b11 && vram_data[15:8]==8'hff ) begin
                            obj_fill <= 1;
                        end
                    end
                    4'd8: begin
                        scr_wr <= 0;
                        obj_wr <= 0;
                        pal_wr <= 0;
                        if( |cur_task[SCR3:SCR1] ) begin
                            if( scr_cnt==scr_over ) begin
                                adv     <= 1;
                                if( cur_task[SCR1] ) tasks[SCR1] <= 0;
                                if( cur_task[SCR2] ) tasks[SCR2] <= 0;
                                if( cur_task[SCR3] ) tasks[SCR3] <= 0;
                            end
                            else begin
                                scr_cnt <= scr_cnt+1;
                                if( scr_cnt[0] )
                                    hn <= hn + hstep;
                            end
                        end else
                        if( cur_task[ROW] ) begin
                            adv        <= 1;
                            tasks[ROW] <= 0;
                        end
                        if( cur_task[OBJ] || obj_fill ) begin
                            obj_cnt <= obj_cnt + 10'd1;
                            if( cur_task[OBJ] ) begin
                                adv <= (&obj_cnt[1:0]) | obj_fill;
                                if( &obj_cnt[1:0] ) tasks[OBJ]<=0;
                            end
                            if( &obj_cnt ) begin
                                obj_end  <= 1;
                                obj_fill <= 0;
                            end
                        end
                        if( |cur_task[PAL5:PAL0] ) begin
                            pal_cnt <= pal_cnt + 9'd1;
                            if( &pal_cnt ) begin
                                tasks[PAL5:PAL0] <= tasks[PAL5:PAL0] & ~cur_task[PAL5:PAL0];
                                adv <= 1;
                                // Update palette page
                                pal_wr_page <= pal_wr_page+3'd1;
                                pal_rd_page<=pal_rd_page+3'd1;
                            end
                        end
                    end
                endcase
            end
        end
    end
end

endmodule