// this is a test of the ch32v003 board with just the uart
// uart pin, Tx is pin 2(PD5), Rx is pin 3(PD6)
// send count to uart

#include <Wire.h>

const int LEDpin = PD4; // LED pin1

void setup()
{
  Serial.begin(9600);
  while (!Serial)
  {
    delay(1);
  }
  delay(1000);
  Serial.println("ch32v003-just_uart");
}

void loop()
{
  static int count = 0;
  Serial.println(count);
  count++;

  if (count % 2 == 0)
  {
    digitalWrite(LEDpin, HIGH);
  }
  else
  {
    digitalWrite(LEDpin, LOW);
  }

  delay(500);
}
