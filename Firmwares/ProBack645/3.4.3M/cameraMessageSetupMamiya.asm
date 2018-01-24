cameraMessageSetupMamiya
00013280-566C=DC14
00013280 94 21 FF E8                 stwu      r1,
00013284 7C 08 02 A6                 mflr      r0
00013288 93 C1 00 10                 stw       r30, 0x18+var_8(r1)
0001328C 93 E1 00 14                 stw       r31, 0x18+var_4(r1)
00013290 90 01 00 1C                 stw       r0, 0x18+arg_4(r1)
00013294 3B E3 00 00                 addi      r31, r3, 0
00013298 3B C0 00 00                 li        r30, 0
0001329C 89 60 21 DD                 lbz       r11, digitalBody
000132A0 2C 0B 00 00                 cmpwi     r11, 0
000132A4 41 82 01 A8                 beq       loc_1344C
000132A8 89 80 21 ED                 lbz       r12, camShutterOpen
000132AC 2C 0C 00 00                 cmpwi     r12, 0
000132B0 41 82 01 9C                 beq       loc_1344C
000132B4 81 80 21 AC                 lwz       r12, shutterMode
000132B8 2C 0C 00 00                 cmpwi     r12, 0
000132BC 40 82 00 68                 bne       loc_13324
000132C0 81 80 21 BC                 lwz       r12, exposureTime
000132C4 2C 0C 00 00                 cmpwi     r12, 0
000132C8 41 82 01 84                 beq       loc_1344C
000132CC 81 80 20 A0                 lwz       r12, shutterOpenTime
000132D0 2C 0C 00 00                 cmpwi     r12, 0
000132D4 41 82 01 78                 beq       loc_1344C
000132D8 48 08 64 45                 bl        timeUsec 
000132DC 81 80 20 A0                 lwz       r12, shutterOpenTime
000132E0 7C 6C 18 50                 subf      r3, r12, r3
000132E4 81 60 21 BC                 lwz       r11, exposureTime
000132E8 3D 40 00 01                 lis       r10, loc_186A0@h
000132EC 61 4A 86 A0                 ori       r10, r10, loc_186A0@l
000132F0 7D 6B 52 14                 add       r11, r11, r10
000132F4 7C 03 58 40                 cmplw     r3, r11
000132F8 40 81 01 54                 ble       loc_1344C
000132FC 48 00 45 99                 bl        cameraShutterCloseCommon 
00013300 38 60 00 06                 li        r3, SHUTTER_CLOSE
00013304 38 80 00 00                 li        r4, 0
00013308 38 A0 00 00                 li        r5, 0
0001330C 48 02 A6 6D                 bl        eventPost 
00013310 39 20 00 00                 li        r9, 0
00013314 99 20 21 ED                 stb       r9, camShutterOpen
00013318 48 08 64 05                 bl        timeUsec 
0001331C 90 60 20 A4                 stw       r3, shutterCloseTime
00013320 48 00 01 2C                 b         loc_1344C
00013324 81 80 20 A0 loc_13324:      lwz       r12, shutterOpenTime
00013328 2C 0C 00 00                 cmpwi     r12, 0
0001332C 40 82 00 AC                 bne       loc_133D8
00013330 3D 60 20 00                 lis       r11, IMMR@h
00013334 81 8B 0A C4                 lwz       r12, 0xAC4(r11)
00013338 55 8C 07 7B                 rlwinm.   r12, r12, 0,29,29 # r12 = r12 & 4
0001333C 41 82 07 A8                 beq       loc_13AE4
00013340 81 80 21 AC                 lwz       r12, shutterMode
00013344 2C 0C 00 01                 cmpwi     r12, 1
00013348 40 82 00 7C                 bne       loc_133C4
0001334C 4B FF F6 39                 bl        cameraSoftPress 
00013350 3C 60 00 04                 lis       r3, 493E0@h
00013354 60 63 93 E0                 ori       r3, r3, 493E0@l
00013358 48 08 65 61                 bl        waitUsec 
0001335C 39 80 00 01                 li        r12, 1
00013360 99 80 21 EC                 stb       r12, camShutterArm
00013364 38 60 00 00                 li        r3, 0
00013368 98 60 21 ED                 stb       r3, camShutterOpen
0001336C 98 60 21 EE                 stb       r3, camShutterOpenDigital
00013370 38 60 00 04                 li        r3, SHUTTER_WARNING # event SHUTTER_WARNING
00013374 38 80 00 00                 li        r4, 0
00013378 38 A0 00 00                 li        r5, 0
0001337C 48 02 A5 FD                 bl        eventPost 
00013380 3C 60 00 00                 lis       r3, C350@h
00013384 60 63 C3 50                 ori       r3, r3, C350@l
00013388 48 08 65 31                 bl        waitUsec 
0001338C 38 60 00 00                 li        r3, 0
00013390 90 60 20 A4                 stw       r3, shutterCloseTime
00013394 98 60 21 EC                 stb       r3, camShutterArm
00013398 98 60 21 F0                 stb       r3, camTakeRequested
0001339C 98 60 21 48                 stb       r3, takePicture
000133A0 38 60 00 01                 li        r30, 1
000133A4 98 60 21 ED                 stb       r30, camShutterOpen
000133A8 98 60 21 EE                 stb       r30, camShutterOpenDigital
000133AC 98 60 20 99                 stb       r30, takePictureDone
000133B0 48 00 44 11                 bl        cameraShutterOpenCommon 
000133B4 38 60 00 05                 li        r3, 5
000133B8 38 80 00 00                 li        r4, 0
000133BC 38 A0 00 00                 li        r5, 0
000133C0 48 02 A5 B9                 bl        eventPost 
000133C4 48 08 63 59 loc_133C4:      bl        timeUsec 
000133C8 90 60 20 A0                 stw       r3, shutterOpenTime
000133CC 39 80 00 00                 li        r12, 0
000133D0 99 80 21 DF                 stb       r12, camSettingsReceived
000133D4 48 00 00 78                 b         loc_1344C
000133D8 81 80 20 A4 loc_133D8:      lwz       r12, shutterCloseTime
000133DC 2C 0C 00 00                 cmpwi     r12, 0
000133E0 40 82 00 20                 bne       loc_13400
000133E4 3D 60 20 00                 lis       r11, IMMR@h
000133E8 81 8B 0A C4                 lwz       r12, 0xAC4(r11)
000133EC 55 8C 07 7B                 rlwinm.   r12, r12, 0,29,29 # r12 = r12 & 4
000133F0 40 82 00 5C                 bne       loc_1344C
000133F4 48 08 63 29                 bl        timeUsec 
000133F8 90 60 20 A4                 stw       r3, shutterCloseTime
000133FC 48 00 00 50                 b         loc_1344C
00013400 81 60 21 BC loc_13400:      lwz       r11, exposureTime
00013404 2C 0B 00 00                 cmpwi     r11, 0
00013408 41 82 00 28                 beq       loc_13430
0001340C 48 08 63 11                 bl        timeUsec 
00013410 81 80 20 A0                 lwz       r12, shutterOpenTime
00013414 7C 6C 18 50                 subf      r3, r12, r3
00013418 81 60 21 BC                 lwz       r11, exposureTime
0001341C 3D 40 00 01                 lis       r10, 15F90@h
00013420 61 4A 5F 90                 ori       r10, r10, 15F90@l
00013424 7D 6B 52 14                 add       r11, r11, r10
00013428 7C 03 58 40                 cmplw     r3, r11
0001342C 41 80 00 20                 blt       loc_1344C
00013430 48 00 44 65 loc_13430:      bl        cameraShutterCloseCommon 
00013434 38 60 00 06                 li        r3, 6
00013438 38 80 00 00                 li        r4, 0
0001343C 38 A0 00 00                 li        r5, 0
00013440 48 02 A5 39                 bl        eventPost 
00013444 39 20 00 00                 li        r9, 0
00013448 99 20 21 ED                 stb       r9, camShutterOpen
0001344C 81 80 21 AC loc_1344C:      lwz       r12, shutterMode
00013450 2C 0C 00 00                 cmpwi     r12, 0
00013454 41 82 00 0C                 beq       loc_13460
00013458 2C 0C 00 02                 cmpwi     r12, 2
0001345C 40 82 00 7C                 bne       loc_134D8
00013460 89 80 21 E8 loc_13460:      lbz       r12, camSoft
00013464 2C 0C 00 00                 cmpwi     r12, 0
00013468 41 82 00 70                 beq       loc_134D8
0001346C 89 80 21 ED                 lbz       r12, camShutterOpen
00013470 2C 0C 00 00                 cmpwi     r12, 0
00013474 40 82 00 64                 bne       loc_134D8
00013478 89 80 21 EE                 lbz       r12, camShutterOpenDigital
0001347C 2C 0C 00 00                 cmpwi     r12, 0
00013480 40 82 00 58                 bne       loc_134D8
00013484 48 08 62 99                 bl        timeUsec 
00013488 81 80 21 C4                 lwz       r12, lastMessageTime
0001348C 7C 6C 18 50                 subf      r3, r12, r3
00013490 89 60 21 B2                 lbz       r11, curCamSoftOnTime
00013494 55 6B 10 3A                 slwi      r11, r11, 2   # r11 = r11 << 2
00013498 3D 40 00 01                 lis       r10, camSoftOnTimes@h
0001349C 61 4A 24 F0                 ori       r10, r10, camSoftOnTimes@l
000134A0 7D 6A 58 2E                 lwzx      r11, r10, r11
000134A4 7C 03 58 40                 cmplw     r3, r11
000134A8 40 81 00 30                 ble       loc_134D8
000134AC 39 80 00 00                 li        r12, 0
000134B0 99 80 21 E8                 stb       r12, camSoft
000134B4 38 60 00 0A                 li        r3, 0xA
000134B8 38 80 00 00                 li        r4, 0
000134BC 38 A0 00 00                 li        r5, 0
000134C0 48 02 A4 B9                 bl        eventPost 
000134C4 48 04 E1 B5                 bl        imageSafeSet 
000134C8 38 60 00 03                 li        r3, 3
000134CC 38 80 00 00                 li        r4, 0
000134D0 38 A0 00 00                 li        r5, 0
000134D4 48 02 A4 A5                 bl        eventPost 
000134D8 81 80 21 AC loc_134D8:      lwz       r12, shutterMode
000134DC 2C 0C 00 01                 cmpwi     r12, 1
000134E0 40 82 00 54                 bne       loc_13534
000134E4 89 80 21 E8                 lbz       r12, camSoft
000134E8 2C 0C 00 00                 cmpwi     r12, 0
000134EC 41 82 00 48                 beq       loc_13534
000134F0 89 80 21 ED                 lbz       r12, camShutterOpen
000134F4 2C 0C 00 00                 cmpwi     r12, 0
000134F8 40 82 00 3C                 bne       loc_13534
000134FC 89 80 21 EE                 lbz       r12, camShutterOpenDigital
00013500 2C 0C 00 00                 cmpwi     r12, 0
00013504 40 82 00 30                 bne       loc_13534
00013508 39 80 00 00                 li        r12, 0
0001350C 99 80 21 E8                 stb       r12, camSoft
00013510 38 60 00 0A                 li        r3, 0xA
00013514 38 80 00 00                 li        r4, 0
00013518 38 A0 00 00                 li        r5, 0
0001351C 48 02 A4 5D                 bl        eventPost 
00013520 48 04 E1 59                 bl        imageSafeSet 
00013524 38 60 00 03                 li        r3, 3
00013528 38 80 00 00                 li        r4, 0
0001352C 38 A0 00 00                 li        r5, 0
00013530 48 02 A4 49                 bl        eventPost 
00013534 48 00 4F 39 loc_13534:      bl        cameraDialogCheck 
00013538 81 80 21 E0                 lwz       r12, backMessageCount
0001353C 28 0C 00 04                 cmplwi    r12, 4
00013540 40 81 00 8C                 ble       loc_135CC
00013544 89 80 21 DD                 lbz       r12, digitalBody
00013548 2C 0C 00 00                 cmpwi     r12, 0
0001354C 40 82 00 80                 bne       loc_135CC
00013550 89 80 21 48                 lbz       r12, takePicture
00013554 2C 0C 00 00                 cmpwi     r12, 0
00013558 41 82 00 64                 beq       loc_135BC
0001355C 89 80 20 98                 lbz       r12, takePictureHost
00013560 2C 0C 00 00                 cmpwi     r12, 0
00013564 41 82 00 18                 beq       loc_1357C
00013568 38 60 00 39                 li        r3, 0x39 # '9'
0001356C 38 80 00 00                 li        r4, 0
00013570 3C A0 00 3A                 lis       r5, 0x3A # ':'
00013574 48 02 A4 05                 bl        eventPost 
00013578 48 00 00 38                 b         loc_135B0
0001357C 39 80 00 00 loc_1357C:      li        r12, 0
00013580 91 81 00 08                 stw       r12, 0x18+var_10(r1)
00013584 3C 60 00 02                 lis       r3, unk_1C6A0@ha
00013588 38 63 C6 A0                 addi      r3, r3, unk_1C6A0@l
0001358C 3C 80 00 02                 lis       r4, dword_1C6DC@ha
00013590 38 84 C6 DC                 addi      r4, r4, dword_1C6DC@l
00013594 38 A0 00 00                 li        r5, 0
00013598 38 C0 00 00                 li        r6, 0
0001359C 38 E0 00 00                 li        r7, 0
000135A0 39 00 00 00                 li        r8, 0
000135A4 39 20 00 00                 li        r9, 0
000135A8 39 40 00 00                 li        r10, 0
000135AC 48 08 C5 79                 bl        userDialog 
000135B0 3B E0 00 00 loc_135B0:      li        r31, 0
000135B4 9B E0 21 F0                 stb       r31, camTakeRequested
000135B8 9B E0 21 48                 stb       r31, takePicture
000135BC 3B E0 00 00 loc_135BC:      li        r31, 0
000135C0 9B E0 21 E6                 stb       r31, camGet
000135C4 9B E0 21 E5                 stb       r31, camSet
000135C8 48 00 01 14                 b         loc_136DC
000135CC 28 1F 00 0A loc_135CC:      cmplwi    r31, 0xA
000135D0 40 81 00 74                 ble       loc_13644
000135D4 89 80 21 48                 lbz       r12, takePicture
000135D8 2C 0C 00 00                 cmpwi     r12, 0
000135DC 41 82 01 00                 beq       loc_136DC
000135E0 89 80 20 98                 lbz       r12, takePictureHost
000135E4 2C 0C 00 00                 cmpwi     r12, 0
000135E8 41 82 00 18                 beq       loc_13600
000135EC 38 60 00 39                 li        r3, 0x39 # '9'
000135F0 38 80 00 00                 li        r4, 0
000135F4 3C A0 00 31                 lis       r5, 0x31 # '1'
000135F8 48 02 A3 81                 bl        eventPost 
000135FC 48 00 00 38                 b         loc_13634
00013600 39 80 00 00 loc_13600:      li        r12, 0
00013604 91 81 00 08                 stw       r12, 0x18+var_10(r1)
00013608 3C 60 00 02                 lis       r3, unk_1C6E0@ha
0001360C 38 63 C6 E0                 addi      r3, r3, unk_1C6E0@l
00013610 3C 80 00 02                 lis       r4, dword_1C6DC@ha
00013614 38 84 C6 DC                 addi      r4, r4, dword_1C6DC@l
00013618 38 A0 00 00                 li        r5, 0
0001361C 38 C0 00 00                 li        r6, 0
00013620 38 E0 00 00                 li        r7, 0
00013624 39 00 00 00                 li        r8, 0
00013628 39 20 00 00                 li        r9, 0
0001362C 39 40 00 00                 li        r10, 0
00013630 48 08 C4 F5                 bl        userDialog 
00013634 3B E0 00 00 loc_13634:      li        r31, 0
00013638 9B E0 21 F0                 stb       r31, camTakeRequested
0001363C 9B E0 21 48                 stb       r31, takePicture
00013640 48 00 00 9C                 b         loc_136DC
00013644 89 80 21 48 loc_13644:      lbz       r12, takePicture
00013648 2C 0C 00 00                 cmpwi     r12, 0
0001364C 41 82 00 90                 beq       loc_136DC
00013650 89 80 21 F0                 lbz       r12, camTakeRequested
00013654 2C 0C 00 00                 cmpwi     r12, 0
00013658 41 82 00 84                 beq       loc_136DC
0001365C 48 08 60 C1                 bl        timeUsec 
00013660 81 80 21 CC                 lwz       r12, releaseMessageTime
00013664 7C 6C 18 50                 subf      r3, r12, r3
00013668 3D 60 00 4C                 lis       r11, 0x4C # 0x4C4B40 # 'L'
0001366C 61 6B 4B 40                 ori       r11, r11, 0x4B40 # 0x4C4B40
00013670 7C 03 58 40                 cmplw     r3, r11
00013674 40 81 00 68                 ble       loc_136DC
00013678 38 60 00 C7                 li        r3, 0xC7 # 'Ã'
0001367C 38 80 00 00                 li        r4, 0
00013680 3C A0 00 36                 lis       r5, 0x36 # '6'
00013684 48 02 A2 F5                 bl        eventPost 
00013688 89 20 20 98                 lbz       r9, takePictureHost
0001368C 2C 09 00 00                 cmpwi     r9, 0
00013690 40 82 00 38                 bne       loc_136C8
00013694 39 80 00 10                 li        r12, 0x10
00013698 91 81 00 08                 stw       r12, 0x18+var_10(r1)
0001369C 3C 60 00 02                 lis       r3, unk_1C704@ha
000136A0 38 63 C7 04                 addi      r3, r3, unk_1C704@l
000136A4 3C 80 00 02                 lis       r4, dword_1C6DC@ha
000136A8 38 84 C6 DC                 addi      r4, r4, dword_1C6DC@l
000136AC 38 A0 00 00                 li        r5, 0
000136B0 38 C0 00 00                 li        r6, 0
000136B4 38 E0 00 00                 li        r7, 0
000136B8 39 00 00 00                 li        r8, 0
000136BC 39 20 00 00                 li        r9, 0
000136C0 39 40 00 00                 li        r10, 0
000136C4 48 08 C4 61                 bl        userDialog 
000136C8 3B E0 00 00 loc_136C8:      li        r31, 0
000136CC 9B E0 21 F0                 stb       r31, camTakeRequested
000136D0 9B E0 21 48                 stb       r31, takePicture
000136D4 39 60 00 01                 li        r11, 1
000136D8 99 60 21 E7                 stb       r11, camClearRequest
000136DC 81 80 21 F4 loc_136DC:      lwz       r12, cameraMinIso
000136E0 81 60 22 24                 lwz       r11, cameraIso
000136E4 7D 8C 5A 14                 add       r12, r12, r11
000136E8 55 9F 20 36                 slwi      r31, r12, 4   # r31 = r12 << 4
000136EC 3D 40 00 02                 lis       r10, listIso@ha
000136F0 39 4A 8F 6C                 addi      r10, r10, listIso@l
000136F4 7D 4A F8 AE                 lbzx      r10, r10, r31
000136F8 99 40 58 22                 stb       r10, byte_5822
000136FC 3D 60 00 02                 lis       r11, listIsoSet@ha
00013700 39 6B 91 0C                 addi      r11, r11, listIsoSet@l
00013704 7D 6B F8 AE                 lbzx      r11, r11, r31
00013708 99 60 22 15                 stb       r11, setISO
0001370C 89 80 21 E8                 lbz       r12, camSoft
00013710 2C 0C 00 00                 cmpwi     r12, 0
00013714 38 80 00 01                 li        r4, 1
00013718 41 82 00 08                 beq       loc_13720
0001371C 38 80 00 00                 li        r4, 0
00013720 89 80 21 DD loc_13720:      lbz       r12, digitalBody
00013724 2C 0C 00 00                 cmpwi     r12, 0
00013728 40 82 00 1C                 bne       loc_13744
0001372C 81 80 21 AC                 lwz       r12, shutterMode
00013730 2C 0C 00 00                 cmpwi     r12, 0
00013734 40 82 00 10                 bne       loc_13744
00013738 3C 60 00 01                 lis       r3, loc_11170@h
0001373C 60 63 11 70                 ori       r3, r3, loc_11170@l
00013740 48 00 00 0C                 b         loc_1374C
00013744 3C 60 00 04 loc_13744:      lis       r3, loc_493E0@h
00013748 60 63 93 E0                 ori       r3, r3, loc_493E0@l
0001374C 48 04 DE A1 loc_1374C:      bl        imageOkToTakePicture 
00013750 3B E3 00 00                 addi      r31, r3, 0
00013754 2C 1F 00 00 loc_13754:      cmpwi     r31, 0
00013758 41 82 00 10                 beq       loc_13768
0001375C 89 80 21 E4                 lbz       r12, alwaysEnable
00013760 2C 0C 00 00                 cmpwi     r12, 0
00013764 41 82 00 2C                 beq       loc_13790
00013768 39 80 00 01 loc_13768:      li        r12, 1
0001376C 99 80 21 EA                 stb       r12, camEnable
00013770 38 60 58 20                 li        r3, 0x5820
00013774 89 43 00 04                 lbz       r10, 4(r3)
00013778 55 4A 07 FA                 rlwinm    r10, r10, 0,31,29 # r10 = r10 & 0xFFFFFFFD
0001377C 99 43 00 04                 stb       r10, 4(r3)
00013780 38 60 00 00                 li        r3, 0
00013784 98 60 22 11                 stb       r3, setST
00013788 98 60 21 F1                 stb       r3, camDisable
0001378C 48 00 00 88                 b         loc_13814
00013790 39 80 00 00 loc_13790:      li        r12, 0
00013794 99 80 21 EA                 stb       r12, camEnable
00013798 38 60 58 20                 li        r3, 0x5820
0001379C 89 43 00 04                 lbz       r10, 4(r3)
000137A0 61 4A 00 02                 ori       r10, r10, 2
000137A4 99 43 00 04                 stb       r10, 4(r3)
000137A8 57 E3 00 1E                 clrrwi    r3, r31, 16   # r3 = r31 & 0xFFFF0000
000137AC 3D 60 00 12                 lis       r11, 0x12
000137B0 7C 03 58 40                 cmplw     r3, r11
000137B4 41 82 00 10                 beq       loc_137C4
000137B8 3D 80 00 22                 lis       r12, 0x22 # '"'
000137BC 7C 03 60 40                 cmplw     r3, r12
000137C0 40 82 00 10                 bne       loc_137D0
000137C4 39 80 00 03 loc_137C4:      li        r12, 3
000137C8 99 80 22 11                 stb       r12, setST
000137CC 48 00 00 44                 b         loc_13810
000137D0 3D 80 00 1B loc_137D0:      lis       r12, 0x1B
000137D4 7C 03 60 40                 cmplw     r3, r12
000137D8 40 82 00 10                 bne       loc_137E8
000137DC 39 80 00 05                 li        r12, 5
000137E0 99 80 22 11                 stb       r12, setST
000137E4 48 00 00 2C                 b         loc_13810
000137E8 3D 80 00 0D loc_137E8:      lis       r12, 0xD
000137EC 7C 03 60 40                 cmplw     r3, r12
000137F0 40 82 00 18                 bne       loc_13808
000137F4 39 80 00 08                 li        r12, 8
000137F8 99 80 22 11                 stb       r12, setST
000137FC 39 60 00 00                 li        r11, 0
00013800 99 60 21 F1                 stb       r11, camDisable
00013804 48 00 00 10                 b         loc_13814
00013808 39 80 00 01 loc_13808:      li        r12, 1
0001380C 99 80 22 11                 stb       r12, setST
00013810 48 00 4B D5 loc_13810:      bl        cameraDisable 
00013814 89 80 22 11 loc_13814:      lbz       r12, setST
00013818 2C 0C 00 00                 cmpwi     r12, 0
0001381C 40 82 00 84                 bne       loc_138A0
00013820 81 80 21 AC loc_13820:      lwz       r12, shutterMode
00013824 2C 0C 00 03                 cmpwi     r12, 3
00013828 40 82 00 30                 bne       loc_13858
0001382C 89 80 21 E8                 lbz       r12, camSoft
00013830 2C 0C 00 00                 cmpwi     r12, 0
00013834 41 82 00 6C                 beq       loc_138A0
00013838 48 08 5E E5                 bl        timeUsec 
0001383C 81 60 21 A8                 lwz       r11, camSoftStartTime
00013840 7C 6B 18 50                 subf      r3, r11, r3
00013844 3D 40 00 03                 lis       r10, loc_30D40@h
00013848 61 4A 0D 40                 ori       r10, r10, loc_30D40@l
0001384C 7C 03 50 40                 cmplw     r3, r10
00013850 40 81 00 3C                 ble       loc_1388C
00013854 48 00 00 4C                 b         loc_138A0
00013858 81 80 21 AC loc_13858:      lwz       r12, shutterMode
0001385C 2C 0C 00 02                 cmpwi     r12, 2
00013860 40 82 00 40                 bne       loc_138A0
00013864 89 80 21 E8                 lbz       r12, camSoft
00013868 2C 0C 00 00                 cmpwi     r12, 0
0001386C 41 82 00 20                 beq       loc_1388C
00013870 48 08 5E AD                 bl        timeUsec 
00013874 81 60 21 A8                 lwz       r11, camSoftStartTime
00013878 7C 6B 18 50                 subf      r3, r11, r3
0001387C 3D 40 00 03                 lis       r10, loc_30D40@h
00013880 61 4A 0D 40                 ori       r10, r10, loc_30D40@l
00013884 7C 03 50 40                 cmplw     r3, r10
00013888 41 81 00 18                 bgt       loc_138A0
0001388C 39 80 00 08 loc_1388C:      li        r12, 8
00013890 99 80 22 11                 stb       r12, setST
00013894 39 60 00 00                 li        r11, 0
00013898 99 60 21 EA                 stb       r11, camEnable
0001389C 99 60 21 F1                 stb       r11, camDisable
000138A0 81 60 21 AC loc_138A0:      lwz       r11, shutterMode
000138A4 3D 40 00 01                 lis       r10, shutterModeMask@h
000138A8 61 4A 25 64                 ori       r10, r10, shutterModeMask@l
000138AC 7D 6A 58 AE                 lbzx      r11, r10, r11
000138B0 89 80 22 11                 lbz       r12, setST
000138B4 7D 6C 63 78                 or        r12, r11, r12
000138B8 99 80 22 11                 stb       r12, setST
000138BC 89 80 21 EE                 lbz       r12, camShutterOpenDigital
000138C0 2C 0C 00 00                 cmpwi     r12, 0
000138C4 41 82 00 7C                 beq       loc_13940
000138C8 89 80 21 ED                 lbz       r12, camShutterOpen
000138CC 2C 0C 00 00                 cmpwi     r12, 0
000138D0 40 82 00 70                 bne       loc_13940
000138D4 57 EC 00 1E                 clrrwi    r12, r31, 16  # r12 = r31 & 0xFFFF0000
000138D8 3D 60 00 0D                 lis       r11, 0xD
000138DC 7C 0C 58 40                 cmplw     r12, r11
000138E0 40 82 00 44                 bne       loc_13924
000138E4 57 EC 04 3E                 clrlwi    r12, r31, 16  # r12 = r31 & 0xFFFF
000138E8 28 0C 01 00                 cmplwi    r12, 0x100
000138EC 41 80 00 38                 blt       loc_13924
000138F0 48 08 5E 2D                 bl        timeUsec 
000138F4 81 80 20 A4                 lwz       r12, shutterCloseTime
000138F8 7C 6C 18 50                 subf      r3, r12, r3
000138FC 81 80 21 AC                 lwz       r12, shutterMode
00013900 2C 0C 00 00                 cmpwi     r12, 0
00013904 40 82 00 10                 bne       loc_13914
00013908 3D 60 01 31                 lis       r11, 0x1312D00@h
0001390C 61 6B 2D 00                 ori       r11, r11, 0x1312D00@l
00013910 48 00 00 0C                 b         loc_1391C
00013914 3D 60 00 6A loc_13914:      lis       r11, 0x6ACFC0@h
00013918 61 6B CF C0                 ori       r11, r11, 0x6ACFC0@l
0001391C 7C 03 58 40 loc_1391C:      cmplw     r3, r11
00013920 40 81 01 C4                 ble       loc_13AE4
00013924 89 80 21 DF loc_13924:      lbz       r12, camSettingsReceived
00013928 2C 0C 00 00                 cmpwi     r12, 0
0001392C 40 82 00 0C                 bne       loc_13938
00013930 3B C0 00 12                 li        r30, 0x12
00013934 48 00 01 B0                 b         loc_13AE4
00013938 3B C0 00 02 loc_13938:      li        r30, 2
0001393C 48 00 01 A8                 b         loc_13AE4
00013940 8B E0 21 E9 loc_13940:      lbz       r31, camAwake
00013944 2C 1F 00 00                 cmpwi     r31, 0
00013948 40 82 00 3C                 bne       loc_13984
0001394C 89 80 21 E6                 lbz       r12, camGet
00013950 2C 0C 00 00                 cmpwi     r12, 0
00013954 40 82 00 28                 bne       loc_1397C
00013958 89 80 21 E5                 lbz       r12, camSet
0001395C 2C 0C 00 00                 cmpwi     r12, 0
00013960 40 82 00 1C                 bne       loc_1397C
00013964 89 80 21 48                 lbz       r12, takePicture
00013968 2C 0C 00 00                 cmpwi     r12, 0
0001396C 40 82 00 10                 bne       loc_1397C
00013970 89 80 22 28                 lbz       r12, cameraWake
00013974 2C 0C 00 00                 cmpwi     r12, 0
00013978 41 82 00 0C                 beq       loc_13984
0001397C 3B C0 00 01 loc_1397C:      li        r30, 1
00013980 48 00 01 64                 b         loc_13AE4
00013984 2C 1F 00 00 loc_13984:      cmpwi     r31, 0
00013988 41 82 01 5C                 beq       loc_13AE4
0001398C 89 80 21 EC                 lbz       r12, camShutterArm
00013990 2C 0C 00 00                 cmpwi     r12, 0
00013994 40 82 01 50                 bne       loc_13AE4
00013998 89 80 21 ED                 lbz       r12, camShutterOpen
0001399C 2C 0C 00 00                 cmpwi     r12, 0
000139A0 40 82 01 44                 bne       loc_13AE4
000139A4 8B E0 21 F2                 lbz       r31, camReply
000139A8 2C 1F 00 00                 cmpwi     r31, 0
000139AC 41 82 00 0C                 beq       loc_139B8
000139B0 3B DF 00 00                 addi      r30, r31, 0
000139B4 48 00 01 30                 b         loc_13AE4
000139B8 89 80 21 EB loc_139B8:      lbz       r12, camEnabled
000139BC 89 60 21 EA                 lbz       r11, camEnable
000139C0 7C 0C 58 00                 cmpw      r12, r11
000139C4 41 82 00 30                 beq       loc_139F4
000139C8 81 80 21 E0                 lwz       r12, backMessageCount
000139CC 28 0C 00 02                 cmplwi    r12, 2
000139D0 41 80 00 24                 blt       loc_139F4
000139D4 89 80 21 DD                 lbz       r12, digitalBody
000139D8 2C 0C 00 00                 cmpwi     r12, 0
000139DC 40 82 00 10                 bne       loc_139EC
000139E0 89 80 21 E8                 lbz       r12, camSoft
000139E4 2C 0C 00 00                 cmpwi     r12, 0
000139E8 41 82 00 0C                 beq       loc_139F4
000139EC 3B C0 00 01 loc_139EC:      li        r30, 1
000139F0 48 00 00 F4                 b         loc_13AE4
000139F4 89 80 21 DD loc_139F4:      lbz       r12, digitalBody
000139F8 2C 0C 00 00                 cmpwi     r12, 0
000139FC 41 82 00 E8                 beq       loc_13AE4
00013A00 81 80 21 E0                 lwz       r12, backMessageCount
00013A04 28 0C 00 03                 cmplwi    r12, 3
00013A08 40 81 00 DC                 ble       loc_13AE4
00013A0C 89 80 21 E8                 lbz       r12, camSoft
00013A10 2C 0C 00 00                 cmpwi     r12, 0
00013A14 41 82 00 20                 beq       loc_13A34
00013A18 48 08 5D 05                 bl        timeUsec 
00013A1C 81 80 21 CC                 lwz       r12, releaseMessageTime
00013A20 7C 6C 18 50                 subf      r3, r12, r3
00013A24 3D 60 00 7A                 lis       r11, 0x7A # 0x7A1200 # 'z'
00013A28 61 6B 12 00                 ori       r11, r11, 0x1200 # 0x7A1200
00013A2C 7C 03 58 40                 cmplw     r3, r11
00013A30 40 81 00 40                 ble       loc_13A70
00013A34 89 80 21 E6 loc_13A34:      lbz       r12, camGet
00013A38 2C 0C 00 00                 cmpwi     r12, 0
00013A3C 40 82 00 28                 bne       loc_13A64
00013A40 89 80 21 E5                 lbz       r12, camSet
00013A44 2C 0C 00 00                 cmpwi     r12, 0
00013A48 40 82 00 1C                 bne       loc_13A64
00013A4C 89 80 21 48                 lbz       r12, takePicture
00013A50 2C 0C 00 00                 cmpwi     r12, 0
00013A54 40 82 00 10                 bne       loc_13A64
00013A58 89 80 22 28                 lbz       r12, cameraWake
00013A5C 2C 0C 00 00                 cmpwi     r12, 0
00013A60 41 82 00 10                 beq       loc_13A70
00013A64 39 80 00 01 loc_13A64:      li        r12, 1
00013A68 99 80 22 19                 stb       r12, setRE
00013A6C 48 00 00 74                 b         loc_13AE0
00013A70 89 80 21 E6 loc_13A70:      lbz       r12, camGet
00013A74 2C 0C 00 00                 cmpwi     r12, 0
00013A78 40 82 00 10                 bne       loc_13A88
00013A7C 89 80 21 E5                 lbz       r12, camSet
00013A80 2C 0C 00 00                 cmpwi     r12, 0
00013A84 41 82 00 0C                 beq       loc_13A90
00013A88 3B C0 00 13 loc_13A88:      li        r30, 0x13
00013A8C 48 00 00 58                 b         loc_13AE4
00013A90 89 80 21 48 loc_13A90:      lbz       r12, takePicture
00013A94 2C 0C 00 00                 cmpwi     r12, 0
00013A98 41 82 00 34                 beq       loc_13ACC
00013A9C 89 80 21 F0                 lbz       r12, camTakeRequested
00013AA0 2C 0C 00 00                 cmpwi     r12, 0
00013AA4 40 82 00 28                 bne       loc_13ACC
00013AA8 89 80 21 EB                 lbz       r12, camEnabled
00013AAC 2C 0C 00 00                 cmpwi     r12, 0
00013AB0 41 82 00 1C                 beq       loc_13ACC
00013AB4 89 80 21 E8                 lbz       r12, camSoft
00013AB8 2C 0C 00 00                 cmpwi     r12, 0
00013ABC 41 82 00 10                 beq       loc_13ACC
00013AC0 39 80 00 03                 li        r12, 3
00013AC4 99 80 22 19                 stb       r12, setRE
00013AC8 48 00 00 18                 b         loc_13AE0
00013ACC 89 80 21 E7 loc_13ACC:      lbz       r12, camClearRequest
00013AD0 2C 0C 00 00                 cmpwi     r12, 0
00013AD4 41 82 00 10                 beq       loc_13AE4
00013AD8 39 80 00 00                 li        r12, 0
00013ADC 99 80 22 19                 stb       r12, setRE
00013AE0 3B C0 00 04 loc_13AE0:      li        r30, 4
00013AE4 57 C3 06 3E loc_13AE4:      clrlwi    r3, r30, 24
00013AE8 83 C1 00 10                 lwz       r30, 0x18+var_8(r1)
00013AEC 83 E1 00 14                 lwz       r31, 0x18+var_4(r1)
00013AF0 80 01 00 1C                 lwz       r0, 0x18+arg_4(r1)
00013AF4 7C 08 03 A6                 mtlr      r0
00013AF8 38 21 00 18                 addi      r1, r1, 0x18
00013AFC 4E 80 00 20                 blr
00013B00 00 00 00 00
00013B04 00 00 00 00
00013B08 00 00 00 00
00013B0C 00 00 00 00
00013B10 00 00 00 00
00013B14 00 00 00 00
00013B18 00 00 00 00
00013B1C 00 00 00 00
00013B20 00 00 00 00
00013B24 00 00 00 00
00013B28 00 00 00 00
00013B2C 00 00 00 00
00013B30 00 00 00 00
00013B34
00013B38
00013B3C
00013B40
00013B44
00013B48
00013B4C
00013B50
00013B54
00013B58
00013B5C
00013B60
00013B64
00013B68
00013B6C
00013B70
00013B74
00013B78
00013B7C
00013B80
00013B84
00013B88
00013B8C