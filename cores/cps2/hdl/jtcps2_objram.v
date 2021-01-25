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
    output   [15:0] obj_x,
    output   [15:0] obj_y,
    output   [15:0] obj_attr,
    output   [15:0] obj_code
);

parameter AW=13; // 13 for full table shadowing

wire [   1:0] wex, wey, wecode, weattr;
wire [AW-3:0] wr_addr;
wire [AW-4:0] gfx_addr;

assign wex       = ~dsn & {2{cs & main_addr[2:1]==2'd0}};
assign wey       = ~dsn & {2{cs & main_addr[2:1]==2'd1}};
assign wecode    = ~dsn & {2{cs & main_addr[2:1]==2'd2}};
assign weattr    = ~dsn & {2{cs & main_addr[2:1]==2'd3}};

assign wr_addr  = {  obank^main_addr[13], main_addr[AW-1:3] };
assign gfx_addr = { ~obank, obj_addr[AW-4:0] };

always @(posedge clk_cpu) begin
    ok <= cs;
end

jtframe_dual_ram16 #(
    .aw(AW-2),.simfile_lo("objx_lo.bin"), .simfile_hi("objx_hi.bin")
) u_x(
    .clk0       ( clk_cpu      ),
    .clk1       ( clk_gfx      ),
    // Port 0: CPU
    .data0      ( main_dout    ),
    .addr0      ( wr_addr      ),
    .we0        ( wex          ),
    .q0         (              ),
    // Port 1: GFX
    .data1      ( 16'd0        ),
    .addr1      ( gfx_addr     ),
    .we1        ( 2'b0         ),
    .q1         ( obj_x        )
);

jtframe_dual_ram16 #(
    .aw(AW-2),.simfile_lo("objy_lo.bin"), .simfile_hi("objy_hi.bin")
) u_y(
    .clk0       ( clk_cpu      ),
    .clk1       ( clk_gfx      ),
    // Port 0: CPU
    .data0      ( main_dout    ),
    .addr0      ( wr_addr      ),
    .we0        ( wey          ),
    .q0         (              ),
    // Port 1: GFX
    .data1      ( 16'd0        ),
    .addr1      ( gfx_addr     ),
    .we1        ( 2'b0         ),
    .q1         ( obj_y        )
);

jtframe_dual_ram16 #(
    .aw(AW-2),.simfile_lo("objattr_lo.bin"), .simfile_hi("objattr_hi.bin")
) u_attr(
    .clk0       ( clk_cpu      ),
    .clk1       ( clk_gfx      ),
    // Port 0: CPU
    .data0      ( main_dout    ),
    .addr0      ( wr_addr      ),
    .we0        ( weattr       ),
    .q0         (              ),
    // Port 1: GFX
    .data1      ( 16'd0        ),
    .addr1      ( gfx_addr     ),
    .we1        ( 2'b0         ),
    .q1         ( obj_attr     )
);

jtframe_dual_ram16 #(
    .aw(AW-2),.simfile_lo("objcode_lo.bin"), .simfile_hi("objcode_hi.bin")
) u_code(
    .clk0       ( clk_cpu      ),
    .clk1       ( clk_gfx      ),
    // Port 0: CPU
    .data0      ( main_dout    ),
    .addr0      ( wr_addr      ),
    .we0        ( wecode       ),
    .q0         (              ),
    // Port 1: GFX
    .data1      ( 16'd0        ),
    .addr1      ( gfx_addr     ),
    .we1        ( 2'b0         ),
    .q1         ( obj_code     )
);

endmodule
