cameraTask:
00016D8C-566C=11720
00016D8C 4B FF CA 2D                 bl        cameraTaskMamiya ; 000137B8-00016D8C

cameraTaskMamiya:

rTimeDelay = r23

000137B8 94 21 FF 40                 stwu      r1, -0xC0(r1)
000137BC 7C 08 02 A6                 mflr      r0
000137C0 BD C1 00 78                 stmw      r14, 0xC0+var_48(r1)
000137C4 90 01 00 C4                 stw       r0, 0xC0+arg_4(r1)
000137C8 4B FF D2 CD                 bl        cameraRegisterSettings ;00010A94-000137C8
000137CC 3C 60 00 01                 lis       r3, mamiyaProperties@h
000137D0 38 63 44 60                 addi      r3, r3, mamiyaProperties@l
000137D4 38 80 00 02                 li        r4, 2
000137D8 48 06 97 79                 bl        propertyRegister ;7CF50-000137D8
000137DC 4B FF DC 99                 bl        cameraPinSetup ;00011474-000137DC
000137E0 3A C0 00 00                 li        r22, 0
000137E4 3B 60 00 00                 li        r27, 0
000137E8 3A E0 7D 00 loc_137E8:      li        rTimeDelay, 0x7D00 # 32ms
000137EC 3F E0 20 00                 lis       r31, IMMR@h
000137F0 3B FF 00 00                 addi      r31, r31, IMMR@l
000137F4 7C C0 00 A6 loc_137F4:      mfmsr     r6
000137F8 7C 11 13 A6                 mtspr     eid, r0 # External interrupt disable
000137FC 4C 00 01 2C                 isync
00013800 3C A0 00 01                 lis       r5, ((byte_8000+0x10000)@h)
00013804 38 A5 80 00                 addi      r5, r5, byte_8000@l
00013808 7C C6 28 38                 and       r6, r6, r5
0001380C 7C 70 42 A6                 mfsprg0   r3
00013810 54 63 08 3E                 rotlwi    r3, r3, 1     # r3 = (r3 << 1) | (r3 >> 31)
00013814 7C 63 28 78                 andc      r3, r3, r5
00013818 7C 63 33 78                 or        r3, r3, r6
0001381C 7C 70 43 A6                 mtsprg0   r3
00013820 81 9F 0A C4                 lwz       r12, IMMR.PBDAT@l(r31)
00013824 61 8C 00 01                 ori       r12, r12, 1
00013828 91 9F 0A C4                 stw       r12, IMMR.PBDAT@l(r31)
0001382C 81 7F 0A C0                 lwz       r11, IMMR.PBODR@l(r31)
00013830 55 6B 00 3C                 clrrwi    r11, r11, 1   # r11 = r11 & 0xFFFFFFFE
00013834 91 7F 0A C0                 stw       r11, IMMR.PBODR@l(r31)
00013838 81 5F 0A B8                 lwz       r10, IMMR.PBDIR@l(r31)
0001383C 61 4A 00 01                 ori       r10, r10, 1
00013840 91 5F 0A B8                 stw       r10, IMMR.PBDIR@l(r31)
00013844 81 9F 0A BC                 lwz       r12, IMMR.PBPAR@l(r31)
00013848 55 8C 00 3C                 clrrwi    r12, r12, 1   # r12 = r12 & 0xFFFFFFFE
0001384C 91 9F 0A BC                 stw       r12, IMMR.PBPAR@l(r31)
00013850 7C 90 42 A6                 mfsprg0   r4
00013854 54 83 F8 3E                 rotrwi    r3, r4, 1     # r3 = (r4 << 31) | (r4 >> 1)
00013858 7C 70 43 A6                 mtsprg0   r3
0001385C 70 84 80 00                 andi.     r4, r4, 0x8000
00013860 41 82 00 08                 beq       loc_13868-13860
00013864 7C 10 13 A6                 mtspr     eie, r0 # External interrupt enable
00013868 4C 00 01 2C loc_13868:      isync
0001386C 7C C0 00 A6 loc_1386C:      mfmsr     r6
00013870 7C 11 13 A6                 mtspr     eid, r0 # External interrupt disable
00013874 4C 00 01 2C                 isync
00013878 3C A0 00 01                 lis       r5, ((byte_8000+0x10000)@h)
0001387C 38 A5 80 00                 addi      r5, r5, byte_8000@l
00013880 7C C6 28 38                 and       r6, r6, r5
00013884 7C 70 42 A6                 mfsprg0   r3
00013888 54 63 08 3E                 rotlwi    r3, r3, 1     # r3 = (r3 << 1) | (r3 >> 31)
0001388C 7C 63 28 78                 andc      r3, r3, r5
00013890 7C 63 33 78                 or        r3, r3, r6
00013894 7C 70 43 A6                 mtsprg0   r3
00013898 A1 9F 09 60                 lhz       r12, IMMR.PCDIR@l(r31)
0001389C 55 8C 06 2C                 rlwinm    r12, r12, 0,24,22 # r12 = r12 & 0xFFFFFEFF
000138A0 B1 9F 09 60                 sth       r12, IMMR.PCDIR@l(r31)
000138A4 A1 7F 09 64                 lhz       r11, IMMR.PCSO@l(r31)
000138A8 55 6B 06 2C                 rlwinm    r11, r11, 0,24,22 # r11 = r11 & 0xFFFFFEFF
000138AC B1 7F 09 64                 sth       r11, IMMR.PCSO@l(r31)
000138B0 A1 5F 09 66                 lhz       r10, IMMR.PCDAT@l(r31)
000138B4 55 4A 06 2C                 rlwinm    r10, r10, 0,24,22 # r10 = r10 & 0xFFFFFEFF
000138B8 B1 5F 09 66                 sth       r10, IMMR.PCDAT@l(r31)
000138BC A1 9F 09 62                 lhz       r12, IMMR.PCPAR@l(r31)
000138C0 55 8C 06 2C                 rlwinm    r12, r12, 0,24,22 # r12 = r12 & 0xFFFFFEFF
000138C4 B1 9F 09 62                 sth       r12, IMMR.PCPAR@l(r31)
000138C8 7C 90 42 A6                 mfsprg0   r4
000138CC 54 83 F8 3E                 rotrwi    r3, r4, 1     # r3 = (r4 << 31) | (r4 >> 1)
000138D0 7C 70 43 A6                 mtsprg0   r3
000138D4 70 84 80 00                 andi.     r4, r4, 0x8000
000138D8 41 82 00 08                 beq       loc_138E0-138D8
000138DC 7C 10 13 A6                 mtspr     eie, r0 # External interrupt enable
000138E0 4C 00 01 2C loc_138E0:      isync
000138E4 A1 7F 09 66                 lhz       r11, IMMR.PCDAT@l(r31)
000138E8 55 6B 05 EF                 rlwinm.   r11, r11, 0,23,23 # r11 = r11 & 0x100
000138EC 41 82 00 24                 beq       loc_13910-138EC
000138F0 38 60 FF FF loc_138F0:      li        r3, -1
000138F4 38 80 00 01                 li        r4, 1
000138F8 38 A0 03 E8                 li        r5, 1000
000138FC 38 C0 00 00                 li        r6, 0
00013900 48 06 58 19                 bl        osEvPend ;00079118-00013900
00013904 A1 9F 09 66                 lhz       r12, IMMR.PCDAT@l(r31)
00013908 55 8C 05 EF                 rlwinm.   r12, r12, 0,23,23 # r12 = r12 & 0x100
0001390C 40 82 FF E4                 bne       loc_138F0-1390C
00013910 A1 9F 09 66 loc_13910:      lhz       r12, IMMR.PCDAT@l(r31)
00013914 55 8C 05 EF                 rlwinm.   r12, r12, 0,23,23 # r12 = r12 & 0x100
00013918 40 82 02 28                 bne       loc_13B40-13918
0001391C 89 80 21 E9 loc_1391C:      lbz       r12, camAwake
00013920 2C 0C 00 00                 cmpwi     r12, 0
00013924 40 82 00 34                 bne       loc_13958-13924
00013928 89 80 21 E5                 lbz       r12, camSet
0001392C 2C 0C 00 00                 cmpwi     r12, 0
00013930 40 82 00 28                 bne       loc_13958-13930
00013934 89 80 21 E6                 lbz       r12, camGet
00013938 2C 0C 00 00                 cmpwi     r12, 0
0001393C 40 82 00 1C                 bne       loc_13958-1393C
00013940 89 80 21 48                 lbz       r12, takePicture
00013944 2C 0C 00 00                 cmpwi     r12, 0
00013948 40 82 00 10                 bne       loc_13958-13948
0001394C 89 80 22 28                 lbz       r12, cameraWake
00013950 2C 0C 00 00                 cmpwi     r12, 0
00013954 41 82 00 1C                 beq       loc_13970-13954
00013958 38 60 FF FF loc_13958:      li        r3, -1
0001395C 38 80 00 01                 li        r4, 1
00013960 38 A0 03 E8                 li        r5, 1000
00013964 38 C0 00 00                 li        r6, 0
00013968 48 06 57 B1                 bl        osEvPend ;00079118-00013968
0001396C 48 00 00 1C                 b         loc_13988-1396C
00013970 38 60 FF FF loc_13970:      li        r3, -1
00013974 38 80 00 01                 li        r4, 1
00013978 3C A0 00 4C                 lis       r5, 0x4C # 0x4C4B40 # 'L' # 5000000 = 5sec
0001397C 60 A5 4B 40                 ori       r5, r5, 0x4B40 # 0x4C4B40
00013980 38 C0 00 00                 li        r6, 0
00013984 48 06 57 95                 bl        osEvPend ;00079118-00013984
00013988 48 00 4A E5 loc_13988:      bl        cameraDialogCheck ; 0001846C-00013988
0001398C 38 7B 00 00                 addi      r3, r27, 0
00013990 4B FF F7 9D                 bl        cameraMessageSetupMamiya ;0001312C-00013990 
00013994 3B A3 00 00                 addi      r29, r3, 0
00013998 57 BD 06 3E                 clrlwi    r29, r29, 24  # r29 = r29 & 0xFF
0001399C 2C 1D 00 00                 cmpwi     r29, 0
000139A0 41 82 01 94 loc_139A0:      beq       loc_13B34-139A0
000139A4 89 80 21 E9                 lbz       r12, camAwake
000139A8 2C 0C 00 00                 cmpwi     r12, 0
000139AC 40 82 00 20                 bne       loc_139CC-139AC
000139B0 48 08 5D 6D                 bl        timeUsec ; 9971C-000139B0
000139B4 81 80 21 D0                 lwz       r12, bodySleepTime
000139B8 7C 6C 18 50                 subf      r3, r12, r3
000139BC 3D 60 00 0A                 lis       r11, loc_AAE60@h # 700000 = 0.7s
000139C0 61 6B AE 60                 ori       r11, r11, loc_AAE60@l
000139C4 7C 03 58 40                 cmplw     r3, r11
000139C8 41 81 00 10                 bgt       loc_139D8-139C8
000139CC 81 80 21 E0 loc_139CC:      lwz       r12, backMessageCount
000139D0 28 0C 00 02                 cmplwi    r12, 2
000139D4 41 80 01 60                 blt       loc_13B34-139D4
000139D8 48 08 5D 45 loc_139D8:      bl        timeUsec ; 9971C-000139D8 
000139DC 7C 76 18 50                 subf      r3, r22, r3
000139E0 7C 03 B8 40                 cmplw     r3, rTimeDelay
000139E4 40 81 01 50                 ble       loc_13B34-139E4
000139E8 89 80 21 EF                 lbz       r12, camReplyDelay
000139EC 2C 0C 00 00                 cmpwi     r12, 0
000139F0 41 82 00 20                 beq       loc_13A10-139F0
000139F4 48 08 5D 29                 bl        timeUsec ; 9971C-000139F4
000139F8 81 80 21 C4                 lwz       r12, lastMessageTime
000139FC 7C 6C 18 50                 subf      r3, r12, r3
00013A00 3D 40 00 03                 lis       r10, 3
00013A04 61 4A 0D 40                 ori       r10, r10, 0x0D40
00013A08 7C 03 50 40                 cmplw     r3, r10
00013A0C 40 81 01 28                 ble       loc_13B34-13A0C
00013A10 57 BD 06 3E loc_13A10:      clrlwi    r29, r29, 24  # r29 = r29 & 0xFF
00013A14 38 BD 00 00                 addi      r5, r29, 0
00013A18 38 60 00 C7                 li        r3, INFO_EVENT # event INFO_EVENT
00013A1C 38 80 00 00                 li        r4, 0
00013A20 48 02 9F 59                 bl        eventPost ; 3D978-00013A20 
00013A24 3A 40 00 01                 li        r18, 1
00013A28 7C C0 00 A6                 mfmsr     r6
00013A2C 7C 11 13 A6                 mtspr     eid, r0 # External interrupt disable
00013A30 4C 00 01 2C                 isync
00013A34 3C A0 00 01                 lis       r5, ((byte_8000+0x10000)@h)
00013A38 38 A5 80 00                 addi      r5, r5, byte_8000@l
00013A3C 7C C6 28 38                 and       r6, r6, r5
00013A40 7C 70 42 A6                 mfsprg0   r3
00013A44 54 63 08 3E                 rotlwi    r3, r3, 1     # r3 = (r3 << 1) | (r3 >> 31)
00013A48 7C 63 28 78                 andc      r3, r3, r5
00013A4C 7C 63 33 78                 or        r3, r3, r6
00013A50 7C 70 43 A6                 mtsprg0   r3
00013A54 A1 3F 09 66                 lhz       r9, IMMR.PCDAT@l(r31)
00013A58 61 29 01 00                 ori       r9, r9, 0x100
00013A5C B1 3F 09 66                 sth       r9, IMMR.PCDAT@l(r31)
00013A60 A1 9F 09 64                 lhz       r12, IMMR.PCSO@l(r31)
00013A64 55 8C 06 2C                 rlwinm    r12, r12, 0,24,22 # r12 = r12 & 0xFFFFFEFF
00013A68 B1 9F 09 64                 sth       r12, IMMR.PCSO@l(r31)
00013A6C A1 7F 09 60                 lhz       r11, IMMR.PCDIR@l(r31)
00013A70 61 6B 01 00                 ori       r11, r11, 0x100
00013A74 B1 7F 09 60                 sth       r11, IMMR.PCDIR@l(r31)
00013A78 A1 5F 09 62                 lhz       r10, immr.PCPAR(r31)
00013A7C 55 4A 06 2C                 rlwinm    r10, r10, 0,24,22 # r10 = r10 & 0xFFFFFEFF
00013A80 B1 5F 09 62                 sth       r10, immr.PCPAR(r31)
00013A84 7C 90 42 A6                 mfsprg0   r4
00013A88 54 83 F8 3E                 rotrwi    r3, r4, 1     # r3 = (r4 << 31) | (r4 >> 1)
00013A8C 7C 70 43 A6                 mtsprg0   r3
00013A90 70 84 80 00                 andi.     r4, r4, 0x8000
00013A94 41 82 00 08                 beq       loc_13A9C-13A94
00013A98 7C 10 13 A6                 mtspr     eie, r0 # External interrupt enable
00013A9C 4C 00 01 2C loc_13A9C:      isync
00013AA0 38 60 0B B8                 li        r3, 3000
00013AA4 48 08 5E 15                 bl        waitUsec ;998B8-00013AA4 
00013AA8 7C C0 00 A6                 mfmsr     r6
00013AAC 7C 11 13 A6                 mtspr     eid, r0 # External interrupt disable
00013AB0 4C 00 01 2C                 isync
00013AB4 3C A0 00 01                 lis       r5, ((byte_8000+0x10000)@h)
00013AB8 38 A5 80 00                 addi      r5, r5, byte_8000@l
00013ABC 7C C6 28 38                 and       r6, r6, r5
00013AC0 7C 70 42 A6                 mfsprg0   r3
00013AC4 54 63 08 3E                 rotlwi    r3, r3, 1     # r3 = (r3 << 1) | (r3 >> 31)
00013AC8 7C 63 28 78                 andc      r3, r3, r5
00013ACC 7C 63 33 78                 or        r3, r3, r6
00013AD0 7C 70 43 A6                 mtsprg0   r3
00013AD4 A1 7F 09 60                 lhz       r11, immr.PCDIR(r31)
00013AD8 55 6B 06 2C                 rlwinm    r11, r11, 0,24,22 # r11 = r11 & 0xFFFFFEFF
00013ADC B1 7F 09 60                 sth       r11, immr.PCDIR(r31)
00013AE0 A1 5F 09 64                 lhz       r10, immr.PCSO(r31)
00013AE4 55 4A 06 2C                 rlwinm    r10, r10, 0,24,22 # r10 = r10 & 0xFFFFFEFF
00013AE8 B1 5F 09 64                 sth       r10, immr.PCSO(r31)
00013AEC A1 9F 09 66                 lhz       r12, immr.PCDAT(r31)
00013AF0 55 8C 06 2C                 rlwinm    r12, r12, 0,24,22 # r12 = r12 & 0xFFFFFEFF
00013AF4 B1 9F 09 66                 sth       r12, immr.PCDAT(r31)
00013AF8 A1 7F 09 62                 lhz       r11, immr.PCPAR(r31)
00013AFC 55 6B 06 2C                 rlwinm    r11, r11, 0,24,22 # r11 = r11 & 0xFFFFFEFF
00013B00 B1 7F 09 62                 sth       r11, immr.PCPAR(r31)
00013B04 7C 90 42 A6                 mfsprg0   r4
00013B08 54 83 F8 3E                 rotrwi    r3, r4, 1     # r3 = (r4 << 31) | (r4 >> 1)
00013B0C 7C 70 43 A6                 mtsprg0   r3
00013B10 70 84 80 00                 andi.     r4, r4, 0x8000
00013B14 41 82 00 08                 beq       loc_13B1C-13B14
00013B18 7C 10 13 A6                 mtspr     eie, r0 # External interrupt enable
00013B1C 4C 00 01 2C loc_13B1C:      isync
00013B20 38 60 03 E8                 li        r3, 1000
00013B24 48 08 5D 95                 bl        waitUsec ;998B8-00013B24 
00013B28 48 08 5B F5                 bl        timeUsec ; 9971C-00013B28
00013B2C 3A C3 00 00                 addi      r22, r3, 0
00013B30 3B 7B 00 01                 addi      r27, r27, 1
00013B34 A1 9F 09 66 loc_13B34:      lhz       r12, immr.PCDAT(r31)
00013B38 55 8C 05 EF                 rlwinm.   r12, r12, 0,23,23 # r12 = r12 & 0x100
00013B3C 41 82 FD E0                 beq       loc_1391C-13B3C
00013B40 81 9F 0A C4 loc_13B40:      lwz       r12, immr.PBDAT(r31)
00013B44 55 8C 07 7B                 rlwinm.   r12, r12, 0,29,29 # r12 = r12 & 4
00013B48 41 82 FD 24                 beq       loc_1386C-13B48
00013B4C 48 08 5B D1                 bl        timeUsec ; 9971C-00013B4C
00013B50 3A C3 00 00                 addi      r22, r3, 0
00013B54 3B 60 00 00                 li        r27, 0
00013B58 38 61 00 08                 addi      r3, r1, 0xC0+var_B8
00013B5C 38 80 00 00                 li        r4, 0
00013B60 38 A0 00 2C                 li        r5, 0x2C # ','
00013B64 48 09 77 91                 bl        memset   ; AB2F4-00013B64
00013B68 38 61 00 34                 addi      r3, r1, 0xC0+var_8C
00013B6C 38 80 00 00                 li        r4, 0
00013B70 38 A0 00 2C                 li        r5, 0x2C # ','
00013B74 48 09 77 81                 bl        memset   ; AB2F4-00013B74
00013B78 39 20 00 AA                 li        r9, 0xAA # '¬'
00013B7C 99 21 00 33                 stb       r9, 0xC0+var_8D(r1)
00013B80 3B 80 00 00                 li        r28, 0
00013B84 3B 40 00 00                 li        r26, 0
00013B88 88 61 00 34                 lbz       r3, 0xC0+var_8C(r1)
00013B8C 38 97 00 00                 addi      r4, rTimeDelay, 0
00013B90 4B FF D0 D1                 bl        cameraSpiGetPut  ;10C60-00013B90
00013B94 3B 23 00 00                 addi      r25, r3, 0
00013B98 9B 21 00 08                 stb       r25, 0xC0+var_B8(r1)
00013B9C 57 39 06 3E                 clrlwi    r25, r25, 24  # r25 = r25 & 0xFF
00013BA0 2C 19 00 7E                 cmpwi     r25, 0x7E
00013BA4 40 82 00 B8                 bne       loc_13C5C-13BA4
00013BA8 3B 40 00 02                 li        r26, 2
00013BAC 2C 12 00 00                 cmpwi     r18, 0
00013BB0 41 82 00 7C                 beq       loc_13C2C-13BB0
00013BB4 7C C0 00 A6                 mfmsr     r6
00013BB8 7C 11 13 A6                 mtspr     eid, r0 # External interrupt disable
00013BBC 4C 00 01 2C                 isync
00013BC0 3C A0 00 01                 lis       r5, ((byte_8000+0x10000)@h)
00013BC4 38 A5 80 00                 addi      r5, r5, byte_8000@l
00013BC8 7C C6 28 38                 and       r6, r6, r5
00013BCC 7C 70 42 A6                 mfsprg0   r3
00013BD0 54 63 08 3E                 rotlwi    r3, r3, 1     # r3 = (r3 << 1) | (r3 >> 31)
00013BD4 7C 63 28 78                 andc      r3, r3, r5
00013BD8 7C 63 33 78                 or        r3, r3, r6
00013BDC 7C 70 43 A6                 mtsprg0   r3
00013BE0 81 7F 0A C4                 lwz       r11, immr.PBDAT(r31)
00013BE4 55 6B 07 76                 rlwinm    r11, r11, 0,29,27 # r11 = r11 & 0xFFFFFFF7
00013BE8 91 7F 0A C4                 stw       r11, immr.PBDAT(r31)
00013BEC 81 5F 0A C0                 lwz       r10, immr.PBODR(r31)
00013BF0 55 4A 07 76                 rlwinm    r10, r10, 0,29,27 # r10 = r10 & 0xFFFFFFF7
00013BF4 91 5F 0A C0                 stw       r10, immr.PBODR(r31)
00013BF8 81 9F 0A B8                 lwz       r12, immr.PBDIR(r31)
00013BFC 61 8C 00 08                 ori       r12, r12, 8
00013C00 91 9F 0A B8                 stw       r12, immr.PBDIR(r31)
00013C04 81 7F 0A BC                 lwz       r11, immr.PBPAR(r31)
00013C08 61 6B 00 08                 ori       r11, r11, 8
00013C0C 91 7F 0A BC                 stw       r11, immr.PBPAR(r31)
00013C10 7C 90 42 A6                 mfsprg0   r4
00013C14 54 83 F8 3E                 rotrwi    r3, r4, 1     # r3 = (r4 << 31) | (r4 >> 1)
00013C18 7C 70 43 A6                 mtsprg0   r3
00013C1C 70 84 80 00                 andi.     r4, r4, 0x8000
00013C20 41 82 00 08                 beq       loc_13C28-13C20
00013C24 7C 10 13 A6                 mtspr     eie, r0 # External interrupt enable
00013C28 4C 00 01 2C loc_13C28:      isync
00013C2C 39 80 00 01 loc_13C2C:      li        r12, 1
00013C30 99 81 00 35                 stb       r12, 0xC0+var_8C+1(r1)
00013C34 39 60 00 00                 li        r11, 0
00013C38 99 61 00 36                 stb       r11, 0xC0+var_8A(r1)
00013C3C 38 60 00 01                 li        r3, 1
00013C40 38 97 00 00                 addi      r4, rTimeDelay, 0
00013C44 4B FF D0 1D                 bl        cameraSpiGetPut  ;10C60-00013C44
00013C48 98 61 00 09                 stb       r3, 0xC0+var_B8+1(r1)
00013C4C 88 61 00 36                 lbz       r3, 0xC0+var_8A(r1)
00013C50 38 97 00 00                 addi      r4, rTimeDelay, 0
00013C54 4B FF D0 0D                 bl        cameraSpiGetPut  ;10C60-00013C54
00013C58 98 61 00 0A                 stb       r3, 0xC0+var_B6(r1)
00013C5C 3A 40 00 00 loc_13C5C:      li        r18, 0
00013C60 7D 61 D2 14                 add       r11, r1, r26
00013C64 3A 2B 00 08                 addi      r17, r11, 8
00013C68 7D 81 D2 14                 add       r12, r1, r26
00013C6C 3A 6C 00 34                 addi      r19, r12, 0x34
00013C70 3A B1 FF FF                 addi      r21, r17, -1
00013C74 89 51 00 00                 lbz       r10, 0(r17)
00013C78 2C 0A 00 01                 cmpwi     r10, 1
00013C7C 40 82 00 80                 bne       loc_13CFC-13C7C
00013C80 3B 80 00 01                 li        r28, 1
00013C84 7C C0 00 A6                 mfmsr     r6
00013C88 7C 11 13 A6                 mtspr     eid, r0 # External interrupt disable
00013C8C 4C 00 01 2C                 isync
00013C90 3C A0 00 01                 lis       r5, ((byte_8000+0x10000)@h)
00013C94 38 A5 80 00                 addi      r5, r5, byte_8000@l
00013C98 7C C6 28 38                 and       r6, r6, r5
00013C9C 7C 70 42 A6                 mfsprg0   r3
00013CA0 54 63 08 3E                 rotlwi    r3, r3, 1     # r3 = (r3 << 1) | (r3 >> 31)
00013CA4 7C 63 28 78                 andc      r3, r3, r5
00013CA8 7C 63 33 78                 or        r3, r3, r6
00013CAC 7C 70 43 A6                 mtsprg0   r3
00013CB0 81 5F 0A C4                 lwz       r10, immr.PBDAT(r31)
00013CB4 55 4A 07 76                 rlwinm    r10, r10, 0,29,27 # r10 = r10 & 0xFFFFFFF7
00013CB8 91 5F 0A C4                 stw       r10, immr.PBDAT(r31)
00013CBC 81 9F 0A C0                 lwz       r12, immr.PBODR(r31)
00013CC0 55 8C 07 76                 rlwinm    r12, r12, 0,29,27 # r12 = r12 & 0xFFFFFFF7
00013CC4 91 9F 0A C0                 stw       r12, immr.PBODR(r31)
00013CC8 81 7F 0A B8                 lwz       r11, immr.PBDIR(r31)
00013CCC 61 6B 00 08                 ori       r11, r11, 8
00013CD0 91 7F 0A B8                 stw       r11, immr.PBDIR(r31)
00013CD4 81 5F 0A BC                 lwz       r10, immr.PBPAR(r31)
00013CD8 61 4A 00 08                 ori       r10, r10, 8
00013CDC 91 5F 0A BC                 stw       r10, immr.PBPAR(r31)
00013CE0 7C 90 42 A6                 mfsprg0   r4
00013CE4 54 83 F8 3E                 rotrwi    r3, r4, 1     # r3 = (r4 << 31) | (r4 >> 1)
00013CE8 7C 70 43 A6                 mtsprg0   r3
00013CEC 70 84 80 00                 andi.     r4, r4, 0x8000
00013CF0 41 82 00 08                 beq       loc_13CF8-13CF0
00013CF4 7C 10 13 A6                 mtspr     eie, r0 # External interrupt enable
00013CF8 4C 00 01 2C loc_13CF8:      isync
00013CFC 3B 00 00 08 loc_13CFC:      li        r24, 8
00013D00 89 91 00 00                 lbz       r12, 0(r17)
00013D04 2C 0C 00 7D                 cmpwi     r12, 0x7D
00013D08 40 82 00 08                 bne       loc_13D10-13D08
00013D0C 3B 00 00 02                 li        r24, 2
00013D10 3A 00 00 00 loc_13D10:      li        r16, 0
00013D14 3B 20 00 01                 li        r25, 1
00013D18 39 F1 00 00                 addi      r15, r17, 0
00013D1C 39 D7 00 00                 addi      r14, rTimeDelay, 0
00013D20 89 91 00 00 loc_13D20:      lbz       r12, 0(r17)
00013D24 2C 0C 00 01                 cmpwi     r12, 1
00013D28 41 82 00 10                 beq       loc_13D38-13D28
00013D2C 39 80 00 00                 li        r12, 0
00013D30 7D 93 C9 AE                 stbx      r12, r19, r25
00013D34 48 00 01 FC                 b         loc_13F30-13D34
00013D38 7D 95 C8 AE loc_13D38:      lbzx      r12, r21, r25
00013D3C 7D 93 C9 AE                 stbx      r12, r19, r25
00013D40 2C 19 00 02                 cmpwi     r25, 2
00013D44 40 82 00 40                 bne       loc_13D84-13D44
00013D48 81 80 21 E0                 lwz       r12, backMessageCount
00013D4C 28 0C 00 02                 cmplwi    r12, 2
00013D50 41 80 00 10                 blt       loc_13D60-13D50
00013D54 89 80 21 DD                 lbz       r12, digitalBody
00013D58 2C 0C 00 00                 cmpwi     r12, 0
00013D5C 41 82 00 10                 beq       loc_13D6C-13D5C
00013D60 89 80 22 29 loc_13D60:      lbz       r12, noDigitalBody
00013D64 2C 0C 00 00                 cmpwi     r12, 0
00013D68 41 82 00 10                 beq       loc_13D78-13D68
00013D6C 39 80 00 11 loc_13D6C:      li        r12, 0x11
00013D70 7D 93 C9 AE                 stbx      r12, r19, r25
00013D74 48 00 01 AC                 b         loc_13F20-13D74
00013D78 39 80 00 81 loc_13D78:      li        r12, 0x81 # 'ü'
00013D7C 7D 93 C9 AE                 stbx      r12, r19, r25
00013D80 48 00 01 A0                 b         loc_13F20-13D80
00013D84 2C 19 00 04 loc_13D84:      cmpwi     r25, 4
00013D88 40 82 01 70                 bne       loc_13EF8-13D88
00013D8C 89 91 00 03                 lbz       r12, 3(r17)
00013D90 3B 0C 00 08                 addi      r24, r12, 8
00013D94 88 B1 00 02                 lbz       r5, 2(r17)
00013D98 2C 05 00 03                 cmpwi     r5, 3
00013D9C 40 82 01 04                 bne       loc_13EA0-13D9C
00013DA0 39 80 00 00                 li        r12, 0
00013DA4 99 80 21 EF                 stb       r12, camReplyDelay
00013DA8 89 60 21 DD                 lbz       r11, digitalBody
00013DAC 2C 0B 00 00                 cmpwi     r11, 0
00013DB0 40 82 00 14                 bne       loc_13DC4-13DB0
00013DB4 3A A0 58 14                 li        r21, 0x5814
00013DB8 89 60 58 19                 lbz       r11, byte_5819
00013DBC 3B 0B 00 08                 addi      r24, r11, 8
00013DC0 48 00 00 D8                 b         loc_13E98-13DC0
00013DC4 57 AC 06 F6 loc_13DC4:      rlwinm    r12, r29, 0,27,27 # r12 = r29 & 0x10
00013DC8 2C 0C 00 00                 cmpwi     r12, 0
00013DCC 41 82 00 40                 beq       loc_13E0C-13DCC
00013DD0 57 BD 07 34                 rlwinm    r29, r29, 0,28,26 # r29 = r29 & 0xFFFFFFEF
00013DD4 38 C0 58 1B                 li        r6, msg03d
00013DD8 39 40 00 82                 li        r10, 0x82 # 'é'
00013DDC 99 46 00 03                 stb       r10, 3(r6)
00013DE0 3D 20 00 00                 lis       r9, command@h
00013DE4 39 29 73 D8                 addi      r9, r9, command@l
00013DE8 57 BD 06 3E                 clrlwi    r29, r29, 24  # r29 = r29 & 0xFF
00013DEC 1D 9D 00 34                 mulli     r12, r29, 0x34
00013DF0 7D 29 60 AE                 lbzx      r9, r9, r12
00013DF4 55 29 06 36                 rlwinm    r9, r9, 0,24, 27 # r9 = r9 & 0xF0
00013DF8 99 26 00 04                 stb       r9, 4(r6)
00013DFC 3A A0 58 17                 li        r21, 0x5817
00013E00 89 46 00 01                 lbz       r10, 1(r6)
00013E04 3B 0A 00 08                 addi      r24, r10, 8
00013E08 48 00 00 90                 b         loc_13E98-13E08
00013E0C 57 BD 06 3E loc_13E0C:      clrlwi    r29, r29, 24  # r29 = r29 & 0xFF
00013E10 2C 1D 00 00                 cmpwi     r29, 0
00013E14 40 82 00 08                 bne       loc_13E1C-13E14
00013E18 3B A0 00 01                 li        r29, 1
00013E1C 38 C0 58 1B loc_13E1C:      li        r6, msg03d
00013E20 39 60 00 83                 li        r11, 0x83 # 'â'
00013E24 99 66 00 03                 stb       r11, 3(r6)
00013E28 3C 60 00 00                 lis       r3, command@h
00013E2C 38 63 73 D8                 addi      r3, r3, command@l
00013E30 57 BD 06 3E                 clrlwi    r29, r29, 24  # r29 = r29 & 0xFF
00013E34 1C 9D 00 34                 mulli     r4, r29, 0x34
00013E38 7F A3 20 AE                 lbzx      r29, r3, r4
00013E3C 9B A6 00 04                 stb       r29, 4(r6)
00013E40 3A A0 58 17                 li        r21, 0x5817
00013E44 89 46 00 01                 lbz       r10, 1(r6)
00013E48 3B 0A 00 08                 addi      r24, r10, 8
00013E4C 38 C0 58 29                 li        r6, msg83
00013E50 57 AB 07 7E                 clrlwi    r11, r29, 29  # r11 = r29 & 7
00013E54 39 6B 00 01                 addi      r11, r11, 1
00013E58 99 66 00 01                 stb       r11, 1(r6)
00013E5C 9B A6 00 02                 stb       r29, 2(r6)
00013E60 38 C0 00 00                 li        r6, 0
00013E64 7D 83 22 14                 add       r12, r3, r4
00013E68 3B AC 00 18                 addi      r29, r12, 0x18
00013E6C 85 9D 00 04 loc_13E6C:      lwzu      r12, 4(r29)
00013E70 39 60 00 00                 li        r11, 0
00013E74 2C 0C 00 00                 cmpwi     r12, 0
00013E78 41 82 00 0C                 beq       loc_13E84-13E78
00013E7C 81 7D 00 00                 lwz       r11, 0(r29)
00013E80 89 6B 00 00                 lbz       r11, 0(r11)
00013E84 39 80 58 2C loc_13E84:      li        r12, 0x582C
00013E88 7D 6C 31 AE                 stbx      r11, r12, r6
00013E8C 38 C6 00 01                 addi      r6, r6, 1
00013E90 28 06 00 06                 cmplwi    r6, 6
00013E94 41 80 FF D8                 blt       loc_13E6C-13E94
00013E98 3B A0 00 00 loc_13E98:      li        r29, 0
00013E9C 48 00 00 4C                 b         loc_13EE8-13E9C
00013EA0 38 C0 00 00 loc_13EA0:      li        r6, 0
00013EA4 81 60 58 34                 lwz       r11, messageList
00013EA8 2C 0B 00 00                 cmpwi     r11, 0
00013EAC 41 82 00 3C                 beq       loc_13EE8-13EAC
00013EB0 38 80 58 34                 li        r4, messageList
00013EB4 38 65 00 00                 addi      r3, r5, 0
00013EB8 80 A4 00 00 loc_13EB8:      lwz       r5, 0(r4)
00013EBC 89 65 00 00                 lbz       r11, 0(r5)
00013EC0 7C 0B 18 00                 cmpw      r11, r3
00013EC4 40 82 00 14                 bne       loc_13ED8-13EC4
00013EC8 3A A5 FF FC                 addi      r21, r5, -4
00013ECC 89 65 00 01                 lbz       r11, 1(r5)
00013ED0 3B 0B 00 08                 addi      r24, r11, 8
00013ED4 48 00 00 14                 b         loc_13EE8-13ED4
00013ED8 38 C6 00 01 loc_13ED8:      addi      r6, r6, 1
00013EDC 85 64 00 04                 lwzu      r11, 4(r4)
00013EE0 2C 0B 00 00                 cmpwi     r11, 0
00013EE4 40 82 FF D4                 bne       loc_13EB8-13EE4
00013EE8 28 18 00 2C loc_13EE8:      cmplwi    r24, 0x2C
00013EEC 40 81 00 34                 ble       loc_13F20-13EEC
00013EF0 3B 00 00 2C                 li        r24, 0x2C # ','
00013EF4 48 00 00 2C                 b         loc_13F20-13EF4
00013EF8 39 99 00 02 loc_13EF8:      addi      r12, r25, 2
00013EFC 7C 0C C0 40                 cmplw     r12, r24
00013F00 40 82 00 0C                 bne       loc_13F0C-13F00
00013F04 7E 13 C9 AE                 stbx      r16, r19, r25
00013F08 48 00 00 18                 b         loc_13F20-13F08
00013F0C 39 99 00 02 loc_13F0C:      addi      r12, r25, 2
00013F10 7C 0C C0 40                 cmplw     r12, r24
00013F14 40 81 00 0C                 ble       loc_13F20-13F14
00013F18 39 80 00 00                 li        r12, 0
00013F1C 7D 93 C9 AE                 stbx      r12, r19, r25
00013F20 28 19 00 02 loc_13F20:      cmplwi    r25, 2
00013F24 41 80 00 0C                 blt       loc_13F30-13F24
00013F28 7D 93 C8 AE                 lbzx      r12, r19, r25
00013F2C 7E 10 62 78                 xor       r16, r16, r12
00013F30 7C 73 C8 AE loc_13F30:      lbzx      r3, r19, r25
00013F34 38 8E 00 00                 addi      r4, r14, 0
00013F38 4B FF CD 29                 bl        cameraSpiGetPut  ;10C60-00013F38
00013F3C 9C 6F 00 01                 stbu      r3, 1(r15)
00013F40 7C 19 C0 40                 cmplw     r25, r24
00013F44 40 80 00 28                 bge       loc_13F6C-13F44
00013F48 89 8F 00 00                 lbz       r12, 0(r15)
00013F4C 2C 0C 00 AA                 cmpwi     r12, 0xAA
00013F50 41 82 00 1C                 beq       loc_13F6C-13F50
00013F54 A1 9F 09 66                 lhz       r12, immr.PCDAT(r31)
00013F58 55 8C 05 EF                 rlwinm.   r12, r12, 0,23,23 # r12 = r12 & 0x100
00013F5C 41 82 00 10                 beq       loc_13F6C-13F5C
00013F60 3B 39 00 01                 addi      r25, r25, 1
00013F64 7C 19 C0 40                 cmplw     r25, r24
00013F68 41 80 FD B8                 blt       loc_13D20-13F68
00013F6C 89 8F 00 00 loc_13F6C:      lbz       r12, 0(r15)
00013F70 2C 0C 00 AA                 cmpwi     r12, 0xAA
00013F74 40 82 00 18                 bne       loc_13F8C-13F74
00013F78 89 8F FF FF                 lbz       r12, -1(r15)
00013F7C 2C 0C 00 00                 cmpwi     r12, 0
00013F80 41 82 00 0C                 beq       loc_13F8C-13F80
00013F84 39 80 00 01                 li        r12, 1
00013F88 99 80 22 2A                 stb       r12, mamiyaSerialV1
00013F8C 7C C0 00 A6 loc_13F8C:      mfmsr     r6
00013F90 7C 11 13 A6                 mtspr     eid, r0 # External interrupt disable
00013F94 4C 00 01 2C                 isync
00013F98 3C A0 00 01                 lis       r5, ((byte_8000+0x10000)@h)
00013F9C 38 A5 80 00                 addi      r5, r5, byte_8000@l
00013FA0 7C C6 28 38                 and       r6, r6, r5
00013FA4 7C 70 42 A6                 mfsprg0   r3
00013FA8 54 63 08 3E                 rotlwi    r3, r3, 1     # r3 = (r3 << 1) | (r3 >> 31)
00013FAC 7C 63 28 78                 andc      r3, r3, r5
00013FB0 7C 63 33 78                 or        r3, r3, r6
00013FB4 7C 70 43 A6                 mtsprg0   r3
00013FB8 81 9F 0A B8                 lwz       r12, immr.PBDIR(r31)
00013FBC 55 8C 07 76                 rlwinm    r12, r12, 0,29,27 # r12 = r12 & 0xFFFFFFF7
00013FC0 91 9F 0A B8                 stw       r12, immr.PBDIR(r31)
00013FC4 81 7F 0A C0                 lwz       r11, immr.PBODR(r31)
00013FC8 55 6B 07 76                 rlwinm    r11, r11, 0,29,27 # r11 = r11 & 0xFFFFFFF7
00013FCC 91 7F 0A C0                 stw       r11, immr.PBODR(r31)
00013FD0 81 5F 0A C4                 lwz       r10, immr.PBDAT(r31)
00013FD4 55 4A 07 76                 rlwinm    r10, r10, 0,29,27 # r10 = r10 & 0xFFFFFFF7
00013FD8 91 5F 0A C4                 stw       r10, immr.PBDAT(r31)
00013FDC 81 9F 0A BC                 lwz       r12, immr.PBPAR(r31)
00013FE0 55 8C 07 76                 rlwinm    r12, r12, 0,29,27 # r12 = r12 & 0xFFFFFFF7
00013FE4 91 9F 0A BC                 stw       r12, immr.PBPAR(r31)
00013FE8 7C 90 42 A6                 mfsprg0   r4
00013FEC 54 83 F8 3E                 rotrwi    r3, r4, 1     # r3 = (r4 << 31) | (r4 >> 1)
00013FF0 7C 70 43 A6                 mtsprg0   r3
00013FF4 70 84 80 00                 andi.     r4, r4, 0x8000
00013FF8 41 82 00 08                 beq       loc_14000-13FF8
00013FFC 7C 10 13 A6                 mtspr     eie, r0 # External interrupt enable
00014000 4C 00 01 2C loc_14000:      isync
00014004 38 71 00 00                 addi      r3, r17, 0
00014008 38 93 00 00                 addi      r4, r19, 0
0001400C 4B FF EA 1D                 bl        cameraMessageMamiya  ;12A28-0001400C
00014010 89 40 20 8C                 lbz       r10, cameraWatch
00014014 2C 0A 00 00                 cmpwi     r10, 0
00014018 40 82 00 10                 bne       loc_14028-14018
0001401C 89 80 21 B1                 lbz       r12, cameraLogWatch
00014020 2C 0C 00 00                 cmpwi     r12, 0
00014024 41 82 F7 D0                 beq       loc_137F4-14024
00014028 7D 9A CA 14 loc_14028:      add       r12, r26, r25
0001402C 38 AC 00 01                 addi      r5, r12, 1
00014030 38 DC 00 00                 addi      r6, r28, 0
00014034 38 61 00 08                 addi      r3, r1, 0xC0+var_B8
00014038 38 81 00 34                 addi      r4, r1, 0xC0+var_8C
0001403C 4B FF D2 B1                 bl        cameraSpiLog ;112EC-0001403C
00014040 4B FF F7 A8                 b         loc_137E8-14040
00014044 B9 C1 00 78                 lmw       r14, 0x78(r1)
00014048 80 01 00 C4                 lwz       r0, 0xC4(r1)
0001404C 7C 08 03 A6                 mtlr      r0
00014050 38 21 00 C0                 addi      r1, r1, 0xC0
00014054 4E 80 00 20                 blr
