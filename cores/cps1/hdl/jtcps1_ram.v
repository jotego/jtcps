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
    Date: 19-12-2020 */

module jtcps1_ram(
    input           rst,
    input           clk_gfx,    // 96   MHz
    input           clk_cpu,    // 48   MHz

    // VRAM
    input           vram_dma_cs,
    input           main_ram_cs,
    input           main_vram_cs,

    input    [ 1:0] dsn,
    input    [15:0] main_dout,
    input           main_rnw,

    output reg      main_ram_ok,
    output reg      vram_dma_ok,

    input    [16:0] main_ram_addr,
    input    [16:0] vram_dma_addr,

    output reg [15:0] main_ram_data,
    output reg [15:0] vram_dma_data
);

wire [ 7:0] din_lo, din_hi;

reg  [14:0] ram_addr, vram_addr0, vram_addr1, vram_addr2,
            dma_addr0, dma_addr1, dma_addr2;
reg  [ 7:0] ram_in_lo, ram_in_hi,
            vram_din_lo0, vram_din_lo1, vram_din_lo2,
            vram_din_hi0, vram_din_hi1, vram_din_hi2;

wire [ 7:0] vram_hi_dout0, vram_hi_dout1, vram_hi_dout2,
            vram_lo_dout0, vram_lo_dout1, vram_lo_dout2,
            dma_hi_dout0,  dma_hi_dout1,  dma_hi_dout2,
            dma_lo_dout0,  dma_lo_dout1,  dma_lo_dout2,
            ram_hi_dout, ram_lo_dout;

reg         ram_lo_we,   ram_hi_we,
            vram_lo_we0, vram_hi_we0,
            vram_lo_we1, vram_hi_we1,
            vram_lo_we2, vram_hi_we2;
reg  [ 2:0] vram_sel, dma_sel;
reg  [ 1:0] ram_sh, dma_sh;
reg         main_edge, main_last;

assign din_lo = main_dout[7:0];
assign din_hi = main_dout[15:8];

always @(*) begin
    vram_sel = 3'd0;
    vram_sel[ main_ram_addr[16:15] ] <= main_vram_cs;

    dma_sel = 3'd0;
    dma_sel[ vram_dma_addr[16:15] ] <= vram_dma_cs;

    main_edge = (main_ram_cs || main_vram_cs) && !main_last;
end


// CPU side memory
always @(posedge clk_cpu, posedge rst) begin
    if( rst ) begin
        main_ram_ok <= 0;
        ram_sh <= 2'd0;
        main_ram_data <= 16'hffff;
    end else begin
        main_last <= main_ram_cs || main_vram_cs;
        ram_sh <= ram_sh >> 1;
        if( main_edge ) begin
            ram_addr   <= main_ram_addr[14:0];
            vram_addr0 <= main_ram_addr[14:0];
            vram_addr1 <= main_ram_addr[14:0];
            vram_addr2 <= main_ram_addr[14:0];

            ram_in_hi    <= din_hi;
            ram_in_lo    <= din_lo;
            vram_din_lo0 <= din_lo;
            vram_din_lo1 <= din_lo;
            vram_din_lo2 <= din_lo;
            vram_din_hi0 <= din_hi;
            vram_din_hi1 <= din_hi;
            vram_din_hi2 <= din_hi;

            ram_lo_we <= main_ram_cs & ~main_rnw & ~dsn[0];
            ram_hi_we <= main_ram_cs & ~main_rnw & ~dsn[1];

            vram_lo_we0 <= vram_sel[0] & ~main_rnw & ~dsn[0];
            vram_hi_we0 <= vram_sel[0] & ~main_rnw & ~dsn[1];

            vram_lo_we1 <= vram_sel[1] & ~main_rnw & ~dsn[0];
            vram_hi_we1 <= vram_sel[1] & ~main_rnw & ~dsn[1];

            vram_lo_we2 <= vram_sel[2] & ~main_rnw & ~dsn[0];
            vram_hi_we2 <= vram_sel[2] & ~main_rnw & ~dsn[1];

            ram_sh[1] <= 1;
            main_ram_ok <= 0;
        end else begin
            ram_hi_we   <= 0;
            ram_lo_we   <= 0;

            vram_lo_we0 <= 0;
            vram_lo_we1 <= 0;
            vram_lo_we2 <= 0;

            vram_hi_we0 <= 0;
            vram_hi_we1 <= 0;
            vram_hi_we2 <= 0;
        end
        if( ram_sh[0] ) begin
            main_ram_ok <= 1;
            if( main_ram_cs )
                main_ram_data <= {ram_hi_dout, ram_lo_dout};
            else if( vram_sel[0] )
                main_ram_data <= {vram_hi_dout0, vram_lo_dout0};
            else if( vram_sel[1] )
                main_ram_data <= {vram_hi_dout1, vram_lo_dout1};
            else if( vram_sel[2] )
                main_ram_data <= {vram_hi_dout2, vram_lo_dout2};
        end
    end
end

