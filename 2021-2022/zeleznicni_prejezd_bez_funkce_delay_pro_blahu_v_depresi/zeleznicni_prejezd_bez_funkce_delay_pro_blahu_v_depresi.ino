
#define PIN_CLK     2
#define PIN_DT      3
#define PIN_BTN     4
#define PIN_BLUE    5
#define PIN_GREEN   6
#define PIN_RED     9

unsigned long predchoziMS;
byte stav = 0;

void setup() {
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
}

void loop() {
  unsigned long aktualniMS = millis();

  if (aktualniMS - predchoziMS >= 1000) {
    if (stav == 0) stav = 1;
    else stav = 0;

    if (stav == 0) {
      digitalWrite(PIN_RED, HIGH);
      digitalWrite(PIN_BLUE, LOW);
    } else {
      digitalWrite(PIN_RED, LOW);
      digitalWrite(PIN_BLUE, HIGH);
    }
  }
}
