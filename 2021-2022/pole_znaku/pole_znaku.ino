char retezec[10];
int i = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    retezec[i] = c;
    i++;
    if (i > 9 || c == ' ') {
      i = 0;
      Serial.println(retezec);
    }
  }
}
