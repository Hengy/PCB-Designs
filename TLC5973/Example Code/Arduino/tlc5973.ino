uint16_t count = 33;
uint8_t nopDelay = 3;

uint16_t rgb[] = {2048,2048,2048};
float comp[] = {1.0,0.8,0.15};
float whiteComp[][3] = {
  {1.0,0.60,0.03},
  {1.0,0.63,0.04},
  {1.0,0.65,0.06},
  {1.0,0.67,0.08}
};
float gBright = 1.0;

#define NOP __asm__ __volatile__ ("nop\n\t")

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
      NOP;
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
    NOP;
  }
  interrupts();
}

void writeGSLAT() {
  noInterrupts();
  for (int i=0; i<200; i++) {
    NOP;
  }
  interrupts();
}

void writeStrict(uint16_t r, uint16_t g, uint16_t b) {
  writeWord(0x3AA);
  writeWord(r);   // red - chan 2
  writeWord(g);   // green - chan 1
  writeWord(b);   // blue - chan 0
}

void writeAll(uint16_t r, uint16_t g, uint16_t b) {
  writeWord(0x3AA);
  writeWord(r*comp[0]*gBright);   // red - chan 2
  writeWord(g*comp[1]*gBright);   // green - chan 1
  writeWord(b*comp[2]*gBright);   // blue - chan 0
}

void writeWhite(uint16_t v) {
  uint16_t r,g,b;
  if (v < 400) {
    r = v*whiteComp[0][0]*gBright+((4095-v)*0.07);
    g = v*whiteComp[0][1]*gBright;
    b = v*whiteComp[0][2]*gBright;
  } else if (v < 800) {
    r = v*whiteComp[1][0]*gBright+((4095-v)*0.08);
    g = v*whiteComp[1][1]*gBright;
    b = v*whiteComp[1][2]*gBright;
  } else if (v < 1500) {
    r = v*whiteComp[2][0]*gBright+((4095-v)*0.09);
    g = v*whiteComp[2][1]*gBright;
    b = v*whiteComp[2][2]*gBright;
  } else {
    r = v*whiteComp[3][0]*gBright+((4095-v)*0.11);
    g = v*whiteComp[3][1]*gBright;
    b = v*whiteComp[3][2]*gBright;
  }
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
//  writeWhite(count);
//  writeGSLAT();
//  count++;
//  if (count > 4095) {
//    delay(3000);
//    count = 33;
//  }
//  delay(10);

    writeStrict(0,0,4095);
    writeGSLAT();
    delay(5000);
    writeStrict(0,0,0);
    writeGSLAT();
    delay(200);
    writeStrict(0,0,2048);
    writeGSLAT();
    delay(5000);
    writeStrict(0,0,0);
    writeGSLAT();
    delay(200);
    writeStrict(0,0,1);
    writeGSLAT();
    delay(5000);
}
