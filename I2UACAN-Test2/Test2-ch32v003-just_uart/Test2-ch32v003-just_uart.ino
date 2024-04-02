// this is a test of the ch32v003 board with just the uart
// uart pin, Tx is pin 2(PD5), Rx is pin 3(PD6)
// send count to uart

#include <Wire.h>

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    delay(1);
  }
  delay(1000);
  Serial.println("ch32v003-just_uart");
}

void loop() {
  /*
  static uint8_t count = 1;  // counter until 1byte
  if (count < 255) {
    count++;
  } else {
    count = 1;
  }
  */

  // serial send
  // Serial.write("H"); // header
  Serial.println(4033);

  delay(100);
}
