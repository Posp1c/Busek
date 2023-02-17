#include <Servo.h>

// vytvori servo tridu
Servo srv;

byte mode = 0;              // rezim sterace (0~stoji, 1~stira 3x, 2~stira porad)
unsigned long predtim = 0;  // predchozi pocet milisekund vykonani vzorkovaci smycky
byte pos = 0;               // pozice serva

void setup() {
  Serial.begin(9600);       // spusteni seriovek omunikace s PC
  srv.attach(9);            // "pripojeni" serva na pin 9
}

void loop() {
  unsigned long ted = millis();
  // ------------
  // ZMENA REZIMU
  // ------------
  if (Serial.available()) {   // zjisteni, zda dorazil nejaky znak z PC
    char z = Serial.read();   // precteni znaku a ulozeni do promenne
    switch (z) {              // zmena rezimu podle prichoziho znaku
      case 'a':
        mode = 1;
        break;
      case 's':
        mode = 2;
        break;
      case 'd':
        mode = 0;
        break;
    }
  }
  // --------------
  // OVLADANI SERVA
  // --------------
  if (ted - predtim >= 600) {       // kazdych 600 ms se vykona nasledujici kod
    if (mode == 2 || mode == 1) {   // v rezimu 1 nebo 2 se provadi cyklovani
      if (pos == 0) {               // je-li servo v poloze 0, nastav 180
        pos = 180;
      } else if (pos == 180) {      // je-li servo v poloze 180, nastav 0
        pos = 0;
        if (mode == 1) {            // pokud je rezim 1, ukonci ihned cyklovani nastavenim rezimu 0
          mode = 0;
        }
      }
    } else if (mode == 0) {         // zastaveni cyklovani sterace
      pos = 0;
    }
    srv.write(pos);                 // nastaveni polohy sterace
    predtim = ted;                  // aktualizace vzorkovaci smycky
  }
}
