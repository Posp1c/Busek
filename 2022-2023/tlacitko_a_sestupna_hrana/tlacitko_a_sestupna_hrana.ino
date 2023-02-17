#define LED     13
#define PIN_BTN 3

int btn_prev;
int led_state = LOW;

void setup() {
  pinMode(PIN_BTN, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  btn_prev = digitalRead(PIN_BTN);
}

void loop() {
  int btn = digitalRead(PIN_BTN);
  if (btn == LOW && btn_prev == HIGH) {
    led_state = !led_state;
  }
  btn_prev = btn;

  digitalWrite(LED, led_state);
}
