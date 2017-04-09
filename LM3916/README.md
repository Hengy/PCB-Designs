# LM3914/5/6

Designed to use the LM3916 (but can use the LM3914/5) to make a LED VU meter.

Op amp on input should be a rail-to-rail type (NOT a NE5532 as originally silkscreened, and as used in the schematic). Rail-torail op amps that are pin compatible include the TLC2272 and the TL972, but there are many others. The TLC2272 is cheap. Noise performance shouldn't be an issue with an LED output.

The op amp / trimmer combo is meant to amplify the typical 0.7-1.2V line level from standard consumer audio equipment to the full range of the LM3916, with the trimmer used to adjust for different input voltages and op amp gains.

Using R28 = 2K, and R29 = 3.3K, gives a full range of approx. 0-3.8V, with an LED current of aobut 9.7mA.

For my application, I used R25 = 10k, and R26 = 680, which gives the op amp a gain of approx. 15.7. This, with an input amplitude of 250mV, gives 3.925. The trimmer is then used to reduce the voltage to within the 0-3.8V range.

The tutorial here: https://learn.sparkfun.com/tutorials/dotbar-display-driver-hookup-guide is a really good guide to calculating resistor values.