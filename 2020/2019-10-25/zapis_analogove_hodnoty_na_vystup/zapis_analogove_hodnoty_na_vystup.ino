void setup() {
  pinMode(2, OUTPUT);  // nastaveni funkce GPIO pinu
}

void loop() {
  analogWrite(2, 127); // zapis analogove hodnoty na analogovy vystup
}
