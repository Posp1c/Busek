// knihovna I2C
#include <Wire.h>
// komunikace s displejem pomoci I2C
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

/*
1. radek ... index 0
1. symbol na radku ... index 0
*/

unsigned long predtim = 0;
byte znak = 0; // 0..255
byte radek = 0;

void setup() {
  lcd.init();
  lcd.clear();
  lcd.print("muj text");
  lcd.print("ahoj");
  lcd.setCursor(0,1); // 1. pozice na radku, 2. radek
  lcd.print("12345xcvxcv");
  delay(2000);
  lcd.clear();
}

void loop() {
  unsigned long ted = millis();
  if (ted - predtim >= 500) {
    // znak = 15, radek = 0
    lcd.clear();
    lcd.setCursor(znak,radek);
    lcd.print("O");
    znak++;
    if (znak == 16 && radek == 0) {
      radek++;
      znak = 0;
    }
    if (znak == 16 && radek == 1) {
      radek = 0;
      znak = 0;
    }
    /*
    if (znak == 16) {
      if (radek == 1) {
        radek = 0;
      } else {
        radek++; 
      }
      znak = 0;  
    }    
    */
    // aktualizuj promennou predtim
    predtim = ted;
  }
}
