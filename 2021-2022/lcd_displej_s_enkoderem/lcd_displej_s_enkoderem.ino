// knihovny pro displej s I2C prevodnikem

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

byte customChar[] = {
  B00000,
  B10001,
  B01110,
  B11011,
  B10001,
  B01110,
  B10001,
  B10001
};

// inicializace displeje

LiquidCrystal_I2C lcd(0x27, 16, 2);

// definice zastupnych symbolu

#define PIN_DT      3
#define PIN_CLK     2
#define PIN_SW      4

byte predchoziCLK;
byte cislo = 0;
byte tlacitko_predchozi = HIGH;
byte radek = 0;

void setup() {

  // nastaveni digitalnich vstupu

  pinMode(PIN_CLK, INPUT);  // A
  pinMode(PIN_DT, INPUT);   // B
  pinMode(PIN_SW, INPUT_PULLUP);   // SW

  // inicializace seriove linky

  Serial.begin(9600);

  // nacteni vychozi hodnoty CLK

  predchoziCLK = digitalRead(PIN_CLK);

  // zapnuti displeje

  lcd.init();
  lcd.createChar(0, customChar);
  lcd.backlight();
  update();

}

void loop() {

  // detekce stisku tlacitka

  byte tlacitko = digitalRead(PIN_SW);

  if (tlacitko_predchozi == HIGH && tlacitko == LOW) {
    if (radek) radek = 0;
    else radek = 1;
    update();
  }

  tlacitko_predchozi = tlacitko;

  // nacteni aktualni hodnoty CLK

  byte aktualniCLK = digitalRead(PIN_CLK);

  // detekce nabezne hrany CLK

  if (aktualniCLK != predchoziCLK && aktualniCLK == true) {

    // detekce stavu DT

    if (digitalRead(PIN_DT) != aktualniCLK) {
      if (cislo < 15) cislo++;
    } else {
      if (cislo > 0) cislo--;
    }

    update();

  }

  // aktualizace predchoziho stavu CLK

  predchoziCLK = aktualniCLK;

  // kratky delay proti zakmitu kontaktu

  delay(1);
}

void update() {
  lcd.clear();
  lcd.setCursor(cislo, radek);
  lcd.write(0);
}

/*
   vice info napriklad zde: https://lastminuteengineers.com/rotary-encoder-arduino-tutorial/
*/
