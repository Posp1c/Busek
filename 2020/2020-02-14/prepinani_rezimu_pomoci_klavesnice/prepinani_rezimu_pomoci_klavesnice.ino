byte rezim = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(rezim);
  if (Serial.available() > 0) {
    char znak = Serial.read();
    // ROZHODOVACI SMYCKA 'IF'
//    if (znak == 'J') {
//      rezim = 0;
//    } else if (znak == 'K') {
//      rezim = 1;
//    } else {
//      // opatreni proti spatnemu prikazu
//      Serial.println("Spatny prikaz!");
//    }
    // ROZHODOVACI SMYCKA 'SWITCH-CASE'
    switch (znak) {
      case 'J':
        rezim = 0;
        break;
      case 'K':
        rezim = 1;
        break;
      default:
        // opatreni proti spatnemu prikazu
        Serial.println("Spatny prikaz!");
        break;
    }
  }
  ////// ZNAK
  ////// REZIM
  switch (rezim) {
    case 0:

      break;
    case 1:
    
      break;
  }
}
