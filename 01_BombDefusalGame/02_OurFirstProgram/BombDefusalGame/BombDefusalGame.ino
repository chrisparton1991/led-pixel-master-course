#include "FastLED.h"

#define NUM_LEDS 12

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, 10, GRB>(leds, NUM_LEDS);
}

void loop() {
  leds[0] = CRGB::Blue;
  FastLED.show();
}
