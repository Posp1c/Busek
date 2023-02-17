#define PUL 2
#define RES 3

const byte prumer = 76;
const float pi = 3.14159;

const float obvod = pi*prumer;
float vzdalenost = 0.0;
float vzdalenost_predchozi = 0.0;
float rychlost = 0.0;

unsigned long cas_predchozi = 0;

byte senzor_predchozi;
byte reset_predchozi;

void setup() {
  pinMode(PUL, INPUT);
  senzor_predchozi = digitalRead(PUL);
  pinMode(RES, INPUT);
  reset_predchozi = digitalRead(RES);
  Serial.begin(9600);
}

void loop() {
  
  /* DETEKCE PULZU */

  byte senzor = digitalRead(PUL);
  if (senzor == HIGH && senzor_predchozi == LOW) {
    vzdalenost += obvod;
  }
  senzor_predchozi = senzor;

  /* DETEKCE STISKU TLACITKA */    

  byte reset = digitalRead(RES);
  if (reset == HIGH && reset_predchozi == LOW) {
    vzdalenost = 0.0;
  }
  reset_predchozi = reset;

  /* CASOVANI PRO MERENI RYCHLOSTI */

  unsigned long cas = millis();
  if (cas - cas_predchozi > 5000) {
    rychlost = 720.0*(vzdalenost - vzdalenost_predchozi);
    vzdalenost_predchozi = vzdalenost;
    cas_predchozi = cas;
    
    Serial.println(rychlost);
    Serial.println(vzdalenost);
  }
}