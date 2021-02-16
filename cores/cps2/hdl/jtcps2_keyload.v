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

module jtcps2_keyload(
    input             clk,
    input             rst,
    input      [ 7:0] din,
    input             din_we,

    output     [15:0] addr_rng,
    output     [63:0] key
);

reg          last_din_we;
wire [159:0] cfg;
reg  [159:0] raw;

always @(posedge clk, posedge rst) begin
    if( rst ) begin
        last_din_we <= 0;
        raw <= 160'd0;
    end else begin
        last_din_we <= din_we;
        if( din_we && !last_din_we ) begin
            raw <= { din, raw[159:8] };
        end
        if( last_din_we && !din_we )
            $display("%X -> %x", raw, cfg );
    end
end

assign key= { cfg[15:0], cfg[31:16], cfg[47:32], cfg[63:48] };

assign cfg={
/* 159 */ raw[ 10],
/* 158 */ raw[ 11],
/* 157 */ raw[ 12],
/* 156 */ raw[ 13],
/* 155 */ raw[ 14],
/* 154 */ raw[ 15],
/* 153 */ raw[  0],
/* 152 */ raw[  1],
/* 151 */ raw[  2],
/* 150 */ raw[  3],
/* 149 */ raw[  4],
/* 148 */ raw[  5],
/* 147 */ raw[  6],
/* 146 */ raw[  7],
/* 145 */ raw[152],
/* 144 */ raw[153],
/* 143 */ raw[ 26],
/* 142 */ raw[ 27],
/* 141 */ raw[ 28],
/* 140 */ raw[ 29],
/* 139 */ raw[ 30],
/* 138 */ raw[ 31],
/* 137 */ raw[ 16],
/* 136 */ raw[ 17],
/* 135 */ raw[ 18],
/* 134 */ raw[ 19],
/* 133 */ raw[ 20],
/* 132 */ raw[ 21],
/* 131 */ raw[ 22],
/* 130 */ raw[ 23],
/* 129 */ raw[  8],
/* 128 */ raw[  9],
/* 127 */ raw[ 42],
/* 126 */ raw[ 43],
/* 125 */ raw[ 44],
/* 124 */ raw[ 45],
/* 123 */ raw[ 46],
/* 122 */ raw[ 47],
/* 121 */ raw[ 32],
/* 120 */ raw[ 33],
/* 119 */ raw[ 34],
/* 118 */ raw[ 35],
/* 117 */ raw[ 36],
/* 116 */ raw[ 37],
/* 115 */ raw[ 38],
/* 114 */ raw[ 39],
/* 113 */ raw[ 24],
/* 112 */ raw[ 25],
/* 111 */ raw[ 58],
/* 110 */ raw[ 59],
/* 109 */ raw[ 60],
/* 108 */ raw[ 61],
/* 107 */ raw[ 62],
/* 106 */ raw[ 63],
/* 105 */ raw[ 48],
/* 104 */ raw[ 49],
/* 103 */ raw[ 50],
/* 102 */ raw[ 51],
/* 101 */ raw[ 52],
/* 100 */ raw[ 53],
/*  99 */ raw[ 54],
/*  98 */ raw[ 55],
/*  97 */ raw[ 40],
/*  96 */ raw[ 41],
/*  95 */ raw[ 74],
/*  94 */ raw[ 75],
/*  93 */ raw[ 76],
/*  92 */ raw[ 77],
/*  91 */ raw[ 78],
/*  90 */ raw[ 79],
/*  89 */ raw[ 64],
/*  88 */ raw[ 65],
/*  87 */ raw[ 66],
/*  86 */ raw[ 67],
/*  85 */ raw[ 68],
/*  84 */ raw[ 69],
/*  83 */ raw[ 70],
/*  82 */ raw[ 71],
/*  81 */ raw[ 56],
/*  80 */ raw[ 57],
/*  79 */ raw[ 90],
/*  78 */ raw[ 91],
/*  77 */ raw[ 92],
/*  76 */ raw[ 93],
/*  75 */ raw[ 94],
/*  74 */ raw[ 95],
/*  73 */ raw[ 80],
/*  72 */ raw[ 81],
/*  71 */ raw[ 82],
/*  70 */ raw[ 83],
/*  69 */ raw[ 84],
/*  68 */ raw[ 85],
/*  67 */ raw[ 86],
/*  66 */ raw[ 87],
/*  65 */ raw[ 72],
/*  64 */ raw[ 73],
/*  63 */ raw[106],
/*  62 */ raw[107],
/*  61 */ raw[108],
/*  60 */ raw[109],
/*  59 */ raw[110],
/*  58 */ raw[111],
/*  57 */ raw[ 96],
/*  56 */ raw[ 97],
/*  55 */ raw[ 98],
/*  54 */ raw[ 99],
/*  53 */ raw[100],
/*  52 */ raw[101],
/*  51 */ raw[102],
/*  50 */ raw[103],
/*  49 */ raw[ 88],
/*  48 */ raw[ 89],
/*  47 */ raw[122],
/*  46 */ raw[123],
/*  45 */ raw[124],
/*  44 */ raw[125],
/*  43 */ raw[126],
/*  42 */ raw[127],
/*  41 */ raw[112],
/*  40 */ raw[113],
/*  39 */ raw[114],
/*  38 */ raw[115],
/*  37 */ raw[116],
/*  36 */ raw[117],
/*  35 */ raw[118],
/*  34 */ raw[119],
/*  33 */ raw[104],
/*  32 */ raw[105],
/*  31 */ raw[138],
/*  30 */ raw[139],
/*  29 */ raw[140],
/*  28 */ raw[141],
/*  27 */ raw[142],
/*  26 */ raw[143],
/*  25 */ raw[128],
/*  24 */ raw[129],
/*  23 */ raw[130],
/*  22 */ raw[131],
/*  21 */ raw[132],
/*  20 */ raw[133],
/*  19 */ raw[134],
/*  18 */ raw[135],
/*  17 */ raw[120],
/*  16 */ raw[121],
/*  15 */ raw[154],
/*  14 */ raw[155],
/*  13 */ raw[156],
/*  12 */ raw[157],
/*  11 */ raw[158],
/*  10 */ raw[159],
/*   9 */ raw[144],
/*   8 */ raw[145],
/*   7 */ raw[146],
/*   6 */ raw[147],
/*   5 */ raw[148],
/*   4 */ raw[149],
/*   3 */ raw[150],
/*   2 */ raw[151],
/*   1 */ raw[136],
/*   0 */ raw[137]
};


endmodule