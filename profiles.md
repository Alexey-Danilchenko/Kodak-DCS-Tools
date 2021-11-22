# Camera profiles and profile extraction for Kodak cameras

## Profile for Kodak 14nx, SLR/n, SLR/c

This profile was published [here](https://club.foto.ru/forum/view_post.php?p_id=6930508) and I believe now is used by [RPP](https://www.raw-photo-processor.com/RPP/Overview.html). I have converted it to .DCP format for use in ACR/Lightroom. It is [available here](https://drive.google.com/file/d/0Bw2ZohnbXtyAUVI5RmFOTC1VNG8/view?usp=sharing). The download contains two versions of profile - one with standard Lightroom/ACR curve and one with linear curve.

Alternatively the source .ICC profile could be converted by my [`icc2dcp` utility](sources/icc2dcp).

## Profiles for Kodak ProBack 645 M/C/H

Older version of Lightroom/ACR (ACR 4.2) contained quite neutral profile for these cameras. So I extracted them and converted to .ICC format to use in [RPP](https://www.raw-photo-processor.com/RPP/Overview.html). The [6500K profile is available here](https://drive.google.com/file/d/0Bw2ZohnbXtyAUUFhcGl3Z2ExNzg/view?usp=sharing) and [2850K profile is available here](https://drive.google.com/file/d/0Bw2ZohnbXtyAZmNCX1lnVUpuaVk/view?usp=sharing).


## Profile extraction for any Kodak camera from .DCR file

Pretty much all Kodak raw files (.DCR) for cameras supported here come with set of data that contain standard camera profiling information as well as information specific to this instance of the camera (profiled at a factory). The standard information pretty much matches the generic camera profiles Kodak shiped with these cameras. This data can be used to extract and generate camera profiles for various raw converters. 

I have created a utility to do just that - extract that data into profiles in various shapes and formats. This is called `dcrprofile` with sources available [here](sources/dcrprofile) and binaries could be downloaded [here](sources/dcrprofile/bin). It is a command line utility accepting the following set of options:


```
dcrprofile.exe -ikls <.DCR>
    -i - generate .ICC profiles (by default generates .DCP profiles for ACR/Lightroom)
    -k - use old Kodak ProPhoto matrix instead of current ProPhoto for space conversion (experimental)
    -l - generate DCP profiles with linear curve instead of ACR/Lightroom standard one
    -s - generate profiles from standard camera data (without this key - generates from camera instance specific data)

```

Example `dcrprofile` run:

```
dcrprofile.exe 4G4Z1250.DCR
    Generating profiles from unique sensor calibrated matrices...
       Creating "Kodak ProBack645 PB645M-6287 Daylight/Tungsten Unique" DCP profile
       Creating "Kodak ProBack645 PB645M-6287 Daylight Unique" DCP profile
       Creating "Kodak ProBack645 PB645M-6287 Tungsten Unique" DCP profile
       Creating "Kodak ProBack645 PB645M-6287 Fluorescent Unique" DCP profile
       Creating "Kodak ProBack645 PB645M-6287 Flash Unique" DCP profile
    ...Done

dcrprofile.exe -s 4G4Z1250.DCR
    Generating profiles from standard matrices...
       Creating "Kodak ProBack645 Daylight/Tungsten Standard" DCP profile
       Creating "Kodak ProBack645 Daylight Standard" DCP profile
       Creating "Kodak ProBack645 Tungsten Standard" DCP profile
       Creating "Kodak ProBack645 Fluorescent Standard" DCP profile
       Creating "Kodak ProBack645 Flash Standard" DCP profile
    ...Done
```
