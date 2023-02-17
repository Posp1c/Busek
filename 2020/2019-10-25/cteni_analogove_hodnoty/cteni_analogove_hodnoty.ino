/*
Datum: 2019-10-25
Autor: Jaroslav Busek
Popis: Cte analogovy vstup A0 a prevadi ho na napeti,
       ktere je pak posilano do PC pres UART.
*/
void setup() {
  Serial.begin(9600); // inicializace komunikace s PC
  // standardni baudove rychlosti: 9600, 19200, 38400, 57600, 115200
}

void loop() {
  int cislo = analogRead(A0); // ulozeni prectene hodnoty
                              // z analogoveho vstupu A0
                              // do promenne cislo
  //float u = 5.0*cislo/1023.0; // prevede 0 az 1023 na 0 az 5
  long u = map(cislo, 0, 1023, 0, 500);  // map("co chci prevest", "puvodni min.", "puvodni max.", "nove min.", "nove max.")
  Serial.println(u/100.0);      // odeslani cisla do PC
  delay(500);                 // cekani 500 ms
}
