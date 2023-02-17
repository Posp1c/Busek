#include <HCSR04.h>

#define PIN_BTN   2
byte triggerPin = 3;
byte echoPin = 4;

bool btn_prev = true;
bool state = false;
unsigned long time_prev = 0;

void setup() {
  pinMode(PIN_BTN, INPUT_PULLUP);
  HCSR04.begin(triggerPin, echoPin);
  Serial.begin(9600);
}

void loop() {
  bool btn_now = digitalRead(PIN_BTN);
  unsigned long time_now = millis();
  double* distances = HCSR04.measureDistanceCm();

  // vzorkovani
  if (time_now - time_prev >= 100) {
    
    // detekce stisknuti tlacitka
    if (!btn_now && btn_prev) {
      state = !state;
      // detekovana sestupna hrana
    }
    // ulozeni stavu tlacitka
    btn_prev = btn_now;

    // vysis do seriove linky
    if (state) {
      Serial.println("BUSEK");
    } else {
      Serial.print("d=");
      Serial.print(distances[0]);
      Serial.println(" cm");
    }

    // ulozeni casu
    time_prev = time_now;
  }
}
