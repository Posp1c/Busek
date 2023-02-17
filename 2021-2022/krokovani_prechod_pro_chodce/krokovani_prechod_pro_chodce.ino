#define PIN_TL  5
#define PIN_CER 6
#define PIN_ZEL 7

#define STAV_SVITI_CERVENA  0
#define STAV_SVITI_ZELENA   1
#define STAV_CEKEJ_10S      2

byte stav = 0;              // stav zarizeni
byte tl_stav_pred = HIGH;   // predchozi stav tlacitka
unsigned int cas_udalosti = 0;

void setup() {
  // nastaveni funkce pinu
  pinMode(PIN_TL, INPUT_PULLUP);
  pinMode(PIN_CER, OUTPUT);
  pinMode(PIN_ZEL, OUTPUT);

  // pocatecni zhasnuti svetel semaforu
  digitalWrite(PIN_CER, LOW);
  digitalWrite(PIN_ZEL, LOW);
}

void loop() {
  unsigned long cas_aktualni = millis();

  switch (stav) {
    // stav: sviti cervena
    case STAV_SVITI_CERVENA:
      // rozsvitit cervenou
      digitalWrite(PIN_CER, HIGH);
      // zhasnout zelenou
      digitalWrite(PIN_ZEL, LOW);
      if (bylo_stisknuto_tlacitko()) {
        cas_udalosti = cas_aktualni;
        stav = STAV_CEKEJ_10S;
      }
      break;
    case STAV_CEKEJ_10S:
      if (cas_aktualni - cas_udalosti >= 10000) {
        stav = STAV_SVITI_ZELENA;
      }
      break;
    // stav: sviti zelena
    case STAV_SVITI_ZELENA:
      // zhasnout cervenou
      digitalWrite(PIN_CER, LOW);
      // rozsvitit zelenou
      digitalWrite(PIN_ZEL, HIGH);
      if (bylo_stisknuto_tlacitko()) {
        stav = STAV_SVITI_CERVENA;
      }
      break;
    default:
      stav = STAV_SVITI_CERVENA;
      break;
  }
}

byte bylo_stisknuto_tlacitko() {
  byte tl_stav = digitalRead(PIN_TL);
  byte vysledek = LOW;
  if (tl_stav_pred == HIGH && tl_stav == LOW) {
    vysledek = HIGH;
  }
  tl_stav_pred = tl_stav;
  return vysledek;
}
