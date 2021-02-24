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
    Date: 28-1-2021 */

// Two line counters plus one pixel counter

module jtcps2_raster(
    input              rst,
    input              clk,
    input              pxl_cen,

    input              frame_start,
    input              line_inc,

    // interface with CPU
    input       [ 2:0] cnt_sel,
    input              wrn,
    input       [15:0] cpu_dout,
    output reg  [ 8:0] cnt_dout,

    output reg         raster       // raster event
);

wire [8:0] dout0, dout1, dout2, din;
wire [2:0] we, zero;
wire       lock;
wire       step;
reg        cnt4; // 4MHz
wire       cen4;
reg        restart;
wire       set_irq = zero[2] & (|zero[1:0]);
reg        irqsh;

assign cen4  = pxl_cen & cnt4;
assign lock  = cpu_dout[15];
assign din   = cpu_dout[8:0];
assign we    = {3{~wrn}} & cnt_sel;

assign step    = pxl_cen && line_inc;

always @(posedge clk) begin
    cnt_dout <= cnt_sel[0] ? dout0 : (cnt_sel[1] ? dout1 : dout2);
    if( pxl_cen ) begin
        cnt4    <= ~cnt4;
        restart <= frame_start; // one pxl_cen delay, so the counter produces
                                // a pulse at the "zero" output
    end
    // interrupt pulse lasts at least one pixel, so the CPU clock can
    // catch it
    if( set_irq )
        { raster, irqsh } <= 2'b11;
    else if( pxl_cen ) begin
        { raster, irqsh } <= { irqsh, 1'b0 };
    end
end

initial begin
    cnt4 <= 0;
end

jtcps2_raster_cnt u_cnt0(
    .rst    ( rst       ),
    .clk    ( clk       ),
    .cen4   ( cen4      ),

    .restart( restart   ),
    .step   ( step      ),

    .we     ( we[0]     ),
    .lock   ( lock      ),
    .din    ( din       ),
    .dout   ( dout0     ),

    .zero   ( zero[0]   )
);

jtcps2_raster_cnt u_cnt1(
    .rst    ( rst       ),
    .clk    ( clk       ),
    .cen4   ( cen4      ),

    .restart( restart   ),
    .step   ( step      ),

    .we     ( we[1]     ),
    .lock   ( lock      ),
    .din    ( din       ),
    .dout   ( dout1     ),

    .zero   ( zero[1]   )
);

// Pixel counter
jtcps2_raster_pxlcnt u_cnt2(
    .rst    ( rst       ),
    .clk    ( clk       ),
    .pxl_cen( pxl_cen   ),
    .cen4   ( cen4      ),

    .restart( step      ), // Line start

    .we     ( we[2]     ),
    .din    ( din       ),
    .dout   ( dout2     ),

    .zero   ( zero[2]   )
);
endmodule

module jtcps2_raster_cnt(
    input              rst,
    input              clk,
    input              cen4,

    input              restart,
    input              step,

    input              we,
    input              lock,
    input       [ 8:0] din,
    output reg  [ 8:0] dout,

    output reg         zero       // raster event
);

reg  [8:0] cnt_start, cnt;
reg        locked;

always @(posedge clk, posedge rst) begin
    if( rst ) begin
        cnt       <= ~9'd0;
        cnt_start <= ~9'd0;
        dout      <= ~9'd0;
        locked    <= 0;
        zero      <= 0;
    end else begin
        zero <= ~|cnt;
        if(cen4) dout <= locked ? cnt : cnt_start;
        if( we ) begin
            cnt_start <= din;
            locked    <= lock;
        end
        // counter
        if( we )
            cnt <= din;
        else if( restart || locked )
            cnt <= cnt_start;
        else if( step )
            cnt <= cnt-9'd1;
    end
end

endmodule

module jtcps2_raster_pxlcnt(
    input              rst,
    input              clk,
    input              pxl_cen,
    input              cen4,

    input              restart,

    input              we,
    input       [ 8:0] din,
    output      [ 8:0] dout,

    output reg         zero       // raster event
);

reg  [8:0] cnt_start;
reg  [7:0] cnt, preout;
reg        pulse4;
//wire       cen4b;

//assign cen4b = pxl_cen & ~cen4;
assign dout  = { preout, cnt_start[0] ^ ~pulse4 };

always @(posedge clk, posedge rst) begin
    if( rst ) begin
        cnt       <= ~8'd0;
        cnt_start <= ~9'd0;
        preout    <= ~8'd0;
        pulse4    <= 0;
    end else begin
        if( pxl_cen ) pulse4 <= cen4; // pulse4 must be deterministic
                                      // and independent of reset for dout[0]
                                      // to work as expected
        if( cen4 ) preout <= cnt;
        zero <= ~|cnt;

        if( we ) begin
            cnt_start <= din;
        end
        if( restart )
            cnt <= cnt_start[8:1];
        else if( cen4 )
            cnt <= cnt-8'd1;
    end
end

endmodule