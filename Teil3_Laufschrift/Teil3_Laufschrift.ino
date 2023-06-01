// Adafruit_NeoPixel Bibliothek installieren
// Board: Arduino Nano (Old Bootloader)

#include <Adafruit_NeoPixel.h>
#include "LED.h"
#include "Zeichen.h"

#define LED_PIN     3
#define NUMPIXELS   320
#define BRIGHTNESS  10 // (0..255)

Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

int laufschriftPos = 0;
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

  // Position aendern?
  if (millis() > startZeitPos + 200) {

    laufschriftPos--;

    // 8 LEDs * 4 Flaechen
    if (laufschriftPos < -31) {
      laufschriftPos = 0;
    }

    startZeitPos = millis();
  }

  // Farbe aendern?
  if (millis() > startZeitColor + 50) {

    // LEDs beschreiben
    pixels.clear();

    // blau
    uint32_t color = pixels.Color(0, 0, 255);

    zeichenB(color, laufschriftPos, pixels);
    zeichenD(color, laufschriftPos + 8, pixels);
    zeichenG(color, laufschriftPos + 15, pixels);

    pixels.show();

    // neue Position in Farbrad
    wheelPos += 10;

    if (wheelPos == 255) {
      wheelPos = 0;
    }

    startZeitColor = millis();
  }
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
