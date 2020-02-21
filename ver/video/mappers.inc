game_forgottn: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1 ) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==SCR2 ) /* 0 - 1ffff */  ||
         ( layer==SCR3 ) /* 0 - 1ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_forgottn: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1 ) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==SCR2 ) /* 0 - 1ffff */  ||
         ( layer==SCR3 ) /* 0 - 1ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_forgottn: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1 ) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==SCR2 ) /* 0 - 1ffff */  ||
         ( layer==SCR3 ) /* 0 - 1ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_forgottn: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1 ) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==SCR2 ) /* 0 - 1ffff */  ||
         ( layer==SCR3 ) /* 0 - 1ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_forgottn: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1 ) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==SCR2 ) /* 0 - 1ffff */  ||
         ( layer==SCR3 ) /* 0 - 1ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_forgottn: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1 ) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==SCR2 ) /* 0 - 1ffff */  ||
         ( layer==SCR3 ) /* 0 - 1ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_forgottn: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1 ) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==SCR2 ) /* 0 - 1ffff */  ||
         ( layer==SCR3 ) /* 0 - 1ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_forgottn: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1 ) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==SCR2 ) /* 0 - 1ffff */  ||
         ( layer==SCR3 ) /* 0 - 1ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_forgottn: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1 ) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==SCR2 ) /* 0 - 1ffff */  ||
         ( layer==SCR3 ) /* 0 - 1ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ghouls: begin
        // Bank 1 size 0x02000
        bank[1] <=  ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hb) /* 8000 - bfff */ ;
        // Bank 2 size 0x02000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h2 && code[15:11]<=5'h3) /* 2000 - 3fff */ ;
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR2 ) /* 0 - 1ffff */ 
        ||  ( layer==SCR1 ) /* 0 - 1ffff */ 
        ||  ( layer==SCR3 ) /* 0 - 1ffff */ 
        ||  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==OBJ   && code[15:11]<=5'h1) /* 0 - 1fff */ ;
        bank[3] <= 1'b0;
    end
game_ghouls: begin
        // Bank 1 size 0x02000
        bank[1] <=  ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hb) /* 8000 - bfff */ ;
        // Bank 2 size 0x02000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h2 && code[15:11]<=5'h3) /* 2000 - 3fff */ ;
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR2 ) /* 0 - 1ffff */ 
        ||  ( layer==SCR1 ) /* 0 - 1ffff */ 
        ||  ( layer==SCR3 ) /* 0 - 1ffff */ 
        ||  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==OBJ   && code[15:11]<=5'h1) /* 0 - 1fff */ ;
        bank[3] <= 1'b0;
    end
game_ghouls: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h1) /* 0 - 1fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h2 && code[15:12]<=5'h3) /* 2000 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
        // Bank 2 size 0x02000
        bank[2] <=  ( layer==SCR3 ) /* 0 - 1ffff */ ;
        // Bank 3 size 0x02000
        bank[3] <=  ( layer==OBJ   && code[15:11]>=5'h2 && code[15:11]<=5'h3) /* 2000 - 3fff */ ;
    end
game_ghouls: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h1) /* 0 - 1fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h2 && code[15:12]<=5'h2) /* 2000 - 2fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3 ) /* 0 - 1ffff */  ||
         ( layer==OBJ   && code[15:11]>=5'h2 && code[15:11]<=5'h3) /* 2000 - 3fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_strider: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==STARS  && code[15:11]<=5'h0) /* 0 - 3ff */  ||
         ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_strider: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==STARS  && code[15:11]<=5'h0) /* 0 - 3ff */  ||
         ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_strider: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==STARS  && code[15:11]<=5'h0) /* 0 - 3ff */  ||
         ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_strider: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
        // Bank 2 size 0x04000
        bank[2] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */ ;
        // Bank 3 size 0x04000
        bank[3] <=  ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h7) /* 4000 - 7fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */ ;
    end
game_strider: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==STARS  && code[15:11]<=5'h0) /* 0 - 3ff */  ||
         ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_dynwar: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h5) /* 4000 - 5fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h6 && code[15:12]<=5'h7) /* 6000 - 7fff */ ;
        // Bank 2 size 0x04000
        bank[2] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */ ;
        // Bank 3 size 0x04000
        bank[3] <=  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
    end
game_dynwar: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h5) /* 4000 - 5fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h6 && code[15:12]<=5'h7) /* 6000 - 7fff */ ;
        // Bank 2 size 0x04000
        bank[2] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */ ;
        // Bank 3 size 0x04000
        bank[3] <=  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
    end
game_dynwar: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h5) /* 4000 - 5fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h6 && code[15:12]<=5'h7) /* 6000 - 7fff */ ;
        // Bank 2 size 0x04000
        bank[2] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */ ;
        // Bank 3 size 0x04000
        bank[3] <=  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
    end
game_dynwar: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h5) /* 4000 - 5fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h6 && code[15:12]<=5'h7) /* 6000 - 7fff */ ;
        // Bank 2 size 0x04000
        bank[2] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */ ;
        // Bank 3 size 0x04000
        bank[3] <=  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
    end
