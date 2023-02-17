byte pocet = 0;
byte i = 0;
bool stav = LOW;
unsigned long ted = 0;
unsigned long predtim = 0;

void moje_funkce();

void setup() {
  pinMode(13, OUTPUT);
  delay(2000);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    pocet = Serial.read()-48;
    Serial.println(pocet, DEC);
  }
  moje_funkce();
}

void moje_funkce() {
  // nacti aktualni pocet ms od spusteni Arduina
  ted = millis();
  // zkontroluj, zda ubehlo 500 ms
  if (ted - predtim >= 500 && i < pocet) {
    // zmen stav LED
    stav = !stav;
    // aktualizuj predchozi cas
    predtim = ted;
    // pokud pozadovany stav LED je nula, pricti i
    if (!stav) {
      i++;
    }
  }
  // nastav stav LED na prislusny vystup
  digitalWrite(13, stav);
}
