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
    Date: 30-1-2020 */

module jtcps1_prom_we #(
parameter        CPS=1, // 1, 15, or 2
                 REGSIZE=24, // This is defined at _game level
parameter [21:0] CPU_OFFSET =22'h0,
                 SND_OFFSET =22'h0,
                 PCM_OFFSET =22'h0,
                 GFX_OFFSET =22'h0,
                 VRAM_OFFSET=22'h0,
parameter [ 5:0] CFG_BYTE   =6'd39, // location of the byte with encoder information
parameter        EEPROM_AW  = 7
)(
    input                clk,
    input                downloading,
    input      [24:0]    ioctl_addr,    // max 32 MB
    input      [ 7:0]    ioctl_data,
    output     [ 7:0]    ioctl_data2sd,
    input                ioctl_wr,
    input                ioctl_ram,
    output reg [21:0]    prog_addr,
    output     [15:0]    prog_data,
    output reg [ 1:0]    prog_mask, // active low
    output reg [ 1:0]    prog_ba,
    output reg           prog_we,
    output reg           prom_we,   // for Q-Sound internal ROM
    input                prog_rdy,
    output reg           cfg_we,
    output reg           dwnld_busy=0,
    // EEPROM
    output reg [15:0]    dump_din,
    input      [15:0]    dump_dout,
    output     [EEPROM_AW-1:0]    dump_addr,
    output reg           dump_we,
    // Kabuki decoder (CPS 1.5)
    output reg           kabuki_we
);


// The start position header has 16 bytes, from which 6 are actually used and
// 10 are reserved
localparam START_BYTES   = 8,
           START_HEADER  = 16,
           STARTW        = 8*START_BYTES,
           FULL_HEADER   = 25'd64,
           KABUKI_HEADER = 25'd48,
           KABUKI_END    = KABUKI_HEADER + 25'd11;

reg  [STARTW-1:0] starts;
wire       [15:0] snd_start, pcm_start, gfx_start, qsnd_start;
reg        [ 7:0] pre_data;

assign snd_start  = starts[15: 0];
assign pcm_start  = starts[31:16];
assign gfx_start  = starts[47:32];
assign qsnd_start = starts[63:48];
assign prog_data = {2{pre_data}};

