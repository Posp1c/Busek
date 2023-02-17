// globalni promenna pro zaznam casu smycky
unsigned long predchoziMS = 0;

void setup() {
  // zapnuti seriove linky pro komunikaci s PC pres USB (COM port)
  Serial.begin(9600);

  // nastaveni 'direction register' pro konfiguraci pinu 11, 12, 13 jako vystupy
  DDRB = B00111000;

  // nastaveni 'data register'
  PORTB = B00000100;  // nastaveni logicke HIGH na pinu 10, ktery ale neni vystupem, takze ani jedna LED na pinech 11, 12, 13 nebude svitit
}

void loop() {
  // ziskani aktualniho casu
  unsigned long aktualniMS = millis();

  // kontrola uplynuti casu
  if (aktualniMS - predchoziMS >= 500) {

    // kontrola zapnuti pinu 13
    if (PORTB < B00100000) {
      
      // posun zapnuti pinu o jeden pin
      PORTB = PORTB << 1;
    } else {

      // vypnuti vsech led zapnutim pinu 10, ktery neni nastaveny jako vystup
      PORTB = B00000100;
    }

    // aktualizace casu smycky
    predchoziMS = aktualniMS;
  }
}
