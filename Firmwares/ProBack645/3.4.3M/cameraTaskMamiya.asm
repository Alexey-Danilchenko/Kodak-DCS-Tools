cameraTaskMamiya
00013B90-566C=E524
00013B90 94 21 FF 40                 stwu      r1, -0xC0(r1)
00013B94 7C 08 02 A6                 mflr      r0
00013B98 BD C1 00 78                 stmw      r14, 0xC0+var_48(r1)
00013B9C 90 01 00 C4                 stw       r0, 0xC0+arg_4(r1)
00013BA0 4B FF CE F5                 bl        cameraRegisterSettings 
00013BA4 3C 60 00 01                 lis       r3, mamiyaProperties@h
00013BA8 38 63 25 70                 addi      r3, r3, mamiyaProperties@l
00013BAC 38 80 00 02                 li        r4, 3
00013BB0 48 06 93 A1                 bl        propertyRegister 
00013BB4 3C 80 00 01                 lis       r4, cameraMamiyaMainMenu@ha
00013BB8 60 84 28 DC                 ori       r4, r4, cameraMamiyaMainMenu@l
00013BBC 38 60 00 28                 li        r3, MAIN_MENU_SHOW
00013BC0 48 02 AB 61                 bl        eventHook 
00013BC4 4B FF D8 B1                 bl        cameraPinSetup 
00013BC8 3A C0 00 00                 li        r22, 0
00013BCC 3B 60 00 00                 li        r27, 0
00013BD0 3F E0 20 00 loc_13BD0:      lis       r31, IMMR@h
00013BD4 3B FF 00 00                 addi      r31, r31, IMMR@l
00013BD8 3A E0 7D 00 loc_13BD8:      li        r23, 0x7D00
00013BDC 81 80 21 AC                 lwz       r12, shutterMode
00013BE0 2C 0C 00 00                 cmpwi     r12, 0
00013BE4 40 82 00 0C                 bne       loc_13BF0
00013BE8 3E E0 00 03                 lis       r23, loc_30D40@h
00013BEC 62 F7 0D 40                 ori       r23, rTimeDelay, loc_30D40@l
00013BF0 7C C0 00 A6 loc_13BF0:      mfmsr     r6
00013BF4 7C 11 13 A6                 mtspr     eid, r0 # External interrupt disable
00013BF8 4C 00 01 2C                 isync
00013BFC 3C A0 00 01                 lis       r5, byte_8000@ha
00013C00 38 A5 80 00                 addi      r5, r5, byte_8000@l
00013C04 7C C6 28 38                 and       r6, r6, r5
00013C08 7C 70 42 A6                 mfsprg0   r3
00013C0C 54 63 08 3E                 rotlwi    r3, r3, 1     # r3 = (r3 << 1) | (r3 >> 31)
00013C10 7C 63 28 78                 andc      r3, r3, r5
00013C14 7C 63 33 78                 or        r3, r3, r6
00013C18 7C 70 43 A6                 mtsprg0   r3
00013C1C 81 9F 0A C4                 lwz       r12, (IMMR.PBDAT - IMMR)(r31)
00013C20 61 8C 00 01                 ori       r12, r12, 1
00013C24 91 9F 0A C4                 stw       r12, (IMMR.PBDAT - IMMR)(r31)
00013C28 81 7F 0A C0                 lwz       r11, (IMMR.PBODR - IMMR)(r31)
00013C2C 55 6B 00 3C                 clrrwi    r11, r11, 1   # r11 = r11 & 0xFFFFFFFE
00013C30 91 7F 0A C0                 stw       r11, (IMMR.PBODR - IMMR)(r31)
00013C34 81 5F 0A B8                 lwz       r10, (IMMR.PBDIR - IMMR)(r31)
00013C38 61 4A 00 01                 ori       r10, r10, 1
00013C3C 91 5F 0A B8                 stw       r10, (IMMR.PBDIR - IMMR)(r31)
00013C40 81 9F 0A BC                 lwz       r12, (IMMR.PBPAR - IMMR)(r31)
00013C44 55 8C 00 3C                 clrrwi    r12, r12, 1   # r12 = r12 & 0xFFFFFFFE
00013C48 91 9F 0A BC                 stw       r12, (IMMR.PBPAR - IMMR)(r31)
00013C4C 7C 90 42 A6                 mfsprg0   r4
00013C50 54 83 F8 3E                 rotrwi    r3, r4, 1     # r3 = (r4 << 31) | (r4 >> 1)
00013C54 7C 70 43 A6                 mtsprg0   r3
00013C58 70 84 80 00                 andi.     r4, r4, 0x8000
00013C5C 41 82 00 08                 beq       loc_13C64
00013C60 7C 10 13 A6                 mtspr     eie, r0 # External interrupt enable
00013C64 4C 00 01 2C loc_13C64:      isync
00013C68 7C C0 00 A6 loc_13C68:      mfmsr     r6
00013C6C 7C 11 13 A6                 mtspr     eid, r0 # External interrupt disable
00013C70 4C 00 01 2C                 isync
00013C74 3C A0 00 01                 lis       r5, byte_8000@ha
00013C78 38 A5 80 00                 addi      r5, r5, byte_8000@l
00013C7C 7C C6 28 38 loc_13C7C:      and       r6, r6, r5
00013C80 7C 70 42 A6                 mfsprg0   r3
00013C84 54 63 08 3E                 rotlwi    r3, r3, 1     # r3 = (r3 << 1) | (r3 >> 31)
00013C88 7C 63 28 78                 andc      r3, r3, r5
00013C8C 7C 63 33 78                 or        r3, r3, r6
00013C90 7C 70 43 A6                 mtsprg0   r3
00013C94 A1 9F 09 60                 lhz       r12, (IMMR.PCDIR - IMMR)(r31)
00013C98 55 8C 06 2C                 rlwinm    r12, r12, 0,24,22 # r12 = r12 & 0xFFFFFEFF
00013C9C B1 9F 09 60                 sth       r12, (IMMR.PCDIR - IMMR)(r31)
00013CA0 A1 7F 09 64                 lhz       r11, (IMMR.PCSO - IMMR)(r31)
00013CA4 55 6B 06 2C                 rlwinm    r11, r11, 0,24,22 # r11 = r11 & 0xFFFFFEFF
00013CA8 B1 7F 09 64                 sth       r11, (IMMR.PCSO - IMMR)(r31)
00013CAC A1 5F 09 66                 lhz       r10, (IMMR.PCDAT - IMMR)(r31)
00013CB0 55 4A 06 2C                 rlwinm    r10, r10, 0,24,22 # r10 = r10 & 0xFFFFFEFF
00013CB4 B1 5F 09 66                 sth       r10, (IMMR.PCDAT - IMMR)(r31)
00013CB8 A1 9F 09 62                 lhz       r12, (IMMR.PCPAR - IMMR)(r31)
00013CBC 55 8C 06 2C                 rlwinm    r12, r12, 0,24,22 # r12 = r12 & 0xFFFFFEFF
00013CC0 B1 9F 09 62                 sth       r12, (IMMR.PCPAR - IMMR)(r31)
00013CC4 7C 90 42 A6                 mfsprg0   r4
00013CC8 54 83 F8 3E                 rotrwi    r3, r4, 1     # r3 = (r4 << 31) | (r4 >> 1)
00013CCC 7C 70 43 A6                 mtsprg0   r3
00013CD0 70 84 80 00                 andi.     r4, r4, 0x8000
00013CD4 41 82 00 08                 beq       loc_13CDC
00013CD8 7C 10 13 A6                 mtspr     eie, r0 # External interrupt enable
00013CDC 4C 00 01 2C loc_13CDC:      isync
00013CE0 A1 7F 09 66                 lhz       r11, (IMMR.PCDAT - IMMR)(r31)
00013CE4 55 6B 05 EF                 rlwinm.   r11, r11, 0,23,23 # r11 = r11 & 0x100
00013CE8 41 82 00 24                 beq       loc_13D0C
00013CEC 38 60 FF FF loc_13CEC:      li        r3, -1
00013CF0 38 80 00 01                 li        r4, 1
00013CF4 38 A0 03 E8                 li        r5, 0x3E8
00013CF8 38 C0 00 00                 li        r6, 0
00013CFC 48 06 54 1D                 bl        osEvPend 
00013D00 A1 9F 09 66                 lhz       r12, (IMMR.PCDAT - IMMR)(r31)
00013D04 55 8C 05 EF                 rlwinm.   r12, r12, 0,23,23 # r12 = r12 & 0x100
00013D08 40 82 FF E4                 bne       loc_13CEC
00013D0C A1 9F 09 66 loc_13D0C:      lhz       r12, (IMMR.PCDAT - IMMR)(r31)
00013D10 55 8C 05 EF                 rlwinm.   r12, r12, 0,23,23 # r12 = r12 & 0x100
00013D14 40 82 02 20                 bne       loc_13F34
00013D18 89 80 21 E9 loc_13D18:      lbz       r12, camAwake
00013D1C 2C 0C 00 00                 cmpwi     r12, 0
00013D20 40 82 00 34                 bne       loc_13D54
00013D24 89 80 21 E5                 lbz       r12, camSet
00013D28 2C 0C 00 00                 cmpwi     r12, 0
00013D2C 40 82 00 28                 bne       loc_13D54
00013D30 89 80 21 E6                 lbz       r12, camGet
00013D34 2C 0C 00 00                 cmpwi     r12, 0
00013D38 40 82 00 1C                 bne       loc_13D54
00013D3C 89 80 21 48                 lbz       r12, takePicture
00013D40 2C 0C 00 00                 cmpwi     r12, 0
00013D44 40 82 00 10                 bne       loc_13D54
00013D48 89 80 22 28                 lbz       r12, cameraWake
00013D4C 2C 0C 00 00                 cmpwi     r12, 0
00013D50 41 82 00 1C                 beq       loc_13D6C
00013D54 38 60 FF FF loc_13D54:      li        r3, -1
00013D58 38 80 00 01                 li        r4, 1
00013D5C 38 A0 03 E8                 li        r5, 0x3E8
00013D60 38 C0 00 00                 li        r6, 0
00013D64 48 06 53 B5                 bl        osEvPend 
00013D68 48 00 00 1C                 b         loc_13D84
00013D6C 38 60 FF FF loc_13D6C:      li        r3, -1
00013D70 38 80 00 01                 li        r4, 1
00013D74 3C A0 00 4C                 lis       r5, 0x4C # 0x4C4B40 # 'L'
00013D78 60 A5 4B 40                 ori       r5, r5, 0x4B40 # 0x4C4B40
00013D7C 38 C0 00 00                 li        r6, 0
00013D80 48 06 53 99                 bl        osEvPend 
00013D84 48 00 46 E9 loc_13D84:      bl        cameraDialogCheck 
00013D88 38 7B 00 00                 addi      r3, r27, 0
00013D8C 4B FF F4 F5                 bl        cameraMessageSetupMamiya 
00013D90 3B A3 00 00                 addi      r29, r3, 0
00013D94 57 BD 06 3E                 clrlwi    r29, r29, 24  # r29 = r29 & 0xFF
00013D98 2C 1D 00 00                 cmpwi     r29, 0
00013D9C 41 82 01 8C                 beq       loc_13F28
00013DA0 89 80 21 E9                 lbz       r12, camAwake
00013DA4 2C 0C 00 00                 cmpwi     r12, 0
00013DA8 40 82 00 20                 bne       loc_13DC8
00013DAC 48 08 59 71                 bl        timeUsec 
00013DB0 81 80 21 D0                 lwz       r12, bodySleepTime
00013DB4 7C 6C 18 50                 subf      r3, r12, r3
00013DB8 3D 60 00 07                 lis       r11, loc_7A120@h
00013DBC 61 6B A1 20                 ori       r11, r11, loc_7A120@l
00013DC0 7C 03 58 40                 cmplw     r3, r11
00013DC4 41 81 00 10                 bgt       loc_13DD4
00013DC8 81 80 21 E0 loc_13DC8:      lwz       r12, backMessageCount
00013DCC 28 0C 00 02                 cmplwi    r12, 2
00013DD0 41 80 01 58                 blt       loc_13F28
00013DD4 48 08 59 49 loc_13DD4:      bl        timeUsec 
00013DD8 7C 76 18 50                 subf      r3, r22, r3
00013DDC 7C 03 B8 40                 cmplw     r3, r23
00013DE0 40 81 01 48                 ble       loc_13F28
00013DE4 89 80 21 EF                 lbz       r12, camReplyDelay
00013DE8 2C 0C 00 00                 cmpwi     r12, 0
00013DEC 41 82 00 18                 beq       loc_13E04
00013DF0 48 08 59 2D                 bl        timeUsec 
00013DF4 81 80 21 C4                 lwz       r12, lastMessageTime
00013DF8 7C 6C 18 50                 subf      r3, r12, r3
00013DFC 7C 03 B8 40                 cmplw     r3, r23
00013E00 40 81 01 28                 ble       loc_13F28
00013E04 57 BD 06 3E loc_13E04:      clrlwi    r29, r29, 24  # r29 = r29 & 0xFF
00013E08 38 BD 00 00                 addi      r5, r29, 0
00013E0C 38 60 00 C7                 li        r3, 0xC7 # 'Ã'
00013E10 38 80 00 00                 li        r4, 0
00013E14 48 02 9B 65                 bl        eventPost 
00013E18 3A 40 00 01                 li        r18, 1
00013E1C 7C C0 00 A6                 mfmsr     r6
00013E20 7C 11 13 A6                 mtspr     eid, r0 # External interrupt disable
00013E24 4C 00 01 2C                 isync
00013E28 3C A0 00 01                 lis       r5, byte_8000@ha
00013E2C 38 A5 80 00                 addi      r5, r5, byte_8000@l
00013E30 7C C6 28 38                 and       r6, r6, r5
00013E34 7C 70 42 A6                 mfsprg0   r3
00013E38 54 63 08 3E                 rotlwi    r3, r3, 1     # r3 = (r3 << 1) | (r3 >> 31)
00013E3C 7C 63 28 78                 andc      r3, r3, r5
00013E40 7C 63 33 78                 or        r3, r3, r6
00013E44 7C 70 43 A6                 mtsprg0   r3
00013E48 A1 3F 09 66                 lhz       r9, (IMMR.PCDAT - IMMR)(r31)
00013E4C 61 29 01 00                 ori       r9, r9, 0x100
00013E50 B1 3F 09 66                 sth       r9, (IMMR.PCDAT - IMMR)(r31)
00013E54 A1 9F 09 64                 lhz       r12, (IMMR.PCSO - IMMR)(r31)
00013E58 55 8C 06 2C                 rlwinm    r12, r12, 0,24,22 # r12 = r12 & 0xFFFFFEFF
00013E5C B1 9F 09 64                 sth       r12, (IMMR.PCSO - IMMR)(r31)
00013E60 A1 7F 09 60                 lhz       r11, (IMMR.PCDIR - IMMR)(r31)
00013E64 61 6B 01 00                 ori       r11, r11, 0x100
00013E68 B1 7F 09 60                 sth       r11, 0x960(r31)
00013E6C A1 5F 09 62                 lhz       r10, 0x962(r31)
00013E70 55 4A 06 2C                 rlwinm    r10, r10, 0,24,22 # r10 = r10 & 0xFFFFFEFF
00013E74 B1 5F 09 62                 sth       r10, 0x962(r31)
00013E78 7C 90 42 A6                 mfsprg0   r4
00013E7C 54 83 F8 3E                 rotrwi    r3, r4, 1     # r3 = (r4 << 31) | (r4 >> 1)
00013E80 7C 70 43 A6                 mtsprg0   r3
00013E84 70 84 80 00                 andi.     r4, r4, 0x8000
00013E88 41 82 00 08                 beq       loc_13E90
00013E8C 7C 10 13 A6                 mtspr     eie, r0 # External interrupt enable
00013E90 4C 00 01 2C loc_13E90:      isync
00013E94 38 60 0B B8                 li        r3, 0xBB8
00013E98 48 08 5A 21                 bl        waitUsec 
00013E9C 7C C0 00 A6                 mfmsr     r6
00013EA0 7C 11 13 A6                 mtspr     eid, r0 # External interrupt disable
00013EA4 4C 00 01 2C                 isync
00013EA8 3C A0 00 01                 lis       r5, byte_8000@ha
00013EAC 38 A5 80 00                 addi      r5, r5, byte_8000@l
00013EB0 7C C6 28 38                 and       r6, r6, r5
00013EB4 7C 70 42 A6                 mfsprg0   r3
00013EB8 54 63 08 3E                 rotlwi    r3, r3, 1     # r3 = (r3 << 1) | (r3 >> 31)
00013EBC 7C 63 28 78                 andc      r3, r3, r5
00013EC0 7C 63 33 78                 or        r3, r3, r6
00013EC4 7C 70 43 A6                 mtsprg0   r3
00013EC8 A1 7F 09 60                 lhz       r11, 0x960(r31)
00013ECC 55 6B 06 2C                 rlwinm    r11, r11, 0,24,22 # r11 = r11 & 0xFFFFFEFF
00013ED0 B1 7F 09 60                 sth       r11, 0x960(r31)
00013ED4 A1 5F 09 64                 lhz       r10, 0x964(r31)
00013ED8 55 4A 06 2C                 rlwinm    r10, r10, 0,24,22 # r10 = r10 & 0xFFFFFEFF
00013EDC B1 5F 09 64                 sth       r10, 0x964(r31)
00013EE0 A1 9F 09 66                 lhz       r12, 0x966(r31)
00013EE4 55 8C 06 2C                 rlwinm    r12, r12, 0,24,22 # r12 = r12 & 0xFFFFFEFF
00013EE8 B1 9F 09 66                 sth       r12, 0x966(r31)
00013EEC A1 7F 09 62                 lhz       r11, 0x962(r31)
00013EF0 55 6B 06 2C                 rlwinm    r11, r11, 0,24,22 # r11 = r11 & 0xFFFFFEFF
00013EF4 B1 7F 09 62                 sth       r11, 0x962(r31)
00013EF8 7C 90 42 A6                 mfsprg0   r4
00013EFC 54 83 F8 3E                 rotrwi    r3, r4, 1     # r3 = (r4 << 31) | (r4 >> 1)
00013F00 7C 70 43 A6                 mtsprg0   r3
00013F04 70 84 80 00                 andi.     r4, r4, 0x8000
00013F08 41 82 00 08                 beq       loc_13F10
00013F0C 7C 10 13 A6                 mtspr     eie, r0 # External interrupt enable
00013F10 4C 00 01 2C loc_13F10:      isync
00013F14 38 60 03 E8                 li        r3, 0x3E8
00013F18 48 08 59 A1                 bl        waitUsec 
00013F1C 48 08 58 01                 bl        timeUsec 
00013F20 3A C3 00 00                 addi      r22, r3, 0
00013F24 3B 7B 00 01                 addi      r27, r27, 1
00013F28 A1 9F 09 66 loc_13F28:      lhz       r12, 0x966(r31)
00013F2C 55 8C 05 EF                 rlwinm.   r12, r12, 0,23,23 # r12 = r12 & 0x100
00013F30 41 82 FD E8                 beq       loc_13D18
00013F34 81 9F 0A C4 loc_13F34:      lwz       r12, 0xAC4(r31)
00013F38 55 8C 07 7B                 rlwinm.   r12, r12, 0,29,29 # r12 = r12 & 4
00013F3C 41 82 FD 2C                 beq       loc_13C68
00013F40 48 08 57 DD                 bl        timeUsec 
00013F44 3A C3 00 00                 addi      r22, r3, 0
00013F48 3B 60 00 00                 li        r27, 0
00013F4C 38 61 00 08                 addi      r3, r1, 0xC0+var_B8
00013F50 38 80 00 00                 li        r4, 0
00013F54 38 A0 00 2C                 li        r5, 0x2C # ','
00013F58 48 09 73 9D                 bl        memset 
00013F5C 38 61 00 34                 addi      r3, r1, 0xC0+var_8C
00013F60 38 80 00 00                 li        r4, 0
00013F64 38 A0 00 2C                 li        r5, 0x2C # ','
00013F68 48 09 73 8D                 bl        memset 
00013F6C 39 20 00 AA                 li        r9, 0xAA # '¬'
00013F70 99 21 00 33                 stb       r9, 0xC0+var_8D(r1)
00013F74 3B 80 00 00                 li        r28, 0
00013F78 3B 40 00 00                 li        r26, 0
00013F7C 88 61 00 34                 lbz       r3, 0xC0+var_8C(r1)
00013F80 38 97 00 00                 addi      r4, r23, 0
00013F84 4B FF CC DD                 bl        cameraSpiGetPut 
00013F88 3B 23 00 00                 addi      r25, r3, 0
00013F8C 9B 21 00 08                 stb       r25, 0xC0+var_B8(r1)
00013F90 57 39 06 3E                 clrlwi    r25, r25, 24  # r25 = r25 & 0xFF
00013F94 2C 19 00 7E                 cmpwi     r25, 0x7E
00013F98 40 82 00 B8                 bne       loc_14050
00013F9C 3B 40 00 02                 li        r26, 2
00013FA0 2C 12 00 00                 cmpwi     r18, 0
00013FA4 41 82 00 7C                 beq       loc_14020
00013FA8 7C C0 00 A6                 mfmsr     r6
00013FAC 7C 11 13 A6                 mtspr     eid, r0 # External interrupt disable
00013FB0 4C 00 01 2C                 isync
00013FB4 3C A0 00 01                 lis       r5, byte_8000@ha
00013FB8 38 A5 80 00                 addi      r5, r5, byte_8000@l
00013FBC 7C C6 28 38                 and       r6, r6, r5
00013FC0 7C 70 42 A6                 mfsprg0   r3
00013FC4 54 63 08 3E                 rotlwi    r3, r3, 1     # r3 = (r3 << 1) | (r3 >> 31)
00013FC8 7C 63 28 78                 andc      r3, r3, r5
00013FCC 7C 63 33 78                 or        r3, r3, r6
00013FD0 7C 70 43 A6                 mtsprg0   r3
00013FD4 81 7F 0A C4                 lwz       r11, 0xAC4(r31)
00013FD8 55 6B 07 76                 rlwinm    r11, r11, 0,29,27 # r11 = r11 & 0xFFFFFFF7
00013FDC 91 7F 0A C4                 stw       r11, 0xAC4(r31)
00013FE0 81 5F 0A C0                 lwz       r10, 0xAC0(r31)
00013FE4 55 4A 07 76                 rlwinm    r10, r10, 0,29,27 # r10 = r10 & 0xFFFFFFF7
00013FE8 91 5F 0A C0                 stw       r10, 0xAC0(r31)
00013FEC 81 9F 0A B8                 lwz       r12, 0xAB8(r31)
00013FF0 61 8C 00 08                 ori       r12, r12, 8
00013FF4 91 9F 0A B8                 stw       r12, 0xAB8(r31)
00013FF8 81 7F 0A BC                 lwz       r11, 0xABC(r31)
00013FFC 61 6B 00 08                 ori       r11, r11, 8
00014000 91 7F 0A BC                 stw       r11, 0xABC(r31)
00014004 7C 90 42 A6                 mfsprg0   r4
00014008 54 83 F8 3E                 rotrwi    r3, r4, 1     # r3 = (r4 << 31) | (r4 >> 1)
0001400C 7C 70 43 A6                 mtsprg0   r3
00014010 70 84 80 00                 andi.     r4, r4, 0x8000
00014014 41 82 00 08                 beq       loc_1401C
00014018 7C 10 13 A6                 mtspr     eie, r0 # External interrupt enable
0001401C 4C 00 01 2C loc_1401C:      isync
00014020 39 80 00 01 loc_14020:      li        r12, 1
00014024 99 81 00 35                 stb       r12, 0xC0+var_8C+1(r1)
00014028 39 60 00 00                 li        r11, 0
0001402C 99 61 00 36                 stb       r11, 0xC0+var_8A(r1)
00014030 38 60 00 01                 li        r3, 1
00014034 38 97 00 00                 addi      r4, r23, 0
00014038 4B FF CC 29                 bl        cameraSpiGetPut 
0001403C 98 61 00 09                 stb       r3, 0xC0+var_B8+1(r1)
00014040 88 61 00 36                 lbz       r3, 0xC0+var_8A(r1)
00014044 38 97 00 00                 addi      r4, r23, 0
00014048 4B FF CC 19                 bl        cameraSpiGetPut 
0001404C 98 61 00 0A                 stb       r3, 0xC0+var_B6(r1)
00014050 3A 40 00 00 loc_14050:      li        r18, 0
00014054 7D 61 D2 14                 add       r11, r1, r26
00014058 3A 2B 00 08                 addi      r17, r11, 8
0001405C 7D 81 D2 14                 add       r12, r1, r26
00014060 3A 6C 00 34                 addi      r19, r12, 0x34
00014064 3A B1 FF FF                 addi      r21, r17, -1
00014068 89 51 00 00                 lbz       r10, 0(r17)
0001406C 2C 0A 00 01                 cmpwi     r10, 1
00014070 40 82 00 80                 bne       loc_140F0
00014074 3B 80 00 01                 li        r28, 1
00014078 7C C0 00 A6                 mfmsr     r6
0001407C 7C 11 13 A6                 mtspr     eid, r0 # External interrupt disable
00014080 4C 00 01 2C                 isync
00014084 3C A0 00 01                 lis       r5, byte_8000@ha
00014088 38 A5 80 00                 addi      r5, r5, byte_8000@l
0001408C 7C C6 28 38                 and       r6, r6, r5
00014090 7C 70 42 A6                 mfsprg0   r3
00014094 54 63 08 3E                 rotlwi    r3, r3, 1     # r3 = (r3 << 1) | (r3 >> 31)
00014098 7C 63 28 78                 andc      r3, r3, r5
0001409C 7C 63 33 78                 or        r3, r3, r6
000140A0 7C 70 43 A6                 mtsprg0   r3
000140A4 81 5F 0A C4                 lwz       r10, 0xAC4(r31)
000140A8 55 4A 07 76                 rlwinm    r10, r10, 0,29,27 # r10 = r10 & 0xFFFFFFF7
000140AC 91 5F 0A C4                 stw       r10, 0xAC4(r31)
000140B0 81 9F 0A C0                 lwz       r12, 0xAC0(r31)
000140B4 55 8C 07 76                 rlwinm    r12, r12, 0,29,27 # r12 = r12 & 0xFFFFFFF7
000140B8 91 9F 0A C0                 stw       r12, 0xAC0(r31)
000140BC 81 7F 0A B8                 lwz       r11, 0xAB8(r31)
000140C0 61 6B 00 08                 ori       r11, r11, 8
000140C4 91 7F 0A B8                 stw       r11, 0xAB8(r31)
000140C8 81 5F 0A BC                 lwz       r10, 0xABC(r31)
000140CC 61 4A 00 08                 ori       r10, r10, 8
000140D0 91 5F 0A BC                 stw       r10, 0xABC(r31)
000140D4 7C 90 42 A6                 mfsprg0   r4
000140D8 54 83 F8 3E                 rotrwi    r3, r4, 1     # r3 = (r4 << 31) | (r4 >> 1)
000140DC 7C 70 43 A6                 mtsprg0   r3
000140E0 70 84 80 00                 andi.     r4, r4, 0x8000
000140E4 41 82 00 08                 beq       loc_140EC
000140E8 7C 10 13 A6                 mtspr     eie, r0 # External interrupt enable
000140EC 4C 00 01 2C loc_140EC:      isync
000140F0 3B 00 00 08 loc_140F0:      li        r24, 8
000140F4 89 91 00 00                 lbz       r12, 0(r17)
000140F8 2C 0C 00 7D                 cmpwi     r12, 0x7D
000140FC 40 82 00 08                 bne       loc_14104
00014100 3B 00 00 02                 li        r24, 2
00014104 3A 00 00 00 loc_14104:      li        r16, 0
00014108 3B 20 00 01                 li        r25, 1
0001410C 39 F1 00 00                 addi      r15, r17, 0
00014110 39 D7 00 00                 addi      r14, r23, 0
00014114 89 91 00 00 loc_14114:      lbz       r12, 0(r17)
00014118 2C 0C 00 01                 cmpwi     r12, 1
0001411C 41 82 00 10                 beq       loc_1412C
00014120 39 80 00 00                 li        r12, 0
00014124 7D 93 C9 AE                 stbx      r12, r19, r25
00014128 48 00 02 08                 b         loc_14330
0001412C 7D 95 C8 AE loc_1412C:      lbzx      r12, r21, r25
00014130 7D 93 C9 AE                 stbx      r12, r19, r25
00014134 2C 19 00 02                 cmpwi     r25, 2
00014138 40 82 00 40                 bne       loc_14178
0001413C 81 80 21 AC                 lwz       r12, shutterMode
00014140 2C 0C 00 00                 cmpwi     r12, 0
00014144 40 82 00 28                 bne       loc_1416C
00014148 81 80 21 E0                 lwz       r12, backMessageCount
0001414C 28 0C 00 02                 cmplwi    r12, 2
00014150 41 80 00 1C                 blt       loc_1416C
00014154 89 80 21 DD                 lbz       r12, digitalBody
00014158 2C 0C 00 00                 cmpwi     r12, 0
0001415C 40 82 00 10                 bne       loc_1416C
00014160 39 80 00 11 loc_14160:      li        r12, 0x11
00014164 7D 93 C9 AE                 stbx      r12, r19, r25
00014168 48 00 01 B8                 b         loc_14320
0001416C 39 80 00 81 loc_1416C:      li        r12, 0x81 # 'ü'
00014170 7D 93 C9 AE                 stbx      r12, r19, r25
00014174 48 00 01 AC                 b         loc_14320
00014178 2C 19 00 04 loc_14178:      cmpwi     r25, 4
0001417C 40 82 01 7C                 bne       loc_142F8
00014180 89 91 00 03                 lbz       r12, 3(r17)
00014184 3B 0C 00 08                 addi      r24, r12, 8
00014188 88 B1 00 02                 lbz       r5, 2(r17)
0001418C 2C 05 00 03                 cmpwi     r5, 3
00014190 40 82 01 10                 bne       loc_142A0
00014194 39 80 00 00                 li        r12, 0
00014198 99 80 21 EF                 stb       r12, camReplyDelay
0001419C 81 80 21 AC                 lwz       r12, shutterMode
000141A0 2C 0C 00 00                 cmpwi     r12, 0
000141A4 40 82 00 20                 bne       loc_141C4
000141A8 89 60 21 DD                 lbz       r11, digitalBody
000141AC 2C 0B 00 00                 cmpwi     r11, 0
000141B0 40 82 00 14                 bne       loc_141C4
000141B4 3A A0 58 14                 li        r21, 0x5814
000141B8 89 60 58 19                 lbz       r11, byte_5819
000141BC 3B 0B 00 08                 addi      r24, r11, 8
000141C0 48 00 00 D8                 b         loc_14298
000141C4 57 AC 06 F6 loc_141C4:      rlwinm    r12, r29, 0,27,27 # r12 = r29 & 0x10
000141C8 2C 0C 00 00                 cmpwi     r12, 0
000141CC 41 82 00 40                 beq       loc_1420C
000141D0 57 BD 07 34                 rlwinm    r29, r29, 0,28,26 # r29 = r29 & 0xFFFFFFEF
000141D4 38 C0 58 1B                 li        r6, msg03d
000141D8 39 40 00 82                 li        r10, 0x82 # 'é'
000141DC 99 46 00 03                 stb       r10, 3(r6)
000141E0 3D 20 00 00                 lis       r9, command@h
000141E4 39 29 73 D8                 addi      r9, r9, command@l
000141E8 57 BD 06 3E                 clrlwi    r29, r29, 24  # r29 = r29 & 0xFF
000141EC 1D 9D 00 34                 mulli     r12, r29, 0x34
000141F0 7D 29 60 AE                 lbzx      r9, r9, r12
000141F4 55 29 06 36                 rlwinm    r9, r9, 0,24,27 # r9 = r9 & 0xF0
000141F8 99 26 00 04                 stb       r9, 4(r6)
000141FC 3A A0 58 17                 li        r21, 0x5817
00014200 89 46 00 01                 lbz       r10, 1(r6)
00014204 3B 0A 00 08                 addi      r24, r10, 8
00014208 48 00 00 90                 b         loc_14298
0001420C 57 BD 06 3E loc_1420C:      clrlwi    r29, r29, 24  # r29 = r29 & 0xFF
00014210 2C 1D 00 00                 cmpwi     r29, 0
00014214 40 82 00 08                 bne       loc_1421C
00014218 3B A0 00 01                 li        r29, 1
0001421C 38 C0 58 1B loc_1421C:      li        r6, msg03d
00014220 39 60 00 83                 li        r11, 0x83 # 'â'
00014224 99 66 00 03                 stb       r11, 3(r6)
00014228 3C 60 00 00                 lis       r3, command@h
0001422C 38 63 73 D8                 addi      r3, r3, command@l
00014230 57 BD 06 3E                 clrlwi    r29, r29, 24  # r29 = r29 & 0xFF
00014234 1C 9D 00 34                 mulli     r4, r29, 0x34
00014238 7F A3 20 AE                 lbzx      r29, r3, r4
0001423C 9B A6 00 04                 stb       r29, 4(r6)
00014240 3A A0 58 17                 li        r21, 0x5817
00014244 89 46 00 01                 lbz       r10, 1(r6)
00014248 3B 0A 00 08                 addi      r24, r10, 8
0001424C 38 C0 58 29                 li        r6, msg83
00014250 57 AB 07 7E                 clrlwi    r11, r29, 29  # r11 = r29 & 7
00014254 39 6B 00 01                 addi      r11, r11, 1
00014258 99 66 00 01                 stb       r11, 1(r6)
0001425C 9B A6 00 02                 stb       r29, 2(r6)
00014260 38 C0 00 00                 li        r6, 0
00014264 7D 83 22 14                 add       r12, r3, r4
00014268 3B AC 00 18                 addi      r29, r12, 0x18
0001426C 85 9D 00 04 loc_1426C:      lwzu      r12, 4(r29)
00014270 39 60 00 00                 li        r11, 0
00014274 2C 0C 00 00                 cmpwi     r12, 0
00014278 41 82 00 0C                 beq       loc_14284
0001427C 81 7D 00 00                 lwz       r11, 0(r29)
00014280 89 6B 00 00                 lbz       r11, 0(r11)
00014284 39 80 58 2C loc_14284:      li        r12, 0x582C
00014288 7D 6C 31 AE                 stbx      r11, r12, r6
0001428C 38 C6 00 01                 addi      r6, r6, 1
00014290 28 06 00 06                 cmplwi    r6, 6
00014294 41 80 FF D8                 blt       loc_1426C
00014298 3B A0 00 00 loc_14298:      li        r29, 0
0001429C 48 00 00 4C                 b         loc_142E8
000142A0 38 C0 00 00 loc_142A0:      li        r6, 0
000142A4 81 60 58 34                 lwz       r11, messageList
000142A8 2C 0B 00 00                 cmpwi     r11, 0
000142AC 41 82 00 3C                 beq       loc_142E8
000142B0 38 80 58 34                 li        r4, messageList
000142B4 38 65 00 00                 addi      r3, r5, 0
000142B8 80 A4 00 00 loc_142B8:      lwz       r5, 0(r4)
000142BC 89 65 00 00                 lbz       r11, 0(r5)
000142C0 7C 0B 18 00                 cmpw      r11, r3
000142C4 40 82 00 14                 bne       loc_142D8
000142C8 3A A5 FF FC                 addi      r21, r5, -4
000142CC 89 65 00 01                 lbz       r11, 1(r5)
000142D0 3B 0B 00 08                 addi      r24, r11, 8
000142D4 48 00 00 14                 b         loc_142E8
000142D8 38 C6 00 01 loc_142D8:      addi      r6, r6, 1
000142DC 85 64 00 04                 lwzu      r11, 4(r4)
000142E0 2C 0B 00 00                 cmpwi     r11, 0
000142E4 40 82 FF D4                 bne       loc_142B8
000142E8 28 18 00 2C loc_142E8:      cmplwi    r24, 0x2C
000142EC 40 81 00 34                 ble       loc_14320
000142F0 3B 00 00 2C                 li        r24, 0x2C # ','
000142F4 48 00 00 2C                 b         loc_14320
000142F8 39 99 00 02 loc_142F8:      addi      r12, r25, 2
000142FC 7C 0C C0 40                 cmplw     r12, r24
00014300 40 82 00 0C                 bne       loc_1430C
00014304 7E 13 C9 AE                 stbx      r16, r19, r25
00014308 48 00 00 18                 b         loc_14320
0001430C 39 99 00 02 loc_1430C:      addi      r12, r25, 2
00014310 7C 0C C0 40                 cmplw     r12, r24
00014314 40 81 00 0C                 ble       loc_14320
00014318 39 80 00 00                 li        r12, 0
0001431C 7D 93 C9 AE                 stbx      r12, r19, r25
00014320 28 19 00 02 loc_14320:      cmplwi    r25, 2
00014324 41 80 00 0C                 blt       loc_14330
00014328 7D 93 C8 AE                 lbzx      r12, r19, r25
0001432C 7E 10 62 78                 xor       r16, r16, r12
00014330 7C 73 C8 AE loc_14330:      lbzx      r3, r19, r25
00014334 38 8E 00 00                 addi      r4, r14, 0
00014338 4B FF C9 29                 bl        cameraSpiGetPut 
0001433C 9C 6F 00 01                 stbu      r3, 1(r15)
00014340 7C 19 C0 40                 cmplw     r25, r24
00014344 40 80 00 28                 bge       loc_1436C
00014348 89 8F 00 00                 lbz       r12, 0(r15)
0001434C 2C 0C 00 AA                 cmpwi     r12, 0xAA
00014350 41 82 00 1C                 beq       loc_1436C
00014354 A1 9F 09 66                 lhz       r12, immr.PCDAT(r31)
00014358 55 8C 05 EF                 rlwinm.   r12, r12, 0,23,23 # r12 = r12 & 0x100
0001435C 41 82 00 10                 beq       loc_1436C
00014360 3B 39 00 01                 addi      r25, r25, 1
00014364 7C 19 C0 40                 cmplw     r25, r24
00014368 41 80 FD AC                 blt       loc_14114
0001436C 89 8F 00 00 loc_1436C:      lbz       r12, 0(r15)
00014370 2C 0C 00 AA                 cmpwi     r12, 0xAA
00014374 40 82 00 18                 bne       loc_1438C
00014378 89 8F FF FF                 lbz       r12, -1(r15)
0001437C 2C 0C 00 00                 cmpwi     r12, 0
00014380 41 82 00 0C                 beq       loc_1438C
00014384 39 80 00 01                 li        r12, 1
00014388 99 80 22 2A                 stb       r12, mamiyaSerialV1
0001438C 7C C0 00 A6 loc_1438C:      mfmsr     r6
00014390 7C 11 13 A6                 mtspr     eid, r0 # External interrupt disable
00014394 4C 00 01 2C                 isync
00014398 3C A0 00 01                 lis       r5, byte_8000@ha
0001439C 38 A5 80 00                 addi      r5, r5, byte_8000@l
000143A0 7C C6 28 38                 and       r6, r6, r5
000143A4 7C 70 42 A6                 mfsprg0   r3
000143A8 54 63 08 3E                 rotlwi    r3, r3, 1     # r3 = (r3 << 1) | (r3 >> 31)
000143AC 7C 63 28 78                 andc      r3, r3, r5
000143B0 7C 63 33 78                 or        r3, r3, r6
000143B4 7C 70 43 A6                 mtsprg0   r3
000143B8 81 9F 0A B8                 lwz       r12, immr.PBDIR(r31)
000143BC 55 8C 07 76                 rlwinm    r12, r12, 0,29,27 # r12 = r12 & 0xFFFFFFF7
000143C0 91 9F 0A B8                 stw       r12, immr.PBDIR(r31)
000143C4 81 7F 0A C0                 lwz       r11, immr.PBODR(r31)
000143C8 55 6B 07 76                 rlwinm    r11, r11, 0,29,27 # r11 = r11 & 0xFFFFFFF7
000143CC 91 7F 0A C0                 stw       r11, immr.PBODR(r31)
000143D0 81 5F 0A C4                 lwz       r10, immr.PBDAT(r31)
000143D4 55 4A 07 76                 rlwinm    r10, r10, 0,29,27 # r10 = r10 & 0xFFFFFFF7
000143D8 91 5F 0A C4                 stw       r10, immr.PBDAT(r31)
000143DC 81 9F 0A BC                 lwz       r12, immr.PBPAR(r31)
000143E0 55 8C 07 76                 rlwinm    r12, r12, 0,29,27 # r12 = r12 & 0xFFFFFFF7
000143E4 91 9F 0A BC                 stw       r12, immr.PBPAR(r31)
000143E8 7C 90 42 A6                 mfsprg0   r4
000143EC 54 83 F8 3E                 rotrwi    r3, r4, 1     # r3 = (r4 << 31) | (r4 >> 1)
000143F0 7C 70 43 A6                 mtsprg0   r3
000143F4 70 84 80 00                 andi.     r4, r4, 0x8000
000143F8 41 82 00 08                 beq       loc_14400
000143FC 7C 10 13 A6                 mtspr     eie, r0 # External interrupt enable
00014400 4C 00 01 2C loc_14400:      isync
00014404 38 71 00 00                 addi      r3, r17, 0
00014408 38 93 00 00                 addi      r4, r19, 0
0001440C 4B FF E6 1D                 bl        cameraMessageMamiya 
00014410 89 40 20 8C                 lbz       r10, cameraWatch
00014414 2C 0A 00 00                 cmpwi     r10, 0
00014418 40 82 00 10                 bne       loc_14428
0001441C 89 80 21 B1                 lbz       r12, cameraLogWatch
00014420 2C 0C 00 00                 cmpwi     r12, 0
00014424 41 82 F7 B4                 beq       loc_13BD8
00014428 7D 9A CA 14 loc_14428:      add       r12, r26, r25
0001442C 38 AC 00 01                 addi      r5, r12, 1
00014430 38 DC 00 00                 addi      r6, r28, 0
00014434 38 61 00 08                 addi      r3, r1, 0xC0+var_B8
00014438 38 81 00 34                 addi      r4, r1, 0xC0+var_8C
0001443C 4B FF CE B1                 bl        cameraSpiLog 
00014440 4B FF F7 90                 b         loc_13BD0
00014444 B9 C1 00 78                 lmw       r14, 0xC0+var_48(r1)
00014448 80 01 00 C4                 lwz       r0, 0xC0+arg_4(r1)
0001444C 7C 08 03 A6                 mtlr      r0
00014450 38 21 00 C0                 addi      r1, r1, 0xC0
00014454 4E 80 00 20                 blr
00014458 00 00 00 00
0001445C 00 00 00 00
00014460 00 00 00 00
