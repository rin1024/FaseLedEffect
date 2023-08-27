/**
 * ConfettiEffect
 *
 * つぶつぶが点在するエフェクト
 */
#include "ConfettiEffect.h"

/**
 * A time (rather than loop) based demo sequencer. This gives us full control over the length of each sequence.
 */
void ConfettiEffect::loop() {
  // Check the demo loop for changes to the variables
  // Change Me
  uint8_t secondHand = (millis() / 1000) % 15;                // IMPORTANT!!! Change '15' to a different value to change duration of the loop.
  static uint8_t lastSecond = 99;                             // Static variable, means it's only defined once. This is our 'debounce' variable.
  if (lastSecond != secondHand) {                             // Debounce to make sure we're not repeating an assignment.
    lastSecond = secondHand;
    switch(secondHand) {
      case  0: thisinc=1; thishue=192; thissat=255; thisfade=2; huediff=256; break;  // You can change values here, one at a time , or altogether.
      case  5: thisinc=2; thishue=128; thisfade=8; huediff=64; break;
      case 10: thisinc=1; thishue=random16(255); thisfade=1; huediff=16; break;      // Only gets called once, and not continuously for the next several seconds. Therefore, no rainbows.
      case 15: break;                                                                // Here's the matching 15 for the other one.
    }
  }

  // FastLED based non-blocking delay to update/display the sequence.
  EVERY_N_MILLISECONDS(thisdelay) {
    confetti();
  }
}

/**
 * random colored speckles that blink in and fade smoothly
 */
void ConfettiEffect::confetti() {
  fadeToBlackBy(leds, numLeds, thisfade);                    // Low values = slower fade.
  int pos = random16(numLeds);                               // Pick an LED at random.

  // デフォルトのカラフルver
  // leds[pos] += CHSV((thishue + random16(huediff))/4, thissat, getBrightness());  // I use 12 bits for hue so that the hue increment isn't too quick.

  // 白のみのつぶつぶ表現ver
  // NOTE: HSVのHとSを0にすると白になる
  leds[pos] += CHSV(0, 0, getBrightness());  // I use 12 bits for hue so that the hue increment isn't too quick.

  thishue = thishue + thisinc;                                // It increments here.
}
