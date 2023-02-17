/*
  Naprogramujte následující funkce bez použití funkce delay().
  Tlačítko enkodéru jedním stiskem aktivuje následující funkce
  a dalším stiskem všechny LED zhasne (uvede zařízení do původního
  stavu).

  Je-li zařízení aktivní (tj. bylo zapnuto stiskem tlačítka enkodéru),
  bliká střídavě modrá a červená LED (když je zapnutá červená, modrá
  nesvítí a naopak). Periodu blikání lze plynule měnit mezi 200 a 1000
  milisekundami. Po zapnutí zařízení je perioda 200 milisekund.
*/

#define PIN_CLK     2
#define PIN_DT      3
#define PIN_BTN     4
#define PIN_BLUE    5
#define PIN_GREEN   6
#define PIN_RED     9

byte predchoziBTN = HIGH;
byte rezim = 0;
byte blik = 0;
unsigned long predchoziMS = 0;
unsigned long predchoziUS = 0;
byte predchoziCLK;
byte cislo = 0;

void setup() {
  pinMode(PIN_BTN, INPUT_PULLUP);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
  pinMode(PIN_CLK, INPUT);  // A
  pinMode(PIN_DT, INPUT);   // B
  predchoziCLK = digitalRead(PIN_CLK);
  Serial.begin(9600);
}

void loop() {
  /* OBSLUHA TLACITKA */
  byte aktualniBTN = digitalRead(PIN_BTN);
  if (aktualniBTN == LOW && predchoziBTN == HIGH) {
    // bylo stisknuto tlacitko
    if (rezim < 1) rezim++;
    else rezim = 0;
    Serial.println(rezim);
  }
  predchoziBTN = aktualniBTN;

  /* REZIM */
  switch (rezim) {
    case 0:
      digitalWrite(PIN_RED, LOW);
      digitalWrite(PIN_BLUE, LOW);
      break;
    case 1:
      digitalWrite(PIN_RED, blik);
      digitalWrite(PIN_BLUE, !blik);
      break;
  }

  /* BLIKANI */
  unsigned long aktualniMS = millis();
  if (aktualniMS - predchoziMS >= cislo) {
    if (blik == 0) blik = 1;
    else blik = 0;
    predchoziMS = aktualniMS;
  }

  /* 1 US DELAY */
  unsigned long aktualniUS = micros();
  if (aktualniUS - predchoziUS >= 1000) {
    
    /* OBSLUHA ENKODERU */
    byte aktualniCLK = digitalRead(PIN_CLK);
    if (aktualniCLK != predchoziCLK && aktualniCLK == true) {
      if (digitalRead(PIN_DT) != true) {
        if (cislo < 1000) cislo++;
      } else {
        if (cislo > 200) cislo--;
      }
    }
    predchoziCLK = aktualniCLK;
    
    predchoziUS = aktualniUS;
  }
}
