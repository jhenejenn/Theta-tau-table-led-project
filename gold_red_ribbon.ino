//this code starts a ribbon of red, which stretches across from left to right, then a stream of gold which starts from right and goes to left. Then, the red starts again and repeats the loop
#include <FastLED.h>

#define NUM_LEDS 90
#define LED_PIN 6
//this speed is arbitrary, can be increased or decreased depending on our needs
#define SPEED 40

CRGB leds[NUM_LEDS];
uint8_t startHue = 0;
uint8_t deltaHue = 0;
void setup() { 
 FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
 FastLED.setBrightness(65); 
}

void loop(){
    for (int i = 0; i < NUM_LEDS; i++){
        leds[i] = CRGB::Maroon;
        FastLED.show();
        delay(SPEED);
    }
    for(int i = NUM_LEDS - 1; i >= 0; i--){
        leds[i] = CRGB::Gold;
        FastLED.show();
        delay(SPEED);
    }
}
