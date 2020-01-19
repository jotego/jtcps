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
    Date: 28-2-2019 */

`timescale 1ns/1ps

// Three types of slots:
// 0 = read only    ( default )
// 1 = write only
// 2 = R/W

module jtframe_sdram_rq #(parameter AW=18, DW=8, TYPE=0 )(
    input               rst,
    input               clk,
    input               cen,
    input [AW-1:0]      addr,
    input [  21:0]      offset,     // It is not supposed to change during game play
    input               addr_ok,    // signals that value in addr is valid
    input [31:0]        din,
    input               din_ok,
    input               wrin,   
    input               we,
    output reg          req,
    output reg          req_rnw,
    output reg          data_ok,    // strobe that signals that data is ready
    output     [21:0]   sdram_addr,
    input [DW-1:0]      wrdata ,
    output reg [DW-1:0] dout
);

reg [AW-1:0] addr_req;
wire  [21:0] size_ext   = { {22-AW{1'b0}}, addr_req };
assign sdram_addr = (DW==8?(size_ext>>1):size_ext ) + offset;

reg [AW-1:0] cached_addr0;
reg [AW-1:0] cached_addr1;
reg [31:0]   cached_data0;
reg [31:0]   cached_data1;
reg deleterus;
reg [1:0]    subaddr;
reg init;
reg hit0, hit1;

wire data_match = dout === wrdata || init;

always @(*) begin
    case(DW)
        8:  addr_req = {addr[AW-1:2],2'b0};
        16: addr_req = {addr[AW-1:1],1'b0};
        32: addr_req = addr;
    endcase
    if( TYPE==1 ) begin
        hit0 = (addr_req === cached_addr0) && data_match;
        hit1 = (addr_req === cached_addr1) && data_match;    
    end else begin
        hit0 = addr_req === cached_addr0;
        hit1 = addr_req === cached_addr1;    
    end
    req = TYPE == 1 ? addr_ok && !(hit0 || hit1)
        : init || ( !(hit0 || hit1) && addr_ok && !we);
    case(TYPE)
        0:  req_rnw = 1'b1; // read only
        1:  req_rnw = 1'b0; // write only
    endcase
end

// reg [1:0] ok_sr;
wire [31:0] cache_din = TYPE==0 ? din : wrdata;

always @(posedge clk, posedge rst)
    if( rst ) begin
        init      <= 1'b1;
        deleterus <= 1'b0;  // signals which cached data is to be overwritten next time
        cached_data0 <= 32'd0;
        cached_data1 <= 32'd0;
    end else begin
        data_ok <= !init && addr_ok && ( hit0 || hit1 || (din_ok&&we));
        if( we && din_ok ) begin
            if( init ) begin
                cached_data0 <= cache_din;
                cached_addr0 <= addr_req;
                cached_data1 <= cache_din;
                cached_addr1 <= addr_req;
            end else begin
                if( deleterus ) begin
                    cached_data1 <= cache_din;
                    cached_addr1 <= addr_req;
                end else begin
                    cached_data0 <= cache_din;
                    cached_addr0 <= addr_req;
                end
                deleterus <= ~deleterus;
            end
            init <= 1'b0;
        end
    end

always @(*) begin
    subaddr[1] = addr[1];
    subaddr[0] =  addr[0];
end

// data_mux selects one of two cache registers
// but if we are getting fresh data, it selects directly the new data
// this saves one clock cycle at the expense of more LUTs
wire [31:0] data_mux;

if (TYPE==0) begin
    assign data_mux = (we&&din_ok) ? din :
        (hit0 ? cached_data0 : cached_data1);
end else begin
    assign data_mux = hit0 ? cached_data0 : cached_data1;
end

generate
    if(DW==8) begin
        always @(*)
        case( subaddr )
            2'd0: dout = data_mux[ 7: 0];
            2'd1: dout = data_mux[15: 8];
            2'd2: dout = data_mux[23:16];
            2'd3: dout = data_mux[31:24];
        endcase
    end else if(DW==16) begin
        always @(*)
        case( subaddr[0] )
                1'd0: dout = data_mux[15:0];
                1'd1: dout = data_mux[31:16];
        endcase
    end else always @(*) dout = data_mux;
endgenerate

endmodule // jtframe_romrq