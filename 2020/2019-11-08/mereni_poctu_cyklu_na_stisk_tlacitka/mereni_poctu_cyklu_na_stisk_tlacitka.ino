int i = 0;
void setup() {
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(2) == LOW) {
    i++;
  }
  delay(1000);
  if (millis() % 1000 == 0) {
    Serial.println(i);
  }
}
