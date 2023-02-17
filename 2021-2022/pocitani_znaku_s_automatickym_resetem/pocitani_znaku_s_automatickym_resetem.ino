unsigned int pocet_acek = 0;
unsigned long cas_posledniho_prijeti_znaku = 0;
byte uz_poslano = LOW;

void setup() {

  // konfigurace seriove linky
  Serial.begin(9600);

}

void loop() {

  // kontrola poctu prijatych znaku
  if (Serial.available() > 0) {

    // aktualizace casu prijeti posledniho znaku
    cas_posledniho_prijeti_znaku = millis();

    // vynulovani priznaku odeslani informace o resetu citace
    uz_poslano = LOW;

    // precteni nejstarsiho znaku
    char c = Serial.read();

    // kontrola, zda se jedna o znak a/A
    if (c == 'a' || c == 'A') {

      // pricteni poctu a/A
      pocet_acek++;
      Serial.print("pocet acek je: ");
      Serial.println(pocet_acek);
    }
  }

  // kontrola uplynuti 10 sekund od posledniho prijeti znaku
  if (millis() - cas_posledniho_prijeti_znaku >= 5000 && uz_poslano == LOW) {
    pocet_acek = 0;
    uz_poslano = HIGH;
    Serial.println("Doslo k vynulovani poctu acek.");
  }
}
