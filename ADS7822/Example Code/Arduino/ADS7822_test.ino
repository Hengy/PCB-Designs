// SPI library
#include <SPI.h>

// set pin 10 as the slave select
const int slaveSelectPin = 10;

// ADC output
uint16_t voltageBits = 0;
double voltage = 0;

const uint8_t numReadings = 20;

uint16_t readings[numReadings];                 // the readings from the analog input
uint8_t readIndex = 0;                // the index of the current reading
uint32_t total = 0;                   // the running total
uint16_t average = 0;                 // the average

// SPI dummy transfer data
const uint16_t dummy = 0;

// ADC data mask
uint16_t dataMask = 0x1FFE;

void setup() {
  Serial.begin(38400);
  // set the slaveSelectPin as an output
  pinMode(slaveSelectPin, OUTPUT);
  digitalWrite(slaveSelectPin, HIGH);
  // initialize SPI
  SPI.begin();
  // set bit order
  SPI.setBitOrder(MSBFIRST);
  // set data mode
  SPI.setDataMode(SPI_MODE1);
  // set speed
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  // initialize all readings to 0
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() {
  // subtract the last reading:
  total = total - readings[readIndex];
  
  // select ADC
  digitalWrite(slaveSelectPin, LOW);
  delayMicroseconds(1);
  
  // transfer voltage
  voltageBits = SPI.transfer16(dummy);

  // deselect ADC
  digitalWrite(slaveSelectPin, HIGH);

  // add new reading
  readings[readIndex] = ((voltageBits & dataMask) >> 1);
  // add the reading to the total
  total = total + readings[readIndex];
  // advance to the next position in the array
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning
    readIndex = 0;
  }
	
  // print voltage
  voltage = (total / numReadings) / 1000;
  Serial.print("Voltage: ");
  Serial.print(voltage, 3);
  Serial.print("\n");
  
  delay(200);
}
