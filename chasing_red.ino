#include <FastLED.h>

#define NUM_LED 90
#define LED_PIN 6

CRGB leds[NUM_LED];

CRGB red  = CRGB(0x8B0000);
CRGB gold = CRGB(0xFFD700);

int pos1 = 0;
int pos2 = 10;
int pos3 = 20;

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LED);
  FastLED.setBrightness(80);
  FastLED.clear();
}

void loop() {
  fadeToBlackBy(leds, NUM_LED, 50);

  leds[pos1] = red;
  leds[pos2] = gold;
  leds[pos3] = red;

  FastLED.show();
  delay(40);

  pos1++;
  pos2++;
  pos3++;

  if (pos1 >= NUM_LED) pos1 = 0;
  if (pos2 >= NUM_LED) pos2 = 0;
  if (pos3 >= NUM_LED) pos3 = 0;
}