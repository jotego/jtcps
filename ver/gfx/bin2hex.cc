#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    while( true ) {
        unsigned char b[2];
        cin.read((char*)&b[1],1);
        cin.read((char*)&b[0],1);
        if(cin.eof()) break;
        unsigned v = b[0] | (b[1]<<8);
        cout << hex << v << '\n';
    }
    return 0;
}