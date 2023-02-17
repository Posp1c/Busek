#define PINA  2
#define PINB  3

volatile int pocet = 0;

void setup() {
  // nastaveni pinu
  pinMode(PINA, INPUT);
  pinMode(PINB, INPUT);

  // zapnuti preruseni
  attachInterrupt(digitalPinToInterrupt(PINA), obsluha_preruseni, RISING);

  // zapnuti seriove linky (komunikace do PC)
  Serial.begin(115200);
}

void loop() {
  // vypis do PC
  Serial.print(pocet);
  Serial.println();
  // kratka pauza
  delay(2000);
}

void obsluha_preruseni() {
  noInterrupts();
  // ziskani stavu signalu B
  int sigB = digitalRead(PINB);
  // otoceni na jednu stranu
  if (sigB == HIGH) pocet++;
  // otoceni na druhou stranu
  if (sigB == LOW) pocet--;
  interrupts();
}
