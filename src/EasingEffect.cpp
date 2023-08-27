/**
 * EasingEffect
 *
 *
 */
#include "EasingEffect.h"

/**
 *
 */
void EasingEffect::setup(CRGB *_leds, uint16_t _numLeds) {
  FastLEDEffect::setup(_leds, _numLeds);
}

/**
 * 
 */
void EasingEffect::loop() {
  // FastLED based non-blocking delay to update/display the sequence.
  EVERY_N_MILLISECONDS(delayMillis) {
    ease();
  }
}

/**
 * 
 */
void EasingEffect::setDelayMillis(uint16_t _delayMillis) {
  delayMillis = _delayMillis;
}

/**
 * 
 */
void EasingEffect::ease() {
  // Start with easeInVal at 0 and then go to 255 for the full easing.
  easeOutVal = ease8InOutQuad(easeInVal);
  easeInVal++;

  // Map it to the number of LED's you have.
  lerpVal = lerp8by8(0, numLeds, easeOutVal);
  lerpVal %= numLeds;

  // 8 bit, 1 = slow fade, 255 = fast fade
  leds[(numLeds - 1) - lerpVal] = CRGB::Red;
  fadeToBlackBy(leds, numLeds, 16);
}
