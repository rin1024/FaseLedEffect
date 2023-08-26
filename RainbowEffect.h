/**
 * RainbowEffect
 */
#ifndef RAINBOW_EFFECT_H
#define RAINBOW_EFFECT_H

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
#define RAINBOW_SPEED 5 // 20

/**************************************************************************************
  class definition
 **************************************************************************************/
class RainbowEffect: public FaseLedEffect {
  public:
    void loop();

  private:
    uint8_t rainbowHue;
    
    void fill_rainbow_with_brigthness(uint8_t initialhue, uint8_t deltahue);
};

#endif
