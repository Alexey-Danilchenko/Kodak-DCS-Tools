cameraMessageSetupMamiya:

0001312C 94 21 FF E8                 stwu      r1, -0x18(r1)
00013130 7C 08 02 A6                 mflr      r0
00013134 93 C1 00 10                 stw       r30, 0x18+var_8(r1)
00013138 93 E1 00 14                 stw       r31, 0x18+var_4(r1)
0001313C 90 01 00 1C                 stw       r0, 0x18+arg_4(r1)
00013140 3B E3 00 00                 addi      r31, r3, 0
00013144 3B C0 00 00                 li        r30, 0
00013148 89 60 21 DD                 lbz       r11, digitalBody
0001314C 2C 0B 00 00                 cmpwi     r11, 0
00013150 41 82 00 8C                 beq       loc_131DC-13150
00013154 89 80 21 ED                 lbz       r12, camShutterOpen
00013158 2C 0C 00 00                 cmpwi     r12, 0
0001315C 41 82 00 80                 beq       loc_131DC-1315C
00013160 81 80 20 A0                 lwz       r12, shutterOpenTime
00013164 2C 0C 00 00                 cmpwi     r12, 0
00013168 41 82 00 74                 beq       loc_131DC-13168
0001316C 48 08 65 B1                 bl        timeUsec ; 9971C-0001316C
00013170 81 80 20 A0                 lwz       r12, shutterOpenTime
00013174 7C 6C 18 50                 subf      r3, r12, r3
00013178 81 80 21 BC                 lwz       r12, exposureTime
0001317C 2C 0C 00 00                 cmpwi     r12, 0
00013180 41 82 00 20                 beq       loc_131A0-13180
00013184 81 60 21 BC                 lwz       r11, exposureTime
00013188 3D 40 00 01                 lis       r10, loc_186A0@h
0001318C 61 4A 86 A0                 ori       r10, r10, loc_186A0@l
00013190 7D 6B 52 14                 add       r11, r11, r10
00013194 7C 03 58 40                 cmplw     r3, r11
00013198 41 80 00 44                 blt       loc_131DC-13198
0001319C 48 00 00 1C                 b         loc_131B8-1319C
000131A0 39 60 7D 00 loc_131A0:      li        r11, 32000
000131A4 7C 03 58 40                 cmplw     r3, r11
000131A8 40 80 00 34                 ble       loc_131DC-131A8
000131AC 81 9F 0A C4 loc_131AC:      lwz       r12, immr.PBDAT(r31)
000131B0 55 8C 07 7B                 rlwinm.   r12, r12, 0,29,29 # r12 = r12 & 4
000131B4 40 82 00 28                 bne       loc_131DC-131B4
000131B8 48 00 46 DD loc_131B8:      bl        cameraShutterCloseCommon ;00017894-131B8
000131BC 38 60 00 06                 li        r3, SHUTTER_CLOSE
000131C0 38 80 00 00                 li        r4, 0
000131C4 38 A0 00 00                 li        r5, 0
000131C8 48 02 A7 B1                 bl        eventPost ; 3D978-000131C8
000131CC 39 20 00 00                 li        r9, 0
000131D0 99 20 21 ED                 stb       r9, camShutterOpen
000131D4 48 08 65 49                 bl        timeUsec ; 9971C-000131D4
000131D8 90 60 20 A4                 stw       r3, shutterCloseTime
000131DC 89 80 21 E8 loc_131DC:      lbz       r12, camSoft
000131E0 2C 0C 00 00                 cmpwi     r12, 0
000131E4 41 82 00 78                 beq       loc_1325C-131E4
000131E8 89 80 21 ED                 lbz       r12, camShutterOpen
000131EC 2C 0C 00 00                 cmpwi     r12, 0
000131F0 40 82 00 6C                 bne       loc_1325C-131F0
000131F4 89 80 21 EE                 lbz       r12, camShutterOpenDigital
000131F8 2C 0C 00 00                 cmpwi     r12, 0
000131FC 40 82 00 60                 bne       loc_1325C-131FC
00013200 48 08 65 1D                 bl        timeUsec ; 9971C-00013200
00013204 81 80 21 C4                 lwz       r12, lastMessageTime
00013208 7C 6C 18 50                 subf      r3, r12, r3
0001320C 3D 40 00 01                 lis       r10, camSoftOnTime@h
00013210 61 4A 24 C0                 ori       r10, r10, camSoftOnTime@l
00013214 81 6A 00 00                 lwz       r11, 0(r10)
00013218 55 6B 10 3A                 slwi      r11, r11, 2
0001321C 3D 40 00 01                 lis       r10, camSoftOnTimes@h
00013220 61 4A 25 58                 ori       r10, r10, camSoftOnTimes@l
00013224 7D 6A 58 2E                 lwzx      r11, r10, r11
00013228 7C 03 58 40                 cmplw     r3, r11
0001322C 40 81 00 30                 ble       loc_1325C-1322C
00013230 39 80 00 00                 li        r12, 0
00013234 99 80 21 E8                 stb       r12, camSoft
00013238 38 60 00 0A                 li        r3, SOFT_RELEASE # event SOFT_RELEASE
0001323C 38 80 00 00                 li        r4, 0
00013240 38 A0 00 00                 li        r5, 0
00013244 48 02 A7 35                 bl        eventPost ; 3D978-00013244
00013248 48 04 E4 31                 bl        imageSafeSet ;61678-00013248
0001324C 38 60 00 03                 li        r3, CAMERA_SAFE # event CAMERA_SAFE
00013250 38 80 00 00                 li        r4, 0
00013254 38 A0 00 00                 li        r5, 0
00013258 48 02 A7 21                 bl        eventPost ; 3D978-00013258
0001325C 48 00 52 11 loc_1325C:      bl        cameraDialogCheck    ;01846C-1325C
00013260 81 80 21 E0                 lwz       r12, backMessageCount
00013264 28 0C 00 04                 cmplwi    r12, 4
00013268 40 81 00 8C                 ble       loc_132F4-13268
0001326C 89 80 21 DD                 lbz       r12, digitalBody
00013270 2C 0C 00 00                 cmpwi     r12, 0
00013274 40 82 00 80                 bne       loc_132F4-13274
00013278 89 80 21 48                 lbz       r12, takePicture
0001327C 2C 0C 00 00                 cmpwi     r12, 0
00013280 41 82 00 64                 beq       loc_132E4-13280
00013284 89 80 20 98                 lbz       r12, takePictureHost
00013288 2C 0C 00 00                 cmpwi     r12, 0
0001328C 41 82 00 18                 beq       loc_132A4-1328C
00013290 38 60 00 39                 li        r3, PREVIEW_PROGRESS # event PREVIEW_PROGRESS
00013294 38 80 00 00                 li        r4, 0
00013298 3C A0 00 3A                 lis       r5, 0x3A # ':'
0001329C 48 02 A6 DD                 bl        eventPost ; 3D978-0001329C
000132A0 48 00 00 38                 b         loc_132D8-132A0
000132A4 39 80 00 00 loc_132A4:      li        r12, 0
000132A8 91 81 00 08                 stw       r12, 0x18+var_10(r1)
000132AC 3C 60 00 02                 lis       r3, ((aCameraErrorCam+0x10000)@h) # "Camera error: Camera body cannot be con"...
000132B0 38 63 C6 A0                 addi      r3, r3, aCameraErrorCam@l # "Camera error: Camera body cannot be con"...
000132B4 3C 80 00 02                 lis       r4, ((aOk_10+0x10000)@h) # "OK"
000132B8 38 84 C6 DC                 addi      r4, r4, aOk_10@l # "OK"
000132BC 38 A0 00 00                 li        r5, 0
000132C0 38 C0 00 00                 li        r6, 0
000132C4 38 E0 00 00                 li        r7, 0
000132C8 39 00 00 00                 li        r8, 0
000132CC 39 20 00 00                 li        r9, 0
000132D0 39 40 00 00                 li        r10, 0
000132D4 48 08 C8 51                 bl        userDialog   ;9FB24-000132D4
000132D8 3B E0 00 00 loc_132D8:      li        r31, 0
000132DC 9B E0 21 F0                 stb       r31, camTakeRequested
000132E0 9B E0 21 48                 stb       r31, takePicture
000132E4 3B E0 00 00 loc_132E4:      li        r31, 0
000132E8 9B E0 21 E6                 stb       r31, camGet
000132EC 9B E0 21 E5                 stb       r31, camSet
000132F0 48 00 01 14                 b         loc_13404-132F0
000132F4 28 1F 00 0A loc_132F4:      cmplwi    r31, 0xA
000132F8 40 81 00 74                 ble       loc_1336C-132F8
000132FC 89 80 21 48                 lbz       r12, takePicture
00013300 2C 0C 00 00                 cmpwi     r12, 0
00013304 41 82 01 00                 beq       loc_13404-13304
00013308 89 80 20 98                 lbz       r12, takePictureHost
0001330C 2C 0C 00 00                 cmpwi     r12, 0
00013310 41 82 00 18                 beq       loc_13328-13310
00013314 38 60 00 39                 li        r3, PREVIEW_PROGRESS # event PREVIEW_PROGRESS
00013318 38 80 00 00                 li        r4, 0
0001331C 3C A0 00 31                 lis       r5, 0x31 # '1'
00013320 48 02 A6 59                 bl        eventPost ; 3D978-00013320
00013324 48 00 00 38                 b         loc_1335C-13324
00013328 39 80 00 00 loc_13328:      li        r12, 0
0001332C 91 81 00 08                 stw       r12, 0x18+var_10(r1)
00013330 3C 60 00 02                 lis       r3, ((aCameraErrorC_0+0x10000)@h) # "Camera error: Camera body is off.\a"
00013334 38 63 C6 E0                 addi      r3, r3, aCameraErrorC_0@l # "Camera error: Camera body is off.\a"
00013338 3C 80 00 02                 lis       r4, ((aOk_10+0x10000)@h) # "OK"
0001333C 38 84 C6 DC                 addi      r4, r4, aOk_10@l # "OK"
00013340 38 A0 00 00                 li        r5, 0
00013344 38 C0 00 00                 li        r6, 0
00013348 38 E0 00 00                 li        r7, 0
0001334C 39 00 00 00                 li        r8, 0
00013350 39 20 00 00                 li        r9, 0
00013354 39 40 00 00                 li        r10, 0
00013358 48 08 C7 CD                 bl        userDialog   ;9FB24-00013358
0001335C 3B E0 00 00 loc_1335C:      li        r31, 0
00013360 9B E0 21 F0                 stb       r31, camTakeRequested
00013364 9B E0 21 48                 stb       r31, takePicture
00013368 48 00 00 9C                 b         loc_13404-13368
0001336C 89 80 21 48 loc_1336C:      lbz       r12, takePicture
00013370 2C 0C 00 00                 cmpwi     r12, 0
00013374 41 82 00 90                 beq       loc_13404-13374
00013378 89 80 21 F0                 lbz       r12, camTakeRequested
0001337C 2C 0C 00 00                 cmpwi     r12, 0
00013380 41 82 00 84                 beq       loc_13404-13380
00013384 48 08 63 99                 bl        timeUsec ; 9971C-00013384
00013388 81 80 21 CC                 lwz       r12, releaseMessageTime
0001338C 7C 6C 18 50                 subf      r3, r12, r3
00013390 3D 60 00 4C                 lis       r11, 0x4C # 0x4C4B40 # 'L'
00013394 61 6B 4B 40                 ori       r11, r11, 0x4B40 # 0x4C4B40
00013398 7C 03 58 40                 cmplw     r3, r11
0001339C 40 81 00 68                 ble       loc_13404-1339C
000133A0 38 60 00 C7                 li        r3, INFO_EVENT
000133A4 38 80 00 00                 li        r4, 0
000133A8 3C A0 00 36                 lis       r5, 0x36 # '6'
000133AC 48 02 A5 CD                 bl        eventPost ; 3D978-000133AC
000133B0 89 20 20 98                 lbz       r9, takePictureHost
000133B4 2C 09 00 00                 cmpwi     r9, 0
000133B8 40 82 00 38                 bne       loc_133F0-133B8
000133BC 39 80 00 10                 li        r12, 0x10
000133C0 91 81 00 08                 stw       r12, 0x18+var_10(r1)
000133C4 3C 60 00 02                 lis       r3, ((aCameraWarningC+0x10000)@h) # "Camera warning: Camera body is unable t"...
000133C8 38 63 C7 04                 addi      r3, r3, aCameraWarningC@l # "Camera warning: Camera body is unable t"...
000133CC 3C 80 00 02                 lis       r4, ((aOk_10+0x10000)@h) # "OK"
000133D0 38 84 C6 DC                 addi      r4, r4, aOk_10@l # "OK"
000133D4 38 A0 00 00                 li        r5, 0
000133D8 38 C0 00 00                 li        r6, 0
000133DC 38 E0 00 00                 li        r7, 0
000133E0 39 00 00 00                 li        r8, 0
000133E4 39 20 00 00                 li        r9, 0
000133E8 39 40 00 00                 li        r10, 0
000133EC 48 08 C7 39                 bl        userDialog   ;9FB24-000133EC 
000133F0 3B E0 00 00 loc_133F0:      li        r31, 0
000133F4 9B E0 21 F0                 stb       r31, camTakeRequested
000133F8 9B E0 21 48                 stb       r31, takePicture
000133FC 39 60 00 01                 li        r11, 1
00013400 99 60 21 E7                 stb       r11, camClearRequest
00013404 81 80 21 F4 loc_13404:      lwz       r12, cameraMinIso
00013408 81 60 22 24                 lwz       r11, cameraIso
0001340C 7D 8C 5A 14                 add       r12, r12, r11
00013410 55 9F 20 36                 slwi      r31, r12, 4   # r31 = r12 << 4
00013414 3D 40 00 02                 lis       r10, ((listIso+0x10000)@h)
00013418 39 4A 8F 6C                 addi      r10, r10, listIso@l
0001341C 7D 4A F8 AE                 lbzx      r10, r10, r31
00013420 99 40 58 22                 stb       r10, byte_5822
00013424 3D 60 00 02                 lis       r11, ((listIsoSet+0x10000)@h)
00013428 39 6B 91 0C                 addi      r11, r11, listIsoSet@l
0001342C 7D 6B F8 AE                 lbzx      r11, r11, r31
00013430 99 60 22 15                 stb       r11, setISO
00013434 89 80 21 DD                 lbz       r12, digitalBody
00013438 2C 0C 00 00                 cmpwi     r12, 0
0001343C 40 82 00 2C                 bne       loc_13468-1343C
00013440 89 80 21 E8                 lbz       r12, camSoft
00013444 2C 0C 00 00                 cmpwi     r12, 0
00013448 38 80 00 01                 li        r4, 1
0001344C 41 82 00 08                 beq       loc_13454-1344C
00013450 38 80 00 00                 li        r4, 0
00013454 3C 60 00 01 loc_13454:      lis       r3, loc_11170@h
00013458 60 63 11 70                 ori       r3, r3, loc_11170@l
0001345C 48 04 E1 91                 bl        imageOkToTakePicture ;615EC-0001345C 
00013460 3B E3 00 00                 addi      r31, r3, 0
00013464 48 00 00 28                 b         loc_1348C-13464
00013468 89 80 21 E8 loc_13468:      lbz       r12, camSoft
0001346C 2C 0C 00 00                 cmpwi     r12, 0
00013470 38 80 00 01                 li        r4, 1
00013474 41 82 00 08                 beq       loc_1347C-13474
00013478 38 80 00 00                 li        r4, 0
0001347C 3C 60 00 04 loc_1347C:      lis       r3, loc_493E0@h
00013480 60 63 93 E0                 ori       r3, r3, loc_493E0@l
00013484 48 04 E1 69                 bl        imageOkToTakePicture ;615EC-00013484 
00013488 3B E3 00 00                 addi      r31, r3, 0
0001348C 2C 1F 00 00 loc_1348C:      cmpwi     r31, 0
00013490 41 82 00 10                 beq       loc_134A0-13490
00013494 89 80 21 E4                 lbz       r12, alwaysEnable
00013498 2C 0C 00 00                 cmpwi     r12, 0
0001349C 41 82 00 2C                 beq       loc_134C8-1349C
000134A0 39 80 00 01 loc_134A0:      li        r12, 1
000134A4 99 80 21 EA                 stb       r12, camEnable
000134A8 38 60 58 20                 li        r3, msg81
000134AC 89 43 00 04                 lbz       r10, 4(r3)
000134B0 55 4A 07 FA                 rlwinm    r10, r10, 0,31,29 # r10 = r10 & 0xFFFFFFFD
000134B4 99 43 00 04                 stb       r10, 4(r3)
000134B8 38 60 00 00                 li        r3, 0
000134BC 98 60 22 11                 stb       r3, setST
000134C0 98 60 21 F1                 stb       r3, camDisable
000134C4 48 00 00 88                 b         loc_1354C-134C4
000134C8 39 80 00 00 loc_134C8:      li        r12, 0
000134CC 99 80 21 EA                 stb       r12, camEnable
000134D0 38 60 58 20                 li        r3, msg81
000134D4 89 43 00 04                 lbz       r10, 4(r3)
000134D8 61 4A 00 02                 ori       r10, r10, 2
000134DC 99 43 00 04                 stb       r10, 4(r3)
000134E0 57 E3 00 1E                 clrrwi    r3, r31, 16   # r3 = r31 & 0xFFFF0000
000134E4 3D 60 00 12                 lis       r11, 0x12
000134E8 7C 03 58 40                 cmplw     r3, r11
000134EC 41 82 00 10                 beq       loc_134FC-134EC
000134F0 3D 80 00 22                 lis       r12, 0x22 # '"'
000134F4 7C 03 60 40                 cmplw     r3, r12
000134F8 40 82 00 10                 bne       loc_13508-134F8
000134FC 39 80 00 03 loc_134FC:      li        r12, 3
00013500 99 80 22 11                 stb       r12, setST
00013504 48 00 00 44                 b         loc_13548-13504
00013508 3D 80 00 1B loc_13508:      lis       r12, 0x1B
0001350C 7C 03 60 40                 cmplw     r3, r12
00013510 40 82 00 10                 bne       loc_13520-13510
00013514 39 80 00 05                 li        r12, 5
00013518 99 80 22 11                 stb       r12, setST
0001351C 48 00 00 2C                 b         loc_13548-1351C
00013520 3D 80 00 0D loc_13520:      lis       r12, 0xD
00013524 7C 03 60 40                 cmplw     r3, r12
00013528 40 82 00 18                 bne       loc_13540-13528
0001352C 39 80 00 08                 li        r12, 8
00013530 99 80 22 11                 stb       r12, setST
00013534 39 60 00 00                 li        r11, 0
00013538 99 60 21 F1                 stb       r11, camDisable
0001353C 48 00 00 10                 b         loc_1354C-1353C
00013540 39 80 00 01 loc_13540:      li        r12, 1
00013544 99 80 22 11                 stb       r12, setST
00013548 48 00 4E 9D loc_13548:      bl        cameraDisable    ;183E4-13548
0001354C 89 80 22 2A loc_1354C:      lbz       r12, mamiyaSerialV1
00013550 2C 0C 00 00                 cmpwi     r12, 0
00013554 41 82 00 10                 beq       loc_13564-13554
00013558 89 80 22 11                 lbz       r12, setST
0001355C 61 8C 00 20                 ori       r12, r12, 0x20
00013560 99 80 22 11                 stb       r12, setST
00013564 89 80 21 EE loc_13564:      lbz       r12, camShutterOpenDigital
00013568 2C 0C 00 00                 cmpwi     r12, 0
0001356C 41 82 00 74                 beq       loc_135E0-1356C
00013570 89 80 21 ED                 lbz       r12, camShutterOpen
00013574 2C 0C 00 00                 cmpwi     r12, 0
00013578 40 82 00 68                 bne       loc_135E0-13578
0001357C 57 EC 00 1E                 clrrwi    r12, r31, 16  # r12 = r31 & 0xFFFF0000
00013580 3D 60 00 0D                 lis       r11, 0xD
00013584 7C 0C 58 40                 cmplw     r12, r11
00013588 40 82 00 3C                 bne       loc_135C4-13588
0001358C 57 EC 04 3E                 clrlwi    r12, r31, 16  # r12 = r31 & 0xFFFF
00013590 28 0C 01 00                 cmplwi    r12, 0x100
00013594 41 80 00 30                 blt       loc_135C4-13594
00013598 48 08 61 85                 bl        timeUsec ; 9971C-00013598 
0001359C 81 80 20 A4                 lwz       r12, shutterCloseTime
000135A0 7C 6C 18 50                 subf      r3, r12, r3
000135A4 3D 60 00 98                 lis       r11, 0x98 # 0x989680
000135A8 61 6B 96 80                 ori       r11, r11, 0x9680 # 0x989680
000135AC 7C 03 58 40                 cmplw     r3, r11
000135B0 40 81 01 D4                 ble       loc_13784-135B0
000135B4 89 80 21 DF                 lbz       r12, camSettingsReceived
000135B8 2C 0C 00 00                 cmpwi     r12, 0
000135BC 41 82 00 1C                 beq       loc_135D8-135BC
000135C0 48 00 01 C4                 b         loc_13784-135C0
000135C4 89 80 21 DF loc_135C4:      lbz       r12, camSettingsReceived
000135C8 2C 0C 00 00                 cmpwi     r12, 0
000135CC 41 82 00 0C                 beq       loc_135D8-135CC
000135D0 3B C0 00 11                 li        r30, 0x11
000135D4 48 00 01 B0                 b         loc_13784-135D4
000135D8 3B C0 00 12 loc_135D8:      li        r30, 0x12
000135DC 48 00 01 A8                 b         loc_13784-135DC
000135E0 8B E0 21 E9 loc_135E0:      lbz       r31, camAwake
000135E4 2C 1F 00 00                 cmpwi     r31, 0
000135E8 40 82 00 3C                 bne       loc_13624-135E8
000135EC 89 80 21 E6                 lbz       r12, camGet
000135F0 2C 0C 00 00                 cmpwi     r12, 0
000135F4 40 82 00 28                 bne       loc_1361C-135F4
000135F8 89 80 21 E5                 lbz       r12, camSet
000135FC 2C 0C 00 00                 cmpwi     r12, 0
00013600 40 82 00 1C                 bne       loc_1361C-13600
00013604 89 80 21 48                 lbz       r12, takePicture
00013608 2C 0C 00 00                 cmpwi     r12, 0
0001360C 40 82 00 10                 bne       loc_1361C-1360C
00013610 89 80 22 28                 lbz       r12, cameraWake
00013614 2C 0C 00 00                 cmpwi     r12, 0
00013618 41 82 00 0C                 beq       loc_13624-13618
0001361C 3B C0 00 01 loc_1361C:      li        r30, 1
00013620 48 00 01 64                 b         loc_13784-13620
00013624 2C 1F 00 00 loc_13624:      cmpwi     r31, 0
00013628 41 82 01 5C                 beq       loc_13784-13628
0001362C 89 80 21 EC                 lbz       r12, camShutterArm
00013630 2C 0C 00 00                 cmpwi     r12, 0
00013634 40 82 01 50                 bne       loc_13784-13634
00013638 89 80 21 ED                 lbz       r12, camShutterOpen
0001363C 2C 0C 00 00                 cmpwi     r12, 0
00013640 40 82 01 44                 bne       loc_13784-13640
00013644 8B E0 21 F2                 lbz       r31, camReply
00013648 2C 1F 00 00                 cmpwi     r31, 0
0001364C 41 82 00 0C                 beq       loc_13658-1364C
00013650 3B DF 00 00                 addi      r30, r31, 0
00013654 48 00 01 30                 b         loc_13784-13654
00013658 89 80 21 EB loc_13658:      lbz       r12, camEnabled
0001365C 89 60 21 EA                 lbz       r11, camEnable
00013660 7C 0C 58 00                 cmpw      r12, r11
00013664 41 82 00 30                 beq       loc_13694-13664
00013668 81 80 21 E0                 lwz       r12, backMessageCount
0001366C 28 0C 00 02                 cmplwi    r12, 2
00013670 41 80 00 24                 blt       loc_13694-13670
00013674 89 80 21 DD                 lbz       r12, digitalBody
00013678 2C 0C 00 00                 cmpwi     r12, 0
0001367C 40 82 00 10                 bne       loc_1368C-1367C
00013680 89 80 21 E8                 lbz       r12, camSoft
00013684 2C 0C 00 00                 cmpwi     r12, 0
00013688 41 82 00 0C                 beq       loc_13694-13688
0001368C 3B C0 00 01 loc_1368C:      li        r30, 1
00013690 48 00 00 F4                 b         loc_13784-13690
00013694 89 80 21 DD loc_13694:      lbz       r12, digitalBody
00013698 2C 0C 00 00                 cmpwi     r12, 0
0001369C 41 82 00 E8                 beq       loc_13784-1369C
000136A0 81 80 21 E0                 lwz       r12, backMessageCount
000136A4 28 0C 00 03                 cmplwi    r12, 3
000136A8 40 81 00 DC                 ble       loc_13784-136A8
000136AC 89 80 21 E8                 lbz       r12, camSoft
000136B0 2C 0C 00 00                 cmpwi     r12, 0
000136B4 41 82 00 20                 beq       loc_136D4-136B4
000136B8 48 08 60 65                 bl        timeUsec ; 9971C-000136B8 
000136BC 81 80 21 CC                 lwz       r12, releaseMessageTime
000136C0 7C 6C 18 50                 subf      r3, r12, r3
000136C4 3D 60 00 7A                 lis       r11, 0x7A # 0x7A1200 # 'z'
000136C8 61 6B 12 00                 ori       r11, r11, 0x1200 # 0x7A1200
000136CC 7C 03 58 40                 cmplw     r3, r11
000136D0 40 81 00 40                 ble       loc_13710-136D0
000136D4 89 80 21 E6 loc_136D4:      lbz       r12, camGet
000136D8 2C 0C 00 00                 cmpwi     r12, 0
000136DC 40 82 00 28                 bne       loc_13704-136DC
000136E0 89 80 21 E5                 lbz       r12, camSet
000136E4 2C 0C 00 00                 cmpwi     r12, 0
000136E8 40 82 00 1C                 bne       loc_13704-136E8
000136EC 89 80 21 48                 lbz       r12, takePicture
000136F0 2C 0C 00 00                 cmpwi     r12, 0
000136F4 40 82 00 10                 bne       loc_13704-136F4
000136F8 89 80 22 28                 lbz       r12, cameraWake
000136FC 2C 0C 00 00                 cmpwi     r12, 0
00013700 41 82 00 10                 beq       loc_13710-13700
00013704 39 80 00 01 loc_13704:      li        r12, 1
00013708 99 80 22 19                 stb       r12, setRE
0001370C 48 00 00 74                 b         loc_13780-1370C
00013710 89 80 21 E6 loc_13710:      lbz       r12, camGet
00013714 2C 0C 00 00                 cmpwi     r12, 0
00013718 40 82 00 10                 bne       loc_13728-13718
0001371C 89 80 21 E5                 lbz       r12, camSet
00013720 2C 0C 00 00                 cmpwi     r12, 0
00013724 41 82 00 0C                 beq       loc_13730-13724
00013728 3B C0 00 13 loc_13728:      li        r30, 0x13
0001372C 48 00 00 58                 b         loc_13784-1372C
00013730 89 80 21 48 loc_13730:      lbz       r12, takePicture
00013734 2C 0C 00 00                 cmpwi     r12, 0
00013738 41 82 00 34                 beq       loc_1376C-13738
0001373C 89 80 21 F0                 lbz       r12, camTakeRequested
00013740 2C 0C 00 00                 cmpwi     r12, 0
00013744 40 82 00 28                 bne       loc_1376C-13744
00013748 89 80 21 EB                 lbz       r12, camEnabled
0001374C 2C 0C 00 00                 cmpwi     r12, 0
00013750 41 82 00 1C                 beq       loc_1376C-13750
00013754 89 80 21 E8                 lbz       r12, camSoft
00013758 2C 0C 00 00                 cmpwi     r12, 0
0001375C 41 82 00 10                 beq       loc_1376C-1375C
00013760 39 80 00 03                 li        r12, 3
00013764 99 80 22 19                 stb       r12, setRE
00013768 48 00 00 18                 b         loc_13780-13768
0001376C 89 80 21 E7 loc_1376C:      lbz       r12, camClearRequest
00013770 2C 0C 00 00                 cmpwi     r12, 0
00013774 41 82 00 10                 beq       loc_13784-13774
00013778 39 80 00 00                 li        r12, 0
0001377C 99 80 22 19                 stb       r12, setRE
00013780 3B C0 00 04 loc_13780:      li        r30, 4
00013784 57 C3 06 3E loc_13784:      clrlwi    r3, r30, 24   # r3 = r30 & 0xFF
00013788 83 C1 00 10                 lwz       r30, 0x18+var_8(r1)
0001378C 83 E1 00 14                 lwz       r31, 0x18+var_4(r1)
00013790 80 01 00 1C                 lwz       r0, 0x18+arg_4(r1)
00013794 7C 08 03 A6                 mtlr      r0
00013798 38 21 00 18                 addi      r1, r1, 0x18
0001379C 4E 80 00 20                 blr
000137A0 00 00 00 00 
000137A4 00 00 00 00 
000137A8 00 00 00 00 
000137AC 00 00 00 00 
000137B0 00 00 00 00 
000137B4 00 00 00 00 
