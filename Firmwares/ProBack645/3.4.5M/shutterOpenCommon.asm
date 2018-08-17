cameraMessageMamiya
00012FB4-566C=D948
00012FB4 48 00 47 CD                 bl        cameraShutterOpenCommon 

00013060-566C=D9F4
00013060 48 00 47 21                 bl        cameraShutterOpenCommon 

cameraMessageSetupMamiya
000133B0-566C=DD44
000133B0 48 00 43 D1                 bl        cameraShutterOpenCommon 

00015598-566C=FF2C
00015598 48 00 21 E9                 bl        cameraShutterOpenCommon 


cameraShutterOpenCommon 000177C0
00017780-566C=12114
00017780 94 21 FF F0                 stwu      r1, -0x10(r1)
00017784 7C 08 02 A6                 mflr      r0
00017788 90 01 00 14                 stw       r0, 0x10+arg_4(r1)
0001778C 39 80 00 01                 li        r12, 1
00017790 99 80 21 4A                 stb       r12, cameraShutterOpen
00017794 81 80 21 AC                 lwz       r12, shutterMode
00017798 2C 0C 00 00                 cmpwi     r12, 0
0001779C 40 82 00 0C                 bne       loc_177A8
000177A0 39 80 00 00                 li        r12, 0
000177A4 99 80 21 B2                 stb       r12, curCamSoftOnTime
000177A8 89 60 20 9B loc_177A8:      lbz       r11, cameraShutterPulseEnable
000177AC 2C 0B 00 00                 cmpwi     r11, 0
000177B0 41 82 00 88                 beq       loc_17838
000177B4 7C C0 00 A6                 mfmsr     r6
000177B8 7C 11 13 A6                 mtspr     eid, r0 # External interrupt disable
000177BC 4C 00 01 2C                 isync
000177C0 3C A0 00 01                 lis       r5, byte_8000@ha
000177C4 38 A5 80 00                 addi      r5, r5, byte_8000@l
000177C8 7C C6 28 38                 and       r6, r6, r5
000177CC 7C 70 42 A6                 mfsprg0   r3
000177D0 54 63 08 3E                 rotlwi    r3, r3, 1
000177D4 7C 63 28 78                 andc      r3, r3, r5
000177D8 7C 63 33 78                 or        r3, r3, r6
000177DC 7C 70 43 A6                 mtsprg0   r3
000177E0 38 60 FF BF                 li        r3, -0x41
000177E4 3C 80 20 00                 lis       r4, IMMR@h
000177E8 38 84 00 00                 addi      r4, r4, IMMR@l
000177EC 81 44 0A C4                 lwz       r10, (IMMR.PBDAT - IMMR)(r4)
000177F0 7D 4A 18 38                 and       r10, r10, r3
000177F4 91 44 0A C4                 stw       r10, (IMMR.PBDAT - IMMR)(r4)
000177F8 81 84 0A C0                 lwz       r12, (IMMR.PBODR - IMMR)(r4)
000177FC 7D 8C 18 38                 and       r12, r12, r3
00017800 91 84 0A C0                 stw       r12, (IMMR.PBODR - IMMR)(r4)
00017804 81 64 0A B8                 lwz       r11, (IMMR.PBDIR - IMMR)(r4)
00017808 61 6B 00 40                 ori       r11, r11, 0x40
0001780C 91 64 0A B8                 stw       r11, (IMMR.PBDIR - IMMR)(r4)
00017810 81 44 0A BC                 lwz       r10, (IMMR.PBPAR - IMMR)(r4)
00017814 55 4A 06 B0                 rlwinm    r10, r10, 0,26,24
00017818 91 44 0A BC                 stw       r10, (IMMR.PBPAR - IMMR)(r4)
0001781C 7C 90 42 A6                 mfsprg0   r4
00017820 54 83 F8 3E                 rotrwi    r3, r4, 1
00017824 7C 70 43 A6                 mtsprg0   r3
00017828 70 84 80 00                 andi.     r4, r4, 0x8000
0001782C 41 82 00 08                 beq       loc_17834
00017830 7C 10 13 A6                 mtspr     eie, r0 # External interrupt enable
00017834 4C 00 01 2C loc_17834:      isync
00017838 81 80 21 4C loc_17838:      lwz       r12, cameraActuations
0001783C 39 8C 00 01                 addi      r12, r12, 1
00017840 91 80 21 4C                 stw       r12, cameraActuations
00017844 38 60 21 4C                 li        r3, 0x214C
00017848 48 06 71 51                 bl        propertySave 
0001784C 80 01 00 14                 lwz       r0, 0x10+arg_4(r1)
00017850 7C 08 03 A6                 mtlr      r0
00017854 38 21 00 10                 addi      r1, r1, 0x10
00017858 4E 80 00 20                 blr
0001785C 00 00 00 00
00017860 00 00 00 00
00017864 00 00 00 00
00017868 00 00 00 00
0001786C 00 00 00 00
00017870 00 00 00 00
00017874 00 00 00 00
00017878 00 00 00 00
0001787C 00 00 00 00
00017880 00 00 00 00
00017884 00 00 00 00
00017888 00 00 00 00
0001788C 00 00 00 00
