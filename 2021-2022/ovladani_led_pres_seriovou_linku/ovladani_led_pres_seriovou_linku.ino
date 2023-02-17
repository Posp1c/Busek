unsigned long cas_predtim = 0;
byte stav = LOW;
byte rezim = 0;

void setup() {

  // nasteveni seriove linky
  Serial.begin(9600);

  // nastaveni pinu se zabudovanou LED
  pinMode(13, OUTPUT);
}

void loop() {

  // kontrola prijeti znaku do Arduina
  if (Serial.available() > 0) {
    
    // ulozeni znaku do promenne
    char c = Serial.read();
    
    // zmena rezimu na zaklade prijateho znaku
    switch (c) {
      case 'z':
        rezim = 1;
        break;

      case 'v':
        rezim = 2;
        break;

      case 'b':
        rezim = 3;
        break;
    }
  }

  // obsluha LED (musi byt mimo kontrolu znaku, aby se provadelo i pri neprijeti znaku)
  switch (rezim) {
    case 1:

      // zhasne LED
      stav = HIGH;
      break;

    case 2:

      // rozsviti LED
      stav = LOW;
      break;

    case 3:

      // blika LED
      unsigned long cas_ted = millis();
      if (cas_ted - cas_predtim >= 1000) {
        stav = !stav;
        cas_predtim = cas_ted;
      }
      break;
  }

  // nastaevni pinu
  digitalWrite(13, stav);
}
