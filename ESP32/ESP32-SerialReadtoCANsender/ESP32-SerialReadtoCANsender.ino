#include <CAN.h>

volatile int Mgdeg = 0; // Magnetic degree
const int LED = 18;     // LED pin
int count = 0;          // counter

void twinkle();       // LEDを点滅させる
void serialEvent2();  // シリアル2の受信割り込み
void CANsender(byte); // CAN送信

void setup()
{
  // setup serial
  Serial.begin(115200);
  Serial2.begin(115200);
  while (!Serial)
  {
    delay(10);
  }

  // setup LED for checking
  pinMode(LED, OUTPUT);

  // setup CAN
  if (!CAN.begin(1000E3))
  {
    Serial.println("Starting CAN failed!");
    while (1)
      ;
  }
  Serial.println("CAN Sender started");
}

void loop()
{
  CANsender(Mgdeg);
  twinkle();
  count++;
  delay(100);
}

void twinkle()
{
  if ((count % 2) == 1)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
  Serial.print("count = ");
  Serial.print(count);
  Serial.print("\n");
}

void serialEvent2()
{
  if (Serial2.available() > 0)
  {
    // シリアルデータの受信 (改行まで)
    String data = Serial2.readStringUntil('\n');

    // 受信したデータを出力
    Serial.print("Receive:");
    Serial.println(data);

    Mgdeg = data.toInt();
  }
}

void CANsender(byte data)
{
  byte prime8bit = data >> 8;    // 16bitの上位8bit
  byte latter8bit = data & 0x0F; // 16bitの下位8bit
  Serial.print("prime8bit: ");
  Serial.println(prime8bit, HEX);
  Serial.print("latter8bit: ");
  Serial.println(latter8bit, HEX);

  Serial.println("Sending packet ... ");

  CAN.beginPacket(0x0F);
  CAN.write(prime8bit);
  CAN.write(latter8bit);
  CAN.endPacket();
}
