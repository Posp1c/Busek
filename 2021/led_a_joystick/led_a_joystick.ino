void setup() {
  pinMode(3, OUTPUT);
}

void loop() {
  int hodnota = analogRead(A0);
  byte intenzita = map(hodnota, 0, 1023, 0 , 255);
  analogWrite(3, intenzita);
}
