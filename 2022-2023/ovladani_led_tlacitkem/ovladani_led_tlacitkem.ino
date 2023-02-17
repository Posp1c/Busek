int tlacitko_predchozi = HIGH;
int stav = LOW;

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop() {
  int tlacitko = digitalRead(2);
  if (tlacitko == LOW && tlacitko_predchozi == HIGH) {
    stav = !stav;
  }
  tlacitko_predchozi = tlacitko;
  digitalWrite(13, stav);
  delay(20000);
}
