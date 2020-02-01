#include <FastLED.h>

#define NUM_LEDS 288
#define DATA_PIN 5

const CRGB colors[] = {
  0xff0000, 0xff4000, 0xff8000, 0xffc000,
  0xffff00, 0xc0ff00, 0x80ff00, 0x40ff00,
  0x00ff00, 0x00ff40, 0x00ff80, 0x00ffc0,
  0x00ffff, 0x00c0ff, 0x0080ff, 0x0040ff,
  0x0000ff, 0x4000ff, 0x8000ff, 0xc000ff,
  0xff00ff, 0xff00c0, 0xff0080, 0xff0040
};

CRGB leds[NUM_LEDS];
int ptr = 0;

void setup() { 
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop() { 
  int p;
  for (int i = 0; i < NUM_LEDS; i++) {
    p = (ptr + i) % 24;
    leds[i] = colors[p];
  }
  FastLED.show();
  delay(100);
  ptr++;
  ptr = (ptr == 24) ? 0 : ptr;
}
