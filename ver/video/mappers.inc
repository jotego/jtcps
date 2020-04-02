game_forgottn: begin
        // Bank 0 size 0x08000
        bank_b[0] <=  ( layer==OBJ  ) /* 0 - 7fff */  ||
         ( layer==SCR1  && code[15:10]<=7'h7f) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank_b[1] <=  ( layer==SCR2  && code[15:9]<=7'h7f) /* 0 - 1ffff */  ||
         ( layer==SCR3  && code[13:7]<=7'h7f && code[15:14]==2'b00 ) /* 0 - 1ffff */ ;
        bank_b[2] <= 1'b0;
        bank_b[3] <= 1'b0;
        set_used  <= 1'b1;
    end
game_ghouls: begin
        // Bank 1 size 0x02000
        bank_b[1] <=  ( layer==SCR3  && code[13:7]>=7'h20 && code[13:7]<=7'h2f && code[15:14]==2'b00 ) /* 8000 - bfff */ ;
        // Bank 2 size 0x02000
        bank_b[2] <=  ( layer==OBJ   && code[15:9]>=7'h8 && code[15:9]<=7'hf) /* 2000 - 3fff */ ;
        // Bank 0 size 0x08000
        bank_b[0] <=  ( layer==SCR2  && code[15:9]<=7'h7f) /* 0 - 1ffff */ 
        ||  ( layer==SCR1  && code[15:10]<=7'h7f) /* 0 - 1ffff */ 
        ||  ( layer==SCR3  && code[13:7]<=7'h7f && code[15:14]==2'b00 ) /* 0 - 1ffff */  ||
         ( layer==OBJ   && code[15:9]<=7'h7) /* 0 - 1fff */ ;
        bank_b[3] <= 1'b0;
        set_used  <= 1'b1;
    end
game_daimakai: begin
        // Bank 0 size 0x04000
        bank_a[0] <=  ( layer==OBJ   && code[15:9]<=7'h7) /* 0 - 1fff */  ||
         ( layer==SCR1  && code[15:10]>=7'h8 && code[15:10]<=7'hf) /* 2000 - 3fff */ ;
        // Bank 1 size 0x04000
        bank_a[1] <=  ( layer==SCR2  && code[15:9]>=7'h10) /* 4000 - 7fff */ ;
        // Bank 2 size 0x02000
        bank_a[2] <=  ( layer==SCR3  && code[13:7]<=7'h7f && code[15:14]==2'b00 ) /* 0 - 1ffff */ ;
        // Bank 3 size 0x02000
        bank_a[3] <=  ( layer==OBJ   && code[15:9]>=7'h8 && code[15:9]<=7'hf) /* 2000 - 3fff */ ;
        set_used  <= 1'b0;
    end
game_daimakair: begin
        // Bank 0 size 0x08000
        bank_a[0] <=  ( layer==OBJ   && code[15:9]<=7'h7) /* 0 - 1fff */  ||
         ( layer==SCR1  && code[15:10]>=7'h8 && code[15:10]<=7'hb) /* 2000 - 2fff */  ||
         ( layer==SCR2  && code[15:9]>=7'h10) /* 4000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank_a[1] <=  ( layer==SCR3  && code[13:7]<=7'h7f && code[15:14]==2'b00 ) /* 0 - 1ffff */  ||
         ( layer==OBJ   && code[15:9]>=7'h8 && code[15:9]<=7'hf) /* 2000 - 3fff */ ;
        bank_a[2] <= 1'b0;
        bank_a[3] <= 1'b0;
        set_used  <= 1'b0;
    end
game_strider: begin
        // Bank 0 size 0x08000
        bank_a[0] <=  ( layer==OBJ   && code[15:9]<=7'h13) /* 0 - 4fff */  ||
         ( layer==SCR2  && code[15:9]>=7'h10) /* 4000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank_a[1] <=  ( layer==SCR3  && code[15:14]==2'b00 ) /* 0 - 7fff */  ||
         ( layer==SCR1  && code[15:10]>=7'h1c) /* 7000 - 7fff */ ;
        bank_a[2] <= 1'b0;
        bank_a[3] <= 1'b0;
        set_used  <= 1'b0;
    end
game_dynwar: begin
        // Bank 0 size 0x04000
        bank_b[0] <=  ( layer==OBJ   && code[15:9]<=7'hf) /* 0 - 3fff */ ;
        // Bank 1 size 0x04000
        bank_b[1] <=  ( layer==OBJ   && code[15:9]>=7'h10 && code[15:9]<=7'h17) /* 4000 - 5fff */  ||
         ( layer==SCR1  && code[15:10]>=7'h18) /* 6000 - 7fff */ ;
        // Bank 2 size 0x04000
        bank_b[2] <=  ( layer==SCR3  && code[13:7]<=7'hf && code[15:14]==2'b00 ) /* 0 - 3fff */ ;
        // Bank 3 size 0x04000
        bank_b[3] <=  ( layer==SCR2  && code[15:9]>=7'h10) /* 4000 - 7fff */ ;
        set_used  <= 1'b1;
    end
game_willow: begin
        // Bank 0 size 0x08000
        bank_a[0] <=  ( layer==OBJ   && code[15:9]<=7'h13) /* 0 - 4fff */  ||
         ( layer==SCR3  && code[13:7]>=7'h14 && code[13:7]<=7'h1b && code[15:14]==2'b00 ) /* 5000 - 6fff */  ||
         ( layer==SCR1  && code[15:10]>=7'h1c) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank_a[1] <=  ( layer==SCR2  && code[15:9]<=7'hf) /* 0 - 3fff */ ;
        bank_a[2] <= 1'b0;
        bank_a[3] <= 1'b0;
        set_used  <= 1'b0;
    end
game_unsquad: begin
        // Bank 0 size 0x08000
        bank_a[0] <=  ( layer==OBJ   && code[15:9]<=7'hb) /* 0 - 2fff */  ||
         ( layer==SCR1  && code[15:10]>=7'hc && code[15:10]<=7'hf) /* 3000 - 3fff */  ||
         ( layer==SCR2  && code[15:9]>=7'h10 && code[15:9]<=7'h17) /* 4000 - 5fff */  ||
         ( layer==SCR3  && code[13:7]>=7'h18 && code[15:14]==2'b00 ) /* 6000 - 7fff */ ;
        bank_a[1] <= 1'b0;
        bank_a[2] <= 1'b0;
        bank_a[3] <= 1'b0;
        set_used  <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank_b[0] <=  ( layer==OBJ   && code[15:9]<=7'h10) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:10]>=7'h11 && code[15:10]<=7'h12) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:7]>=7'h13 && code[13:7]<=7'h17 && code[15:14]==2'b00 ) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:9]>=7'h18) /* 6000 - 7fff */ ;
        bank_b[1] <= 1'b0;
        bank_b[2] <= 1'b0;
        bank_b[3] <= 1'b0;
        set_used  <= 1'b1;
    end
game_1941: begin
        // Bank 0 size 0x08000
        bank_b[0] <=  ( layer==OBJ   && code[15:9]<=7'h7) /* 0 - 1fff */  ||
         ( layer==SCR3  && code[13:7]>=7'h8 && code[13:7]<=7'hf && code[15:14]==2'b00 ) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:10]>=7'h10 && code[15:10]<=7'h11) /* 4000 - 47ff */  ||
         ( layer==SCR2  && code[15:9]>=7'h12) /* 4800 - 7fff */ ;
        bank_b[1] <= 1'b0;
        bank_b[2] <= 1'b0;
        bank_b[3] <= 1'b0;
        set_used  <= 1'b1;
    end
game_mercs: begin
        // Bank 0 size 0x08000
        bank_b[0] <=  ( layer==SCR1  && code[15:10]<=7'h2) /* 0 - bff */  ||
         ( layer==SCR2  && code[15:9]>=7'h3 && code[15:9]<=7'he) /* c00 - 3bff */  ||
         ( layer==SCR3  && code[13:7]>=7'hf && code[13:7]<=7'h12 && code[15:14]==2'b00 ) /* 3c00 - 4bff */  ||
         ( layer==OBJ   && code[15:9]>=7'h13) /* 4c00 - 7fff */ ;
        // Bank 1 size 0x04000
        bank_b[1] <=  ( layer==OBJ   && code[15:9]>=7'h20 && code[15:9]<=7'h29) /* 8000 - a7ff */  ||
         ( layer==SCR2  && code[15:9]>=7'h2a && code[15:9]<=7'h2d) /* a800 - b7ff */  ||
         ( layer==SCR3  && code[13:7]>=7'h2e && code[13:7]<=7'h2f && code[15:14]==2'b00 ) /* b800 - bfff */ ;
        bank_b[2] <= 1'b0;
        bank_b[3] <= 1'b0;
        set_used  <= 1'b1;
    end
game_mtwins: begin
        // Bank 0 size 0x08000
        bank_b[0] <=  ( layer==OBJ   && code[15:9]<=7'hb) /* 0 - 2fff */  ||
         ( layer==SCR1  && code[15:10]>=7'hc && code[15:10]<=7'hf) /* 3000 - 3fff */  ||
         ( layer==SCR2  && code[15:9]>=7'h10 && code[15:9]<=7'h1b) /* 4000 - 6fff */  ||
         ( layer==SCR3  && code[13:7]>=7'h1c && code[15:14]==2'b00 ) /* 7000 - 7fff */ ;
        bank_b[1] <= 1'b0;
        bank_b[2] <= 1'b0;
        bank_b[3] <= 1'b0;
        set_used  <= 1'b1;
    end
game_msword: begin
        // Bank 0 size 0x08000
        bank_b[0] <=  ( layer==OBJ   && code[15:9]<=7'hf) /* 0 - 3fff */  ||
         ( layer==SCR1  && code[15:10]>=7'h10 && code[15:10]<=7'h13) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:9]>=7'h14 && code[15:9]<=7'h1b) /* 5000 - 6fff */  ||
         ( layer==SCR3  && code[13:7]>=7'h1c && code[15:14]==2'b00 ) /* 7000 - 7fff */ ;
        bank_b[1] <= 1'b0;
        bank_b[2] <= 1'b0;
        bank_b[3] <= 1'b0;
        set_used  <= 1'b1;
    end
game_cawing: begin
        // Bank 0 size 0x08000
        bank_b[0] <=  ( layer==OBJ   && code[15:9]<=7'hb) /* 0 - 2fff */  ||
         ( layer==SCR2  && code[15:9]<=7'hb) /* 0 - 2fff */  ||
         ( layer==SCR3  && code[13:7]>=7'hc && code[13:7]<=7'h13 && code[15:14]==2'b00 ) /* 3000 - 4fff */  ||
         ( layer==SCR1  && code[15:10]>=7'h14 && code[15:10]<=7'h15) /* 5000 - 57ff */  ||
         ( layer==OBJ   && code[15:9]>=7'h16) /* 5800 - 7fff */  ||
         ( layer==SCR2  && code[15:9]>=7'h16) /* 5800 - 7fff */ ;
        bank_b[1] <= 1'b0;
        bank_b[2] <= 1'b0;
        bank_b[3] <= 1'b0;
        set_used  <= 1'b1;
    end
game_nemo: begin
        // Bank 0 size 0x08000
        bank_a[0] <=  ( layer==OBJ   && code[15:9]<=7'hf) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:9]<=7'hf) /* 0 - 3fff */  ||
         ( layer==SCR1  && code[15:10]>=7'h10 && code[15:10]<=7'h11) /* 4000 - 47ff */  ||
         ( layer==OBJ   && code[15:9]>=7'h12 && code[15:9]<=7'h19) /* 4800 - 67ff */  ||
         ( layer==SCR2  && code[15:9]>=7'h12 && code[15:9]<=7'h19) /* 4800 - 67ff */  ||
         ( layer==SCR3  && code[13:7]>=7'h1a && code[15:14]==2'b00 ) /* 6800 - 7fff */ ;
        bank_a[1] <= 1'b0;
        bank_a[2] <= 1'b0;
        bank_a[3] <= 1'b0;
        set_used  <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank_a[0] <=  ( layer==OBJ  ) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank_a[1] <=  ( layer==OBJ   && code[15:9]>=7'h20 && code[15:9]<=7'h3f) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank_a[2] <=  ( layer==OBJ   && code[15:9]>=7'h40 && code[15:9]<=7'h47) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:7]>=7'h8 && code[13:7]<=7'hf && code[15:14]==2'b00 ) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:10]>=7'h10 && code[15:10]<=7'h13) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:9]>=7'h14) /* 5000 - 7fff */ ;
        bank_a[3] <= 1'b0;
        set_used  <= 1'b0;
    end
game_3wonders: begin
        // Bank 0 size 0x08000
        bank_b[0] <=  ( layer==OBJ   && code[15:9]<=7'h14) /* 0 - 53ff */  ||
         ( layer==SCR1  && code[15:10]>=7'h15 && code[15:10]<=7'h1b) /* 5400 - 6fff */  ||
         ( layer==SCR3  && code[13:7]>=7'h1c && code[15:14]==2'b00 ) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank_b[1] <=  ( layer==SCR3  && code[13:7]<=7'hf && code[15:14]==2'b00 ) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:9]>=7'ha) /* 2800 - 7fff */  ||
         ( layer==OBJ   && code[15:9]>=7'h15) /* 5400 - 7fff */ ;
        bank_b[2] <= 1'b0;
        bank_b[3] <= 1'b0;
        set_used  <= 1'b1;
    end
game_kod: begin
        // Bank 0 size 0x08000
        bank_b[0] <=  ( layer==OBJ  ) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank_b[1] <=  ( layer==OBJ   && code[15:9]>=7'h20 && code[15:9]<=7'h23) /* 8000 - 8fff */  ||
         ( layer==SCR2  && code[15:9]>=7'h24 && code[15:9]<=7'h2f) /* 9000 - bfff */  ||
         ( layer==SCR1  && code[15:10]>=7'h30 && code[15:10]<=7'h35) /* c000 - d7ff */  ||
         ( layer==SCR3  && code[13:7]>=7'h36 && code[13:7]<=7'h3f && code[15:14]==2'b00 ) /* d800 - ffff */ ;
        bank_b[2] <= 1'b0;
        bank_b[3] <= 1'b0;
        set_used  <= 1'b1;
    end
game_captcomm: begin
        // Bank 0 size 0x08000
        bank_b[0] <=  ( layer==OBJ  ) /* 0 - 7fff */  ||
         ( layer==SCR2 ) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank_b[1] <=  ( layer==OBJ   && code[15:9]>=7'h20 && code[15:9]<=7'h3f) /* 8000 - ffff */  ||
         ( layer==SCR1  && code[15:10]>=7'h20 && code[15:10]<=7'h3f) /* 8000 - ffff */  ||
         ( layer==SCR2  && code[15:9]>=7'h20 && code[15:9]<=7'h3f) /* 8000 - ffff */  ||
         ( layer==SCR3  && code[13:7]>=7'h20 && code[13:7]<=7'h3f && code[15:14]==2'b00 ) /* 8000 - ffff */ ;
        bank_b[2] <= 1'b0;
        bank_b[3] <= 1'b0;
        set_used  <= 1'b1;
    end
game_knights: begin
        // Bank 0 size 0x08000
        bank_b[0] <=  ( layer==OBJ  ) /* 0 - 7fff */  ||
         ( layer==SCR2 ) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank_b[1] <=  ( layer==SCR1  && code[15:10]>=7'h20 && code[15:10]<=7'h27) /* 8000 - 9fff */  ||
         ( layer==OBJ   && code[15:9]>=7'h20 && code[15:9]<=7'h33) /* 8000 - cfff */  ||
         ( layer==SCR2  && code[15:9]>=7'h20 && code[15:9]<=7'h33) /* 8000 - cfff */  ||
         ( layer==SCR3  && code[13:7]>=7'h34 && code[13:7]<=7'h3f && code[15:14]==2'b00 ) /* d000 - ffff */ ;
        bank_b[2] <= 1'b0;
        bank_b[3] <= 1'b0;
        set_used  <= 1'b1;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank_a[0] <=  ( layer==OBJ  ) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank_a[1] <=  ( layer==OBJ   && code[15:9]>=7'h20 && code[15:9]<=7'h3f) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank_a[2] <=  ( layer==OBJ   && code[15:9]>=7'h40 && code[15:9]<=7'h47) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:7]>=7'h8 && code[13:7]<=7'hf && code[15:14]==2'b00 ) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:10]>=7'h10 && code[15:10]<=7'h13) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:9]>=7'h14) /* 5000 - 7fff */ ;
        bank_a[3] <= 1'b0;
        set_used  <= 1'b0;
    end
game_cworld2j: begin
        // Bank 0 size 0x08000
        bank_b[0] <=  ( layer==OBJ   && code[15:9]<=7'h1b) /* 0 - 6fff */ 
        ||  ( layer==SCR2  && code[15:9]<=7'h1b) /* 0 - 6fff */  ||
         ( layer==SCR3  && code[13:7]>=7'h1c && code[13:7]<=7'h1d && code[15:14]==2'b00 ) /* 7000 - 77ff */  ||
         ( layer==SCR1  && code[15:10]>=7'h1e) /* 7800 - 7fff */ ;
        bank_b[1] <= 1'b0;
        bank_b[2] <= 1'b0;
        bank_b[3] <= 1'b0;
        set_used  <= 1'b1;
    end
game_varth: begin
        // Bank 0 size 0x08000
        bank_a[0] <=  ( layer==OBJ  ) /* 0 - 7fff */ 
        ||  ( layer==SCR2 ) /* 0 - 7fff */ 
        ||  ( layer==SCR1 ) /* 0 - 7fff */ 
        ||  ( layer==SCR3  && code[15:14]==2'b00 ) /* 0 - 7fff */ ;
        bank_a[1] <= 1'b0;
        bank_a[2] <= 1'b0;
        bank_a[3] <= 1'b0;
        set_used  <= 1'b0;
    end
game_qad: begin
        // Bank 0 size 0x04000
        bank_a[0] <=  ( layer==OBJ   && code[15:9]<=7'hf) /* 0 - 3fff */  ||
         ( layer==SCR1  && code[15:10]<=7'hf) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:9]<=7'hf) /* 0 - 3fff */  ||
         ( layer==SCR3  && code[13:7]<=7'hf && code[15:14]==2'b00 ) /* 0 - 3fff */ ;
        bank_a[1] <= 1'b0;
        bank_a[2] <= 1'b0;
        bank_a[3] <= 1'b0;
        set_used  <= 1'b0;
    end
game_wof: begin
        // Bank 0 size 0x08000
        bank_a[0] <=  ( layer==OBJ  ) /* 0 - 7fff */ 
        ||  ( layer==SCR2 ) /* 0 - 7fff */ 
        ||  ( layer==SCR1 ) /* 0 - 7fff */ 
        ||  ( layer==SCR3  && code[15:14]==2'b00 ) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank_a[1] <=  ( layer==OBJ   && code[15:9]>=7'h20 && code[15:9]<=7'h3f) /* 8000 - ffff */ 
        ||  ( layer==SCR2  && code[15:9]>=7'h20 && code[15:9]<=7'h3f) /* 8000 - ffff */ 
        ||  ( layer==SCR1  && code[15:10]>=7'h20 && code[15:10]<=7'h3f) /* 8000 - ffff */ 
        ||  ( layer==SCR3  && code[13:7]>=7'h20 && code[13:7]<=7'h3f && code[15:14]==2'b00 ) /* 8000 - ffff */ ;
        bank_a[2] <= 1'b0;
        bank_a[3] <= 1'b0;
        set_used  <= 1'b0;
    end
game_sf2hf: begin
        // Bank 0 size 0x08000
        bank_a[0] <=  ( layer==OBJ  ) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank_a[1] <=  ( layer==OBJ   && code[15:9]>=7'h20 && code[15:9]<=7'h3f) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank_a[2] <=  ( layer==OBJ   && code[15:9]>=7'h40 && code[15:9]<=7'h47) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:7]>=7'h8 && code[13:7]<=7'hf && code[15:14]==2'b00 ) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:10]>=7'h10 && code[15:10]<=7'h13) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:9]>=7'h14) /* 5000 - 7fff */ ;
        bank_a[3] <= 1'b0;
        set_used  <= 1'b0;
    end
game_dino: begin
        // Bank 0 size 0x08000
        bank_b[0] <=  ( layer==SCR1  && code[15:10]<=7'h3) /* 0 - fff */  ||
         ( layer==OBJ   && code[15:9]>=7'h4) /* 1000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank_b[1] <=  ( layer==OBJ   && code[15:9]>=7'h20 && code[15:9]<=7'h37) /* 8000 - dfff */ 
        ||  ( layer==SCR2  && code[15:9]>=7'h20 && code[15:9]<=7'h37) /* 8000 - dfff */  ||
         ( layer==SCR3  && code[13:7]>=7'h38 && code[13:7]<=7'h3f && code[15:14]==2'b00 ) /* e000 - ffff */ ;
        bank_b[2] <= 1'b0;
        bank_b[3] <= 1'b0;
        set_used  <= 1'b1;
    end
game_punisher: begin
        // Bank 0 size 0x08000
        bank_a[0] <=  ( layer==SCR1  && code[15:10]<=7'h3) /* 0 - fff */  ||
         ( layer==OBJ   && code[15:9]>=7'h4) /* 1000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank_a[1] <=  ( layer==OBJ   && code[15:9]>=7'h20 && code[15:9]<=7'h36) /* 8000 - dbff */ 
        ||  ( layer==SCR2  && code[15:9]>=7'h20 && code[15:9]<=7'h36) /* 8000 - dbff */  ||
         ( layer==SCR3  && code[13:7]>=7'h37 && code[13:7]<=7'h3f && code[15:14]==2'b00 ) /* dc00 - ffff */ ;
        bank_a[2] <= 1'b0;
        bank_a[3] <= 1'b0;
        set_used  <= 1'b0;
    end
game_slammast: begin
        // Bank 0 size 0x08000
        bank_a[0] <=  ( layer==SCR1  && code[15:10]<=7'h3) /* 0 - fff */  ||
         ( layer==OBJ   && code[15:9]>=7'h4) /* 1000 - 7fff */ 
        ||  ( layer==SCR2  && code[15:9]>=7'h4) /* 1000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank_a[1] <=  ( layer==OBJ   && code[15:9]>=7'h20 && code[15:9]<=7'h3f) /* 8000 - ffff */ 
        ||  ( layer==SCR2  && code[15:9]>=7'h20 && code[15:9]<=7'h3f) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank_a[2] <=  ( layer==OBJ   && code[15:9]>=7'h40 && code[15:9]<=7'h59) /* 10000 - 167ff */ 
        ||  ( layer==SCR2  && code[15:9]>=7'h40 && code[15:9]<=7'h59) /* 10000 - 167ff */  ||
         ( layer==SCR3  && code[13:7]>=7'h5a && code[13:7]<=7'h5f && code[15:14]==2'b00 ) /* 16800 - 17fff */ ;
        bank_a[3] <= 1'b0;
        set_used  <= 1'b0;
    end
game_mbombrd: begin
        // Bank 0 size 0x08000
        bank_b[0] <=  ( layer==SCR1  && code[15:10]<=7'h3) /* 0 - fff */  ||
         ( layer==OBJ   && code[15:9]>=7'h4) /* 1000 - 7fff */ 
        ||  ( layer==SCR2  && code[15:9]>=7'h4) /* 1000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank_b[1] <=  ( layer==OBJ   && code[15:9]>=7'h20 && code[15:9]<=7'h3f) /* 8000 - ffff */ 
        ||  ( layer==SCR2  && code[15:9]>=7'h20 && code[15:9]<=7'h3f) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank_b[2] <=  ( layer==OBJ   && code[15:9]>=7'h40 && code[15:9]<=7'h59) /* 10000 - 167ff */ 
        ||  ( layer==SCR2  && code[15:9]>=7'h40 && code[15:9]<=7'h59) /* 10000 - 167ff */  ||
         ( layer==SCR3  && code[13:7]>=7'h5a && code[13:7]<=7'h5f && code[15:14]==2'b00 ) /* 16800 - 17fff */ ;
        bank_b[3] <= 1'b0;
        set_used  <= 1'b1;
    end
game_pnickj: begin
        // Bank 0 size 0x08000
        bank_a[0] <=  ( layer==SCR1  && code[15:10]<=7'h3) /* 0 - fff */  ||
         ( layer==OBJ   && code[15:9]>=7'h4 && code[15:9]<=7'h17) /* 1000 - 5fff */ 
        ||  ( layer==SCR2  && code[15:9]>=7'h4 && code[15:9]<=7'h17) /* 1000 - 5fff */  ||
         ( layer==SCR3  && code[13:7]>=7'h18 && code[15:14]==2'b00 ) /* 6000 - 7fff */ ;
        bank_a[1] <= 1'b0;
        bank_a[2] <= 1'b0;
        bank_a[3] <= 1'b0;
        set_used  <= 1'b0;
    end
game_qtono2j: begin
        // Bank 0 size 0x08000
        bank_a[0] <=  ( layer==SCR1  && code[15:10]<=7'h3) /* 0 - fff */  ||
         ( layer==SCR3  && code[13:7]>=7'h4 && code[13:7]<=7'hf && code[15:14]==2'b00 ) /* 1000 - 3fff */  ||
         ( layer==OBJ   && code[15:9]>=7'h10) /* 4000 - 7fff */ 
        ||  ( layer==SCR2  && code[15:9]>=7'h10) /* 4000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank_a[1] <=  ( layer==OBJ   && code[15:9]>=7'h20 && code[15:9]<=7'h3f) /* 8000 - ffff */ 
        ||  ( layer==SCR2  && code[15:9]>=7'h20 && code[15:9]<=7'h3f) /* 8000 - ffff */ ;
        bank_a[2] <= 1'b0;
        bank_a[3] <= 1'b0;
        set_used  <= 1'b0;
    end
game_megaman: begin
        // Bank 0 size 0x08000
        bank_b[0] <=  ( layer==OBJ  ) /* 0 - 7fff */ 
        ||  ( layer==SCR2 ) /* 0 - 7fff */ 
        ||  ( layer==SCR1 ) /* 0 - 7fff */ 
        ||  ( layer==SCR3  && code[15:14]==2'b00 ) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank_b[1] <=  ( layer==OBJ   && code[15:9]>=7'h20 && code[15:9]<=7'h3f) /* 8000 - ffff */ 
        ||  ( layer==SCR2  && code[15:9]>=7'h20 && code[15:9]<=7'h3f) /* 8000 - ffff */ 
        ||  ( layer==SCR1  && code[15:10]>=7'h20 && code[15:10]<=7'h3f) /* 8000 - ffff */ 
        ||  ( layer==SCR3  && code[13:7]>=7'h20 && code[13:7]<=7'h3f && code[15:14]==2'b00 ) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank_b[2] <=  ( layer==OBJ   && code[15:9]>=7'h40 && code[15:9]<=7'h5f) /* 10000 - 17fff */ 
        ||  ( layer==SCR2  && code[15:9]>=7'h40 && code[15:9]<=7'h5f) /* 10000 - 17fff */ 
        ||  ( layer==SCR1  && code[15:10]>=7'h40 && code[15:10]<=7'h5f) /* 10000 - 17fff */ 
        ||  ( layer==SCR3  && code[13:7]>=7'h40 && code[13:7]<=7'h5f && code[15:14]==2'b00 ) /* 10000 - 17fff */ ;
        // Bank 3 size 0x08000
        bank_b[3] <=  ( layer==OBJ   && code[15:9]>=7'h60 && code[15:9]<=7'h7f) /* 18000 - 1ffff */ 
        ||  ( layer==SCR2  && code[15:9]>=7'h60 && code[15:9]<=7'h7f) /* 18000 - 1ffff */ 
        ||  ( layer==SCR1  && code[15:10]>=7'h60 && code[15:10]<=7'h7f) /* 18000 - 1ffff */ 
        ||  ( layer==SCR3  && code[13:7]>=7'h60 && code[13:7]<=7'h7f && code[15:14]==2'b00 ) /* 18000 - 1ffff */ ;
        set_used  <= 1'b1;
    end
game_pokonyan: begin
        // Bank 0 size 0x08000
        bank_a[0] <=  ( layer==OBJ   && code[15:9]<=7'hb) /* 0 - 2fff */  ||
         ( layer==SCR1  && code[15:10]>=7'h1c) /* 7000 - 7fff */  ||
         ( layer==SCR3  && code[13:7]>=7'hc && code[13:7]<=7'hf && code[15:14]==2'b00 ) /* 3000 - 3fff */  ||
         ( layer==SCR2  && code[15:9]>=7'h10 && code[15:9]<=7'h1b) /* 4000 - 6fff */ ;
        bank_a[1] <= 1'b0;
        bank_a[2] <= 1'b0;
        bank_a[3] <= 1'b0;
        set_used  <= 1'b0;
    end
game_pang3: begin
        // Bank 0 size 0x08000
        bank_a[0] <=  ( layer==OBJ  ) /* 0 - 7fff */ 
        ||  ( layer==SCR2 ) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank_a[1] <=  ( layer==OBJ   && code[15:9]>=7'h20 && code[15:9]<=7'h27) /* 8000 - 9fff */ 
        ||  ( layer==SCR2  && code[15:9]>=7'h20 && code[15:9]<=7'h27) /* 8000 - 9fff */  ||
         ( layer==SCR1  && code[15:10]>=7'h28 && code[15:10]<=7'h2f) /* a000 - bfff */  ||
         ( layer==SCR3  && code[13:7]>=7'h30 && code[13:7]<=7'h3f && code[15:14]==2'b00 ) /* c000 - ffff */ ;
        bank_a[2] <= 1'b0;
        bank_a[3] <= 1'b0;
        set_used  <= 1'b0;
    end
