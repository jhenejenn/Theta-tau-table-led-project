#include <FastLED.h>

#define NUM_LED 90
#define LED_PIN 6

CRGB leds[NUM_LED];

CRGB red  = CRGB(0x8B0000);
CRGB gold = CRGB(0xFFD700);

uint8_t breath = 0;
int direction = 1;

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LED);
  FastLED.setBrightness(80);
}

void loop() {

  // blend between red and gold
  CRGB baseColor = blend(red, gold, breath);

  // apply brightness "breathing"
  for (int i = 0; i < NUM_LED; i++) {
    leds[i] = baseColor;
    leds[i].nscale8(breath); // controls brightness fade
  }

  FastLED.show();
  delay(20);

  // update breathing value
  breath += direction;

  if (breath == 0 || breath == 255) {
    direction *= -1;
  }
}