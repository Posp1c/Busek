#include <Wire.h>
#include <LiquidCrystal_I2C.h>

byte cislo = 0;
unsigned long cas_predtim = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  unsigned long cas_ted = millis();
  if (cas_ted - cas_predtim >= 1000) {
    //lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("cislo: ");
    lcd.print(cislo);
    if (cislo < 20) cislo++;
    else cislo = 0;
    cas_predtim = cas_ted;
  }
}
