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

// Original order
// 0  X
// 1  Y
// 2  code
// 3  attr
// Y is read with attr
// X is read with code

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
    input    [13:1] main_addr,
    // output   [15:0] dout2cpu,

    // Interface with OBJ engine
    input    [10:0] obj_addr, // 11 bits because bank is automatic
                              // and 32-bits are read together
    output   [15:0] obj_xy,
    output   [15:0] obj_attr
);

parameter AW=13; // 13 for full table shadowing

wire [   1:0] wexy, weattr;
wire [AW-2:0] wr_addr, gfx_addr;

assign wexy[0]   = ~dsn[0] & cs & ~main_addr[2];
assign wexy[1]   = ~dsn[1] & cs & ~main_addr[2];
assign weattr[0] = ~dsn[0] & cs &  main_addr[2];
assign weattr[1] = ~dsn[1] & cs &  main_addr[2];

assign wr_addr  = {  obank^main_addr[13], main_addr[AW-1:3], main_addr[1] };
assign gfx_addr = { ~obank, obj_addr[AW-3:0] };

always @(posedge clk_cpu) begin
    ok <= cs;
end

// Y and X

jtframe_dual_ram #(.dw(8),.aw(AW-1),.simfile("objxy_lo.bin")) u_xy_lo(
    .clk0       ( clk_cpu           ),
    .clk1       ( clk_gfx           ),
    // Port 0: CPU
    .data0      ( main_dout[7:0]    ),
    .addr0      ( wr_addr           ),
    .we0        ( wexy[0]           ),
    .q0         (                   ),
    // Port 1: GFX
    .data1      ( 8'd0              ),
    .addr1      ( gfx_addr          ),
    .we1        ( 1'b0              ),
    .q1         ( obj_xy[7:0]       )
);

jtframe_dual_ram #(.dw(8),.aw(AW-1),.simfile("objxy_hi.bin")) u_xy_hi(
    .clk0       ( clk_cpu           ),
    .clk1       ( clk_gfx           ),
    // Port 0: CPU
    .data0      ( main_dout[15:8]   ),
    .addr0      ( wr_addr           ),
    .we0        ( wexy[1]           ),
    .q0         (                   ),
    // Port 1: GFX
    .data1      ( 8'd0              ),
    .addr1      ( gfx_addr          ),
    .we1        ( 1'b0              ),
    .q1         ( obj_xy[15:8]      )
);

// attr and code

jtframe_dual_ram #(.dw(8),.aw(AW-1),.simfile("objattr_lo.bin")) u_attr_lo(
    .clk0       ( clk_cpu           ),
    .clk1       ( clk_gfx           ),
    // Port 0: CPU
    .data0      ( main_dout[7:0]    ),
    .addr0      ( wr_addr           ),
    .we0        ( weattr[0]         ),
    .q0         (                   ),
    // Port 1: GFX
    .data1      ( 8'd0              ),
    .addr1      ( gfx_addr          ),
    .we1        ( 1'b0              ),
    .q1         ( obj_attr[7:0]     )
);

jtframe_dual_ram #(.dw(8),.aw(AW-1),.simfile("objattr_hi.bin")) u_attr_hi(
    .clk0       ( clk_cpu           ),
    .clk1       ( clk_gfx           ),
    // Port 0: CPU
    .data0      ( main_dout[15:8]   ),
    .addr0      ( wr_addr           ),
    .we0        ( weattr[1]         ),
    .q0         (                   ),
    // Port 1: GFX
    .data1      ( 8'd0              ),
    .addr1      ( gfx_addr          ),
    .we1        ( 1'b0              ),
    .q1         ( obj_attr[15:8]    )
);

endmodule
