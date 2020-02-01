#include <FastLED.h>

#define NUM_LEDS 288
#define DATA_PIN 5

CRGB leds[NUM_LEDS];

void setup() { 
      FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void show(int r, int g, int b) {
  for (int i = 0; i < 255; i += 5) {
    for (int j = 0; j < NUM_LEDS; j++) {
      leds[j].r = r ? i : 0;
      leds[j].g = g ? i : 0;
      leds[j].b = b ? i : 0;
    }
    FastLED.show();
    delay(10);
  }
  for (int i = 255; i > 0; i -= 5) {
    for (int j = 0; j < NUM_LEDS; j++) {
      leds[j].r = r ? i : 0;
      leds[j].g = g ? i : 0;
      leds[j].b = b ? i : 0;
    }
    FastLED.show();
    delay(10);
  }
}
void loop() { 
  show(1, 0, 0);
  show(0, 1, 0);
  show(0, 0, 1);
  show(1, 1, 0);
  show(1, 0, 1);
  show(0, 1, 1);
  show(1, 1, 1);
}
