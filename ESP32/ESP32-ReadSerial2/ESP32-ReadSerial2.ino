//シリアル2の受信割り込み

int LED = 18;
int count = 0;

void serialEvent2();
void twinkle();

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  Serial.println(" ");
  Serial2.begin(115200);

  delay(1000);
}

void loop() {
  twinkle();
  count++;
  delay(100);
}

void twinkle() {
  if ((count % 2) == 1) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
  Serial.print("count = ");
  Serial.print(count);
  Serial.print("\n");
}

void serialEvent2() {
  if (Serial2.available() > 0) {
    // シリアルデータの受信 (改行まで)
    String data = Serial2.readStringUntil('\n');

    // 受信したデータを出力
    Serial.print("Receive:");
    Serial.println(data);
  }
}
