#include <Ultrasonic.h>
Ultrasonic ultrasonic(12, 13);
int vzdalenost = 0;
int x = 1000;
unsigned long ted = 0;
unsigned long predtim = 0;
bool tlacitko = HIGH;
bool tlacitko_predtim = HIGH;
bool stav = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  // levy vyvojovy diagram
  ted = millis();
  vzdalenost = ultrasonic.read();
  if (ted - predtim >= x) {
    Serial.println(vzdalenost);
    predtim = ted;
  }
  // pravy vyvojovy diagram
  tlacitko = digitalRead(2);
  if (tlacitko == LOW && tlacitko_predtim == HIGH) {
    stav = !stav;
    if (stav == HIGH) {
      x = 1000;
    } else {
      x = 100;
    }
  }
  tlacitko_predtim = tlacitko;
}
