byte pocet = 0;
byte i = 0;
bool stav = LOW;
unsigned long predtim = 0;

void setup() {
  // nastavi pin 13 jako vystup
  pinMode(13, OUTPUT);
  // inicializuje UART a nastavi rychlost komunikace na 9600 bps
  Serial.begin(9600);
}

void loop() {
  // kontroluje, zda byl prijat znak
  if (Serial.available() > 0) {
    // precte znak a posune ho o poradove cislo znaku "0"
    pocet = Serial.read() - 48;
  }
  moje_funkce();
}

void moje_funkce() {
  // zjisti, kolik milisekund Arduino bezi
  unsigned long ted = millis();
  // 
  if (ted - predtim >= 500 && i < pocet) {
    // zneguje promennou
    stav = !stav;
    // aktualizuje pomocnou promennou pro ulozeni casu posledniho provedeni podminky
    predtim = ted;
    // omezuje na bliknuti jako celek (tj. rozsviceni i zhasnuti)
    if (!stav) {  // (stav == LOW)
      i++;
    }
  }
  // nastavi na vystupu 13 prislusne napeti (LOW/HIGH)
  digitalWrite(13, stav);
  // pokud byl dosazen pocet bliknuti, tak resetuje aktualni pocet a nastaveny pocet
  if (i == pocet) {
    i = 0;
    pocet = 0;
  }
}
