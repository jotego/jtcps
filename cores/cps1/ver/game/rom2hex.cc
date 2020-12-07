// Creates hex files to be load in simulation in order to
// skip the ROM loading process
// The input ROM file must be created from an MRA file with the mra tool

// The output files are:
// sdram bank hex files
// CPS config data
// Q-Sound firmware

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
void dump_cfg( char header[64]);
void dump_kabuki( char header[64]);
void dump_qsnd( char *data );

int main(int argc, char *argv[]) {
    ifstream fin( argv[1], ios_base::binary );
    if( !fin.good() ) {
        cout << "ERROR: cannot open file " << argv[1] << '\n';
        return 1;
    }
    char header[64];
    bool qnsd_game=false;
    fin.read( header, 64 );

    int snd_start  = get_offset( header, 0 );
    int pcm_start  = get_offset( header, 2 );
    int gfx_start  = get_offset( header, 4 );
    int qsnd_start = get_offset( header, 6 );
    qnsd_game = qsnd_start != 0xffff*0x400;

    cout << "Sound start " << hex << snd_start << '\n';
    cout << "PCM   start " << hex << pcm_start << '\n';
    cout << "GFX   start " << hex << gfx_start << '\n';
    if( qnsd_game ) {
        cout << "Qsnd  start " << hex << qsnd_start << '\n';
    }

    dump_cfg( header );
    dump_kabuki( header );

    char *data = new char[8*1024*1024];
    try{
        // Main CPU
        clear_bank( data );
        read_bank( data, fin, 0, snd_start );
        dump_bank( data, "sdram_bank3.hex" );
        // GFX
        clear_bank( data );
        read_bank( data, fin, gfx_start, 0 );
        dump_bank( data, "sdram_bank2.hex" );
        // Sound
        clear_bank( data );
        read_bank( data, fin, snd_start, pcm_start );
        read_bank( data, fin, pcm_start, gfx_start, 0x10'0000<<1 );
        dump_bank( data, "sdram_bank1.hex" );
        // QSound firmware
        if( qnsd_game ) {
            read_bank( data, fin, qsnd_start, qsnd_start+0x2000 );
            dump_qsnd( data );
        }
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
        //fout << hex << setw(4) << setfill('0') << a << '\n';
        fout << hex << setw(4) << setfill('0') << a << '\n';
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
    const int len=end-start;
    if( len <=0 ) throw "Wrong offsets";
    data += offset;
    fin.read(data,len);
    fin.clear();
}

void dump_cfg( char header[64]) {
    ofstream fout("cps_cfg.hex");
    for( int k=0x27; k>=0x10; k-- ) {
        int j = header[k];
        j&=0xff;
        fout << "8'h" << hex << j;
        if( k!=0x10 ) fout << ',';
    }
}

void dump_kabuki( char header[64]) {
    ofstream fout("kabuki.hex");
    for( int k=0x30; k<=0x3a; k++ ) {
        int j = header[k];
        j&=0xff;
        fout << hex << setw(2) << setfill('0') << j;
    }
    fout << '\n';
}

void dump_qsnd( char *data ) {
    ofstream flsb("qsnd_lsb.hex");
    ofstream fmsb("qsnd_msb.hex");
    for( int k=0; k<0x2000; ) {
        int d;
        d = data[k++];
        flsb << hex << (d&0xff) << '\n';
        d = data[k++];
        fmsb << hex << (d&0xff) << '\n';
    }
}