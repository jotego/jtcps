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
    Date: 28-1-2020 */

module jtcps1_sound(
    input           rst,
    input           clk,    
    input           cen_fm,
    input           cen_fm2,

    // Interface with main CPU
    input   [7:0]   snd_latch0,
    input   [7:0]   snd_latch1,

    // ROM
    output  reg [15:0]  rom_addr,
    output  reg         rom_cs,
    input       [ 7:0]  rom_data,
    input               rom_ok,

    // Sound output
    output  signed [15:0] left,
    output  signed [15:0] right,
    output                sample
);

(*keep*) wire [15:0] A;
reg  fm_cs, latch0_cs, latch1_cs, ram_cs, oki_cs, oki7_cs, bank_cs;
wire mreq_n, rfsh_n, int_n;
wire WRn;

reg  bank;

always @(*) begin
    rom_cs   = 1'b0;
    ram_cs   = 1'b0;
    latch0_cs= 1'b0;
    latch1_cs= 1'b0;
    fm_cs    = 1'b0;
    bank_cs  = 1'b0;
    oki_cs   = 1'b0;
    oki7_cs  = 1'b0;
    rom_addr = 16'h0000;
    if(!mreq_n) casez( A[15:12] )
        4'b0???: begin
            rom_cs = 1'b1;
            rom_addr = { 1'b0, A[14:0] };
        end
        4'b10??: begin
            rom_cs   = 1'b1;
            rom_addr = { 1'b1, bank, A[13:0] };
        end
        4'b1101: ram_cs   = 1'b1; // D
        4'b1111: begin // F
            case(A[3:1])
                3'd0: fm_cs     = 1'b1;
                3'd1: oki_cs    = 1'b1;
                3'd2: bank_cs   = 1'b1;
                3'd3: oki7_cs   = 1'b1;
                3'd4: latch0_cs = 1'b1;
                3'd5: latch1_cs = 1'b1;
            endcase
        end
    endcase
end

wire rd_n;
wire wr_n;

wire RAM_we = ram_cs && !WRn;
wire [7:0] ram_dout, dout, fm_dout;

assign WRn = wr_n | mreq_n;

always @(posedge clk, posedge rst) begin
    if(rst) begin
        bank=1'b0;
    end else if(bank_cs) bank <= dout[0];
end

jtframe_ram #(.aw(11)) u_ram(
    .clk    ( clk      ),
    .cen    ( 1'b1     ),
    .data   ( dout     ),
    .addr   ( A[10:0]  ),
    .we     ( RAM_we   ),
    .q      ( ram_dout )
);

reg [7:0] din;

always @(*)
    case( 1'b1 )
        fm_cs:     din = fm_dout;
        latch0_cs: din = snd_latch0;
        latch1_cs: din = snd_latch1;
        ram_cs:    din = ram_dout;
        rom_cs:    din = rom_data;
        default:   din = 8'hff;
    endcase

wire iorq_n, m1_n;
(*keep*) wire irq_ack = !iorq_n && !m1_n;

jtframe_z80_wait u_cpu(
    .rst_n      ( ~rst        ),
    .clk        ( clk         ),
    .cen        ( cen_fm      ),
    .int_n      ( int_n       ),
    .nmi_n      ( 1'b1        ),
    .busrq_n    ( 1'b1        ),
    .m1_n       ( m1_n        ),
    .mreq_n     ( mreq_n      ),
    .iorq_n     ( iorq_n      ),
    .rd_n       ( rd_n        ),
    .wr_n       ( wr_n        ),
    .rfsh_n     ( rfsh_n      ),
    .halt_n     (             ),
    .busak_n    (             ),
    .A          ( A           ),
    .din        ( din         ),
    .dout       ( dout        ),
    // manage access to ROM data from SDRAM
    .rom_cs     ( rom_cs      ),
    .rom_ok     ( rom_ok      )
);

jt51 u_jt51(
    .rst        ( rst       ), // reset
    .clk        ( clk       ), // main clock
    .cen        ( cen_fm    ),
    .cen_p1     ( cen_fm2   ),
    .cs_n       ( !fm_cs    ), // chip select
    .wr_n       ( WRn       ), // write
    .a0         ( A[0]      ),
    .din        ( dout      ), // data in
    .dout       ( fm_dout   ), // data out
    .ct1        (           ),
    .ct2        (           ),
    .irq_n      ( int_n     ),  // I do not synchronize this signal
    // Low resolution output (same as real chip)
    .sample     ( sample    ), // marks new output sample
    .left       (           ),
    .right      (           ),
    // Full resolution output
    .xleft      ( left      ),
    .xright     ( right     ),
    // unsigned outputs for sigma delta converters, full resolution
    .dacleft    (           ),
    .dacright   (           )
);

endmodule