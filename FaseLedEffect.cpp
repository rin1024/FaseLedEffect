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
}

/**
   アップデート関数
*/
void FaseLedEffect::loop() {

}
