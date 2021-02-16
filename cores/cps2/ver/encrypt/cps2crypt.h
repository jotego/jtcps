#ifndef __MAME_DECRYPT
#define __MAME_DECRYPT

struct MAME_keys {
    uint32_t key[2];
    uint32_t upper;
};

int init_cps2crypt(char *m_key, MAME_keys& keys);

#endif