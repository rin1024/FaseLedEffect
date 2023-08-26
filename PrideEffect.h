/**
   PrideEffect
*/
#ifndef PRIDE_EFFECT_H
#define PRIDE_EFFECT_H

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
//

/**************************************************************************************
   class definition
 **************************************************************************************/
class PrideEffect: public FaseLedEffect {
  public:
    void loop();
};

#endif
