// 炎をイメージしたエフェクト
#define FASTLED_ALLOW_INTERRUPTS 0
#include <FastLED.h>
FASTLED_USING_NAMESPACE
#include "FireEffect.h"

#define __COMPILE_DATE__ __DATE__ " " __TIME__
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define DATA_PIN    3
#define LED_TYPE    WS2812
#define COLOR_ORDER BGR
#define NUM_LEDS    100

#define FRAMES_SPEED 15 // 小さいほど早くなる、30くらいがいいかも

CRGB leds[NUM_LEDS];

FireEffect effect;

void setup() {
  Serial.begin(115200);
  delay(3000); // 3 second delay for recovery
 
  char buff[50];
  sprintf(buff, "[%s] %s", __COMPILE_DATE__, __FILENAME__);
  Serial.println(buff);

  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS)
    .setCorrection(TypicalLEDStrip);

  effect.setup(leds, NUM_LEDS);
}

void loop() {
  EVERY_N_MILLISECONDS(FRAMES_SPEED) {
    effect.loop();
  }
  
  FastLED.show();
}
