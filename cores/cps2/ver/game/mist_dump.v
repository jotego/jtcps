`timescale 1ns/1ps

module mist_dump(
    input           VGA_VS,
    input           led,
    input   [31:0]  frame_cnt
);

`ifdef DUMP
`ifndef NCVERILOG // iVerilog:
    initial begin
        // #(200*100*1000*1000);
        $display("DUMP enabled");
        $dumpfile("test.lxt");
    end
    `ifdef LOADROM
    always @(negedge led) if( $time > 20000 ) begin // led = downloading signal
        $display("DUMP starts");
        $dumpvars(0,mist_test);
        $dumpon;
    end
    `else
        `ifdef DUMP_START
        always @(negedge VGA_VS) if( frame_cnt==`DUMP_START ) begin
        `else
            initial begin
        `endif
            $display("DUMP starts");
            `ifdef DEEPDUMP
                $dumpvars(0,mist_test);
            `else
                $dumpvars(1,mist_test.UUT.u_game.u_main);
                $dumpvars(1,mist_test.UUT.u_game);
                $dumpvars(0,mist_test.UUT.u_game.u_sdram_mux);
                $dumpvars(1,mist_test.UUT.u_game.u_video.u_mmr);
                $dumpvars(0,mist_test.UUT.u_frame.u_board.u_sdram);
                $dumpvars(1,mist_test.frame_cnt);
            `endif
            $dumpon;
        end
    `endif
`else // NCVERILOG
    `ifdef DUMP_START
    always @(negedge VGA_VS) if( frame_cnt==`DUMP_START ) begin
    `else
    initial begin
    `endif
        $shm_open("test.shm");
        `ifdef DEEPDUMP
            $display("NC Verilog: will dump all signals");
            $shm_probe(mist_test,"AS");
        `else
            $display("NC Verilog: will dump selected signals");
            $shm_probe(frame_cnt);
            //$shm_probe(UUT.u_game.u_prom_we, "A");
            $shm_probe(UUT.u_game.u_sound, "A");
            $shm_probe(UUT.u_game.u_sound.u_buslock, "A");
            //$shm_probe(UUT.u_game, "A");
            `ifdef LOADROM
                $shm_probe(UUT.u_game.u_sdram, "A");
                $shm_probe(UUT.u_game.u_sdram.u_prom_we, "A");
            `endif
            `ifdef JTFRAME_SDRAM_STATS
            $shm_probe(UUT.u_frame.u_board.u_sdram.u_stats, "A");
            `endif
            //$shm_probe(UUT.u_frame.u_board.u_sdram, "A");
            //$shm_probe(UUT.u_game, "AS");
            `ifdef NOMAIN
                $shm_probe(UUT.u_game.u_video, "AS");
            `else
                $shm_probe(UUT.u_game.u_main, "A");
                $shm_probe(UUT.u_game.u_main.u_dtack, "A");
            `endif
            $shm_probe(UUT.u_game.u_video.u_obj, "AS");
            //$shm_probe(UUT.u_game.u_main.obank);
            //$shm_probe(UUT.u_game.LVBL);
            //$shm_probe(UUT.u_game.LHBL);
            //$shm_probe(UUT.u_game.u_video.u_mmr, "A");

            //$shm_probe(UUT.u_game.u_video.VB );
            //$shm_probe(UUT.u_game.u_video.HB );
            //$shm_probe(UUT.u_game.u_main.vram_cs );
            //$shm_probe(UUT.u_game.u_main, "A" );
            //$shm_probe(UUT.u_game.u_video, "A");
            //$shm_probe(UUT.u_game.u_video.u_obj, "AS");
            //$shm_probe(UUT.u_game.u_video.u_colmix, "AS");

        `endif
    end
`endif
`endif

endmodule // mist_dump