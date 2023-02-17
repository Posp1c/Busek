unsigned int pocet_acek = 0;
unsigned long cas_posledniho_prijateho_znaku = 0;
byte uz_poslano = LOW;

void setup() {

  // konfigurace seriove linky
  Serial.begin(9600);
}

void loop() {

  // kontrola poctu prijatych znaku
  if (Serial.available() > 0) {

    cas_posledniho_prijateho_znaku = millis();
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

  if (millis() - cas_posledniho_prijateho_znaku >= 5000 && uz_poslano == LOW) {
    pocet_acek = 0;
    uz_poslano = HIGH;
    Serial.println("vynulovano");
  }
}
