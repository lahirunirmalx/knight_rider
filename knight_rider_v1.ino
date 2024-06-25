#define DELAY_TIME 100
#define FULL_BRIGHTNESS 255
#define HALF_BRIGHTNESS 120
#define OFF 0

int pins[6] = {3, 5, 6, 9, 10, 11};
int numPins = sizeof(pins) / sizeof(pins[0]);  

void lightUpSequence(int pins[], int numPins) {
  for (int i = 0; i < numPins; i++) {
    analogWrite(pins[i], FULL_BRIGHTNESS);
    if (i > 0) {
      analogWrite(pins[i - 1], HALF_BRIGHTNESS);
    }
    delay(DELAY_TIME);   
    analogWrite(pins[i], OFF);
    if (i > 0) {
      analogWrite(pins[i - 1], OFF);
    }
  }
}

void lightDownSequence(int pins[], int numPins) {
  for (int i = numPins - 1; i >= 0; i--) {
    analogWrite(pins[i], FULL_BRIGHTNESS);
    if (i < numPins - 1) {
      analogWrite(pins[i + 1], HALF_BRIGHTNESS);
    }
    delay(DELAY_TIME);   
    analogWrite(pins[i], OFF);
    if (i < numPins - 1) {
      analogWrite(pins[i + 1], OFF);
    }
  }
}

void setup() {
  for (int i = 0; i < numPins; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  lightUpSequence(pins, numPins);
  lightDownSequence(pins, numPins);
  delay(1000);  
}
