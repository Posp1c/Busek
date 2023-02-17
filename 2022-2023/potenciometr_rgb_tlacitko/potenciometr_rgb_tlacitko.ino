#define PIN_TL  2
#define PIN_R   9
#define PIN_G   10
#define PIN_B   11

int stav_tlacitka_predchozi = HIGH;
byte barva = 1;

void setup() {
  pinMode(PIN_TL, INPUT_PULLUP);
  stav_tlacitka_predchozi = digitalRead(PIN_TL);
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  /*
   * OBSLUHA TLACITKA
   */
  int stav_tlacitka = digitalRead(PIN_TL);
  if (stav_tlacitka == LOW && stav_tlacitka_predchozi == HIGH) {
    if (barva < 3) barva++;
    else barva = 1;
  }
  stav_tlacitka_predchozi = stav_tlacitka;

  /*
   * OBSLUHA BAREV
   */
  switch (barva) {
    case 1:
      digitalWrite(PIN_R, HIGH);
      digitalWrite(PIN_G, LOW);
      digitalWrite(PIN_B, LOW);
      break;
    case 2:
      digitalWrite(PIN_R, LOW);
      digitalWrite(PIN_G, HIGH);
      digitalWrite(PIN_B, LOW);
      break;
    case 3:
      digitalWrite(PIN_R, LOW);
      digitalWrite(PIN_G, LOW);
      digitalWrite(PIN_B, HIGH);
      break;
  }

  Serial.println(barva);
}
