#include <Wire.h>
#include <LiquidCrystal_I2C.h>

char znak = 'O';
byte radek = 0;
byte sloupec = 0;
byte doleva = 0; 
unsigned long cas_predtim = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  unsigned long cas_ted = millis();
  if (cas_ted - cas_predtim >= 100) {
    
    // vycisteni displeje
    
    lcd.clear();

    // nastaveni pozice znaku
    
    lcd.setCursor(sloupec, radek);

    // vypsani znaku
    
    lcd.print(znak);

    // posun znaku
    
    if (doleva) sloupec--;
    else sloupec++;

    // zmena smeru
        
    if (sloupec == 0) doleva = 0;
    else if (sloupec == 15) doleva = 1;
    
    // aktualizace casu
    
    cas_predtim = cas_ted;
  }
}
