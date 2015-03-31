# Kernel(3.5.67) Source Code for Inhon G1 (MT6577)
This kernel is for Android Kitkat 4.4.2(build KOT49I), based on [superdragonpt](http://forum.xda-developers.com/android/development/rom-zte-v970-v970m-t2956447)'s ZTE kernel.  
This is an Unofficial Build, so it will NOT be supported by the OEM.  

## Building Kernel
  - In Terminal, cd to project's root folder:
```sh
$ cd ~/ ... /Inhon-G1-KK-Kernel-3.4.67/
```
  - Setting environment for cross compiler:
```sh
$ export CROSS_COMPILE=~/ ... /arm-eabi-4.7/bin/arm-eabi-
```
  - Run command to build new kernel: 
```sh
$ ./mk inhon_g1 n k
```
  - Once finished, you will find kerenl file in "out" directory

## Current Kernel Status
### [Working]
  - LCD & Touch Panel
  - Telephony & Data Connection with 2G and 3G 
  - ART & Dalvik
  - FM Radio
  - Wifi and Wifi Theter
  - Bluetooth and BT Theter
  - Sensors ( Accelerometer, Gyroscope, Magnetometer, ALS/PS )
  - Flashlight
  - Camera Rear / Camcorder
  - Headset
  - Volume Keys

### [Needs Improvements / Not Working]
  - GPS: not sure if the gps work or not
  - Back(Main) Camera: purple tint ( software fix by ZSD option )

## Special Thanks
  - [superdragonpt](http://forum.xda-developers.com/android/development/rom-zte-v970-v970m-t2956447), for his great work making Kitkat available on ZTE v970(MT6577).  
  


