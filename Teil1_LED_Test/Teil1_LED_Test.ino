// Adafruit_NeoPixel Bibliothek installieren
// Board: Arduino Nano (Old Bootloader)

#include <Adafruit_NeoPixel.h>
#include "LED.h"

#define LED_PIN     3
#define NUMPIXELS   320
#define BRIGHTNESS  10 // (0..255)

Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

byte wheelPosOben = 0;
byte wheelPosVorne = 80;
byte wheelPosRechts = 120;
byte wheelPosHinten = 160;
byte wheelPosLinks = 200;

uint32_t colorOben;
uint32_t colorVorne;
uint32_t colorRechts;
uint32_t colorHinten;
uint32_t colorLinks;

int lauflichtPos;

void setup() {
  pixels.begin();
  pixels.setBrightness(BRIGHTNESS);
}

void loop() {

  // neue Farben auslesen
  colorOben = wheel(wheelPosOben);
  colorVorne = wheel(wheelPosVorne);
  colorRechts = wheel(wheelPosRechts);
  colorHinten = wheel(wheelPosHinten);
  colorLinks = wheel(wheelPosLinks);

  // neue Position in Farbrad
  wheelPosOben++;

  if (wheelPosOben == 255) {
    wheelPosOben = 0;
  }

  wheelPosVorne++;

  if (wheelPosVorne == 255) {
    wheelPosVorne = 0;
  }

  wheelPosRechts++;

  if (wheelPosRechts == 255) {
    wheelPosRechts = 0;
  }

  wheelPosHinten++;

  if (wheelPosHinten == 255) {
    wheelPosHinten = 0;
  }

  wheelPosLinks++;

  if (wheelPosLinks == 255) {
    wheelPosLinks = 0;
  }

  // LEDs beschreiben
  pixels.clear();

  oben(colorOben);
  vorne(colorVorne);
  rechts(colorRechts);
  hinten(colorHinten);
  links(colorLinks);

  lauflicht();

  pixels.show();

  delay(40);
}

void lauflicht() {

  switch (lauflichtPos) {
    case 1:
      pixels.setPixelColor(LED_V_8x1, colorVorne);
      break;

    case 2:
      pixels.setPixelColor(LED_V_8x2, colorVorne);
      break;

    case 3:
      pixels.setPixelColor(LED_V_8x3, colorVorne);
      break;

    case 4:
      pixels.setPixelColor(LED_V_8x4, colorVorne);
      break;

    case 5:
      pixels.setPixelColor(LED_V_8x5, colorVorne);
      break;

    case 6:
      pixels.setPixelColor(LED_V_8x6, colorVorne);
      break;

    case 7:
      pixels.setPixelColor(LED_V_8x7, colorVorne);
      break;

    case 8:
      pixels.setPixelColor(LED_V_8x8, colorVorne);
      break;

    case 9:
      pixels.setPixelColor(LED_R_8x1, colorRechts);
      break;

    case 10:
      pixels.setPixelColor(LED_R_8x2, colorRechts);
      break;

    case 11:
      pixels.setPixelColor(LED_R_8x3, colorRechts);
      break;

    case 12:
      pixels.setPixelColor(LED_R_8x4, colorRechts);
      break;

    case 13:
      pixels.setPixelColor(LED_R_8x5, colorRechts);
      break;

    case 14:
      pixels.setPixelColor(LED_R_8x6, colorRechts);
      break;

    case 15:
      pixels.setPixelColor(LED_R_8x7, colorRechts);
      break;

    case 16:
      pixels.setPixelColor(LED_R_8x8, colorRechts);
      break;

    case 17:
      pixels.setPixelColor(LED_H_8x1, colorHinten);
      break;

    case 18:
      pixels.setPixelColor(LED_H_8x2, colorHinten);
      break;

    case 19:
      pixels.setPixelColor(LED_H_8x3, colorHinten);
      break;

    case 20:
      pixels.setPixelColor(LED_H_8x4, colorHinten);
      break;

    case 21:
      pixels.setPixelColor(LED_H_8x5, colorHinten);
      break;

    case 22:
      pixels.setPixelColor(LED_H_8x6, colorHinten);
      break;

    case 23:
      pixels.setPixelColor(LED_H_8x7, colorHinten);
      break;

    case 24:
      pixels.setPixelColor(LED_H_8x8, colorHinten);
      break;

    case 25:
      pixels.setPixelColor(LED_L_8x1, colorLinks);
      break;

    case 26:
      pixels.setPixelColor(LED_L_8x2, colorLinks);
      break;

    case 27:
      pixels.setPixelColor(LED_L_8x3, colorLinks);
      break;

    case 28:
      pixels.setPixelColor(LED_L_8x4, colorLinks);
      break;

    case 29:
      pixels.setPixelColor(LED_L_8x5, colorLinks);
      break;

    case 30:
      pixels.setPixelColor(LED_L_8x6, colorLinks);
      break;

    case 31:
      pixels.setPixelColor(LED_L_8x7, colorLinks);
      break;

    case 32:
      pixels.setPixelColor(LED_L_8x8, colorLinks);
      break;

    default:
      lauflichtPos = 0;
      break;
  }

  lauflichtPos++;
}

