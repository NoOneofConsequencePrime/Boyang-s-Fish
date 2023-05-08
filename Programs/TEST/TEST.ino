void setup() {
    pinMode(26, OUTPUT);
    Serial.begin(9600);
}

void loop() {
  digitalWrite(26, HIGH);
  delay(100);
  digitalWrite(26, LOW);
  delay(100);
  Serial.println("Running");
}