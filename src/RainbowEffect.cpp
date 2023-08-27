/**
 * RainbowEffect
 *
 * 虹っぽいやつ
 */
#include "RainbowEffect.h"

/**
 *
 */
void RainbowEffect::setup(CRGB *_leds, uint16_t _numLeds) {
  FaseLedEffect::setup(_leds, _numLeds);

  saturation = 255;
  rainbowHue = 5;
}

/**
 * 
 */
void RainbowEffect::loop() {
  EVERY_N_MILLISECONDS(rainbowSpeed) {
    rainbowHue++;
  }

  fill_rainbow_with_brigthness(rainbowHue % 255, 8);
}

/**
 *
 */
void RainbowEffect::setSaturation(uint8_t _saturation) {
  saturation = _saturation;
}

/**
 *
 */
void RainbowEffect::setRainbowSpeed(uint16_t _rainbowSpeed) {
  rainbowSpeed = _rainbowSpeed;
}

/**
 *
 */
void RainbowEffect::fill_rainbow_with_brigthness(uint8_t initialhue, uint8_t deltahue) {
  CHSV hsv;
  hsv.hue = initialhue;
  hsv.val = getBrightness();
  hsv.sat = saturation;
  for (uint16_t i = 0; i < numLeds; i++) {
    leds[i] = hsv;
    hsv.hue += deltahue;
  }
}
