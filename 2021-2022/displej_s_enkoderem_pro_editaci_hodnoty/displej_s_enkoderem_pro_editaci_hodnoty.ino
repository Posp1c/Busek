#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define PIN_BTN   4
#define PIN_CLK   3
#define PIN_DT    2

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo;

byte tlacitko_predchozi = HIGH;   // predchozi hodnota tlacitka
byte clk_predchozi = HIGH;        // predchozi hodnota signalu CLK
byte stav = 0;                    // stav editace
byte poloha = 0;                  // predvolena poloha serva

void setup() {

  // digitalni vstupy
  
  pinMode(PIN_BTN, INPUT_PULLUP);
  pinMode(PIN_CLK, INPUT);
  pinMode(PIN_DT, INPUT);

  // lcd

  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("POLOHA: ");
  lcd.setCursor(8, 0);
  lcd.print(poloha);

  // servo

  servo.attach(11);
  servo.write(poloha);
}

void loop() {

  // obsluha tlacitka

  byte tlacitko = digitalRead(PIN_BTN);
  if (tlacitko == LOW && tlacitko_predchozi == HIGH) {
    lcd.setCursor(0, 1);
    if (stav == 0) {
      lcd.print("EDITACE");   // vypis editacniho modu na displej
      stav = 1;
    }
    else {
      stav = 0;
      servo.write(poloha);
      lcd.print("       ");   // smazani informace o editacnim modu
    }
  }
  tlacitko_predchozi = tlacitko;

  // enkoder
  
  if (stav == HIGH) {         // podminka aktivniho editacniho modu
    
    byte clk = digitalRead(PIN_CLK);
    if (clk != clk_predchozi && clk == HIGH) {
      byte dt = digitalRead(PIN_DT);
      if (dt) {
        if (poloha > 0) poloha--;
      }
      else {
        if (poloha < 180) poloha++;
      }
      lcd.setCursor(8, 0);
      lcd.print("   ");
      lcd.setCursor(8, 0);
      lcd.print(poloha);
    }
    clk_predchozi = clk;
    
  }
}
