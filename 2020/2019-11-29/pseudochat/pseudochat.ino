char zprava[32];
byte i = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    zprava[i] = c;
    if (i < 31) {
      i++;
    }
    if (c == 10) {
      Serial.print("Pritel: ");
      Serial.print(zprava);
      for (int j = 0; j < 32; j++) {
        zprava[j] = 0;
      }
      i = 0;
    }  
  }
}
