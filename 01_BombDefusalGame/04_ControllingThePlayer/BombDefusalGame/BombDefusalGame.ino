#include "FastLED.h"

#define NUM_LEDS 12
#define DATA_PIN 10
#define MOVE_LEFT_PIN 9
#define MOVE_RIGHT_PIN 8

CRGB leds[NUM_LEDS];
int playerPos = 0;

void setup() {
  delay(3000);

  pinMode(MOVE_LEFT_PIN, INPUT_PULLUP);
  pinMode(MOVE_RIGHT_PIN, INPUT_PULLUP);
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
  if (digitalRead(MOVE_LEFT_PIN) == LOW) {
    playerPos = (playerPos - 1 + NUM_LEDS) % NUM_LEDS;
  } else if (digitalRead(MOVE_RIGHT_PIN) == LOW) {
    playerPos = (playerPos + 1) % NUM_LEDS;
  }
}
