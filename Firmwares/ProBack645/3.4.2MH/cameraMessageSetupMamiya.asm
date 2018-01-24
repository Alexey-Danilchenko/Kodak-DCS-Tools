cameraMessageSetupMamiya
00013240 94 21 FF E8                 stwu      r1,
00013244 7C 08 02 A6                 mflr      r0
00013248 93 C1 00 10                 stw       r30, 0x18+var_8(r1)
0001324C 93 E1 00 14                 stw       r31, 0x18+var_4(r1)
00013250 90 01 00 1C                 stw       r0, 0x18+arg_4(r1)
00013254 3B E3 00 00                 addi      r31, r3, 0
00013258 3B C0 00 00                 li        r30, 0
0001325C 89 60 21 DD                 lbz       r11, digitalBody
00013260 2C 0B 00 00                 cmpwi     r11, 0
00013264 41 82 01 A8                 beq       loc_1340C
00013268 89 80 21 ED                 lbz       r12, camShutterOpen
0001326C 2C 0C 00 00                 cmpwi     r12, 0
00013270 41 82 01 9C                 beq       loc_1340C
00013274 81 80 21 AC                 lwz       r12, shutterMode
00013278 2C 0C 00 00                 cmpwi     r12, 0
0001327C 40 82 00 68                 bne       loc_132E4
00013280 81 80 21 BC                 lwz       r12, exposureTime
00013284 2C 0C 00 00                 cmpwi     r12, 0
00013288 41 82 01 84                 beq       loc_1340C
0001328C 81 80 20 A0                 lwz       r12, shutterOpenTime
00013290 2C 0C 00 00                 cmpwi     r12, 0
00013294 41 82 01 78                 beq       loc_1340C
00013298 48 08 64 85                 bl        timeUsec 
0001329C 81 80 20 A0                 lwz       r12, shutterOpenTime
000132A0 7C 6C 18 50                 subf      r3, r12, r3
000132A4 81 60 21 BC                 lwz       r11, exposureTime
000132A8 3D 40 00 01                 lis       r10, loc_186A0@h
000132AC 61 4A 86 A0                 ori       r10, r10, loc_186A0@l
000132B0 7D 6B 52 14                 add       r11, r11, r10
000132B4 7C 03 58 40                 cmplw     r3, r11
000132B8 40 81 01 54                 ble       loc_1340C
000132BC 48 00 45 D9                 bl        cameraShutterCloseCommon 
000132C0 38 60 00 06                 li        r3, SHUTTER_CLOSE
000132C4 38 80 00 00                 li        r4, 0
000132C8 38 A0 00 00                 li        r5, 0
000132CC 48 02 A6 AD                 bl        eventPost 
000132D0 39 20 00 00                 li        r9, 0
000132D4 99 20 21 ED                 stb       r9, camShutterOpen
000132D8 48 08 64 45                 bl        timeUsec 
000132DC 90 60 20 A4                 stw       r3, shutterCloseTime
000132E0 48 00 01 2C                 b         loc_1340C
000132E4 81 80 20 A0 loc_132E4:      lwz       r12, shutterOpenTime
000132E8 2C 0C 00 00                 cmpwi     r12, 0
000132EC 40 82 00 AC                 bne       loc_13398
000132F0 3D 60 20 00                 lis       r11, IMMR@h
000132F4 81 8B 0A C4                 lwz       r12, 0xAC4(r11)
000132F8 55 8C 07 7B                 rlwinm.   r12, r12, 0,29,29 # r12 = r12 & 4
000132FC 41 82 07 AC                 beq       loc_13AA8
00013300 81 80 21 AC                 lwz       r12, shutterMode
00013304 2C 0C 00 01                 cmpwi     r12, 1
00013308 40 82 00 7C                 bne       loc_13384
0001330C 4B FF F6 79                 bl        cameraSoftPress 
00013310 3C 60 00 04                 lis       r3, 493E0@h
00013314 60 63 93 E0                 ori       r3, r3, 493E0@l
00013318 48 08 65 A1                 bl        waitUsec 
0001331C 39 80 00 01                 li        r12, 1
00013320 99 80 21 EC                 stb       r12, camShutterArm
00013324 38 60 00 00                 li        r3, 0
00013328 98 60 21 ED                 stb       r3, camShutterOpen
0001332C 98 60 21 EE                 stb       r3, camShutterOpenDigital
00013330 38 60 00 04                 li        r3, SHUTTER_WARNING # event SHUTTER_WARNING
00013334 38 80 00 00                 li        r4, 0
00013338 38 A0 00 00                 li        r5, 0
0001333C 48 02 A6 3D                 bl        eventPost 
00013340 3C 60 00 00                 lis       r3, C350@h
00013344 60 63 C3 50                 ori       r3, r3, C350@l
00013348 48 08 65 71                 bl        waitUsec 
0001334C 38 60 00 00                 li        r3, 0
00013350 90 60 20 A4                 stw       r3, shutterCloseTime
00013354 98 60 21 EC                 stb       r3, camShutterArm
00013358 98 60 21 F0                 stb       r3, camTakeRequested
0001335C 98 60 21 48                 stb       r3, takePicture
00013360 38 60 00 01                 li        r30, 1
00013364 98 60 21 ED                 stb       r30, camShutterOpen
00013368 98 60 21 EE                 stb       r30, camShutterOpenDigital
0001336C 98 60 20 99                 stb       r30, takePictureDone
00013370 48 00 44 51                 bl        cameraShutterOpenCommon 
00013374 38 60 00 05                 li        r3, 5
00013378 38 80 00 00                 li        r4, 0
0001337C 38 A0 00 00                 li        r5, 0
00013380 48 02 A5 F9                 bl        eventPost 
00013384 48 08 63 99 loc_13384:      bl        timeUsec 
00013388 90 60 20 A0                 stw       r3, shutterOpenTime
0001338C 39 80 00 00                 li        r12, 0
00013390 99 80 21 DF                 stb       r12, camSettingsReceived
00013394 48 00 00 78                 b         loc_1340C
00013398 81 80 20 A4 loc_13398:      lwz       r12, shutterCloseTime
0001339C 2C 0C 00 00                 cmpwi     r12, 0
000133A0 40 82 00 20                 bne       loc_133C0
000133A4 3D 60 20 00                 lis       r11, IMMR@h
000133A8 81 8B 0A C4                 lwz       r12, 0xAC4(r11)
000133AC 55 8C 07 7B                 rlwinm.   r12, r12, 0,29,29 # r12 = r12 & 4
000133B0 40 82 00 5C                 bne       loc_1340C
000133B4 48 08 63 69                 bl        timeUsec 
000133B8 90 60 20 A4                 stw       r3, shutterCloseTime
000133BC 48 00 00 50                 b         loc_1340C
000133C0 81 60 21 BC loc_133C0:      lwz       r11, exposureTime
000133C4 2C 0B 00 00                 cmpwi     r11, 0
000133C8 41 82 00 28                 beq       loc_133F0
000133CC 48 08 63 51                 bl        timeUsec 
000133D0 81 80 20 A0                 lwz       r12, shutterOpenTime
000133D4 7C 6C 18 50                 subf      r3, r12, r3
000133D8 81 60 21 BC                 lwz       r11, exposureTime
000133DC 3D 40 00 01                 lis       r10, 15F90@h
000133E0 61 4A 5F 90                 ori       r10, r10, 15F90@l
000133E4 7D 6B 52 14                 add       r11, r11, r10
000133E8 7C 03 58 40                 cmplw     r3, r11
000133EC 41 80 00 20                 blt       loc_1340C
000133F0 48 00 44 A5 loc_133F0:      bl        cameraShutterCloseCommon 
000133F4 38 60 00 06                 li        r3, 6
000133F8 38 80 00 00                 li        r4, 0
000133FC 38 A0 00 00                 li        r5, 0
00013400 48 02 A5 79                 bl        eventPost 
00013404 39 20 00 00                 li        r9, 0
00013408 99 20 21 ED                 stb       r9, camShutterOpen
0001340C 81 80 21 AC loc_1340C:      lwz       r12, shutterMode
00013410 2C 0C 00 00                 cmpwi     r12, 0
00013414 41 82 00 0C                 beq       loc_13420
00013418 2C 0C 00 02                 cmpwi     r12, 2
0001341C 40 82 00 7C                 bne       loc_13498
00013420 89 80 21 E8 loc_13420:      lbz       r12, camSoft
00013424 2C 0C 00 00                 cmpwi     r12, 0
00013428 41 82 00 70                 beq       loc_13498
0001342C 89 80 21 ED                 lbz       r12, camShutterOpen
00013430 2C 0C 00 00                 cmpwi     r12, 0
00013434 40 82 00 64                 bne       loc_13498
00013438 89 80 21 EE                 lbz       r12, camShutterOpenDigital
0001343C 2C 0C 00 00                 cmpwi     r12, 0
00013440 40 82 00 58                 bne       loc_13498
00013444 48 08 62 D9                 bl        timeUsec 
00013448 81 80 21 C4                 lwz       r12, lastMessageTime
0001344C 7C 6C 18 50                 subf      r3, r12, r3
00013450 89 60 21 B2                 lbz       r11, curCamSoftOnTime
00013454 55 6B 10 3A                 slwi      r11, r11, 2   # r11 = r11 << 2
00013458 3D 40 00 01                 lis       r10, camSoftOnTimes@h
0001345C 61 4A 25 58                 ori       r10, r10, camSoftOnTimes@l
00013460 7D 6A 58 2E                 lwzx      r11, r10, r11
00013464 7C 03 58 40                 cmplw     r3, r11
00013468 40 81 00 30                 ble       loc_13498
0001346C 39 80 00 00                 li        r12, 0
00013470 99 80 21 E8                 stb       r12, camSoft
00013474 38 60 00 0A                 li        r3, 0xA
00013478 38 80 00 00                 li        r4, 0
0001347C 38 A0 00 00                 li        r5, 0
00013480 48 02 A4 F9                 bl        eventPost 
00013484 48 04 E1 F5                 bl        imageSafeSet 
00013488 38 60 00 03                 li        r3, 3
0001348C 38 80 00 00                 li        r4, 0
00013490 38 A0 00 00                 li        r5, 0
00013494 48 02 A4 E5                 bl        eventPost 
00013498 81 80 21 AC loc_13498:      lwz       r12, shutterMode
0001349C 2C 0C 00 01                 cmpwi     r12, 1
000134A0 40 82 00 58                 bne       loc_134F8
000134A4 89 80 21 E8                 lbz       r12, camSoft
000134A8 2C 0C 00 00                 cmpwi     r12, 0
000134AC 41 82 00 4C                 beq       loc_134F8
000134B0 89 80 21 ED                 lbz       r12, camShutterOpen
000134B4 2C 0C 00 00                 cmpwi     r12, 0
000134B8 40 82 00 40                 bne       loc_134F8
000134BC 89 80 21 EE                 lbz       r12, camShutterOpenDigital
000134C0 2C 0C 00 00                 cmpwi     r12, 0
000134C4 40 82 00 34                 bne       loc_134F8
000134C8 39 80 00 00                 li        r12, 0
000134CC 99 80 21 E8                 stb       r12, camSoft
000134D0 38 60 00 0A                 li        r3, 0xA
000134D4 38 80 00 00                 li        r4, 0
000134D8 38 A0 00 00                 li        r5, 0
000134DC 48 02 A4 9D                 bl        eventPost 
000134E0 48 04 E1 99                 bl        imageSafeSet 
000134E4 38 60 00 03                 li        r3, 3
000134E8 38 80 00 00                 li        r4, 0
000134EC 38 A0 00 00                 li        r5, 0
000134F0 48 02 A4 89                 bl        eventPost 
000134F4 48 00 03 70                 b         loc_13864
000134F8 48 00 4F 75 loc_134F8:      bl        cameraDialogCheck 
000134FC 81 80 21 E0                 lwz       r12, backMessageCount
00013500 28 0C 00 04                 cmplwi    r12, 4
00013504 40 81 00 8C                 ble       loc_13590
00013508 89 80 21 DD                 lbz       r12, digitalBody
0001350C 2C 0C 00 00                 cmpwi     r12, 0
00013510 40 82 00 80                 bne       loc_13590
00013514 89 80 21 48                 lbz       r12, takePicture
00013518 2C 0C 00 00                 cmpwi     r12, 0
0001351C 41 82 00 64                 beq       loc_13580
00013520 89 80 20 98                 lbz       r12, takePictureHost
00013524 2C 0C 00 00                 cmpwi     r12, 0
00013528 41 82 00 18                 beq       loc_13540
0001352C 38 60 00 39                 li        r3, 0x39 # '9'
00013530 38 80 00 00                 li        r4, 0
00013534 3C A0 00 3A                 lis       r5, 0x3A # ':'
00013538 48 02 A4 41                 bl        eventPost 
0001353C 48 00 00 38                 b         loc_13574
00013540 39 80 00 00 loc_13540:      li        r12, 0
00013544 91 81 00 08                 stw       r12, 0x18+var_10(r1)
00013548 3C 60 00 02                 lis       r3, unk_1C6A0@ha
0001354C 38 63 C6 A0                 addi      r3, r3, unk_1C6A0@l
00013550 3C 80 00 02                 lis       r4, dword_1C6DC@ha
00013554 38 84 C6 DC                 addi      r4, r4, dword_1C6DC@l
00013558 38 A0 00 00                 li        r5, 0
0001355C 38 C0 00 00                 li        r6, 0
00013560 38 E0 00 00                 li        r7, 0
00013564 39 00 00 00                 li        r8, 0
00013568 39 20 00 00                 li        r9, 0
0001356C 39 40 00 00                 li        r10, 0
00013570 48 08 C5 B5                 bl        userDialog 
00013574 3B E0 00 00 loc_13574:      li        r31, 0
00013578 9B E0 21 F0                 stb       r31, camTakeRequested
0001357C 9B E0 21 48                 stb       r31, takePicture
00013580 3B E0 00 00 loc_13580:      li        r31, 0
00013584 9B E0 21 E6                 stb       r31, camGet
00013588 9B E0 21 E5                 stb       r31, camSet
0001358C 48 00 01 14                 b         loc_136A0
00013590 28 1F 00 0A loc_13590:      cmplwi    r31, 0xA
00013594 40 81 00 74                 ble       loc_13608
00013598 89 80 21 48                 lbz       r12, takePicture
0001359C 2C 0C 00 00                 cmpwi     r12, 0
000135A0 41 82 01 00                 beq       loc_136A0
000135A4 89 80 20 98                 lbz       r12, takePictureHost
000135A8 2C 0C 00 00                 cmpwi     r12, 0
000135AC 41 82 00 18                 beq       loc_135C4
000135B0 38 60 00 39                 li        r3, 0x39 # '9'
000135B4 38 80 00 00                 li        r4, 0
000135B8 3C A0 00 31                 lis       r5, 0x31 # '1'
000135BC 48 02 A3 BD                 bl        eventPost 
000135C0 48 00 00 38                 b         loc_135F8
000135C4 39 80 00 00 loc_135C4:      li        r12, 0
000135C8 91 81 00 08                 stw       r12, 0x18+var_10(r1)
000135CC 3C 60 00 02                 lis       r3, unk_1C6E0@ha
000135D0 38 63 C6 E0                 addi      r3, r3, unk_1C6E0@l
000135D4 3C 80 00 02                 lis       r4, dword_1C6DC@ha
000135D8 38 84 C6 DC                 addi      r4, r4, dword_1C6DC@l
000135DC 38 A0 00 00                 li        r5, 0
000135E0 38 C0 00 00                 li        r6, 0
000135E4 38 E0 00 00                 li        r7, 0
000135E8 39 00 00 00                 li        r8, 0
000135EC 39 20 00 00                 li        r9, 0
000135F0 39 40 00 00                 li        r10, 0
000135F4 48 08 C5 31                 bl        userDialog 
000135F8 3B E0 00 00 loc_135F8:      li        r31, 0
000135FC 9B E0 21 F0                 stb       r31, camTakeRequested
00013600 9B E0 21 48                 stb       r31, takePicture
00013604 48 00 00 9C                 b         loc_136A0
00013608 89 80 21 48 loc_13608:      lbz       r12, takePicture
0001360C 2C 0C 00 00                 cmpwi     r12, 0
00013610 41 82 00 90                 beq       loc_136A0
00013614 89 80 21 F0                 lbz       r12, camTakeRequested
00013618 2C 0C 00 00                 cmpwi     r12, 0
0001361C 41 82 00 84                 beq       loc_136A0
00013620 48 08 60 FD                 bl        timeUsec 
00013624 81 80 21 CC                 lwz       r12, releaseMessageTime
00013628 7C 6C 18 50                 subf      r3, r12, r3
0001362C 3D 60 00 4C                 lis       r11, 0x4C # 0x4C4B40 # 'L'
00013630 61 6B 4B 40                 ori       r11, r11, 0x4B40 # 0x4C4B40
00013634 7C 03 58 40                 cmplw     r3, r11
00013638 40 81 00 68                 ble       loc_136A0
0001363C 38 60 00 C7                 li        r3, 0xC7 # 'Ã'
00013640 38 80 00 00                 li        r4, 0
00013644 3C A0 00 36                 lis       r5, 0x36 # '6'
00013648 48 02 A3 31                 bl        eventPost 
0001364C 89 20 20 98                 lbz       r9, takePictureHost
00013650 2C 09 00 00                 cmpwi     r9, 0
00013654 40 82 00 38                 bne       loc_1368C
00013658 39 80 00 10                 li        r12, 0x10
0001365C 91 81 00 08                 stw       r12, 0x18+var_10(r1)
00013660 3C 60 00 02                 lis       r3, unk_1C704@ha
00013664 38 63 C7 04                 addi      r3, r3, unk_1C704@l
00013668 3C 80 00 02                 lis       r4, dword_1C6DC@ha
0001366C 38 84 C6 DC                 addi      r4, r4, dword_1C6DC@l
00013670 38 A0 00 00                 li        r5, 0
00013674 38 C0 00 00                 li        r6, 0
00013678 38 E0 00 00                 li        r7, 0
0001367C 39 00 00 00                 li        r8, 0
00013680 39 20 00 00                 li        r9, 0
00013684 39 40 00 00                 li        r10, 0
00013688 48 08 C4 9D                 bl        userDialog 
0001368C 3B E0 00 00 loc_1368C:      li        r31, 0
00013690 9B E0 21 F0                 stb       r31, camTakeRequested
00013694 9B E0 21 48                 stb       r31, takePicture
00013698 39 60 00 01                 li        r11, 1
0001369C 99 60 21 E7                 stb       r11, camClearRequest
000136A0 81 80 21 F4 loc_136A0:      lwz       r12, cameraMinIso
000136A4 81 60 22 24                 lwz       r11, cameraIso
000136A8 7D 8C 5A 14                 add       r12, r12, r11
000136AC 55 9F 20 36                 slwi      r31, r12, 4   # r31 = r12 << 4
000136B0 3D 40 00 02                 lis       r10, listIso@ha
000136B4 39 4A 8F 6C                 addi      r10, r10, listIso@l
000136B8 7D 4A F8 AE                 lbzx      r10, r10, r31
000136BC 99 40 58 22                 stb       r10, byte_5822
000136C0 3D 60 00 02                 lis       r11, listIsoSet@ha
000136C4 39 6B 91 0C                 addi      r11, r11, listIsoSet@l
000136C8 7D 6B F8 AE                 lbzx      r11, r11, r31
000136CC 99 60 22 15                 stb       r11, setISO
000136D0 89 80 21 E8                 lbz       r12, camSoft
000136D4 2C 0C 00 00                 cmpwi     r12, 0
000136D8 38 80 00 01                 li        r4, 1
000136DC 41 82 00 08                 beq       loc_136E4
000136E0 38 80 00 00                 li        r4, 0
000136E4 89 80 21 DD loc_136E4:      lbz       r12, digitalBody
000136E8 2C 0C 00 00                 cmpwi     r12, 0
000136EC 40 82 00 1C                 bne       loc_13708
000136F0 81 80 21 AC                 lwz       r12, shutterMode
000136F4 2C 0C 00 00                 cmpwi     r12, 0
000136F8 40 82 00 10                 bne       loc_13708
000136FC 3C 60 00 01                 lis       r3, loc_11170@h
00013700 60 63 11 70                 ori       r3, r3, loc_11170@l
00013704 48 00 00 0C                 b         loc_13710
00013708 3C 60 00 04 loc_13708:      lis       r3, loc_493E0@h
0001370C 60 63 93 E0                 ori       r3, r3, loc_493E0@l
00013710 48 04 DE DD loc_13710:      bl        imageOkToTakePicture 
00013714 3B E3 00 00                 addi      r31, r3, 0
00013718 2C 1F 00 00 loc_13718:      cmpwi     r31, 0
0001371C 41 82 00 10                 beq       loc_1372C
00013720 89 80 21 E4                 lbz       r12, alwaysEnable
00013724 2C 0C 00 00                 cmpwi     r12, 0
00013728 41 82 00 2C                 beq       loc_13754
0001372C 39 80 00 01 loc_1372C:      li        r12, 1
00013730 99 80 21 EA                 stb       r12, camEnable
00013734 38 60 58 20                 li        r3, 0x5820
00013738 89 43 00 04                 lbz       r10, 4(r3)
0001373C 55 4A 07 FA                 rlwinm    r10, r10, 0,31,29 # r10 = r10 & 0xFFFFFFFD
00013740 99 43 00 04                 stb       r10, 4(r3)
00013744 38 60 00 00                 li        r3, 0
00013748 98 60 22 11                 stb       r3, setST
0001374C 98 60 21 F1                 stb       r3, camDisable
00013750 48 00 00 88                 b         loc_137D8
00013754 39 80 00 00 loc_13754:      li        r12, 0
00013758 99 80 21 EA                 stb       r12, camEnable
0001375C 38 60 58 20                 li        r3, 0x5820
00013760 89 43 00 04                 lbz       r10, 4(r3)
00013764 61 4A 00 02                 ori       r10, r10, 2
00013768 99 43 00 04                 stb       r10, 4(r3)
0001376C 57 E3 00 1E                 clrrwi    r3, r31, 16   # r3 = r31 & 0xFFFF0000
00013770 3D 60 00 12                 lis       r11, 0x12
00013774 7C 03 58 40                 cmplw     r3, r11
00013778 41 82 00 10                 beq       loc_13788
0001377C 3D 80 00 22                 lis       r12, 0x22 # '"'
00013780 7C 03 60 40                 cmplw     r3, r12
00013784 40 82 00 10                 bne       loc_13794
00013788 39 80 00 03 loc_13788:      li        r12, 3
0001378C 99 80 22 11                 stb       r12, setST
00013790 48 00 00 44                 b         loc_137D4
00013794 3D 80 00 1B loc_13794:      lis       r12, 0x1B
00013798 7C 03 60 40                 cmplw     r3, r12
0001379C 40 82 00 10                 bne       loc_137AC
000137A0 39 80 00 05                 li        r12, 5
000137A4 99 80 22 11                 stb       r12, setST
000137A8 48 00 00 2C                 b         loc_137D4
000137AC 3D 80 00 0D loc_137AC:      lis       r12, 0xD
000137B0 7C 03 60 40                 cmplw     r3, r12
000137B4 40 82 00 18                 bne       loc_137CC
000137B8 39 80 00 08                 li        r12, 8
000137BC 99 80 22 11                 stb       r12, setST
000137C0 39 60 00 00                 li        r11, 0
000137C4 99 60 21 F1                 stb       r11, camDisable
000137C8 48 00 00 10                 b         loc_137D8
000137CC 39 80 00 01 loc_137CC:      li        r12, 1
000137D0 99 80 22 11                 stb       r12, setST
000137D4 48 00 4C 11 loc_137D4:      bl        cameraDisable 
000137D8 89 80 22 11 loc_137D8:      lbz       r12, setST
000137DC 2C 0C 00 00                 cmpwi     r12, 0
000137E0 40 82 00 84                 bne       loc_13864
000137E4 81 80 21 AC loc_137E4:      lwz       r12, shutterMode
000137E8 2C 0C 00 03                 cmpwi     r12, 3
000137EC 40 82 00 30                 bne       loc_1381C
000137F0 89 80 21 E8                 lbz       r12, camSoft
000137F4 2C 0C 00 00                 cmpwi     r12, 0
000137F8 41 82 00 6C                 beq       loc_13864
000137FC 48 08 5F 21                 bl        timeUsec 
00013800 81 60 21 A8                 lwz       r11, camSoftStartTime
00013804 7C 6B 18 50                 subf      r3, r11, r3
00013808 3D 40 00 03                 lis       r10, loc_30D40@h
0001380C 61 4A 0D 40                 ori       r10, r10, loc_30D40@l
00013810 7C 03 50 40                 cmplw     r3, r10
00013814 40 81 00 3C                 ble       loc_13850
00013818 48 00 00 4C                 b         loc_13864
0001381C 81 80 21 AC loc_1381C:      lwz       r12, shutterMode
00013820 2C 0C 00 02                 cmpwi     r12, 2
00013824 40 82 00 40                 bne       loc_13864
00013828 89 80 21 E8                 lbz       r12, camSoft
0001382C 2C 0C 00 00                 cmpwi     r12, 0
00013830 41 82 00 20                 beq       loc_13850
00013834 48 08 5E E9                 bl        timeUsec 
00013838 81 60 21 A8                 lwz       r11, camSoftStartTime
0001383C 7C 6B 18 50                 subf      r3, r11, r3
00013840 3D 40 00 03                 lis       r10, loc_30D40@h
00013844 61 4A 0D 40                 ori       r10, r10, loc_30D40@l
00013848 7C 03 50 40                 cmplw     r3, r10
0001384C 41 81 00 18                 bgt       loc_13864
00013850 39 80 00 08 loc_13850:      li        r12, 8
00013854 99 80 22 11                 stb       r12, setST
00013858 39 60 00 00                 li        r11, 0
0001385C 99 60 21 EA                 stb       r11, camEnable
00013860 99 60 21 F1                 stb       r11, camDisable
00013864 81 60 21 AC loc_13864:      lwz       r11, shutterMode
00013868 3D 40 00 01                 lis       r10, shutterModeMask@h
0001386C 61 4A 47 A0                 ori       r10, r10, shutterModeMask@l
00013870 7D 6A 58 AE                 lbzx      r11, r10, r11
00013874 89 80 22 11                 lbz       r12, setST
00013878 7D 6C 63 78                 or        r12, r11, r12
0001387C 99 80 22 11                 stb       r12, setST
00013880 89 80 21 EE                 lbz       r12, camShutterOpenDigital
00013884 2C 0C 00 00                 cmpwi     r12, 0
00013888 41 82 00 7C                 beq       loc_13904
0001388C 89 80 21 ED                 lbz       r12, camShutterOpen
00013890 2C 0C 00 00                 cmpwi     r12, 0
00013894 40 82 00 70                 bne       loc_13904
00013898 57 EC 00 1E                 clrrwi    r12, r31, 16  # r12 = r31 & 0xFFFF0000
0001389C 3D 60 00 0D                 lis       r11, 0xD
000138A0 7C 0C 58 40                 cmplw     r12, r11
000138A4 40 82 00 44                 bne       loc_138E8
000138A8 57 EC 04 3E                 clrlwi    r12, r31, 16  # r12 = r31 & 0xFFFF
000138AC 28 0C 01 00                 cmplwi    r12, 0x100
000138B0 41 80 00 38                 blt       loc_138E8
000138B4 48 08 5E 69                 bl        timeUsec 
000138B8 81 80 20 A4                 lwz       r12, shutterCloseTime
000138BC 7C 6C 18 50                 subf      r3, r12, r3
000138C0 81 80 21 AC                 lwz       r12, shutterMode
000138C4 2C 0C 00 00                 cmpwi     r12, 0
000138C8 40 82 00 10                 bne       loc_138D8
000138CC 3D 60 01 31                 lis       r11, 0x1312D00@h
000138D0 61 6B 2D 00                 ori       r11, r11, 0x1312D00@l
000138D4 48 00 00 0C                 b         loc_138E0
000138D8 3D 60 00 6A loc_138D8:      lis       r11, 0x6ACFC0@h
000138DC 61 6B CF C0                 ori       r11, r11, 0x6ACFC0@l
000138E0 7C 03 58 40 loc_138E0:      cmplw     r3, r11
000138E4 40 81 01 C4                 ble       loc_13AA8
000138E8 89 80 21 DF loc_138E8:      lbz       r12, camSettingsReceived
000138EC 2C 0C 00 00                 cmpwi     r12, 0
000138F0 40 82 00 0C                 bne       loc_138FC
000138F4 3B C0 00 12                 li        r30, 0x12
000138F8 48 00 01 B0                 b         loc_13AA8
000138FC 3B C0 00 02 loc_138FC:      li        r30, 2
00013900 48 00 01 A8                 b         loc_13AA8
00013904 8B E0 21 E9 loc_13904:      lbz       r31, camAwake
00013908 2C 1F 00 00                 cmpwi     r31, 0
0001390C 40 82 00 3C                 bne       loc_13948
00013910 89 80 21 E6                 lbz       r12, camGet
00013914 2C 0C 00 00                 cmpwi     r12, 0
00013918 40 82 00 28                 bne       loc_13940
0001391C 89 80 21 E5                 lbz       r12, camSet
00013920 2C 0C 00 00                 cmpwi     r12, 0
00013924 40 82 00 1C                 bne       loc_13940
00013928 89 80 21 48                 lbz       r12, takePicture
0001392C 2C 0C 00 00                 cmpwi     r12, 0
00013930 40 82 00 10                 bne       loc_13940
00013934 89 80 22 28                 lbz       r12, cameraWake
00013938 2C 0C 00 00                 cmpwi     r12, 0
0001393C 41 82 00 0C                 beq       loc_13948
00013940 3B C0 00 01 loc_13940:      li        r30, 1
00013944 48 00 01 64                 b         loc_13AA8
00013948 2C 1F 00 00 loc_13948:      cmpwi     r31, 0
0001394C 41 82 01 5C                 beq       loc_13AA8
00013950 89 80 21 EC                 lbz       r12, camShutterArm
00013954 2C 0C 00 00                 cmpwi     r12, 0
00013958 40 82 01 50                 bne       loc_13AA8
0001395C 89 80 21 ED                 lbz       r12, camShutterOpen
00013960 2C 0C 00 00                 cmpwi     r12, 0
00013964 40 82 01 44                 bne       loc_13AA8
00013968 8B E0 21 F2                 lbz       r31, camReply
0001396C 2C 1F 00 00                 cmpwi     r31, 0
00013970 41 82 00 0C                 beq       loc_1397C
00013974 3B DF 00 00                 addi      r30, r31, 0
00013978 48 00 01 30                 b         loc_13AA8
0001397C 89 80 21 EB loc_1397C:      lbz       r12, camEnabled
00013980 89 60 21 EA                 lbz       r11, camEnable
00013984 7C 0C 58 00                 cmpw      r12, r11
00013988 41 82 00 30                 beq       loc_139B8
0001398C 81 80 21 E0                 lwz       r12, backMessageCount
00013990 28 0C 00 02                 cmplwi    r12, 2
00013994 41 80 00 24                 blt       loc_139B8
00013998 89 80 21 DD                 lbz       r12, digitalBody
0001399C 2C 0C 00 00                 cmpwi     r12, 0
000139A0 40 82 00 10                 bne       loc_139B0
000139A4 89 80 21 E8                 lbz       r12, camSoft
000139A8 2C 0C 00 00                 cmpwi     r12, 0
000139AC 41 82 00 0C                 beq       loc_139B8
000139B0 3B C0 00 01 loc_139B0:      li        r30, 1
000139B4 48 00 00 F4                 b         loc_13AA8
000139B8 89 80 21 DD loc_139B8:      lbz       r12, digitalBody
000139BC 2C 0C 00 00                 cmpwi     r12, 0
000139C0 41 82 00 E8                 beq       loc_13AA8
000139C4 81 80 21 E0                 lwz       r12, backMessageCount
000139C8 28 0C 00 03                 cmplwi    r12, 3
000139CC 40 81 00 DC                 ble       loc_13AA8
000139D0 89 80 21 E8                 lbz       r12, camSoft
000139D4 2C 0C 00 00                 cmpwi     r12, 0
000139D8 41 82 00 20                 beq       loc_139F8
000139DC 48 08 5D 41                 bl        timeUsec 
000139E0 81 80 21 CC                 lwz       r12, releaseMessageTime
000139E4 7C 6C 18 50                 subf      r3, r12, r3
000139E8 3D 60 00 7A                 lis       r11, 0x7A # 0x7A1200 # 'z'
000139EC 61 6B 12 00                 ori       r11, r11, 0x1200 # 0x7A1200
000139F0 7C 03 58 40                 cmplw     r3, r11
000139F4 40 81 00 40                 ble       loc_13A34
000139F8 89 80 21 E6 loc_139F8:      lbz       r12, camGet
000139FC 2C 0C 00 00                 cmpwi     r12, 0
00013A00 40 82 00 28                 bne       loc_13A28
00013A04 89 80 21 E5                 lbz       r12, camSet
00013A08 2C 0C 00 00                 cmpwi     r12, 0
00013A0C 40 82 00 1C                 bne       loc_13A28
00013A10 89 80 21 48                 lbz       r12, takePicture
00013A14 2C 0C 00 00                 cmpwi     r12, 0
00013A18 40 82 00 10                 bne       loc_13A28
00013A1C 89 80 22 28                 lbz       r12, cameraWake
00013A20 2C 0C 00 00                 cmpwi     r12, 0
00013A24 41 82 00 10                 beq       loc_13A34
00013A28 39 80 00 01 loc_13A28:      li        r12, 1
00013A2C 99 80 22 19                 stb       r12, setRE
00013A30 48 00 00 74                 b         loc_13AA4
00013A34 89 80 21 E6 loc_13A34:      lbz       r12, camGet
00013A38 2C 0C 00 00                 cmpwi     r12, 0
00013A3C 40 82 00 10                 bne       loc_13A4C
00013A40 89 80 21 E5                 lbz       r12, camSet
00013A44 2C 0C 00 00                 cmpwi     r12, 0
00013A48 41 82 00 0C                 beq       loc_13A54
00013A4C 3B C0 00 13 loc_13A4C:      li        r30, 0x13
00013A50 48 00 00 58                 b         loc_13AA8
00013A54 89 80 21 48 loc_13A54:      lbz       r12, takePicture
00013A58 2C 0C 00 00                 cmpwi     r12, 0
00013A5C 41 82 00 34                 beq       loc_13A90
00013A60 89 80 21 F0                 lbz       r12, camTakeRequested
00013A64 2C 0C 00 00                 cmpwi     r12, 0
00013A68 40 82 00 28                 bne       loc_13A90
00013A6C 89 80 21 EB                 lbz       r12, camEnabled
00013A70 2C 0C 00 00                 cmpwi     r12, 0
00013A74 41 82 00 1C                 beq       loc_13A90
00013A78 89 80 21 E8                 lbz       r12, camSoft
00013A7C 2C 0C 00 00                 cmpwi     r12, 0
00013A80 41 82 00 10                 beq       loc_13A90
00013A84 39 80 00 03                 li        r12, 3
00013A88 99 80 22 19                 stb       r12, setRE
00013A8C 48 00 00 18                 b         loc_13AA4
00013A90 89 80 21 E7 loc_13A90:      lbz       r12, camClearRequest
00013A94 2C 0C 00 00                 cmpwi     r12, 0
00013A98 41 82 00 10                 beq       loc_13AA8
00013A9C 39 80 00 00                 li        r12, 0
00013AA0 99 80 22 19                 stb       r12, setRE
00013AA4 3B C0 00 04 loc_13AA4:      li        r30, 4
00013AA8 57 C3 06 3E loc_13AA8:      clrlwi    r3, r30, 24
00013AAC 83 C1 00 10                 lwz       r30, 0x18+var_8(r1)
00013AB0 83 E1 00 14                 lwz       r31, 0x18+var_4(r1)
00013AB4 80 01 00 1C                 lwz       r0, 0x18+arg_4(r1)
00013AB8 7C 08 03 A6                 mtlr      r0
00013ABC 38 21 00 18                 addi      r1, r1, 0x18
00013AC0 4E 80 00 20                 blr
00013AC4 00 00 00 00
00013AC8 00 00 00 00
00013ACC 00 00 00 00
00013AD0 00 00 00 00
00013AD4 00 00 00 00
00013AD8 00 00 00 00
00013ADC 00 00 00 00
00013AE0 00 00 00 00
00013AE4 00 00 00 00
00013AE8 00 00 00 00
00013AEC 00 00 00 00
00013AF0 00 00 00 00
00013AF4 00 00 00 00

