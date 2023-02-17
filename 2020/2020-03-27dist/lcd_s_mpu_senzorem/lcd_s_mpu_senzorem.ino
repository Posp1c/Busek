#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <TinyMPU6050.h>

LiquidCrystal_I2C lcd(0x27,16,2);
MPU6050 mpu (Wire);

void setup()
{
  mpu.Initialize();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Ahoj!");
  delay(1000);
  lcd.clear();
}


void loop() {
  mpu.Execute();
  float acc_z = mpu.GetAccZ();
  lcd.setCursor(0,0);
  lcd.print(acc_z);
  delay(100);
}
