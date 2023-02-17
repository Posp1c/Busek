#define PIN_SENS  2

byte shit = 0;
bool sens_prev = LOW;
unsigned long time_detect = 0;

void setup() {
  pinMode(PIN_SENS, INPUT);
  Serial.begin(115200);
  while (!Serial) {
  }
}

void loop() {
  switch (shit) {
    case 0:
      Serial.println("================================================");
      Serial.println("INFO: Initialized.");
      shit++;
      break;
    case 1:
      Serial.println("INFO: Waiting for input.");
      shit++;
      break;
    case 2:
      if (sensor()) {
        time_detect = millis();
        Serial.println("INFO: Detected (running 5 seconds safe time).");
        shit++;
      }
      break;
    case 3:
      if (millis() - time_detect >= 5000) {
        shit++;
      }
      break;
    case 4:
      if (sensor()) {
        Serial.print("INFO: Elapsed time is ");
        Serial.print(millis() - time_detect);
        Serial.println(" ms.");
        shit++;
      }
      break;
    case 5:
      if (millis() - time_detect >=2000) {
        shit++;
      }
      break;
    default:
      shit = 0;
      break;
  }
}

bool sensor() {
  bool sens = digitalRead(PIN_SENS);
  if (!sens && sens_prev) {
    sens_prev = sens;
    return true;
  }
  sens_prev = sens;
  return false;
}
