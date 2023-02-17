bool stav = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    if (Serial.read() == 10) {
      stav = !stav;    
    }
  }
  digitalWrite(13, stav);
}
