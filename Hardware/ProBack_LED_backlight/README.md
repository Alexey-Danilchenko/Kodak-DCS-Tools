# ProBack screen upgrade to use LED backlighting

Proback is an old digital back using Sanyo ALP230CCX LCD with CCFL tube as backlighting (that was a technology back in 2001). The CCFL tube lights up the edge of the screen and light guide plate with diffusers and light concentrator sheets providing a backlight. The backlighting achieved this way is very weak and in a strong daylight practically nothing can be seen on the LCD. Besides CCFL tubes have limited lifespan and cannot be replaced. The aim of this hardware project is a complete replacement of this backlighting system with LED board instead of CCFL tube driven from the same on/off signal as the main backlight.

This project followed the footsteps of something similar already done [here (link in russian)](https://web.archive.org/web/20171017015512/http://wowcamera.info/viewtopic.php?f=18&t=815&sid=7ef8761ab0095eecd0e935a0096e5fdd&start=740) but does a properly designed LED light source with constant current control.

I have designed the LED boards originally for 3x SMD LEDs in 2835 packages to fit perefecly inside LCD outer casing instead of CCFL. However upon experimenting with that it appears that Sanyo LCD backlight construction uses a light guide plate with straight vertical pattern that may work with linear light source like CCFL tube but does not work well with just a few LEDs creating long vertical beams of light. Modern LCD light guide panels use diaginal pattern that scatter light more evenly. With this in mind I also designed board for 6x SMD LEDs more closely spaced - those will need to be driven at 30mA to have the same power usage and light output as the 3x LEDs.

The alternative to 6x LED board and direct replacement is to place 3x LED lights sideways to the edge of the light guide - that means the light source needs to be behind the LCD case and holes for the LEDs need to be drilled into metallic frame to allow this. I will test both constructs and publish the results here. The latter approach is more involved than simple drop-in light replacement as this whole LED boards were designed to be but may be better at providing more uniform lighting.

The LED driver board provides constant current source from 3.3V and can be adjusted for your LEDs (by calculating R2 values for your LEDs current - see note on schematic with a few sample values). The LED driver board is very small and is designed to fit onto free space on ProBack board close to LCD and power source. 

Current design was tested with Yuji LEDs [[YJ-BC-2835L](https://www.yujiintl.com/bc-2835l-0-2w/) (20 lumens per LED - CRI95). 

Photos and description of the process of replacement to follow