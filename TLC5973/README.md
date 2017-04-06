# TLC5973

This PCB was designed to control brightness for LED drivers - that is, it provides 3 channels of non-inverted 12-bit PWM.

Since the TLC5973 has current sink outputs, the PWM signal is inverted. The output transistor will invert the signal again, resulting in a non-inverted output.

R1 sets output current. For driving the BJTs, 35mA is sufficient.

R3-R5 should be sized to provide all output current to the BJTs base. I used 100 Ohms.

R6-R8 should be 10K Ohms.

Q1-Q3 are SOT23-3 PNP BJT transistors.

This can be run on 3.3V, but output current is limited.