void vorne(uint32_t color) {
  pixels.setPixelColor(LED_V_1x1, color);

  pixels.setPixelColor(LED_V_2x2, color);
  pixels.setPixelColor(LED_V_2x3, color);
  pixels.setPixelColor(LED_V_2x6, color);
  pixels.setPixelColor(LED_V_2x7, color);

  pixels.setPixelColor(LED_V_3x2, color);
  pixels.setPixelColor(LED_V_3x3, color);
  pixels.setPixelColor(LED_V_3x6, color);
  pixels.setPixelColor(LED_V_3x7, color);

  pixels.setPixelColor(LED_V_4x2, color);
  pixels.setPixelColor(LED_V_4x3, color);
  pixels.setPixelColor(LED_V_4x6, color);
  pixels.setPixelColor(LED_V_4x7, color);

  pixels.setPixelColor(LED_V_5x2, color);
  pixels.setPixelColor(LED_V_5x3, color);
  pixels.setPixelColor(LED_V_5x6, color);
  pixels.setPixelColor(LED_V_5x7, color);

  pixels.setPixelColor(LED_V_6x3, color);
  pixels.setPixelColor(LED_V_6x4, color);
  pixels.setPixelColor(LED_V_6x5, color);
  pixels.setPixelColor(LED_V_6x6, color);

  pixels.setPixelColor(LED_V_7x4, color);
  pixels.setPixelColor(LED_V_7x5, color);
}

void oben(uint32_t color) {
  pixels.setPixelColor(LED_O_1x1, color);

  pixels.setPixelColor(LED_O_2x4, color);
  pixels.setPixelColor(LED_O_2x5, color);

  pixels.setPixelColor(LED_O_3x3, color);
  pixels.setPixelColor(LED_O_3x4, color);
  pixels.setPixelColor(LED_O_3x5, color);
  pixels.setPixelColor(LED_O_3x6, color);

  pixels.setPixelColor(LED_O_4x2, color);
  pixels.setPixelColor(LED_O_4x3, color);
  pixels.setPixelColor(LED_O_4x6, color);
  pixels.setPixelColor(LED_O_4x7, color);

  pixels.setPixelColor(LED_O_5x2, color);
  pixels.setPixelColor(LED_O_5x3, color);
  pixels.setPixelColor(LED_O_5x6, color);
  pixels.setPixelColor(LED_O_5x7, color);

  pixels.setPixelColor(LED_O_6x3, color);
  pixels.setPixelColor(LED_O_6x4, color);
  pixels.setPixelColor(LED_O_6x5, color);
  pixels.setPixelColor(LED_O_6x6, color);

  pixels.setPixelColor(LED_O_7x4, color);
  pixels.setPixelColor(LED_O_7x5, color);
}

