void setup() {
  pinMode(PD4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(PD4, HIGH);
  Serial.println("ON!");
  delay(1000);

  digitalWrite(PD4, LOW);
  Serial.print("OFF!");
  delay(1000);
}