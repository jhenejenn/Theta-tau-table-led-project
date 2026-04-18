#include <FastLED.h>

#define NUM_LED 90
#define LED_PIN 6

CRGB leds[NUM_LED];

CRGB red  = CRGB(0x8B0000);
CRGB gold = CRGB(0xFFD700);

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LED);
  FastLED.setBrightness(60);
  FastLED.clear();
  FastLED.show();
}

void loop() {
  comeTogether();
  explodeOutward();
  fadeAway();
}

void comeTogether() {
  FastLED.clear();

  for (int step = 0; step <= NUM_LED / 2; step++) {
    FastLED.clear();

    for (int i = 0; i <= step; i++) {
      leds[i] = red;
      leds[NUM_LED - 1 - i] = gold;
    }

    FastLED.show();
    delay(35);
  }
}

void explodeOutward() {
  int centerLeft = (NUM_LED / 2) - 1;
  int centerRight = NUM_LED / 2;

  for (int radius = 0; radius < NUM_LED / 2; radius++) {
    fadeToBlackBy(leds, NUM_LED, 40);

    if (centerLeft - radius >= 0) {
      leds[centerLeft - radius] = blend(red, gold, 128);
    }
    if (centerRight + radius < NUM_LED) {
      leds[centerRight + radius] = blend(red, gold, 128);
    }

    if (centerLeft - radius - 1 >= 0) {
      leds[centerLeft - radius - 1] = red;
    }
    if (centerRight + radius + 1 < NUM_LED) {
      leds[centerRight + radius + 1] = gold;
    }

    FastLED.show();
    delay(40);
  }
}

void fadeAway() {
  for (int i = 0; i < 40; i++) {
    fadeToBlackBy(leds, NUM_LED, 8);
    FastLED.show();
    delay(30);
  }

  FastLED.clear();
  FastLED.show();
  delay(250);
}