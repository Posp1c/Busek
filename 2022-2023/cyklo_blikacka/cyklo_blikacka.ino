#define PIN_BTN 2
#define PIN_R   9
#define PIN_G   10
#define PIN_B   11

int predchozi_stav = HIGH;
int prepinac = LOW;
int on_off = LOW;
byte cervena = 0;

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

    on_off = !on_off;
    
  }

  if (on_off) blikani();
  else digitalWrite(PIN_R, LOW);

  // ulozeni aktualniho stavu tlacitka do pameti
  predchozi_stav = stav;

}

void blikani() {
  // nastaveni PWM hodnoty
  analogWrite(PIN_R, cervena);

  // prepinani pricitani a odcitani intenzity podle prepinace
  if (prepinac) cervena++;
  else cervena--;

  // zmena prepinace pri dosazeni krajnich poloh intenzity
  if (cervena == 255) prepinac = LOW;
  else if (cervena == 0) prepinac = HIGH;

  // kratka prodleva (cim mensi, tim rychlejsi blikani)
  delay(1);  
}
