#include "romsets.h"
#include "mappers.h"

#define __not_applicable__  -1,-1,-1,-1,-1,-1,-1
#define CPS_B_01      -1, 0x0000,          __not_applicable__,          0x26,{0x28,0x2a,0x2c,0x2e},0x30, {0x02,0x04,0x08,0x30,0x30}
#define CPS_B_02     0x20,0x0002,          __not_applicable__,          0x2c,{0x2a,0x28,0x26,0x24},0x22, {0x02,0x04,0x08,0x00,0x00}
#define CPS_B_03      -1, 0x0000,          __not_applicable__,          0x30,{0x2e,0x2c,0x2a,0x28},0x26, {0x20,0x10,0x08,0x00,0x00}
#define CPS_B_04     0x20,0x0004,          __not_applicable__,          0x2e,{0x26,0x30,0x28,0x32},0x2a, {0x02,0x04,0x08,0x00,0x00}
#define CPS_B_05     0x20,0x0005,          __not_applicable__,          0x28,{0x2a,0x2c,0x2e,0x30},0x32, {0x02,0x08,0x20,0x14,0x14}
#define CPS_B_11     0x32,0x0401,          __not_applicable__,          0x26,{0x28,0x2a,0x2c,0x2e},0x30, {0x08,0x10,0x20,0x00,0x00}
#define CPS_B_12     0x20,0x0402,          __not_applicable__,          0x2c,{0x2a,0x28,0x26,0x24},0x22, {0x02,0x04,0x08,0x00,0x00}
#define CPS_B_13     0x2e,0x0403,          __not_applicable__,          0x22,{0x24,0x26,0x28,0x2a},0x2c, {0x20,0x02,0x04,0x00,0x00}
#define CPS_B_14     0x1e,0x0404,          __not_applicable__,          0x12,{0x14,0x16,0x18,0x1a},0x1c, {0x08,0x20,0x10,0x00,0x00}
#define CPS_B_15     0x0e,0x0405,          __not_applicable__,          0x02,{0x04,0x06,0x08,0x0a},0x0c, {0x04,0x02,0x20,0x00,0x00}
#define CPS_B_16     0x00,0x0406,          __not_applicable__,          0x0c,{0x0a,0x08,0x06,0x04},0x02, {0x10,0x0a,0x0a,0x00,0x00}
#define CPS_B_17     0x08,0x0407,          __not_applicable__,          0x14,{0x12,0x10,0x0e,0x0c},0x0a, {0x08,0x14,0x02,0x00,0x00}   // the sf2 -> strider conversion needs 0x04 for the 2nd layer enable on one level, gfx confirmed to appear on the PCB, register at the time is 0x8e, so 0x10 is not set.
#define CPS_B_18     0x10,0x0408,          __not_applicable__,          0x1c,{0x1a,0x18,0x16,0x14},0x12, {0x10,0x08,0x02,0x00,0x00}
#define CPS_B_21_DEF 0x32,  -1,   0x00,0x02,0x04,0x06, 0x08, -1,  -1,   0x26,{0x28,0x2a,0x2c,0x2e},0x30, {0x02,0x04,0x08,0x30,0x30} // pang3 sets layer enable to 0x26 on startup
#define CPS_B_21_BT1 0x32,0x0800, 0x0e,0x0c,0x0a,0x08, 0x06,0x04,0x02,  0x28,{0x26,0x24,0x22,0x20},0x30, {0x20,0x04,0x08,0x12,0x12}
#define CPS_B_21_BT2  -1,   -1,   0x1e,0x1c,0x1a,0x18,  -1, 0x0c,0x0a,  0x20,{0x2e,0x2c,0x2a,0x28},0x30, {0x30,0x08,0x30,0x00,0x00}
#define CPS_B_21_BT3  -1,   -1,   0x06,0x04,0x02,0x00, 0x0e,0x0c,0x0a,  0x20,{0x2e,0x2c,0x2a,0x28},0x30, {0x20,0x12,0x12,0x00,0x00}
#define CPS_B_21_BT4  -1,   -1,   0x06,0x04,0x02,0x00, 0x1e,0x1c,0x1a,  0x28,{0x26,0x24,0x22,0x20},0x30, {0x20,0x10,0x02,0x00,0x00}
#define CPS_B_21_BT5 0x32,  -1,   0x0e,0x0c,0x0a,0x08, 0x1e,0x1c,0x1a,  0x20,{0x2e,0x2c,0x2a,0x28},0x30, {0x20,0x04,0x02,0x00,0x00}
#define CPS_B_21_BT6  -1,   -1,    -1,  -1,  -1,  -1,   -1,  -1,  -1,   0x20,{0x2e,0x2c,0x2a,0x28},0x30, {0x20,0x14,0x14,0x00,0x00}
#define CPS_B_21_BT7  -1,   -1,    -1,  -1,  -1,  -1,   -1,  -1,  -1,   0x2c,{ -1,  -1,  -1,  -1 },0x12, {0x14,0x02,0x14,0x00,0x00}
#define CPS_B_21_QS1  -1,   -1,    -1,  -1,  -1,  -1,   -1,  -1,  -1,   0x22,{0x24,0x26,0x28,0x2a},0x2c, {0x10,0x08,0x04,0x00,0x00}
#define CPS_B_21_QS2  -1,   -1,    -1,  -1,  -1,  -1,   -1, 0x2e,0x20,  0x0a,{0x0c,0x0e,0x00,0x02},0x04, {0x16,0x16,0x16,0x00,0x00}
#define CPS_B_21_QS3 0x0e,0x0c00,  -1,  -1,  -1,  -1,  0x2c, -1,  -1,   0x12,{0x14,0x16,0x08,0x0a},0x0c, {0x04,0x02,0x20,0x00,0x00}
#define CPS_B_21_QS4 0x2e,0x0c01,  -1,  -1,  -1,  -1,  0x1c,0x1e,0x08,  0x16,{0x00,0x02,0x28,0x2a},0x2c, {0x04,0x08,0x10,0x00,0x00}
#define CPS_B_21_QS5 0x1e,0x0c02,  -1,  -1,  -1,  -1,  0x0c, -1,  -1,   0x2a,{0x2c,0x2e,0x30,0x32},0x1c, {0x04,0x08,0x10,0x00,0x00}
#define HACK_B_1      -1,   -1,    -1,  -1,  -1,  -1,   -1,  -1,  -1,   0x14,{0x12,0x10,0x0e,0x0c},0x0a, {0x0e,0x0e,0x0e,0x30,0x30}
#define HACK_B_2      -1,   -1,   0x0e,0x0c,0x0a,0x08, 0x06,0x04,0x02,  0x28,{0x26,0x24,0x22,0x20},0x22, {0x20,0x04,0x08,0x12,0x12}

