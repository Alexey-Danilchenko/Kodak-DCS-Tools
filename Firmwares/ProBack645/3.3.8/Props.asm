566C
cameraCommonProperty:.long aTakepicture # "takePicture"
_code:0000569C                 .long aTakePicture      # "Take Picture"
_code:000056A0                 .long takePicture
_code:000056A4                 .long aCameraControl    # "Camera Control"
_code:000056A8                 .long 1, 2, 0, 0, 0, 0
_code:000056C0                 .long cameraPropertySet
_code:000056C4                 .long 0
_code:000056C8                 .long aCameraopenshut   # "cameraOpenShutter"
_code:000056CC                 .long aOpenShutter      # "Open Shutter"
_code:000056D0                 .long cameraOpenShutter
_code:000056D4                 .long 0
_code:000056D8                 .long 1, 0x20, 0, 0, 0, 0
_code:000056F0                 .long cameraPropertySet
_code:000056F4                 .long 0
_code:000056F8                 .long aCamerashuttero   # "cameraShutterOpen"
_code:000056FC                 .long aShutterOpen      # "Shutter Open"
_code:00005700                 .long cameraShutterOpen
_code:00005704                 .long aCameraControl    # "Camera Control"
_code:00005708                 .long 1, 1, 0, 0, 0, 0, 0, 0
_code:00005728                 .long aCameraactuatio   # "cameraActuations"
_code:0000572C                 .long aTotalActuation   # "Total Actuations"
_code:00005730                 .long cameraActuations
_code:00005734                 .long aCameraControl    # "Camera Control"
_code:00005738                 .long 2, 0x10121, 0
_code:00005744                 .long 1000000000, 0, 0, 0, 0

77604(file)
_code:7CC70: aHightemperatur

4FA4 (file)
_code:0000A610 00 07 CC 70    .long aHightemperatur   # "maxTemperature"
_code:0000A614 00 07 CC 80    .long aHighTempLimit    # "Max Temp Limit"
_code:0000A618 00 00 3C C8    .long highTemperature
               00 07 CC 28    maxTemperature
_code:0000A61C 00 00 00 02    .long aPower_1          # "Power"
_code:0000A620 00 01 01 02    .long 1, 0x502, 0, 0, 0, 0, 0, 0
_code:0000A620 00 00 00 28 
_code:0000A624 00 00 00 65  
_code:0000A628 00 00 00 00 
_code:0000A62C 00 00 00 00
               00 00 00 00 
               00 00 00 00  
                
               
                
00 07 CC 70
00 07 CC 80
00 00 3C C8
00 07 CC 28
00 00 00 02
00 01 01 02
00 00 00 19
00 00 00 C8
00 00 00 00 
00 00 00 00  
00 00 00 00 
00 00 00 00
