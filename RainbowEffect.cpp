/**
 * RainbowEffect
 *
 * 虹っぽいやつ
 */
#include "RainbowEffect.h"

/**
 * 
 */
void RainbowEffect::loop() {
  EVERY_N_MILLISECONDS(RAINBOW_SPEED) {
    rainbowHue++;
  }

  fill_rainbow_with_brigthness(rainbowHue % 255, 8);
}

/**
 *
 */
void RainbowEffect::fill_rainbow_with_brigthness(uint8_t initialhue, uint8_t deltahue) {
  CHSV hsv;
  hsv.hue = initialhue;
  hsv.val = getBrightness();
  hsv.sat = 200;//saturation;
  for (uint16_t i = 0; i < numLeds; i++) {
    leds[i] = hsv;
    hsv.hue += deltahue;
  }
}
