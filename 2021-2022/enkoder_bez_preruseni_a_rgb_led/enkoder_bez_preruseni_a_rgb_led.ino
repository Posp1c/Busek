/*
   Program detekuje otaceni enkoderu bez pouziti preruseni a nastavuje intenzitu LED.
*/

// makra pro pridruzeni identifikatoru

#define PIN_DT      3
#define PIN_CLK     2
#define PIN_SW      4
#define PIN_RED     9
#define PIN_GREEN   10
#define PIN_BLUE    11

byte predchoziCLK;
byte cislo = 0;

void setup() {

  // nastaveni digitalnich vstupu

  pinMode(PIN_CLK, INPUT);        // A
  pinMode(PIN_DT, INPUT);         // B
  pinMode(PIN_SW, INPUT_PULLUP);  // tlacitko

  // nastaveni analogoveho vystupu

  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);

  // inicializace seriove linky

  Serial.begin(9600);

  // nacteni vychozi hodnoty CLK

  predchoziCLK = digitalRead(PIN_CLK);

}

void loop() {

  enkoder();

  // kratky delay proti zakmitu kontaktu

  delay(1);
}

void enkoder() {
  // nacteni aktualni hodnoty CLK

  byte aktualniCLK = digitalRead(PIN_CLK);

  // detekce nabezne hrany CLK

  if (aktualniCLK != predchoziCLK && aktualniCLK == true) {

    // detekce stavu DT

    if (digitalRead(PIN_DT) != aktualniCLK) {
      cislo++;
      Serial.print("CW: ");
    } else {
      cislo--;
      Serial.print("CCW: ");
    }

    // vypsani aktualniho cisla

    Serial.println(cislo);
  }

  // aktualizace predchoziho stavu CLK

  predchoziCLK = aktualniCLK;
}

/*
   vice info napriklad zde: https://lastminuteengineers.com/rotary-encoder-arduino-tutorial/
*/
