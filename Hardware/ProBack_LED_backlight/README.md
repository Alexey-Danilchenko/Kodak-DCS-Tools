# ProBack screen upgrade to use LED backlighting

Proback is an old digital back using LCD with CCFL tube as backlighting (that was a technology back in 2001). The CCFL tube lights up the edge of the screen and polarised plate providing a backlight. The backlighting achieved this way is very weak and in strong daylight practically nothing can be seen on the LCD. The aim of this hardware project is a complete replacement of this backlighting system with LED board instead of CCFL tube.

I have designed the LED boards for 2x and 3x SMD LEDs in 2835 packages to fit perefecly inside LCD outer casing instead of CCFL. The LED driver board provides constant current application from 3.3V and can be adjusted for your LEDs (by calculating R2 values for your LEDs current - see note on schematic). The LED driver board is very small and is designed to fit onto free space on ProBack board close to LCD. 

Current design was tested with Yuji LEDs [YJ-VTC-2835X](https://www.yujiintl.com/vtc-2835x-0-2w/) (15 lumens per LED - CRI98) and [YJ-BC-2835L](https://www.yujiintl.com/bc-2835l-0-2w/) (20 lumens per LED - CRI95). The latter provides good illumination with just 2 LEDs that makes ProBack LCD usable in daylight.

Photos and description of the process of replacement to follow