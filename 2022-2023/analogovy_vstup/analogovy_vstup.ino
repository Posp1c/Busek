void setup() {
  Serial.begin(9600);
}

void loop() {
  float hodnota = analogRead(A0);
  float napeti = 5*hodnota/1023;
  Serial.println(napeti);
}
