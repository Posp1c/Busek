/*
Zadani:
Naprogramujte Arduino tak, aby po stisku tlačítka
(pin 2) LED na pinu 13 (LED_BUILTIN) dvakrát po
sobě blikla tak, že 1 sekundu svítí a 0,5 sekundy
je zhasnutá. Proveďte praktické zapojení.
*/
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  byte btn = digitalRead(2);
  if (btn == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);    
  }
}
