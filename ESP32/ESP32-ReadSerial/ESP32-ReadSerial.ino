int LED = 18;
int count = 0;

void serialEvent();
void twinkle();

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  Serial.println(" ");
  Serial2.begin(115200);

  delay(1000);
}

void loop() {
  Serial2.print("count = ");
  Serial2.print(count);
  Serial2.print("\n");
  twinkle();
  // readUartData();
  count++;
  delay(100);
}

void twinkle() {
  if ((count % 2) == 1) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}

void serialEvent() {
  if (Serial.available() > 0) {
    // シリアルデータの受信 (改行まで)
    String data = Serial.readStringUntil('\n');

    // 受信したデータを出力
    Serial.print("Receive:");
    Serial.println(data);
  }
}
