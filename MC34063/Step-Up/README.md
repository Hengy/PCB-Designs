# MC34063 Step Up Converter

This project was designed for stepping up 5-24V to >200V for a Nixie Tube clock, but is also suitable for many other output voltages.

Output voltage is set using the trimmer R5 and voltage divider R4, R6.

C2, C5, and C6 should be rated for at least twice the output voltage. Low ESR recommended.

D1 should be schottky diode type with a rating greater than the output voltage.

Q1 N-Channel MOSFET should be rated greater than output voltage.

R3 should be 1K

T1 is a general purpose PNP BJT transistor SOT223 package


For 200V output:
C1: 50V 200uF 3.5mm x 8mm Package
R1|R2: 0.25 Ohms 1206 Package
Q1: FQP22N30 TO-220 Package
L1: 150uH 2A DRA127 Package
D1: US2FA 300V 1.5A SMA Package
C6: 400V 4.7uF 3.5mm x 8mm Package
C5: 500V 0.1uF 1206 Package
R4: 250K Ohm 0805 Package
R5: 100K Trimmer
R6: 2K Ohm 0805 Package