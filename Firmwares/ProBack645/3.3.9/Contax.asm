https://www.fidessamilestones.com/

60F 2.8 M S140/2.8

mask    3FFFFFC
bl mask 48000001
b mask  48000000
bc mask FFFC

beq   41820000
bne   40820000
blt   41800000
bgt   41810000

_code:000124E4  48 09 6E 38    b         contaxFL(000A931C)
_code:000124E8                 stw       r12, cameraFocalLength

_code:000124E4                 li        r12, 0
_code:000124E8                 stw       r12, cameraFocalLength


_code:000A9318                 .globl mallinfo
_code:000A9318  4E 80 00 20    blr

_code:000A931C                 .globl contaxFL

_code:000A931C                38 7F 00 03     addi      r3, r31, 3
_code:000A9320                48 00 23 21     bl        strlen (000AB640)
_code:000A9324                39 83 00 00     addi      r12, r3, 0
_code:000A9328                38 7F 00 03     addi      r3, r31, 3
_code:000A932C loc_start:     2C 0C 00 00     cmpwi     r12, 0
_code:000A9330                41 82 00 88     beq       loc_end (000A93B8)
_code:000A9334                7C 83 62 14     add       r4, r3, r12
_code:000A9338                88 E4 00 00     lbz       r7, 0(r4)
_code:000A933C                2C 07 00 2F     cmpwi     r7, 0x2F   # '/'
_code:000A9340                41 82 00 0C     beq       loc_endFl (000A934C)
_code:000A9344                39 8C FF FF     addi      r12, r12, -1
_code:000A9348                4B FF FF E4     b         loc_start
_code:000A934C loc_endFl:     39 6C 00 00     addi      r11, r12, 0
_code:000A9350                39 8C FF FF     addi      r12, r12, -1
_code:000A9354 loc_start2:    7C 83 62 14     add       r4, r3, r12
_code:000A9358                88 E4 00 00     lbz       r7, 0(r4)
_code:000A935C                2C 07 00 30     cmpwi     r7, 0x30   # '0'
_code:000A9360                41 80 00 18     blt       loc_calc (000A9378)
_code:000A9364                2C 07 00 39     cmpwi     r7, 0x39   # '9'
_code:000A9368                41 81 00 10     bgt       loc_calc (000A9378)
_code:000A936C                35 8C FF FF     addic.    r12, r12, -1
_code:000A9370                40 82 FF E4     bne       loc_start2 (000A9354)
_code:000A9374                39 8C FF FF     addi      r12, r12, -1
_code:000A9378 loc_calc:      39 8C 00 01     addi      r12, r12, 1
_code:000A937C                7C AC 58 50     subf      r5, r12, r11
_code:000A9380                2C 05 00 00     cmpwi     r5, 0
_code:000A9384                41 82 00 34     beq       loc_end (000A93B8)
_code:000A9388                2C 05 00 05     cmpwi     r5, 5
_code:000A938C                41 81 00 2C     bgt       loc_end (000A93B8)
_code:000A9390                7C 83 62 14     add       r4, r3, r12
_code:000A9394                38 61 00 08     addi      r3, r1, 8
_code:000A9398                7C C3 2A 14     add       r6, r3, r5 
_code:000A939C                38 E0 00 00     li        r7, 0
_code:000A93A0                98 E6 00 00     stb       r7, 0(r6)
_code:000A93A4                4B FE D9 4D     bl        memmove (00096CF0)
_code:000A93A8                38 61 00 08     addi      r3, r1, 8
_code:000A93AC                48 00 0B 99     bl        atoi (000A9F44)
_code:000A93B0                39 83 00 00     addi      r12, r3, 0
_code:000A93B4                4B F6 91 34     b         _code:000124E8 
_code:000A93B8 loc_end:       39 80 00 00     li        r12, 0
_code:000A93BC                4B F6 91 2C     b         _code:000124E8


offset 566C

000124E4-566C:
CE78:
48 09 6E 38

000A9318-566C:
A3CAC:
4E 80 00 20 38 7F 00 03 48 00 23 21 39 83 00 00 
38 7F 00 03 2C 0C 00 00 41 82 00 88 7C 83 62 14 
88 E4 00 00 2C 07 00 2F 41 82 00 0C 39 8C FF FF 
4B FF FF E4 39 6C 00 00 39 8C FF FF 7C 83 62 14 
88 E4 00 00 2C 07 00 30 41 80 00 18 2C 07 00 39 
41 81 00 10 35 8C FF FF 40 82 FF E4 39 8C FF FF 
39 8C 00 01 7C AC 58 50 2C 05 00 00 41 82 00 34 
2C 05 00 05 41 81 00 2C 7C 83 62 14 38 61 00 08 
7C C3 2A 14 38 E0 00 00 98 E6 00 00 4B FE D9 4D 
38 61 00 08 48 00 0B 99 39 83 00 00 4B F6 91 34 
39 80 00 00 4B F6 91 2C 