#include <FastLED.h>

#define NUM_LED 90
#define LED_PIN 6

CRGB leds[NUM_LED];

CRGB red  = CRGB(0x8B0000);
CRGB gold = CRGB(0xFFD700);

int position = 0;
int direction = 1;

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LED);
  FastLED.setBrightness(80);
  FastLED.clear();
}

void loop() {

  // fade previous LEDs (creates trail)
  fadeToBlackBy(leds, NUM_LED, 40);

  // blend color depending on position (red → gold across strip)
  uint8_t blendAmount = map(position, 0, NUM_LED - 1, 0, 255);
  CRGB currentColor = blend(red, gold, blendAmount);

  // main moving light
  leds[position] = currentColor;

  FastLED.show();
  delay(20);

  // move position
  position += direction;

  // bounce at ends
  if (position <= 0 || position >= NUM_LED - 1) {
    direction *= -1;
  }
}