struct CPS1config
{
    const char *name;             /* game driver name */

    /* Some games interrogate a couple of registers on bootup. */
    /* These are CPS1 board B self test checks. They wander from game to */
    /* game. */
    int cpsb_addr;        /* CPS board B test register address */
    int cpsb_value;       /* CPS board B test register expected value */

    /* some games use as a protection check the ability to do 16-bit multiplies */
    /* with a 32-bit result, by writing the factors to two ports and reading the */
    /* result from two other ports. */
    /* It looks like this feature was introduced with 3wonders (CPSB ID = 08xx) */
    int mult_factor1;
    int mult_factor2;
    int mult_result_lo;
    int mult_result_hi;

    /* unknown registers which might be related to the multiply protection */
    int unknown1;
    int unknown2;
    int unknown3;

    int layer_control;
    int priority[4];
    int palette_control;

    /* ideally, the layer enable masks should consist of only one bit, */
    /* but in many cases it is unknown which bit is which. */
    int layer_enable_mask[5];
    int bank_size[4];
    const gfx_range *ranges;
    /* some C-boards have additional I/O for extra buttons/extra players */
    int in2_addr;
    int in3_addr;
    int out2_addr;

    int bootleg_kludge;
};

static const struct CPS1config cps1_config_table[]=
{
    /* name         CPSB          gfx mapper   in2  in3  out2   kludge */
    {"forgottn",    CPS_B_01,      mapper_LW621 },
    {"forgottna",   CPS_B_01,      mapper_LW621 },
    {"forgottnu",   CPS_B_01,      mapper_LW621 },
    {"forgottnue",  CPS_B_01,      mapper_LWCHR },
    {"forgottnuc",  CPS_B_01,      mapper_LWCHR },
    {"forgottnua",  CPS_B_01,      mapper_LWCHR },
    {"forgottnuaa", CPS_B_01,      mapper_LWCHR },
    {"lostwrld",    CPS_B_01,      mapper_LWCHR },
    {"lostwrldo",   CPS_B_01,      mapper_LWCHR },
    {"ghouls",      CPS_B_01,      mapper_DM620 },
    {"ghoulsu",     CPS_B_01,      mapper_DM620 },
    {"daimakai",    CPS_B_01,      mapper_DM22A },   // equivalent to DM620
    {"daimakair",   CPS_B_21_DEF,  mapper_DAM63B },  // equivalent to DM620, also CPS_B_21_DEF is equivalent to CPS_B_01
    {"strider",     CPS_B_01,      mapper_ST24M1 },
    {"striderua",   CPS_B_01,      mapper_ST24M1 },  // wrong, this set uses ST24B2, still not dumped
    {"strideruc",   CPS_B_17,      mapper_ST24M1 },  // wrong?
    {"striderj",    CPS_B_01,      mapper_ST22B },   // equivalent to ST24M1
    {"striderjr",   CPS_B_21_DEF,  mapper_ST24M1 },  // wrong, this set uses STH63B, still not dumped
    {"dynwar",      CPS_B_02,      mapper_TK22B },   // wrong, this set uses TK24B1, dumped but equations still not added
    {"dynwara",     CPS_B_02,      mapper_TK22B },
    {"dynwarj",     CPS_B_02,      mapper_TK22B },
    {"dynwarjr",    CPS_B_21_DEF,  mapper_TK22B },   // wrong, this set uses TK163B, still not dumped
    {"willow",      CPS_B_03,      mapper_WL24B },
    {"willowu",     CPS_B_03,      mapper_WL24B },
    {"willowuo",    CPS_B_03,      mapper_WL24B },
    {"willowj",     CPS_B_03,      mapper_WL24B },   // wrong, this set uses WL22B, still not dumped
    {"ffight",      CPS_B_04,      mapper_S224B },
    {"ffighta",     CPS_B_04,      mapper_S224B },
    {"ffightu",     CPS_B_04,      mapper_S224B },
    {"ffightu1",    CPS_B_04,      mapper_S224B },
    {"ffightua",    CPS_B_01,      mapper_S224B },
    {"ffightub",    CPS_B_03,      mapper_S224B },   // had 04 handwritten on the CPS_B chip, but clearly isn't.
    {"ffightuc",    CPS_B_05,      mapper_S224B },
    {"ffightj",     CPS_B_04,      mapper_S224B },   // wrong, this set uses S222B
    {"ffightj1",    CPS_B_01,      mapper_S224B },   // wrong, this set uses S222B
    {"ffightj2",    CPS_B_02,      mapper_S224B },   // wrong, this set uses S222B
    {"ffightj3",    CPS_B_03,      mapper_S224B },   // wrong, this set uses S222B
    {"ffightj4",    CPS_B_05,      mapper_S224B },   // wrong, this set uses S222B
    {"ffightjh",    CPS_B_01,      mapper_S224B },   // wrong, ffightjh hack doesn't even use the S222B PAL, since replaced with a GAL.
    {"1941",        CPS_B_05,      mapper_YI24B },
    {"1941r1",      CPS_B_05,      mapper_YI24B },
    {"1941u",       CPS_B_05,      mapper_YI24B },
    {"1941j",       CPS_B_05,      mapper_YI24B },   // wrong, this set uses YI22B, dumped but equations still not added
    {"unsquad",     CPS_B_11,      mapper_AR24B },
    {"area88",      CPS_B_11,      mapper_AR22B },   // equivalent to AR24B
    {"area88r",     CPS_B_21_DEF,  mapper_AR22B },   // wrong, this set uses ARA63B, still not dumped
    {"mercs",       CPS_B_12,      mapper_O224B, 0x36, 0, 0x34 },
    {"mercsu",      CPS_B_12,      mapper_O224B, 0x36, 0, 0x34 },
    {"mercsur1",    CPS_B_12,      mapper_O224B, 0x36, 0, 0x34 },
    {"mercsj",      CPS_B_12,      mapper_O224B, 0x36, 0, 0x34 },   // wrong, this set uses O222B, still not dumped
    {"msword",      CPS_B_13,      mapper_MS24B },
    {"mswordr1",    CPS_B_13,      mapper_MS24B },
    {"mswordu",     CPS_B_13,      mapper_MS24B },
    {"mswordj",     CPS_B_13,      mapper_MS24B },   // wrong, this set uses MS22B, dumped but equations still not added
    {"mtwins",      CPS_B_14,      mapper_CK24B },
    {"chikij",      CPS_B_14,      mapper_CK24B },   // wrong, this set uses CK22B, dumped but equations still not added
    {"nemo",        CPS_B_15,      mapper_NM24B },
    {"nemor1",      CPS_B_15,      mapper_NM24B },
    {"nemoj",       CPS_B_15,      mapper_NM24B },   // wrong, this set uses NM22B, still not dumped
    {"cawing",      CPS_B_16,      mapper_CA24B },
    {"cawingr1",    CPS_B_16,      mapper_CA24B },
    {"cawingu",     CPS_B_05,      mapper_CA22B },   // equivalent to CA24B
    {"cawingur1",   CPS_B_16,      mapper_CA24B },
    {"cawingj",     CPS_B_16,      mapper_CA22B },   // equivalent to CA24B
    {"cawingbl",    CPS_B_16,      mapper_CA22B },   // equivalent to CA24B
    {"sf2",         CPS_B_11,      mapper_STF29,   0x36 },
    {"sf2ea",       CPS_B_17,      mapper_STF29,   0x36 },
    {"sf2eb",       CPS_B_17,      mapper_STF29,   0x36 },
    {"sf2ed",       CPS_B_05,      mapper_STF29,   0x36 },
    {"sf2ee",       CPS_B_18,      mapper_STF29,   0x3c },
    {"sf2em",       CPS_B_17,      mapper_STF29,   0x36 },
    {"sf2en",       CPS_B_17,      mapper_STF29,   0x36 },
    {"sf2ebbl",     CPS_B_17,      mapper_STF29 }, //   0x36, 0, 0, 1  },
    {"sf2ebbl2",    CPS_B_17,      mapper_STF29 }, //   0x36, 0, 0, 1  },
    {"sf2ebbl3",    CPS_B_17,      mapper_STF29 }, //   0x36, 0, 0, 1  },
    {"sf2stt",      CPS_B_17,      mapper_STF29 }, //   0x36, 0, 0, 1  },
    {"sf2rk",       CPS_B_17,      mapper_STF29 }, //   0x36, 0, 0, 1  },
    {"sf2ua",       CPS_B_17,      mapper_STF29,   0x36 },
    {"sf2ub",       CPS_B_17,      mapper_STF29,   0x36 },
    {"sf2uc",       CPS_B_12,      mapper_STF29,   0x36 },
    {"sf2ud",       CPS_B_05,      mapper_STF29,   0x36 },
    {"sf2ue",       CPS_B_18,      mapper_STF29,   0x3c },
    {"sf2uf",       CPS_B_15,      mapper_STF29,   0x36 },
    {"sf2ug",       CPS_B_11,      mapper_STF29,   0x36 },
    {"sf2uh",       CPS_B_13,      mapper_STF29,   0x36 },
    {"sf2ui",       CPS_B_14,      mapper_STF29,   0x36 },
    {"sf2uk",       CPS_B_17,      mapper_STF29,   0x36 },
    {"sf2j",        CPS_B_13,      mapper_STF29,   0x36 },
    {"sf2j17",      CPS_B_17,      mapper_STF29,   0x36 },
    {"sf2ja",       CPS_B_17,      mapper_STF29,   0x36 },
    {"sf2jc",       CPS_B_12,      mapper_STF29,   0x36 },
    {"sf2jf",       CPS_B_15,      mapper_STF29,   0x36 },
    {"sf2jh",       CPS_B_13,      mapper_STF29,   0x36 },
    {"sf2jl",       CPS_B_17,      mapper_STF29,   0x36 },
    {"sf2qp1",      CPS_B_17,      mapper_STF29,   0x36 },
    {"sf2qp2",      CPS_B_14,      mapper_STF29,   0x36 },
    {"sf2thndr",    CPS_B_17,      mapper_STF29,   0x36 },
    {"sf2thndr2",   CPS_B_17,      mapper_STF29,   0x36 },

    /* from here onwards the CPS-B board has suicide battery and multiply protection */

    {"3wonders",    CPS_B_21_BT1,  mapper_RT24B },
    {"3wondersr1",  CPS_B_21_BT1,  mapper_RT24B },
    {"3wondersu",   CPS_B_21_BT1,  mapper_RT24B },
    {"wonder3",     CPS_B_21_BT1,  mapper_RT22B },   // equivalent to RT24B
    {"3wondersb",   CPS_B_21_BT1,  mapper_RT24B, 0x36, 0, 0, 0x88 }, // same as 3wonders except some registers are hard wired rather than written to
    {"3wondersh",   HACK_B_2,      mapper_RT24B },  // one port is changed from 3wonders, and no protection
    {"kod",         CPS_B_21_BT2,  mapper_KD29B, 0x36, 0, 0x34 },
    {"kodr1",       CPS_B_21_BT2,  mapper_KD29B, 0x36, 0, 0x34 },
    {"kodr2",       CPS_B_21_BT2,  mapper_KD29B, 0x36, 0, 0x34 },
    {"kodu",        CPS_B_21_BT2,  mapper_KD29B, 0x36, 0, 0x34 },
    {"kodj",        CPS_B_21_BT2,  mapper_KD29B, 0x36, 0, 0x34 },
    {"kodja",       CPS_B_21_BT2,  mapper_KD29B, 0x36, 0, 0x34 },   // wrong, this set uses KD22B, still not dumped
    {"kodb",        CPS_B_21_BT2,  mapper_KD29B, 0x36, 0, 0x34 },   /* bootleg, doesn't use multiply protection */
    {"captcomm",    CPS_B_21_BT3,  mapper_CC63B, 0x36, 0x38, 0x34 },
    {"captcommr1",  CPS_B_21_BT3,  mapper_CC63B, 0x36, 0x38, 0x34 },
    {"captcommu",   CPS_B_21_BT3,  mapper_CC63B, 0x36, 0x38, 0x34 },
    {"captcommj",   CPS_B_21_BT3,  mapper_CC63B, 0x36, 0x38, 0x34 },
    {"captcommjr1", CPS_B_21_BT3,  mapper_CC63B, 0x36, 0x38, 0x34 },
    {"captcommb",   CPS_B_21_BT3,  mapper_CC63B, 0x36, 0x38, 0x34, 3 },
    {"captcommb2",  CPS_B_21_BT4,  mapper_CC63B },  // junk around health bar with default cps2 mapper, uses BT4(knights) config
    {"knights",     CPS_B_21_BT4,  mapper_KR63B, 0x36, 0, 0x34 },
    {"knightsu",    CPS_B_21_BT4,  mapper_KR63B, 0x36, 0, 0x34 },
    {"knightsj",    CPS_B_21_BT4,  mapper_KR63B, 0x36, 0, 0x34 },
    {"knightsja",   CPS_B_21_BT4,  mapper_KR63B, 0x36, 0, 0x34 },   // wrong, this set uses KR22B, still not dumped
    {"knightsb2",   CPS_B_21_BT4,  mapper_KR63B, 0x36, 0, 0x34 },   // wrong, knightsb bootleg doesn't use the KR63B PAL
    //{"knightsb",    CPS_B_21_BT4,  mapper_KR63B }, //   0x36, 0, 0x34 },   // wrong, knightsb bootleg doesn't use the KR63B PAL
    {"knightsb3",   CPS_B_21_BT4,  mapper_KR63B },
    {"pokonyan",    CPS_B_21_DEF,  mapper_pokonyan,  0x36 },
    {"sf2ce",       CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"sf2ceea",     CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"sf2ceua",     CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"sf2ceub",     CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"sf2ceuc",     CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"sf2cet",      CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"sf2ceja",     CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"sf2cejb",     CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"sf2cejc",     CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"sf2bhh",      CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"sf2rb",       CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"sf2rb2",      CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"sf2rb3",      CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"sf2red",      CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"sf2redp2",    CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"sf2v004",     CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"sf2acc",      CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"sf2ceblp",    CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"sf2cebltw",   CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"sf2acca",     CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"sf2accp2",    CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"sf2amf",      CPS_B_21_DEF,  mapper_S9263B,  0x36, 0, 0, 1 }, // probably wrong but this set is not completely dumped anyway
    {"sf2amf2",     CPS_B_21_DEF,  mapper_S9263B,  0x36, 0, 0, 1 },
    {"sf2amf3",     CPS_B_21_DEF,  mapper_S9263B,  0x36, 0, 0, 1 },
    {"sf2dkot2",    CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"sf2level",    HACK_B_1,      mapper_S9263B,  0,    0, 0, 2 },
    {"sf2m1",       CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"sf2m2",       CPS_B_21_DEF,  mapper_S9263B,  0x36, 0, 0, 1 },
    {"sf2m3",       HACK_B_1,      mapper_S9263B,  0,    0, 0, 2 },
    {"sf2m4",       HACK_B_1,      mapper_S9263B,  0x36, 0, 0, 1 },
    {"sf2m5",       CPS_B_21_DEF,  mapper_S9263B,  0x36, 0, 0, 1 },
    {"sf2m6",       CPS_B_21_DEF,  mapper_S9263B,  0x36, 0, 0, 1 },
    {"sf2m7",       CPS_B_21_DEF,  mapper_S9263B,  0x36, 0, 0, 1 },
    {"sf2m8",       HACK_B_1,      mapper_S9263B,  0,    0, 0, 2 },
    {"sf2m9",       CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"sf2m10",      HACK_B_1,      mapper_S9263B,  0x36, 0, 0, 1 },
    {"sf2dongb",    CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"sf2yyc",      CPS_B_21_DEF,  mapper_S9263B,  0x36, 0, 0, 1 },
    {"sf2koryu",    CPS_B_21_DEF,  mapper_S9263B,  0x36, 0, 0, 1 },
    {"sf2mdt",      CPS_B_21_DEF,  mapper_S9263B,  0x36, 0, 0, 1 },
    {"sf2mdta",     CPS_B_21_DEF,  mapper_S9263B,  0x36, 0, 0, 1 },
    {"sf2mdtb",     CPS_B_21_DEF,  mapper_S9263B,  0x36, 0, 0, 1 },
    {"sf2ceb",      CPS_B_21_DEF,  mapper_S9263B,  0x36, 0, 0, 1 },
    {"sf2b",        CPS_B_17,      mapper_STF29 ,  0x36, 0, 0, 1 },
    {"sf2b2",       CPS_B_17,      mapper_STF29 ,  0x36, 0, 0, 1 },
    {"sf2ceupl",    HACK_B_1,      mapper_S9263B,  0x36, 0, 0, 1 },
    {"sf2rules",    HACK_B_1,      mapper_S9263B,  0x36, 0, 0, 2 },
    {"sf2ceds6",    HACK_B_1,      mapper_S9263B,  0,    0, 0, 2 },
    {"sf2cems6a",   HACK_B_1,      mapper_S9263B,  0,    0, 0, 2 },
    {"sf2cems6b",   HACK_B_1,      mapper_S9263B,  0,    0, 0, 2 },
    {"sf2cems6c",   HACK_B_1,      mapper_S9263B,  0,    0, 0, 2 },
    {"sf2re",       HACK_B_1,      mapper_S9263B,  0,    0, 0, 2 },
    {"varth",       CPS_B_04,      mapper_VA63B },   /* CPSB test has been patched out (60=0008) register is also written to, possibly leftover from development */  // wrong, this set uses VA24B, dumped but equations still not added
    {"varthb",      CPS_B_04,      mapper_VA63B }, //  0, 0, 0, 0x0F },
    {"varthr1",     CPS_B_04,      mapper_VA63B },   /* CPSB test has been patched out (60=0008) register is also written to, possibly leftover from development */  // wrong, this set uses VA24B, dumped but equations still not added
    {"varthu",      CPS_B_04,      mapper_VA63B },   /* CPSB test has been patched out (60=0008) register is also written to, possibly leftover from development */
    {"varthj",      CPS_B_21_BT5,  mapper_VA22B },   /* CPSB test has been patched out (72=0001) register is also written to, possibly leftover from development */
    {"varthjr",     CPS_B_21_BT5,  mapper_VA63B },   /* CPSB test has been patched out (72=0001) register is also written to, possibly leftover from development */
    {"cworld2j",    CPS_B_21_BT6,  mapper_Q522B, 0x36, 0, 0x34 },   /* (ports 36, 34 probably leftover input code from another game) */
    {"cworld2ja",   CPS_B_21_DEF,  mapper_Q522B }, // patched set, no battery, could be desuicided // wrong, this set uses Q529B, still not dumped
    {"cworld2jb",   CPS_B_21_BT6,  mapper_Q522B, 0x36, 0, 0x34 }, // wrong, this set uses Q563B, still not dumped
    {"wof",         CPS_B_21_QS1,  mapper_TK263B },
    {"wofr1",       CPS_B_21_DEF,  mapper_TK263B },
    {"wofa",        CPS_B_21_DEF,  mapper_TK263B },  // patched set coming from a desuicided board?
    {"wofu",        CPS_B_21_QS1,  mapper_TK263B },
    {"wofj",        CPS_B_21_QS1,  mapper_TK263B },
    {"wofhfh",      CPS_B_21_DEF,  mapper_TK263B, 0x36 },    /* Chinese bootleg */
    {"dino",        CPS_B_21_QS2,  mapper_CD63B },   /* layer enable never used */
    {"dinou",       CPS_B_21_QS2,  mapper_CD63B },   /* layer enable never used */
    {"dinoj",       CPS_B_21_QS2,  mapper_CD63B },   /* layer enable never used */
    {"dinoa",       CPS_B_21_QS2,  mapper_CD63B },   /* layer enable never used */
    {"dinopic",     CPS_B_21_QS2,  mapper_CD63B },   /* layer enable never used */
    {"dinopic2",    CPS_B_21_QS2,  mapper_CD63B },   /* layer enable never used */
    {"dinohunt",    CPS_B_21_DEF,  mapper_CD63B },   /* Chinese bootleg */
    {"punisher",    CPS_B_21_QS3,  mapper_PS63B },
    {"punisheru",   CPS_B_21_QS3,  mapper_PS63B },
    {"punisherh",   CPS_B_21_QS3,  mapper_PS63B },
    {"punisherj",   CPS_B_21_QS3,  mapper_PS63B },
    {"punipic",     CPS_B_21_QS3,  mapper_PS63B },
    {"punipic2",    CPS_B_21_QS3,  mapper_PS63B },
    {"punipic3",    CPS_B_21_QS3,  mapper_PS63B },
    {"punisherbz",  CPS_B_21_DEF,  mapper_PS63B },   /* Chinese bootleg */
    {"slammast",    CPS_B_21_QS4,  mapper_MB63B },
    {"slammastu",   CPS_B_21_QS4,  mapper_MB63B },
    {"slampic",     CPS_B_21_QS4,  mapper_MB63B },
    {"slampic2",    CPS_B_21_QS4,  mapper_sfzch },  // default cps2 mapper breaks scroll layers
    {"mbomberj",    CPS_B_21_QS4,  mapper_MB63B },
    {"mbombrd",     CPS_B_21_QS5,  mapper_MB63B },
    {"mbombrdj",    CPS_B_21_QS5,  mapper_MB63B },
    {"sf2hf",       CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"sf2hfu",      CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"sf2hfj",      CPS_B_21_DEF,  mapper_S9263B,  0x36 },
    {"qad",         CPS_B_21_BT7,  mapper_QD22B,   0x36 },    /* TODO: layer enable (port 36 probably leftover input code from another game) */
    {"qadjr",       CPS_B_21_DEF,  mapper_QAD63B,  0x36, 0x38, 0x34 },    /* (ports 36, 38, 34 probably leftover input code from another game) */
    {"qtono2j",     CPS_B_21_DEF,  mapper_TN2292,  0x36, 0x38, 0x34 },    /* (ports 36, 38, 34 probably leftover input code from another game) */
    {"megaman",     CPS_B_21_DEF,  mapper_RCM63B },
    {"megamana",    CPS_B_21_DEF,  mapper_RCM63B },
    {"rockmanj",    CPS_B_21_DEF,  mapper_RCM63B },
    {"pnickj",      CPS_B_21_DEF,  mapper_PKB10B },
    {"pang3",       CPS_B_21_DEF,  mapper_pang3 },   /* EEPROM port is among the CPS registers (handled by DRIVER_INIT) */   // should use one of these three CP1B1F,CP1B8K,CP1B9KA
    {"pang3r1",     CPS_B_21_DEF,  mapper_pang3 },   /* EEPROM port is among the CPS registers (handled by DRIVER_INIT) */   // should use one of these three CP1B1F,CP1B8K,CP1B9K
    {"pang3j",      CPS_B_21_DEF,  mapper_pang3 },   /* EEPROM port is among the CPS registers (handled by DRIVER_INIT) */   // should use one of these three CP1B1F,CP1B8K,CP1B9K
    {"pang3b",      CPS_B_21_DEF,  mapper_pang3 },   /* EEPROM port is among the CPS registers (handled by DRIVER_INIT) */   // should use one of these three CP1B1F,CP1B8K,CP1B9K
    {"ganbare",     CPS_B_21_DEF,  mapper_sfzch },   // wrong, this set uses GBPR2, dumped but equations still not added

    /* CPS Changer */

    {"sfach",       CPS_B_21_DEF,  mapper_sfzch },   // wrong, this set uses an unknown PAL, still not dumped
    {"sfzbch",      CPS_B_21_DEF,  mapper_sfzch },   // wrong, this set uses an unknown PAL, still not dumped
    {"sfzch",       CPS_B_21_DEF,  mapper_sfzch },   // wrong, this set uses an unknown PAL, still not dumped
    {"wofch",       CPS_B_21_DEF,  mapper_TK263B },

    /* CPS2 games */

    {"cps2",        CPS_B_21_DEF,  mapper_cps2 },

    /* CPS1 board + extra support boards */

    {"kenseim",     CPS_B_21_DEF,  mapper_KNM10B },  // wrong, need to convert equations from PAL

    {nullptr}     /* End of table */
};
