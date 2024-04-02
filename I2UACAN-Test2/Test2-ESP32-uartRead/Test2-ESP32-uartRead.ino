// read degree from UART-CH32V
// and send it to CAN

#include <CAN.h>

byte CANAddr = 0x12;  // CANアドレス

// volatile int Uart2Data = 0; // uart2で受信したデータの格納
const int LED = 18;  // LED pin

void twinkle();       // LEDを点滅させる関数
void serialEvent2();  // シリアル2の受信割り込み関数
void CANsender();     // CAN送信関数

void setup() {
  // setup serial
  Serial.begin(9600);
  Serial2.begin(9600);  // Serial2 tx=io17, rx=io16
  while (!Serial) {
    delay(10);
  }

  // setup LED for checking
  pinMode(LED, OUTPUT);

  // setup CAN
  if (!CAN.begin(500E3)) {
    Serial.println("Starting CAN failed!");
    while (1)
      ;
  }
  Serial.println("CAN Sender started");
}

void loop() {
  if (Serial2.available() > 0) {
    int Uart2Data = Serial2.parseInt();
    int status, angle;
    status = Uart2Data % 100;
    angle = (Uart2Data - status) / 100;

    //Serial.println(Uart2Data);
    Serial.println(status);
    Serial.println(angle);

    /*
    int firstDigits = Uart2Data;
    while (firstDigits >= 100) {
      firstDigits /= 10;
    }
    Serial.println(firstDigits);
    */
  }
}
