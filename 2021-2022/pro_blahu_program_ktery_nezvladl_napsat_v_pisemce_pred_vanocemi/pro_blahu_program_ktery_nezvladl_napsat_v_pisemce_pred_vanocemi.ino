/*
   Program detekuje otaceni enkoderu bez pouziti preruseni a nastavuje intenzitu LED.
*/

// definice zastupnych symbolu

#define PIN_CLK     2
#define PIN_DT      3
#define PIN_BTN     4
#define PIN_BLUE    5
#define PIN_GREEN   6
#define PIN_RED     9

byte predchoziCLK;
unsigned long predchoziUS;
unsigned long predchoziMS;
byte cislo = 0;
byte stav = false;

void setup() {

  // nastaveni digitalnich vstupu

  pinMode(PIN_CLK, INPUT);  // A
  pinMode(PIN_DT, INPUT);   // B

  // nastaveni analogoveho vystupu

  pinMode(PIN_BLUE, OUTPUT);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);

  // inicializace seriove linky

  Serial.begin(9600);

  // nacteni vychozi hodnoty CLK

  predchoziCLK = digitalRead(PIN_CLK);
  cislo = 100;
}

void loop() {
  unsigned long aktualniUS = micros();
  unsigned long aktualniMS = millis();

  if (aktualniUS - predchoziUS >= 1000) {

    // nacteni aktualni hodnoty CLK

    byte aktualniCLK = digitalRead(PIN_CLK);

    // detekce nabezne hrany CLK

    if (aktualniCLK != predchoziCLK && aktualniCLK == true) {

      // detekce stavu DT

      if (digitalRead(PIN_DT) != aktualniCLK) {
        if (cislo < 1000) cislo++;
      } else {
        if (cislo > 100) cislo--;
      }

      // vypsani aktualniho cisla

      Serial.println(cislo);
    }

    // aktualizace predchoziho stavu CLK

    predchoziCLK = aktualniCLK;

    predchoziUS = aktualniUS;

  }

  if (aktualniMS - predchoziMS >= cislo) {

    if (stav < 2) stav++;
    else stav = 0;

    predchoziMS = aktualniMS;
  }

  switch (stav) {
    case 0:
      digitalWrite(PIN_RED, HIGH);
      digitalWrite(PIN_GREEN, LOW);
      digitalWrite(PIN_BLUE, LOW);
      break;
    case 1:
      digitalWrite(PIN_RED, LOW);
      digitalWrite(PIN_GREEN, HIGH);
      digitalWrite(PIN_BLUE, LOW);
      break;
    case 2:
      digitalWrite(PIN_RED, LOW);
      digitalWrite(PIN_GREEN, LOW);
      digitalWrite(PIN_BLUE, HIGH);
      break;
  }

}

/*
   vice info napriklad zde: https://lastminuteengineers.com/rotary-encoder-arduino-tutorial/
*/
