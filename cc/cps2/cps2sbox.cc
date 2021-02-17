#include "cps2crypt.h"
#include <cstdio>

using namespace std;

void parse_fn_r( const char *fn_name, const sbox* boxes );
void parse_sbox( const char *name, const sbox& sb, int keyoff );

int main() {
    puts(
"/*  This file is part of JTCPS1.\n"
"    JTCPS1 program is distributed in the hope that it will be useful,\n"
"    but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
"    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
"    GNU General Public License for more details.\n"
"\n"
"    You should have received a copy of the GNU General Public License\n"
"    along with JTCPS1.  If not, see <http://www.gnu.org/licenses/>.\n"
"\n"
"    Author: Jose Tejada Gomez. Twitter: @topapate\n"
"    Version: 1.0\n"
"    Date: 16-2-2021 */\n"
    );

    parse_fn_r( "fn1_r1", fn1_r1_boxes );
    parse_fn_r( "fn1_r2", fn1_r2_boxes );
    parse_fn_r( "fn1_r3", fn1_r3_boxes );
    parse_fn_r( "fn1_r4", fn1_r4_boxes );

    parse_fn_r( "fn2_r1", fn2_r1_boxes );
    parse_fn_r( "fn2_r2", fn2_r2_boxes );
    parse_fn_r( "fn2_r3", fn2_r3_boxes );
    parse_fn_r( "fn2_r4", fn2_r4_boxes );
    return 0;
}

void parse_fn_r( const char *fn_name, const sbox* boxes ) {
    printf("\nmodule jtcps2_sbox_%s(\n", fn_name );
    printf("    input  [ 7:0] din,\n"
           "    input  [23:0] key,\n"
           "    output [ 7:0] dout\n);\n\n"
    );
    for( int k=0; k<4; k++ ) {
        char name[32];
        sprintf( name, "%s_%d", fn_name, k );
        parse_sbox( name, boxes[k],  k*6 );
    }
    printf("endmodule\n\n");
}

void parse_sbox( const char *name, const sbox& sb, int keyoff ) {
    printf("    jtcps2_sbox #(\n        .LUT( {\n        ");
    for( int k=63; k>=0; k-- ) {
        printf("2'd%d", sb.table[k] );
        if( k!=0 ) printf(", ");
        if( (k&7)==0 && k!=0) printf("\n        ");
    }
    printf("\n        } ),\n        .LOC( { ");
    for( int k=5; k>=0; k-- ) {
        printf("3'd%d", sb.inputs[k]==-1 ? 0 : sb.inputs[k] );
        if( k!=0 ) printf(", ");
    }
    printf(" } ),\n        .OK ( 6'b");
    for( int k=5; k>=0; k-- ) {
        printf("%d", sb.inputs[k]==-1 ? 0 : 1 );
        if(k==4) putchar('_');
    }
    printf(" ))\n    u_sbox_%s(\n", name );
    printf("        .din ( din                  ),\n" );
    printf("        .key ( key[%2d:%-2d]           ),\n", keyoff+5, keyoff );
    printf("        .dout( { dout[%d], dout[%d] } )\n", sb.outputs[1], sb.outputs[0] );
    printf("    );\n\n");
}