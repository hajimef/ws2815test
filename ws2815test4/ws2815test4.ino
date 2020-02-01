#include <FastLED.h>

#define NUM_LEDS 288
#define DATA_PIN 5
#define DEG 3.1415926535 / 180

CRGB leds[NUM_LEDS];
int ptr = 0;

void setup() { 
  Serial.begin(115200);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void set_leds(int offset, int r, int g, int b) { 
  int max = -1, min = 9999;
  int pos;
  
  for (int i = 0; i < 10; i++) {
    pos = (sin(DEG * (i + ptr + offset)) + 1.0) / 2 * (NUM_LEDS - 1);
    max = (pos > max) ? pos : max;
    min = (pos < min) ? pos : min;
  }
//  Serial.print("min = ");
//  Serial.print(min);
//  Serial.print(", max = ");
//  Serial.print(max);
  for (int i = min; i <= max; i++) {
    if (r >= 0) {
      leds[i].r = r;
    }
    if (g >= 0) {
      leds[i].g = g;
    }
    if (b >= 0) {
      leds[i].b = b;
    }
  }
//  Serial.print(", led[max] = ");
//  Serial.println(leds[max]);
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
  set_leds(0, 0xff, -1, -1);
  set_leds(60, -1, 0xff, -1);
  set_leds(120, -1, -1, 0xff);
  set_leds(180, 0xff, 0xff, -1);
  set_leds(240, -1, 0xff, 0xff);
  set_leds(300, 0xff, -1, 0xff);
  FastLED.show();
  delay(50);
  ptr++;
  ptr = (ptr == 360) ? 0 : ptr;
  
}
