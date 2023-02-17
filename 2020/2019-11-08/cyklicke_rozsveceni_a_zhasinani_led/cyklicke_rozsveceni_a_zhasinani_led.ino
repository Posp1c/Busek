void setup() {
  // nastaveni pinu jako vystup
  pinMode(3, OUTPUT);
}

void loop() {
  // rozsveceni LED
  for (byte i = 0; i < 255; i++) {
    analogWrite(3, i);
    delay(10);
  }
  // zhasinani LED
  for (byte i = 255; i > 0; i--) {
    analogWrite(3, i);
    delay(10);
  }
}
