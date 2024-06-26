#include <Arduino.h>
#define DELAY_TIME 100
#define FULL_BRIGHTNESS 255
#define Q1_BRIGHTNESS 200
#define Q2_BRIGHTNESS 155
#define HALF_BRIGHTNESS 100
#define Q3_BRIGHTNESS 55
#define OFF 0
#define PATTERN 12
#define PATTERN_LED 6
#define PATTERN_LED 6
#define RESOLUTION 8
#define FREQUENCY 5000 
 

int pins[PATTERN_LED] = {16, 17, 18, 19, 21, 22};
const int ledChannels[PATTERN_LED] = {0, 1, 2, 3, 4, 5};
int numPins = sizeof(pins) / sizeof(pins[0]);
int brightnessPatterns[PATTERN][PATTERN_LED] = {
     {OFF, OFF, OFF, OFF, OFF, OFF},
    {FULL_BRIGHTNESS, OFF, OFF, OFF, OFF, OFF},
    {Q1_BRIGHTNESS, FULL_BRIGHTNESS, OFF, OFF, OFF, OFF},
    {Q2_BRIGHTNESS, Q1_BRIGHTNESS, FULL_BRIGHTNESS, OFF, OFF, OFF},
    {HALF_BRIGHTNESS, Q2_BRIGHTNESS, Q1_BRIGHTNESS, FULL_BRIGHTNESS, OFF, OFF},
    {Q3_BRIGHTNESS, HALF_BRIGHTNESS, Q2_BRIGHTNESS, Q1_BRIGHTNESS, FULL_BRIGHTNESS, OFF},
    {OFF, Q3_BRIGHTNESS, HALF_BRIGHTNESS, Q2_BRIGHTNESS, Q1_BRIGHTNESS, FULL_BRIGHTNESS},
    {OFF, OFF, HALF_BRIGHTNESS, Q2_BRIGHTNESS, Q1_BRIGHTNESS, FULL_BRIGHTNESS},
    {OFF, OFF, OFF, Q2_BRIGHTNESS, Q1_BRIGHTNESS, FULL_BRIGHTNESS},
    {OFF, OFF, OFF, OFF, Q1_BRIGHTNESS, FULL_BRIGHTNESS},
    {OFF, OFF, OFF, OFF, OFF, FULL_BRIGHTNESS},
    {OFF, OFF, OFF, OFF, OFF, OFF}
  };


void setup() {
  for (int i = 0; i < numPins; i++) { 
    ledcSetup(ledChannels[i], FREQUENCY, RESOLUTION); 
    ledcAttachPin(pins[i], ledChannels[i]);
  }
}

void setBrightness(int brightnesses[]) {
  for (int i = 0; i < numPins; i++) {
    if(i <= PATTERN_LED){
      ledcWrite(ledChannels[i], brightnesses[i]);
    }else{
     ledcWrite(ledChannels[i], OFF);
    }
  }
  delay(DELAY_TIME);
}

void runPattern(int pattern[][PATTERN_LED], int patternLength) {
  delay(DELAY_TIME);
  for (int i = 0; i < patternLength; i++) {
    setBrightness(pattern[i]);
  }
  delay(DELAY_TIME);
  for (int i = patternLength - 1  ; i >= 0; i--) {  
    setBrightness(pattern[i]);
  }
   delay(DELAY_TIME);
}

void loop() { 
  runPattern(brightnessPatterns, PATTERN); 
  delay(DELAY_TIME);
}
