#include "Vjtcps2_fn1.h"
#include "cps2crypt.h"

#include <cstdio>
#include <cstring>

using namespace std;

class DUT {
public:
    Vjtcps2_fn1 sbox;
    int eval( int din, uint64_t key );
};

int main( int argc, char *argv[] ) {
    DUT dut;
    //optimised_sbox ref[4];
    //optimise_sboxes( ref, fn1_r1_boxes );
    for( int cnt=0; cnt<100'000'000; cnt++ ) {
        uint64_t k=0;
        for( int j=0; j<4; j++ ) {
            k |= rand();
            k <<= 16;
        }

        dut.eval( 0, k );

        uint32_t key1[4];
        uint32_t master_key[2];
        master_key[1] = (k>>32)&0xffff'ffff;
        master_key[0] = k&0xffff'ffff;
        // expand master key to 1st FN 96-bit key
        expand_1st_key(key1, master_key);

        // add extra bits for s-boxes with less than 6 inputs
        key1[0] ^= BIT(key1[0], 1) <<  4;
        key1[0] ^= BIT(key1[0], 2) <<  5;
        key1[0] ^= BIT(key1[0], 8) << 11;
        key1[1] ^= BIT(key1[1], 0) <<  5;
        key1[1] ^= BIT(key1[1], 8) << 11;
        key1[2] ^= BIT(key1[2], 1) <<  5;
        key1[2] ^= BIT(key1[2], 8) << 11;

        if( key1[0] != dut.sbox.key1 ||
            key1[1] != dut.sbox.key2 ||
            key1[2] != dut.sbox.key3 ||
            key1[3] != dut.sbox.key4
            ) {
            printf("Key1 %05X <> %05X\n", key1[0], dut.sbox.key1 );
            printf("Key2 %05X <> %05X\n", key1[1], dut.sbox.key2 );
            printf("Key3 %05X <> %05X\n", key1[2], dut.sbox.key3 );
            printf("Key4 %05X <> %05X\n", key1[3], dut.sbox.key4 );
            goto finish;
        }
        if( k&0xffff'ffffL==0 ) putchar('.');
    }
    puts("PASS");
    finish:
    return 0;
}


int DUT::eval( int din, uint64_t key ) {
    sbox.din = din;
    sbox.key = key;
    sbox.eval();
    return sbox.dout;
}