void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char znak = Serial.read();
    Serial.print("Napsal jsi mi: ");
    Serial.write(znak);
    Serial.println();
    /*
    if (znak == 'a') {
      
    }
    */
  }
}
