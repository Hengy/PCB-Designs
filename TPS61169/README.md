# TPS61169 LED Driver

There are three different PCB designs for the TPS61169.

The power supply used plays a large role in the ability of this driver to drive LEDs. It must be capable of sourcing 2-4x the LED output current, and be able to handle large transients typical of a boost converter.

Note: the max input voltage of the TPS61169 is 5.5V!

TPS61169_Tant is the smallest layout, and uses a tantalum capacitor on the input. This is suitable for driving small LED loads (up to 200mA, ~20V).

TPS61169_El uses a electrolytic capacitor on the input. This is suitable for small to moderate LED loads (up to 350mA, ~24V). The electrolytic cap should be greater than 330uF, and low ESR.

L1 is 4.7-10uH, CD54 package, and should be rated for 2-3x the LED current. There are two footprints in the PCB, one for SMD, and one for through hole.

C3, C4 should be 1-2.2uF, 1206 package, X7R or better, and rated for greater than twice the LED voltage.

R2-R5 allow for parallel feedback resistors. This makes it easier, and sometimes less expensive to get the correct feedback resistance for a given LED current.

D1 should be a Schottky diode, rated for greater than the LED voltage, and greater than the output current.

Output capability of the above two designs can be increased by putting more capacitance on the input.

TPS61169_HPLED is a larger PCB design with a larger inductor footprint (DR125 package) and two electrolytic input capacitors. This is suitable for getting driving high power LEDs from the TPS61169 (up to 750mA, 38V). 

Note: I have not tested the TPS61169 at greater than 500mA, ~24V output.

PWM Dimming:

The TPS61169 uses PWM on the CTRL pin to impliment dimming. The datasheet states a minimum of 5KHz PWM frequency. My own tests using the TLC5973 with a PWM frequency of ~3KHz to be adaquate in the range of 5-100% duty cycle, however, the first 5% is poor, turning on the LEDs fairly brightly even at 0.5% duty. Using a >5KHz PWM frequency may have better results.