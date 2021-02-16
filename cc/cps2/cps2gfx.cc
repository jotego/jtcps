/*

This is a test program to verify that the CPS2 GFX is
decoded correctly. Data is passed through the MAME unshuffle
routine and compared to an array created the way I read data
in the FPGA core

*/

#include <cstdlib>
#include <cstdio>
#include <cassert>

using namespace std;

void unshuffle( int64_t *buf, int len )
{
    int i;
    int64_t t;

    if (len == 2)
        return;

    assert(len % 4 == 0);   /* must not happen */

    len /= 2;

    unshuffle(buf, len);
    unshuffle(buf + len, len);

    for (i = 0; i < len / 2; i++)
    {
        t = buf[len / 2 + i];
        buf[len / 2 + i] = buf[len + i];
        buf[len + i] = t;
    }
}

int main() {
    const int LEN = 0x20'0000;
    const int MASK = (LEN/8)-1;
    int64_t *b = new int64_t[ LEN/8 ];
    int64_t *c = new int64_t[ LEN/8 ];
    for( int k=0; k<LEN/8; k++ ) {
        int kx = //k<0x20'0000 ?
            (
                (k>>1) | ( (k&1)<< 17 )
            );// :k;
        b[ k] =k;
        kx &= MASK;
        c[kx] = b[k];
    }

    unshuffle( (int64_t*) b, LEN/8 );
    //for( int k=0, j=0; j<64; j++) {
    bool good = true;
    for( int k=0; k<LEN/8; k++) {
        if( c[k] != b[k] ) {
            printf("%04X %8lX <> %8lX %c\n",
                k, b[k]&0xffff'ffff, c[k]&0xffff'ffff, b[k]!=c[k] ? '*' : ' '
                );
            good = false;
            break;
        }
        //k++;
    }
    if( good ) puts("PASS");
    delete []b;
    delete []c;
    return 0;
}