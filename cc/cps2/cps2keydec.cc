#include <cstdio>

int main( int argc, char *argv[] ) {

    //printf("assign cfg = {\n");
    for (int b = 0, j=0; b<160; b++)
    {
        int bit = (317 - b) % 160;
        int input = (bit ^ 7) % 8;
        int output = 15-(b%16);
        //printf("%2d=%03o[%o] -> %d=o%03o[%02o]  ", bit/8, bit, input, b/16, b, output );
        //printf("/* %03o */ raw[8'o%03o],", b^8, bit^7 );
        int s = bit;
        int d = b;
        if( s==1 && d!=0 ) {
            printf("bad s=%X, d=%X\n", s,d);
            return 1;
        }
        //printf("raw[8'o%03o], ", bit );
        //if( (j&7)==7 ) putchar('\n');
        //putchar('\n');
        j++;
    }
    putchar('\n');
    //printf("};\n");
    return 0;
}