#include <Wire.h>
#define AS5600_addr 0x36

// Function Prototype Declaration
byte read_AS5600(byte);
void write_AS5600(byte, byte);

void setup() {
  pinMode(PD4, OUTPUT);

  Wire.begin();
  Serial.begin(9600);
  while (!Serial) {
    delay(1);
  }

  delay(1000);
  byte offSetAngle1 = read_AS5600(0x0C);
  byte offSetAngle2 = read_AS5600(0x0D);

  write_AS5600(0x01, offSetAngle1);
  write_AS5600(0x02, offSetAngle2);
}

void loop() {
  // check status
  byte AS5600Status = read_AS5600(0x0B);
  AS5600Status = AS5600Status & 0B00111000;

  // read angle
  uint16_t angle1 = read_AS5600(0x0E);
  uint16_t angle2 = read_AS5600(0x0F);
  uint16_t angle = ((0x0F & angle1) << 8) | angle2;

  Serial.println(AS5600Status);

  Serial.println(angle);  // only print angle

  delay(20);
}

byte read_AS5600(byte addr) {
  Wire.beginTransmission(AS5600_addr);
  Wire.write(addr);
  Wire.endTransmission(false);
  Wire.requestFrom(AS5600_addr, 1, true);
  byte data = Wire.read();
  return data;
}

void write_AS5600(byte addr, byte data) {
  Wire.beginTransmission(AS5600_addr);
  Wire.write(addr);  // addressing
  Wire.write(data);  // write data
  Wire.endTransmission();
}