game_willow: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 4fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h5 && code[13:9]<=5'h6) /* 5000 - 6fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR2  && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_willow: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 4fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h5 && code[13:9]<=5'h6) /* 5000 - 6fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR2  && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_willow: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 4fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h5 && code[13:9]<=5'h6) /* 5000 - 6fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR2  && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_willow: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 4fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h5 && code[13:9]<=5'h6) /* 5000 - 6fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR2  && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_unsquad: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h3 && code[15:12]<=5'h3) /* 3000 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h5) /* 4000 - 5fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h6 && code[13:9]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_unsquad: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h3 && code[15:12]<=5'h3) /* 3000 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h5) /* 4000 - 5fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h6 && code[13:9]<=5'h7) /* 6000 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_unsquad: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h3 && code[15:12]<=5'h3) /* 3000 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h5) /* 4000 - 5fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h6 && code[13:9]<=5'h7) /* 6000 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_1941: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h1) /* 0 - 1fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 47ff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_1941: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h1) /* 0 - 1fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 47ff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_1941: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h1) /* 0 - 1fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 47ff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_1941: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h1) /* 0 - 1fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 47ff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_mercs: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR1  && code[15:12]<=5'h0) /* 0 - bff */  ||
         ( layer==SCR2  && code[15:11]<=5'h3) /* c00 - 3bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h4) /* 3c00 - 4bff */  ||
         ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4c00 - 7fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'ha) /* 8000 - a7ff */  ||
         ( layer==SCR2  && code[15:11]>=5'ha && code[15:11]<=5'hb) /* a800 - b7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hb && code[13:9]<=5'hb) /* b800 - bfff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_mercs: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR1  && code[15:12]<=5'h0) /* 0 - bff */  ||
         ( layer==SCR2  && code[15:11]<=5'h3) /* c00 - 3bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h4) /* 3c00 - 4bff */  ||
         ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4c00 - 7fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'ha) /* 8000 - a7ff */  ||
         ( layer==SCR2  && code[15:11]>=5'ha && code[15:11]<=5'hb) /* a800 - b7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hb && code[13:9]<=5'hb) /* b800 - bfff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_mercs: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR1  && code[15:12]<=5'h0) /* 0 - bff */  ||
         ( layer==SCR2  && code[15:11]<=5'h3) /* c00 - 3bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h4) /* 3c00 - 4bff */  ||
         ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4c00 - 7fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'ha) /* 8000 - a7ff */  ||
         ( layer==SCR2  && code[15:11]>=5'ha && code[15:11]<=5'hb) /* a800 - b7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hb && code[13:9]<=5'hb) /* b800 - bfff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_mercs: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR1  && code[15:12]<=5'h0) /* 0 - bff */  ||
         ( layer==SCR2  && code[15:11]<=5'h3) /* c00 - 3bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h4) /* 3c00 - 4bff */  ||
         ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4c00 - 7fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'ha) /* 8000 - a7ff */  ||
         ( layer==SCR2  && code[15:11]>=5'ha && code[15:11]<=5'hb) /* a800 - b7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hb && code[13:9]<=5'hb) /* b800 - bfff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_mtwins: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h3 && code[15:12]<=5'h3) /* 3000 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h6) /* 4000 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_mtwins: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h3 && code[15:12]<=5'h3) /* 3000 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h6) /* 4000 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_msword: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h6) /* 5000 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_msword: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h6) /* 5000 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_msword: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h6) /* 5000 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_msword: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h6) /* 5000 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_cawing: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h4) /* 3000 - 4fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h5) /* 5000 - 57ff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_cawing: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h4) /* 3000 - 4fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h5) /* 5000 - 57ff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_cawing: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h3) /* 3000 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h5) /* 5000 - 57ff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_cawing: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h4) /* 3000 - 4fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h5) /* 5000 - 57ff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_cawing: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h3) /* 3000 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h5) /* 5000 - 57ff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_nemo: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 47ff */  ||
         ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h6) /* 4800 - 67ff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h6) /* 4800 - 67ff */  ||
         ( layer==SCR3  && code[13:9]>=5'h6 && code[13:9]<=5'h7) /* 6800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_nemo: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 47ff */  ||
         ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h6) /* 4800 - 67ff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h6) /* 4800 - 67ff */  ||
         ( layer==SCR3  && code[13:9]>=5'h6 && code[13:9]<=5'h7) /* 6800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_nemo: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 47ff */  ||
         ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h6) /* 4800 - 67ff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h6) /* 4800 - 67ff */  ||
         ( layer==SCR3  && code[13:9]>=5'h6 && code[13:9]<=5'h7) /* 6800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_3wonders: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h5) /* 0 - 53ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h6) /* 5400 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h2 && code[15:11]<=5'h7) /* 2800 - 7fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5400 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_3wonders: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h5) /* 0 - 53ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h6) /* 5400 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h2 && code[15:11]<=5'h7) /* 2800 - 7fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5400 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_3wonders: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h5) /* 0 - 53ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h6) /* 5400 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h2 && code[15:11]<=5'h7) /* 2800 - 7fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5400 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_3wonders: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h5) /* 4000 - 53ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h6) /* 5400 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 2 size 0x04000
        bank[2] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h2 && code[15:11]<=5'h3) /* 2800 - 3fff */ ;
        // Bank 3 size 0x04000
        bank[3] <=  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5400 - 7fff */ ;
    end
game_3wonders: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h5) /* 0 - 53ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h6) /* 5400 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h2 && code[15:11]<=5'h7) /* 2800 - 7fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5400 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_3wonders: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h5) /* 0 - 53ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h6) /* 5400 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h2 && code[15:11]<=5'h7) /* 2800 - 7fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5400 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_kod: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h8) /* 8000 - 8fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h9 && code[15:11]<=5'hb) /* 9000 - bfff */  ||
         ( layer==SCR1  && code[15:12]>=5'hc && code[15:12]<=5'hd) /* c000 - d7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d800 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_kod: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h8) /* 8000 - 8fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h9 && code[15:11]<=5'hb) /* 9000 - bfff */  ||
         ( layer==SCR1  && code[15:12]>=5'hc && code[15:12]<=5'hd) /* c000 - d7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d800 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_kod: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h8) /* 8000 - 8fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h9 && code[15:11]<=5'hb) /* 9000 - bfff */  ||
         ( layer==SCR1  && code[15:12]>=5'hc && code[15:12]<=5'hd) /* c000 - d7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d800 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_kod: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h8) /* 8000 - 8fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h9 && code[15:11]<=5'hb) /* 9000 - bfff */  ||
         ( layer==SCR1  && code[15:12]>=5'hc && code[15:12]<=5'hd) /* c000 - d7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d800 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_kod: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h8) /* 8000 - 8fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h9 && code[15:11]<=5'hb) /* 9000 - bfff */  ||
         ( layer==SCR1  && code[15:12]>=5'hc && code[15:12]<=5'hd) /* c000 - d7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d800 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_kod: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h8) /* 8000 - 8fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h9 && code[15:11]<=5'hb) /* 9000 - bfff */  ||
         ( layer==SCR1  && code[15:12]>=5'hc && code[15:12]<=5'hd) /* c000 - d7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d800 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_captcomm: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_captcomm: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_captcomm: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_captcomm: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_captcomm: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_captcomm: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_knights: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'h9) /* 8000 - 9fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_knights: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'h9) /* 8000 - 9fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_knights: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'h9) /* 8000 - 9fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_knights: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'h9) /* 8000 - 9fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_knights: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'h9) /* 8000 - 9fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_cworld2j: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h6) /* 0 - 6fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h6) /* 0 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 77ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_cworld2j: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h6) /* 0 - 6fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h6) /* 0 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 77ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_cworld2j: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h6) /* 0 - 6fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h6) /* 0 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 77ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_varth: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR1  && code[15:12]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_varth: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR1  && code[15:12]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_varth: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR1  && code[15:12]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_varth: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h3) /* 0 - 3fff */ 
        ||  ( layer==SCR1  && code[15:12]<=5'h3) /* 0 - 3fff */ 
        ||  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h7) /* 4000 - 7fff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h7) /* 4000 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_varth: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR1  && code[15:12]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_qad: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR1  && code[15:12]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_qad: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR1  && code[15:12]<=5'h0) /* 0 - 7ff */  ||
         ( layer==SCR3  && code[13:9]<=5'h1) /* 800 - 1fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h2 && code[15:11]<=5'h7) /* 2000 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h2 && code[15:11]<=5'h7) /* 2000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_wof: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR1  && code[15:12]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_sf2hf: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2hf: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2hf: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_dino: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR1  && code[15:12]<=5'h0) /* 0 - fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h1 && code[15:11]<=5'h7) /* 1000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hd) /* 8000 - dfff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hd) /* 8000 - dfff */  ||
         ( layer==SCR3  && code[13:9]>=5'he && code[13:9]<=5'hf) /* e000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_punisher: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR1  && code[15:12]<=5'h0) /* 0 - fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h1 && code[15:11]<=5'h7) /* 1000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hd) /* 8000 - dbff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hd) /* 8000 - dbff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* dc00 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_pnickj: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR1  && code[15:12]<=5'h0) /* 0 - fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h1 && code[15:11]<=5'h5) /* 1000 - 5fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h1 && code[15:11]<=5'h5) /* 1000 - 5fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h6 && code[13:9]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_qtono2j: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR1  && code[15:12]<=5'h0) /* 0 - fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h1 && code[13:9]<=5'h3) /* 1000 - 3fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_megaman: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR1  && code[15:12]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h17) /* 10000 - 17fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h10 && code[15:11]<=5'h17) /* 10000 - 17fff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h10 && code[15:12]<=5'h17) /* 10000 - 17fff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h10 && code[13:9]<=5'h17) /* 10000 - 17fff */ ;
        // Bank 3 size 0x08000
        bank[3] <=  ( layer==OBJ   && code[15:11]>=5'h18) /* 18000 - 1ffff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h18) /* 18000 - 1ffff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h18) /* 18000 - 1ffff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h18) /* 18000 - 1ffff */ ;
    end
game_megaman: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR1  && code[15:12]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h17) /* 10000 - 17fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h10 && code[15:11]<=5'h17) /* 10000 - 17fff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h10 && code[15:12]<=5'h17) /* 10000 - 17fff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h10 && code[13:9]<=5'h17) /* 10000 - 17fff */ ;
        // Bank 3 size 0x08000
        bank[3] <=  ( layer==OBJ   && code[15:11]>=5'h18) /* 18000 - 1ffff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h18) /* 18000 - 1ffff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h18) /* 18000 - 1ffff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h18) /* 18000 - 1ffff */ ;
    end
game_megaman: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR1  && code[15:12]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h17) /* 10000 - 17fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h10 && code[15:11]<=5'h17) /* 10000 - 17fff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h10 && code[15:12]<=5'h17) /* 10000 - 17fff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h10 && code[13:9]<=5'h17) /* 10000 - 17fff */ ;
        // Bank 3 size 0x08000
        bank[3] <=  ( layer==OBJ   && code[15:11]>=5'h18) /* 18000 - 1ffff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h18) /* 18000 - 1ffff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h18) /* 18000 - 1ffff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h18) /* 18000 - 1ffff */ ;
    end
game_pokonyan: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h3) /* 3000 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h6) /* 4000 - 6fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_pang3: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h9) /* 8000 - 9fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'h9) /* 8000 - 9fff */  ||
         ( layer==SCR1  && code[15:12]>=5'ha && code[15:12]<=5'hb) /* a000 - bfff */  ||
         ( layer==SCR3  && code[13:9]>=5'hc && code[13:9]<=5'hf) /* c000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_pang3: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h9) /* 8000 - 9fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'h9) /* 8000 - 9fff */  ||
         ( layer==SCR1  && code[15:12]>=5'ha && code[15:12]<=5'hb) /* a000 - bfff */  ||
         ( layer==SCR3  && code[13:9]>=5'hc && code[13:9]<=5'hf) /* c000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_pang3: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h9) /* 8000 - 9fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'h9) /* 8000 - 9fff */  ||
         ( layer==SCR1  && code[15:12]>=5'ha && code[15:12]<=5'hb) /* a000 - bfff */  ||
         ( layer==SCR3  && code[13:9]>=5'hc && code[13:9]<=5'hf) /* c000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_pang3: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h9) /* 8000 - 9fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'h9) /* 8000 - 9fff */  ||
         ( layer==SCR1  && code[15:12]>=5'ha && code[15:12]<=5'hb) /* a000 - bfff */  ||
         ( layer==SCR3  && code[13:9]>=5'hc && code[13:9]<=5'hf) /* c000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_forgottn: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1 ) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==SCR2 ) /* 0 - 1ffff */  ||
         ( layer==SCR3 ) /* 0 - 1ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_forgottn: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1 ) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==SCR2 ) /* 0 - 1ffff */  ||
         ( layer==SCR3 ) /* 0 - 1ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_forgottn: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1 ) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==SCR2 ) /* 0 - 1ffff */  ||
         ( layer==SCR3 ) /* 0 - 1ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_forgottn: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1 ) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==SCR2 ) /* 0 - 1ffff */  ||
         ( layer==SCR3 ) /* 0 - 1ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_forgottn: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1 ) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==SCR2 ) /* 0 - 1ffff */  ||
         ( layer==SCR3 ) /* 0 - 1ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_forgottn: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1 ) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==SCR2 ) /* 0 - 1ffff */  ||
         ( layer==SCR3 ) /* 0 - 1ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_forgottn: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1 ) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==SCR2 ) /* 0 - 1ffff */  ||
         ( layer==SCR3 ) /* 0 - 1ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_forgottn: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1 ) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==SCR2 ) /* 0 - 1ffff */  ||
         ( layer==SCR3 ) /* 0 - 1ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_forgottn: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1 ) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==SCR2 ) /* 0 - 1ffff */  ||
         ( layer==SCR3 ) /* 0 - 1ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ghouls: begin
        // Bank 1 size 0x02000
        bank[1] <=  ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hb) /* 8000 - bfff */ ;
        // Bank 2 size 0x02000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h2 && code[15:11]<=5'h3) /* 2000 - 3fff */ ;
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR2 ) /* 0 - 1ffff */ 
        ||  ( layer==SCR1 ) /* 0 - 1ffff */ 
        ||  ( layer==SCR3 ) /* 0 - 1ffff */ 
        ||  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==OBJ   && code[15:11]<=5'h1) /* 0 - 1fff */ ;
        bank[3] <= 1'b0;
    end
