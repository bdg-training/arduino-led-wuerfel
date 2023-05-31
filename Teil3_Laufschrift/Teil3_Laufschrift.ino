// Adafruit_NeoPixel Bibliothek installieren
// Board: Arduino Nano (Old Bootloader)

#include <Adafruit_NeoPixel.h>
#include "LED.h"

#define LED_PIN     3
#define NUMPIXELS   320
#define BRIGHTNESS  10 // (0..255)

Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

uint32_t colorVorne;

int laufschriftPos = 7;

void setup() {
  delay(500);
  Serial.begin(115200);
  Serial.println(" ");
  Serial.println(" ");
  Serial.println("setup()");

  pixels.begin();
  pixels.setBrightness(BRIGHTNESS);
}

void loop() {

  // LEDs beschreiben
  pixels.clear();

  // gruen
  uint32_t color = pixels.Color(0, 255, 0);
  vorne(color, laufschriftPos);

  pixels.show();

  laufschriftPos--;

  if (laufschriftPos < -7) {
    laufschriftPos = 7;
  }

  delay(200);
}

void vorne(uint32_t color, int offset) {

  ledOffsetX(LED_V_2x2, offset, color, pixels);
  ledOffsetX(LED_V_2x3, offset, color, pixels);
  ledOffsetX(LED_V_2x6, offset, color, pixels);
  ledOffsetX(LED_V_2x7, offset, color, pixels);

  ledOffsetX(LED_V_3x2, offset, color, pixels);
  ledOffsetX(LED_V_3x3, offset, color, pixels);
  ledOffsetX(LED_V_3x6, offset, color, pixels);
  ledOffsetX(LED_V_3x7, offset, color, pixels);

  ledOffsetX(LED_V_4x2, offset, color, pixels);
  ledOffsetX(LED_V_4x3, offset, color, pixels);
  ledOffsetX(LED_V_4x6, offset, color, pixels);
  ledOffsetX(LED_V_4x7, offset, color, pixels);

  ledOffsetX(LED_V_5x2, offset, color, pixels);
  ledOffsetX(LED_V_5x3, offset, color, pixels);
  ledOffsetX(LED_V_5x6, offset, color, pixels);
  ledOffsetX(LED_V_5x7, offset, color, pixels);

  ledOffsetX(LED_V_6x3, offset, color, pixels);
  ledOffsetX(LED_V_6x4, offset, color, pixels);
  ledOffsetX(LED_V_6x5, offset, color, pixels);
  ledOffsetX(LED_V_6x6, offset, color, pixels);

  ledOffsetX(LED_V_7x4, offset, color, pixels);
  ledOffsetX(LED_V_7x5, offset, color, pixels);
}
