#include "FastLED.h"

#define NUM_LEDS 12
#define DATA_PIN 10
#define MOVE_LEFT_PIN 9
#define MOVE_RIGHT_PIN 8

struct Bomb {
  int pos;
  unsigned long startTime;
  int duration;
};

CRGB leds[NUM_LEDS];
Bomb bomb = Bomb();
int score = 0;
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

    if (playerPos == bomb.pos) {
      score++;
      moveBomb();
    }
  }

  leds[playerPos] = CRGB::Blue;

  int bombTimeLeft = bomb.duration - (millis() - bomb.startTime);
  leds[bomb.pos] = getBombColor(bombTimeLeft);

  if (bombTimeLeft <= 0) {
    gameOver();
  }

  FastLED.show();
}

void startGame() {
  bomb = Bomb();
  score = 0;
  playerPos = 0;

  moveBomb();
}

void movePlayer() {
  if (digitalRead(MOVE_LEFT_PIN) == LOW) {
    playerPos = (playerPos - 1 + NUM_LEDS) % NUM_LEDS;
  } else if (digitalRead(MOVE_RIGHT_PIN) == LOW) {
    playerPos = (playerPos + 1) % NUM_LEDS;
  }
}

void moveBomb() {
  do {
    bomb.pos = random16(NUM_LEDS);
  } while (bomb.pos == playerPos);

  bomb.startTime = millis();
  bomb.duration = max(1500, 5000 - (score * 100));
}

CRGB getBombColor(int timeLeft) {
  int brightness = map(timeLeft, bomb.duration, 0, 0, 255);
  return CRGB(brightness, brightness, 0);
}

void gameOver() {
  while (true) {
    fill_solid(leds, NUM_LEDS, CRGB::Red);
    FastLED.show();
  }
}
