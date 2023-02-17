/*
 * Program vypisuje pocet ubehlych sekund od
 * spusteni Arduina.
 */

int pocet_sekund = 1;
unsigned long cas_predtim = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {

  // ziskani aktualniho poctu milisekund
  unsigned long cas_ted = millis();

  // kontrola ubehnuteho casu
  if (cas_ted - cas_predtim >= 1000) {

    // vypis do seriove linky
    Serial.print("Ahoj! Cislo je: ");
    Serial.println(pocet_sekund++);
    
    // aktulizace ulozeneho casu
    cas_predtim = cas_ted;
  }
}
