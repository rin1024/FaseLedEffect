/**
 * easing
 * By: Andrew Tuline
 *
 * Date: August, 2015
 *
 * This boring display demonstrates the easing capability of FastLED. The Red LED starts out slow, speeds up and then slows down when it gets to the end.
 *
 * It uses uint8_t variables and may not work correctly on longer strands . . as noted by GitHub user fahrvergnuunen.
 *
 * easeOutVal = ease8InOutQuad(easeInVal);                       // Start with easeInVal at 0 and then go to 255 for the full easing.
 * ledNum = lerp8by8(0, NUM_LEDS, easeOutVal);                   // Map it to the number of LED's you have.
 *
 * Reference:
 * 
 * https://github.com/FastLED/FastLED/wiki/High-performance-math
 * 
 * Ideas:
 *  - Ease from 128 to 255 to throw something in the air
 *  - Ease from 255 to 128 and reverse direction for it to fall back.
 *  - Reduce the lerp8 value after each cycle to simulate a bouncing ball.
 */
#ifndef EASING_EFFECT_H
#define EASING_EFFECT_H

/*******************************************
  include
 *******************************************/
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>
#include <avr/pgmspace.h>
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <FastLED.h>
#include "FastLEDEffect.h"

/*******************************************
  const
 *******************************************/


/**************************************************************************************
  class definition
 **************************************************************************************/
class EasingEffect: public FastLEDEffect {
  public:
    void setup(CRGB *_leds, uint16_t _numLeds = 5);
    void loop();

    void setDelayMillis(uint16_t _delayMillis);

  private:
    uint8_t easeOutVal = 0;
    uint8_t easeInVal  = 0;
    uint8_t lerpVal    = 0;

    uint16_t delayMillis = 0;

    void ease();
};

#endif
