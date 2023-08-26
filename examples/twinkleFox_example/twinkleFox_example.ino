#define FASTLED_ALLOW_INTERRUPTS 0
#include <FastLED.h>
FASTLED_USING_NAMESPACE
#include "TwinkleFoxEffect.h"

#define NUM_LEDS      100
#define LED_TYPE   WS2812
#define COLOR_ORDER   BGR//RGB
#define DATA_PIN        3

CRGBArray<NUM_LEDS> leds;

TwinkleFoxEffect effect;

void setup() {
  Serial.begin(115200);
  delay(3000); // 3 second delay for recovery

  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS)
    .setCorrection(TypicalLEDStrip);

  effect.setup(leds, NUM_LEDS);
}

void loop() {
  effect.loop();
  FastLED.show();
}
