#include <stdio.h>

int main(int argc, char *argv[]) {
    int dst=0;
    int src;
    src = strtol(argv[1],NULL,16);
    if ( src & 0x01) dst ^= 0x04;
    if ( src & 0x02) dst ^= 0x21;
    if ( src & 0x04) dst ^= 0x01;
    if (~src & 0x08) dst ^= 0x50;
    if ( src & 0x10) dst ^= 0x40;
    if ( src & 0x20) dst ^= 0x06;
    if ( src & 0x40) dst ^= 0x08;
    if (~src & 0x80) dst ^= 0x88;    
    printf("%X -> %X\n", src, dst);
}