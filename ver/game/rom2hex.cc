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

void dump(const char *, ifstream& fin, int start, int end );

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

    dump("sdram_bank1.hex", fin, 0, snd_start ); // CPU
    dump("sdram_bank2.hex", fin, gfx_start, 0 ); // GFX
    dump("sdram_bank0.hex", fin, snd_start, gfx_start ); // GFX
}

void dump(const char *fname, ifstream& fin, int start, int end ) {
    const int header_size = 64;
    start += header_size;
    if( end )
        end += header_size;
    else {
        fin.seekg(0,ios_base::end);
        end = (int) fin.tellg();
    }
    fin.seekg( start );
    const int len=end-start+1;
    if( len <=0 ) return;

    char *data = new char[len];
    ofstream fout(fname);    
    fin.read(data,len);
    cout << "INFO: " << dec << len << " bytes dumped to " << fname << '\n';
    for( int k=0; k<len; k+=2 ) {
        int a = data[k+1];
        int b = data[k];
        a&=0xff;
        b&=0xff;
        a = (a<<8) | b;
        fout << hex << a << '\n';
    }
    delete []data;
    // Fill up to 8MB
    for( int k=len; k<8*1024*1024-1; k+=2 ) fout << "ffff\n";
}