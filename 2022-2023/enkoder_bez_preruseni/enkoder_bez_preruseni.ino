#define PINA  2
#define PINB  3

int sigA_pred = LOW;
int pocet = 0;

void setup() {
  // nastaveni pinu
  pinMode(PINA, INPUT);
  pinMode(PINB, INPUT);
  // nacteni pocatecniho stavu pinu
  sigA_pred = digitalRead(PINA);
  // zapnuti seriove linky (komunikace do PC)
  Serial.begin(115200);
}

void loop() {
  // ziskani stavu signalu A
  int sigA = digitalRead(PINA);
  // detekce nabezne hrany na signalu A
  if (sigA == HIGH && sigA_pred == LOW) {
    // ziskani stavu signalu B
    int sigB = digitalRead(PINB);
    // otoceni na jednu stranu
    if (sigB == HIGH) pocet++;
    // otoceni na druhou stranu
    if (sigB == LOW) pocet--;
  }
  // aktualizace predchozi hodnoty
  sigA_pred = sigA;
  // vypis do PC
  Serial.print(pocet);
  Serial.println();
  // kratka pauza
  delay(2);
}
