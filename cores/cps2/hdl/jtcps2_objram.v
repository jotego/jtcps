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
    Date: 5-12-2020 */

module jtcps2_objram(
    input           rst,
    input           clk_cpu,
    input           clk_gfx,

    input           obank,

    // Interface with CPU
    input           cs,
    output reg      ok,
    input    [ 1:0] dsn,
    input    [15:0] main_dout,
    input           main_rnw,
    input    [12:0] main_addr,
    output   [15:0] dout2cpu,

    // Interface with OBJ engine
    input    [11:0] obj_addr,
    output   [15:0] dout2gfx
);

wire [ 1:0] we;
wire [12:0] cpu_addr, gfx_addr;

assign we[0] = ~dsn[0] & cs;
assign we[1] = ~dsn[1] & cs;

assign cpu_addr = {  obank^main_addr[12], main_addr[11:0] };
assign gfx_addr = { ~obank, obj_addr        };

always @(posedge clk) begin
    ok <= cs;
end

jtframe_dual_ram #(.dw(8),.aw(13)) u_low(
    .clk0       ( clk_cpu           ),
    .clk1       ( clk               ),
    // Port 0: CPU
    .data0      ( main_dout[7:0]    ),
    .addr0      ( cpu_addr          ),
    .we0        ( we[0]             ),
    .q0         ( dout2cpu[7:0]     ),
    // Port 1: GFX
    .data1      ( 8'd0              ),
    .addr1      ( gfx_addr          ),
    .we1        ( 1'b0              ),
    .q1         ( dout2gfx[7:0]     )
);

jtframe_dual_ram #(.dw(8),.aw(13)) u_high(
    .clk0       ( clk_cpu           ),
    .clk1       ( clk               ),
    // Port 0: CPU
    .data0      ( main_dout[15:8]   ),
    .addr0      ( cpu_addr          ),
    .we0        ( we[1]             ),
    .q0         ( dout2cpu[15:8]    ),
    // Port 1: GFX
    .data1      ( 8'd0              ),
    .addr1      ( gfx_addr          ),
    .we1        ( 1'b0              ),
    .q1         ( dout2gfx[15:8]    )
);

endmodule
