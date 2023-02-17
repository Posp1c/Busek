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
byte predchoziBTN;
byte intenzita = 0;
byte rezim = 0;
unsigned long predchoziUS = 0;

void setup() {

  // nastaveni digitalnich vstupu

  pinMode(PIN_CLK, INPUT);  // A
  pinMode(PIN_DT, INPUT);   // B
  pinMode(PIN_BTN, INPUT_PULLUP); // tlacitko

  // nastaveni analogoveho vystupu

  pinMode(PIN_BLUE, OUTPUT);

  // inicializace seriove linky

  Serial.begin(9600);

  // nacteni vychozi hodnoty CLK

  predchoziCLK = digitalRead(PIN_CLK);

  // nacteni aktulniho casu

  predchoziUS = millis();

  // nacteni aktulniho stavu tlacitka

  predchoziBTN = digitalRead(PIN_BTN);

}

void loop() {

  unsigned long aktualniUS = micros();

  if (aktualniUS - predchoziUS >= 1000) {

    /*
     * Obsluha tlacitka
     */

    byte aktualniBTN = digitalRead(PIN_BTN);

    if (aktualniBTN == false && predchoziBTN == true) {

      if (rezim < 2) {

          rezim++;
          
      } else {

          rezim = 0;
          
      }

      Serial.println(rezim);

    }

    predchoziBTN = aktualniBTN;

    /*
     * Obsluha enkoderu
     */
    
    // nacteni aktualni hodnoty CLK

    byte aktualniCLK = digitalRead(PIN_CLK);

    // detekce nabezne hrany CLK

    if (aktualniCLK != predchoziCLK && aktualniCLK == true) {

      // detekce stavu DT

      if (digitalRead(PIN_DT) != aktualniCLK) {
        intenzita++;
      } else {
        intenzita--;
      }

      // vypsani aktualniho cisla

      Serial.println(intenzita);
    }

    // nastaveni analogove hodnoty

    analogWrite(PIN_BLUE, intenzita);

    // aktualizace predchoziho stavu CLK

    predchoziCLK = aktualniCLK;

    // aktualizace casu posledni smycky

    predchoziUS = aktualniUS;
  
  }
  
}

/*
   vice info napriklad zde: https://lastminuteengineers.com/rotary-encoder-arduino-tutorial/
*/
