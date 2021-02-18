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
    Date: 18-1-2021 */

module jtcps2_dec_ctrl(
    input      [ 2:0] fc,
    input             en,
    input      [15:0] din,
    input      [15:0] dec,
    output reg [15:0] dout
);

wire op_fetch = fc[1:0]==2'b10;

always @(*) begin
    dout = (op_fetch && en) ? dec : din;
end

endmodule