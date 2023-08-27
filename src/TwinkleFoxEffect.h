/**
  TwinkleFoxEffect
  */
#ifndef TWINKLE_FOX__EFFECT_H
#define TWINKLE_FOX__EFFECT_H

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
#include "FastLEDEffectPalette.h"

/*******************************************
  const
 *******************************************/
// Overall twinkle speed.
// 0 (VERY slow) to 8 (VERY fast).  
// 4, 5, and 6 are recommended, default is 4.
#define DEFAULT_TWINKLE_SPEED 4

// Overall twinkle density.
// 0 (NONE lit) to 8 (ALL lit at once).  
// Default is 5.
#define DEFAULT_TWINKLE_DENSITY 5

// If AUTO_SELECT_BACKGROUND_COLOR is set to 1,
// then for any palette where the first two entries 
// are the same, a dimmed version of that color will
// automatically be used as the background color.
#define DEFAULT_AUTO_SELECT_BACKGROUND_COLOR false

// If COOL_LIKE_INCANDESCENT is set to 1, colors will 
// fade out slighted 'reddened', similar to how
// incandescent bulbs change color as they get dim down.
#define DEFAULT_COOL_LIKE_INCANDESCENT true

/**************************************************************************************
  class definition
 **************************************************************************************/
class TwinkleFoxEffect: public FastLEDEffect {
  public:
    void setup(CRGB *_leds, uint16_t _numLeds = 5);
    void loop();

    void setBackgroundColor(CRGB _backgroundColor);
    void setTargetPalette(CRGBPalette16 &_nextPalette);
    void setTwinkleSpeed(uint8_t _twinkleSpeed);
    void setTwinkleDensity(uint8_t _twinkleDensity);
    
    void setAutoSelectBackgroundColorFlag(bool _flag);
    void setCoolLikeIncandescentFlag(bool _flag);

  private:
    // Background color for 'unlit' pixels
    // Can be set to CRGB::Black if desired.
    CRGB gBackgroundColor = CRGB::Black; 
    // Example of dim incandescent fairy light background color
    // CRGB gBackgroundColor = CRGB(CRGB::FairyLight).nscale8_video(16);

    CRGBPalette16 gCurrentPalette;
    CRGBPalette16 gTargetPalette;

    uint8_t twinkleSpeed = DEFAULT_TWINKLE_SPEED;
    uint8_t twinkleDensity = DEFAULT_TWINKLE_DENSITY;

    bool autoSelectBackgroundColorFlag = DEFAULT_AUTO_SELECT_BACKGROUND_COLOR;
    bool coolLikeIncandescentFlag = DEFAULT_COOL_LIKE_INCANDESCENT;

    void drawTwinkles();
    uint8_t attackDecayWave8( uint8_t i);
    CRGB computeOneTwinkle( uint32_t ms, uint8_t salt);
    void coolLikeIncandescent( CRGB& c, uint8_t phase);
};

#endif
