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
    Date: 24-1-2021 */


module jtcps2_obj_scan(
    input              rst,
    input              clk,
    input              flip,

    input      [ 8:0]  vrender, // 1 line ahead of vdump
    input              start,

    input      [ 9:0]  off_x,
    input      [ 9:0]  off_y,

    // interface with frame table
    output reg [ 9:0]  table_addr,
    input      [15:0]  table_x,
    input      [15:0]  table_y,
    input      [15:0]  table_code,
    input      [15:0]  table_attr,

    // interface with renderer
    output reg         dr_start,    // dr for "draw"
    input              dr_idle,

    output reg [15:0]  dr_code,
    output reg [15:0]  dr_attr,
    output reg [ 8:0]  dr_hpos,
    output reg [ 2:0]  dr_prio,
    output reg [ 1:0]  dr_bank
);

reg  [ 9:0] mapper_in;
reg  [ 8:0] vrenderf;

reg  [ 9:0] obj_y, obj_x;
wire [15:0] code_mn;
wire [ 9:0] eff_x;
wire [ 1:0] obj_bank;
wire [ 2:0] prio;

reg         done;
wire [ 3:0] tile_n, tile_m;
reg  [ 3:0] n, npos, m;  // tile expansion n==horizontal, m==vertical
wire [ 3:0] vsub;
wire        inzone, vflip;
reg  [ 2:0] wait_cycle;
reg         last_tile;

jtcps1_obj_tile_match u_tile_match(
    .clk        ( clk       ),

    .obj_code   ( table_code),
    .tile_m     ( tile_m    ),
    .tile_n     ( tile_n    ),
    .n          ( n         ),

    .vflip      ( vflip     ),
    .vrenderf   ( vrenderf  ),
    .obj_y      ( obj_y     ),

    .vsub       ( vsub      ),
    .inzone     ( inzone    ),
    .code_mn    ( code_mn   )
);

assign      prio       = table_x[15:13];
assign      obj_bank   = table_y[14:13];
assign      tile_m     = table_attr[15:12];
assign      tile_n     = table_attr[11: 8];
assign      vflip      = table_attr[6];
wire        hflip      = table_attr[5];
//          pal        = table_attr[4:0];
assign      eff_x      = obj_x + { 1'b0, npos, 4'd0}; // effective x value for multi tile objects

reg  [ 4:0] st;


reg last_start;
reg newline;

always @(posedge clk, posedge rst) begin
    if( rst ) begin
        table_addr <= 11'd0;
        st         <= 0;
        dr_start   <= 0;
        dr_code    <= 16'h0;
        dr_attr    <= 16'h0;
        dr_hpos    <=  9'd0;
        newline    <= 0;
        last_start <= 0;
    end else begin
        last_start <= start;
        st <= st+5'd1;
        case( st )
            0: begin
                table_addr <= 10'd0;
                if( !newline ) begin
                    st       <= 5'd0;
                    dr_start <= 0;
                end else begin
                    newline    <= 0;
                    wait_cycle <= 3'b001;
                    last_tile  <= 1'b0;
                    vrenderf   <= vrender ^ {1'b0,{8{flip}}};
                end
            end
            1: begin
                wait_cycle <= { 1'b0, wait_cycle[2:1] };
                dr_start   <= 0;
                if( &table_addr )
                    last_tile <= 1;
                else
                    table_addr <= table_addr+10'd1;

                if( !wait_cycle[0] ) begin
                    n          <= 4'd0;
                    // npos is the X offset of the tile. When the sprite is flipped
                    // npos order is reversed
                    npos       <= table_attr[5] /* flip */ ? table_attr[11: 8] /* tile_n */ : 4'd0;
                    if( table_y[15] || table_attr[15:8]==8'hff ) begin
                        st<=0;  // done
                    end
                    else begin
                        obj_y      <= table_y[9:0] + 10'h10 - (table_attr[7] ? 10'd0 : off_y);
                        obj_x      <= table_x[9:0] + 10'h40 - (table_attr[7] ? 10'd0 : off_x);
                        wait_cycle <= 3'b011; // leave it ready for next round
                        table_addr <= table_addr - 10'd1; // undo
                    end
                end else begin
                    st<= last_tile ? 0 : 1;
                end
            end
            4: begin // check whether sprite is visible
                if( !inzone ) begin
                    st <= last_tile ? 0 : 1; // next element
                    //table_addr <= table_addr+10'd1;
                end else begin
                    if( !dr_idle ) begin
                        st <= 4;
                    end else begin
                        dr_attr  <= { 4'd0, vsub, table_attr[7:0] };
                        dr_code  <= code_mn;
                        dr_hpos  <= eff_x - 9'd1;
                        dr_prio  <= prio;
                        dr_bank  <= obj_bank;
                        dr_start <= ~eff_x[9];
                    end
                end
            end
            5: begin
                dr_start <= 0;
                if( n == tile_n ) begin
                    st <= last_tile ? 0 : 1; // next element
                end else begin // prepare for next tile
                    n    <= n + 4'd1;
                    npos <= hflip ? npos-4'd1 : npos+4'd1;
                    st   <= 3; // get extra cycles for inzone and dr_idle
                end
            end
        endcase
        // This must be after the case statement
        if( start && !last_start ) begin
            newline <= 1;
            st <= 0;
        end
    end
end

endmodule
