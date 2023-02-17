/*
 * Program detekuje otaceni enkoderu bez pouziti preruseni a nastavuje intenzitu LED.
 */

// definice zastupnych symbolu

#define PIN_DT      3
#define PIN_CLK     2
#define PIN_BLUE    5

byte predchoziCLK;
byte cislo = 0;

void setup() {

  // nastaveni digitalnich vstupu
  
  pinMode(PIN_CLK, INPUT);  // A
  pinMode(PIN_DT, INPUT);   // B

  // nastaveni analogoveho vystupu
  
  pinMode(PIN_BLUE, OUTPUT);
  
  // inicializace seriove linky
  
  Serial.begin(9600);

  // nacteni vychozi hodnoty CLK
  
  predchoziCLK = digitalRead(PIN_CLK);
  
}

void loop() {
  
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

  // nastaveni analogove hodnoty

  analogWrite(PIN_BLUE, cislo);

  // aktualizace predchoziho stavu CLK
  
  predchoziCLK = aktualniCLK;

  // kratky delay proti zakmitu kontaktu
  
  delay(1);
}

/*
   vice info napriklad zde: https://lastminuteengineers.com/rotary-encoder-arduino-tutorial/
*/
