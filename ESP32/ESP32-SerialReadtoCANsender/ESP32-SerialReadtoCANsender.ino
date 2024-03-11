#include <CAN.h>

const int LED = 18; // LED pin
int count = 0;      // counter
int Mgdeg = 0;      // Magnetic degree

void twinkle();      // LEDを点滅させる
void serialEvent2(); // シリアル2の受信割り込み
void CANsend();      // CAN送信

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
  }
}

void CANsend()
{
  Serial.println("Sending packet ... ");

  CAN.beginPacket(0x0F);
  CAN.write('h');
  CAN.endPacket();
}
