Offset:566C

_code:0007C918 power_Start:
_code:0007C918 
_code:0007C918 .set var_4, -4
_code:0007C918 .set arg_4,  4
_code:0007C918  
_code:0007C918   94 21 FF F0   stwu      r1, -0x10(r1)
_code:0007C91C   7C 08 02 A6   mflr      r0
_code:0007C920   93 E1 00 0C   stw       r31, 0x10+var_4(r1)
_code:0007C924   90 01 00 14   stw       r0, 0x10+arg_4(r1)
_code:0007C928   3B E3 00 00   addi      r31, r3, 0
_code:0007C92C   93 E0 3C A0   stw       r31, powerId
_code:0007C930   39 80 00 01   li        r12, 1
_code:0007C934   99 80 3C AD   stb       r12, powerSwitchOn

_code:0007C938
// subtract 60 / 3C hex
_code:0007C974   39 80 00 00   li        r12, 0
_code:0007C978   91 80 3C DC   stw       r12, dspClock
_code:0007C97C   3C 60 00 01   lis       r3, ((powerProperty+0x10000)@h)
_code:0007C980   38 63 A5 80   addi      r3, r3, powerProperty@l
_code:0007C984   38 80 00 06   li        r4, 6
_code:0007C988   48 00 06 05   bl        propertyRegister


_code:0007C938   89 60 3C D9   lbz       r11, highTemperature   
_code:0007C93C   2C 0B 00 00   cmpwi     r11, 0
_code:0007C940   41 82 00 10   beq       loc_7C950
_code:0007C944   39 80 00 C8   li        r12, 200
_code:0007C948   91 80 3C C8   stw       r12, maxTemperature
_code:0007C94C   48 00 00 28   b         loc_7C974
_code:0007C950 # ---------------------------------------------------------------------------

_code:0007C938   81 60 3C C8   lwz       r11, maxTemperature
_code:0007C93C   2C 0B 00 28   cmpwi     r11, 0x28
_code:0007C940   40 82 00 34   bne       loc_7C950
                 41 81 00 34
_code:0007C944   60 00 00 00   nop
_code:0007C948   60 00 00 00   nop
_code:0007C94C   60 00 00 00   nop

_code:0007C950
_code:0007C950 loc_7C950:                              # CODE XREF: power_Start+28
_code:0007C950   3C 60 00 40   lis       r3, 0x40 # '@' # 64
_code:0007C954   48 01 E7 B5   bl        unitModelFeatures
_code:0007C958   2C 03 00 00   cmpwi     r3, 0
_code:0007C95C   41 82 00 10   beq       loc_7C96C
_code:0007C960   39 80 00 41   li        r12, 0x41     # 65
_code:0007C964   91 80 3C C8   stw       r12, maxTemperature
 _code:0007C968  48 00 00 0C   b         loc_7C974
_code:0007C96C # ---------------------------------------------------------------------------
_code:0007C96C
_code:0007C96C loc_7C96C:                              # CODE XREF: power_Start+44
_code:0007C96C   39 80 00 32   li        r12, 0x32     # 50
_code:0007C970   91 80 3C C8   stw       r12, maxTemperature
_code:0007C974
_code:0007C974 loc_7C974:                              # CODE XREF: power_Start+34
_code:0007C974                                         # power_Start+50

_code:0007C974   39 80 00 00   li        r12, 0
_code:0007C978   91 80 3C DC   stw       r12, dspClock
_code:0007C97C   3C 60 00 01   lis       r3, ((powerProperty+0x10000)@h)
_code:0007C980   38 63 A5 80   addi      r3, r3, powerProperty@l
_code:0007C984   38 80 00 06   li        r4, 6
_code:0007C988   48 00 05 C9   bl        propertyRegister

_code:0007C98C   3F E0 00 08   lis       r31, ((powerEventHandler+0x10000)@h)


   772CC (file)
0007C938: 39 80 00 00 91 80 3C DC 3C 60 00 01 38 63 A5 80
0007C948  38 80 00 06 48 00 06 05 81 60 3C C8 2C 0B 00 28
0007C958  41 81 00 34 60 00 00 00 60 00 00 00 60 00 00 00
0007C968  3C 60 00 40 48 01 E7 B5 2C 03 00 00 41 82 00 10
0007C978  39 80 00 41 91 80 3C C8 48 00 00 0C 39 80 00 32
0007C988  91 80 3C C8






Was:
0007C918  94 21 FF F0 7C 08 02 A6  93 E1 00 0C 90 01 00 14
0007C928  3B E3 00 00 93 E0 3C A0  39 80 00 01 99 80 3C AD
0007C938  89 60 3C D9 2C 0B 00 00  41 82 00 10 39 80 00 C8
0007C948  91 80 3C C8 48 00 00 28  3C 60 00 40 48 01 E7 CD
0007C958  2C 03 00 00 41 82 00 10  39 80 00 41 91 80 3C C8
0007C968  48 00 00 0C 39 80 00 32  91 80 3C C8 39 80 00 00
0007C978  91 80 3C DC 3C 60 00 01  38 63 A5 80 38 80 00 06
0007C988  48 00 05 C9 3F E0 00 08

------------------------------------------------------------------------------

 mallinfo (file offset A3CAC):
_code:000A9318  81 80 53 04    lwz       r12, dword_5304
_code:000A931C
...
_code:000A94D4  4E 80 00 20    blr

b mask (3FFFFFC)
b rev mask (48000001)
New:
imagerMenu (file offset 607DC):
_code:00065E48  48 04 34 D4    b         loc_000A931C
_code:00065E4C  3F E0 00 06 

mallinfo (file offset A3CAC):
_code:000A9318  4E 80 00 20    blr

