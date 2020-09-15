#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int get_offset( char *b, int s ) {
    int a0 = b[s];
    int a1 = b[s+1];
    a0 &= 0xff;
    a1 &= 0xff;
    int a2 = (a1<<8) | a0;
    a2 <<= 10; // convert kB to bytes
    return a2;
}

void clear_bank( char *data );
void dump_bank( char *data, const char *fname );
void read_bank(char *data, ifstream& fin, int start, int end, int offset=0 );

int main(int argc, char *argv[]) {
    ifstream fin( argv[1], ios_base::binary );
    if( !fin.good() ) {
        cout << "ERROR: cannot open file " << argv[1] << '\n';
        return 1;
    }
    char header[64];
    fin.read( header, 64 );

    int snd_start = get_offset( header, 0 );
    int oki_start = get_offset( header, 2 );
    int gfx_start = get_offset( header, 4 );

    cout << "Sound start " << hex << snd_start << '\n';
    cout << "Oki   start " << hex << oki_start << '\n';
    cout << "GFX   start " << hex << gfx_start << '\n';

    char *data = new char[8*1024*1024];
    try{
        // Main CPU
        clear_bank( data );
        read_bank( data, fin, 0, snd_start );
        dump_bank( data, "sdram_bank1.hex" );
        // GFX
        clear_bank( data );
        read_bank( data, fin, gfx_start, 0 );
        dump_bank( data, "sdram_bank2.hex" );
        // Sound
        clear_bank( data );
        read_bank( data, fin, snd_start, oki_start );
        read_bank( data, fin, oki_start, gfx_start, 0x10000<<1 );
        dump_bank( data, "sdram_bank0.hex" );
    } catch( const char *s) {
        cout << "ERROR: " << s << '\n';
    }

    delete []data;
    return 0;
}

void clear_bank( char *data ) {
    const int v = ~0;
    int *b = (int*)data;
    for( int k=0; k<8*1024*1024; k+=sizeof(int) ) *b++=v;
}

void dump_bank( char *data, const char *fname ) {
    ofstream fout(fname);
    if( !fout.good() ) throw "Cannot open output file";
    for( int k=0; k<8*1024*1024; k+=2 ) {
        int a = data[k+1];
        int b = data[k];
        a&=0xff;
        b&=0xff;
        a = (a<<8) | b;
        fout << hex << a << '\n';
    }
}

void read_bank(char *data, ifstream& fin, int start, int end, int offset ) {
    const int header_size = 64;
    start += header_size;
    if( end )
        end += header_size;
    else {
        fin.seekg(0,ios_base::end);
        end = (int) fin.tellg();
    }
    fin.seekg( start, ios_base::beg );
    if( fin.eof() ) throw "input file reached EOF";
    if( !fin.good() ) throw "Cannot seek inside input file";
    const int len=end-start+1;
    if( len <=0 ) throw "Wrong offsets";
    data += offset;
    fin.read(data,len);
    fin.clear();
}