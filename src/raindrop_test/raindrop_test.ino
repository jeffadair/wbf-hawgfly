#include <FastLED.h>
#include <ArduinoSTL.h>
#define DATA_PIN 11
#define NUM_LEDS 60

CRGB leds[NUM_LEDS];
std::vector<CHSV> vec1(NUM_LEDS, CHSV(0, 0, 0));

// std::vector<CHSV> vec1{CHSV(0, 0, 50),
//                   CHSV(0, 0, 35),
//                   CHSV(0, 0, 20),
//                   CHSV(0, 0, 5),
//                   CHSV(0, 0, 0)};


void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  vec1[0] = CHSV(0, 0, 50);
  vec1[1] = CHSV(0, 0, 35);
  vec1[2] = CHSV(0, 0, 20);
  vec1[3] = CHSV(0, 0, 5);
  vec1[4] = CHSV(0, 0, 0);
}

void loop() {
  for(int dot = 0; dot < NUM_LEDS; dot++) { 
    leds[dot] = vec1[dot];
  }
  FastLED.show();
  std::rotate(vec1.begin(), vec1.begin()+1, vec1.end());
  delay(50);
}