game_ghouls: begin
        // Bank 1 size 0x02000
        bank[1] <=  ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hb) /* 8000 - bfff */ ;
        // Bank 2 size 0x02000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h2 && code[15:11]<=5'h3) /* 2000 - 3fff */ ;
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR2 ) /* 0 - 1ffff */ 
        ||  ( layer==SCR1 ) /* 0 - 1ffff */ 
        ||  ( layer==SCR3 ) /* 0 - 1ffff */ 
        ||  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==OBJ   && code[15:11]<=5'h1) /* 0 - 1fff */ ;
        bank[3] <= 1'b0;
    end
game_ghouls: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h1) /* 0 - 1fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h2 && code[15:12]<=5'h3) /* 2000 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
        // Bank 2 size 0x02000
        bank[2] <=  ( layer==SCR3 ) /* 0 - 1ffff */ ;
        // Bank 3 size 0x02000
        bank[3] <=  ( layer==OBJ   && code[15:11]>=5'h2 && code[15:11]<=5'h3) /* 2000 - 3fff */ ;
    end
game_ghouls: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h1) /* 0 - 1fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h2 && code[15:12]<=5'h2) /* 2000 - 2fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3 ) /* 0 - 1ffff */  ||
         ( layer==OBJ   && code[15:11]>=5'h2 && code[15:11]<=5'h3) /* 2000 - 3fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_strider: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==STARS  && code[15:11]<=5'h0) /* 0 - 3ff */  ||
         ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_strider: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==STARS  && code[15:11]<=5'h0) /* 0 - 3ff */  ||
         ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_strider: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==STARS  && code[15:11]<=5'h0) /* 0 - 3ff */  ||
         ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_strider: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
        // Bank 2 size 0x04000
        bank[2] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */ ;
        // Bank 3 size 0x04000
        bank[3] <=  ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h7) /* 4000 - 7fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */ ;
    end
