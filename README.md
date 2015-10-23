# Drivers
This repository includes a list of drivers to manage different peripherals and special components from the SamR21. 

## Neopixel

There are some clear clock requirements defined to make a Neopixel work. So far, to my understanding it requres a square signal with a duty cycle modulated defining a digital '0' or '1'. Since the Neopixel is created by the combination of three leds (Red, Green and Blue) the instruction set is defined by 3 bytes, one per each led. Since the resolution of each byte is 8 bits, or 256 decimal, values defining the intensity of each led vary from 0 to 255, or from 0b0000000 to 0b1111111. A white color at full intensity then is expected to be create sending three continous streams of 0b00000000 (one for red, one for green and one for blue).

