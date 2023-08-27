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
#include "FastLEDEffect.h"

/*******************************************
   const
 *******************************************/
//

/**************************************************************************************
   class definition
 **************************************************************************************/
class PrideEffect: public FastLEDEffect {
  public:
    void loop();

  private:
    uint16_t sPseudotime = 0;
    uint16_t sLastMillis = 0;
    uint16_t sHue16 = 0;
};

#endif