game_strider: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==STARS  && code[15:11]<=5'h0) /* 0 - 3ff */  ||
         ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_dynwar: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h5) /* 4000 - 5fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h6 && code[15:12]<=5'h7) /* 6000 - 7fff */ ;
        // Bank 2 size 0x04000
        bank[2] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */ ;
        // Bank 3 size 0x04000
        bank[3] <=  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
    end
game_dynwar: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h5) /* 4000 - 5fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h6 && code[15:12]<=5'h7) /* 6000 - 7fff */ ;
        // Bank 2 size 0x04000
        bank[2] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */ ;
        // Bank 3 size 0x04000
        bank[3] <=  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
    end
game_dynwar: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h5) /* 4000 - 5fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h6 && code[15:12]<=5'h7) /* 6000 - 7fff */ ;
        // Bank 2 size 0x04000
        bank[2] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */ ;
        // Bank 3 size 0x04000
        bank[3] <=  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
    end
game_dynwar: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h5) /* 4000 - 5fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h6 && code[15:12]<=5'h7) /* 6000 - 7fff */ ;
        // Bank 2 size 0x04000
        bank[2] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */ ;
        // Bank 3 size 0x04000
        bank[3] <=  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
    end
game_willow: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 4fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h5 && code[13:9]<=5'h6) /* 5000 - 6fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR2  && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_willow: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 4fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h5 && code[13:9]<=5'h6) /* 5000 - 6fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR2  && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_willow: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 4fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h5 && code[13:9]<=5'h6) /* 5000 - 6fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR2  && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_willow: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 4fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h5 && code[13:9]<=5'h6) /* 5000 - 6fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR2  && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_unsquad: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h3 && code[15:12]<=5'h3) /* 3000 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h5) /* 4000 - 5fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h6 && code[13:9]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_unsquad: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h3 && code[15:12]<=5'h3) /* 3000 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h5) /* 4000 - 5fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h6 && code[13:9]<=5'h7) /* 6000 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_unsquad: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h3 && code[15:12]<=5'h3) /* 3000 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h5) /* 4000 - 5fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h6 && code[13:9]<=5'h7) /* 6000 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_1941: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h1) /* 0 - 1fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 47ff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_1941: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h1) /* 0 - 1fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 47ff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_1941: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h1) /* 0 - 1fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 47ff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_1941: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h1) /* 0 - 1fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 47ff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_mercs: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR1  && code[15:12]<=5'h0) /* 0 - bff */  ||
         ( layer==SCR2  && code[15:11]<=5'h3) /* c00 - 3bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h4) /* 3c00 - 4bff */  ||
         ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4c00 - 7fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'ha) /* 8000 - a7ff */  ||
         ( layer==SCR2  && code[15:11]>=5'ha && code[15:11]<=5'hb) /* a800 - b7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hb && code[13:9]<=5'hb) /* b800 - bfff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_mercs: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR1  && code[15:12]<=5'h0) /* 0 - bff */  ||
         ( layer==SCR2  && code[15:11]<=5'h3) /* c00 - 3bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h4) /* 3c00 - 4bff */  ||
         ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4c00 - 7fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'ha) /* 8000 - a7ff */  ||
         ( layer==SCR2  && code[15:11]>=5'ha && code[15:11]<=5'hb) /* a800 - b7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hb && code[13:9]<=5'hb) /* b800 - bfff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_mercs: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR1  && code[15:12]<=5'h0) /* 0 - bff */  ||
         ( layer==SCR2  && code[15:11]<=5'h3) /* c00 - 3bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h4) /* 3c00 - 4bff */  ||
         ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4c00 - 7fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'ha) /* 8000 - a7ff */  ||
         ( layer==SCR2  && code[15:11]>=5'ha && code[15:11]<=5'hb) /* a800 - b7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hb && code[13:9]<=5'hb) /* b800 - bfff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_mercs: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR1  && code[15:12]<=5'h0) /* 0 - bff */  ||
         ( layer==SCR2  && code[15:11]<=5'h3) /* c00 - 3bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h4) /* 3c00 - 4bff */  ||
         ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4c00 - 7fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'ha) /* 8000 - a7ff */  ||
         ( layer==SCR2  && code[15:11]>=5'ha && code[15:11]<=5'hb) /* a800 - b7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hb && code[13:9]<=5'hb) /* b800 - bfff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_mtwins: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h3 && code[15:12]<=5'h3) /* 3000 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h6) /* 4000 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_mtwins: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h3 && code[15:12]<=5'h3) /* 3000 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h6) /* 4000 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_msword: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h6) /* 5000 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_msword: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h6) /* 5000 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_msword: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h6) /* 5000 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_msword: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h6) /* 5000 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_cawing: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h4) /* 3000 - 4fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h5) /* 5000 - 57ff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_cawing: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h4) /* 3000 - 4fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h5) /* 5000 - 57ff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_cawing: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h3) /* 3000 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h5) /* 5000 - 57ff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_cawing: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h4) /* 3000 - 4fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h5) /* 5000 - 57ff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_cawing: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h3) /* 3000 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h5) /* 5000 - 57ff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_nemo: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 47ff */  ||
         ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h6) /* 4800 - 67ff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h6) /* 4800 - 67ff */  ||
         ( layer==SCR3  && code[13:9]>=5'h6 && code[13:9]<=5'h7) /* 6800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_nemo: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 47ff */  ||
         ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h6) /* 4800 - 67ff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h6) /* 4800 - 67ff */  ||
         ( layer==SCR3  && code[13:9]>=5'h6 && code[13:9]<=5'h7) /* 6800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_nemo: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 47ff */  ||
         ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h6) /* 4800 - 67ff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h6) /* 4800 - 67ff */  ||
         ( layer==SCR3  && code[13:9]>=5'h6 && code[13:9]<=5'h7) /* 6800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_3wonders: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h5) /* 0 - 53ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h6) /* 5400 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h2 && code[15:11]<=5'h7) /* 2800 - 7fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5400 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_3wonders: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h5) /* 0 - 53ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h6) /* 5400 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h2 && code[15:11]<=5'h7) /* 2800 - 7fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5400 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_3wonders: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h5) /* 0 - 53ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h6) /* 5400 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h2 && code[15:11]<=5'h7) /* 2800 - 7fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5400 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_3wonders: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h5) /* 4000 - 53ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h6) /* 5400 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 2 size 0x04000
        bank[2] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h2 && code[15:11]<=5'h3) /* 2800 - 3fff */ ;
        // Bank 3 size 0x04000
        bank[3] <=  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5400 - 7fff */ ;
    end
game_3wonders: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h5) /* 0 - 53ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h6) /* 5400 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h2 && code[15:11]<=5'h7) /* 2800 - 7fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5400 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_3wonders: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h5) /* 0 - 53ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h6) /* 5400 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h2 && code[15:11]<=5'h7) /* 2800 - 7fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5400 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_kod: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h8) /* 8000 - 8fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h9 && code[15:11]<=5'hb) /* 9000 - bfff */  ||
         ( layer==SCR1  && code[15:12]>=5'hc && code[15:12]<=5'hd) /* c000 - d7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d800 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_kod: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h8) /* 8000 - 8fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h9 && code[15:11]<=5'hb) /* 9000 - bfff */  ||
         ( layer==SCR1  && code[15:12]>=5'hc && code[15:12]<=5'hd) /* c000 - d7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d800 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_kod: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h8) /* 8000 - 8fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h9 && code[15:11]<=5'hb) /* 9000 - bfff */  ||
         ( layer==SCR1  && code[15:12]>=5'hc && code[15:12]<=5'hd) /* c000 - d7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d800 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_kod: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h8) /* 8000 - 8fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h9 && code[15:11]<=5'hb) /* 9000 - bfff */  ||
         ( layer==SCR1  && code[15:12]>=5'hc && code[15:12]<=5'hd) /* c000 - d7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d800 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_kod: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h8) /* 8000 - 8fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h9 && code[15:11]<=5'hb) /* 9000 - bfff */  ||
         ( layer==SCR1  && code[15:12]>=5'hc && code[15:12]<=5'hd) /* c000 - d7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d800 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_kod: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h8) /* 8000 - 8fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h9 && code[15:11]<=5'hb) /* 9000 - bfff */  ||
         ( layer==SCR1  && code[15:12]>=5'hc && code[15:12]<=5'hd) /* c000 - d7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d800 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_captcomm: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_captcomm: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_captcomm: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_captcomm: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_captcomm: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_captcomm: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_knights: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'h9) /* 8000 - 9fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_knights: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'h9) /* 8000 - 9fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_knights: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'h9) /* 8000 - 9fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_knights: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'h9) /* 8000 - 9fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_knights: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'h9) /* 8000 - 9fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_cworld2j: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h6) /* 0 - 6fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h6) /* 0 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 77ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_cworld2j: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h6) /* 0 - 6fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h6) /* 0 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 77ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_cworld2j: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h6) /* 0 - 6fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h6) /* 0 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 77ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_varth: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR1  && code[15:12]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_varth: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR1  && code[15:12]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_varth: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR1  && code[15:12]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_varth: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h3) /* 0 - 3fff */ 
        ||  ( layer==SCR1  && code[15:12]<=5'h3) /* 0 - 3fff */ 
        ||  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h7) /* 4000 - 7fff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h7) /* 4000 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_varth: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR1  && code[15:12]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_qad: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR1  && code[15:12]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_qad: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR1  && code[15:12]<=5'h0) /* 0 - 7ff */  ||
         ( layer==SCR3  && code[13:9]<=5'h1) /* 800 - 1fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h2 && code[15:11]<=5'h7) /* 2000 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h2 && code[15:11]<=5'h7) /* 2000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_wof: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR1  && code[15:12]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_sf2hf: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2hf: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2hf: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_dino: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR1  && code[15:12]<=5'h0) /* 0 - fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h1 && code[15:11]<=5'h7) /* 1000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hd) /* 8000 - dfff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hd) /* 8000 - dfff */  ||
         ( layer==SCR3  && code[13:9]>=5'he && code[13:9]<=5'hf) /* e000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_punisher: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR1  && code[15:12]<=5'h0) /* 0 - fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h1 && code[15:11]<=5'h7) /* 1000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hd) /* 8000 - dbff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hd) /* 8000 - dbff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* dc00 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_pnickj: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR1  && code[15:12]<=5'h0) /* 0 - fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h1 && code[15:11]<=5'h5) /* 1000 - 5fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h1 && code[15:11]<=5'h5) /* 1000 - 5fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h6 && code[13:9]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_qtono2j: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR1  && code[15:12]<=5'h0) /* 0 - fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h1 && code[13:9]<=5'h3) /* 1000 - 3fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_megaman: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR1  && code[15:12]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h17) /* 10000 - 17fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h10 && code[15:11]<=5'h17) /* 10000 - 17fff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h10 && code[15:12]<=5'h17) /* 10000 - 17fff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h10 && code[13:9]<=5'h17) /* 10000 - 17fff */ ;
        // Bank 3 size 0x08000
        bank[3] <=  ( layer==OBJ   && code[15:11]>=5'h18) /* 18000 - 1ffff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h18) /* 18000 - 1ffff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h18) /* 18000 - 1ffff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h18) /* 18000 - 1ffff */ ;
    end
game_megaman: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR1  && code[15:12]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h17) /* 10000 - 17fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h10 && code[15:11]<=5'h17) /* 10000 - 17fff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h10 && code[15:12]<=5'h17) /* 10000 - 17fff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h10 && code[13:9]<=5'h17) /* 10000 - 17fff */ ;
        // Bank 3 size 0x08000
        bank[3] <=  ( layer==OBJ   && code[15:11]>=5'h18) /* 18000 - 1ffff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h18) /* 18000 - 1ffff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h18) /* 18000 - 1ffff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h18) /* 18000 - 1ffff */ ;
    end
game_megaman: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR1  && code[15:12]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h17) /* 10000 - 17fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h10 && code[15:11]<=5'h17) /* 10000 - 17fff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h10 && code[15:12]<=5'h17) /* 10000 - 17fff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h10 && code[13:9]<=5'h17) /* 10000 - 17fff */ ;
        // Bank 3 size 0x08000
        bank[3] <=  ( layer==OBJ   && code[15:11]>=5'h18) /* 18000 - 1ffff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h18) /* 18000 - 1ffff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h18) /* 18000 - 1ffff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h18) /* 18000 - 1ffff */ ;
    end
game_pokonyan: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h3) /* 3000 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h6) /* 4000 - 6fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_pang3: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h9) /* 8000 - 9fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'h9) /* 8000 - 9fff */  ||
         ( layer==SCR1  && code[15:12]>=5'ha && code[15:12]<=5'hb) /* a000 - bfff */  ||
         ( layer==SCR3  && code[13:9]>=5'hc && code[13:9]<=5'hf) /* c000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_pang3: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h9) /* 8000 - 9fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'h9) /* 8000 - 9fff */  ||
         ( layer==SCR1  && code[15:12]>=5'ha && code[15:12]<=5'hb) /* a000 - bfff */  ||
         ( layer==SCR3  && code[13:9]>=5'hc && code[13:9]<=5'hf) /* c000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_pang3: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h9) /* 8000 - 9fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'h9) /* 8000 - 9fff */  ||
         ( layer==SCR1  && code[15:12]>=5'ha && code[15:12]<=5'hb) /* a000 - bfff */  ||
         ( layer==SCR3  && code[13:9]>=5'hc && code[13:9]<=5'hf) /* c000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_pang3: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h9) /* 8000 - 9fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'h9) /* 8000 - 9fff */  ||
         ( layer==SCR1  && code[15:12]>=5'ha && code[15:12]<=5'hb) /* a000 - bfff */  ||
         ( layer==SCR3  && code[13:9]>=5'hc && code[13:9]<=5'hf) /* c000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_forgottn: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1 ) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==SCR2 ) /* 0 - 1ffff */  ||
         ( layer==SCR3 ) /* 0 - 1ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_forgottn: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1 ) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==SCR2 ) /* 0 - 1ffff */  ||
         ( layer==SCR3 ) /* 0 - 1ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_forgottn: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1 ) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==SCR2 ) /* 0 - 1ffff */  ||
         ( layer==SCR3 ) /* 0 - 1ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_forgottn: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1 ) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==SCR2 ) /* 0 - 1ffff */  ||
         ( layer==SCR3 ) /* 0 - 1ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_forgottn: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1 ) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==SCR2 ) /* 0 - 1ffff */  ||
         ( layer==SCR3 ) /* 0 - 1ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_forgottn: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1 ) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==SCR2 ) /* 0 - 1ffff */  ||
         ( layer==SCR3 ) /* 0 - 1ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_forgottn: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1 ) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==SCR2 ) /* 0 - 1ffff */  ||
         ( layer==SCR3 ) /* 0 - 1ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_forgottn: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1 ) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==SCR2 ) /* 0 - 1ffff */  ||
         ( layer==SCR3 ) /* 0 - 1ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_forgottn: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1 ) /* 0 - 1ffff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==SCR2 ) /* 0 - 1ffff */  ||
         ( layer==SCR3 ) /* 0 - 1ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ghouls: begin
        // Bank 1 size 0x02000
        bank[1] <=  ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hb) /* 8000 - bfff */ ;
        // Bank 2 size 0x02000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h2 && code[15:11]<=5'h3) /* 2000 - 3fff */ ;
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR2 ) /* 0 - 1ffff */ 
        ||  ( layer==SCR1 ) /* 0 - 1ffff */ 
        ||  ( layer==SCR3 ) /* 0 - 1ffff */ 
        ||  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==OBJ   && code[15:11]<=5'h1) /* 0 - 1fff */ ;
        bank[3] <= 1'b0;
    end
