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
reg  [ 11:0] sum = 12'd0;

reg          betang;

always @(posedge clk, posedge rst) begin
    if( rst ) begin
        last_din_we <= 0;
        raw <= 160'd0;
        sum <= 12'd0;
        betang <= 1;
    end else begin
        last_din_we <= din_we;
        if( din_we && !last_din_we ) begin
            raw <= { din, raw[159:8] };
            sum <= ( ((din&8'hcf)!=8'd0) ? (sum^12'h65) : sum ) + {{4{din[7]}},din};
        end
        case(sum)
            12'h4C7, // dstlk
            12'hE81, // megaman2
            12'hFC6, // batcir
            12'h0CA, // qndream
            12'h204, // nwarr
            12'hF12, // sfz2alj
            12'h03D, // csclub
            12'hEE2, // rmancp2j
            12'h247, // sfa2
            12'h147, // jyangoku
            12'h16A, // spf2t
            12'h08A, // dimahoo
            12'h03B, // pzloop2
            12'hDC6, // sfa
            12'hF79, // mpang
            12'h1C1, // ddtod
            12'hF6A, // avsp
            12'h028, // 19xx
            12'hE47, // mmancp2u
            12'h049, // sfz2j
            12'hFD1, // sfz2n
            12'h123, // sfz2h
            12'hF5E, // sfa2u
            12'hFE5, // sfz2b
            12'hFDF, // sfz2a
            12'hE74, // sfzh
            12'hE87, // sfzj
            12'hF10, // sfzb
            12'hEF3, // sfza
            12'hC2C, // sfau
            12'h06E, // ddtoda
            12'h1E9, // ddtodj
            12'h3C3, // ddtodh
            12'h22D, // ddtodu
            12'h321, // nwarru
            12'h212, // vhuntj
            12'h26C, // nwarrb
            12'h23E, // nwarra
            12'h31B, // nwarrh
            12'h206, // 19xxj
            12'hF19, // 19xxa
            12'h21C, // 19xxu
            12'h315, // 19xxh
            12'h1F8, // 19xxb
            12'h2A9, // spf2xj
            12'h1F3, // spf2th
            12'h285, // spf2ta
            12'h0DA, // spf2tu
            12'h379, // dstlkh
            12'h3B5, // dstlka
            12'h482, // dstlku
            12'h316, // vampj
            12'hF5F, // gmahou
            12'hDC3, // dimahoou
            12'hFD6, // rockman2j
            12'hFFF, // megaman2h
            12'h03A, // megaman2a
            12'hF82, // sfz2alb
            12'hF12, // sfz2alj
            12'hE4E, // sfz2al
            12'h076, // sfz2alh
            12'h03E, // xmcotab
            12'h14D, // xmcotau
            12'hE8B, // xmcotaa
            12'h14A, // xmcotah
            12'h043, // xmcotaj
            12'h12D, // cscluba
            12'h0B0, // csclubh
            12'h04C, // csclubj
            12'h106, // avspu
            12'h002, // avspj
            12'h159, // avspa
            12'h023, // avsph
            12'h277, // batcirj
            12'h1C6, // batcira
            12'h068, // xmcota
            // 9 Apr
            12'h1BD, // ddsom
            12'h091, // ddsoma
            12'h0B1, // ddsomb
            12'h034, // ddsomh
            12'h181, // ddsomj
            12'h0DB, // ddsomu
            12'h070, // 1944j
            12'h174, // 1944
            12'hFF3, // 1944u
            12'h005, // choko
            12'h0B9, // sfa3
            12'h2A5, // sfa3b
            12'h026, // sfa3h
            12'h0D3, // sfa3u
            12'h1CB, // sfz3a
            12'h1D3, // sfz3j
            12'h1B0, // ecofghtr
            12'h150, // ecofghtra
            12'h1CD, // ecofghtrh
            12'h126, // ecofghtru
            12'h2A7, // uecology
            12'h309, // progear
            12'h2EE, // progeara
            12'h1AF, // progearj
            // 23rd April
            12'h2B5, // xmvsfa
            12'h187, // xmvsfb
            12'h1D0, // xmvsfh
            12'h1A6, // xmvsfj
            12'h198, // xmvsf
            12'h2AF, // xmvsfu
            12'h037, // vsava
            12'h1DC, // vsavh
            12'h1E7, // vsavj
            12'h343, // vsav
            12'hF04, // vsavu
            12'h0EE, // vsavb
            12'hF0E, // ringdesta
            12'hF88, // ringdesth
            12'hF3C, // ringdest
            12'h1C4, // smbomb
            12'hEC5, // sgemfa
            12'hE42, // sgemfh
            12'hE70, // sgemf
            12'hE43, // pfghtj
            // 30th April
            12'h177, // msha
            12'h04A, // mshb
            12'h271, // mshh
            12'h25C, // mshj
            12'h077, // msh
            12'h16C, // mshu
            12'h490, // mshvsfa
            12'h10A, // mshvsfb
            12'h054, // mshvsfh
            12'h1A3, // mshvsfj
            12'hFC2, // mshvsf
            12'h40F, // mshvsfu
            12'h1EC, // cybotsj
            12'h12F, // cybots
            12'h10F, // cybotsu
            // Beta 11
            12'h22C, // mvsca
            12'h203, // mvscb
            12'h270, // mvsch
            12'h2B7, // mvscj
            12'h34E, // mvsc
            12'h0F2, // mvscu
            12'hD62, // vsav2
            12'hFC7  // vhunt2
            : betang <= 0;
            default:
            betang <= 1;
        endcase
        // if( last_din_we && !din_we )
        //     $display("%X -> %x", raw, cfg );
    end
end

assign key      = cfg[63:0];
assign addr_rng = cfg[159:144];

assign cfg={
raw[ 10], raw[ 11], raw[ 12], raw[ 13], raw[ 14], raw[ 15], raw[  0], raw[  1],
raw[  2], raw[  3], raw[  4], raw[  5], raw[  6], raw[  7], raw[152], raw[153],
raw[ 26], raw[ 27], raw[ 28], raw[ 29], raw[ 30], raw[ 31], raw[ 16], raw[ 17],
raw[ 18], raw[ 19], raw[ 20], raw[ 21], raw[ 22], raw[ 23], raw[  8], raw[  9],
raw[ 42], raw[ 43], raw[ 44], raw[ 45], raw[ 46], raw[ 47], raw[ 32], raw[ 33],
raw[ 34], raw[ 35], raw[ 36], raw[ 37], raw[ 38], raw[ 39], raw[ 24], raw[ 25],
raw[ 58], raw[ 59], raw[ 60], raw[ 61], raw[ 62], raw[ 63], raw[ 48], raw[ 49],
raw[ 50], raw[ 51], raw[ 52], raw[ 53], raw[ 54], raw[ 55], raw[ 40], raw[ 41],
raw[ 74], raw[ 75], raw[ 76], raw[ 77], raw[ 78], raw[ 79], raw[ 64], raw[ 65],
raw[ 66], raw[ 67], raw[ 68], raw[ 69], raw[ 70], raw[ 71], raw[ 56], raw[ 57],
raw[ 90], raw[ 91], raw[ 92], raw[ 93], raw[ 94], raw[ 95], raw[ 80], raw[ 81],
raw[ 82], raw[ 83], raw[ 84], raw[ 85], raw[ 86], raw[ 87], raw[ 72], raw[ 73],

// Keys 1
raw[122], raw[123], raw[124], raw[125], raw[126], raw[127], raw[112], raw[113],
raw[114], raw[115], raw[116], raw[117], raw[118], raw[119], raw[104], raw[105],
raw[106], raw[107], raw[108], raw[109], raw[110], raw[111], raw[ 96], raw[ 97],
raw[ 98], raw[ 99], raw[100], raw[101], raw[102], raw[103], raw[ 88], raw[ 89],

// Key 0
raw[154], raw[155], raw[156], raw[157], raw[158], raw[159], raw[144], raw[145],
raw[146], raw[147], raw[148], raw[149], raw[150], raw[151], raw[136], raw[137],
raw[138], raw[139], raw[140], raw[141], raw[142], raw[143], raw[128], raw[129],
raw[130], raw[131], raw[132], raw[133], raw[134], raw[135], raw[120], raw[121]
}
`ifdef BETA
    | {150'd0, {10{betang}}};
`else
    ;
`endif


endmodule