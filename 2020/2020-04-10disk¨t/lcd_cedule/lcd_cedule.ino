// knihovna I2C
#include <Wire.h>
// komunikace s displejem pomoci I2C
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

unsigned long predtim = 0;
byte znak = 0;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.clear();
}

void loop() {
  unsigned long ted = millis();
  if (ted - predtim >= 500) {
    lcd.clear();
    lcd.setCursor(znak,0);
    lcd.print("BAF");
    if (znak == 14) {
        lcd.setCursor(0,0);
        lcd.print("F");
    }
    if (znak == 15) {
        lcd.setCursor(0,0);
        lcd.print("AF");
    }
    Serial.println(znak);
    znak++;
    if (znak == 16) {
      znak = 0;
    }
    // aktualizuj promennou predtim
    predtim = ted;
  }
}
