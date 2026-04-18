#include <FastLED.h>

#define NUM_LED 90
#define LED_PIN 6

CRGB leds[NUM_LED];

uint8_t offset = 0;

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LED);
  FastLED.setBrightness(80);
}

void loop() {

  for (int i = 0; i < NUM_LED; i++) {

    // create moving heat value
    uint8_t heat = (i * 255 / NUM_LED + offset) % 256;

    // map heat to colors
    leds[i] = heatColor(heat);
  }

  FastLED.show();
  delay(40);

  offset++; // move gradient
}

// custom heat color function
CRGB heatColor(uint8_t heat) {
  if (heat < 85) {
    // dark red → red
    return CRGB(heat * 2, 0, 0);
  } 
  else if (heat < 170) {
    // red → orange
    heat -= 85;
    return CRGB(255, heat * 3, 0);
  } 
  else {
    // orange → gold
    heat -= 170;
    return CRGB(255, 255, heat * 2);
  }
}