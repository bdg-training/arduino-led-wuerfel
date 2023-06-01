// Adafruit_NeoPixel Bibliothek installieren
// Board: Arduino Nano (Old Bootloader)

#include <Adafruit_NeoPixel.h>
#include "LED.h"

#define LED_PIN     3
#define NUMPIXELS   320
#define BRIGHTNESS  10 // (0..255)

Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

int laufschriftPos = 6;
byte wheelPos = 0;

unsigned long startZeitPos = 0;
unsigned long startZeitColor = 0;

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

  if (millis() > startZeitPos + 200) {

    laufschriftPos--;

    if (laufschriftPos < -13) {
      laufschriftPos = 6;
    }

    startZeitPos = millis();
  }

  if (millis() > startZeitColor + 50) {

    // LEDs beschreiben
    pixels.clear();

    uint32_t color = wheel(wheelPos);
    // gruen
    //color = pixels.Color(0, 255, 0);

    zeichenV(color, laufschriftPos);
    zeichenL(color, laufschriftPos + 7);

    pixels.show();

    // neue Position in Farbrad
    wheelPos += 10;

    if (wheelPos == 255) {
      wheelPos = 0;
    }

    startZeitColor = millis();
  }
}

void zeichenV(uint32_t color, int offset) {

  ledOffsetX(LED_V_2x1, offset, color, pixels);
  ledOffsetX(LED_V_2x2, offset, color, pixels);
  ledOffsetX(LED_V_2x5, offset, color, pixels);
  ledOffsetX(LED_V_2x6, offset, color, pixels);

  ledOffsetX(LED_V_3x1, offset, color, pixels);
  ledOffsetX(LED_V_3x2, offset, color, pixels);
  ledOffsetX(LED_V_3x5, offset, color, pixels);
  ledOffsetX(LED_V_3x6, offset, color, pixels);

  ledOffsetX(LED_V_4x1, offset, color, pixels);
  ledOffsetX(LED_V_4x2, offset, color, pixels);
  ledOffsetX(LED_V_4x5, offset, color, pixels);
  ledOffsetX(LED_V_4x6, offset, color, pixels);

  ledOffsetX(LED_V_5x1, offset, color, pixels);
  ledOffsetX(LED_V_5x2, offset, color, pixels);
  ledOffsetX(LED_V_5x5, offset, color, pixels);
  ledOffsetX(LED_V_5x6, offset, color, pixels);

  ledOffsetX(LED_V_6x2, offset, color, pixels);
  ledOffsetX(LED_V_6x3, offset, color, pixels);
  ledOffsetX(LED_V_6x4, offset, color, pixels);
  ledOffsetX(LED_V_6x5, offset, color, pixels);

  ledOffsetX(LED_V_7x3, offset, color, pixels);
  ledOffsetX(LED_V_7x4, offset, color, pixels);
}

void zeichenL(uint32_t color, int offset) {

  ledOffsetX(LED_V_2x2, offset, color, pixels);
  ledOffsetX(LED_V_3x2, offset, color, pixels);
  ledOffsetX(LED_V_4x2, offset, color, pixels);
  ledOffsetX(LED_V_5x2, offset, color, pixels);
  ledOffsetX(LED_V_6x2, offset, color, pixels);
  ledOffsetX(LED_V_7x2, offset, color, pixels);

  ledOffsetX(LED_V_2x3, offset, color, pixels);
  ledOffsetX(LED_V_3x3, offset, color, pixels);
  ledOffsetX(LED_V_4x3, offset, color, pixels);
  ledOffsetX(LED_V_5x3, offset, color, pixels);
  ledOffsetX(LED_V_6x3, offset, color, pixels);
  ledOffsetX(LED_V_7x3, offset, color, pixels);

  ledOffsetX(LED_V_6x4, offset, color, pixels);
  ledOffsetX(LED_V_7x4, offset, color, pixels);

  ledOffsetX(LED_V_6x5, offset, color, pixels);
  ledOffsetX(LED_V_7x5, offset, color, pixels);
}


// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
