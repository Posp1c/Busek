byte LED = 0;
byte tlacitko_predchozi = HIGH;
bool stav = HIGH;
bool pridat = HIGH;

void setup() {
  // nastaveni pinu pro tlacitko s internim pullup rezistorem
  pinMode(2, INPUT_PULLUP);
  // nastaveni pinu pro LED s moznosti PWM (vlnka u cisla pinu)
  pinMode(3, OUTPUT);
}

void loop() {
  // detekce kratkodobeho stiknuti tlacitka
  byte tlacitko = digitalRead(2);
  if (tlacitko == LOW && tlacitko_predchozi == HIGH) {
    // zmena stavu
    stav = !stav;
  }
  // ulozeni soucasne hodnoty tlacitka do pameti
  tlacitko_predchozi = tlacitko;
  // pokud je stav log. 1, bude cyklovat intenzita sviceni LED
  if (stav == HIGH) {
    // jestlize je pridat v log. 1, bude se intenzita zvetsovat, jinak se bude zmensovat
    if (pridat == HIGH) {
      LED++;
    } else {
      LED--;
    }
    // pri dosazeni max. intenzity (255) dojde ke zmene promenne udavajici rust/klesani intenzity
    if (LED == 255) {
      pridat = LOW;
    }
    if (LED == 0) {
      pridat = HIGH;
    }
    // nastavit intenzitu LED
    analogWrite(3, LED);
  }
  // chvili pockat
  delay(10);
}
