uint16_t count = 0;
uint8_t nopDelay = 3;

void writeWord(uint16_t w) {
  noInterrupts();
  for (int i=11; i>=0; i--) {
    if ( w & _BV(i) ) {
      PORTB |= _BV(0);  // pin 8 HIGH
      delayMicroseconds(nopDelay);
      PORTB &= ~_BV(0);  // pin 8 LOW
      delayMicroseconds(nopDelay);
      PORTB |= _BV(0);  // pin 8 HIGH
      delayMicroseconds(nopDelay);
      PORTB &= ~_BV(0);  // pin 8 LOW
      delayMicroseconds(1);
    } else {
      PORTB |= _BV(0);  // pin 8 HIGH
      delayMicroseconds(nopDelay);
      PORTB &= ~_BV(0);  // pin 8 LOW
      delayMicroseconds(nopDelay*2);
    }
  }
  interrupts();
}

void writeEOS() {
  noInterrupts();
  for (int i=0; i<40; i++) {
    delayMicroseconds(1);
  }
  interrupts();
}

void writeGSLAT() {
  noInterrupts();
  for (int i=0; i<200; i++) {
    delayMicroseconds(1);
  }
  interrupts();
}

void writeStrict(uint16_t r, uint16_t g, uint16_t b) {
  writeWord(0x3AA);
  writeWord(r);   // red - chan 2
  writeWord(g);   // green - chan 1
  writeWord(b);   // blue - chan 0
}

void setup() {
  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);
}

void loop() {
  writeStrict(count, count, count);
  writeGSLAT();
  count++;
  if (count > 4095) {
    count = 0;
  }
  delay(12);
}
