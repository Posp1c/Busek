void setup() {
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(3), pozdrav, FALLING);
  Serial.begin(9600);
}

void loop() {
  byte i = 0;
  bool b = LOW;
  while (b == LOW) {
    i++;
  }
  i = i +3;
}

void pozdrav() {
  Serial.println("ahoj");
}
