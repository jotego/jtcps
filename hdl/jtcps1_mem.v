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
`timescale 1ns/1ps

module jtcps1_mem(
    input              rst,
    input              clk,
    // RAM access
    input              ram_cs,
    input       [15:1] ram_addr,
    output      [15:0] ram_data,
    output             ram_ok,
    // Video RAM access
    input              vram_cs,
    input       [23:1] vram_addr,
    output      [15:0] vram_data,
    output             vram_ok,    
    // ROM access
    input              main_cs,
    input       [23:1] main_addr,
    output      [15:0] main_data,
    output             main_ok,
);

endmodule