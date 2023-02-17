void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    switch (c) {
      case 'a':
        Serial.println("Jak se mas?");
        break;
      case 'b':
        Serial.println("Jak bylo ve skole?");
        break;
      default:
        Serial.println("Nerozumim ti.");
        break;
    }
  }
}
