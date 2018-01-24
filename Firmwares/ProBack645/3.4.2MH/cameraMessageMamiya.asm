cameraMessageMamiya
00012A28 94 21 FF D8                 stwu      r1,
00012A2C 7C 08 02 A6                 mflr      r0
00012A30 93 A1 00 1C                 stw       r29, 0x28+var_C(r1)
00012A34 93 C1 00 20                 stw       r30, 0x28+var_8(r1)
00012A38 93 E1 00 24                 stw       r31, 0x28+var_4(r1)
00012A3C 90 01 00 2C                 stw       r0, 0x28+arg_4(r1)
00012A40 3B A3 00 00                 addi      r29, r3, 0
00012A44 3B E4 00 00                 addi      r31, r4, 0
00012A48 89 9D 00 00                 lbz       r12, 0(r29)
00012A4C 99 81 00 08                 stb       r12, 0x28+var_20(r1)
00012A50 89 7D 00 02                 lbz       r11, 2(r29)
00012A54 99 61 00 09                 stb       r11, 0x28+var_20+1(r1)
00012A58 89 5F 00 07                 lbz       r10, 7(r31)
00012A5C 99 41 00 0A                 stb       r10, 0x28+var_20+2(r1)
00012A60 89 3F 00 08                 lbz       r9, 8(r31)
00012A64 99 21 00 0B                 stb       r9, 0x28+var_20+3(r1)
00012A68 8B DD 00 02                 lbz       r30, 2(r29)
00012A6C 2C 1E 00 82                 cmpwi     r30, 0x82
00012A70 40 82 00 18                 bne       loc_12A88
00012A74 89 9D 00 04                 lbz       r12, 4(r29)
00012A78 99 81 00 0A                 stb       r12, 0x28+var_20+2(r1)
00012A7C 89 7D 00 05                 lbz       r11, 5(r29)
00012A80 99 61 00 0B                 stb       r11, 0x28+var_20+3(r1)
00012A84 48 00 00 38                 b         loc_12ABC
00012A88 2C 1E 00 83 loc_12A88:      cmpwi     r30, 0x83
00012A8C 40 82 00 18                 bne       loc_12AA4
00012A90 89 9F 00 06                 lbz       r12, 6(r31)
00012A94 99 81 00 0A                 stb       r12, 0x28+var_20+2(r1)
00012A98 89 7F 00 07                 lbz       r11, 7(r31)
00012A9C 99 61 00 0B                 stb       r11, 0x28+var_20+3(r1)
00012AA0 48 00 00 1C                 b         loc_12ABC
00012AA4 2C 1E 00 A2 loc_12AA4:      cmpwi     r30, 0xA2
00012AA8 40 82 00 14                 bne       loc_12ABC
00012AAC 89 9D 00 03                 lbz       r12, 3(r29)
00012AB0 99 81 00 0A                 stb       r12, 0x28+var_20+2(r1)
00012AB4 89 7D 00 04                 lbz       r11, 4(r29)
00012AB8 99 61 00 0B                 stb       r11, 0x28+var_20+3(r1)
00012ABC 80 A1 00 08 loc_12ABC:      lwz       r5, 0x28+var_20(r1)
00012AC0 38 60 00 C7                 li        r3, 0xC7 # 'Ã'
00012AC4 38 80 00 00                 li        r4, 0
00012AC8 48 02 AE B1                 bl        eventPost 
00012ACC 89 80 22 2A                 lbz       r12, mamiyaSerialV1
00012AD0 2C 0C 00 00                 cmpwi     r12, 0
00012AD4 40 82 00 10                 bne       loc_12AE4
00012AD8 81 80 21 AC                 lwz       r12, shutterMode
00012ADC 2C 0C 00 00                 cmpwi     r12, 0
00012AE0 41 82 00 44                 beq       loc_12B24
00012AE4 81 80 21 AC loc_12AE4:      lwz       r12, shutterMode
00012AE8 2C 0C 00 00                 cmpwi     r12, 0
00012AEC 41 82 00 14                 beq       loc_12B00
00012AF0 39 80 00 90                 li        r12, 0x90 # 'É'
00012AF4 99 80 22 16                 stb       r12, setEO
00012AF8 39 80 00 99                 li        r12, 0x99 # 'Ö'
00012AFC 99 80 22 2B                 stb       r12, setP1
00012B00 39 80 00 01 loc_12B00:      li        r12, 1
00012B04 99 80 21 DD                 stb       r12, digitalBody
00012B08 89 3D 00 00                 lbz       r9, 0(r29)
00012B0C 2C 09 00 02                 cmpwi     r9, 2
00012B10 41 82 00 0C                 beq       loc_12B1C
00012B14 2C 09 00 04                 cmpwi     r9, 4
00012B18 40 82 00 0C                 bne       loc_12B24
00012B1C 39 80 00 01 loc_12B1C:      li        r12, 1
00012B20 99 80 21 F3                 stb       r12, isFilmBody
00012B24 89 3D 00 00 loc_12B24:      lbz       r9, 0(r29)
00012B28 2C 09 00 00                 cmpwi     r9, 0
00012B2C 41 82 06 EC                 beq       loc_13218
00012B30 48 08 6B ED                 bl        timeUsec 
00012B34 90 60 21 C4                 stw       r3, lastMessageTime
00012B38 81 80 21 AC loc_12B38:      lwz       r12, shutterMode
00012B3C 2C 0C 00 00                 cmpwi     r12, 0
00012B40 40 82 00 40                 bne       loc_12B80
00012B44 89 80 21 DD                 lbz       r12, digitalBody
00012B48 2C 0C 00 00                 cmpwi     r12, 0
00012B4C 41 82 00 34                 beq       loc_12B80
00012B50 89 80 21 ED                 lbz       r12, camShutterOpen
00012B54 2C 0C 00 00                 cmpwi     r12, 0
00012B58 41 82 00 28                 beq       loc_12B80
00012B5C 48 00 4D 39                 bl        cameraShutterCloseCommon 
00012B60 38 60 00 06                 li        r3, SHUTTER_CLOSE # event SHUTTER_CLOSE
00012B64 38 80 00 00                 li        r4, 0
00012B68 38 A0 00 00                 li        r5, 0
00012B6C 48 02 AE 0D                 bl        eventPost 
00012B70 39 20 00 00                 li        r9, 0
00012B74 99 20 21 ED                 stb       r9, camShutterOpen
00012B78 48 08 6B A5                 bl        timeUsec 
00012B7C 90 60 20 A4                 stw       r3, shutterCloseTime
00012B80 8B DD 00 00 loc_12B80:      lbz       r30, 0(r29)
00012B84 2C 1E 00 01                 cmpwi     r30, 1
00012B88 40 82 04 88                 bne       loc_13010
00012B8C 81 80 21 E0                 lwz       r12, backMessageCount
00012B90 39 8C 00 01                 addi      r12, r12, 1
00012B94 91 80 21 E0                 stw       r12, backMessageCount
00012B98 8B DD 00 02                 lbz       r30, 2(r29)
00012B9C 2C 1E 00 81                 cmpwi     r30, 0x81
00012BA0 40 82 00 80                 bne       loc_12C20
00012BA4 48 00 57 B9                 bl        cameraWakeup 
00012BA8 89 80 21 EA                 lbz       r12, camEnable
00012BAC 99 80 21 EB                 stb       r12, camEnabled
00012BB0 48 08 6B 6D                 bl        timeUsec 
00012BB4 90 60 21 C8                 stw       r3, lastBackStatusTime
00012BB8 81 80 21 AC                 lwz       r12, shutterMode
00012BBC 2C 0C 00 00                 cmpwi     r12, 0
00012BC0 40 82 06 58                 bne       loc_13218
00012BC4 89 60 21 DD                 lbz       r11, digitalBody
00012BC8 2C 0B 00 00                 cmpwi     r11, 0
00012BCC 40 82 00 14                 bne       loc_12BE0
00012BD0 89 80 21 E8                 lbz       r12, camSoft
00012BD4 2C 0C 00 00                 cmpwi     r12, 0
00012BD8 40 82 00 08                 bne       loc_12BE0
00012BDC 4B FF FD A9                 bl        cameraSoftPress 
00012BE0 89 80 21 DD loc_12BE0:      lbz       r12, digitalBody
00012BE4 2C 0C 00 00                 cmpwi     r12, 0
00012BE8 40 82 06 30                 bne       loc_13218
00012BEC 89 80 21 ED                 lbz       r12, camShutterOpen
00012BF0 2C 0C 00 00                 cmpwi     r12, 0
00012BF4 41 82 06 24                 beq       loc_13218
00012BF8 48 00 4C 9D                 bl        cameraShutterCloseCommon 
00012BFC 38 60 00 06                 li        r3, 6
00012C00 38 80 00 00                 li        r4, 0
00012C04 38 A0 00 00                 li        r5, 0
00012C08 48 02 AD 71                 bl        eventPost 
00012C0C 39 20 00 00                 li        r9, 0
00012C10 99 20 21 ED                 stb       r9, camShutterOpen
00012C14 48 08 6B 09                 bl        timeUsec 
00012C18 90 60 20 A4                 stw       r3, shutterCloseTime
00012C1C 48 00 05 FC                 b         loc_13218
00012C20 2C 1E 00 82 loc_12C20:      cmpwi     r30, 0x82
00012C24 40 82 01 A4                 bne       loc_12DC8
00012C28 48 00 57 35                 bl        cameraWakeup 
00012C2C 39 80 00 01                 li        r12, 1
00012C30 99 80 21 DD                 stb       r12, digitalBody
00012C34 89 7D 00 04                 lbz       r11, 4(r29)
00012C38 55 6B 06 76                 rlwinm    r11, r11, 0,25,27
00012C3C 55 7E E7 3E                 extrwi    r30, r11, 4,24
00012C40 9B C0 21 F2                 stb       r30, camReply
00012C44 3B E0 00 00                 li        r31, 0
00012C48 3D 40 00 00                 lis       r10, command@h
00012C4C 39 4A 73 D8                 addi      r10, r10, command@l
00012C50 1D 3E 00 34                 mulli     r9, r30, 0x34
00012C54 7C AA 4A 14                 add       r5, r10, r9
00012C58 85 85 00 04 loc_12C58:      lwzu      r12, 4(r5)
00012C5C 2C 0C 00 00                 cmpwi     r12, 0
00012C60 41 82 00 14                 beq       loc_12C74
00012C64 81 85 00 00                 lwz       r12, 0(r5)
00012C68 7D 7D FA 14                 add       r11, r29, r31
00012C6C 89 6B 00 05                 lbz       r11, 5(r11)
00012C70 99 6C 00 00                 stb       r11, 0(r12)
00012C74 3B FF 00 01 loc_12C74:      addi      r31, r31, 1
00012C78 28 1F 00 06                 cmplwi    r31, 6
00012C7C 41 80 FF DC                 blt       loc_12C58
00012C80 2C 1E 00 01                 cmpwi     r30, 1
00012C84 40 82 00 1C                 bne       loc_12CA0
00012C88 89 80 22 1A                 lbz       r12, getST
00012C8C 2C 0C 00 05                 cmpwi     r12, 5
00012C90 40 82 00 EC                 bne       loc_12D7C
00012C94 39 80 00 00                 li        r12, 0
00012C98 99 80 21 DC                 stb       r12, camMainSwitchOn
00012C9C 48 00 00 E0                 b         loc_12D7C
00012CA0 2C 1E 00 02 loc_12CA0:      cmpwi     r30, 2
00012CA4 40 82 00 30                 bne       loc_12CD4
00012CA8 39 80 00 01                 li        r12, 1
00012CAC 99 80 21 DF                 stb       r12, camSettingsReceived
00012CB0 4B FF FC 31                 bl        cameraUpdateSettingsMamiyaDigital 
00012CB4 81 80 21 AC                 lwz       r12, shutterMode
00012CB8 2C 0C 00 00                 cmpwi     r12, 0
00012CBC 40 82 00 C0                 bne       loc_12D7C
00012CC0 4B FF D9 25                 bl        cameraDataComplete 
00012CC4 39 80 00 00                 li        r12, 0
00012CC8 99 80 21 EE                 stb       r12, camShutterOpenDigital
00012CCC 99 80 21 DF                 stb       r12, camSettingsReceived
00012CD0 48 00 00 AC                 b         loc_12D7C
00012CD4 2C 1E 00 03 loc_12CD4:      cmpwi     r30, 3
00012CD8 40 82 00 2C                 bne       loc_12D04
00012CDC 4B FF FC 05                 bl        cameraUpdateSettingsMamiyaDigital 
00012CE0 89 80 21 E5                 lbz       r12, camSet
00012CE4 2C 0C 00 00                 cmpwi     r12, 0
00012CE8 41 82 00 10                 beq       loc_12CF8
00012CEC 39 80 00 20                 li        r12, 0x20 # ' '
00012CF0 99 80 22 18                 stb       r12, setMD
00012CF4 48 00 00 88                 b         loc_12D7C
00012CF8 39 80 00 00 loc_12CF8:      li        r12, 0
00012CFC 99 80 22 18                 stb       r12, setMD
00012D00 48 00 00 7C                 b         loc_12D7C
00012D04 2C 1E 00 04 loc_12D04:      cmpwi     r30, 4
00012D08 41 82 00 74                 beq       loc_12D7C
00012D0C 2C 1E 00 05                 cmpwi     r30, 5
00012D10 40 82 00 6C                 bne       loc_12D7C
00012D14 89 80 22 22                 lbz       r12, getSU
00012D18 3D 60 00 0F                 lis       r11, unk_F4240@h
00012D1C 61 6B 42 40                 ori       r11, r11, unk_F4240@l
00012D20 7C 6C 59 D6                 mullw     r3, r12, r11
00012D24 90 60 21 BC                 stw       r3, exposureTime
00012D28 3B E0 00 00                 li        r31, 0
00012D2C 89 20 22 23                 lbz       r9, getSL
00012D30 55 24 06 7E                 clrlwi    r4, r9, 25
00012D34 2C 04 00 00                 cmpwi     r4, 0
00012D38 41 82 00 44                 beq       loc_12D7C
00012D3C 38 C3 00 00                 addi      r6, r3, 0
00012D40 3B A0 00 0A                 li        r29, 0xA
00012D44 38 A4 00 00                 addi      r5, r4, 0
00012D48 21 64 00 00                 subfic    r11, r4, 0
00012D4C 55 6B 07 FF                 clrlwi.   r11, r11, 31
00012D50 41 82 00 14                 beq       loc_12D64
00012D54 7C C3 EB 96                 divwu     r6, r3, r29
00012D58 3B E0 00 01                 li        r31, 1
00012D5C 28 04 00 01                 cmplwi    r4, 1
00012D60 40 81 00 18                 ble       loc_12D78
00012D64 7C C6 EB 96 loc_12D64:      divwu     r6, r6, r29
00012D68 7C C6 EB 96                 divwu     r6, r6, r29
00012D6C 3B FF 00 02                 addi      r31, r31, 2
00012D70 7C 1F 28 40                 cmplw     r31, r5
00012D74 41 80 FF F0                 blt       loc_12D64
00012D78 90 C0 21 BC loc_12D78:      stw       r6, exposureTime
00012D7C 81 80 21 AC loc_12D7C:      lwz       r12, shutterMode
00012D80 2C 0C 00 01                 cmpwi     r12, 1
00012D84 41 82 04 94                 beq       loc_13218
00012D88 89 80 21 E8                 lbz       r12, camSoft
00012D8C 2C 0C 00 00                 cmpwi     r12, 0
00012D90 40 82 04 88                 bne       loc_13218
00012D94 2C 1E 00 01                 cmpwi     r30, 1
00012D98 40 82 00 14                 bne       loc_12DAC
00012D9C 89 80 22 1A                 lbz       r12, getST
00012DA0 55 8C 07 7A                 rlwinm    r12, r12, 0,29,29
00012DA4 2C 0C 00 00                 cmpwi     r12, 0
00012DA8 40 82 04 70                 bne       loc_13218
00012DAC 4B FF FB D9 loc_12DAC:      bl        cameraSoftPress 
00012DB0 81 80 21 AC                 lwz       r12, shutterMode
00012DB4 2C 0C 00 00                 cmpwi     r12, 0
00012DB8 40 82 04 60                 bne       loc_13218
00012DBC 39 80 00 01                 li        r12, 1
00012DC0 99 80 21 EF                 stb       r12, camReplyDelay
00012DC4 48 00 04 54                 b         loc_13218
00012DC8 2C 1E 00 83 loc_12DC8:      cmpwi     r30, 0x83
00012DCC 40 82 01 4C                 bne       loc_12F18
00012DD0 89 9F 00 06                 lbz       r12, 6(r31)
00012DD4 55 8C 06 76                 rlwinm    r12, r12, 0,25,27
00012DD8 55 9E E7 3E                 extrwi    r30, r12, 4,24
00012DDC 2C 1E 00 01                 cmpwi     r30, 1
00012DE0 40 82 00 10                 bne       loc_12DF0
00012DE4 89 80 21 EA                 lbz       r12, camEnable
00012DE8 99 80 21 EB                 stb       r12, camEnabled
00012DEC 48 00 01 20                 b         loc_12F0C
00012DF0 2C 1E 00 02 loc_12DF0:      cmpwi     r30, 2
00012DF4 40 82 00 30                 bne       loc_12E24
00012DF8 81 80 21 AC                 lwz       r12, shutterMode
00012DFC 2C 0C 00 00                 cmpwi     r12, 0
00012E00 41 82 01 0C                 beq       loc_12F0C
00012E04 89 80 21 DF                 lbz       r12, camSettingsReceived
00012E08 2C 0C 00 00                 cmpwi     r12, 0
00012E0C 41 82 01 00                 beq       loc_12F0C
00012E10 4B FF D7 D5                 bl        cameraDataComplete 
00012E14 39 80 00 00                 li        r12, 0
00012E18 99 80 21 EE                 stb       r12, camShutterOpenDigital
00012E1C 99 80 21 DF                 stb       r12, camSettingsReceived
00012E20 48 00 00 EC                 b         loc_12F0C
00012E24 2C 1E 00 03 loc_12E24:      cmpwi     r30, 3
00012E28 40 82 00 14                 bne       loc_12E3C
00012E2C 3B E0 00 00                 li        r31, 0
00012E30 9B E0 21 E6                 stb       r31, camGet
00012E34 9B E0 21 E5                 stb       r31, camSet
00012E38 48 00 00 D4                 b         loc_12F0C
00012E3C 2C 1E 00 04 loc_12E3C:      cmpwi     r30, 4
00012E40 40 82 00 88                 bne       loc_12EC8
00012E44 8B C0 21 EA                 lbz       r30, camEnable
00012E48 9B C0 21 EB                 stb       r30, camEnabled
00012E4C 8B E0 21 E8                 lbz       r31, camSoft
00012E50 2C 1F 00 00                 cmpwi     r31, 0
00012E54 41 82 00 28                 beq       loc_12E7C
00012E58 57 DE 06 3E                 clrlwi    r30, r30, 24
00012E5C 2C 1E 00 00                 cmpwi     r30, 0
00012E60 41 82 00 1C                 beq       loc_12E7C
00012E64 89 80 22 19                 lbz       r12, setRE
00012E68 55 8C 07 BE                 clrlwi    r12, r12, 30
00012E6C 2C 0C 00 03                 cmpwi     r12, 3
00012E70 40 82 00 0C                 bne       loc_12E7C
00012E74 39 80 00 01                 li        r12, 1
00012E78 99 80 21 F0                 stb       r12, camTakeRequested
00012E7C 2C 1F 00 00 loc_12E7C:      cmpwi     r31, 0
00012E80 40 82 00 18                 bne       loc_12E98
00012E84 89 80 22 19                 lbz       r12, setRE
00012E88 55 8C 07 FE                 clrlwi    r12, r12, 31
00012E8C 2C 0C 00 00                 cmpwi     r12, 0
00012E90 41 82 00 08                 beq       loc_12E98
00012E94 4B FF FA F1                 bl        cameraSoftPress 
00012E98 89 80 21 E7 loc_12E98:      lbz       r12, camClearRequest
00012E9C 2C 0C 00 00                 cmpwi     r12, 0
00012EA0 41 82 00 1C                 beq       loc_12EBC
00012EA4 89 80 22 19                 lbz       r12, setRE
00012EA8 55 8C 07 BE                 clrlwi    r12, r12, 30
00012EAC 2C 0C 00 00                 cmpwi     r12, 0
00012EB0 40 82 00 0C                 bne       loc_12EBC
00012EB4 39 80 00 00                 li        r12, 0
00012EB8 99 80 21 E7                 stb       r12, camClearRequest
00012EBC 48 08 68 61 loc_12EBC:      bl        timeUsec 
00012EC0 90 60 21 CC                 stw       r3, releaseMessageTime
00012EC4 48 00 00 48                 b         loc_12F0C
00012EC8 2C 1E 00 05 loc_12EC8:      cmpwi     r30, 5
00012ECC 40 82 00 40                 bne       loc_12F0C
00012ED0 81 80 21 AC                 lwz       r12, shutterMode
00012ED4 2C 0C 00 00                 cmpwi     r12, 0
00012ED8 40 82 00 34                 bne       loc_12F0C
00012EDC 89 80 21 EC                 lbz       r12, camShutterArm
00012EE0 2C 0C 00 00                 cmpwi     r12, 0
00012EE4 40 82 00 28                 bne       loc_12F0C
00012EE8 39 80 00 01                 li        r12, 1
00012EEC 99 80 21 EC                 stb       r12, camShutterArm
00012EF0 3B E0 00 00                 li        r31, 0
00012EF4 9B E0 21 ED                 stb       r31, camShutterOpen
00012EF8 9B E0 21 EE                 stb       r31, camShutterOpenDigital
00012EFC 38 60 00 04                 li        r3, SHUTTER_WARNING # event SHUTTER_WARNING
00012F00 38 80 00 00                 li        r4, 0
00012F04 38 A0 00 00                 li        r5, 0
00012F08 48 02 AA 71                 bl        eventPost 
00012F0C 39 80 00 00 loc_12F0C:      li        r12, 0
00012F10 99 80 21 F2                 stb       r12, camReply
00012F14 48 00 03 04                 b         loc_13218
00012F18 2C 1E 00 84 loc_12F18:      cmpwi     r30, 0x84
00012F1C 40 82 00 B4                 bne       loc_12FD0
00012F20 81 80 21 AC                 lwz       r12, shutterMode
00012F24 2C 0C 00 01                 cmpwi     r12, 1
00012F28 40 82 00 1C                 bne       loc_12F44
00012F2C 38 60 00 00                 li        r3, 0
00012F30 90 60 20 A0                 stw       r3, shutterOpenTime
00012F34 90 60 20 A4                 stw       r3, shutterCloseTime
00012F38 3B C0 00 01                 li        r30, 1
00012F3C 9B C0 21 ED                 stb       r30, camShutterOpen
00012F40 48 00 02 D8                 b         loc_13218
00012F44 89 80 21 EC loc_12F44:      lbz       r12, camShutterArm
00012F48 2C 0C 00 00                 cmpwi     r12, 0
00012F4C 40 82 00 30                 bne       loc_12F7C
00012F50 39 80 00 01                 li        r12, 1
00012F54 99 80 21 EC                 stb       r12, camShutterArm
00012F58 3B E0 00 00                 li        r31, 0
00012F5C 9B E0 21 ED                 stb       r31, camShutterOpen
00012F60 9B E0 21 EE                 stb       r31, camShutterOpenDigital
00012F64 38 60 00 04                 li        r3, 4
00012F68 38 80 00 00                 li        r4, 0
00012F6C 38 A0 00 00                 li        r5, 0
00012F70 48 02 AA 09                 bl        eventPost 
00012F74 38 60 1B 58                 li        r3, 0x1B58
00012F78 48 08 69 41                 bl        waitUsec 
00012F7C 38 60 00 00 loc_12F7C:      li        r3, 0
00012F80 90 60 20 A0                 stw       r3, shutterOpenTime
00012F84 90 60 20 A4                 stw       r3, shutterCloseTime
00012F88 98 60 21 EC                 stb       r3, camShutterArm
00012F8C 98 60 21 F0                 stb       r3, camTakeRequested
00012F90 98 60 21 48                 stb       r3, takePicture
00012F94 81 80 21 AC                 lwz       r12, shutterMode
00012F98 2C 0C 00 00                 cmpwi     r12, 0
00012F9C 40 82 00 0C                 bne       loc_12FA8
00012FA0 48 08 67 7D                 bl        timeUsec 
00012FA4 90 60 20 A0                 stw       r3, shutterOpenTime
00012FA8 3B C0 00 01 loc_12FA8:      li        r30, 1
00012FAC 9B C0 21 ED                 stb       r30, camShutterOpen
00012FB0 9B C0 21 EE                 stb       r30, camShutterOpenDigital
00012FB4 9B C0 20 99                 stb       r30, takePictureDone
00012FB8 48 00 48 09                 bl        cameraShutterOpenCommon 
00012FBC 38 60 00 05                 li        r3, 5
00012FC0 38 80 00 00                 li        r4, 0
00012FC4 38 A0 00 00                 li        r5, 0
00012FC8 48 02 A9 B1                 bl        eventPost 
00012FCC 48 00 02 4C                 b         loc_13218
00012FD0 81 80 21 AC loc_12FD0:      lwz       r12, shutterMode
00012FD4 2C 0C 00 00                 cmpwi     r12, 0
00012FD8 40 82 02 40                 bne       loc_13218
00012FDC 2C 1E 00 A3                 cmpwi     r30, 0xA3
00012FE0 40 82 00 14                 bne       loc_12FF4
00012FE4 38 7D 00 00                 addi      r3, r29, 0
00012FE8 4B FF F7 39                 bl        cameraUpdateSettingsMamiyaFilm 
00012FEC 4B FF D5 F9                 bl        cameraDataComplete 
00012FF0 48 00 02 28                 b         loc_13218
00012FF4 2C 1E 00 A7 loc_12FF4:      cmpwi     r30, 0xA7
00012FF8 41 82 02 20                 beq       loc_13218
00012FFC 2C 1E 00 A8                 cmpwi     r30, 0xA8
00013000 40 82 02 18                 bne       loc_13218
00013004 39 80 00 00                 li        r12, 0
00013008 99 80 21 DC                 stb       r12, camMainSwitchOn
0001300C 48 00 02 0C                 b         loc_13218
00013010 2C 1E 00 02 loc_13010:      cmpwi     r30, 2
00013014 40 82 01 38                 bne       loc_1314C
00013018 81 80 21 AC                 lwz       r12, shutterMode
0001301C 2C 0C 00 00                 cmpwi     r12, 0
00013020 40 82 01 2C                 bne       loc_1314C
00013024 8B FD 00 02                 lbz       r31, 2(r29)
00013028 2C 1F 00 03                 cmpwi     r31, 3
0001302C 40 82 00 50                 bne       loc_1307C
00013030 89 80 21 DD                 lbz       r12, digitalBody
00013034 2C 0C 00 00                 cmpwi     r12, 0
00013038 40 82 01 E0                 bne       loc_13218
0001303C 89 80 21 EC                 lbz       r12, camShutterArm
00013040 2C 0C 00 00                 cmpwi     r12, 0
00013044 41 82 01 D4                 beq       loc_13218
00013048 3B C0 00 01                 li        r30, 1
0001304C 9B C0 21 ED                 stb       r30, camShutterOpen
00013050 3B E0 00 00                 li        r31, 0
00013054 9B E0 21 EC                 stb       r31, camShutterArm
00013058 9B E0 21 F0                 stb       r31, camTakeRequested
0001305C 9B E0 21 48                 stb       r31, takePicture
00013060 9B C0 20 99                 stb       r30, takePictureDone
00013064 48 00 47 5D                 bl        cameraShutterOpenCommon 
00013068 38 60 00 05                 li        r3, 5
0001306C 38 80 00 00                 li        r4, 0
00013070 38 A0 00 00                 li        r5, 0
00013074 48 02 A9 05                 bl        eventPost 
00013078 48 00 01 A0                 b         loc_13218
0001307C 2C 1F 00 81 loc_1307C:      cmpwi     r31, 0x81
00013080 40 82 00 0C                 bne       loc_1308C
00013084 48 00 52 D9                 bl        cameraWakeup 
00013088 48 00 01 90                 b         loc_13218
0001308C 2C 1F 00 A0 loc_1308C:      cmpwi     r31, 0xA0
00013090 40 82 00 48                 bne       loc_130D8
00013094 89 80 21 EC                 lbz       r12, camShutterArm
00013098 2C 0C 00 00                 cmpwi     r12, 0
0001309C 40 82 00 1C                 bne       loc_130B8
000130A0 89 80 21 DD                 lbz       r12, digitalBody
000130A4 2C 0C 00 00                 cmpwi     r12, 0
000130A8 40 82 01 70                 bne       loc_13218
000130AC 89 80 21 ED                 lbz       r12, camShutterOpen
000130B0 2C 0C 00 00                 cmpwi     r12, 0
000130B4 41 82 01 64                 beq       loc_13218
000130B8 38 60 00 08 loc_130B8:      li        r3, 8
000130BC 38 80 00 00                 li        r4, 0
000130C0 38 A0 00 00                 li        r5, 0
000130C4 48 02 A8 B5                 bl        eventPost 
000130C8 3B E0 00 00                 li        r31, 0
000130CC 9B E0 21 ED                 stb       r31, camShutterOpen
000130D0 9B E0 21 EC                 stb       r31, camShutterArm
000130D4 48 00 01 44                 b         loc_13218
000130D8 2C 1F 00 A2 loc_130D8:      cmpwi     r31, 0xA2
000130DC 40 82 01 3C                 bne       loc_13218
000130E0 89 80 21 EB                 lbz       r12, camEnabled
000130E4 2C 0C 00 00                 cmpwi     r12, 0
000130E8 41 82 01 30                 beq       loc_13218
000130EC 89 80 21 E8                 lbz       r12, camSoft
000130F0 2C 0C 00 00                 cmpwi     r12, 0
000130F4 41 82 01 24                 beq       loc_13218
000130F8 89 80 21 EC                 lbz       r12, camShutterArm
000130FC 2C 0C 00 00                 cmpwi     r12, 0
00013100 40 82 01 18                 bne       loc_13218
00013104 89 80 21 EE                 lbz       r12, camShutterOpenDigital
00013108 2C 0C 00 00                 cmpwi     r12, 0
0001310C 40 82 01 0C                 bne       loc_13218
00013110 89 80 21 DD                 lbz       r12, digitalBody
00013114 2C 0C 00 00                 cmpwi     r12, 0
00013118 41 82 00 10                 beq       loc_13128
0001311C 81 80 21 E0                 lwz       r12, backMessageCount
00013120 28 0C 00 04                 cmplwi    r12, 4
00013124 40 81 00 F4                 ble       loc_13218
00013128 39 80 00 01 loc_13128:      li        r12, 1
0001312C 99 80 21 EC                 stb       r12, camShutterArm
00013130 39 60 00 00                 li        r11, 0
00013134 99 60 21 ED                 stb       r11, camShutterOpen
00013138 38 60 00 04                 li        r3, 4
0001313C 38 80 00 00                 li        r4, 0
00013140 38 A0 00 00                 li        r5, 0
00013144 48 02 A8 35                 bl        eventPost 
00013148 48 00 00 D0                 b         loc_13218
0001314C 2C 1E 00 7D loc_1314C:      cmpwi     r30, 0x7D
00013150 40 82 00 C8                 bne       loc_13218
00013154 89 9D 00 01                 lbz       r12, 1(r29)
00013158 2C 0C 00 82                 cmpwi     r12, 0x82
0001315C 40 82 00 34                 bne       loc_13190
00013160 48 00 51 FD                 bl        cameraWakeup 
00013164 39 80 00 01                 li        r12, 1
00013168 99 80 22 2A                 stb       r12, mamiyaSerialV1
0001316C 99 80 21 DD                 stb       r12, digitalBody
00013170 81 80 21 AC                 lwz       r12, shutterMode
00013174 2C 0C 00 00                 cmpwi     r12, 0
00013178 41 82 00 A0                 beq       loc_13218
0001317C 39 80 00 90                 li        r12, 0x90 # 'É'
00013180 99 80 22 16                 stb       r12, setEO
00013184 39 80 00 99                 li        r12, 0x99 # 'Ö'
00013188 99 80 22 2B                 stb       r12, setP1
0001318C 48 00 00 8C                 b         loc_13218
00013190 48 08 65 8D loc_13190:      bl        timeUsec 
00013194 90 60 21 D0                 stw       r3, bodySleepTime
00013198 89 80 21 E8                 lbz       r12, camSoft
0001319C 2C 0C 00 00                 cmpwi     r12, 0
000131A0 41 82 00 30                 beq       loc_131D0
000131A4 39 80 00 00                 li        r12, 0
000131A8 99 80 21 E8                 stb       r12, camSoft
000131AC 38 60 00 0A                 li        r3, 0xA
000131B0 38 80 00 00                 li        r4, 0
000131B4 38 A0 00 00                 li        r5, 0
000131B8 48 02 A7 C1                 bl        eventPost 
000131BC 48 04 E4 BD                 bl        imageSafeSet 
000131C0 38 60 00 03                 li        r3, 3
000131C4 38 80 00 00                 li        r4,
000131C8 38 A0 00 00                 li        r5, 0
000131CC 48 02 A7 AD                 bl        eventPost 
000131D0 89 80 21 DC loc_131D0:      lbz       r12, camMainSwitchOn
000131D4 2C 0C 00 00                 cmpwi     r12, 0
000131D8 41 82 00 10                 beq       loc_131E8
000131DC 81 80 21 AC                 lwz       r12, shutterMode
000131E0 2C 0C 00 00                 cmpwi     r12, 0
000131E4 40 82 00 34                 bne       loc_13218
000131E8 3B E0 00 00 loc_131E8:      li        r31, 0
000131EC 9B E0 21 E9                 stb       r31, camAwake
000131F0 9B E0 21 DD                 stb       r31, digitalBody
000131F4 93 E0 21 E0                 stw       r31, backMessageCount
000131F8 93 E0 21 BC                 stw       r31, exposureTime
000131FC 89 80 21 DC                 lbz       r12, camMainSwitchOn
00013200 2C 0C 00 00                 cmpwi     r12, 0
00013204 40 82 00 14                 bne       loc_13218
00013208 38 60 00 0E                 li        r3, 0xE
0001320C 38 80 00 00                 li        r4, 0
00013210 38 A0 00 00                 li        r5, 0
00013214 48 02 A7 65                 bl        eventPost 
00013218 83 A1 00 1C loc_13218:      lwz       r29, 0x28+var_C(r1)
0001321C 83 C1 00 20                 lwz       r30, 0x28+var_8(r1)
00013220 83 E1 00 24                 lwz       r31, 0x28+var_4(r1)
00013224 80 01 00 2C                 lwz       r0, 0x28+arg_4(r1)
00013228 7C 08 03 A6                 mtlr      r0
0001322C 38 21 00 28                 addi      r1, r1, 0x28
00013230 4E 80 00 20                 blr
00013234 00 00 00 00
00013238 00 00 00 00
0001323C 00 00 00 00
