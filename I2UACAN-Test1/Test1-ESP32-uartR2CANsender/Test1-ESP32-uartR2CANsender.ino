// Copyright (c) Sandeep Mistry. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <CAN.h>

uint8_t serVal = 0;
byte CANAddr = 0x12; // CANアドレス

void serRead(); // シリアル読み取り関数

void setup()
{
  Serial.begin(115200);
  while (!Serial)
    ;
  Serial2.begin(9600); // Serial2 tx=io17, rx=io16
  while (!Serial2)
    ;

  Serial.println("CAN Sender");

  // start the CAN bus at 500 kbps
  if (!CAN.begin(500E3))
  {
    Serial.println("Starting CAN failed!");
    while (1)
      ;
  }
}

void loop()
{
  serRead();
  
  // send packet: id is 11 bits, packet can contain up to 8 bytes of data
  Serial.print("Sending packet ... ");

  CAN.beginPacket(CANAddr);
  
  CAN.write(serVal);

  CAN.endPacket();

  Serial.println("done");

  delay(1000);
}

void serRead()
{
  if (Serial2.available() > 0)
  {
    serVal = Serial2.read();
    Serial.print("serVal = ");
    Serial.println(serVal);
  }
}
