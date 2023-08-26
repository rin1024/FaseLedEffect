#define FASTLED_ALLOW_INTERRUPTS 0
#include <FastLED.h>
FASTLED_USING_NAMESPACE
#include "TwinkleFoxEffect.h"
#include "TwinklePaletteList.h"

#define __COMPILE_DATE__ __DATE__ " " __TIME__
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define NUM_LEDS      100
#define LED_TYPE   WS2812
#define COLOR_ORDER   RGB
#define DATA_PIN        3

CRGBArray<NUM_LEDS> leds;

TwinkleFoxEffect effect;

// Add or remove palette names from this list to control which color
// palettes are used, and in what order.
const TProgmemRGBPalette16* ActivePaletteList[] = {
  &Snow_p,
  &Ice_p,
  &RetroC9_p,
  &BlueWhite_p,
  &RainbowColors_p,
  &FairyLight_p,
  &RedGreenWhite_p,
  &PartyColors_p,
  &RedWhite_p,
  &Holly_p,
};

uint8_t currentPaletteIndex = -1;

void setup() {
  Serial.begin(115200);
  delay(3000); // 3 second delay for recovery

  char buff[50];
  sprintf(buff, "[%s] %s", __COMPILE_DATE__, __FILENAME__);
  Serial.println(buff);

  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS)
    .setCorrection(TypicalLEDStrip);

  effect.setup(leds, NUM_LEDS);

  chooseNextColorPalette(0);
}

void loop() {
  EVERY_N_SECONDS( SECONDS_PER_PALETTE ) { 
    const uint8_t numberOfPalettes = sizeof(ActivePaletteList) / sizeof(ActivePaletteList[0]);
    currentPaletteIndex = addmod8( currentPaletteIndex, 1, numberOfPalettes);
    
    //chooseNextColorPalette(currentPaletteIndex); 
  }
  
  effect.loop();
  
  FastLED.show();
}

// Advance to the next color palette in the list (above).
void chooseNextColorPalette(int _paletteIndex) {
  CRGBPalette16 pal = *ActivePaletteList[_paletteIndex];
  effect.setTargetPalette(pal);
}
