/**
  ConfettiEffect
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
class ConfettiEffect: public FaseLedEffect {
  public:
    void loop();

  private:
    unsigned long previousMillis;                                 // Store last time the strip was updated.

    // Define variables used by the sequences.
    uint8_t  thisfade = 8;                                        // How quickly does it fade? Lower = slower fade rate.
    int       thishue = 50;                                       // Starting hue.
    uint8_t   thisinc = 1;                                        // Incremental value for rotating hues
    uint8_t   thissat = 100;                                      // The saturation, where 255 = brilliant colours.
    int       huediff = 256;                                      // Range of random #'s to use for hue
    uint8_t thisdelay = 5;                                        // We don't need much delay (if any)

    void confetti();
};

#endif
