#include <Stepper.h>
Stepper krokac(200, 8, 9, 10, 11);

void setup() {
  Serial.begin(9600);
  krokac.setSpeed(10);
}

void loop() {
  int hodnota = analogRead(A0);
  int rychlost = map(hodnota, 0, 1005, -100, 100);
  krokac.setSpeed(abs(rychlost));
  if (rychlost >= 0) {
    krokac.step(10);
  } else {
    krokac.step(-10);
  }
}