// DMA access
// This is different from the CPU because vram_dma_cs is not a strobe
// but a level signal
always @(posedge clk_gfx, posedge rst) begin
    if( rst ) begin
        vram_dma_ok <= 0;
        dma_sh <= 2'b11;
        vram_dma_data <= 16'hffff;
    end else begin
        dma_sh <= dma_sh >> 1;
        if( vram_dma_cs ) begin
            dma_addr0 <= vram_dma_addr[14:0];
            dma_addr1 <= vram_dma_addr[14:0];
            dma_addr2 <= vram_dma_addr[14:0];
            if( dma_addr0 != vram_dma_addr[14:0] ) begin
                dma_sh[1] <= 1;
                vram_dma_ok <= 0;
            end
        end
        if( dma_sh[0] ) begin
            vram_dma_ok <= 1;
            if( dma_sel[0] )
                vram_dma_data <= { dma_hi_dout0, dma_lo_dout0 };
            else if( dma_sel[1] )
                vram_dma_data <= { dma_hi_dout1, dma_lo_dout1 };
            else if( dma_sel[2] )
                vram_dma_data <= { dma_hi_dout2, dma_lo_dout2 };
        end
    end
end

// 32kB only for CPU access
jtframe_ram #(.aw(15),.dw(8)) u_ram_lo(
    .clk    ( clk_cpu             ),
    .cen    ( 1'b1                ),
    .addr   ( ram_addr            ),
    .data   ( din_lo              ),
    .we     ( ram_lo_we           ),
    .q      ( ram_lo_dout         )
);

jtframe_ram #(.aw(15),.dw(8)) u_ram_hi(
    .clk    ( clk_cpu             ),
    .cen    ( 1'b1                ),
    .addr   ( ram_addr            ),
    .data   ( din_hi              ),
    .we     ( ram_hi_we           ),
    .q      ( ram_hi_dout         )
);

// 192 kB shared with GFX chips
jtframe_dual_ram #(.aw(15),.dw(8)) u_vram0_lo(
    .clk0   ( clk_cpu             ),
    .clk1   ( clk_gfx             ),
    // CPU side
    .addr0  ( vram_addr0          ),
    .data0  ( vram_din_lo0        ),
    .we0    ( vram_lo_we0         ),
    .q0     ( vram_lo_dout0       ),
    // GFX side
    .addr1  ( dma_addr0           ),
    .data1  ( 8'd0                ),
    .we1    ( 1'b0                ),
    .q1     ( dma_lo_dout0        )
);

jtframe_dual_ram #(.aw(15),.dw(8)) u_vram1_lo(
    .clk0   ( clk_cpu             ),
    .clk1   ( clk_gfx             ),
    // CPU side
    .addr0  ( vram_addr1          ),
    .data0  ( vram_din_lo1        ),
    .we0    ( vram_lo_we1         ),
    .q0     ( vram_lo_dout1       ),
    // GFX side
    .addr1  ( dma_addr1           ),
    .data1  ( 8'd0                ),
    .we1    ( 1'b0                ),
    .q1     ( dma_lo_dout1        )
);

jtframe_dual_ram #(.aw(15),.dw(8)) u_vram2_lo(
    .clk0   ( clk_cpu             ),
    .clk1   ( clk_gfx             ),
    // CPU side
    .addr0  ( vram_addr2          ),
    .data0  ( vram_din_lo2        ),
    .we0    ( vram_lo_we2         ),
    .q0     ( vram_lo_dout2       ),
    // GFX side
    .addr1  ( dma_addr2           ),
    .data1  ( 8'd0                ),
    .we1    ( 1'b0                ),
    .q1     ( dma_lo_dout2        )
);

jtframe_dual_ram #(.aw(15),.dw(8)) u_vram0_hi(
    .clk0   ( clk_cpu             ),
    .clk1   ( clk_gfx             ),
    // CPU side
    .addr0  ( vram_addr0          ),
    .data0  ( vram_din_hi0        ),
    .we0    ( vram_hi_we0         ),
    .q0     ( vram_hi_dout0       ),
    // GFX side
    .addr1  ( dma_addr0           ),
    .data1  ( 8'd0                ),
    .we1    ( 1'b0                ),
    .q1     ( dma_hi_dout0        )
);

jtframe_dual_ram #(.aw(15),.dw(8)) u_vram1_hi(
    .clk0   ( clk_cpu             ),
    .clk1   ( clk_gfx             ),
    // CPU side
    .addr0  ( vram_addr1          ),
    .data0  ( vram_din_hi1        ),
    .we0    ( vram_hi_we1         ),
    .q0     ( vram_hi_dout1       ),
    // GFX side
    .addr1  ( dma_addr1           ),
    .data1  ( 8'd0                ),
    .we1    ( 1'b0                ),
    .q1     ( dma_hi_dout1        )
);

jtframe_dual_ram #(.aw(15),.dw(8)) u_vram2_hi(
    .clk0   ( clk_cpu             ),
    .clk1   ( clk_gfx             ),
    // CPU side
    .addr0  ( vram_addr2          ),
    .data0  ( vram_din_hi2        ),
    .we0    ( vram_hi_we2         ),
    .q0     ( vram_hi_dout2       ),
    // GFX side
    .addr1  ( dma_addr2           ),
    .data1  ( 8'd0                ),
    .we1    ( 1'b0                ),
    .q1     ( dma_hi_dout2        )
);

endmodule