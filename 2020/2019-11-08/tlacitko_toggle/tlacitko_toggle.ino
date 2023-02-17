// globalni promenne
bool tlacitko_pred = LOW;
bool led = LOW;
bool tlacitko;

void setup() {
  // nastaveni pinu pro logicky vstup s pullup rezistorem
  pinMode(2, INPUT_PULLUP);
  // nastaveni vystupu pro LED na pinu 13 (vestavena LED na Arduinu)
  pinMode(13, OUTPUT);
}

void loop() {
  // prectu aktualni stav tlacitka
  tlacitko = digitalRead(2);
  // zkontroluji, zda sestupna hrana (v klidu je tlacitko
  if (tlacitko == LOW & tlacitko_pred == HIGH) {
    // provede negaci promenne led
    led = !led;
  }
  // nastav hodnotu LED
  digitalWrite(13, led);
  // nactu aktualni stav  tlacitka do predchozi hodnoty
  tlacitko_pred = tlacitko;
  // male zpomaleni smycky programu
  delay(50);
}
