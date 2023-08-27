/**
 * CylonEffect
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
#define DIRECTION_BOTH          1
#define DIRECTION_FORWARD_ONLY  2
#define DIRECTION_BACKWARD_ONLY 3

/**************************************************************************************
  class definition
 **************************************************************************************/
class CylonEffect: public FaseLedEffect {
  public:
    void loop();

    void setDirection(uint8_t _direction);

  private:
    uint8_t direction = DIRECTION_BOTH;
    uint8_t hue = 0;

    void fadeall();
};

#endif