game_ghouls: begin
        // Bank 1 size 0x02000
        bank[1] <=  ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hb) /* 8000 - bfff */ ;
        // Bank 2 size 0x02000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h2 && code[15:11]<=5'h3) /* 2000 - 3fff */ ;
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR2 ) /* 0 - 1ffff */ 
        ||  ( layer==SCR1 ) /* 0 - 1ffff */ 
        ||  ( layer==SCR3 ) /* 0 - 1ffff */ 
        ||  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==OBJ   && code[15:11]<=5'h1) /* 0 - 1fff */ ;
        bank[3] <= 1'b0;
    end
game_ghouls: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h1) /* 0 - 1fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h2 && code[15:12]<=5'h3) /* 2000 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
        // Bank 2 size 0x02000
        bank[2] <=  ( layer==SCR3 ) /* 0 - 1ffff */ ;
        // Bank 3 size 0x02000
        bank[3] <=  ( layer==OBJ   && code[15:11]>=5'h2 && code[15:11]<=5'h3) /* 2000 - 3fff */ ;
    end
game_ghouls: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h1) /* 0 - 1fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h2 && code[15:12]<=5'h2) /* 2000 - 2fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3 ) /* 0 - 1ffff */  ||
         ( layer==OBJ   && code[15:11]>=5'h2 && code[15:11]<=5'h3) /* 2000 - 3fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_strider: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==STARS  && code[15:11]<=5'h0) /* 0 - 3ff */  ||
         ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_strider: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==STARS  && code[15:11]<=5'h0) /* 0 - 3ff */  ||
         ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_strider: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==STARS  && code[15:11]<=5'h0) /* 0 - 3ff */  ||
         ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_strider: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==STARS ) /* 0 - 1ffff */  ||
         ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
        // Bank 2 size 0x04000
        bank[2] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */ ;
        // Bank 3 size 0x04000
        bank[3] <=  ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h7) /* 4000 - 7fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */ ;
    end
