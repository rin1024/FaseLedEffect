/**
   FaseLedEffect
*/
#include "FaseLedEffect.h"

/**
   コンストラクタ
*/
FaseLedEffect::FaseLedEffect() {
}

/**
   デストラクタ
*/
FaseLedEffect::~FaseLedEffect() {
  //delete[] leds;
}

/**
   初期化
*/
void FaseLedEffect::setup(CRGB *_leds, uint16_t _numLeds) {
  leds = _leds;
  numLeds = _numLeds;
  brightness = 255; // default brightness
}

/**
   アップデート関数
*/
void FaseLedEffect::loop() {

}

/**
 * getter
 */
uint16_t FaseLedEffect::getBrightness() {
  return brightness;
}

/**
 * setter
 */
void FaseLedEffect::setBrightness(uint16_t _brightness) {
  brightness = _brightness;
}
