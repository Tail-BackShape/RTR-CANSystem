void setup() {
  pinMode(PB0, OUTPUT);
}

void loop() {
  digitalWrite(PB0, HIGH);
  delay(1000);
  digitalWrite(PB0, LOW);
  delay(1000);
}