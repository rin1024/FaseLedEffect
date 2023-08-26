/**
   FaseLedEffect
*/
#ifndef FAST_LED_EFFECT_H
#define FAST_LED_EFFECT_H

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

/*******************************************
   const
 *******************************************/
//

/**************************************************************************************
   Smoothing readings
 **************************************************************************************/
class FaseLedEffect {
  public:
    FaseLedEffect();
    ~FaseLedEffect();

    void setup(CRGB *_leds, uint16_t _numLeds = 5);
    void loop();

  protected:
    CRGB *leds; // CRGBSet
    uint16_t numLeds;
};

#endif
