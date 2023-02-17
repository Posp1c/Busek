#define PIN_R   9
#define PIN_G   10
#define PIN_B   11

byte cervena = 0;
byte prepinac = HIGH;

void setup() {
  // inicializace pinu s RGB led
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);

  // zapnuti seriove komunikace
  Serial.begin(9600);
}

void loop() {
  // nastaveni PWM hodnoty
  analogWrite(PIN_R, cervena);

  // vypsani intenzity do serioveho monitoru
  Serial.println(cervena);

  // prepinani pricitani a odcitani intenzity podle prepinace
  if (prepinac) cervena++;
  else cervena--;

  // zmena prepinace pri dosazeni krajnich poloh intenzity
  if (cervena == 255) prepinac = LOW;
  else if (cervena == 0) prepinac = HIGH;

  // kratka prodleva (cim mensi, tim rychlejsi blikani)
  delay(1);  
}
