#include <FastLED.h>
#include <ArduinoSTL.h>
#define DATA_PIN_LED_STRIP_1 11
#define DATA_PIN_LED_STRIP_2 9
#define NUM_LEDS 120
#define DRIP_SIZE 9

CRGB leds[NUM_LEDS];
std::vector<CHSV> led_vec(NUM_LEDS, CHSV(0, 0, 0));
std::vector<CHSV> drip_vec(DRIP_SIZE, CHSV(0, 0, 0));

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN_LED_STRIP_1>(leds, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, DATA_PIN_LED_STRIP_2>(leds, NUM_LEDS);

  drip_vec[7] = CHSV(0, 0, 30);
  drip_vec[6] = CHSV(0, 0, 60);
  drip_vec[5] = CHSV(0, 0, 90);
  drip_vec[4] = CHSV(0, 0, 100);
  drip_vec[3] = CHSV(0, 0, 80);
  drip_vec[2] = CHSV(0, 0, 60);
  drip_vec[1] = CHSV(0, 0, 40);
  drip_vec[0] = CHSV(0, 0, 20);

  auto drip1_iter = led_vec.begin();
  auto drip2_iter = led_vec.begin() + 20;
  auto drip3_iter = led_vec.begin() + 40;
  for (auto & element : drip_vec) {
    *drip1_iter = element;
    drip1_iter++;
    *drip2_iter = element;
    drip2_iter++;
    *drip3_iter = element;
    drip3_iter++;
  }
}

void loop() {
  for(int dot = 0; dot < NUM_LEDS; dot++) { 
    leds[dot] = led_vec[dot];
  }
  FastLED.show();
  std::rotate(led_vec.begin(), led_vec.begin()+led_vec.size()-1, led_vec.end());
  delay(50);
}
