volatile int stav = LOW;

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), blik, FALLING);
}

void loop() {
  delay(10000);
}

void blik() {
  stav = !stav;
  digitalWrite(13, stav);
}
