#include <cstdio>
#include <cstdlib>

int main() {
    float gsig[] = {1.0/220.0, 1.0/470, 1.0/1000.0, 1.0/2200.0 };
    float gbri[] = {1.0/100.0, 1.0/220.0, 1.0/470, 1.0/1000.0 };
    float gsum_sig;

    FILE *f = fopen("pal_lut.hex","w");

    for( int k=0; k<4; k++ ) gsum_sig+=gsig[k];

    for( int b=0; b<16; b++ ) {
        for( int s=0; s<16; s++ ) {
            float gh=0;
            float gsum=gsum_sig;
            if( s&1 ) gh += gsig[3];
            if( s&2 ) gh += gsig[2];
            if( s&4 ) gh += gsig[1];
            if( s&8 ) gh += gsig[0];

            if( (~b)&1 ) gsum += gbri[3];
            if( (~b)&2 ) gsum += gbri[2];
            if( (~b)&4 ) gsum += gbri[1];
            if( (~b)&8 ) gsum += gbri[0];

            float col = gh/gsum;
            int rnd = col*255;
            if( s==0 || s==15) printf("%x%x %.3f %X\n", b,s, col, rnd );
            fprintf(f, "%02X ", rnd );
            if( s==15 ) {
                putchar('\n');
                fprintf(f,"\n");
            }
        }
    }
    fclose(f);
    return 0;
}