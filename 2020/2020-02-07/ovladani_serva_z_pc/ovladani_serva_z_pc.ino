#include <Servo.h>

Servo mojeservo;

byte pos = 0;

void setup() {
  Serial.begin(9600);
  mojeservo.attach(9);
}

void loop() {
  if (Serial.available()) {
    char z = Serial.read();
    if (z == 'A' && pos >= 5) {
      pos -= 5;
      mojeservo.write(pos);
    }
    if (z == 'D' && pos <= 175) {
      pos += 5;
      mojeservo.write(pos);
    }
  }
}
