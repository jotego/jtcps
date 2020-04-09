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

// PCB measurements show that palette is read at 4MHz. There are 3072+60 cycles
// It takes 783us to copy the full palette in the SF2 CE PCB.
// This module takes 768.5us because the ammount of extra cycles is different.
// The extra 60 cycles may be needed by the original DMA state machine
// It doesn't seem that the extra 60 cycles (15us) are due to other DMA operations
// because the numbers don't add up.
// For now, I don't do anything about those 15us because I still don't understand
// where they come from
    
`timescale 1ns/1ps

module jtcps1_colram(
    input              rst,
    input              clk,
    input              pxl_cen,

    input              HB,
    input              VB,

    // Palette PPU control
    input              pal_copy,
    input   [15:0]     pal_base,
    input   [ 5:0]     pal_page_en, // which palette pages to copy

    // Palette data requests
    input       [11:0] pal_addr,
    output reg  [15:0] pal_data,

    // BUS sharing
    output reg         busreq,
    input              busack,

    // VRAM access
    output reg [17:1]  vram_addr,
    input      [15:0]  vram_data,
    input              vram_ok
);

reg [15:0] pal[0:(2**12)-1]; // 4096?


// Palette copy
reg [8:0] pal_cnt;
reg [2:0] st;
reg [2:0] rdpage, wrpage;
reg [5:0] pal_en;
//reg       pal_fist;

reg       last_HB;
wire      hb_edge = HB && !last_HB;

always @(posedge clk) if(pxl_cen) last_HB <= HB;

always @(posedge clk, posedge rst) begin
    if( rst ) begin
        pal_data  <= 16'h0;
        pal_cnt   <= 9'd0;
        st    <= 0;
        vram_addr <= 23'd0;
        busreq    <= 1'b0;
    end else begin
        pal_data <= pal[pal_addr];
        `ifdef FORCE_GRAY
        pal_data <= {4'hf, {3{pal_addr[3:0]}} }; // uses palette index as gray colour
        `endif        
        case( st )
            0: begin
                if( pal_copy ) begin
                    rdpage    <= 3'd0;
                    pal_en    <= pal_page_en;
                    wrpage    <= 3'd0;
                    busreq    <= 1;
                    st    <= 4;
                end
            end
            1: begin
                if( wrpage >= 3'd6 ) begin
                    busreq  <= 1'b0;
                    st  <= 0; // done
                end else begin
                    pal_en <= pal_en>>1;
                    if( !pal_en[0] ) begin
                        if( rdpage!=3'd0 ) rdpage <= rdpage + 3'd1;
                        wrpage <= wrpage + 3'd1;
                    end else begin
                        pal_cnt   <= 9'd0;
                        vram_addr <= { pal_base[9:1], 8'd0 } + { rdpage , 9'd0 };
                        st <= 2;
                    end
                end
            end
            2: if( pxl_cen ) st <= 3; // wait state
            3: if( pxl_cen && vram_ok) begin
                pal[ {wrpage , pal_cnt } ] <= vram_data;
                pal_cnt <= pal_cnt + 9'd1;
                if( &pal_cnt ) begin
                    rdpage <= rdpage + 3'd1;
                    wrpage <= wrpage + 3'd1;
                    st <= 1;
                end
                else begin
                    vram_addr[9:1] <= vram_addr[9:1] + 9'd1;
                    st <= 2;
                end
            end
            4: if( busack && pxl_cen ) st <= 1;
        endcase
    end
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

endmodule