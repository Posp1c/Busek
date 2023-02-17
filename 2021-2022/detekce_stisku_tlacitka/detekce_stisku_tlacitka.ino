/*
   Program pri stisku tlacitka pricte
   do promenne 1 a vypise hodnotu do
   seriove linky.
*/

int pocet = 0;
byte stav_predtim = true;

void setup() {
  // zpanuti seriove linky
  Serial.begin(9600);

  // nastaveni digitalniho vstup s pullup rezistorem
  pinMode(4, INPUT_PULLUP);
}

void loop() {

  // nacteni hodnoty digitalniho vstupu
  byte stav = digitalRead(4);

  // detekce sestupne hrany (kvuli zapnutemu pullup rezistoru)
  if (stav == false && stav_predtim == true) {

    // pricteni hodnoty do promenne pri stisku tlacitka
    pocet++;

    // vypsani do seriove linky
    Serial.println(pocet);
  }

  // aktualizace stavu tlacitka v pameti
  stav_predtim = stav;
}