game_strider: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==STARS  && code[15:11]<=5'h0) /* 0 - 3ff */  ||
         ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_dynwar: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h5) /* 4000 - 5fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h6 && code[15:12]<=5'h7) /* 6000 - 7fff */ ;
        // Bank 2 size 0x04000
        bank[2] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */ ;
        // Bank 3 size 0x04000
        bank[3] <=  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
    end
game_dynwar: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h5) /* 4000 - 5fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h6 && code[15:12]<=5'h7) /* 6000 - 7fff */ ;
        // Bank 2 size 0x04000
        bank[2] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */ ;
        // Bank 3 size 0x04000
        bank[3] <=  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
    end
game_dynwar: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h5) /* 4000 - 5fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h6 && code[15:12]<=5'h7) /* 6000 - 7fff */ ;
        // Bank 2 size 0x04000
        bank[2] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */ ;
        // Bank 3 size 0x04000
        bank[3] <=  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
    end
game_dynwar: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h5) /* 4000 - 5fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h6 && code[15:12]<=5'h7) /* 6000 - 7fff */ ;
        // Bank 2 size 0x04000
        bank[2] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */ ;
        // Bank 3 size 0x04000
        bank[3] <=  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
    end
game_willow: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 4fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h5 && code[13:9]<=5'h6) /* 5000 - 6fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR2  && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_willow: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 4fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h5 && code[13:9]<=5'h6) /* 5000 - 6fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR2  && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_willow: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 4fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h5 && code[13:9]<=5'h6) /* 5000 - 6fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR2  && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_willow: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 4fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h5 && code[13:9]<=5'h6) /* 5000 - 6fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR2  && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_unsquad: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h3 && code[15:12]<=5'h3) /* 3000 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h5) /* 4000 - 5fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h6 && code[13:9]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_unsquad: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h3 && code[15:12]<=5'h3) /* 3000 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h5) /* 4000 - 5fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h6 && code[13:9]<=5'h7) /* 6000 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_unsquad: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h3 && code[15:12]<=5'h3) /* 3000 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h5) /* 4000 - 5fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h6 && code[13:9]<=5'h7) /* 6000 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_ffight: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h4) /* 0 - 43ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4400 - 4bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h5) /* 4c00 - 5fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h6 && code[15:11]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_1941: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h1) /* 0 - 1fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 47ff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_1941: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h1) /* 0 - 1fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 47ff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_1941: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h1) /* 0 - 1fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 47ff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_1941: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h1) /* 0 - 1fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 47ff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_mercs: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR1  && code[15:12]<=5'h0) /* 0 - bff */  ||
         ( layer==SCR2  && code[15:11]<=5'h3) /* c00 - 3bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h4) /* 3c00 - 4bff */  ||
         ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4c00 - 7fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'ha) /* 8000 - a7ff */  ||
         ( layer==SCR2  && code[15:11]>=5'ha && code[15:11]<=5'hb) /* a800 - b7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hb && code[13:9]<=5'hb) /* b800 - bfff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_mercs: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR1  && code[15:12]<=5'h0) /* 0 - bff */  ||
         ( layer==SCR2  && code[15:11]<=5'h3) /* c00 - 3bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h4) /* 3c00 - 4bff */  ||
         ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4c00 - 7fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'ha) /* 8000 - a7ff */  ||
         ( layer==SCR2  && code[15:11]>=5'ha && code[15:11]<=5'hb) /* a800 - b7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hb && code[13:9]<=5'hb) /* b800 - bfff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_mercs: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR1  && code[15:12]<=5'h0) /* 0 - bff */  ||
         ( layer==SCR2  && code[15:11]<=5'h3) /* c00 - 3bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h4) /* 3c00 - 4bff */  ||
         ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4c00 - 7fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'ha) /* 8000 - a7ff */  ||
         ( layer==SCR2  && code[15:11]>=5'ha && code[15:11]<=5'hb) /* a800 - b7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hb && code[13:9]<=5'hb) /* b800 - bfff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_mercs: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR1  && code[15:12]<=5'h0) /* 0 - bff */  ||
         ( layer==SCR2  && code[15:11]<=5'h3) /* c00 - 3bff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h4) /* 3c00 - 4bff */  ||
         ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4c00 - 7fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'ha) /* 8000 - a7ff */  ||
         ( layer==SCR2  && code[15:11]>=5'ha && code[15:11]<=5'hb) /* a800 - b7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hb && code[13:9]<=5'hb) /* b800 - bfff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_mtwins: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h3 && code[15:12]<=5'h3) /* 3000 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h6) /* 4000 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_mtwins: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h3 && code[15:12]<=5'h3) /* 3000 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h6) /* 4000 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_msword: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h6) /* 5000 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_msword: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h6) /* 5000 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_msword: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h6) /* 5000 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_msword: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h6) /* 5000 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_cawing: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h4) /* 3000 - 4fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h5) /* 5000 - 57ff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_cawing: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h4) /* 3000 - 4fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h5) /* 5000 - 57ff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_cawing: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h3) /* 3000 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h5) /* 5000 - 57ff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_cawing: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h4) /* 3000 - 4fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h5) /* 5000 - 57ff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_cawing: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h3) /* 3000 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h5) /* 5000 - 57ff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5800 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_nemo: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 47ff */  ||
         ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h6) /* 4800 - 67ff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h6) /* 4800 - 67ff */  ||
         ( layer==SCR3  && code[13:9]>=5'h6 && code[13:9]<=5'h7) /* 6800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_nemo: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 47ff */  ||
         ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h6) /* 4800 - 67ff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h6) /* 4800 - 67ff */  ||
         ( layer==SCR3  && code[13:9]>=5'h6 && code[13:9]<=5'h7) /* 6800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_nemo: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 47ff */  ||
         ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h6) /* 4800 - 67ff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h6) /* 4800 - 67ff */  ||
         ( layer==SCR3  && code[13:9]>=5'h6 && code[13:9]<=5'h7) /* 6800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_3wonders: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h5) /* 0 - 53ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h6) /* 5400 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h2 && code[15:11]<=5'h7) /* 2800 - 7fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5400 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_3wonders: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h5) /* 0 - 53ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h6) /* 5400 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h2 && code[15:11]<=5'h7) /* 2800 - 7fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5400 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_3wonders: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h5) /* 0 - 53ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h6) /* 5400 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h2 && code[15:11]<=5'h7) /* 2800 - 7fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5400 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_3wonders: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h5) /* 4000 - 53ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h6) /* 5400 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 2 size 0x04000
        bank[2] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h2 && code[15:11]<=5'h3) /* 2800 - 3fff */ ;
        // Bank 3 size 0x04000
        bank[3] <=  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5400 - 7fff */ ;
    end
game_3wonders: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h5) /* 0 - 53ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h6) /* 5400 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h2 && code[15:11]<=5'h7) /* 2800 - 7fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5400 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_3wonders: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h5) /* 0 - 53ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h5 && code[15:12]<=5'h6) /* 5400 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h2 && code[15:11]<=5'h7) /* 2800 - 7fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5400 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_kod: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h8) /* 8000 - 8fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h9 && code[15:11]<=5'hb) /* 9000 - bfff */  ||
         ( layer==SCR1  && code[15:12]>=5'hc && code[15:12]<=5'hd) /* c000 - d7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d800 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_kod: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h8) /* 8000 - 8fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h9 && code[15:11]<=5'hb) /* 9000 - bfff */  ||
         ( layer==SCR1  && code[15:12]>=5'hc && code[15:12]<=5'hd) /* c000 - d7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d800 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_kod: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h8) /* 8000 - 8fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h9 && code[15:11]<=5'hb) /* 9000 - bfff */  ||
         ( layer==SCR1  && code[15:12]>=5'hc && code[15:12]<=5'hd) /* c000 - d7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d800 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_kod: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h8) /* 8000 - 8fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h9 && code[15:11]<=5'hb) /* 9000 - bfff */  ||
         ( layer==SCR1  && code[15:12]>=5'hc && code[15:12]<=5'hd) /* c000 - d7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d800 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_kod: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h8) /* 8000 - 8fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h9 && code[15:11]<=5'hb) /* 9000 - bfff */  ||
         ( layer==SCR1  && code[15:12]>=5'hc && code[15:12]<=5'hd) /* c000 - d7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d800 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_kod: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h8) /* 8000 - 8fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h9 && code[15:11]<=5'hb) /* 9000 - bfff */  ||
         ( layer==SCR1  && code[15:12]>=5'hc && code[15:12]<=5'hd) /* c000 - d7ff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d800 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_captcomm: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_captcomm: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_captcomm: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_captcomm: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_captcomm: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_captcomm: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */  ||
         ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_knights: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'h9) /* 8000 - 9fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_knights: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'h9) /* 8000 - 9fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_knights: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'h9) /* 8000 - 9fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_knights: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'h9) /* 8000 - 9fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_knights: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'h9) /* 8000 - 9fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hc) /* 8000 - cfff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* d000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2ce: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_cworld2j: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h6) /* 0 - 6fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h6) /* 0 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 77ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_cworld2j: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h6) /* 0 - 6fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h6) /* 0 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 77ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_cworld2j: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h6) /* 0 - 6fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h6) /* 0 - 6fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h7 && code[13:9]<=5'h7) /* 7000 - 77ff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7800 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_varth: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR1  && code[15:12]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_varth: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR1  && code[15:12]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_varth: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR1  && code[15:12]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_varth: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h3) /* 0 - 3fff */ 
        ||  ( layer==SCR1  && code[15:12]<=5'h3) /* 0 - 3fff */ 
        ||  ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */ ;
        // Bank 1 size 0x04000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h7) /* 4000 - 7fff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h4 && code[13:9]<=5'h7) /* 4000 - 7fff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_varth: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR1  && code[15:12]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_qad: begin
        // Bank 0 size 0x04000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR1  && code[15:12]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR2  && code[15:11]<=5'h3) /* 0 - 3fff */  ||
         ( layer==SCR3  && code[13:9]<=5'h3) /* 0 - 3fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_qad: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR1  && code[15:12]<=5'h0) /* 0 - 7ff */  ||
         ( layer==SCR3  && code[13:9]<=5'h1) /* 800 - 1fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h2 && code[15:11]<=5'h7) /* 2000 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h2 && code[15:11]<=5'h7) /* 2000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_wof: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR1  && code[15:12]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_sf2hf: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2hf: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_sf2hf: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h11) /* 10000 - 11fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h2 && code[13:9]<=5'h3) /* 2000 - 3fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h4 && code[15:12]<=5'h4) /* 4000 - 4fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h5 && code[15:11]<=5'h7) /* 5000 - 7fff */ ;
        bank[3] <= 1'b0;
    end
game_dino: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR1  && code[15:12]<=5'h0) /* 0 - fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h1 && code[15:11]<=5'h7) /* 1000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hd) /* 8000 - dfff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hd) /* 8000 - dfff */  ||
         ( layer==SCR3  && code[13:9]>=5'he && code[13:9]<=5'hf) /* e000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_punisher: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR1  && code[15:12]<=5'h0) /* 0 - fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h1 && code[15:11]<=5'h7) /* 1000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hd) /* 8000 - dbff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hd) /* 8000 - dbff */  ||
         ( layer==SCR3  && code[13:9]>=5'hd && code[13:9]<=5'hf) /* dc00 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_pnickj: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR1  && code[15:12]<=5'h0) /* 0 - fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h1 && code[15:11]<=5'h5) /* 1000 - 5fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h1 && code[15:11]<=5'h5) /* 1000 - 5fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h6 && code[13:9]<=5'h7) /* 6000 - 7fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_qtono2j: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==SCR1  && code[15:12]<=5'h0) /* 0 - fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h1 && code[13:9]<=5'h3) /* 1000 - 3fff */  ||
         ( layer==OBJ   && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h7) /* 4000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_megaman: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR1  && code[15:12]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h17) /* 10000 - 17fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h10 && code[15:11]<=5'h17) /* 10000 - 17fff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h10 && code[15:12]<=5'h17) /* 10000 - 17fff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h10 && code[13:9]<=5'h17) /* 10000 - 17fff */ ;
        // Bank 3 size 0x08000
        bank[3] <=  ( layer==OBJ   && code[15:11]>=5'h18) /* 18000 - 1ffff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h18) /* 18000 - 1ffff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h18) /* 18000 - 1ffff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h18) /* 18000 - 1ffff */ ;
    end
game_megaman: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR1  && code[15:12]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h17) /* 10000 - 17fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h10 && code[15:11]<=5'h17) /* 10000 - 17fff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h10 && code[15:12]<=5'h17) /* 10000 - 17fff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h10 && code[13:9]<=5'h17) /* 10000 - 17fff */ ;
        // Bank 3 size 0x08000
        bank[3] <=  ( layer==OBJ   && code[15:11]>=5'h18) /* 18000 - 1ffff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h18) /* 18000 - 1ffff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h18) /* 18000 - 1ffff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h18) /* 18000 - 1ffff */ ;
    end
game_megaman: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR1  && code[15:12]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR3  && code[13:9]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h8 && code[15:12]<=5'hf) /* 8000 - ffff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h8 && code[13:9]<=5'hf) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank[2] <=  ( layer==OBJ   && code[15:11]>=5'h10 && code[15:11]<=5'h17) /* 10000 - 17fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h10 && code[15:11]<=5'h17) /* 10000 - 17fff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h10 && code[15:12]<=5'h17) /* 10000 - 17fff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h10 && code[13:9]<=5'h17) /* 10000 - 17fff */ ;
        // Bank 3 size 0x08000
        bank[3] <=  ( layer==OBJ   && code[15:11]>=5'h18) /* 18000 - 1ffff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h18) /* 18000 - 1ffff */ 
        ||  ( layer==SCR1  && code[15:12]>=5'h18) /* 18000 - 1ffff */ 
        ||  ( layer==SCR3  && code[13:9]>=5'h18) /* 18000 - 1ffff */ ;
    end
game_pokonyan: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h2) /* 0 - 2fff */  ||
         ( layer==SCR1  && code[15:12]>=5'h7 && code[15:12]<=5'h7) /* 7000 - 7fff */  ||
         ( layer==SCR3  && code[13:9]>=5'h3 && code[13:9]<=5'h3) /* 3000 - 3fff */  ||
         ( layer==SCR2  && code[15:11]>=5'h4 && code[15:11]<=5'h6) /* 4000 - 6fff */ ;
        bank[1] <= 1'b0;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_pang3: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h9) /* 8000 - 9fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'h9) /* 8000 - 9fff */  ||
         ( layer==SCR1  && code[15:12]>=5'ha && code[15:12]<=5'hb) /* a000 - bfff */  ||
         ( layer==SCR3  && code[13:9]>=5'hc && code[13:9]<=5'hf) /* c000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_pang3: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h9) /* 8000 - 9fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'h9) /* 8000 - 9fff */  ||
         ( layer==SCR1  && code[15:12]>=5'ha && code[15:12]<=5'hb) /* a000 - bfff */  ||
         ( layer==SCR3  && code[13:9]>=5'hc && code[13:9]<=5'hf) /* c000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_pang3: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h9) /* 8000 - 9fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'h9) /* 8000 - 9fff */  ||
         ( layer==SCR1  && code[15:12]>=5'ha && code[15:12]<=5'hb) /* a000 - bfff */  ||
         ( layer==SCR3  && code[13:9]>=5'hc && code[13:9]<=5'hf) /* c000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
game_pang3: begin
        // Bank 0 size 0x08000
        bank[0] <=  ( layer==OBJ   && code[15:11]<=5'h7) /* 0 - 7fff */ 
        ||  ( layer==SCR2  && code[15:11]<=5'h7) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank[1] <=  ( layer==OBJ   && code[15:11]>=5'h8 && code[15:11]<=5'h9) /* 8000 - 9fff */ 
        ||  ( layer==SCR2  && code[15:11]>=5'h8 && code[15:11]<=5'h9) /* 8000 - 9fff */  ||
         ( layer==SCR1  && code[15:12]>=5'ha && code[15:12]<=5'hb) /* a000 - bfff */  ||
         ( layer==SCR3  && code[13:9]>=5'hc && code[13:9]<=5'hf) /* c000 - ffff */ ;
        bank[2] <= 1'b0;
        bank[3] <= 1'b0;
    end
