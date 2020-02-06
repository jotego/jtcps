#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    while( !cin.eof() ) {
        int x;
        cin >> hex >> x;
        cout << hex << (x&0xff) << '\n';
        x >>= 8;
        cout << hex << (x&0xff) << '\n';
    }
    return 0;
}