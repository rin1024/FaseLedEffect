/**
 * CylonEffect
 *
 * スムージングされた色が手前から奥に流れていく、逆方向も、を繰り返す
 */
#include "CylonEffect.h"

/** 
 * This function draws rainbows with an ever-changing,
 * widely-varying set of parameters.
 */
void CylonEffect::loop() {
  // 手前から奥に
  if (direction == DIRECTION_BOTH || direction == DIRECTION_FORWARD_ONLY) {
    // First slide the led in one direction
    for(uint16_t i = 0; i < numLeds; i++) {
      // Set the i'th led to red 
      // カラフル
      //leds[i] = CHSV(hue++, 255, getBrightness());
      // 白のみ
      leds[i] = CHSV(0, 0, getBrightness());

      // Show the leds
      FastLED.show(); 
      
      // now that we've shown the leds, reset the i'th led to black
      // leds[i] = CRGB::Black;
      fadeall();
      
      // Wait a little bit before we loop around and do it again
      delay(10);
    }
  }

  // 奥から手前に
  if (direction == DIRECTION_BOTH || direction == DIRECTION_BACKWARD_ONLY) {
    // Now go in the other direction.  
    uint16_t i = numLeds - 1;
    while (true) {
      // Set the i'th led to red 
      // カラフル
      //leds[i] = CHSV(hue++, 255, getBrightness());
      // 白のみ
      leds[i] = CHSV(0, 0, getBrightness());
      
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

      i--;
    }
  }
}

void CylonEffect::fadeall() {
  for(uint16_t i = 0; i < numLeds; i++) {
    leds[i].nscale8(250);
  }
}

void CylonEffect::setDirection(uint8_t _direction) {
  direction = _direction;
}

