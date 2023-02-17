/*
ENA 9
IN1 7
IN2 8
*/
#define IN1 7
#define IN2 8
#define ENA 9

unsigned long predtim = 0;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long ted = millis();
  if (ted >= predtim + 200) {
    int joystick = analogRead(A0);
    int rychlost = map(joystick, 0, 1023, -255, 255);
    if (rychlost > 0) {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
    } else if (rychlost < 0) {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);    
    } else {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);     
    }
    Serial.println(rychlost);
    analogWrite(ENA, abs(rychlost));
    predtim = ted;
  }
}
