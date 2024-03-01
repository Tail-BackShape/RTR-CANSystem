void setup() {
  Serial.begin(115200);

  pinMode(PD4, OUTPUT);
  digitalWrite(PD4, LOW);
  pinMode(PC0, OUTPUT);
  digitalWrite(PC0, HIGH);
}

void loop() {
  digitalWrite(PD4, HIGH);
  delay(200);
  Serial.write("HIGH\n");

  digitalWrite(PD4, LOW);
  delay(200);
  Serial.write("LOW\n");
}
