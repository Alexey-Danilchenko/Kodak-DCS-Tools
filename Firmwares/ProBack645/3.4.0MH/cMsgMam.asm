cameraMessageMamiya:
00012A28-566C=D3BC

00012A28 94 21 FF D8                 stwu      r1, -0x28(r1)
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
00012A70 40 82 00 18                 bne       loc_12A88-12A70
00012A74 89 9D 00 04                 lbz       r12, 4(r29)
00012A78 99 81 00 0A                 stb       r12, 0x28+var_20+2(r1)
00012A7C 89 7D 00 05                 lbz       r11, 5(r29)
00012A80 99 61 00 0B                 stb       r11, 0x28+var_20+3(r1)
00012A84 48 00 00 38                 b         loc_12ABC-12A84
00012A88 2C 1E 00 83 loc_12A88:      cmpwi     r30, 0x83
00012A8C 40 82 00 18                 bne       loc_12AA4-12A8C
00012A90 89 9F 00 06                 lbz       r12, 6(r31)
00012A94 99 81 00 0A                 stb       r12, 0x28+var_20+2(r1)
00012A98 89 7F 00 07                 lbz       r11, 7(r31)
00012A9C 99 61 00 0B                 stb       r11, 0x28+var_20+3(r1)
00012AA0 48 00 00 1C                 b         loc_12ABC-12AA0
00012AA4 2C 1E 00 A2 loc_12AA4:      cmpwi     r30, 0xA2
00012AA8 40 82 00 14                 bne       loc_12ABC-12AA8
00012AAC 89 9D 00 03                 lbz       r12, 3(r29)
00012AB0 99 81 00 0A                 stb       r12, 0x28+var_20+2(r1)
00012AB4 89 7D 00 04                 lbz       r11, 4(r29)
00012AB8 99 61 00 0B                 stb       r11, 0x28+var_20+3(r1)
00012ABC 80 A1 00 08 loc_12ABC:      lwz       r5, 0x28+var_20(r1)
00012AC0 38 60 00 C7                 li        r3, INFO_EVENT
00012AC4 38 80 00 00                 li        r4, 0
00012AC8 48 02 AE B1                 bl        eventPost ; 3D978-00012AC8
00012ACC 89 80 22 2A loc_12ACC:      lbz       r12, mamiyaSerialV1
00012AD0 2C 0C 00 00                 cmpwi     r12, 0
00012AD4 41 82 00 38                 beq       loc_12B0C-12AD4
00012AD8 39 80 00 90                 li        r12, 0x90
00012ADC 99 80 22 16                 stb       r12, setEO
00012AE0 39 80 00 99                 li        r12, 0x99
00012AE4 99 80 22 2B                 stb       r12, setP1
00012AE8 39 80 00 01                 li        r12, 1
00012AEC 99 80 21 DD                 stb       r12, digitalBody
00012AF0 89 3D 00 00                 lbz       r9, 0(r29)
00012AF4 2C 09 00 02                 cmpwi     r9, 2
00012AF8 41 82 00 0C                 beq       loc_12B04-12AF8
00012AFC 2C 09 00 04                 cmpwi     r9, 4
00012B00 40 82 00 0C                 bne       loc_12B0C-12B00
00012B04 39 80 00 01 loc_12B04:      li        r12, 1
00012B08 99 80 21 F3                 stb       r12, isFilmBody
00012B0C 89 3D 00 00 loc_12B0C:      lbz       r9, 0(r29)
00012B10 2C 09 00 00                 cmpwi     r9, 0
00012B14 41 82 05 E4                 beq       loc_130F8-12B14
00012B18 89 80 21 DD                 lbz       r12, digitalBody
00012B1C 2C 0C 00 00                 cmpwi     r12, 0
00012B20 41 82 00 34                 beq       loc_12B54-12B20
00012B24 89 80 21 ED                 lbz       r12, camShutterOpen
00012B28 2C 0C 00 00                 cmpwi     r12, 0
00012B2C 41 82 00 28                 beq       loc_12B54-12B2C
00012B30 48 00 4D 65                 bl        cameraShutterCloseCommon ;17894-00012B30
00012B34 38 60 00 06                 li        r3, SHUTTER_CLOSE # event SHUTTER_CLOSE
00012B38 38 80 00 00                 li        r4, 0
00012B3C 38 A0 00 00                 li        r5, 0
00012B40 48 02 AE 39                 bl        eventPost ; 3D978-00012B40
00012B44 39 20 00 00                 li        r9, 0
00012B48 99 20 21 ED                 stb       r9, camShutterOpen
00012B4C 48 08 6B D1                 bl        timeUsec ; 9971C-00012B4C
00012B50 90 60 20 A4                 stw       r3, shutterCloseTime
00012B54 8B DD 00 00 loc_12B54:      lbz       r30, 0(r29)
00012B58 2C 1E 00 01                 cmpwi     r30, 1
00012B5C 40 82 03 BC                 bne       loc_12F18-12B5C
00012B60 81 80 21 E0                 lwz       r12, backMessageCount
00012B64 39 8C 00 01                 addi      r12, r12, 1
00012B68 91 80 21 E0                 stw       r12, backMessageCount
00012B6C 8B DD 00 02                 lbz       r30, 2(r29)
00012B70 2C 1E 00 81                 cmpwi     r30, 0x81
00012B74 40 82 00 74                 bne       loc_12BE8-12B74
00012B78 48 00 57 E5                 bl        cameraWakeup ;1835C-00012B78
00012B7C 89 80 21 EA                 lbz       r12, camEnable
00012B80 99 80 21 EB                 stb       r12, camEnabled
00012B84 48 08 6B 99                 bl        timeUsec ; 9971C-00012B84
00012B88 90 60 21 C8                 stw       r3, lastBackStatusTime
00012B8C 89 60 21 DD                 lbz       r11, digitalBody
00012B90 2C 0B 00 00                 cmpwi     r11, 0
00012B94 40 82 00 14                 bne       loc_12BA8-12B94
00012B98 89 80 21 E8                 lbz       r12, camSoft
00012B9C 2C 0C 00 00                 cmpwi     r12, 0
00012BA0 40 82 00 08                 bne       loc_12BA8-12BA0
00012BA4 4B FF FD E1                 bl        cameraSoftPress  ;12984-00012BA4
00012BA8 89 80 21 DD loc_12BA8:      lbz       r12, digitalBody
00012BAC 2C 0C 00 00                 cmpwi     r12, 0
00012BB0 40 82 05 40                 bne       loc_130F0-12BB0
00012BB4 89 80 21 ED                 lbz       r12, camShutterOpen
00012BB8 2C 0C 00 00                 cmpwi     r12, 0
00012BBC 41 82 05 34                 beq       loc_130F0-12BBC
00012BC0 48 00 4C D5                 bl        cameraShutterCloseCommon ;17894-00012BC0
00012BC4 38 60 00 06                 li        r3, SHUTTER_CLOSE # event SHUTTER_CLOSE
00012BC8 38 80 00 00                 li        r4, 0
00012BCC 38 A0 00 00                 li        r5, 0
00012BD0 48 02 AD A9                 bl        eventPost ; 3D978-00012BD0
00012BD4 39 20 00 00                 li        r9, 0
00012BD8 99 20 21 ED                 stb       r9, camShutterOpen
00012BDC 48 08 6B 41                 bl        timeUsec ; 9971C-00012BDC
00012BE0 90 60 20 A4                 stw       r3, shutterCloseTime
00012BE4 48 00 05 0C                 b         loc_130F0-12BE4
00012BE8 2C 1E 00 82 loc_12BE8:      cmpwi     r30, 0x82
00012BEC 40 82 01 9C                 bne       loc_12D88-12BEC
00012BF0 48 00 57 6D                 bl        cameraWakeup ;1835C-00012BF0
00012BF4 39 80 00 01                 li        r12, 1
00012BF8 99 80 21 DD                 stb       r12, digitalBody
00012BFC 89 7D 00 04                 lbz       r11, 4(r29)
00012C00 55 6B 06 76                 rlwinm    r11, r11, 0,25,27 # r11 = r11 & 0x70
00012C04 55 7E E7 3E                 extrwi    r30, r11, 4,24 # r30 = (r11 >> 4) & 0xF
00012C08 9B C0 21 F2                 stb       r30, camReply
00012C0C 3B E0 00 00                 li        r31, 0
00012C10 3D 40 00 00                 lis       r10, command@h
00012C14 39 4A 73 D8                 addi      r10, r10, command@l
00012C18 1D 3E 00 34                 mulli     r9, r30, 0x34
00012C1C 7C AA 4A 14                 add       r5, r10, r9
00012C20 85 85 00 04 loc_12C20:      lwzu      r12, 4(r5)
00012C24 2C 0C 00 00                 cmpwi     r12, 0
00012C28 41 82 00 14                 beq       loc_12C3C-12C28
00012C2C 81 85 00 00                 lwz       r12, 0(r5)
00012C30 7D 7D FA 14                 add       r11, r29, r31
00012C34 89 6B 00 05                 lbz       r11, 5(r11)
00012C38 99 6C 00 00                 stb       r11, 0(r12)
00012C3C 3B FF 00 01 loc_12C3C:      addi      r31, r31, 1
00012C40 28 1F 00 06                 cmplwi    r31, 6
00012C44 41 80 FF DC                 blt       loc_12C20-12C44
00012C48 2C 1E 00 01                 cmpwi     r30, 1
00012C4C 40 82 00 44                 bne       loc_12C90-12C4C
00012C50 89 80 22 1A                 lbz       r12, getST
00012C54 2C 0C 00 05                 cmpwi     r12, 5
00012C58 40 82 00 0C                 bne       loc_12C64-12C58
00012C5C 39 80 00 00                 li        r12, 0
00012C60 99 80 21 DC                 stb       r12, camMainSwitchOn
00012C64 89 80 21 EE loc_12C64:      lbz       r12, camShutterOpenDigital
00012C68 2C 0C 00 00                 cmpwi     r12, 0
00012C6C 41 82 00 E8                 beq       loc_12D54-12C6C
00012C70 89 80 21 DF                 lbz       r12, camSettingsReceived
00012C74 2C 0C 00 00                 cmpwi     r12, 0
00012C78 41 82 00 DC                 beq       loc_12D54-12C78
00012C7C 4B FF D9 69                 bl        cameraDataComplete   ; 000105E4-00012C7C
00012C80 39 80 00 00                 li        r12, 0
00012C84 99 80 21 EE                 stb       r12, camShutterOpenDigital
00012C88 99 80 21 DF                 stb       r12, camSettingsReceived
00012C8C 48 00 00 C8                 b         loc_12D54-12C8C
00012C90 2C 1E 00 02 loc_12C90:      cmpwi     r30, 2
00012C94 40 82 00 18                 bne       loc_12CAC-12C94
00012C98 4B FF FC 49                 bl        cameraUpdateSettingsMamiyaDigital    ;128E0-00012C98
00012C9C 4B FF D9 49                 bl        cameraDataComplete   ; 000105E4-00012C9C
00012CA0 39 80 00 00                 li        r12, 0
00012CA4 99 80 21 EE                 stb       r12, camShutterOpenDigital
00012CA8 48 00 00 AC                 b         loc_12D54-12CA8
00012CAC 2C 1E 00 03 loc_12CAC:      cmpwi     r30, 3
00012CB0 40 82 00 2C                 bne       loc_12CDC-12CB0
00012CB4 4B FF FC 2D                 bl        cameraUpdateSettingsMamiyaDigital    ;128E0-00012CB4
00012CB8 89 80 21 E5                 lbz       r12, camSet
00012CBC 2C 0C 00 00                 cmpwi     r12, 0
00012CC0 41 82 00 10                 beq       loc_12CD0-12CC0
00012CC4 39 80 00 20                 li        r12, 0x20 # ' '
00012CC8 99 80 22 18                 stb       r12, setMD
00012CCC 48 00 00 88                 b         loc_12D54-12CCC
00012CD0 39 80 00 00 loc_12CD0:      li        r12, 0
00012CD4 99 80 22 18                 stb       r12, setMD
00012CD8 48 00 00 7C                 b         loc_12D54-12CD8
00012CDC 2C 1E 00 04 loc_12CDC:      cmpwi     r30, 4
00012CE0 41 82 00 74                 beq       loc_12D54-12CE0
00012CE4 2C 1E 00 05                 cmpwi     r30, 5
00012CE8 40 82 00 6C                 bne       loc_12D54-12CE8
00012CEC 89 80 22 22                 lbz       r12, getSU
00012CF0 3D 60 00 0F                 lis       r11, unk_F4240@h
00012CF4 61 6B 42 40                 ori       r11, r11, unk_F4240@l
00012CF8 7C 6C 59 D6                 mullw     r3, r12, r11
00012CFC 90 60 21 BC                 stw       r3, exposureTime
00012D00 3B E0 00 00                 li        r31, 0
00012D04 89 20 22 23                 lbz       r9, getSL
00012D08 55 24 06 7E                 clrlwi    r4, r9, 25    # r4 = r9 & 0x7F
00012D0C 2C 04 00 00                 cmpwi     r4, 0
00012D10 41 82 00 44                 beq       loc_12D54-12D10
00012D14 38 C3 00 00                 addi      r6, r3, 0
00012D18 3B A0 00 0A                 li        r29, 0xA
00012D1C 38 A4 00 00                 addi      r5, r4, 0
00012D20 21 64 00 00                 subfic    r11, r4, 0
00012D24 55 6B 07 FF                 clrlwi.   r11, r11, 31  # r11 = r11 & 1
00012D28 41 82 00 14                 beq       loc_12D3C-12D28
00012D2C 7C C3 EB 96                 divwu     r6, r3, r29
00012D30 3B E0 00 01                 li        r31, 1
00012D34 28 04 00 01                 cmplwi    r4, 1
00012D38 40 81 00 18                 ble       loc_12D50-12D38
00012D3C 7C C6 EB 96 loc_12D3C:      divwu     r6, r6, r29
00012D40 7C C6 EB 96                 divwu     r6, r6, r29
00012D44 3B FF 00 02                 addi      r31, r31, 2
00012D48 7C 1F 28 40                 cmplw     r31, r5
00012D4C 41 80 FF F0                 blt       loc_12D3C-12D4C
00012D50 90 C0 21 BC loc_12D50:      stw       r6, exposureTime
00012D54 89 80 21 E8 loc_12D54:      lbz       r12, camSoft
00012D58 2C 0C 00 00                 cmpwi     r12, 0
00012D5C 40 82 03 94                 bne       loc_130F0-12D5C
00012D60 2C 1E 00 01                 cmpwi     r30, 1
00012D64 40 82 03 8C                 bne       loc_130F0-12D64
00012D68 89 80 22 1A                 lbz       r12, getST
00012D6C 55 8C 07 7A                 rlwinm    r12, r12, 0,29,29 # r12 = r12 & 4
00012D70 2C 0C 00 00                 cmpwi     r12, 0
00012D74 40 82 03 7C                 bne       loc_130F0-12D74
00012D78 4B FF FC 0D loc_12D78:      bl        cameraSoftPress  ;12984-12D78
00012D7C 39 80 00 01                 li        r12, 1
00012D80 99 80 21 EF                 stb       r12, camReplyDelay
00012D84 48 00 03 6C                 b         loc_130F0-12D84
00012D88 2C 1E 00 83 loc_12D88:      cmpwi     r30, 0x83
00012D8C 40 82 00 D8                 bne       loc_12E64-12D8C
00012D90 89 9F 00 06                 lbz       r12, 6(r31)
00012D94 55 8C 06 76                 rlwinm    r12, r12, 0,25,27 # r12 = r12 & 0x70
00012D98 55 9E E7 3E                 extrwi    r30, r12, 4,24 # r30 = (r12 >> 4) & 0xF
00012D9C 2C 1E 00 01                 cmpwi     r30, 1
00012DA0 40 82 00 10                 bne       loc_12DB0-12DA0
00012DA4 89 80 21 EA                 lbz       r12, camEnable
00012DA8 99 80 21 EB                 stb       r12, camEnabled
00012DAC 48 00 00 AC                 b         loc_12E58-12DAC
00012DB0 2C 1E 00 02 loc_12DB0:      cmpwi     r30, 2
00012DB4 41 82 00 A4                 beq       loc_12E58-12DB4
00012DB8 2C 1E 00 03                 cmpwi     r30, 3
00012DBC 40 82 00 14                 bne       loc_12DD0-12DBC
00012DC0 3B E0 00 00                 li        r31, 0
00012DC4 9B E0 21 E6                 stb       r31, camGet
00012DC8 9B E0 21 E5                 stb       r31, camSet
00012DCC 48 00 00 8C                 b         loc_12E58-12DCC
00012DD0 2C 1E 00 04 loc_12DD0:      cmpwi     r30, 4
00012DD4 40 82 00 84                 bne       loc_12E58-12DD4
00012DD8 8B C0 21 EA                 lbz       r30, camEnable
00012DDC 9B C0 21 EB                 stb       r30, camEnabled
00012DE0 8B E0 21 E8                 lbz       r31, camSoft
00012DE4 2C 1F 00 00                 cmpwi     r31, 0
00012DE8 41 82 00 28                 beq       loc_12E10-12DE8
00012DEC 57 DE 06 3E                 clrlwi    r30, r30, 24  # r30 = r30 & 0xFF
00012DF0 2C 1E 00 00                 cmpwi     r30, 0
00012DF4 41 82 00 1C                 beq       loc_12E10-12DF4
00012DF8 89 80 22 19                 lbz       r12, setRE
00012DFC 55 8C 07 BE                 clrlwi    r12, r12, 30  # r12 = r12 & 3
00012E00 2C 0C 00 03                 cmpwi     r12, 3
00012E04 40 82 00 0C                 bne       loc_12E10-12E04
00012E08 39 80 00 01                 li        r12, 1
00012E0C 99 80 21 F0                 stb       r12, camTakeRequested
00012E10 2C 1F 00 00 loc_12E10:      cmpwi     r31, 0
00012E14 40 82 00 18                 bne       loc_12E2C-12E14
00012E18 89 80 22 19                 lbz       r12, setRE
00012E1C 55 8C 07 FE                 clrlwi    r12, r12, 31  # r12 = r12 & 1
00012E20 2C 0C 00 00                 cmpwi     r12, 0
00012E24 41 82 00 08                 beq       loc_12E2C-12E24
00012E28 4B FF FB 5D                 bl        cameraSoftPress  ;12984-00012E28
00012E2C 89 80 21 E7 loc_12E2C:      lbz       r12, camClearRequest
00012E30 2C 0C 00 00                 cmpwi     r12, 0
00012E34 41 82 00 1C                 beq       loc_12E50-12E34
00012E38 89 80 22 19                 lbz       r12, setRE
00012E3C 55 8C 07 BE                 clrlwi    r12, r12, 30  # r12 = r12 & 3
00012E40 2C 0C 00 00                 cmpwi     r12, 0
00012E44 40 82 00 0C                 bne       loc_12E50-12E44
00012E48 39 80 00 00                 li        r12, 0
00012E4C 99 80 21 E7                 stb       r12, camClearRequest
00012E50 48 08 68 CD loc_12E50:      bl        timeUsec ; 9971C-12E50
00012E54 90 60 21 CC                 stw       r3, releaseMessageTime
00012E58 39 80 00 00 loc_12E58:      li        r12, 0
00012E5C 99 80 21 F2                 stb       r12, camReply
00012E60 48 00 02 90                 b         loc_130F0-12E60
00012E64 2C 1E 00 84 loc_12E64:      cmpwi     r30, 0x84
00012E68 40 82 00 7C                 bne       loc_12EE4-12E68
00012E6C 89 80 21 EC                 lbz       r12, camShutterArm
00012E70 2C 0C 00 00                 cmpwi     r12, 0
00012E74 40 82 00 28                 bne       loc_12E9C-12E74
00012E78 39 80 00 01                 li        r12, 1
00012E7C 99 80 21 EC                 stb       r12, camShutterArm
00012E80 3B E0 00 00                 li        r31, 0
00012E84 9B E0 21 ED                 stb       r31, camShutterOpen
00012E88 9B E0 21 EE                 stb       r31, camShutterOpenDigital
00012E8C 38 60 00 04                 li        r3, SHUTTER_WARNING # event SHUTTER_WARNING
00012E90 38 80 00 00                 li        r4, 0
00012E94 38 A0 00 00                 li        r5, 0
00012E98 48 02 AA E1                 bl        eventPost ; 3D978-00012E98
00012E9C 38 60 13 88 loc_12E9C:      li        r3, 5000
00012EA0 48 08 6A 19                 bl        waitUsec   ; 998B8-00012EA0
00012EA4 48 08 68 79                 bl        timeUsec   ; 9971C-00012EA4
00012EA8 90 60 20 A0                 stw       r3, shutterOpenTime
00012EAC 3B C0 00 01                 li        r30, 1
00012EB0 9B C0 21 ED                 stb       r30, camShutterOpen
00012EB4 9B C0 21 EE                 stb       r30, camShutterOpenDigital
00012EB8 3B E0 00 00                 li        r31, 0
00012EBC 9B E0 21 EC                 stb       r31, camShutterArm
00012EC0 9B E0 21 F0                 stb       r31, camTakeRequested
00012EC4 9B E0 21 48                 stb       r31, takePicture
00012EC8 9B C0 20 99                 stb       r30, takePictureDone
00012ECC 48 00 48 F5                 bl        cameraShutterOpenCommon  ;177C0-00012ECC
00012ED0 38 60 00 05                 li        r3, SHUTTER_OPEN # event SHUTTER_OPEN
00012ED4 38 80 00 00                 li        r4, 0
00012ED8 38 A0 00 00                 li        r5, 0
00012EDC 48 02 AA 9D                 bl        eventPost ; 3D978-00012EDC
00012EE0 48 00 02 10                 b         loc_130F0-12EE0
00012EE4 2C 1E 00 A3 loc_12EE4:      cmpwi     r30, 0xA3
00012EE8 40 82 00 14                 bne       loc_12EFC-12EE8
00012EEC 38 7D 00 00                 addi      r3, r29, 0
00012EF0 4B FF F8 31                 bl        cameraUpdateSettingsMamiyaFilm   ;12720-00012EF0
00012EF4 4B FF D6 F1                 bl        cameraDataComplete   ;105E4-00012EF4
00012EF8 48 00 01 F8                 b         loc_130F0-12EF8
00012EFC 2C 1E 00 A7 loc_12EFC:      cmpwi     r30, 0xA7
00012F00 41 82 01 F0                 beq       loc_130F0-12F00
00012F04 2C 1E 00 A8                 cmpwi     r30, 0xA8
00012F08 40 82 01 E8                 bne       loc_130F0-12F08
00012F0C 39 80 00 00                 li        r12, 0
00012F10 99 80 21 DC                 stb       r12, camMainSwitchOn
00012F14 48 00 01 DC                 b         loc_130F0-12F14
00012F18 2C 1E 00 02 loc_12F18:      cmpwi     r30, 2
00012F1C 40 82 01 2C                 bne       loc_13048-12F1C
00012F20 8B FD 00 02                 lbz       r31, 2(r29)
00012F24 2C 1F 00 03                 cmpwi     r31, 3
00012F28 40 82 00 50                 bne       loc_12F78-12F28
00012F2C 89 80 21 DD                 lbz       r12, digitalBody
00012F30 2C 0C 00 00                 cmpwi     r12, 0
00012F34 40 82 01 BC                 bne       loc_130F0-12F34
00012F38 89 80 21 EC                 lbz       r12, camShutterArm
00012F3C 2C 0C 00 00                 cmpwi     r12, 0
00012F40 41 82 01 B0                 beq       loc_130F0-12F40
00012F44 3B C0 00 01                 li        r30, 1
00012F48 9B C0 21 ED                 stb       r30, camShutterOpen
00012F4C 3B E0 00 00                 li        r31, 0
00012F50 9B E0 21 EC                 stb       r31, camShutterArm
00012F54 9B E0 21 F0                 stb       r31, camTakeRequested
00012F58 9B E0 21 48                 stb       r31, takePicture
00012F5C 9B C0 20 99                 stb       r30, takePictureDone
00012F60 48 00 48 61                 bl        cameraShutterOpenCommon  ;177C0-00012F60
00012F64 38 60 00 05                 li        r3, SHUTTER_OPEN # event SHUTTER_OPEN
00012F68 38 80 00 00                 li        r4, 0
00012F6C 38 A0 00 00                 li        r5, 0
00012F70 48 02 AA 09                 bl        eventPost ; 3D978-00012F70
00012F74 48 00 01 7C                 b         loc_130F0-12F74
00012F78 2C 1F 00 81 loc_12F78:      cmpwi     r31, 0x81
00012F7C 40 82 00 0C                 bne       loc_12F88-12F7C
00012F80 48 00 53 DD                 bl        cameraWakeup ;1835C-00012F80
00012F84 48 00 01 6C                 b         loc_130F0-12F84
00012F88 2C 1F 00 A0 loc_12F88:      cmpwi     r31, 0xA0
00012F8C 40 82 00 48                 bne       loc_12FD4-12F8C
00012F90 89 80 21 EC                 lbz       r12, camShutterArm
00012F94 2C 0C 00 00                 cmpwi     r12, 0
00012F98 40 82 00 1C                 bne       loc_12FB4-12F98
00012F9C 89 80 21 DD                 lbz       r12, digitalBody
00012FA0 2C 0C 00 00                 cmpwi     r12, 0
00012FA4 40 82 00 20                 bne       loc_12FC4-12FA4
00012FA8 89 80 21 ED                 lbz       r12, camShutterOpen
00012FAC 2C 0C 00 00                 cmpwi     r12, 0
00012FB0 41 82 00 14                 beq       loc_12FC4-12FB0
00012FB4 38 60 00 08 loc_12FB4:      li        r3, SHUTTER_EARLY_WARNING # event SHUTTER_EARLY_WARNING
00012FB8 38 80 00 00                 li        r4, 0
00012FBC 38 A0 00 00                 li        r5, 0
00012FC0 48 02 A9 B9                 bl        eventPost ; 3D978-00012FC0
00012FC4 3B E0 00 00 loc_12FC4:      li        r31, 0
00012FC8 9B E0 21 ED                 stb       r31, camShutterOpen
00012FCC 9B E0 21 EC                 stb       r31, camShutterArm
00012FD0 48 00 01 20                 b         loc_130F0-12FD0
00012FD4 2C 1F 00 A2 loc_12FD4:      cmpwi     r31, 0xA2
00012FD8 40 82 01 18                 bne       loc_130F0-12FD8
00012FDC 89 80 21 EB                 lbz       r12, camEnabled
00012FE0 2C 0C 00 00                 cmpwi     r12, 0
00012FE4 41 82 01 0C                 beq       loc_130F0-12FE4
00012FE8 89 80 21 E8                 lbz       r12, camSoft
00012FEC 2C 0C 00 00                 cmpwi     r12, 0
00012FF0 41 82 01 00                 beq       loc_130F0-12FF0
00012FF4 89 80 21 EC                 lbz       r12, camShutterArm
00012FF8 2C 0C 00 00                 cmpwi     r12, 0
00012FFC 40 82 00 F4                 bne       loc_130F0-12FFC
00013000 89 80 21 EE                 lbz       r12, camShutterOpenDigital
00013004 2C 0C 00 00                 cmpwi     r12, 0
00013008 40 82 00 E8                 bne       loc_130F0-13008
0001300C 89 80 21 DD                 lbz       r12, digitalBody
00013010 2C 0C 00 00                 cmpwi     r12, 0
00013014 41 82 00 10                 beq       loc_13024-13014
00013018 81 80 21 E0                 lwz       r12, backMessageCount
0001301C 28 0C 00 04                 cmplwi    r12, 4
00013020 40 81 00 D0                 ble       loc_130F0-13020
00013024 39 80 00 01 loc_13024:      li        r12, 1
00013028 99 80 21 EC                 stb       r12, camShutterArm
0001302C 39 60 00 00                 li        r11, 0
00013030 99 60 21 ED                 stb       r11, camShutterOpen
00013034 38 60 00 04                 li        r3, SHUTTER_WARNING # event SHUTTER_WARNING
00013038 38 80 00 00                 li        r4, 0
0001303C 38 A0 00 00                 li        r5, 0
00013040 48 02 A9 39                 bl        eventPost ; 3D978-00013040
00013044 48 00 00 AC                 b         loc_130F0-13044
00013048 2C 1E 00 7D loc_13048:      cmpwi     r30, 0x7D
0001304C 40 82 00 A4                 bne       loc_130F0-1304C
00013050 89 9D 00 01                 lbz       r12, 1(r29)
00013054 2C 0C 00 82                 cmpwi     r12, 0x82
00013058 40 82 00 28                 bne       loc_13080-13058
0001305C 48 00 53 01                 bl        cameraWakeup ;1835C-0001305C
00013060 39 80 00 01                 li        r12, 1
00013064 99 80 22 2A                 stb       r12, mamiyaSerialV1
00013068 99 80 21 DD                 stb       r12, digitalBody
0001306C 39 80 00 90                 li        r12, 0x90
00013070 99 80 22 16                 stb       r12, setEO
00013074 39 80 00 99                 li        r12, 0x99
00013078 99 80 22 2B                 stb       r12, setP1
0001307C 48 00 00 74                 b         loc_130F0-1307C
00013080 48 08 66 9D loc_13080:      bl        timeUsec  ; 9971C-13080
00013084 90 60 21 D0                 stw       r3, bodySleepTime
00013088 89 80 21 E8                 lbz       r12, camSoft
0001308C 2C 0C 00 00                 cmpwi     r12, 0
00013090 41 82 00 30                 beq       loc_130C0-13090
00013094 39 80 00 00                 li        r12, 0
00013098 99 80 21 E8                 stb       r12, camSoft
0001309C 38 60 00 0A                 li        r3, SOFT_RELEASE # event SOFT_RELEASE
000130A0 38 80 00 00                 li        r4, 0
000130A4 38 A0 00 00                 li        r5, 0
000130A8 48 02 A8 D1                 bl        eventPost ; 3D978-000130A8
000130AC 48 04 E5 CD                 bl        imageSafeSet; 61678-000130AC
000130B0 38 60 00 03                 li        r3, CAMERA_SAFE # event CAMERA_SAFE
000130B4 38 80 00 00                 li        r4, 0
000130B8 38 A0 00 00                 li        r5, 0
000130BC 48 02 A8 BD                 bl        eventPost ; 3D978-000130BC 
000130C0 89 80 21 DC loc_130C0:      lbz       r12, camMainSwitchOn
000130C4 2C 0C 00 00                 cmpwi     r12, 0
000130C8 40 82 00 28                 bne       loc_130F0-130C8
000130CC 3B E0 00 00 loc_130CC:      li        r31, 0
000130D0 9B E0 21 E9                 stb       r31, camAwake
000130D4 9B E0 21 DD                 stb       r31, digitalBody
000130D8 93 E0 21 E0                 stw       r31, backMessageCount
000130DC 93 E0 21 BC                 stw       r31, exposureTime
000130E0 38 60 00 0E                 li        r3, MAIN_SWITCH_OFF
000130E4 38 80 00 00                 li        r4, 0
000130E8 38 A0 00 00                 li        r5, 0
000130EC 48 02 A8 8D                 bl        eventPost ; 3D978-000130EC
000130F0 48 08 66 2D loc_130F0:      bl        timeUsec ;9971C-130F0
000130F4 90 60 21 C4                 stw       r3, lastMessageTime
000130F8 83 A1 00 1C loc_130F8:      lwz       r29, 0x28+var_C(r1)
000130FC 83 C1 00 20                 lwz       r30, 0x28+var_8(r1)
00013100 83 E1 00 24                 lwz       r31, 0x28+var_4(r1)
00013104 80 01 00 2C                 lwz       r0, 0x28+arg_4(r1)
00013108 7C 08 03 A6                 mtlr      r0
0001310C 38 21 00 28                 addi      r1, r1, 0x28
00013110 4E 80 00 20                 blr
00013114 00 00 00 00 
00013118 00 00 00 00 
0001311C 00 00 00 00 
00013120 00 00 00 00 
00013124 00 00 00 00  
00013128 00 00 00 00 
