unsigned long predchozi_cas = 0;
byte i = 0;
long j = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  j++;
  unsigned long soucasny_cas = millis();
  if (soucasny_cas - predchozi_cas == 1000) {
    i++;
    Serial.print(j);
    Serial.print("\t");
    Serial.println(i);
    predchozi_cas = soucasny_cas;
  }
}