wire [24:0] bulk_addr = ioctl_addr - FULL_HEADER; // the header is excluded
wire [24:0] cpu_addr  = bulk_addr ; // the header is excluded
wire [24:0] snd_addr  = bulk_addr - { snd_start[14:0], 10'd0 };
wire [24:0] pcm_addr  = bulk_addr - { pcm_start[14:0], 10'd0 };
wire [24:0] gfx_addr  = bulk_addr - { gfx_start[14:0], 10'd0 };

wire is_cps    = ioctl_addr > 7 && ioctl_addr < (REGSIZE+START_HEADER);
wire is_kabuki = ioctl_addr >= KABUKI_HEADER && ioctl_addr < KABUKI_END;
wire is_cpu    = bulk_addr[24:10] < snd_start;
wire is_snd    = bulk_addr[24:10] < pcm_start  && bulk_addr[24:10] >=snd_start;
wire is_oki    = bulk_addr[24:10] < gfx_start  && bulk_addr[24:10] >=pcm_start;
wire is_gfx    = bulk_addr[24:10] < qsnd_start && bulk_addr[24:10] >=gfx_start;
wire is_qsnd   = ioctl_addr >= FULL_HEADER && bulk_addr[24:10] >=qsnd_start; // Q-Sound ROM

reg  last_dwnldng = 0;
reg  clr_ram = 0; // I have to add a proper reset pin to this module

reg       decrypt, pang3, pang3_bit;
reg [7:0] pang3_decrypt;

// The decryption is literally copied from MAME, it is up to
// the synthesizer to optimize the code. And it will.
always @(*) begin
    if( CPS==1 ) begin
        pang3 = is_cpu && cpu_addr[19] && decrypt  && (cpu_addr[0]^pang3_bit);
        pang3_decrypt =
            (((((((ioctl_data[0] ? 8'h04 : 8'h00)  ^
                  (ioctl_data[1] ? 8'h21 : 8'h00)) ^
                  (ioctl_data[2] ? 8'h01 : 8'h00)) ^
                  (ioctl_data[3] ? 8'h00 : 8'h50)) ^
                  (ioctl_data[4] ? 8'h40 : 8'h00)) ^
                  (ioctl_data[5] ? 8'h06 : 8'h00)) ^
                  (ioctl_data[6] ? 8'h08 : 8'h00)) ^
                  (ioctl_data[7] ? 8'h00 : 8'h88);
    end else begin
        pang3 = 0;
        pang3_decrypt = 8'd0;
    end
end

always @(posedge clk) begin
    if ( ioctl_wr && !ioctl_ram ) begin
        last_dwnldng <= 1;
        clr_ram      <= 0;
        dwnld_busy <= 1;
        pre_data  <= pang3 ?
            pang3_decrypt : ioctl_data;
        prog_mask <= !ioctl_addr[0] ? 2'b10 : 2'b01;
        prog_addr <= is_cpu ? bulk_addr[22:1] + CPU_OFFSET : (
                     is_snd ?  snd_addr[22:1] + SND_OFFSET : (
                     is_oki ?  pcm_addr[22:1] + PCM_OFFSET :
                     is_gfx ?  gfx_addr[22:1] + GFX_OFFSET : {9'd0, bulk_addr[12:0]}));
        prog_ba   <= is_cpu ? 2'd3 : ( is_gfx ? 2'd2 : 2'd1 );
        kabuki_we <= is_kabuki;
        if( ioctl_addr < START_BYTES[24:0] ) begin
            starts  <= { ioctl_data, starts[STARTW-1:8] };
            cfg_we  <= 1'b0;
            prog_we <= 1'b0;
            prom_we <= 1'b0;
        end else begin
            if( is_cps ) begin
                cfg_we    <= 1'b1;
                prog_we   <= 1'b0;
                prom_we   <= 1'b0;
                if( ioctl_addr[5:0] == CFG_BYTE ) {decrypt, pang3_bit} <= ioctl_data[7:6];
            end else if(ioctl_addr>=FULL_HEADER) begin
                cfg_we    <= 1'b0;
                prog_we   <= ~is_qsnd;
                prom_we   <=  is_qsnd;
            end
        end
    end
    else begin
        if( clr_ram ) begin
            if( prog_rdy ) begin
                prog_we   <= 0;
                prog_addr <= prog_addr + 1'd1;
            end else begin
                if( &prog_addr ) begin
                    clr_ram    <= 0;
                    dwnld_busy <= 0;
                end else begin
                    prog_we <= 1;
                end
            end
        end else begin
            if(!downloading || prog_rdy) prog_we  <= 1'b0;
            if( !downloading ) begin
                decrypt   <= 0;
                prom_we   <= 0;
                `ifndef SKIP_RAMCLR
                    if( last_dwnldng ) begin
                        prog_addr    <= 22'd0;
                        prog_ba      <= 2'd0;
                        prog_mask    <= 2'd0;
                        pre_data     <= 8'h0;
                        clr_ram      <= 1;
                        prog_we      <= 1;
                        last_dwnldng <= 0;
                    end
                `else
                    dwnld_busy <= 0;
                `endif
            end
            kabuki_we <= 0;
            cfg_we    <= 0;
        end
    end
end

// EEPROM 16 bit parallel interface <-> 8 bit dump interface
assign dump_addr = ioctl_addr[EEPROM_AW:1];
assign ioctl_data2sd = ioctl_addr[0] ? dump_dout[15:8] : dump_dout[7:0];

initial begin
    dump_we  = 0;
    dump_din = 16'd0;
end

always @(posedge clk) begin
    dump_we <= 0;
    if (ioctl_wr && ioctl_ram) begin
        if(ioctl_addr[0]) begin
            dump_din[15:8] <= ioctl_data;
            dump_we <= 1;
        end else begin
            dump_din[7:0] <= ioctl_data;
        end
    end
end

endmodule