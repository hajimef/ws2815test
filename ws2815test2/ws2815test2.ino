#include <FastLED.h>

#define NUM_LEDS 288
#define DATA_PIN 5

CRGB leds[NUM_LEDS];

void setup() { 
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop() { 
  for (int i = 0; i < NUM_LEDS; i += 6) {
    leds[i] = CRGB::Red;
    leds[i + 2] = CRGB::Green;
    leds[i + 4] = CRGB::Blue;
  }
  FastLED.show();
  delay(100);
  for (int i = 0; i < NUM_LEDS; i += 6) {
    leds[i] = CRGB::Green;
    leds[i + 2] = CRGB::Blue;
    leds[i + 4] = CRGB::Red;
  }
  FastLED.show();
  delay(100);
  for (int i = 0; i < NUM_LEDS; i += 6) {
    leds[i] = CRGB::Blue;
    leds[i + 2] = CRGB::Red;
    leds[i + 4] = CRGB::Green;
  }
  FastLED.show();
  delay(100);
}
