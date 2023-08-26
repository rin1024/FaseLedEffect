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
#include "FaseLedEffect.h"

/*******************************************
  const
 *******************************************/
// Overall twinkle speed.
// 0 (VERY slow) to 8 (VERY fast).  
// 4, 5, and 6 are recommended, default is 4.
#define TWINKLE_SPEED 4

// Overall twinkle density.
// 0 (NONE lit) to 8 (ALL lit at once).  
// Default is 5.
#define TWINKLE_DENSITY 5

// How often to change color palettes.
#define SECONDS_PER_PALETTE  30
// Also: toward the bottom of the file is an array 
// called "ActivePaletteList" which controls which color
// palettes are used; you can add or remove color palettes
// from there freely.

// If AUTO_SELECT_BACKGROUND_COLOR is set to 1,
// then for any palette where the first two entries 
// are the same, a dimmed version of that color will
// automatically be used as the background color.
#define AUTO_SELECT_BACKGROUND_COLOR 0

// If COOL_LIKE_INCANDESCENT is set to 1, colors will 
// fade out slighted 'reddened', similar to how
// incandescent bulbs change color as they get dim down.
#define COOL_LIKE_INCANDESCENT 1

#define Holly_Green 0x00580c
#define Holly_Red   0xB00402

#define HALFFAIRY ((CRGB::FairyLight & 0xFEFEFE) / 2)
#define QUARTERFAIRY ((CRGB::FairyLight & 0xFCFCFC) / 4)

#define C9_Red    0xB80400
#define C9_Orange 0x902C02
#define C9_Green  0x046002
#define C9_Blue   0x070758
#define C9_White  0x606820

#define Ice_Blue1 0x0C1040
#define Ice_Blue2 0x182080
#define Ice_Blue3 0x5080C0

/**************************************************************************************
  Smoothing readings
 **************************************************************************************/
class TwinkleFoxEffect: public FaseLedEffect {
  public:
    void setup(CRGB *_leds, uint16_t _numLeds = 5);
    void loop();

  private:
    // Background color for 'unlit' pixels
    // Can be set to CRGB::Black if desired.
    CRGB gBackgroundColor = CRGB::Black; 
    // Example of dim incandescent fairy light background color
    // CRGB gBackgroundColor = CRGB(CRGB::FairyLight).nscale8_video(16);

    CRGBPalette16 gCurrentPalette;
    CRGBPalette16 gTargetPalette;

    // A mostly red palette with green accents and white trim.
    // "CRGB::Gray" is used as white to keep the brightness more uniform.
    const TProgmemRGBPalette16 RedGreenWhite_p FL_PROGMEM =
    {  CRGB::Red, CRGB::Red, CRGB::Red, CRGB::Red, 
      CRGB::Red, CRGB::Red, CRGB::Red, CRGB::Red, 
      CRGB::Red, CRGB::Red, CRGB::Gray, CRGB::Gray, 
      CRGB::Green, CRGB::Green, CRGB::Green, CRGB::Green };

    // A mostly (dark) green palette with red berries.
    const TProgmemRGBPalette16 Holly_p FL_PROGMEM =
    {  Holly_Green, Holly_Green, Holly_Green, Holly_Green, 
      Holly_Green, Holly_Green, Holly_Green, Holly_Green, 
      Holly_Green, Holly_Green, Holly_Green, Holly_Green, 
      Holly_Green, Holly_Green, Holly_Green, Holly_Red 
    };

    // A red and white striped palette
    // "CRGB::Gray" is used as white to keep the brightness more uniform.
    const TProgmemRGBPalette16 RedWhite_p FL_PROGMEM =
    {  CRGB::Red,  CRGB::Red,  CRGB::Red,  CRGB::Red, 
      CRGB::Gray, CRGB::Gray, CRGB::Gray, CRGB::Gray,
      CRGB::Red,  CRGB::Red,  CRGB::Red,  CRGB::Red, 
      CRGB::Gray, CRGB::Gray, CRGB::Gray, CRGB::Gray };

    // A mostly blue palette with white accents.
    // "CRGB::Gray" is used as white to keep the brightness more uniform.
    const TProgmemRGBPalette16 BlueWhite_p FL_PROGMEM =
    {  CRGB::Blue, CRGB::Blue, CRGB::Blue, CRGB::Blue, 
      CRGB::Blue, CRGB::Blue, CRGB::Blue, CRGB::Blue, 
      CRGB::Blue, CRGB::Blue, CRGB::Blue, CRGB::Blue, 
      CRGB::Blue, CRGB::Gray, CRGB::Gray, CRGB::Gray };

    // A pure "fairy light" palette with some brightness variations
    const TProgmemRGBPalette16 FairyLight_p FL_PROGMEM =
    {  CRGB::FairyLight, CRGB::FairyLight, CRGB::FairyLight, CRGB::FairyLight, 
      HALFFAIRY,        HALFFAIRY,        CRGB::FairyLight, CRGB::FairyLight, 
      QUARTERFAIRY,     QUARTERFAIRY,     CRGB::FairyLight, CRGB::FairyLight, 
      CRGB::FairyLight, CRGB::FairyLight, CRGB::FairyLight, CRGB::FairyLight };

    // A palette of soft snowflakes with the occasional bright one
    const TProgmemRGBPalette16 Snow_p FL_PROGMEM =
    {  0x304048, 0x304048, 0x304048, 0x304048,
      0x304048, 0x304048, 0x304048, 0x304048,
      0x304048, 0x304048, 0x304048, 0x304048,
      0x304048, 0x304048, 0x304048, 0xE0F0FF };

    // A palette reminiscent of large 'old-school' C9-size tree lights
    // in the five classic colors: red, orange, green, blue, and white.

    const TProgmemRGBPalette16 RetroC9_p FL_PROGMEM =
    {  C9_Red,    C9_Orange, C9_Red,    C9_Orange,
      C9_Orange, C9_Red,    C9_Orange, C9_Red,
      C9_Green,  C9_Green,  C9_Green,  C9_Green,
      C9_Blue,   C9_Blue,   C9_Blue,
      C9_White
    };

    // A cold, icy pale blue palette
    const TProgmemRGBPalette16 Ice_p FL_PROGMEM =
    {
      Ice_Blue1, Ice_Blue1, Ice_Blue1, Ice_Blue1,
      Ice_Blue1, Ice_Blue1, Ice_Blue1, Ice_Blue1,
      Ice_Blue1, Ice_Blue1, Ice_Blue1, Ice_Blue1,
      Ice_Blue2, Ice_Blue2, Ice_Blue2, Ice_Blue3
    };

    // Add or remove palette names from this list to control which color
    // palettes are used, and in what order.
    const TProgmemRGBPalette16* ActivePaletteList[10] = {
      &RetroC9_p,
      &BlueWhite_p,
      &RainbowColors_p,
      &FairyLight_p,
      &RedGreenWhite_p,
      &PartyColors_p,
      &RedWhite_p,
      &Snow_p,
      &Holly_p,
      &Ice_p  
    };

    void drawTwinkles();
    uint8_t attackDecayWave8( uint8_t i);
    CRGB computeOneTwinkle( uint32_t ms, uint8_t salt);
    void coolLikeIncandescent( CRGB& c, uint8_t phase);
    void chooseNextColorPalette( CRGBPalette16& pal);
};

#endif
