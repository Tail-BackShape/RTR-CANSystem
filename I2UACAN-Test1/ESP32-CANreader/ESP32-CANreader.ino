// read degree from CAN BUS
// and send it to Serial.print

#include <CAN.h>

// byte sendDegAddr = 0x0F; // send degree address

void setup()
{
  Serial.begin(115200);
  while (!Serial)
  {
    delay(1);
  }
  Serial.println("CAN Receiver");

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
  // scan packet size
  int packetSize = CAN.parsePacket();

  if (packetsize || CAN.packetId() != -1)
  {
    // resive packet
    Serial.print("Received ");

    if (CAN.packetExtended())
    {
      Serial.print("extended ");
    }

    if (CAN.packetRtr())
    {
      // Remote transmission request, packet contains no data
      Serial.print("RTR ");
    }

    Serial.print("packet with id 0x");
    Serial.print(CAN.packetId(), HEX);

    if (CAN.packetRtr())
    {
      Serial.print((" and requested length "));
      Serial.println(CAN.packetDlc());
    }
    else
    {
      Serial.print(" and length ");
      Serial.println(packetSize);

      while (CAN.available())
      {
        Serial.print((char)CAN.read());
      }
      Serial.println();
    }
  }
}
