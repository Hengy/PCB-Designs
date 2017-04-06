# Digispark Clone

This was designed to use the Digispark bootloader, and drive WS2812/SK6812 addressable LEDs.

R20 & R21 are 68 Ohms 0805.

Uses USB Mini connector.

Sensor Connect jumper is designed to allow programming with USB without removing a sensor connected to PB4 (USB D+)

Uses ATtiny85.

Note: Programming process is somewhat complicated. First program must be with a AVR ISP. It is recommended to first program the Micronucleus bootloader version with Reset (PB5) enabled. This allows it to be programmed again using ISP. If successful, one can then program the version with Reset disabled for an extra I/O pin.
Nothing can be connected to USB D+/D- (PB4/PB5) while programming using USB. Some computers will not recognize this as a USB device because of the lack of Zener diodes on the data lines. A USB hub is recommended for extra protection/compatability.