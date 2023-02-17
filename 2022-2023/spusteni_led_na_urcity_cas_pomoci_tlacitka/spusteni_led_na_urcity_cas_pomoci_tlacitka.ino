int tlacitko_predchozi = HIGH;
int stav = LOW;
unsigned long cas_stisknuti = 0;

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop() {
  // nacteni stavu tlacitka
  int tlacitko = digitalRead(2);
  if (tlacitko == LOW && tlacitko_predchozi == HIGH) {
    // ziskat cas stisknuti tlacitka
    if (stav == LOW) {
      cas_stisknuti = millis();
      // nastavit stav LED
      stav = HIGH;
    }
  }
  // porovnat aktualni cas a cas stisknuti tlacitka
  if (millis() - cas_stisknuti >= 2000) {
    stav = LOW;
  }
  // ulozeni predchoziho stavu tlacitka
  tlacitko_predchozi = tlacitko;
  // nastaveni LED
  digitalWrite(13, stav);
}
