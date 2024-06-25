#define DELAY_TIME 100
#define FULL_BRIGHTNESS 255
#define Q1_BRIGHTNESS 200
#define Q2_BRIGHTNESS 155
#define HALF_BRIGHTNESS 100
#define Q3_BRIGHTNESS 55
#define OFF 0
#define PATTERN 12
#define PATTERN_LED 6

int pins[6] = {3, 5, 6, 9, 10, 11};
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
    pinMode(pins[i], OUTPUT);
  }
}

void setBrightness(int brightnesses[]) {
  for (int i = 0; i < numPins; i++) {
    if(i <= PATTERN_LED){
      analogWrite(pins[i], brightnesses[i]);
    }else{
     analogWrite(pins[i], OFF);
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
