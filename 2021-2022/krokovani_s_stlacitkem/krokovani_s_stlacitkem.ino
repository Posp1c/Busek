byte stav_predchozi = HIGH;
byte krok = 0;
byte tlacitko_stisknuto = LOW;
unsigned long cas_udalosti = 0;

void setup() {
  pinMode(3, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  obsluha_tlacitka();
  unsigned long cas_ted = millis();

  switch (krok) {
    case 0:
      Serial.println("krok 0");
      if (tlacitko_stisknuto == HIGH) {
        cas_udalosti = cas_ted;
        krok = 1;
      }
      break;
    case 1:
      if (cas_ted - cas_udalosti >= 3000) {
        krok = 2;
      }
      break;
    case 2:
      Serial.println("krok 2");
      break;
    case 3:
      Serial.println("krok 3");
      break;
  }
}

void obsluha_tlacitka() {
  byte stav = digitalRead(3);
  if (stav == LOW && stav_predchozi == HIGH) {
    tlacitko_stisknuto = HIGH;
  }
  else {
    tlacitko_stisknuto = LOW;
  }
  stav_predchozi = stav;
}
