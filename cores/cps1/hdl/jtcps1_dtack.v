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
    Date: 1-2-2021 */

module jtcps1_dtack(
    input       rst,
    input       clk,
    input       cen10,
    input       cen10b,

    input       ASn,
    input       one_wait,
    input       bus_cs,
    input       bus_busy,
    input       rom_ok,

    input       main2qs_cs, // set to zero for CPS1
    input       qs_busakn_s,

    output reg  DTACKn
);

reg       fail_cnt_ok, last_ASn;
reg [2:0] wait_cycles;
reg [3:0] fail_cnt;

always @(posedge clk, posedge rst) begin : dtack_gen
    if( rst ) begin
        DTACKn      <= 1'b1;
        wait_cycles <= 3'b111;
        fail_cnt    <= 4'd0;
        fail_cnt_ok <= 0;
    end else begin
        if( rom_ok ) fail_cnt_ok <= 1;
        last_ASn <= ASn;
        if( (!ASn && last_ASn) || ASn
            || (main2qs_cs && qs_busakn_s) // wait for Z80 bus grant
        ) begin // for falling edge of ASn
            DTACKn <= 1'b1;
            wait_cycles <= {2'b0, ~one_wait};
        end else if( !ASn  ) begin
            if( cen10b ) begin
                wait_cycles[2] <= 1'b1;
                wait_cycles[1] <= wait_cycles[2];
            end
            if( wait_cycles[1] ) wait_cycles[0] <= 1;
            if( bus_cs ) begin
                // we avoid accumulating delay by counting it
                // and skipping wait cycles when necessary
                // the resolution of this compensation is one CPU clock
                // Recovery is done by shortening the normal bus wait
                // by one cycle
                // Average delay can be displayed in simulation by defining the
                // macro REPORT_DELAY
                if( wait_cycles[1] && bus_busy && fail_cnt_ok && cen10 && (~|fail_cnt) ) fail_cnt<=fail_cnt+1'd1;
                if (!bus_busy && (wait_cycles[1] || (fail_cnt!=4'd0&&wait_cycles==3'b100) ) ) begin
                    DTACKn <= 1'b0;
                    if( wait_cycles[1:0]==2'd0 && fail_cnt_ok) fail_cnt<=fail_cnt-1'd1; // one bus cycle recovered
                end
            end
            else DTACKn <= 1'b0;
        end
    end
end

`ifdef REPORT_DELAY
// Note that the data for the first frame may be wrong because
// of SDRAM initialization
real dly_cnt, ticks;
always @(posedge clk) begin
    if( !LVBL && last_LVBL ) begin
        ticks <= 0;
        dly_cnt <= 0;
        if( ticks ) $display("INFO: average CPU delay = %.2f CPU clock ticks",dly_cnt/ticks);
    end else begin
        dly_cnt <= dly_cnt+fail_cnt;
        ticks <= ticks+1;
    end
end
`endif

endmodule