/*  This file is part of JTCPS1.
    JTCPS1 program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    JTCPS1 program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR a PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with JTCPS1.  If not, see <http://www.gnu.org/licenses/>.

    Author: Jose Tejada Gomez. Twitter: @topapate
    Version: 1.0
    Date: 13-1-2020 */
    
`timescale 1ns/1ps

// A[22:20]   Usage
// 000        OBJ
// 001        SCROLL 1
// 010        SCROLL 2
// 011        SCROLL 3
// 100        Star field

module jtcps1_gfx_mappers(
    input              clk,
    input              rst,
    input              enable,

    input      [ 5:0]  game,
    input      [15:0]  bank_offset,
    input      [15:0]  bank_mask,

    input      [ 2:0]  layer,
    input      [ 9:0]  cin,    // pins 2-9, 11,13,15,17,18
    
    output reg [ 3:0]  offset,
    output reg [ 3:0]  mask,
    output             unmapped
);

localparam [2:0] OBJ=3'd0, SCR1=3'd1, SCR2=3'd2, SCR3=3'd3, START=3'd4;

reg  [ 3:0]  bank;
wire [22:10] a = {layer,cin};

assign unmapped = bank==4'd0; // no bank was selected

wire i1 = 1'b0;
wire i2 = layer[2];
wire i3 = layer[1];
wire i4 = layer[0];
wire i5 = cin[9];
wire i6 = cin[8];
wire i7 = cin[7];
wire i8 = cin[6];
wire i9 = cin[5];
wire i11= cin[4];
wire i13= cin[3];
wire i17= cin[2];
wire i18= cin[1];
wire i19= cin[0];

localparam
        game_1941     = 0,
        game_3wonders = 1,
        game_captcomm = 2,
        game_cawing   = 3,
        game_cworld2j = 4,
        game_dino     = 5,
        game_dynwar   = 6,
        game_ffight   = 7,
        game_forgottn = 8,
        game_ganbare  = 9,
        game_ghouls   = 10,
        game_knights  = 11,
        game_kod      = 12,
        game_mbombrd  = 13,
        game_megaman  = 14,
        game_mercs    = 15,
        game_msword   = 16,
        game_mtwins   = 17,
        game_nemo     = 18,
        game_pang3    = 19,
        game_pnickj   = 20,
        game_pokonyan = 21,
        game_punisher = 22,
        game_qad      = 23,
        game_qtono2j  = 24,
        game_sf2      = 25,
        game_sf2ce    = 26,
        game_sf2hf    = 27,
        game_slammast = 28,
        game_strider  = 29,
        game_unsquad  = 30,
        game_varth    = 31,
        game_willow   = 32,
        game_wof      = 33;

wire dino16 = (~i1 & ~i2 & ~i5 & i6 & ~i11) |
                (i1 & ~i2 & ~i5 & i6 & i11);
wire dino17 = (~i1 & ~i2 & ~i5 & i6 & ~i11) |(i1 & ~i2 & ~i5 & i6 & i11);
wire dino18 = (~i1 & ~i2 & ~i5 & ~i6 & ~i11) | (i1 & ~i2 & ~i5 & ~i6 & i11);
wire dino19 = (~i1 & ~i2 & ~i5 & ~i6 & ~i11) | (i1 & ~i2 & ~i5 & ~i6 & i11);

always @(posedge clk, posedge rst) begin
    if( rst ) begin
        bank <= 4'd0;
    end else if(enable) begin
        case( game )
            game_1941:
                bank <= { 3'b0,
                (~i1 & ~i2 & i3 & ~i4 & ~i5 & ~i6 & i7 & i11              )|
                (~i1 & ~i2 & i3 & ~i4 & ~i5 & ~i6 & i7 & i8               )|
                (~i1 & ~i2 & i3 & i4 & ~i5 & ~i6 & ~i7 & i8               )|
                (~i1 & ~i2 & ~i3 & ~i4 & ~i5 & ~i6 & ~i7 & ~i8            )|
                (~i1 & ~i2 & i3 & ~i4 & ~i5 & ~i6 & i7 & i9               )|
                (~i1 & ~i2 & ~i3 & i4 & ~i5 & ~i6 & i7 & ~i8 & ~i9 & ~i11 )
                };
            game_3wonders:
              bank <= { 2'b0,
                (~i1 & ~i2 & ~i3 & ~i4 & ~i5 & ~i6 & ~i7                 )|
                (~i1 & ~i2 & ~i3 & ~i4 & ~i5 & ~i6 & ~i8 & ~i11          )|
                (~i1 & ~i2 & ~i3 & ~i4 & ~i5 & ~i6 & ~i8 & ~i9 & ~i13    )|
                (~i1 & ~i2 & i3 & i4 & ~i5 & ~i6 & i7 & i8 & i11         )|
                (~i1 & ~i2 & ~i3 & i4 & ~i5 & ~i6 & i7 & i8 & ~i11       )|
                (~i1 & ~i2 & ~i3 & i4 & ~i5 & ~i6 & i7 & ~i8 & i11 & i13 )|
                (~i1 & ~i2 & ~i3 & i4 & ~i5 & ~i6 & i7 & ~i8 & i9 & i11  ),

                (~i1 & ~i2 & i3 & ~i4 & ~i5 & ~i6 & i7        )|
                (~i1 & ~i2 & i3 & i4 & ~i5 & ~i6 & ~i7        )|
                (~i1 & ~i2 & ~i4 & ~i5 & ~i6 & i7 & i8        )|
                (~i1 & ~i2 & i3 & ~i4 & ~i5 & ~i6 & i8 & i9   )|
                (~i1 & ~i2 & ~i4 & ~i5 & ~i6 & i7 & i11 & i13 )|
                (~i1 & ~i2 & i3 & ~i4 & ~i5 & ~i6 & i8 & i11  )|
                (~i1 & ~i2 & ~i4 & ~i5 & ~i6 & i7 & i9 & i11  )
                };
            game_captcomm:
                bank <= { 2'b0,
                    (~i1 & ~i2 & ~i5 & i6 & ~i11) |
                    (i1 & ~i2 & ~i5 & i6 & i11  ) ,
                    (~i1 & ~i2 & ~i4 & ~i5 & ~i6 & ~i11) |
                    (i1 & ~i2 & ~i4 & ~i5 & ~i6 & i11  )
                };
            game_cawing:
                bank <= {3'b0,
                    (~i1 & ~i2 & ~i3 & i4 & ~i5 & ~i6 & i7 & ~i8 & ~i9 & i11) |
                    (~i1 & ~i2 & i3 & i4 & ~i5 & ~i6 & i7 & ~i8 & ~i11      ) |
                    (~i1 & ~i2 & i3 & i4 & ~i5 & ~i6 & ~i7 & i8 & i11       ) |
                    (~i1 & ~i2 & ~i4 & ~i5 & ~i6 & ~i7 & ~i8 & ~i9 & i11    ) |
                    (~i1 & ~i2 & ~i4 & ~i5 & ~i6 & ~i8 & i9 & i11           ) |
                    (~i1 & ~i2 & ~i4 & ~i5 & ~i6 & ~i7 & ~i11               ) |
                    (~i1 & ~i2 & ~i4 & ~i5 & ~i6 & i7 & i8                  ) 
                };
            // game_cworld2j: no dump
            game_dino: // unknown bit assignments
                bank <= { 2'b0, dino17, dino19 };
            game_dynwar:
                bank <= {
                   (~i1 & ~i2 & ~i3 & ~i4 & ~i5 & ~i6 & ~i7),

                   (~i1 & ~i2 & ~i3 & i4 & ~i5 & ~i6 & i7 & i8) |
                   (~i1 & ~i2 & ~i3 & ~i4 & ~i5 & ~i6 & i7 & ~i8),

                   (~i1 & ~i2 & ~i3 & ~i4 & ~i5 & ~i6 & ~i7) |
                   (~i1 & ~i2 & ~i3 & ~i4 & ~i5 & ~i6 & ~i8) |
                   (~i1 & ~i2 & ~i3 & i4 & ~i5 & ~i6 & i7 & i8),

                   (~i1 & ~i2 & i3 & ~i4 & ~i5 & ~i6 & i7) |
                   (~i1 & ~i2 & i3 & i4 & ~i5 & ~i6 & ~i7)
                };
            // game_ganbare: // not dumped
            game_ghouls:
                bank <= { 1'b0,
                       ~i1 & ~i2 & ~i3 & ~i4 & i8,
                       ~i1 & ~i2 & i3 & i4 & ~i8,
                       (~i1 & ~i2 & ~i3 & i4 ) |
                       (~i1 & ~i2 & ~i4 & ~i8) |
                       (~i1 & ~i2 & i3 & ~i4) };
            game_knights:
                bank <= { 2'b0,
                    (~i2 & i3 & i4 & ~i5 & i6 & i7 & ~i8 & i9)|
                    (~i2 & i3 & i4 & ~i5 & i6 & i7 & i8) |
                    (~i2 & ~i3 & i4 & ~i5 & i6 & ~i7 & ~i8) |
                    (~i2 & ~i4 & ~i5 & i6 & ~i8 & ~i9) |
                    (~i2 & ~i4 & ~i5 & i6 & ~i7),
                    ~i2 & ~i4 & ~i5 & ~i6
                };
            game_kod:
                bank <= { 2'b0,
                    (~i2 & i3 & i4 & ~i5 & i6 & i7 & i8) |
                    (~i2 & i3 & ~i4 & ~i5 & i6 & ~i7 & i8) |
                    (~i2 & i3 & ~i4 & ~i5 & i6 & ~i7 & i9) |
                    (~i2 & ~i3 & i4 & ~i5 & i6 & i7 & ~i8 & ~i9) |
                    (~i2 & ~i3 & ~i4 & ~i5 & i6 & ~i7 & ~i8 & ~i9) |
                    (~i2 & i3 & i4 & ~i5 & i6 & i7 & i9 & i11) |
                    (~i2 & ~i3 & i4 & ~i5 & i6 & i7 & ~i8 & ~i11),

                    (i1 & ~i2 & ~i3 & ~i4 & ~i5 & ~i6 & i17) |
                    (~i1 & ~i2 & ~i3 & ~i4 & ~i5 & ~i6 & ~i17)
                };
            game_ffight:
                bank <= {3'b0,
                       (~i1 & ~i2 & ~i3 & i4 & ~i5 & ~i6 & i7 & ~i8 & ~i9 & ~i11 & i13) |
                       (~i1 & ~i2 & ~i3 & i4 & ~i5 & ~i6 & i7 & ~i8 & i9 & ~i11 & ~i13) |
                       (~i1 & ~i2 & ~i3 & ~i4 & ~i5 & ~i6 & ~i8 & ~i9 & ~i11 & ~i13   ) |
                       (~i1 & ~i2 & i3 & i4 & ~i5 & ~i6 & i7 & ~i8 & i9 & i13         ) |
                       (~i1 & ~i2 & i3 & i4 & ~i5 & ~i6 & i7 & ~i8 & i11              ) |
                       (~i1 & ~i2 & i3 & ~i4 & ~i5 & ~i6 & i7 & i8                    ) |
                       (~i1 & ~i2 & ~i3 & ~i4 & ~i5 & ~i6 & ~i7                       ) };
            // game_mbombrd: // no pinout available. GAL has too many outputs with too few OR'ed elements
            //     bank <= { 1'b0, 
            //     };
            game_megaman: // pins 13, 15, 17, 19
                bank <= {
                        cin[9:8] == 2'b11,
                        cin[9:8] == 2'b10,
                        cin[9:8] == 2'b01,
                        cin[9:8] == 2'b00 };
                        /* original equations:
                    ~i1 & i5 & i6 & ~i11 |
                    i1 & i5 & i6 & i11,

                    ~i1 & i5 & ~i6 & ~i11 |
                    i1 & i5 & ~i6 & i11,

                    ~i1 & ~i5 & i6 & ~i11 |
                    i1 & ~i5 & i6 & i11,

                    ~i1 & ~i5 & ~i6 & ~i11 |
                    i1 & ~i5 & ~i6 & i11 */
            game_mercs:
                bank <= { 2'b0,
                   (~i1 & ~i2 & i3 & i4 & ~i5 & i6 & ~i7 & i8 & i9 & i11     )|
                   (~i1 & ~i2 & i3 & ~i4 & ~i5 & i6 & ~i7 & i8 & i9 & ~i11   )|
                   (~i1 & ~i2 & ~i3 & ~i4 & ~i5 & i6 & ~i7 & ~i8 & ~i9 & i11 )|
                   (~i1 & ~i2 & i3 & ~i4 & ~i5 & i6 & ~i7 & i8 & ~i9 & i11   )|
                   (~i1 & ~i2 & ~i3 & ~i4 & ~i5 & i6 & ~i7 & ~i9 & ~i11      )|
                   (~i1 & ~i2 & ~i3 & ~i4 & ~i5 & i6 & ~i7 & ~i8 & i9        ),
                   // bank 0
                   (~i1 & ~i2 & ~i3 & i4 & ~i5 & ~i6 & ~i7 & ~i8 & i9 & ~i11 & ~i13) |
                   (~i1 & ~i2 & ~i3 & i4 & ~i5 & ~i6 & ~i7 & ~i8 & ~i9 & ~i11      ) |
                   (~i1 & ~i2 & i3 & i4 & ~i5 & ~i6 & i7 & ~i8 & ~i9 & ~i11     ) |
                   (~i1 & ~i2 & i3 & i4 & ~i5 & ~i6 & i7 & ~i8 & ~i11 & ~i13    ) |
                   (~i1 & ~i2 & ~i3 & ~i4 & ~i5 & ~i6 & i7 & ~i8 & i9 & i13     ) |
                   (~i1 & ~i2 & ~i3 & ~i4 & ~i5 & ~i6 & i7 & i11                ) |
                   (~i1 & ~i2 & ~i3 & ~i4 & ~i5 & ~i6 & i7 & i8                 ) |
                   (~i1 & ~i2 & i3 & i4 & ~i5 & ~i6 & ~i7 & i8 & i9 & i11 & i13 ) |
                   (~i1 & ~i2 & i3 & ~i4 & ~i5 & ~i6 & ~i7 & ~i8 & i9 & i13     ) |
                   (~i1 & ~i2 & i3 & ~i4 & ~i5 & ~i6 & ~i7 & i8 & ~i11          ) |
                   (~i1 & ~i2 & i3 & ~i4 & ~i5 & ~i6 & ~i7 & ~i9 & i11          ) |
                   (~i1 & ~i2 & i3 & ~i4 & ~i5 & ~i6 & ~i7 & i11 & ~i13         )  };
            game_msword:
                bank <= { 3'b0, 
                    (~i1 & ~i2 & ~i3 & i4 & ~i5 & ~i6 & i7 & ~i8 & ~i11) |
                    (~i1 & ~i2 & i3 & i4 & ~i5 & ~i6 & i7 & i8 & i11) |
                    (~i1 & ~i2 & i3 & ~i4 & ~i5 & ~i6 & i7 & i8 & ~i11) |
                    (~i1 & ~i2 & i3 & ~i4 & ~i5 & ~i6 & i7 & ~i8 & i11) |
                    (~i1 & ~i2 & ~i3 & ~i4 & ~i5 & ~i6 & ~i7)
                };
            game_mtwins:
                bank <= { 3'b0,
                    (~i1 & ~i2 & ~i3 & i4 & ~i5 & ~i6 & ~i7 & i8 & i11) |
                    (~i1 & ~i2 & i3 & i4 & ~i5 & ~i6 & i7 & i8 & i11) |
                    (~i1 & ~i2 & ~i3 & ~i4 & ~i5 & ~i6 & ~i7 & ~i11) |
                    (~i1 & ~i2 & i3 & ~i4 & ~i5 & ~i6 & i7 & ~i11) |
                    (~i1 & ~i2 & ~i3 & ~i4 & ~i5 & ~i6 & ~i7 & ~i8) |
                    (~i1 & ~i2 & i3 & ~i4 & ~i5 & ~i6 & i7 & ~i8)
                };
            game_nemo:
                bank <= { 3'b0,
                    (~i1 & ~i2 & ~i3 & i4 & ~i5 & ~i6 & i7 & ~i8 & ~i9 & ~i11) |
                    (~i1 & ~i2 & i3 & i4 & ~i5 & ~i6 & i7 & i8 & ~i9 & i11) |
                    (~i1 & ~i2 & i3 & i4 & ~i5 & ~i6 & i7 & i8 & i9) |
                    (~i1 & ~i2 & ~i4 & ~i5 & ~i6 & i8 & ~i9 & ~i11) |
                    (~i1 & ~i2 & ~i4 & ~i5 & ~i6 & ~i8 & ~i9 & i11) |
                    (~i1 & ~i2 & ~i4 & ~i5 & ~i6 & ~i8 & i9) |
                    (~i1 & ~i2 & ~i4 & ~i5 & ~i6 & ~i7)
                };
            game_pang3:
                bank <= { 2'b0,
                    (i1 & ~i2 & i3 & ~i5 & ~i6 & i7 & ~i17) |
                    (i1 & ~i2 & i3 & ~i4 & i5 & ~i17) |
                    (i1 & ~i2 & i3 & ~i6 & ~i7 & ~i17) |
                    (i1 & ~i2 & i3 & ~i5 & i6 & ~i17),
                    (i1 & ~i2 & i3 & i4 & i5 & i6 & ~i7 & ~i17) |
                    (i1 & ~i2 & i3 & i4 & i5 & ~i6 & i7 & ~i17)
                };
            // game_pnickj nodump
            // game_pokonyan: nodump
            // game_punisher: nodump
            game_strider:
                bank <= { 2'b0, 
                   //( ~i2 & ~i3 & i4 &  ~i5 & ~i6 & i7 & i8 & i11) | // SCR1
                   //(layer==SCR1 && cin[9:6]==4'b0111 ) |
                   //( ~i2 &  i3 & i4 &  ~i5 & ~i6), // SCR3
                   //(layer==SCR3 && cin[9:6]==2'b00 ),
                   layer==SCR3 || layer==SCR1,
                   !(layer==SCR3 || layer==SCR1)
                    /*

                   (~i1 & ~i2 & ~i4 & ~i5 & ~i6 & i7 & ~i8 & ~i9 & ~i11         )|
                   (~i1 & ~i3 & ~i4 & ~i5 & ~i6 & ~i7 & ~i8 & ~i9 & ~i11 & ~i13 )|
                   (~i1 & ~i2 & i3 & ~i4 & ~i5 & ~i6 & i7 & ~i8 & i9            )|
                   (~i1 & ~i2 & i3 & ~i4 & ~i5 & ~i6 & i7 & i8                  )|
                   (~i1 & ~i2 & i3 & ~i4 & ~i5 & ~i6 & i7 & ~i9 & i11           )|
                   (~i1 & ~i2 & ~i3 & ~i4 & ~i5 & ~i6 & ~i8 & i9 & ~i11         )|
                   (~i1 & ~i2 & ~i3 & ~i4 & ~i5 & ~i6 & ~i7                     )*/
                };

            game_sf2: // GAL input pins renamed
                bank <= { 2'b0,
                   (~i1 & ~i2 & ~i3 & i4 & ~i5 & ~i6 & ~i7      ) |
                   (~i1 & i2 & i3 & ~i4 & ~i5 & ~i6 & i7        ) |
                   (~i1 & ~i2 & i3 & ~i4 & ~i5 & i6 & ~i7 & ~i8 ) |
                   (~i1 & i2 & ~i3 & ~i4 & ~i5 & i6 & ~i7 & i8  ) |
                   (~i1 & i2 & ~i3 & ~i4 & ~i5 & i6 & i7        ),
                   // bank 1
                   ~i1 & ~i2 & ~i3 & ~i4 & i5,
                   // bank 0
                   ~i1 & ~i2 & ~i3 & ~i4 & ~i5 };
            game_unsquad:
                bank <= { 3'b0, 
                   (~i1 & ~i2 & ~i3 & ~i4 & ~i5 & ~i6 & ~i7 & ~i11    ) |
                   (~i1 & ~i2 & i3 & i4 & ~i5 & ~i6 & i7 & i8         ) |
                   (~i1 & ~i2 & ~i3 & i4 & ~i5 & ~i6 & ~i7 & i8 & i11 ) |
                   (~i1 & ~i2 & i3 & ~i4 & ~i5 & ~i6 & i7 & ~i8       ) |
                   (~i1 & ~i2 & ~i3 & ~i4 & ~i5 & ~i6 & ~i7 & ~i8     ) };
            game_forgottn:
                bank <= { 2'b0,
                   (~i1 & ~i2 & i3 & ~i4) |
                   (~i1 & i2 & ~i3 & ~i4),
                   (~i1 & ~i2 & ~i3 & i4) |
                   (~i1 & ~i2 & ~i3 & ~i5 & ~i6) };
            game_willow:
                bank <= { 2'b0, 
                        ~i1 & ~i2 & i3 & ~i4 & ~i5 & ~i6 & ~i7,
                        // bank 0
                        (~i1 & ~i2 & i3 & i4 & ~i5 & ~i6 & i7 & i8 & ~i11) |
                        (~i1 & ~i2 & i3 & i4 & ~i5 & ~i6 & i7 & ~i8 & i11) |
                        (~i1 & ~i2 & ~i3 & i4 & ~i5 & ~i6 & i7 & i8 & i11) |
                        (~i1 & ~i2 & ~i3 & ~i4 & ~i5 & ~i6 & ~i8 & ~i11) |
                        (~i1 & ~i2 & ~i3 & ~i4 & ~i5 & ~i6 & ~i7) };
            default: bank <= 4'd0;
        endcase
    end
end

always @(*) begin
    case ( bank )
        4'b0001: { offset, mask } = { bank_offset[ 3: 0], bank_mask[ 3: 0] };
        4'b0010: { offset, mask } = { bank_offset[ 7: 4], bank_mask[ 7: 4] };
        4'b0100: { offset, mask } = { bank_offset[11: 8], bank_mask[11: 8] };
        4'b1000: { offset, mask } = { bank_offset[15:12], bank_mask[15:12] };
        default: { offset, mask } = { 4'h0, 4'hf };
    endcase
end

/*
always @(*) begin
    case( bank )
        4'b0100: cout={7'b0,cin[2:0]} | (16'ha000>>10); // bank 0
        4'b0010: cout={7'b0,cin[2:0]} | (16'h8000>>10); // bank 1
        4'b0001: cout={1'b0,cin[8:0]};                  // bank 2
    endcase
end
*/
endmodule