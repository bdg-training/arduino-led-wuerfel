// Adafruit_NeoPixel Bibliothek installieren
// Board: Arduino Nano (Old Bootloader)

#include <Adafruit_NeoPixel.h>
#include "LED.h"

#define LED_PIN     3
#define NUMPIXELS   320
#define BRIGHTNESS  10 // (0..255)

Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

uint32_t colorVorne;

int laufschriftPos;
int xPos;

void setup() {
  pixels.begin();
  pixels.setBrightness(BRIGHTNESS);
}

void loop() {



  laufschriftPos++;

    // LEDs beschreiben
  pixels.clear();

  // gruen
  uint32_t color = pixels.Color(0, 255, 0);
  vorne(color, laufschriftPos);
  

  pixels.show();


  delay(1000);
}

void vorne(uint32_t color, int pos) {

  pixels.setPixelColor(LED_V_2x2 + pos, color);
  pixels.setPixelColor(LED_V_2x3 + pos, color);
  pixels.setPixelColor(LED_V_2x6 + pos, color);
  pixels.setPixelColor(LED_V_2x7 + pos, color);

  pixels.setPixelColor(LED_V_3x2 + pos, color);
  pixels.setPixelColor(LED_V_3x3 + pos, color);
  pixels.setPixelColor(LED_V_3x6 + pos, color);
  pixels.setPixelColor(LED_V_3x7 + pos, color);

  pixels.setPixelColor(LED_V_4x2 + pos, color);
  pixels.setPixelColor(LED_V_4x3 + pos, color);
  pixels.setPixelColor(LED_V_4x6 + pos, color);
  pixels.setPixelColor(LED_V_4x7 + pos, color);

  pixels.setPixelColor(LED_V_5x2 + pos, color);
  pixels.setPixelColor(LED_V_5x3 + pos, color);
  pixels.setPixelColor(LED_V_5x6 + pos, color);
  pixels.setPixelColor(LED_V_5x7 + pos, color);

  pixels.setPixelColor(LED_V_6x3 + pos, color);
  pixels.setPixelColor(LED_V_6x4 + pos, color);
  pixels.setPixelColor(LED_V_6x5 + pos, color);
  pixels.setPixelColor(LED_V_6x6 + pos, color);

  pixels.setPixelColor(LED_V_7x4 + pos, color);
  pixels.setPixelColor(LED_V_7x5 + pos, color);
}
