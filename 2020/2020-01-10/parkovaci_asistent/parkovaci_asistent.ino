#include <Ultrasonic.h>

Ultrasonic muj_senzor(12, 13);

unsigned long predtim = 0;

void setup() {
  pinMode(10, OUTPUT);
}

void loop() {
  int vzdalenost = muj_senzor.read();
  unsigned long ted = millis();
  if (ted - predtim >= vzdalenost*10) {
    tone(10, 440, 10);
    predtim = ted;
  }
}
