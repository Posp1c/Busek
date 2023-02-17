int pocet = 0;
unsigned long predtim = 0;

void setup() {
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(3), pocitani, FALLING);
  Serial.begin(9600);
}

void loop() {
  unsigned long ted = millis();
  if (ted - predtim >= 2000) { 
    //Serial.print("Pocet kliknuti za vterinu: ");
    Serial.println((float)pocet/2.0);
    pocet = 0;
    predtim = ted;
  }
}

void pocitani() {
  pocet++;
}
