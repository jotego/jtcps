# Memory Map

Device          |    CPS2          |   CPS 1.5        | Remarks
----------------|------------------|------------------|-----------
 ROM            | 0-3F'FFFF        |   0-1F'FFFF      |
 "output"       | 40'0000-40'000B  |                  |
 QSound RAM 1   | 61'8000-61'9FFF  | F1'8000-F1'9FFF  |
 RAM A          | 66'0000-66'3FFF  |                  |
 enable RAM A   | 66'4000-66'4001  |                  |
 OBJ RAM 1      | 70'0000-70'1FFF  |                  | unused ?
 OBJ RAM 2      | 70'8000-70'9FFF  |                  | Mirror 00'6000
 CPS-A          | 80'0100-80'013F  | idem             |
  (mirror)      | 80'4100-80'413F  |                  |
 CPS-B          | 80'0140-80'017F  | idem             |
  (mirror)      | 80'4140-80'417F  |                  |
 IN0            | 80'4000-80'4001  | 80'0000-80'0007  |
 IN1            | 80'4000-80'4001  | F1'C000-F1'C001  |
 IN2/EEPROM     | 80'4020-80'4021  | F1'C002-F1'C003  |
 QSnd Volume rd | 80'4030-80'4031  |                  |
 EEPROM write   | 80'4040-80'4041  |                  |
 ?              | 80'40a0-80'40a1  |                  |
 Kludge?        | 80'40b0-80'40b3  |                  |
 Obj bank       | 80'40e0-80'40e1  |                  |
 Video RAM      | 90'0000-92'FFFF  | idem             |
 Work RAM       | FF'0000-FF'FFFF  | idem             |