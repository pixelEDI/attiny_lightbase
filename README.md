<img src="https://img.shields.io/badge/-ATtiny%20Project-blue.svg?&amp;style=flat-square&amp" style="max-width: 100%;"> <img src="https://img.shields.io/badge/-PlattformIO-orange.svg?&amp;style=flat-square&amp" style="max-width: 100%;">


# General info
[![Watch the video](https://github.com/pixelEDI/attiny_lightbase/blob/main/nightlight_youtube.jpg)](https://www.youtube.com/watch?v=XIh21eYYatw)

## Code
- First we declare the functions for fading in and out the LEDs
- With the function "detectTwoClapsInTimeWindow" we make sure, that the claps are at least 300ms apart from each other to get counted.
- In the loop: 
- if the second clap follows within 1000ms the LEDs will be turned on and/or off in three different ways. And then the clap counter starts at zero.
- otherwise nothing happens and the clap counter starts at zero.


## Hardware
- This DIY nightlight is a practical example of using transistors with ATtinys since we address 4 LEDs with one GPIO, with max 40mA per pin.
- The light is switched on and off from the hardware side with a built-in reed switch and a magnet.
- The microphone functions as a sound detector so you can change between three colors by clapping. 
- We added 100ohm resistors for the LEDs and 1kohm for the transistor (on the base).
- The transistors are a NPN Type with 100mA IC

![Verdrahtung](https://github.com/pixelEDI/attiny_lightbase/blob/acee0ae0a8cb3ad401b295703366edbd02c3874a/Wiring_lightBase.jpg)


## 3D Case
Get the Case:  [thingiverser URL](https://www.thingiverse.com/thing:5427689)
![Case](https://github.com/pixelEDI/attiny_lightbase/blob/main/Collage3dlightbase.jpg?raw=true)
