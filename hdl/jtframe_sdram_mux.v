/*  This file is part of JTFRAME.
    JTFRAME program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    JTFRAME program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with JTFRAME.  If not, see <http://www.gnu.org/licenses/>.

    Author: Jose Tejada Gomez. Twitter: @topapate
    Version: 1.0
    Date: 6-12-2019 */

`timescale 1ns/1ps

// 10 slots for SDRAM access
// slot 0 --> maximum priority
// slot 9 --> minimum priority
// Each slot can be used for 8, 16 or 32 bit access
// Small 4 byte cache used for each slot. Cache can be turned off at synthesis time
// Three types of slots:
// 0 = read only    ( default )
// 1 = write only
// 2 = R/W

module jtframe_sdram_mux #(parameter
    SLOT0_DW = 8, SLOT1_DW = 8, SLOT2_DW = 8, SLOT3_DW = 8, SLOT4_DW = 8,
    SLOT5_DW = 8, SLOT6_DW = 8, SLOT7_DW = 8, SLOT8_DW = 8, SLOT9_DW = 8,

    SLOT0_AW = 8, SLOT1_AW = 8, SLOT2_AW = 8, SLOT3_AW = 8, SLOT4_AW = 8,
    SLOT5_AW = 8, SLOT6_AW = 8, SLOT7_AW = 8, SLOT8_AW = 8, SLOT9_AW = 8,

    SLOT0_CACHE = 1, SLOT1_CACHE = 1, SLOT2_CACHE = 1, SLOT3_CACHE = 1, SLOT4_CACHE = 1,
    SLOT5_CACHE = 1, SLOT6_CACHE = 1, SLOT7_CACHE = 1, SLOT8_CACHE = 1, SLOT9_CACHE = 1,

    SLOT0_TYPE = 0, SLOT1_TYPE = 0, SLOT2_TYPE = 0, SLOT3_TYPE = 0, SLOT4_TYPE = 0,
    SLOT5_TYPE = 0, SLOT6_TYPE = 0, SLOT7_TYPE = 0, SLOT8_TYPE = 0, SLOT9_TYPE = 0
)(
    input               rst,
    input               clk,
    input               vblank,

    input  [SLOT0_AW-1:0] slot0_addr,
    input  [SLOT1_AW-1:0] slot1_addr,
    input  [SLOT2_AW-1:0] slot2_addr,
    input  [SLOT3_AW-1:0] slot3_addr,
    input  [SLOT4_AW-1:0] slot4_addr,
    input  [SLOT5_AW-1:0] slot5_addr,
    input  [SLOT6_AW-1:0] slot6_addr,
    input  [SLOT7_AW-1:0] slot7_addr,
    input  [SLOT8_AW-1:0] slot8_addr,
    input  [SLOT9_AW-1:0] slot9_addr,

    input  [SLOT0_AW-1:0] slot0_offset,
    input  [SLOT1_AW-1:0] slot1_offset,
    input  [SLOT2_AW-1:0] slot2_offset,
    input  [SLOT3_AW-1:0] slot3_offset,
    input  [SLOT4_AW-1:0] slot4_offset,
    input  [SLOT5_AW-1:0] slot5_offset,
    input  [SLOT6_AW-1:0] slot6_offset,
    input  [SLOT7_AW-1:0] slot7_offset,
    input  [SLOT8_AW-1:0] slot8_offset,
    input  [SLOT9_AW-1:0] slot9_offset,

    //  output data
    output [SLOT0_DW-1:0] slot0_dout,
    output [SLOT1_DW-1:0] slot1_dout,
    output [SLOT2_DW-1:0] slot2_dout,
    output [SLOT3_DW-1:0] slot3_dout,
    output [SLOT4_DW-1:0] slot4_dout,
    output [SLOT5_DW-1:0] slot5_dout,
    output [SLOT6_DW-1:0] slot6_dout,
    output [SLOT7_DW-1:0] slot7_dout,
    output [SLOT8_DW-1:0] slot8_dout,
    output [SLOT9_DW-1:0] slot9_dout,

    //  input data
    input  [SLOT0_DW-1:0] slot0_din,
    input  [SLOT1_DW-1:0] slot1_din,
    input  [SLOT2_DW-1:0] slot2_din,
    input  [SLOT3_DW-1:0] slot3_din,
    input  [SLOT4_DW-1:0] slot4_din,
    input  [SLOT5_DW-1:0] slot5_din,
    input  [SLOT6_DW-1:0] slot6_din,
    input  [SLOT7_DW-1:0] slot7_din,
    input  [SLOT8_DW-1:0] slot8_din,
    input  [SLOT9_DW-1:0] slot9_din,
    output  reg         ready=1'b0,

    input  [9:0]        slot_cs,
    input  [9:0]        slot_wr,
    output [9:0]        slot0_ok,
);

jtframe_sdram_rq #(.AW(SLOT0_AW),.DW(SLOT0_DW),.TYPE(SLOT0_TYPE),.CACHE(SLOT0_CACHE)) u_slot0(
    .rst       ( rst                    ),
    .clk       ( clk                    ),
    .cen       ( 1'b1                   ),
    .addr      ( slot0_addr             ),
    .addr_ok   ( slot_cs[0]             ),
    .offset    ( slot0_offset           ),
    .wrdata    ( slot0_din              ),
    .wrin      ( slot_wr[0]             ),
    .req_rnw   ( req_rnw[0]             ),
    .sdram_addr( slot0_addr_req         ),
    .din       ( data_read              ),
    .din_ok    ( data_rdy               ),
    .dout      ( slot0_dout             ),
    .req       ( req[0]                 ),
    .data_ok   ( ok[0]                  ),
    .we        ( data_sel[0]            )
);

jtframe_sdram_rq #(.AW(SLOT1_AW),.DW(SLOT1_DW),.TYPE(SLOT1_TYPE),.CACHE(SLOT1_CACHE)) u_slot1(
    .rst       ( rst                    ),
    .clk       ( clk                    ),
    .cen       ( 1'b1                   ),
    .addr      ( slot1_addr             ),
    .addr_ok   ( slot_cs[1]             ),
    .offset    ( slot1_offset           ),
    .wrdata    ( slot1_din              ),
    .wrin      ( slot_wr[1]             ),
    .req_rnw   ( req_rnw[1]             ),
    .sdram_addr( slot1_addr_req         ),
    .din       ( data_read              ),
    .din_ok    ( data_rdy               ),
    .dout      ( slot1_dout             ),
    .req       ( req[1]                 ),
    .data_ok   ( ok[1]                  ),
    .we        ( data_sel[1]            )
);

jtframe_sdram_rq #(.AW(SLOT2_AW),.DW(SLOT2_DW),.TYPE(SLOT2_TYPE),.CACHE(SLOT2_CACHE)) u_slot2(
    .rst       ( rst                    ),
    .clk       ( clk                    ),
    .cen       ( 1'b1                   ),
    .addr      ( slot2_addr             ),
    .addr_ok   ( slot_cs[2]             ),
    .offset    ( slot2_offset           ),
    .wrdata    ( slot2_din              ),
    .wrin      ( slot_wr[2]             ),
    .req_rnw   ( req_rnw[2]             ),
    .sdram_addr( slot2_addr_req         ),
    .din       ( data_read              ),
    .din_ok    ( data_rdy               ),
    .dout      ( slot2_dout             ),
    .req       ( req[2]                 ),
    .data_ok   ( ok[2]                  ),
    .we        ( data_sel[2]            )
);

jtframe_sdram_rq #(.AW(SLOT3_AW),.DW(SLOT3_DW),.TYPE(SLOT3_TYPE),.CACHE(SLOT3_CACHE)) u_slot3(
    .rst       ( rst                    ),
    .clk       ( clk                    ),
    .cen       ( 1'b1                   ),
    .addr      ( slot3_addr             ),
    .addr_ok   ( slot_cs[3]             ),
    .offset    ( slot3_offset           ),
    .wrdata    ( slot3_din              ),
    .wrin      ( slot_wr[3]             ),
    .req_rnw   ( req_rnw[3]             ),
    .sdram_addr( slot3_addr_req         ),
    .din       ( data_read              ),
    .din_ok    ( data_rdy               ),
    .dout      ( slot3_dout             ),
    .req       ( req[3]                 ),
    .data_ok   ( ok[3]                  ),
    .we        ( data_sel[3]            )
);

jtframe_sdram_rq #(.AW(SLOT4_AW),.DW(SLOT4_DW),.TYPE(SLOT4_TYPE),.CACHE(SLOT4_CACHE)) u_slot4(
    .rst       ( rst                    ),
    .clk       ( clk                    ),
    .cen       ( 1'b1                   ),
    .addr      ( slot4_addr             ),
    .addr_ok   ( slot_cs[4]             ),
    .offset    ( slot4_offset           ),
    .wrdata    ( slot4_din              ),
    .wrin      ( slot_wr[4]             ),
    .req_rnw   ( req_rnw[4]             ),
    .sdram_addr( slot4_addr_req         ),
    .din       ( data_read              ),
    .din_ok    ( data_rdy               ),
    .dout      ( slot4_dout             ),
    .req       ( req[4]                 ),
    .data_ok   ( ok[4]                  ),
    .we        ( data_sel[4]            )
);

jtframe_sdram_rq #(.AW(SLOT5_AW),.DW(SLOT5_DW),.TYPE(SLOT5_TYPE),.CACHE(SLOT5_CACHE)) u_slot5(
    .rst       ( rst                    ),
    .clk       ( clk                    ),
    .cen       ( 1'b1                   ),
    .addr      ( slot5_addr             ),
    .addr_ok   ( slot_cs[5]             ),
    .offset    ( slot5_offset           ),
    .wrdata    ( slot5_din              ),
    .wrin      ( slot_wr[5]             ),
    .req_rnw   ( req_rnw[5]             ),
    .sdram_addr( slot5_addr_req         ),
    .din       ( data_read              ),
    .din_ok    ( data_rdy               ),
    .dout      ( slot5_dout             ),
    .req       ( req[5]                 ),
    .data_ok   ( ok[5]                  ),
    .we        ( data_sel[5]            )
);

jtframe_sdram_rq #(.AW(SLOT6_AW),.DW(SLOT6_DW),.TYPE(SLOT6_TYPE),.CACHE(SLOT6_CACHE)) u_slot6(
    .rst       ( rst                    ),
    .clk       ( clk                    ),
    .cen       ( 1'b1                   ),
    .addr      ( slot6_addr             ),
    .addr_ok   ( slot_cs[6]             ),
    .offset    ( slot6_offset           ),
    .wrdata    ( slot6_din              ),
    .wrin      ( slot_wr[6]             ),
    .req_rnw   ( req_rnw[6]             ),
    .sdram_addr( slot6_addr_req         ),
    .din       ( data_read              ),
    .din_ok    ( data_rdy               ),
    .dout      ( slot6_dout             ),
    .req       ( req[6]                 ),
    .data_ok   ( ok[6]                  ),
    .we        ( data_sel[6]            )
);

jtframe_sdram_rq #(.AW(SLOT7_AW),.DW(SLOT7_DW),.TYPE(SLOT7_TYPE),.CACHE(SLOT7_CACHE)) u_slot7(
    .rst       ( rst                    ),
    .clk       ( clk                    ),
    .cen       ( 1'b1                   ),
    .addr      ( slot7_addr             ),
    .addr_ok   ( slot_cs[7]             ),
    .offset    ( slot7_offset           ),
    .wrdata    ( slot7_din              ),
    .wrin      ( slot_wr[7]             ),
    .req_rnw   ( req_rnw[7]             ),
    .sdram_addr( slot7_addr_req         ),
    .din       ( data_read              ),
    .din_ok    ( data_rdy               ),
    .dout      ( slot7_dout             ),
    .req       ( req[7]                 ),
    .data_ok   ( ok[7]                  ),
    .we        ( data_sel[7]            )
);

jtframe_sdram_rq #(.AW(SLOT8_AW),.DW(SLOT8_DW),.TYPE(SLOT8_TYPE),.CACHE(SLOT8_CACHE)) u_slot8(
    .rst       ( rst                    ),
    .clk       ( clk                    ),
    .cen       ( 1'b1                   ),
    .addr      ( slot8_addr             ),
    .addr_ok   ( slot_cs[8]             ),
    .offset    ( slot8_offset           ),
    .wrdata    ( slot8_din              ),
    .wrin      ( slot_wr[8]             ),
    .req_rnw   ( req_rnw[8]             ),
    .sdram_addr( slot8_addr_req         ),
    .din       ( data_read              ),
    .din_ok    ( data_rdy               ),
    .dout      ( slot8_dout             ),
    .req       ( req[8]                 ),
    .data_ok   ( ok[8]                  ),
    .we        ( data_sel[8]            )
);

jtframe_sdram_rq #(.AW(SLOT9_AW),.DW(SLOT9_DW),.TYPE(SLOT9_TYPE),.CACHE(SLOT9_CACHE)) u_slot9(
    .rst       ( rst                    ),
    .clk       ( clk                    ),
    .cen       ( 1'b1                   ),
    .addr      ( slot9_addr             ),
    .addr_ok   ( slot_cs[9]             ),
    .offset    ( slot9_offset           ),
    .wrdata    ( slot9_din              ),
    .wrin      ( slot_wr[9]             ),
    .req_rnw   ( req_rnw[9]             ),
    .sdram_addr( slot9_addr_req         ),
    .din       ( data_read              ),
    .din_ok    ( data_rdy               ),
    .dout      ( slot9_dout             ),
    .req       ( req[9]                 ),
    .data_ok   ( ok[9]                  ),
    .we        ( data_sel[9]            )
);


endmodule
