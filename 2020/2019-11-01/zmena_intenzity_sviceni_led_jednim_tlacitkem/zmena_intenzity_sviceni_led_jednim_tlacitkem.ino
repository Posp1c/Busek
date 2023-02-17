/*
 * Zapojeni:
 * tlacitko ~ pin 4, GND
 * LED + 220R ~ pin 3, GND
 */
byte x = 0; // pomocna promenna pro ukladani aktualni intenzity

void setup() {
  pinMode(4, INPUT_PULLUP); // nastavi vstup s pullup rezistorem
}

void loop() {
  if (digitalRead(4) == LOW) {  // detekce stisknuteho tlacitka (LOW protoze pullup)
    x = x + 1;  // pricte 1 k aktualni hodnote x
  }
  analogWrite(3, x);  // nastavi PWM na pinu 3 (LED) na hodnotu x
  delay(10);          // chvili pocka, aby se intenzita nemenila prilis rychle
}
