#define PIN_BTN 2
#define PIN_R   9
#define PIN_G   10
#define PIN_B   11

int predchozi_stav = HIGH;
int prepinac = LOW;

void setup() {
  // inicializace tlacitka
  pinMode(PIN_BTN, INPUT_PULLUP);

  // inicializace pinu s RGB led
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  
  // nacteni vychoziho stavu tlacitka
  predchozi_stav = digitalRead(PIN_BTN);

  // zapnuti seriove komunikace
  Serial.begin(9600);
}

void loop() {
  // nacteni stavu tlacitka
  int stav = digitalRead(PIN_BTN);

  if (stav == LOW && predchozi_stav == HIGH) {
    
    // bylo stisknuto tlacitko, neco udelej
    Serial.println("baf");

    prepinac = !prepinac;
    
  }

  // ulozeni aktualniho stavu tlacitka do pameti
  predchozi_stav = stav;

  digitalWrite(PIN_R, prepinac);
}
