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

module jtcps1_obj_line_table(
    input              rst,
    input              clk,
    input              flip,

    input      [ 8:0]  vrender1, // 2 lines ahead of vdump
    input              start,

    // ROM banks
    input      [ 5:0]  game,
    input      [15:0]  bank_offset,
    input      [15:0]  bank_mask,

    // interface with frame table
    output reg [ 9:0]  frame_addr,
    input      [15:0]  frame_data,

    // interface with renderer
    input      [ 8:0]  line_addr,
    output reg [15:0]  line_data
);

reg  [15:0] line_buf[0:1023]; // up to 128 sprites per line
reg  [ 6:0] line_cnt;
reg  [ 9:0] mapper_in;
reg  [ 8:0] vrenderf;

reg  [15:0] obj_x, obj_y, obj_code, obj_attr;
reg  [15:0] last_x, last_y, last_code, last_attr;
reg  [15:0] pre_code;
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
wire [ 3:0] offset, mask;
wire        unmapped;

assign      tile_m     = obj_attr[15:12];
assign      tile_n     = obj_attr[11: 8];
assign      vflip      = obj_attr[6];
wire        hflip      = obj_attr[5];
//          pal        = obj_attr[4:0];
assign      eff_x      = obj_x + { 1'b0, npos, 4'd0}; // effective x value for multi tile objects

reg  [15:0] code_mn;
reg  [ 4:0] st;

wire [ 9:0] rd_addr = {~vrenderf[0], line_addr};
`ifdef SIMULATION
wire [ 7:0] rd_cnt  = line_addr>>2;
wire [ 1:0] rd_sub  = line_addr[1:0];
`endif

always @(posedge clk, posedge rst) begin
    if( rst )
        line_data <= 16'd0;
    else
        line_data <= line_buf[ rd_addr ];
end

jtcps1_gfx_mappers u_mapper(
    .clk        ( clk             ),
    .rst        ( rst             ),
    .game       ( game            ),
    .bank_offset( bank_offset     ),
    .bank_mask  ( bank_mask       ),

    .layer      ( 3'b0            ),
    .cin        ( mapper_in       ),    // pins 2-9, 11,13,15,17,18

    .offset     ( offset          ),
    .mask       ( mask            ),
    .unmapped   ( unmapped        )
);

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
        frame_addr <= ~10'd0;
        st         <= 0;
        done       <= 1'b0;
        first      <= 1'b1;
        obj_attr   <= 16'd0;
        obj_x      <= 16'd0;
        pre_code   <= 16'd0;
        obj_y      <= 16'd0;
    end else begin
        st <= st+5'd1;
        case( st )
            0: begin
                if( !start ) st<=5'd0;
                else begin
                    frame_addr <= 10'd0;
                    wait_cycle <= 3'b011;
                    last_tile  <= 1'b0;
                    line_cnt   <= 7'd0;
                    done       <= 0;
                    first      <= 1'b1;
                    vrenderf   <= vrender1 ^ {1'b0,{8{flip}}};
                end
            end
            1: begin
                wait_cycle <= { 1'b0, wait_cycle[2:1] };
                frame_addr <= frame_addr-10'd1;
                if( !wait_cycle[0] ) begin
                    n          <= 4'd0;
                    // npos is the X offset of the tile. When the sprite is flipped
                    // npos order is reversed
                    npos       <= frame_data[5] /* flip */ ? frame_data[11: 8] /* tile_n */ : 4'd0;
                    last_attr  <= obj_attr;
                    obj_attr   <= frame_data;
                    wait_cycle <= 3'b011; // leave it ready for next round
                    //if( frame_data[15:8] == 8'hff ) st<=10; // end of valid table entries
                end else st<=1;
                if(last_tile) begin                    
                    st   <= 10; // fill
                end                    
            end
            2: begin
                last_code  <= pre_code;
                pre_code   <= frame_data;
                mapper_in  <= frame_data[15:6];
                frame_addr <= frame_addr-10'd1;
            end
            3: begin
                last_y     <= obj_y;
                obj_y      <= frame_data;
                //frame_addr <= frame_addr-10'd1;
            end
            4: begin
                // Note that obj_code uses "offset", which was calculated with the
                // frame_data value of st 2, but because the mapper takes an extra
                // clock cycle to produce the output, the result is collected here
                last_x     <= obj_x;
                obj_x      <= { 7'd0, frame_data[8:0] };
                //frame_addr <= frame_addr-10'd1;
                if( frame_addr[9:2]==8'd0 ) last_tile <= 1'b1;
                st <= 13;
            end
            13: begin
                obj_code   <= { (pre_code[15:12]&mask) | offset, pre_code[11:0] };
                if( unmapped  || (pre_code[15:12]&~mask) )
                    st <= 1; // skip
                else
                    st <= 5;
            end
            5: begin // check whether sprite is visible
                if( (repeated || !inzone )&& !first) begin
                    st<= 1; // try next one
                end
                else begin
                    first <= 1'b0;
                end
            end
            6: line_buf[ {vrenderf[0], line_cnt, 2'd0} ] <= { 4'd0, vsub, obj_attr[7:0] };
            7: line_buf[ {vrenderf[0], line_cnt, 2'd1} ] <= code_mn;
            8: line_buf[ {vrenderf[0], line_cnt, 2'd2} ] <= eff_x;
            9: begin
                if( line_cnt==7'h7f ) begin
                    st   <= 0; // line full
                    done <= 1;
                end else begin
                    if( eff_x>9'h30 && eff_x<9'd448) line_cnt <= line_cnt+7'd1;
                    if( n == tile_n ) st <= 1; // next element
                    else begin // prepare for next tile
                        n <= n + 4'd1;
                        npos <= hflip ? npos-4'd1 : npos+4'd1;
                        st <= 6;
                    end
                end
            end
            // fill the rest of the table
            10: line_buf[ {vrenderf[0], line_cnt, 2'd0} ] <= ~16'h0;
            11: line_buf[ {vrenderf[0], line_cnt, 2'd1} ] <= ~16'h0;
            12: begin
                line_buf[ {vrenderf[0], line_cnt, 2'd2} ] <= ~16'h0;
                line_cnt <= line_cnt+7'd1;
                if( line_cnt==7'h7f ) begin
                    st   <= 0; // line full
                    done <= 1;
                end
                else st <= 10;
            end
        endcase
    end
end

endmodule