_code:000A931C loc_9B460:                              # CODE XREF: imagerMenu+1Cp
_code:000A931C  4B FC 66 15    bl        menuTitle ; 0006F930
_code:000A9320  3F E0 00 06    lis       r31, imagerFileSave@h
_code:000A9324  3B FF 56 9C    addi      r31, r31, imagerFileSave@l
_code:000A9328  3C A0 00 0B    lis       r5, aSaveIfFile@ha # "Save IF File\a\a"
_code:000A932C  38 A5 93 4C    addi      r5, r5, aSaveIfFile@l # "Save IF File\a\a"
_code:000A9330  38 60 00 00    li        r3, 0
_code:000A9334  38 80 00 00    li        r4, 0
_code:000A9338  38 C0 00 01    li        r6, 1
_code:000A933C  38 FF 00 00    addi      r7, r31, 0
_code:000A9340  39 00 00 00    li        r8, 0
_code:000A9344  4B FC 68 D1    bl        menuItem   ; 0006FC14
_code:000A9348  4B FB CB 04    b         loc_65E4C
 # ---------------------------------------------------------------------------
_code:000A934C  53 61 76 65 
_code:000A9350  20 49 46 20  
_code:000A9354  46 69 6C 65 
_code:000A9358  07 07 00 00
_code:000A935C

_code:000A934C aSaveIfFile:    .string "Save IF File\a\a\0\0" 

607DC(file):
48 04 34 D4 3F E0 00 06 

A3CAC(file): 
4E 80 00 20 4B FC 66 15 3F E0 00 06 3B FF 56 9C
3C A0 00 0B 38 A5 93 4C 38 60 00 00 38 80 00 00
38 C0 00 01 38 FF 00 00 39 00 00 00 4B FC 68 D1
4B FB CB 04 53 61 76 65 20 49 46 20 46 69 6C 65
07 07 00 00


------------------------------------------------------------------------------
b mask (3FFFFFC)
b rev mask (48000001)

firmwareMenu:

_code:0004E4CC  48 05 AE A8    b         000A9374
_code:0004E4D0  3C A0 00 05

patch for test mode menu:
_code:000A935C  38 60 00 00    li        r3, 0
_code:000A9360  4B FF 2D E4    b         unitTestSet ; 0009C144
_code:000A9364  00 00 00 00
_code:000A9368  38 60 00 01    li        r3, 1 
_code:000A936C  4B FF 2D D8    b         unitTestSet ; 0009C144
_code:000A9370  00 00 00 00
_code:000A9374  4B FC 65 BD    bl        menuTitle   ; 0006F930
_code:000A9378  4B FF 20 D1    bl        unitTest    ; 0009B448
_code:000A937C  2C 03 00 00    cmpwi     r3, 0
_code:000A9380  41 82 00 18    beq       000A9390
_code:000A9384  3F E0 00 0B    lis       r31, 000A935C
_code:000A9388  3B FF 93 5C    addi      r31, r31, 000A935C
_code:000A938C  3C A0 00 0B    lis       r5, 000A93C4 # "Disable Service Mode\a\a"
_code:000A9390  38 A5 93 C4    addi      r5, r5, 000A93C4 # "Disable Service Mode\a\a"
_code:000A9394  48 00 00 14    b         000A93A0
_code:000A9398  3F E0 00 0B    lis       r31, 000A9368
_code:000A939C  3B FF 93 68    addi      r31, r31, 000A9368
_code:000A93A0  3C A0 00 0B    lis       r5, 000A93DC@ha # "Enable Service Mode\a\a"
_code:000A93A4  38 A5 93 DC    addi      r5, r5, 000A93DC@l # "Enable Service Mode\a\a"
_code:000A93A8  38 60 00 00    li        r3, 0
_code:000A93AC  38 80 00 00    li        r4, 0
_code:000A93B0  38 C0 00 01    li        r6, 1
_code:000A93B4  38 FF 00 00    addi      r7, r31, 0
_code:000A93B8  39 00 00 00    li        r8, 0
_code:000A93BC  4B FC 68 59    bl        menuItem   ; 0006FC14
_code:000A93C0  4B FA 51 10    b         0004E4D0
disable
_code:000A93C4  44 69 73 61 
_code:000A93C8  62 6C 65 20 
_code:000A93CC  53 65 72 76 
_code:000A93D0  69 63 65 20  
_code:000A93D4  4D 6F 64 65
_code:000A93D8  07 07 00 00
enable
_code:000A93DC  45 6E 61 62 
_code:000A93E0  6C 65 20 53  
_code:000A93E4  65 72 76 69
_code:000A93E8  63 65 20 4D 
_code:000A93EC  6F 64 65 07
_code:000A93F0  07 00 00 00

48E60(file):
48 05 AE A8 3C A0 00 05

A3CF0(file):
38 60 00 00 4B FF 2D E4 00 00 00 00 38 60 00 01
4B FF 2D D8 00 00 00 00 4B FC 65 BD 4B FF 20 D1
2C 03 00 00 41 82 00 18 3F E0 00 0B 3B FF 93 5C
3C A0 00 0B 38 A5 93 C4 48 00 00 14 3F E0 00 0B
3B FF 93 68 3C A0 00 0B 38 A5 93 DC 38 60 00 00
38 80 00 00 38 C0 00 01 38 FF 00 00 39 00 00 00
4B FC 68 59 4B FA 51 10 44 69 73 61 62 6C 65 20
53 65 72 76 69 63 65 20 4D 6F 64 65 07 07 00 00
45 6E 61 62 6C 65 20 53 65 72 76 69 63 65 20 4D
6F 64 65 07 07 00 00 00