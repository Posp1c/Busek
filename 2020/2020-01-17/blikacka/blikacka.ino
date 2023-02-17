unsigned long ted = 0;
unsigned long predtim = 0;
bool rezim = LOW;
bool led = LOW;
int tlacitko_predtim = HIGH;

void setup() {
  pinMode(5, INPUT_PULLUP);
  pinMode(2, OUTPUT);
}

void loop() {
  ted = millis();
  int tlacitko = digitalRead(5);
  if (tlacitko == LOW & tlacitko_predtim == HIGH) {
    rezim = !rezim;
  } else {
    
  }
  tlacitko_predtim = tlacitko;
  if (rezim == HIGH) {
    if (ted - predtim >= 1000) {
      predtim = ted;
      led = !led;
      digitalWrite(2, led);
    }
  } else {
    digitalWrite(2, LOW);
  }
}
