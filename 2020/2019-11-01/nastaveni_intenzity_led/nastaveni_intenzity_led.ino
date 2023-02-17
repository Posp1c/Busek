/*
 * Zapojeni:
 * potenciometr ~ 5V, A0, GND
 * LED + 220R ~ pin 3, GND
 */

void setup() {
  pinMode(3, OUTPUT); // nastavi GPIO pin 3 jako vystup
}

void loop() {
  int x = analogRead(A0); // zmeri napeti na analogovem vstupu A0 a ulozi ciselnou reprezentaci 0 az 1023
  analogWrite(3, x/4);    // nastavi PWM na pinu 3 (predtim prevede cislo 0 az 1023 na 0 az 255)
}
