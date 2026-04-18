#include <FastLED.h>


#define NUM_LEDS 90
#define LED_PIN 6

CRGB leds[NUM_LEDS];
uint8_t startHue = 0;
uint8_t deltaHue = 0;
void setup() { 
 FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
 FastLED.setBrightness(65); 
}

void loop() {
  // for (int i = 0; i<40; i++ ){
  //   leds[i] = CRGB::Red;
  //   FastLED.show();
  //   delay(200);
  //   leds[i] = CRGB::Black;
  //   FastLED.show();
  // }
  // for (int i = 90; i>40; i-- ){
  //   leds[i] = CRGB::Gold;
  //   FastLED.show();
  //   delay(200);
  //   leds[i] = CRGB::Black;
  //   FastLED.show();
  // }
  // for (int i = 0; i<=NUM_LEDS / 2; i++ ){
  //   leds[i] = CRGB::Maroon;
  //   FastLED.show();
  //   leds[NUM_LEDS - i] = CRGB::Gold;
  //   delay(200);
  //   FastLED.show();
  // }
  fill_rainbow (leds, NUM_LEDS,startHue, 1);
  FastLED.show();
  delay(10);
  startHue++;

}
void gold() {

}
