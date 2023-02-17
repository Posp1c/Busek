#define PIN_BTN   10
#define PIN_RED   11
#define PIN_GREEN 12
#define PIN_BLUE  13

byte rezim;
byte predchoziBTN;
unsigned long predchoziMS;
byte tik = 0;
byte barva = 0;

void setup() {
  pinMode(PIN_BTN, INPUT_PULLUP);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
}

void loop() {
  // obsluha casu

  unsigned long aktualniMS = millis();
  if (aktualniMS - predchoziMS >= 500) {
    tik = 1;
    predchoziMS = aktualniMS;
  } else {
    tik = 0;
  }

  // obsluha tlacitka

  byte aktualniBTN = digitalRead(PIN_BTN);
  if (aktualniBTN != predchoziBTN && aktualniBTN == LOW) {
    rezim++;
  }
  predchoziBTN = aktualniBTN;

  // obsluha rezimu

  switch (rezim) {
    case 0:
      digitalWrite(PIN_RED, LOW);
      digitalWrite(PIN_GREEN, LOW);
      digitalWrite(PIN_BLUE, LOW);
      break;
    case 1:
      digitalWrite(PIN_RED, HIGH);
      break;
    case 2:
      digitalWrite(PIN_RED, LOW);
      digitalWrite(PIN_GREEN, HIGH);
      break;
    case 3:
      digitalWrite(PIN_GREEN, LOW);
      digitalWrite(PIN_BLUE, HIGH);
      break;
    case 4:
      if (tik) {
        if (barva < 2) barva++;
        else barva = 0;
      }
      switch (barva) {
        case 0:
          digitalWrite(PIN_RED, HIGH);
          digitalWrite(PIN_GREEN, LOW);
          digitalWrite(PIN_BLUE, LOW);
          break;
        case 1:
          digitalWrite(PIN_RED, LOW);
          digitalWrite(PIN_GREEN, HIGH);
          digitalWrite(PIN_BLUE, LOW);
          break;
        case 2:
          digitalWrite(PIN_RED, LOW);
          digitalWrite(PIN_GREEN, LOW);
          digitalWrite(PIN_BLUE, HIGH);
          break;
      }
      break;
    default:
      rezim = 0;
      break;
  }

}
