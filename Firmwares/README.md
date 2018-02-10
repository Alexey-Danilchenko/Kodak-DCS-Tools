# Firmwares

This directory contains all the custom firmwares that I produced with the corresponding changes and patches against previous versions. 

Most patches if applied to main firmware are applied to _code segment, otherwise to DSP coff file inside the firmware. The details of all firmwares are given below.

# Custom firmwares (build by me)

_WARNING_: firmwares when updated in all Kodak cameras have to be updated twice (just like production firmwares). 

Firmwares with standalone service mode is no longer published here - they are still available as a part of DCSRemap and can be downloaded from there. Firmwares for ProBack 645 starting from version 3.3.8 support enabling service mode directly in camera and no longer need special firmware for remap.

## Proback Firmwares

### [Firmware 3.4.4.M for Proback 645 Mamiya](https://drive.google.com/open?id=1324Lww3DexPK7RqckA9R5KxUrMNfGtSL) 
This firmware adds the following features to the 3.4.3.M firmware: it fixes "Image Capture Error" that can appear with fast camera communicatons. This was easy to cause in fast cameras like Phase One DF/DF+ and could appear occasionally in older Mamiya 645 AFD cameras. On Phase One DF/DF+ the problem appeared in **Digital Combined** and **Digital Short Latency** shutter modes and this firmware makes those modes fully opertional. The error was caused by a bug in original Kodak firmware handling image capturing state where image readout stage was not considered _busy_ time for a camera and could lead to a shot attempted whilst capturing. Firmware [sources are here](ProBack645/3.4.4M). 

### [Firmware 3.4.4A.M for Proback 645 Mamiya](ProBack645/3.4.4M_Alt/PB645.bin) 
This firmware is an alternative implementation of the 3.4.3.M firmware and delivers the same functionality. For more details see [firmware sources here](ProBack645/3.4.4M_Alt). 

### [Firmware 3.4.3.M for Proback 645 Mamiya](https://drive.google.com/open?id=1Q4mIz1aos9wumnZDpdeLSlm5z32Svo1z) and [Firmware 3.4.0.CH for Proback 645 Contax/Hasselblad](https://drive.google.com/open?id=1l-_l9BQmKuJeVKslYlQg1K6n2kEW3bLw) 
These firmwares add the following features to the 3.4.2.MH and 3.3.10.C accordingly: add the ability to set metadata for manual lenses (with correct EXIF population) on all 3 Proback supported cameras. This functionality is new for Contax and Hassleblad Probacks and for Mamiya it was enhanced to support new setting system and user loadable list of lenses. Firmware [sources are here](ProBack645/3.4.3M). The overall list of enhancements:

