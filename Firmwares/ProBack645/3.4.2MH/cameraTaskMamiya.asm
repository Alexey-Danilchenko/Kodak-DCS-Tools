cameraTaskMamiya
00013AF8 94 21 FF 40                 stwu      r1, -0xC0(r1)
00013AFC 7C 08 02 A6                 mflr      r0
00013B00 BD C1 00 78                 stmw      r14, 0xC0+var_48(r1)
00013B04 90 01 00 C4                 stw       r0, 0xC0+arg_4(r1)
00013B08 4B FF CF 8D                 bl        cameraRegisterSettings 
00013B0C 3C 60 00 01                 lis       r3, mamiyaProperties@h
00013B10 38 63 44 60                 addi      r3, r3, mamiyaProperties@l
00013B14 38 80 00 03                 li        r4, 3
00013B18 48 06 94 39                 bl        propertyRegister 
00013B1C 3C 80 00 01                 lis       r4, cameraMamiyaMainMenu@ha
00013B20 60 84 49 58                 ori       r4, r4, cameraMamiyaMainMenu@l
00013B24 38 60 00 28                 li        r3, MAIN_MENU_SHOW
00013B28 48 02 AB F9                 bl        eventHook 
00013B2C 4B FF D9 49                 bl        cameraPinSetup 
00013B30 3A C0 00 00                 li        r22, 0
00013B34 3B 60 00 00                 li        r27, 0
00013B38 3F E0 20 00 loc_13B38:      lis       r31, IMMR@h
00013B3C 3B FF 00 00                 addi      r31, r31, IMMR@l
00013B40 3A E0 7D 00 loc_13B40:      li        r23, 0x7D00
00013B44 81 80 21 AC                 lwz       r12, shutterMode
00013B48 2C 0C 00 00                 cmpwi     r12, 0
00013B4C 40 82 00 0C                 bne       loc_13B58
00013B50 3E E0 00 03                 lis       r23, loc_30D40@h
00013B54 62 F7 0D 40                 ori       r23, rTimeDelay, loc_30D40@l
00013B58 7C C0 00 A6 loc_13B58:      mfmsr     r6
00013B5C 7C 11 13 A6                 mtspr     eid, r0 # External interrupt disable
00013B60 4C 00 01 2C                 isync
00013B64 3C A0 00 01                 lis       r5, byte_8000@ha
00013B68 38 A5 80 00                 addi      r5, r5, byte_8000@l
00013B6C 7C C6 28 38                 and       r6, r6, r5
00013B70 7C 70 42 A6                 mfsprg0   r3
00013B74 54 63 08 3E                 rotlwi    r3, r3, 1     # r3 = (r3 << 1) | (r3 >> 31)
00013B78 7C 63 28 78                 andc      r3, r3, r5
00013B7C 7C 63 33 78                 or        r3, r3, r6
00013B80 7C 70 43 A6                 mtsprg0   r3
00013B84 81 9F 0A C4                 lwz       r12, (IMMR.PBDAT - IMMR)(r31)
00013B88 61 8C 00 01                 ori       r12, r12, 1
00013B8C 91 9F 0A C4                 stw       r12, (IMMR.PBDAT - IMMR)(r31)
00013B90 81 7F 0A C0                 lwz       r11, (IMMR.PBODR - IMMR)(r31)
00013B94 55 6B 00 3C                 clrrwi    r11, r11, 1   # r11 = r11 & 0xFFFFFFFE
00013B98 91 7F 0A C0                 stw       r11, (IMMR.PBODR - IMMR)(r31)
00013B9C 81 5F 0A B8                 lwz       r10, (IMMR.PBDIR - IMMR)(r31)
00013BA0 61 4A 00 01                 ori       r10, r10, 1
00013BA4 91 5F 0A B8                 stw       r10, (IMMR.PBDIR - IMMR)(r31)
00013BA8 81 9F 0A BC                 lwz       r12, (IMMR.PBPAR - IMMR)(r31)
00013BAC 55 8C 00 3C                 clrrwi    r12, r12, 1   # r12 = r12 & 0xFFFFFFFE
00013BB0 91 9F 0A BC                 stw       r12, (IMMR.PBPAR - IMMR)(r31)
00013BB4 7C 90 42 A6                 mfsprg0   r4
00013BB8 54 83 F8 3E                 rotrwi    r3, r4, 1     # r3 = (r4 << 31) | (r4 >> 1)
00013BBC 7C 70 43 A6                 mtsprg0   r3
00013BC0 70 84 80 00                 andi.     r4, r4, 0x8000
00013BC4 41 82 00 08                 beq       loc_13BCC
00013BC8 7C 10 13 A6                 mtspr     eie, r0 # External interrupt enable
00013BCC 4C 00 01 2C loc_13BCC:      isync
00013BD0 7C C0 00 A6 loc_13BD0:      mfmsr     r6
00013BD4 7C 11 13 A6                 mtspr     eid, r0 # External interrupt disable
00013BD8 4C 00 01 2C                 isync
00013BDC 3C A0 00 01                 lis       r5, byte_8000@ha
00013BE0 38 A5 80 00                 addi      r5, r5, byte_8000@l
00013BE4 7C C6 28 38 loc_13BE4:      and       r6, r6, r5
00013BE8 7C 70 42 A6                 mfsprg0   r3
00013BEC 54 63 08 3E                 rotlwi    r3, r3, 1     # r3 = (r3 << 1) | (r3 >> 31)
00013BF0 7C 63 28 78                 andc      r3, r3, r5
00013BF4 7C 63 33 78                 or        r3, r3, r6
00013BF8 7C 70 43 A6                 mtsprg0   r3
00013BFC A1 9F 09 60                 lhz       r12, (IMMR.PCDIR - IMMR)(r31)
00013C00 55 8C 06 2C                 rlwinm    r12, r12, 0,24,22 # r12 = r12 & 0xFFFFFEFF
00013C04 B1 9F 09 60                 sth       r12, (IMMR.PCDIR - IMMR)(r31)
00013C08 A1 7F 09 64                 lhz       r11, (IMMR.PCSO - IMMR)(r31)
00013C0C 55 6B 06 2C                 rlwinm    r11, r11, 0,24,22 # r11 = r11 & 0xFFFFFEFF
00013C10 B1 7F 09 64                 sth       r11, (IMMR.PCSO - IMMR)(r31)
00013C14 A1 5F 09 66                 lhz       r10, (IMMR.PCDAT - IMMR)(r31)
00013C18 55 4A 06 2C                 rlwinm    r10, r10, 0,24,22 # r10 = r10 & 0xFFFFFEFF
00013C1C B1 5F 09 66                 sth       r10, (IMMR.PCDAT - IMMR)(r31)
00013C20 A1 9F 09 62                 lhz       r12, (IMMR.PCPAR - IMMR)(r31)
00013C24 55 8C 06 2C                 rlwinm    r12, r12, 0,24,22 # r12 = r12 & 0xFFFFFEFF
00013C28 B1 9F 09 62                 sth       r12, (IMMR.PCPAR - IMMR)(r31)
00013C2C 7C 90 42 A6                 mfsprg0   r4
00013C30 54 83 F8 3E                 rotrwi    r3, r4, 1     # r3 = (r4 << 31) | (r4 >> 1)
00013C34 7C 70 43 A6                 mtsprg0   r3
00013C38 70 84 80 00                 andi.     r4, r4, 0x8000
00013C3C 41 82 00 08                 beq       loc_13C44
00013C40 7C 10 13 A6                 mtspr     eie, r0 # External interrupt enable
00013C44 4C 00 01 2C loc_13C44:      isync
00013C48 A1 7F 09 66                 lhz       r11, (IMMR.PCDAT - IMMR)(r31)
00013C4C 55 6B 05 EF                 rlwinm.   r11, r11, 0,23,23 # r11 = r11 & 0x100
00013C50 41 82 00 24                 beq       loc_13C74
00013C54 38 60 FF FF loc_13C54:      li        r3, -1
00013C58 38 80 00 01                 li        r4, 1
00013C5C 38 A0 03 E8                 li        r5, 0x3E8
00013C60 38 C0 00 00                 li        r6, 0
00013C64 48 06 54 B5                 bl        osEvPend 
00013C68 A1 9F 09 66                 lhz       r12, (IMMR.PCDAT - IMMR)(r31)
00013C6C 55 8C 05 EF                 rlwinm.   r12, r12, 0,23,23 # r12 = r12 & 0x100
00013C70 40 82 FF E4                 bne       loc_13C54
00013C74 A1 9F 09 66 loc_13C74:      lhz       r12, (IMMR.PCDAT - IMMR)(r31)
00013C78 55 8C 05 EF                 rlwinm.   r12, r12, 0,23,23 # r12 = r12 & 0x100
00013C7C 40 82 02 20                 bne       loc_13E9C
00013C80 89 80 21 E9 loc_13C80:      lbz       r12, camAwake
00013C84 2C 0C 00 00                 cmpwi     r12, 0
00013C88 40 82 00 34                 bne       loc_13CBC
00013C8C 89 80 21 E5                 lbz       r12, camSet
00013C90 2C 0C 00 00                 cmpwi     r12, 0
00013C94 40 82 00 28                 bne       loc_13CBC
00013C98 89 80 21 E6                 lbz       r12, camGet
00013C9C 2C 0C 00 00                 cmpwi     r12, 0
00013CA0 40 82 00 1C                 bne       loc_13CBC
00013CA4 89 80 21 48                 lbz       r12, takePicture
00013CA8 2C 0C 00 00                 cmpwi     r12, 0
00013CAC 40 82 00 10                 bne       loc_13CBC
00013CB0 89 80 22 28                 lbz       r12, cameraWake
00013CB4 2C 0C 00 00                 cmpwi     r12, 0
00013CB8 41 82 00 1C                 beq       loc_13CD4
00013CBC 38 60 FF FF loc_13CBC:      li        r3, -1
00013CC0 38 80 00 01                 li        r4, 1
00013CC4 38 A0 03 E8                 li        r5, 0x3E8
00013CC8 38 C0 00 00                 li        r6, 0
00013CCC 48 06 54 4D                 bl        osEvPend 
00013CD0 48 00 00 1C                 b         loc_13CEC
00013CD4 38 60 FF FF loc_13CD4:      li        r3, -1
00013CD8 38 80 00 01                 li        r4, 1
00013CDC 3C A0 00 4C                 lis       r5, 0x4C # 0x4C4B40 # 'L'
00013CE0 60 A5 4B 40                 ori       r5, r5, 0x4B40 # 0x4C4B40
00013CE4 38 C0 00 00                 li        r6, 0
00013CE8 48 06 54 31                 bl        osEvPend 
00013CEC 48 00 47 81 loc_13CEC:      bl        cameraDialogCheck 
00013CF0 38 7B 00 00                 addi      r3, r27, 0
00013CF4 4B FF F5 4D                 bl        cameraMessageSetupMamiya 
00013CF8 3B A3 00 00                 addi      r29, r3, 0
00013CFC 57 BD 06 3E                 clrlwi    r29, r29, 24  # r29 = r29 & 0xFF
00013D00 2C 1D 00 00                 cmpwi     r29, 0
00013D04 41 82 01 8C                 beq       loc_13E90
00013D08 89 80 21 E9                 lbz       r12, camAwake
00013D0C 2C 0C 00 00                 cmpwi     r12, 0
00013D10 40 82 00 20                 bne       loc_13D30
00013D14 48 08 5A 09                 bl        timeUsec 
00013D18 81 80 21 D0                 lwz       r12, bodySleepTime
00013D1C 7C 6C 18 50                 subf      r3, r12, r3
00013D20 3D 60 00 07                 lis       r11, loc_7A120@h
00013D24 61 6B A1 20                 ori       r11, r11, loc_7A120@l
00013D28 7C 03 58 40                 cmplw     r3, r11
00013D2C 41 81 00 10                 bgt       loc_13D3C
00013D30 81 80 21 E0 loc_13D30:      lwz       r12, backMessageCount
00013D34 28 0C 00 02                 cmplwi    r12, 2
00013D38 41 80 01 58                 blt       loc_13E90
00013D3C 48 08 59 E1 loc_13D3C:      bl        timeUsec 
00013D40 7C 76 18 50                 subf      r3, r22, r3
00013D44 7C 03 B8 40                 cmplw     r3, r23
00013D48 40 81 01 48                 ble       loc_13E90
00013D4C 89 80 21 EF                 lbz       r12, camReplyDelay
00013D50 2C 0C 00 00                 cmpwi     r12, 0
00013D54 41 82 00 18                 beq       loc_13D6C
00013D58 48 08 59 C5                 bl        timeUsec 
00013D5C 81 80 21 C4                 lwz       r12, lastMessageTime
00013D60 7C 6C 18 50                 subf      r3, r12, r3
00013D64 7C 03 B8 40                 cmplw     r3, r23
00013D68 40 81 01 28                 ble       loc_13E90
00013D6C 57 BD 06 3E loc_13D6C:      clrlwi    r29, r29, 24  # r29 = r29 & 0xFF
00013D70 38 BD 00 00                 addi      r5, r29, 0
00013D74 38 60 00 C7                 li        r3, 0xC7 # 'Ã'
00013D78 38 80 00 00                 li        r4, 0
00013D7C 48 02 9B FD                 bl        eventPost 
00013D80 3A 40 00 01                 li        r18, 1
00013D84 7C C0 00 A6                 mfmsr     r6
00013D88 7C 11 13 A6                 mtspr     eid, r0 # External interrupt disable
00013D8C 4C 00 01 2C                 isync
00013D90 3C A0 00 01                 lis       r5, byte_8000@ha
00013D94 38 A5 80 00                 addi      r5, r5, byte_8000@l
00013D98 7C C6 28 38                 and       r6, r6, r5
00013D9C 7C 70 42 A6                 mfsprg0   r3
00013DA0 54 63 08 3E                 rotlwi    r3, r3, 1     # r3 = (r3 << 1) | (r3 >> 31)
00013DA4 7C 63 28 78                 andc      r3, r3, r5
00013DA8 7C 63 33 78                 or        r3, r3, r6
00013DAC 7C 70 43 A6                 mtsprg0   r3
00013DB0 A1 3F 09 66                 lhz       r9, (IMMR.PCDAT - IMMR)(r31)
00013DB4 61 29 01 00                 ori       r9, r9, 0x100
00013DB8 B1 3F 09 66                 sth       r9, (IMMR.PCDAT - IMMR)(r31)
00013DBC A1 9F 09 64                 lhz       r12, (IMMR.PCSO - IMMR)(r31)
00013DC0 55 8C 06 2C                 rlwinm    r12, r12, 0,24,22 # r12 = r12 & 0xFFFFFEFF
00013DC4 B1 9F 09 64                 sth       r12, (IMMR.PCSO - IMMR)(r31)
00013DC8 A1 7F 09 60                 lhz       r11, (IMMR.PCDIR - IMMR)(r31)
00013DCC 61 6B 01 00                 ori       r11, r11, 0x100
00013DD0 B1 7F 09 60                 sth       r11, 0x960(r31)
00013DD4 A1 5F 09 62                 lhz       r10, 0x962(r31)
00013DD8 55 4A 06 2C                 rlwinm    r10, r10, 0,24,22 # r10 = r10 & 0xFFFFFEFF
00013DDC B1 5F 09 62                 sth       r10, 0x962(r31)
00013DE0 7C 90 42 A6                 mfsprg0   r4
00013DE4 54 83 F8 3E                 rotrwi    r3, r4, 1     # r3 = (r4 << 31) | (r4 >> 1)
00013DE8 7C 70 43 A6                 mtsprg0   r3
00013DEC 70 84 80 00                 andi.     r4, r4, 0x8000
00013DF0 41 82 00 08                 beq       loc_13DF8
00013DF4 7C 10 13 A6                 mtspr     eie, r0 # External interrupt enable
00013DF8 4C 00 01 2C loc_13DF8:      isync
00013DFC 38 60 0B B8                 li        r3, 0xBB8
00013E00 48 08 5A B9                 bl        waitUsec 
00013E04 7C C0 00 A6                 mfmsr     r6
00013E08 7C 11 13 A6                 mtspr     eid, r0 # External interrupt disable
00013E0C 4C 00 01 2C                 isync
00013E10 3C A0 00 01                 lis       r5, byte_8000@ha
00013E14 38 A5 80 00                 addi      r5, r5, byte_8000@l
00013E18 7C C6 28 38                 and       r6, r6, r5
00013E1C 7C 70 42 A6                 mfsprg0   r3
00013E20 54 63 08 3E                 rotlwi    r3, r3, 1     # r3 = (r3 << 1) | (r3 >> 31)
00013E24 7C 63 28 78                 andc      r3, r3, r5
00013E28 7C 63 33 78                 or        r3, r3, r6
00013E2C 7C 70 43 A6                 mtsprg0   r3
00013E30 A1 7F 09 60                 lhz       r11, 0x960(r31)
00013E34 55 6B 06 2C                 rlwinm    r11, r11, 0,24,22 # r11 = r11 & 0xFFFFFEFF
00013E38 B1 7F 09 60                 sth       r11, 0x960(r31)
00013E3C A1 5F 09 64                 lhz       r10, 0x964(r31)
00013E40 55 4A 06 2C                 rlwinm    r10, r10, 0,24,22 # r10 = r10 & 0xFFFFFEFF
00013E44 B1 5F 09 64                 sth       r10, 0x964(r31)
00013E48 A1 9F 09 66                 lhz       r12, 0x966(r31)
00013E4C 55 8C 06 2C                 rlwinm    r12, r12, 0,24,22 # r12 = r12 & 0xFFFFFEFF
00013E50 B1 9F 09 66                 sth       r12, 0x966(r31)
00013E54 A1 7F 09 62                 lhz       r11, 0x962(r31)
00013E58 55 6B 06 2C                 rlwinm    r11, r11, 0,24,22 # r11 = r11 & 0xFFFFFEFF
00013E5C B1 7F 09 62                 sth       r11, 0x962(r31)
00013E60 7C 90 42 A6                 mfsprg0   r4
00013E64 54 83 F8 3E                 rotrwi    r3, r4, 1     # r3 = (r4 << 31) | (r4 >> 1)
00013E68 7C 70 43 A6                 mtsprg0   r3
00013E6C 70 84 80 00                 andi.     r4, r4, 0x8000
00013E70 41 82 00 08                 beq       loc_13E78
00013E74 7C 10 13 A6                 mtspr     eie, r0 # External interrupt enable
00013E78 4C 00 01 2C loc_13E78:      isync
00013E7C 38 60 03 E8                 li        r3, 0x3E8
00013E80 48 08 5A 39                 bl        waitUsec 
00013E84 48 08 58 99                 bl        timeUsec 
00013E88 3A C3 00 00                 addi      r22, r3, 0
00013E8C 3B 7B 00 01                 addi      r27, r27, 1
00013E90 A1 9F 09 66 loc_13E90:      lhz       r12, 0x966(r31)
00013E94 55 8C 05 EF                 rlwinm.   r12, r12, 0,23,23 # r12 = r12 & 0x100
00013E98 41 82 FD E8                 beq       loc_13C80
00013E9C 81 9F 0A C4 loc_13E9C:      lwz       r12, 0xAC4(r31)
00013EA0 55 8C 07 7B                 rlwinm.   r12, r12, 0,29,29 # r12 = r12 & 4
00013EA4 41 82 FD 2C                 beq       loc_13BD0
00013EA8 48 08 58 75                 bl        timeUsec 
00013EAC 3A C3 00 00                 addi      r22, r3, 0
00013EB0 3B 60 00 00                 li        r27, 0
00013EB4 38 61 00 08                 addi      r3, r1, 0xC0+var_B8
00013EB8 38 80 00 00                 li        r4, 0
00013EBC 38 A0 00 2C                 li        r5, 0x2C # ','
00013EC0 48 09 74 35                 bl        memset 
00013EC4 38 61 00 34                 addi      r3, r1, 0xC0+var_8C
00013EC8 38 80 00 00                 li        r4, 0
00013ECC 38 A0 00 2C                 li        r5, 0x2C # ','
00013ED0 48 09 74 25                 bl        memset 
00013ED4 39 20 00 AA                 li        r9, 0xAA # '¬'
00013ED8 99 21 00 33                 stb       r9, 0xC0+var_8D(r1)
00013EDC 3B 80 00 00                 li        r28, 0
00013EE0 3B 40 00 00                 li        r26, 0
00013EE4 88 61 00 34                 lbz       r3, 0xC0+var_8C(r1)
00013EE8 38 97 00 00                 addi      r4, r23, 0
00013EEC 4B FF CD 75                 bl        cameraSpiGetPut 
00013EF0 3B 23 00 00                 addi      r25, r3, 0
00013EF4 9B 21 00 08                 stb       r25, 0xC0+var_B8(r1)
00013EF8 57 39 06 3E                 clrlwi    r25, r25, 24  # r25 = r25 & 0xFF
00013EFC 2C 19 00 7E                 cmpwi     r25, 0x7E
00013F00 40 82 00 B8                 bne       loc_13FB8
00013F04 3B 40 00 02                 li        r26, 2
00013F08 2C 12 00 00                 cmpwi     r18, 0
00013F0C 41 82 00 7C                 beq       loc_13F88
00013F10 7C C0 00 A6                 mfmsr     r6
00013F14 7C 11 13 A6                 mtspr     eid, r0 # External interrupt disable
00013F18 4C 00 01 2C                 isync
00013F1C 3C A0 00 01                 lis       r5, byte_8000@ha
00013F20 38 A5 80 00                 addi      r5, r5, byte_8000@l
00013F24 7C C6 28 38                 and       r6, r6, r5
00013F28 7C 70 42 A6                 mfsprg0   r3
00013F2C 54 63 08 3E                 rotlwi    r3, r3, 1     # r3 = (r3 << 1) | (r3 >> 31)
00013F30 7C 63 28 78                 andc      r3, r3, r5
00013F34 7C 63 33 78                 or        r3, r3, r6
00013F38 7C 70 43 A6                 mtsprg0   r3
00013F3C 81 7F 0A C4                 lwz       r11, 0xAC4(r31)
00013F40 55 6B 07 76                 rlwinm    r11, r11, 0,29,27 # r11 = r11 & 0xFFFFFFF7
00013F44 91 7F 0A C4                 stw       r11, 0xAC4(r31)
00013F48 81 5F 0A C0                 lwz       r10, 0xAC0(r31)
00013F4C 55 4A 07 76                 rlwinm    r10, r10, 0,29,27 # r10 = r10 & 0xFFFFFFF7
00013F50 91 5F 0A C0                 stw       r10, 0xAC0(r31)
00013F54 81 9F 0A B8                 lwz       r12, 0xAB8(r31)
00013F58 61 8C 00 08                 ori       r12, r12, 8
00013F5C 91 9F 0A B8                 stw       r12, 0xAB8(r31)
00013F60 81 7F 0A BC                 lwz       r11, 0xABC(r31)
00013F64 61 6B 00 08                 ori       r11, r11, 8
00013F68 91 7F 0A BC                 stw       r11, 0xABC(r31)
00013F6C 7C 90 42 A6                 mfsprg0   r4
00013F70 54 83 F8 3E                 rotrwi    r3, r4, 1     # r3 = (r4 << 31) | (r4 >> 1)
00013F74 7C 70 43 A6                 mtsprg0   r3
00013F78 70 84 80 00                 andi.     r4, r4, 0x8000
00013F7C 41 82 00 08                 beq       loc_13F84
00013F80 7C 10 13 A6                 mtspr     eie, r0 # External interrupt enable
00013F84 4C 00 01 2C loc_13F84:      isync
00013F88 39 80 00 01 loc_13F88:      li        r12, 1
00013F8C 99 81 00 35                 stb       r12, 0xC0+var_8C+1(r1)
00013F90 39 60 00 00                 li        r11, 0
00013F94 99 61 00 36                 stb       r11, 0xC0+var_8A(r1)
00013F98 38 60 00 01                 li        r3, 1
00013F9C 38 97 00 00                 addi      r4, r23, 0
00013FA0 4B FF CC C1                 bl        cameraSpiGetPut 
00013FA4 98 61 00 09                 stb       r3, 0xC0+var_B8+1(r1)
00013FA8 88 61 00 36                 lbz       r3, 0xC0+var_8A(r1)
00013FAC 38 97 00 00                 addi      r4, r23, 0
00013FB0 4B FF CC B1                 bl        cameraSpiGetPut 
00013FB4 98 61 00 0A                 stb       r3, 0xC0+var_B6(r1)
00013FB8 3A 40 00 00 loc_13FB8:      li        r18, 0
00013FBC 7D 61 D2 14                 add       r11, r1, r26
00013FC0 3A 2B 00 08                 addi      r17, r11, 8
00013FC4 7D 81 D2 14                 add       r12, r1, r26
00013FC8 3A 6C 00 34                 addi      r19, r12, 0x34
00013FCC 3A B1 FF FF                 addi      r21, r17, -1
00013FD0 89 51 00 00                 lbz       r10, 0(r17)
00013FD4 2C 0A 00 01                 cmpwi     r10, 1
00013FD8 40 82 00 80                 bne       loc_14058
00013FDC 3B 80 00 01                 li        r28, 1
00013FE0 7C C0 00 A6                 mfmsr     r6
00013FE4 7C 11 13 A6                 mtspr     eid, r0 # External interrupt disable
00013FE8 4C 00 01 2C                 isync
00013FEC 3C A0 00 01                 lis       r5, byte_8000@ha
00013FF0 38 A5 80 00                 addi      r5, r5, byte_8000@l
00013FF4 7C C6 28 38                 and       r6, r6, r5
00013FF8 7C 70 42 A6                 mfsprg0   r3
00013FFC 54 63 08 3E                 rotlwi    r3, r3, 1     # r3 = (r3 << 1) | (r3 >> 31)
00014000 7C 63 28 78                 andc      r3, r3, r5
00014004 7C 63 33 78                 or        r3, r3, r6
00014008 7C 70 43 A6                 mtsprg0   r3
0001400C 81 5F 0A C4                 lwz       r10, 0xAC4(r31)
00014010 55 4A 07 76                 rlwinm    r10, r10, 0,29,27 # r10 = r10 & 0xFFFFFFF7
00014014 91 5F 0A C4                 stw       r10, 0xAC4(r31)
00014018 81 9F 0A C0                 lwz       r12, 0xAC0(r31)
0001401C 55 8C 07 76                 rlwinm    r12, r12, 0,29,27 # r12 = r12 & 0xFFFFFFF7
00014020 91 9F 0A C0                 stw       r12, 0xAC0(r31)
00014024 81 7F 0A B8                 lwz       r11, 0xAB8(r31)
00014028 61 6B 00 08                 ori       r11, r11, 8
0001402C 91 7F 0A B8                 stw       r11, 0xAB8(r31)
00014030 81 5F 0A BC                 lwz       r10, 0xABC(r31)
00014034 61 4A 00 08                 ori       r10, r10, 8
00014038 91 5F 0A BC                 stw       r10, 0xABC(r31)
0001403C 7C 90 42 A6                 mfsprg0   r4
00014040 54 83 F8 3E                 rotrwi    r3, r4, 1     # r3 = (r4 << 31) | (r4 >> 1)
00014044 7C 70 43 A6                 mtsprg0   r3
00014048 70 84 80 00                 andi.     r4, r4, 0x8000
0001404C 41 82 00 08                 beq       loc_14054
00014050 7C 10 13 A6                 mtspr     eie, r0 # External interrupt enable
00014054 4C 00 01 2C loc_14054:      isync
00014058 3B 00 00 08 loc_14058:      li        r24, 8
0001405C 89 91 00 00                 lbz       r12, 0(r17)
00014060 2C 0C 00 7D                 cmpwi     r12, 0x7D
00014064 40 82 00 08                 bne       loc_1406C
00014068 3B 00 00 02                 li        r24, 2
0001406C 3A 00 00 00 loc_1406C:      li        r16, 0
00014070 3B 20 00 01                 li        r25, 1
00014074 39 F1 00 00                 addi      r15, r17, 0
00014078 39 D7 00 00                 addi      r14, r23, 0
0001407C 89 91 00 00 loc_1407C:      lbz       r12, 0(r17)
00014080 2C 0C 00 01                 cmpwi     r12, 1
00014084 41 82 00 10                 beq       loc_14094
00014088 39 80 00 00                 li        r12, 0
0001408C 7D 93 C9 AE                 stbx      r12, r19, r25
00014090 48 00 02 08                 b         loc_14298
00014094 7D 95 C8 AE loc_14094:      lbzx      r12, r21, r25
00014098 7D 93 C9 AE                 stbx      r12, r19, r25
0001409C 2C 19 00 02                 cmpwi     r25, 2
000140A0 40 82 00 40                 bne       loc_140E0
000140A4 81 80 21 AC                 lwz       r12, shutterMode
000140A8 2C 0C 00 00                 cmpwi     r12, 0
000140AC 40 82 00 28                 bne       loc_140D4
000140B0 81 80 21 E0                 lwz       r12, backMessageCount
000140B4 28 0C 00 02                 cmplwi    r12, 2
000140B8 41 80 00 1C                 blt       loc_140D4
000140BC 89 80 21 DD                 lbz       r12, digitalBody
000140C0 2C 0C 00 00                 cmpwi     r12, 0
000140C4 40 82 00 10                 bne       loc_140D4
000140C8 39 80 00 11 loc_140C8:      li        r12, 0x11
000140CC 7D 93 C9 AE                 stbx      r12, r19, r25
000140D0 48 00 01 B8                 b         loc_14288
000140D4 39 80 00 81 loc_140D4:      li        r12, 0x81 # 'ü'
000140D8 7D 93 C9 AE                 stbx      r12, r19, r25
000140DC 48 00 01 AC                 b         loc_14288
000140E0 2C 19 00 04 loc_140E0:      cmpwi     r25, 4
000140E4 40 82 01 7C                 bne       loc_14260
000140E8 89 91 00 03                 lbz       r12, 3(r17)
000140EC 3B 0C 00 08                 addi      r24, r12, 8
000140F0 88 B1 00 02                 lbz       r5, 2(r17)
000140F4 2C 05 00 03                 cmpwi     r5, 3
000140F8 40 82 01 10                 bne       loc_14208
000140FC 39 80 00 00                 li        r12, 0
00014100 99 80 21 EF                 stb       r12, camReplyDelay
00014104 81 80 21 AC                 lwz       r12, shutterMode
00014108 2C 0C 00 00                 cmpwi     r12, 0
0001410C 40 82 00 20                 bne       loc_1412C
00014110 89 60 21 DD                 lbz       r11, digitalBody
00014114 2C 0B 00 00                 cmpwi     r11, 0
00014118 40 82 00 14                 bne       loc_1412C
0001411C 3A A0 58 14                 li        r21, 0x5814
00014120 89 60 58 19                 lbz       r11, byte_5819
00014124 3B 0B 00 08                 addi      r24, r11, 8
00014128 48 00 00 D8                 b         loc_14200
0001412C 57 AC 06 F6 loc_1412C:      rlwinm    r12, r29, 0,27,27 # r12 = r29 & 0x10
00014130 2C 0C 00 00                 cmpwi     r12, 0
00014134 41 82 00 40                 beq       loc_14174
00014138 57 BD 07 34                 rlwinm    r29, r29, 0,28,26 # r29 = r29 & 0xFFFFFFEF
0001413C 38 C0 58 1B                 li        r6, msg03d
00014140 39 40 00 82                 li        r10, 0x82 # 'é'
00014144 99 46 00 03                 stb       r10, 3(r6)
00014148 3D 20 00 00                 lis       r9, command@h
0001414C 39 29 73 D8                 addi      r9, r9, command@l
00014150 57 BD 06 3E                 clrlwi    r29, r29, 24  # r29 = r29 & 0xFF
00014154 1D 9D 00 34                 mulli     r12, r29, 0x34
00014158 7D 29 60 AE                 lbzx      r9, r9, r12
0001415C 55 29 06 36                 rlwinm    r9, r9, 0,24,27 # r9 = r9 & 0xF0
00014160 99 26 00 04                 stb       r9, 4(r6)
00014164 3A A0 58 17                 li        r21, 0x5817
00014168 89 46 00 01                 lbz       r10, 1(r6)
0001416C 3B 0A 00 08                 addi      r24, r10, 8
00014170 48 00 00 90                 b         loc_14200
00014174 57 BD 06 3E loc_14174:      clrlwi    r29, r29, 24  # r29 = r29 & 0xFF
00014178 2C 1D 00 00                 cmpwi     r29, 0
0001417C 40 82 00 08                 bne       loc_14184
00014180 3B A0 00 01                 li        r29, 1
00014184 38 C0 58 1B loc_14184:      li        r6, msg03d
00014188 39 60 00 83                 li        r11, 0x83 # 'â'
0001418C 99 66 00 03                 stb       r11, 3(r6)
00014190 3C 60 00 00                 lis       r3, command@h
00014194 38 63 73 D8                 addi      r3, r3, command@l
00014198 57 BD 06 3E                 clrlwi    r29, r29, 24  # r29 = r29 & 0xFF
0001419C 1C 9D 00 34                 mulli     r4, r29, 0x34
000141A0 7F A3 20 AE                 lbzx      r29, r3, r4
000141A4 9B A6 00 04                 stb       r29, 4(r6)
000141A8 3A A0 58 17                 li        r21, 0x5817
000141AC 89 46 00 01                 lbz       r10, 1(r6)
000141B0 3B 0A 00 08                 addi      r24, r10, 8
000141B4 38 C0 58 29                 li        r6, msg83
000141B8 57 AB 07 7E                 clrlwi    r11, r29, 29  # r11 = r29 & 7
000141BC 39 6B 00 01                 addi      r11, r11, 1
000141C0 99 66 00 01                 stb       r11, 1(r6)
000141C4 9B A6 00 02                 stb       r29, 2(r6)
000141C8 38 C0 00 00                 li        r6, 0
000141CC 7D 83 22 14                 add       r12, r3, r4
000141D0 3B AC 00 18                 addi      r29, r12, 0x18
000141D4 85 9D 00 04 loc_141D4:      lwzu      r12, 4(r29)
000141D8 39 60 00 00                 li        r11, 0
000141DC 2C 0C 00 00                 cmpwi     r12, 0
000141E0 41 82 00 0C                 beq       loc_141EC
000141E4 81 7D 00 00                 lwz       r11, 0(r29)
000141E8 89 6B 00 00                 lbz       r11, 0(r11)
000141EC 39 80 58 2C loc_141EC:      li        r12, 0x582C
000141F0 7D 6C 31 AE                 stbx      r11, r12, r6
000141F4 38 C6 00 01                 addi      r6, r6, 1
000141F8 28 06 00 06                 cmplwi    r6, 6
000141FC 41 80 FF D8                 blt       loc_141D4
00014200 3B A0 00 00 loc_14200:      li        r29, 0
00014204 48 00 00 4C                 b         loc_14250
00014208 38 C0 00 00 loc_14208:      li        r6, 0
0001420C 81 60 58 34                 lwz       r11, messageList
00014210 2C 0B 00 00                 cmpwi     r11, 0
00014214 41 82 00 3C                 beq       loc_14250
00014218 38 80 58 34                 li        r4, messageList
0001421C 38 65 00 00                 addi      r3, r5, 0
00014220 80 A4 00 00 loc_14220:      lwz       r5, 0(r4)
00014224 89 65 00 00                 lbz       r11, 0(r5)
00014228 7C 0B 18 00                 cmpw      r11, r3
0001422C 40 82 00 14                 bne       loc_14240
00014230 3A A5 FF FC                 addi      r21, r5, -4
00014234 89 65 00 01                 lbz       r11, 1(r5)
00014238 3B 0B 00 08                 addi      r24, r11, 8
0001423C 48 00 00 14                 b         loc_14250
00014240 38 C6 00 01 loc_14240:      addi      r6, r6, 1
00014244 85 64 00 04                 lwzu      r11, 4(r4)
00014248 2C 0B 00 00                 cmpwi     r11, 0
0001424C 40 82 FF D4                 bne       loc_14220
00014250 28 18 00 2C loc_14250:      cmplwi    r24, 0x2C
00014254 40 81 00 34                 ble       loc_14288
00014258 3B 00 00 2C                 li        r24, 0x2C # ','
0001425C 48 00 00 2C                 b         loc_14288
00014260 39 99 00 02 loc_14260:      addi      r12, r25, 2
00014264 7C 0C C0 40                 cmplw     r12, r24
00014268 40 82 00 0C                 bne       loc_14274
0001426C 7E 13 C9 AE                 stbx      r16, r19, r25
00014270 48 00 00 18                 b         loc_14288
00014274 39 99 00 02 loc_14274:      addi      r12, r25, 2
00014278 7C 0C C0 40                 cmplw     r12, r24
0001427C 40 81 00 0C                 ble       loc_14288
00014280 39 80 00 00                 li        r12, 0
00014284 7D 93 C9 AE                 stbx      r12, r19, r25
00014288 28 19 00 02 loc_14288:      cmplwi    r25, 2
0001428C 41 80 00 0C                 blt       loc_14298
00014290 7D 93 C8 AE                 lbzx      r12, r19, r25
00014294 7E 10 62 78                 xor       r16, r16, r12
00014298 7C 73 C8 AE loc_14298:      lbzx      r3, r19, r25
0001429C 38 8E 00 00                 addi      r4, r14, 0
000142A0 4B FF C9 C1                 bl        cameraSpiGetPut 
000142A4 9C 6F 00 01                 stbu      r3, 1(r15)
000142A8 7C 19 C0 40                 cmplw     r25, r24
000142AC 40 80 00 28                 bge       loc_142D4
000142B0 89 8F 00 00                 lbz       r12, 0(r15)
000142B4 2C 0C 00 AA                 cmpwi     r12, 0xAA
000142B8 41 82 00 1C                 beq       loc_142D4
000142BC A1 9F 09 66                 lhz       r12, immr.PCDAT(r31)
000142C0 55 8C 05 EF                 rlwinm.   r12, r12, 0,23,23 # r12 = r12 & 0x100
000142C4 41 82 00 10                 beq       loc_142D4
000142C8 3B 39 00 01                 addi      r25, r25, 1
000142CC 7C 19 C0 40                 cmplw     r25, r24
000142D0 41 80 FD AC                 blt       loc_1407C
000142D4 89 8F 00 00 loc_142D4:      lbz       r12, 0(r15)
000142D8 2C 0C 00 AA                 cmpwi     r12, 0xAA
000142DC 40 82 00 18                 bne       loc_142F4
000142E0 89 8F FF FF                 lbz       r12, -1(r15)
000142E4 2C 0C 00 00                 cmpwi     r12, 0
000142E8 41 82 00 0C                 beq       loc_142F4
000142EC 39 80 00 01                 li        r12, 1
000142F0 99 80 22 2A                 stb       r12, mamiyaSerialV1
000142F4 7C C0 00 A6 loc_142F4:      mfmsr     r6
000142F8 7C 11 13 A6                 mtspr     eid, r0 # External interrupt disable
000142FC 4C 00 01 2C                 isync
00014300 3C A0 00 01                 lis       r5, byte_8000@ha
00014304 38 A5 80 00                 addi      r5, r5, byte_8000@l
00014308 7C C6 28 38                 and       r6, r6, r5
0001430C 7C 70 42 A6                 mfsprg0   r3
00014310 54 63 08 3E                 rotlwi    r3, r3, 1     # r3 = (r3 << 1) | (r3 >> 31)
00014314 7C 63 28 78                 andc      r3, r3, r5
00014318 7C 63 33 78                 or        r3, r3, r6
0001431C 7C 70 43 A6                 mtsprg0   r3
00014320 81 9F 0A B8                 lwz       r12, immr.PBDIR(r31)
00014324 55 8C 07 76                 rlwinm    r12, r12, 0,29,27 # r12 = r12 & 0xFFFFFFF7
00014328 91 9F 0A B8                 stw       r12, immr.PBDIR(r31)
0001432C 81 7F 0A C0                 lwz       r11, immr.PBODR(r31)
00014330 55 6B 07 76                 rlwinm    r11, r11, 0,29,27 # r11 = r11 & 0xFFFFFFF7
00014334 91 7F 0A C0                 stw       r11, immr.PBODR(r31)
00014338 81 5F 0A C4                 lwz       r10, immr.PBDAT(r31)
0001433C 55 4A 07 76                 rlwinm    r10, r10, 0,29,27 # r10 = r10 & 0xFFFFFFF7
00014340 91 5F 0A C4                 stw       r10, immr.PBDAT(r31)
00014344 81 9F 0A BC                 lwz       r12, immr.PBPAR(r31)
00014348 55 8C 07 76                 rlwinm    r12, r12, 0,29,27 # r12 = r12 & 0xFFFFFFF7
0001434C 91 9F 0A BC                 stw       r12, immr.PBPAR(r31)
00014350 7C 90 42 A6                 mfsprg0   r4
00014354 54 83 F8 3E                 rotrwi    r3, r4, 1     # r3 = (r4 << 31) | (r4 >> 1)
00014358 7C 70 43 A6                 mtsprg0   r3
0001435C 70 84 80 00                 andi.     r4, r4, 0x8000
00014360 41 82 00 08                 beq       loc_14368
00014364 7C 10 13 A6                 mtspr     eie, r0 # External interrupt enable
00014368 4C 00 01 2C loc_14368:      isync
0001436C 38 71 00 00                 addi      r3, r17, 0
00014370 38 93 00 00                 addi      r4, r19, 0
00014374 4B FF E6 B5                 bl        cameraMessageMamiya 
00014378 89 40 20 8C                 lbz       r10, cameraWatch
0001437C 2C 0A 00 00                 cmpwi     r10, 0
00014380 40 82 00 10                 bne       loc_14390
00014384 89 80 21 B1                 lbz       r12, cameraLogWatch
00014388 2C 0C 00 00                 cmpwi     r12, 0
0001438C 41 82 F7 B4                 beq       loc_13B40
00014390 7D 9A CA 14 loc_14390:      add       r12, r26, r25
00014394 38 AC 00 01                 addi      r5, r12, 1
00014398 38 DC 00 00                 addi      r6, r28, 0
0001439C 38 61 00 08                 addi      r3, r1, 0xC0+var_B8
000143A0 38 81 00 34                 addi      r4, r1, 0xC0+var_8C
000143A4 4B FF CF 49                 bl        cameraSpiLog 
000143A8 4B FF F7 90                 b         loc_13B38
000143AC B9 C1 00 78                 lmw       r14, 0xC0+var_48(r1)
000143B0 80 01 00 C4                 lwz       r0, 0xC0+arg_4(r1)
000143B4 7C 08 03 A6                 mtlr      r0
000143B8 38 21 00 C0                 addi      r1, r1, 0xC0
000143BC 4E 80 00 20                 blr
000143C0 00 00 00 00
000143C4 00 00 00 00
000143C8 00 00 00 00
