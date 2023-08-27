/**
 * BeatWaveEffect
 *
 * 波のようにいったりきたりするエフェクト
 */
#include "BeatWaveEffect.h"

/**
 *
 */
void BeatWaveEffect::setup(CRGB *_leds, uint16_t _numLeds) {
  FastLEDEffect::setup(_leds, _numLeds);

  currentPalette = RainbowColors_p;
}

/**
 * 
 */
void BeatWaveEffect::loop() {
  beatwave();

  // AWESOME palette blending capability.
  EVERY_N_MILLISECONDS(100) {
    uint8_t maxChanges = 24; 
    nblendPaletteTowardPalette(currentPalette, targetPalette, maxChanges);
  }

  // TODO: これは外だしにしてパレット変えられるようにしてもいいかも
  // Change the target palette to a random one every 5 seconds.
  EVERY_N_SECONDS(5) {
    targetPalette = CRGBPalette16(
        CHSV(random8(), 255, random8(128,255)), 
        CHSV(random8(), 255, random8(128,255)), 
        CHSV(random8(), 192, random8(128,255)), 
        CHSV(random8(), 255, random8(128,255)));
  }
}

/**
 * 
 */
void BeatWaveEffect::beatwave() {
  // That's the same as beatsin8(9);
  uint8_t wave1 = beatsin8(9, 0, 255);
  uint8_t wave2 = beatsin8(8, 0, 255);
  uint8_t wave3 = beatsin8(7, 0, 255);
  uint8_t wave4 = beatsin8(6, 0, 255);

  for (uint16_t i=0; i<numLeds; i++) {
    // same as ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending)
    leds[i] = ColorFromPalette(
        currentPalette, 
        i + wave1 + wave2 + wave3 + wave4, 
        getBrightness(), 
        currentBlending); 
  }
}
