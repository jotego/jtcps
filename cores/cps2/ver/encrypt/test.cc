#include "Vjtcps2_keyload.h"
#include "cps2crypt.h"

#include <cstdio>
#include <cstring>

using namespace std;

class DUT {
    Vjtcps2_keyload load;
public:
    void load_keys(char *buf);
    int64_t keys() {
        return load.key;
    }
    int upper_range() {
        return (((~load.addr_rng & 0x3ff)<<14) | 0x3fff) + 1;
    }
};

void buffer_load( const char*, char *);

void shift( char *b) {
    int c=0;
    for( int j=0; j<20; j++ ) {
        int nc = (b[j]>>7)&1;
        b[j] = (b[j]<<1) | c;
        c = nc;
    }
}

int main( int argc, char *argv[] ) {
    char buf_keys[20];
    DUT dut;
    MAME_keys mame_keys;

    memset( buf_keys, 0, 20 );
    buf_keys[0]=1;
    try {
        buffer_load( "spf2t/spf2t.key", buf_keys );
        //buffer_load( "t.key", buf_keys );
        dut.load_keys( buf_keys );
        init_cps2crypt( buf_keys, mame_keys );
        //for( int i=0; i<2; i++ )
        //for( int k=0; k<4; k++ )
        //    printf("%02X ", (mame_keys.key[i]>>(k<<3))&0xff );
        putchar('\n');
        // printf("%016lX\n", dut.keys() );
        // printf("Upper range: %X <> %X\n", mame_keys.upper, dut.upper_range() );
    } catch( int e ) {
        return e;
    }

    return 0;
}

void buffer_load( const char*fname, char *buf) {
    FILE *f = fopen(fname,"rb");
    if( f == NULL ) {
        printf("ERROR: cannot open key file %s\n", fname );
        throw 1;
    }
    int cnt = fread( buf, 1, 20, f );
    fclose(f);
    if( cnt != 20 ) {
        printf("ERROR: the key file %s is too short\n", fname );
        throw 2;
    }
}

void DUT::load_keys(char *buf) {
    load.clk=0;
    load.rst=1;
    load.din=0;
    load.din_we=0;
    load.eval();
    load.rst=0;
    load.eval();
    for( int k=0; k<20; k++ ) {
        load.din = buf[k];
        for( int j=0; j<4; j++ ) {
            load.din_we = (j&2) != 0;
            load.clk = j&1;
            load.eval();
        }
    }
    load.din_we=0;
    for( int j=0; j<4; j++ ) {
        load.clk=j&1;
        load.eval();
    }
}