#include "cps2crypt.h"
#include <cstdio>

using namespace std;

void parse_sbox( const sbox& sb );

int main() {
    parse_sbox( fn1_r1_boxes[0] );
    return 0;
}

void parse_sbox( const sbox& sb ) {
    printf("jtcps2_sbox #(\n    .LUT( {\n        ");
    for( int k=63; k>=0; k-- ) {
        printf("2'd%d", sb.table[k] );
        if( k!=0 ) printf(", ");
        if( (k&7)==0 && k!=0) printf("\n        ");
    }
    printf("\n    } ),\n    .LOC( { ");
    for( int k=5; k>=0; k-- ) {
        printf("3'd%d", sb.inputs[k]==-1 ? 0 : sb.inputs[k] );
        if( k!=0 ) printf(", ");
    }
    printf(" } ),\n    .OK( 6'b");
    for( int k=5; k>=0; k-- ) {
        printf("%d", sb.inputs[k]==-1 ? 0 : 1 );
    }
    printf(" )) u_sbox\n");
}