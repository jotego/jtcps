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
    Date: 30-1-2020 */

`timescale 1ns/1ps

module jtcps1_prom_we(
    input                clk,
    input                downloading,
    input      [22:0]    ioctl_addr,
    input      [ 7:0]    ioctl_data,
    input                ioctl_wr,
    (*keep*) output reg [21:0]    prog_addr,
    (*keep*) output reg [ 7:0]    prog_data,
    (*keep*) output reg [ 1:0]    prog_mask, // active low
    (*keep*) output reg           prog_we
);

always @(posedge clk) begin
    if ( ioctl_wr && downloading ) begin
        prog_we   <= 1'b1;
        prog_data <= ioctl_data;
        prog_addr <= ioctl_addr[22:1];
        prog_mask <= !ioctl_addr[0] ? 2'b10 : 2'b01;            
    end
    else begin
        prog_we  <= 1'b0;
    end
end

endmodule