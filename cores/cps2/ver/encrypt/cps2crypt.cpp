#include <cstdint>
#include <cstdio>
#include "cps2crypt.h"

using namespace std;

int init_cps2crypt(char *m_key, MAME_keys& keys)
{
	unsigned short decoded[10] = { 0 };
	int first=159;
	bool found=false;
	for (int b = 0; b < 10 * 16; b++)
	{
		int bit = (317 - b) % 160;
		if ((m_key[bit / 8] >> ((bit ^ 7) % 8)) & 1)
		{
			decoded[b / 16] |= (0x8000 >> (b % 16));
		}
	}
	/*
	puts("MAME decoding:");
	for( int k=9; k>=0; k-- ) {
		for( int j=1; j>=0; j-- ) {
			int i = (decoded[k]>>(8*j))&0xff;
			printf("%02X",i);
			if( !found ) {
				for( int x=0x80; x>=1; x>>=1 ) {
					if( i&x ) {
						found =true;
						break;
					} else {
						first--;
					}
				}
			}
		}
	}
	//puts("");
	*/

	keys.key[0] = ((uint32_t)decoded[0] << 16) | decoded[1];
	keys.key[1] = ((uint32_t)decoded[2] << 16) | decoded[3];

	// decoded[4] == watchdog instruction third word
	// decoded[5] == watchdog instruction second word
	// decoded[6] == watchdog instruction first word
	// decoded[7] == 0x4000 (bits 8 to 23 of CPS2 object output address)
	// decoded[8] == 0x0900

	uint32_t lower;
	if (decoded[9] == 0xffff)
	{
		// On a dead board, the only encrypted range is actually FF0000-FFFFFF.
		// It doesn't start from 0, and it's the upper half of a 128kB bank.
		keys.upper = 0xffffff;
		lower = 0xff0000;
	}
	else
	{
		keys.upper = (((~decoded[9] & 0x3ff) << 14) | 0x3fff) + 1;
		lower = 0;
	}

	// we have a proper key so use it to decrypt
	// cps2_decrypt(machine(), (uint16_t *)memregion("maincpu")->base(), m_decrypted_opcodes, memregion("maincpu")->bytes(), key, lower / 2, upper / 2);
	return first;
}
