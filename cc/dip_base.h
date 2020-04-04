#ifndef __DIPBASE
#define __DIPBASE

enum PORTS_TYPE {
    cps1_2b,
    cps1_2b_4way,
    cps1_3b,
    cps1_3players,
    cps1_4players,
    cps1_6b,
    cps1_quiz,
    parent,
    sf2hack,
    ports_ganbare,
    ports_sfzch
};

struct port_entry {
    PORTS_TYPE ports_type;
    port_entry( PORTS_TYPE pt ) { ports_type = pt; }
};

// define new entry
#define INPUT_PORTS_START( name ) port_entry port_##name
#define PORT_INCLUDE( ports ) (ports)
#define INPUT_PORTS_END ;

// empty macros
#define CPS1_COINAGE_1(...)
#define CPS1_COINAGE_2(...)
#define CPS1_COINAGE_3(...)

#define CPS1_DIFFICULTY_1(...)
#define CPS1_DIFFICULTY_2(...)

#define PORT_START(a) 
#define PORT_BIT(...)
#define PORT_CODE(...)
#define PORT_NAME(...)
#define PORT_PLAYER(...)
#define PORT_MODIFY(...)
#define PORT_DIPNAME(...)
#define PORT_DIPSETTING(...)
#define PORT_DIPLOCATION(...)
#define PORT_DIPUNUSED_DIPLOC(...)
#define PORT_DIPUNKNOWN_DIPLOC(...)
#define PORT_DIPUNUSED(...)
#define PORT_SERVICE_DIPLOC(...)
#define PORT_SERVICE_NO_TOGGLE(...)
#define PORT_CONDITION(...)
#define PORT_READ_LINE_DEVICE_MEMBER(...)
#define PORT_WRITE_LINE_DEVICE_MEMBER(...)

#define DEF_STR(a) 0

#define PORT_8WAY

#define IPT_COIN1 0
#define IPT_COIN2 0
#define IPT_BUTTON1 0
#define IPT_BUTTON2 0
#define IPT_BUTTON3 0
#define IPT_BUTTON4 0
#define IPT_BUTTON5 0
#define IPT_BUTTON6 0
#define IPT_START1 0
#define IPT_START2 0
#define IPT_SERVICE1 0
#define IPT_UNKNOWN 0
#define IPT_CUSTOM 0
#define IP_ACTIVE_LOW 0
#define IPT_JOYSTICK_RIGHT 0
#define IPT_JOYSTICK_LEFT 0
#define IPT_JOYSTICK_UP 0
#define IPT_JOYSTICK_DOWN 0

#define Coin_A 0
#define Coinage 0
#define Difficulty 0


#endif