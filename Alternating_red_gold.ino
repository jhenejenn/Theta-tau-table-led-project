#include <FastLED.h>

#define NUM_LED 90
#define LED_PIN 6

CRGB leds[NUM_LED];


void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB> (leds, NUM_LED); // array, pin6
  FastLED.setBrightness(60); // color brightness 0-255 

}

void loop() {
  for ( int offset = 0; offset < NUM_LED; offset++) {

// red/gold alternating 

    for (int i = 0; i < NUM_LED; i++) {
      if ((i + offset) % 2 == 0) {
        leds[i] = CRGB(0xFFD700); // gold
      } else {
        leds[i] = CRGB(0x8B0000); // dark red
      }
     }
  FastLED.show();
  delay(150);
 }
}