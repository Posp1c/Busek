int cislo = 123;
int pole[3] = {5, 10, 15};

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c == 'v') {
      for (int i = 0; i < 3; i++) {
        Serial.println(pole[i]);
      }
    }
  }
}
