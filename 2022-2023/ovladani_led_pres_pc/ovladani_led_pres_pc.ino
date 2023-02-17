void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char znak = Serial.read();
    if (znak == 'Z') digitalWrite(LED_BUILTIN, HIGH);
    else if (znak == 'V') digitalWrite(LED_BUILTIN, LOW);
  }
}