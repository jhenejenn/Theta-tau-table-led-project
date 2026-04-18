#include <FastLED.h>

#define NUM_LED 90
#define LED_PIN 6

CRGB leds[NUM_LED];

CRGB red  = CRGB(0x8B0000);
CRGB gold = CRGB(0xFFD700);

int wavePosition = 0;

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LED);
  FastLED.setBrightness(80);
}

void loop() {
  for (int i = 0; i < NUM_LED; i++) {
    leds[i] = red;

    int distance = abs(i - wavePosition);

    if (distance < 8) {
      uint8_t amount = map(distance, 0, 7, 255, 0);
      leds[i] = blend(red, gold, amount);
    }
  }

  FastLED.show();
  delay(30);

  wavePosition++;

  if (wavePosition >= NUM_LED) {
    wavePosition = 0;
  }
}