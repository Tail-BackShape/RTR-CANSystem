// read degree from UART-CH32V
// and send it to CAN

#include <CAN.h>

void setup()
{

  delay(2000);
  // setup serial
  Serial.begin(9600);
  Serial2.begin(9600); // for read ch32v uart.tx=io17,rx=io16
  while (!Serial)
  {
    delay(10);
  }

  // start the CAN bus at 500 kbps
  if (!CAN.begin(100E3))
  {
    Serial.println("Starting CAN failed!");
    while (1)
      ;
  }
  Serial.println("CAN Sender started");
}

void loop()
{
  int Uart2Data = 0, angle = 0, status = 0;                 // AS5600 data.
  byte statusByte = 0, angleHighByte = 0, angleLowByte = 0; // for CAN data.

  if (Serial2.available() > 0)
  {
    // read data from CH32V
    Uart2Data = Serial2.parseInt();
    status = Uart2Data % 100;
    angle = (Uart2Data - status) / 100;

    // change data to byte
    statusByte = lowByte(status);
    angleHighByte = highByte(angle);
    angleLowByte = lowByte(angle);

    // 各変数の状態チェック
    Serial.print("Uart2Data : ");
    Serial.println(Uart2Data);
    Serial.print("status: ");
    Serial.println(status);
    Serial.print("angle: ");
    Serial.println(angle);
    Serial.print("statusByte: ");
    Serial.println(statusByte);
    Serial.print("angleHighByte: ");
    Serial.println(angleHighByte);
    Serial.print("angleLowByte: ");
    Serial.println(angleLowByte);

    // send CAN packet
    Serial.println("Sending CAN packet ... ");
    CAN.beginPacket(0x12);
    CAN.write(status);
    CAN.write(angleHighByte);
    CAN.write(angleLowByte);
    CAN.endPacket();
    Serial.println("done");

    //delay(100);
  }
  /*

*/
}
