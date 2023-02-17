#include <Servo.h>

Servo moje_servo;

void setup() {
  moje_servo.attach(3);
}

void loop() {
  int hodnota = analogRead(A0);
  int poloha = map(hodnota, 0, 1023, 0, 180);
  moje_servo.write(poloha);
  //moje_servo.write(map(analogRead(A0), 0, 1023, 0, 180));
}
