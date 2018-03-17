#include "FastLED.h"

#define NUM_LEDS 12
#define DATA_PIN 10
#define MOVE_LEFT_PIN 9
#define MOVE_RIGHT_PIN 8

struct Bomb {
  int pos;
  int duration;
  unsigned long startTime;
};

CRGB leds[NUM_LEDS];
Bomb bomb = Bomb();
int score = 0;
int playerPos = 0;
int wallPos = 0;

void setup() {
  delay(3000);

  random16_add_entropy(analogRead(0));
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
      moveWall();
    }
  }

  leds[playerPos] = CRGB::Blue;
  leds[wallPos] = CRGB::Red;

  int bombTimeLeft = bomb.duration - (millis() - bomb.startTime);
  leds[bomb.pos] = getBombColor(bombTimeLeft);

  if (playerPos == wallPos) {
    gameOver(wallPos);
  } else if (bombTimeLeft <= 0) {
    gameOver(bomb.pos);
  }

  FastLED.show();
}

void startGame() {
  bomb = Bomb();
  score = 0;
  playerPos = 0;

  moveBomb();
  moveWall();
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

  bomb.duration = max(1500, 5000 - (score * 100));
  bomb.startTime = millis();
}

void moveWall() {
  do {
    wallPos = random16(NUM_LEDS);
  } while (getDistance(wallPos, bomb.pos) < 2 || getDistance(wallPos, playerPos) < 2);
}

CRGB getBombColor(int timeLeft) {
  int brightness = map(timeLeft, bomb.duration, 0, 0, 255);
  if (timeLeft < 1000) {
    brightness = beatsin8(255, 0, 255);
  }

  return CRGB(brightness, brightness, 0);
}

int getDistance(int p1, int p2) {
  int distance = abs(p2 - p1);
  if (distance < NUM_LEDS / 2) {
    return distance;
  } else {
    return NUM_LEDS - distance;
  }
}

void gameOver(int pos) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[constrain(pos - i, 0, NUM_LEDS - 1)] = CRGB::Red;
    leds[constrain(pos + i, 0, NUM_LEDS - 1)] = CRGB::Red;
    FastLED.show();
    delay(30);
  }
  delay(500);

  for (int i = 255; i >= 0; i--) {
    fill_solid(leds, NUM_LEDS, CRGB(i, 0, 0));
    FastLED.show();
    delay(4);
  }

  startGame();
}

