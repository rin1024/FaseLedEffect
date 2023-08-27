/**
 * FireEffect
 *
 * 炎をイメージしたエフェクト
 */
#include "FireEffect.h"

/**
   コンストラクタ
*/
FireEffect::FireEffect() {
}

/**
   デストラクタ
*/
FireEffect::~FireEffect() {
  delete[] heat;
}

/**
 *
 */
void FireEffect::setup(CRGB *_leds, uint16_t _numLeds) {
  FaseLedEffect::setup(_leds, _numLeds);

  heat = new uint8_t[_numLeds];
  for (uint16_t i=0;i<_numLeds;i++) {
    heat[i] = 0;
  }
}

/** 
 * This function draws rainbows with an ever-changing,
 * widely-varying set of parameters.
 */
void FireEffect::loop() {
  // Add entropy to random number generator; we use a lot of it.
  // random16_add_entropy( random());
  Fire2012(); // run simulation frame
}

void FireEffect::Fire2012(){
  // Step 1.  Cool down every cell a little
  for( uint16_t i = 0; i < numLeds; i++) {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / numLeds) + 2));
  }

  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for( uint16_t k= numLeds - 1; k >= 2; k--) {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }

  // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
  if( random8() < SPARKING ) {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }

  // Step 4.  Map from heat cells to LED colors
  for( uint16_t j = 0; j < numLeds; j++) {
    CRGB color = HeatColor(heat[j]);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (numLeds - 1) - j;
    } else {
      pixelnumber = j;
    }
    leds[pixelnumber] = blend(CRGB::Black, color, getBrightness());
  }
}
