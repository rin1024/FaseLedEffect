/**
  CylonEffect
  */
#ifndef CYLON_EFFECT_H
#define CYLON_EFFECT_H

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
class CylonEffect: public FaseLedEffect {
  public:
    void loop();

  private:
    uint8_t hue = 0;

    void fadeall();
};

#endif
