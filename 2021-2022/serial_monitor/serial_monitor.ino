/*
 * Program vykresluje
 */

void setup() {
  Serial.begin(9600);
  /*
  Serial.println();
  Serial.print("sin");
  Serial.print(',');
  Serial.print("cos");
  Serial.println();
  //*/
}

void loop() {
  Serial.print(sin(millis()/100.0));
  Serial.print(',');
  Serial.print(cos(millis()/100.0));
  Serial.println();
}
