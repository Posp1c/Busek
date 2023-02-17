unsigned int soucet;
char cislice[3];
byte i = 3;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    // nacteni znaku
    char znak = Serial.read();
    // ulozeni
    i--;
    cislice[i] = znak;
    // posunuti pozice v poli
  }

  if (i == 0) {
    i = 3;
    byte p = 1;
    for (int j = 0; j < 3; j++) {
      int c = p*prevod_znaku_na_cislo(cislice[j]);
      p *= 10;
      Serial.println(c);
    }
  }
}

byte prevod_znaku_na_cislo(char z) {
  byte cislo;
  // prevod znaku na cislici
  if (z >= '0' && z <= '9') {
    cislo = z - '0';
  } else {
    cislo = 0;
  }
  return cislo;
}