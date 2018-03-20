#include "FastLED.h"

#define NUM_LEDS 12
#define DATA_PIN 10

CRGB leds[NUM_LEDS];
int playerPos = 0;

void setup() {
  delay(3000);

  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(160);
  startGame();
}

void loop() {
  fill_solid(leds, NUM_LEDS, CRGB::Black);

  EVERY_N_MILLIS(100) {
    movePlayer();
  }

  leds[playerPos] = CRGB::Blue;
  FastLED.show();
}

void startGame() {
  playerPos = 0;
}

void movePlayer() {
  playerPos = (playerPos + 1) % NUM_LEDS;
}