* Manual lenses are selected on the main screen in a similar way to white balances - via drop-down menu (it is faster and more convenient in a field):
![Lens](http://www.aletan.com/img/s/v-3/p2700542434-2.jpg "image1")

* The data for the selected lens is always present on the status screen (in this respect the layout of the screen has changed slightly to accommodate it):
![Lens](http://www.aletan.com/img/s/v-3/p2700542431-2.jpg "image2")
* You can make up and load your own list of lenses (up to 20 in total). The list can be loaded from _lens.txt_ file that has the following textual format (example):

```
45mm f/3.5
80mm f/1.9
120mm f/4
150mm f/2.8
```
The file should be copied to the CF card's root directory and loaded by selecting the appropriate menu item (see below)
* Added menu Manual Lens Data (modified for Mamiya firmware)
![Lens](http://www.aletan.com/img/s/v-3/p2700542429-2.jpg "image3")
this now contains the options for loading user's manual lens list and resetting the list to the default configuration
![Lens](http://www.aletan.com/img/s/v-3/p2700542428-2.jpg "image4")

__WARNING__: Starting from these versions, the firmwares are recombined - Mamia firmware will be released separately and Contax combined with Hasselblad. This is due to the lack of space in the Mamiya version of firmware for this and further updates (since I have no sources extending binary files is limited).

### [Firmware 3.4.2.MH for Proback 645 Mamiya/Hasselblad](https://drive.google.com/open?id=1jeM1908Q3r0P20EU9ByPIroyTbEe0w6Z)
This adds the support for Mamiya AFD III, Mamiya/Phase One DF and Phase One DF+ to 3.3.10.MH as well as support for manual lenses on Mamiya cameras.  Firmware [sources are here](ProBack645/3.4.2MH). The overall list of enhancements:

* Completely rewritten communication interface with the camera to support newer digital cameras such as Mamiya AFD II/III and Phase One DF/DF+.
* Added Soft Press CCD Active Time property - allows you to set the time period for which the sensor is activated when half-pressed to the shutter (in the original Kodak firmware this is hardcoded to 0.8 seconds).
* Several shutter modes have been added. Available via the Shutter Operating Mode option in the main menu. The following modes are implemented:
    * __Legacy (645 AF / AFD)__ - compatibility mode. It works just like in firmware 3.3.x except for configurable CCD active time. This mode works with cameras up to Mamiya 645 AFD II (inclusive). It is the only mode that will work with film body like Mamiya 645 AF.
    * __Digital Long Latency__ - the sensor is activated only when the shutter is pressed and remains active for the duration of the exposure. Since the sensor activation takes time, this mode exhibits a noticeable delay and blackout when you press the shutter (0.4 seconds approximately - the delay happens in the camera body not in the back). This mode corresponds to Phase One Pnn+ backs Long Latency mode and is the only one which supports full set of modes for ProBack on Phase One DF/DF+. The battery consumption in this mode is the most optimal - the sensor is only turned on when needed.
    * __Digital Combined__ - the combined mode between Long and Short latencies. The sensor is activated when the shutter is half-pressed and remains active for a time set by Soft Press CCD Active Time or until exposing a frame (whichever comes earlier). There are no delays in shooting for sensor activation and minimal viewfinder blackout. It does not however work in the following modes - Continuous shooting mode (when the camera takes pictures continuously whilst shutter is pressed), timer mode (with the timer mode it will work, provided that the timer is set to be less than Soft Press CCD Active Time). The battery consumption is somewhat more than in Digital Long Latency mode - exact consumption will depend on usage patterns.
    * __Digital Short Latency__ - the sensor is activated the first time the shutter is pressed and remains active until the camera goes to sleep (in Phase One DF/DF+ this period is configurable in the camera). There are no delays in the shooting for sensor activation. It exhibits one problem in Continuous shooting mode where (unavoidable I am afraid - Pro Back architecture is too slow for Phase One DF cameras) which results in series of several frames at a time with capture error after that. This mode corresponds more or less to Phase One P+ backs Short Latency mode. Battery consumption is the largest of all modes.
* Added support for Bulb mode and correct calculation of shutter speed in Bulb mode
* Added ability to set metadata for manual lenses (used for EXIF ​​and image info). This is available on the main menu as Manual Lens Data option.
* The focal length is written in EXIF ​​- Adobe ACR/LR will now recognise it correctly.
* 35mm equivalent focal length is calculated and written in EXIF ​​- this will fix problems in Adobe ACR/LR perspective correction tools.
* Removed Scan-Shoot menu options (they are now defunct and if needed they can be brought back via showLegacyMenu property)

**A few things to note**

* The Legacy mode does not work with Phase One AF/DF/DF+ at all
* The Soft Press CCD Active Time for Mamiya 645 AFD could be left at default. For all other cameras since Mamiya 645 AFD II and upwards it should be tuned to your preferences and shutter mode used. I suggest using 5 seconds as a starting point.
* The Soft Press CCD Active Time setting is ignored in Digital Long Latency mode

### Firmwares [3.3.10.MH (Mamiya, Hasselblad)](https://drive.google.com/open?id=0Bw2ZohnbXtyATjRfbnVWelBVSm8) and [3.3.10.C (Contax)](https://drive.google.com/open?id=0Bw2ZohnbXtyAOGhjWXgycldreFE)

These firmwares extend range of allowed dates for Pro Backs to 2099. Firmware [sources are here](ProBack645/3.3.10MH). 

### [Firmware 3.3.9.MH for Proback 645 Mamiya/Hasselblad](https://drive.google.com/open?id=0Bw2ZohnbXtyAV2FVRklFYy1YOTg) 
This firmware adds the following features to the 3.3.8 firmware: correctly works with Mamiya AFD II camera - camera shutter speeds and f-number are recognized correctly for all new 1/3 steps. Auto-exposure (that can have intermediate 1/8 exposure steps) mapped correctly as well. Firmware [sources are here](ProBack645/3.3.9MH). 

### [Firmware 3.3.9.C for Proback 645 Contax](https://drive.google.com/file/d/0Bw2ZohnbXtyAaUpuNmh4dUNiT1pjY1VJWkxlbmlielhPTmd3/view?usp=sharing) 
This firmware adds the following features to the 3.3.8 firmware: fully supports recording of focal length in metadata. For zoom lenses the longer focal length is used (i.e. for 45-90 zoom, the 90mm will be recorded).
Firmware [sources are here](ProBack645/3.3.9). 

### [Firmware 3.3.8 for Proback 645](https://drive.google.com/file/d/0Bw2ZohnbXtyAdExkZ1ZiX1YzdFU/view?usp=sharing)
This firmware ([sources are here](ProBack645/3.3.8)) adds the following features to the stock Kodak 3.3.7 firmware:

* Service mode can be enabled/disabled via public property Enable Service Mode (in Properties menu). When change the mode from service mode enabled to normal, it is recommended to reboot Pro Back by replacing the battery. This property eliminates the need for special firmware used for DCS Remap - use this instead (the Save IF File in imager menu is also present in this firmware).
* The maximum allowed temperature for the sensor is configurable via Max Temp Limit public property (in Properties menu). It is by default set to the temperature that Kodak originally programmed for your ProBack type (50 degrees C for Mamiya and 65 for the Contax/Hasselblad). Setting this property to 101 degrees disables the check altogether. This allows user to control the well known "Camera too hot" error preventing the shoot or broken frames.

### [Proback и Proback Plus firmware 3.2.10](http://wowcamera.info/viewtopic.php?p=86748#p86748)

This firmware adds the following to the stock Kodak 3.2.9 firmware:

* Enables shooting with the [following manual trigger](http://wowcamera.info/viewtopic.php?p=86748#p86748) (link is in Russian please use Google translate) for Pro Back used on Hasseldlad 200/2000. Removes modal synchronization errors display that prevent normal shooting with this trigger. 

## Firmwares for Kodak DCS 14nx, SLR/n и SLR/c

Here you will find a custom build firmwares for the above Kodak cameras with modifications to fix or remove certain limitations. Installation procedure for all these is the same as for standard Kodak firmwares - it needs to be copied on card and updated twice from the camera menus. Firmware [sources are here](SLRs). 

[Firmware 5.4.10 for Kodak DCS Pro 14n(x)](https://drive.google.com/open?id=0Bw2ZohnbXtyAdkFGYjN0cnZaRGs)
[Firmware 5.4.10 for Kodak DCS Pro SLR/n](https://drive.google.com/open?id=0Bw2ZohnbXtyAcFlwTjJUdlpaeFU)
[Firmware 5.4.10 for Kodak DCS Pro SLR/c](https://drive.google.com/open?id=0Bw2ZohnbXtyATko1aWtBc2xtX2s)

This firmwares have two changes:

* Removed the popup message about long exposure time exceeded for the selected settings (it is annoying when it pops up in a middle of the shoot) - only for 14n and SLR/n
* Removed 10 bit lossy compression so DCR files are losless 12 bit files now


__WARNING__: After upgrading the firmware, do not use the card with compressed 10 bit DCR files taken before upgrade in camera. Attempting to view them in camera on a new firmware could lock up the camera and require reboot by pulling up the battery. The same goes to the downgrade firmware back to 5.4.9 (or any other older version) and 12 bit DCR files on a card.

**Patches to address raw processing software limitations handling 12 bit uncompressed DCR files**

Kodak Photodesk out of the box cannot handle their uncompressed preview properly so thumbnails and fast mode in it shows overexposed image. I have made a [patch for Kodak DCS Pro Photodesk 4.3.0.13 (Windows)](https://drive.google.com/open?id=0Bw2ZohnbXtyAYThyUXh0NDBNSUE) to work properly with those 12 bit images if someone needs to use it in those affected modes. The patch contains a DLL that needs to be dropped in Photodesk directory on Windows overriding existing one there.

Starting with Adobe Lightroom 6.0, ACR 9.0 and DNG Converter 9.0 the patchers are no longer needed - the uncompressed DCR files are handled properly.
