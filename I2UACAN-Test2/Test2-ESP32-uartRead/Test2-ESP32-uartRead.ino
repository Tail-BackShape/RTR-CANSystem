// read degree from UART-CH32V

void setup()
{
  // setup serial
  Serial.begin(9600);
  Serial2.begin(9600); // Serial2 tx=io17, rx=io16
  while (!Serial)
  {
    delay(10);
  }
}

void loop()
{
  if (Serial2.available() > 0)
  {
    int Uart2Data = Serial2.parseInt();
    int status, angle;
    status = Uart2Data % 100;
    angle = (Uart2Data - status) / 100;

    // Serial.println(Uart2Data);
    Serial.println(status);
    Serial.println(angle);
  }
}
