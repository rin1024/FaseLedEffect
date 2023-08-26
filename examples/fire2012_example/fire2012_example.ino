#define FASTLED_ALLOW_INTERRUPTS 0
#include <FastLED.h>
FASTLED_USING_NAMESPACE
#include "FireEffect.h"

#define DATA_PIN    3
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB
#define NUM_LEDS    100

#define FRAMES_PER_SECOND 30//60

CRGB leds[NUM_LEDS];

FireEffect effect;

void setup() {
  Serial.begin(115200);
  delay(3000); // 3 second delay for recovery
 
  FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS)
    .setCorrection(TypicalLEDStrip);

  effect.setup(leds, NUM_LEDS);
}

void loop() {
  // Add entropy to random number generator; we use a lot of it.
  // random16_add_entropy( random());

  effect.loop();
  
  FastLED.show(); // display this frame
  FastLED.delay(1000 / FRAMES_PER_SECOND);
}
