#include <iostream>
#include <fstream>

using namespace std;

void read( char *buf, const char *fname, int wr, int rd, int step, int len=0x20000 );

int main() {
    ofstream fout("forgotna.rom",ios_base::app | ios_base::binary);
    char *buf = new char[0x400000];

    read(buf, "lw_2.2b",   0x000000, 0, 1 );
    read(buf, "lw_1.2a",   0x000001, 0, 1 );
    read(buf, "lw-08.9b",  0x000002, 0, 2, 0x80000 );
    read(buf, "lw-08.9b",  0x000003, 1, 2, 0x80000 );
    read(buf, "lw_18.5e",  0x000004, 0, 1 );
    read(buf, "lw_17.5c",  0x000005, 0, 1 );
    read(buf, "lw_30.8h",  0x000006, 0, 1 );
    read(buf, "lw_29.8f",  0x000007, 0, 1 );

    read(buf, "lw_4.3b",   0x100000, 0, 1 );
    read(buf, "lw_3.3a",   0x100001, 0, 1 );
    read(buf, "lw_20.7e",  0x100004, 0, 1 );
    read(buf, "lw_19.7c",  0x100005, 0, 1 );
    read(buf, "lw_32.9h",  0x100006, 0, 1 );
    read(buf, "lw_31.9f",  0x100007, 0, 1 );

    read(buf, "lw-02.6b",  0x200000, 0, 2, 0x80000 );
    read(buf, "lw-02.6b",  0x200001, 1, 2, 0x80000 );
    read(buf, "lw_14.10b", 0x200002, 0, 1 );
    read(buf, "lw_13.10a", 0x200003, 0, 1 );
    read(buf, "lw-06.9d",  0x200004, 0, 2, 0x80000 );
    read(buf, "lw-06.9d",  0x200005, 1, 2, 0x80000 );
    read(buf, "lw_26.10e", 0x200006, 0, 1 );
    read(buf, "lw_25.10c", 0x200007, 0, 1 );

    read(buf, "lw_16.11b", 0x300002, 0, 1 );
    read(buf, "lw_15.11a", 0x300003, 0, 1 );
    read(buf, "lw_28.11e", 0x300006, 0, 1 );
    read(buf, "lw_27.11c", 0x300007, 0, 1 );

    fout.write( buf, 0x400000);
    delete []buf;
}

void read( char *buf, const char *fname, int wr, int rd, int step, int len ) {
    ifstream fin(fname,ios_base::binary);
    if( !fin.good() ) cout << "ERROR: cannot open file " << fname << "\n";
    fin.seekg( rd );
    if( !fin.good() ) cout << "ERROR: cannot seek file " << fname << "\n";
    char *c = new char[1024];
    for( int k=0; k<len; ) {
        fin.read( c, 1024 );
        for( int j=0; j<1024; j+=step) {
            buf[wr] = c[j];
            wr+=8;
        }
        k+=1024;
    }
}