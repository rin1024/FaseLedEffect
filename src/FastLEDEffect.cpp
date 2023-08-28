/**
 * FastLEDEffect
 */
#include "FastLEDEffect.h"

/**
 * コンストラクタ
 */
FastLEDEffect::FastLEDEffect() {
}

/**
 * デストラクタ
 */
FastLEDEffect::~FastLEDEffect() {
  //delete[] leds;
}

/**
 * 初期化
 */
void FastLEDEffect::setup(CRGB *_leds, uint16_t _numLeds) {
  leds = _leds;
  numLeds = _numLeds;

  testIndex = 0;
  testTimer = 0;

  brightness = 255; // default brightness
}

/**
 * アップデート関数
 */
void FastLEDEffect::loop() {
  if (millis() - testTimer > TEST_INTERVAL) {
    int r = int((3 - testIndex % 3) / 3) * TEST_BRIGHTNESS;
    int g = int(((testIndex + 1) % 3 + 1) / 3) * TEST_BRIGHTNESS;
    int b = int((testIndex % 3 + 1) / 3) * TEST_BRIGHTNESS;
    setAndShowColor(CRGB(r, g, b));

    testTimer = millis();
    testIndex++;
  }
}

/**
 * アップデート関数(細かい処理を自分で書きたくないときのループ)
 */
void FastLEDEffect::lazyLoop() {
  loop();
}

/**
 * getter
 */
uint16_t FastLEDEffect::getBrightness() {
  return brightness;
}

/**
 * setter
 */
void FastLEDEffect::setBrightness(uint16_t _brightness) {
  brightness = _brightness;
}

/**
 *
 */
void FastLEDEffect::setAndShowColor(CRGB _color) {
  for (uint16_t i = 0; i < numLeds; i++) {
    leds[i] = _color;
  }
  FastLED.show();
}
