/**
 * CylonEffect
 */
#include "CylonEffect.h"

/** 
 * This function draws rainbows with an ever-changing,
 * widely-varying set of parameters.
 */
void CylonEffect::loop() {
  Serial.print("x");
  // First slide the led in one direction
  for(uint16_t i = 0; i < numLeds; i++) {
    // Set the i'th led to red 
    leds[i] = CHSV(hue++, 255, 255);
    // Show the leds
    FastLED.show(); 
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall();
    // Wait a little bit before we loop around and do it again
    delay(10);
  }
  Serial.print("x");

  // Now go in the other direction.  
  for(uint16_t i = (numLeds)-1; i >= 0; i--) {
    // Set the i'th led to red 
    leds[i] = CHSV(hue++, 255, 255);
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall();
    // Wait a little bit before we loop around and do it again
    delay(10);

    if (i == 0) {
      break;
    }
  }
}

void CylonEffect::fadeall() {
  for(uint16_t i = 0; i < numLeds; i++) {
    leds[i].nscale8(250);
  }
}
