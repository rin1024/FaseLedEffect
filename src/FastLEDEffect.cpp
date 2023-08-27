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
  brightness = 255; // default brightness
}

/**
 * アップデート関数
 */
void FastLEDEffect::loop() {

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
