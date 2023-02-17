/*
   Program detekuje otaceni enkoderu bez pouziti preruseni a nastavuje intenzitu LED.
*/

// definice zastupnych symbolu

#define PIN_DT      3
#define PIN_CLK     2

volatile byte cislo = 0;

void setup() {

  // nastaveni digitalnich vstupu

  pinMode(PIN_CLK, INPUT);  // A
  pinMode(PIN_DT, INPUT);   // B

  attachInterrupt(digitalPinToInterrupt(2), petr, RISING);

  // inicializace seriove linky

  Serial.begin(9600);

}

void loop() {

  // kratky delay proti zakmitu kontaktu

  delay(100000);
}

void petr() {
  noInterrupts();
  if (digitalRead(PIN_DT) == LOW) {
    cislo++;
  } else {
    cislo--;
  }
  Serial.println(cislo);
  interrupts();
}

/*
   vice info napriklad zde: https://lastminuteengineers.com/rotary-encoder-arduino-tutorial/
*/
