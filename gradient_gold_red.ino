#include <FastLED.h>

#define NUM_LED 90
#define LED_PIN 6

CRGB leds[NUM_LED];

CRGB red  = CRGB(0x8B0000);
CRGB gold = CRGB(0xFFD700);

uint8_t offset = 0;

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LED);
  FastLED.setBrightness(60);
}

void loop() {

  for (int i = 0; i < NUM_LED; i++) {

  
    uint8_t blendAmount = (i * 255 / NUM_LED + offset) % 256;

    leds[i] = blend(red, gold, blendAmount);
  }

  FastLED.show();
  delay(40);

  offset++; 
}