#include <Ultrasonic.h>

Ultrasonic muj_senzor(2, 3);

unsigned long predtim = 0;
bool stav = LOW;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // zjisteni aktualni vzdalenosti
  int vzdalenost = muj_senzor.read();
  // nastaveni rezimu LED
  if (vzdalenost <= 10) {
    // rozsviceni LED
    digitalWrite(LED_BUILTIN, HIGH);
  } else if (vzdalenost <= 20) {
    // blikani LED
    unsigned long ted = millis();
    if (ted - predtim >= 1000) {
      stav = !stav;
      predtim = ted;    
    }
    digitalWrite(LED_BUILTIN, stav);
  } else {
    // zhasnuti LED
    digitalWrite(LED_BUILTIN, LOW);
  }
}
