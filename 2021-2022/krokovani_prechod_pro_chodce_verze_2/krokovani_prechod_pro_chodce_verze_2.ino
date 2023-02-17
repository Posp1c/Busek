#define PIN_TL  3
#define PIN_CER 4
#define PIN_ZEL 5

#define STAV_SVITI_CERVENA  0
#define STAV_SVITI_ZELENA   1
#define STAV_CEKEJ_10S      2
#define STAV_CEKEJ_5S       3

byte stav = STAV_SVITI_CERVENA;
byte tl_predchozi = HIGH;
unsigned long cas_udalosti = 0;

void setup() {
  pinMode(PIN_TL, INPUT_PULLUP);
  pinMode(PIN_CER, OUTPUT);
  pinMode(PIN_ZEL, OUTPUT);
}

void loop() {
  unsigned long cas_aktualni = millis();

  switch (stav) {

    // stav: sviti cervena
    case STAV_SVITI_CERVENA:
      digitalWrite(PIN_CER, HIGH);
      digitalWrite(PIN_ZEL, LOW);
      // detekce stisku tlacitka
      if (bylo_tlacitko_stisknuto()) {
        cas_udalosti = cas_aktualni;
        stav = STAV_CEKEJ_10S;
      }
      break;

    case STAV_CEKEJ_10S:
      if (cas_aktualni - cas_udalosti >= 10000) {
        cas_udalosti = cas_aktualni;
        stav = STAV_SVITI_ZELENA;
      }
      break;

    // stav: sviti zelena
    case STAV_SVITI_ZELENA:
      digitalWrite(PIN_CER, LOW);
      digitalWrite(PIN_ZEL, HIGH);
      if (cas_aktualni - cas_udalosti >= 5000) {
        stav = STAV_SVITI_CERVENA;
      }      
      break;
    default:
      stav = STAV_SVITI_CERVENA;
      break;
  }
}

byte bylo_tlacitko_stisknuto() {
  byte vysledek = LOW;
  byte tl_aktualni = digitalRead(PIN_TL);
  if (tl_predchozi == HIGH && tl_aktualni == LOW ) {
    vysledek = HIGH;
  }
  tl_predchozi = tl_aktualni;
  return vysledek;
}
