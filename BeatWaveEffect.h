/**
  BeatWaveEffect
  */
#ifndef CONFETTI_EFFECT_H
#define CONFETTI_EFFECT_H

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
#include "FaseLedEffect.h"

/*******************************************
  const
 *******************************************/


/**************************************************************************************
  Smoothing readings
 **************************************************************************************/
class BeatWaveEffect: public FaseLedEffect {
  public:
    void setup(CRGB *_leds, uint16_t _numLeds = 5);
    void loop();

  private:
    // Palette definitions
    CRGBPalette16 currentPalette;
    CRGBPalette16 targetPalette;
    TBlendType    currentBlending = LINEARBLEND;

    void beatwave();
};

#endif
