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


module jtcps2_obj_table(
    input              rst,
    input              clk,
    input              flip,

    input      [ 8:0]  vrender, // 1 line ahead of vdump
    input              start,

    // interface with frame table
    output reg [11:0]  frame_addr,
    input      [15:0]  frame_data,
    input              frame_ok,

    // interface with renderer
    output reg         dr_start,
    input              dr_idle,

    output reg [15:0]  dr_code,
    output reg [15:0]  dr_attr,
    output reg [ 8:0]  dr_hpos
);

reg  [ 9:0] mapper_in;
reg  [ 8:0] vrenderf;

reg  [15:0] obj_code, obj_attr, obj_x, obj_y;
reg  [15:0] last_x, last_y, last_code, last_attr;
wire [15:0] eff_x;

wire  repeated = (obj_x==last_x) && (obj_y==last_y) &&
                 (obj_code==last_code) && (obj_attr==last_attr);

reg         first, done, inzone;
wire [ 3:0] tile_n, tile_m;
reg  [ 3:0] n, npos, m, mflip, vsub;  // tile expansion n==horizontal, m==verital
wire        vflip, inzone_lsb;
wire [15:0] match;
reg  [ 2:0] wait_cycle;
reg         last_tile;
reg         sdram_wait;
wire        rom_good;

assign      tile_m     = obj_attr[15:12];
assign      tile_n     = obj_attr[11: 8];
assign      vflip      = obj_attr[6];
wire        hflip      = obj_attr[5];
//          pal        = obj_attr[4:0];
assign      eff_x      = obj_x + { 1'b0, npos, 4'd0}; // effective x value for multi tile objects
assign      rom_good   = !sdram_wait && frame_ok;

reg  [15:0] code_mn;
reg  [ 4:0] st;

generate
    genvar mgen;
    for( mgen=0; mgen<16;mgen=mgen+1) begin : obj_matches
        jtcps1_obj_match #(mgen) u_match(
            .clk    ( clk           ),
            .tile_m ( tile_m        ),
            .vrender( vrenderf      ),
            .obj_y  (   obj_y[8:0]  ),
            .match  ( match[mgen]   )
        );
    end
endgenerate

always @(*) begin
    inzone = match!=16'd0;
    vsub = vrenderf-obj_y;
    vsub = vsub ^ {4{vflip}};
    // which m won?
    case( match )
        16'h1:     m = 0;
        16'h2:     m = 1;
        16'h4:     m = 2;
        16'h8:     m = 3;

        16'h10:    m = 4;
        16'h20:    m = 5;
        16'h40:    m = 6;
        16'h80:    m = 7;

        16'h100:   m = 8;
        16'h200:   m = 9;
        16'h400:   m = 10;
        16'h800:   m = 11;

        16'h10_00: m = 12;
        16'h20_00: m = 13;
        16'h40_00: m = 14;
        16'h80_00: m = 15;
        default: m=0;
    endcase
    mflip = tile_m-m;
end

always @(*) begin
    case( {tile_m!=4'd0, tile_n!=4'd0 } )
        2'b00: code_mn = obj_code;
        2'b01: code_mn = { obj_code[15:4], obj_code[3:0]+n };
        2'b10: code_mn = { obj_code[15:8],
                           obj_code[7:4]+ (vflip ? mflip : m),
                           obj_code[3:0] };
        2'b11: code_mn = { obj_code[15:8],
                           obj_code[7:4]+ (vflip ? mflip : m),
                           obj_code[3:0]+n };
    endcase
end

always @(posedge clk, posedge rst) begin
    if( rst ) begin
        frame_addr <= ~12'd0;
        st         <= 0;
        done       <= 1'b0;
        first      <= 1'b1;
        obj_attr   <= 16'd0;
        obj_x      <= 16'd0;
        obj_y      <= 16'd0;
        dr_start   <= 0;
        dr_code    <= 16'h0;
        dr_attr    <= 16'h0;
        dr_hpos    <=  9'd0;
        sdram_wait <= 0;
    end else begin
        if( rom_good ) st <= st+5'd1;
        sdram_wait <= 0;
        case( st )
            0: begin
                if( !start ) begin
                    st       <= 5'd0;
                    dr_start <= 0;
                end else begin
                    frame_addr <= ~12'd0;
                    sdram_wait <= 0;
                    last_tile  <= 1'b0;
                    done       <= 0;
                    first      <= 1'b1;
                    vrenderf   <= vrender ^ {1'b0,{8{flip}}};
                end
            end
            1: begin
                if( rom_good ) begin
                    frame_addr <= frame_addr-10'd1;
                    sdram_wait <= 1;
                    n          <= 4'd0;
                    // npos is the X offset of the tile. When the sprite is flipped
                    // npos order is reversed
                    npos       <= frame_data[5] /* flip */ ? frame_data[11: 8] /* tile_n */ : 4'd0;
                    last_attr  <= obj_attr;
                    obj_attr   <= frame_data;
                    //if( frame_data[15:8] == 8'hff ) st<=10; // end of valid table entries
                end
                if(last_tile) begin
                    st   <= 0; // done
                end
            end
            2: if( rom_good) begin
                last_code  <= obj_code;
                obj_code   <= frame_data;
                mapper_in  <= frame_data[15:6];
                frame_addr <= frame_addr-10'd1;
                sdram_wait <= 1;
            end
            3: if( rom_good) begin
                last_y     <= obj_y;
                obj_y      <= frame_data;
                frame_addr <= frame_addr-10'd1;
                sdram_wait <= 1;
            end
            4: if( rom_good) begin
                // Note that obj_code uses "offset", which was calculated with the
                // frame_data value of st 2, but because the mapper takes an extra
                // clock cycle to produce the output, the result is collected here
                last_x     <= obj_x;
                obj_x      <= { 7'd0, frame_data[8:0] };
                //frame_addr <= frame_addr-10'd1;
                if( frame_addr[11:2]==10'd0 ) last_tile <= 1'b1;
            end
            5: begin // check whether sprite is visible
                if( (repeated && !first ) || !inzone ) begin
                    st<= 1; // try next one
                end
                else begin
                    first <= 1'b0;
                end
            end
            6: begin
                if( !dr_idle ) begin
                    st <= 6;
                end else begin
                    dr_attr <= { 4'd0, vsub, obj_attr[7:0] };
                    dr_code <= code_mn;
                    dr_hpos <= eff_x[8:0] - 9'd1;
                    dr_start <= 1;
                end
            end
            7: begin
                dr_start <= 0;
                st <= 8;
            end
            9: begin
                    if( n == tile_n ) begin
                        st <= 1; // next element
                    end else begin // prepare for next tile
                        n <= n + 4'd1;
                        npos <= hflip ? npos-4'd1 : npos+4'd1;
                        st <= 6;
                    end
                //end
            end
        endcase
    end
end

endmodule
