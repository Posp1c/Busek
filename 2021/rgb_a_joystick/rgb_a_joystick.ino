unsigned long predtim = 0;
byte intenzita[3] = {0};
bool sw_predchozi = HIGH;
byte index = 0;

void setup() {
  // konfigurace seriove linky
  Serial.begin(9600);

  // konfigurace pinu LED
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  // konfigurace pinu tlacitka
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  unsigned long ted = millis();

  // vzorkovani
  if (ted - predtim >= 50) {
    
    // nacteni polohy joysticku
    int prirustek = map(analogRead(A0), 0, 1023, -20, 20);
    
    // overeni rozahu (min. 0, max. 255)
    if (intenzita[index] + prirustek >= 0 && intenzita[index] + prirustek <= 255) {
      
      // uprava intenzity
      intenzita[index] += prirustek;
    }

    
    bool sw = digitalRead(2);
    
    // detekce stisknuti tlacitka (tzv. nabezne hrany)
    if (sw_predchozi && !sw) {

      // posouvani indexu barvy
      if (index < 2) index++;
      else index = 0;
    }
    sw_predchozi = sw;

    // vypis do PC
    Serial.print(intenzita[0]);
    Serial.print(",");
    Serial.print(intenzita[1]);
    Serial.print(",");
    Serial.println(intenzita[2]);

    // nastaveni intenzity LED
    analogWrite(9, intenzita[0]);
    analogWrite(10, intenzita[1]);
    analogWrite(11, intenzita[2]);

    // aktualizace casu pro vzorkovani
    predtim = ted;
  }
}
