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
#include "FastLEDEffect.h"

/**************************************************************************************
  class definition
 **************************************************************************************/
class RainbowEffect: public FastLEDEffect {
  public:
    void setup(CRGB *_leds, uint16_t _numLeds = 5);
    void loop();

    void setSaturation(uint8_t _saturation);
    void setRainbowSpeed(uint16_t _rainbowSpeed);

  private:
    uint8_t rainbowHue;
    uint8_t saturation;
    uint16_t rainbowSpeed;
    
    void fill_rainbow_with_brigthness(uint8_t initialhue, uint8_t deltahue);
};

#endif