void rechts(uint32_t color) {
  pixels.setPixelColor(LED_R_1x1, color);

  pixels.setPixelColor(LED_R_2x2, color);
  pixels.setPixelColor(LED_R_3x2, color);
  pixels.setPixelColor(LED_R_4x2, color);
  pixels.setPixelColor(LED_R_5x2, color);
  pixels.setPixelColor(LED_R_6x2, color);
  pixels.setPixelColor(LED_R_7x2, color);

  pixels.setPixelColor(LED_R_2x3, color);
  pixels.setPixelColor(LED_R_3x3, color);
  pixels.setPixelColor(LED_R_4x3, color);
  pixels.setPixelColor(LED_R_5x3, color);
  pixels.setPixelColor(LED_R_6x3, color);
  pixels.setPixelColor(LED_R_7x3, color);

  pixels.setPixelColor(LED_R_2x4, color);
  pixels.setPixelColor(LED_R_2x5, color);
  pixels.setPixelColor(LED_R_3x6, color);
  pixels.setPixelColor(LED_R_4x6, color);
  pixels.setPixelColor(LED_R_5x5, color);
  pixels.setPixelColor(LED_R_5x4, color);
  pixels.setPixelColor(LED_R_6x6, color);
  pixels.setPixelColor(LED_R_7x6, color);
}

void hinten(uint32_t color) {
  pixels.setPixelColor(LED_H_1x1, color);

  pixels.setPixelColor(LED_H_2x2, color);
  pixels.setPixelColor(LED_H_3x2, color);
  pixels.setPixelColor(LED_H_4x2, color);
  pixels.setPixelColor(LED_H_5x2, color);
  pixels.setPixelColor(LED_H_6x2, color);
  pixels.setPixelColor(LED_H_7x2, color);

  pixels.setPixelColor(LED_H_2x3, color);
  pixels.setPixelColor(LED_H_3x3, color);
  pixels.setPixelColor(LED_H_4x3, color);
  pixels.setPixelColor(LED_H_5x3, color);
  pixels.setPixelColor(LED_H_6x3, color);
  pixels.setPixelColor(LED_H_7x3, color);

  pixels.setPixelColor(LED_H_2x6, color);
  pixels.setPixelColor(LED_H_3x6, color);
  pixels.setPixelColor(LED_H_4x6, color);
  pixels.setPixelColor(LED_H_5x6, color);
  pixels.setPixelColor(LED_H_6x6, color);
  pixels.setPixelColor(LED_H_7x6, color);

  pixels.setPixelColor(LED_H_2x7, color);
  pixels.setPixelColor(LED_H_3x7, color);
  pixels.setPixelColor(LED_H_4x7, color);
  pixels.setPixelColor(LED_H_5x7, color);
  pixels.setPixelColor(LED_H_6x7, color);
  pixels.setPixelColor(LED_H_7x7, color);

  pixels.setPixelColor(LED_H_4x4, color);
  pixels.setPixelColor(LED_H_4x5, color);
  pixels.setPixelColor(LED_H_5x4, color);
  pixels.setPixelColor(LED_H_5x5, color);
}

void links(uint32_t color) {
  pixels.setPixelColor(LED_L_1x1, color);

  pixels.setPixelColor(LED_L_2x3, color);
  pixels.setPixelColor(LED_L_3x3, color);
  pixels.setPixelColor(LED_L_4x3, color);
  pixels.setPixelColor(LED_L_5x3, color);
  pixels.setPixelColor(LED_L_6x3, color);
  pixels.setPixelColor(LED_L_7x3, color);

  pixels.setPixelColor(LED_L_2x4, color);
  pixels.setPixelColor(LED_L_3x4, color);
  pixels.setPixelColor(LED_L_4x4, color);
  pixels.setPixelColor(LED_L_5x4, color);
  pixels.setPixelColor(LED_L_6x4, color);
  pixels.setPixelColor(LED_L_7x4, color);

  pixels.setPixelColor(LED_L_6x5, color);
  pixels.setPixelColor(LED_L_7x5, color);

  pixels.setPixelColor(LED_L_6x6, color);
  pixels.setPixelColor(LED_L_7x6, color);
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
