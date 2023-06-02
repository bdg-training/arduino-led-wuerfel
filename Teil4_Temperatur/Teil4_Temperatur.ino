// Adafruit_NeoPixel Bibliothek installieren
// Adafruit_MCP9808_Library installieren
// Board: Arduino Nano (Old Bootloader)

#include <Wire.h>
#include "Adafruit_MCP9808.h"
#include <Adafruit_NeoPixel.h>
#include "LED.h"
#include "Zahlen.h"

#define LED_PIN     3
#define NUMPIXELS   320
#define BRIGHTNESS  10 // (0..255)

Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();

byte wheelPos = 0;

float temperatur;

unsigned long startZeitColor = 0;
unsigned long startZeitTemperatur = 0;

void setup() {
  delay(500);
  Serial.begin(115200);
  Serial.println(" ");
  Serial.println(" ");
  Serial.println("setup()");

  pixels.begin();
  pixels.setBrightness(BRIGHTNESS);

  if (!tempsensor.begin(0x18)) {
    Serial.println("MCP9808 nicht gefunden");
    while (1);
  }

  tempsensor.setResolution(0);
}

void loop() {

  // Temperatur lesen?
  if (millis() > startZeitTemperatur + 1000) {

    tempsensor.wake();
    temperatur = tempsensor.readTempC();
    Serial.print("Temp: ");
    Serial.print(temperatur, 4);
    Serial.println("*C");
    tempsensor.shutdown_wake(1);

    startZeitTemperatur = millis();
  }


  // Farbe aendern?
  if (millis() > startZeitColor + 100) {

    // LEDs beschreiben
    pixels.clear();

    schreibeTemp(temperatur);

    pixels.show();

    // neue Position in Farbrad
    wheelPos += 1;

    if (wheelPos == 255) {
      wheelPos = 0;
    }

    startZeitColor = millis();
  }
}

void schreibeTemp(float c) {

  int temp = round(c);

  //test
  //temp = 17;

  uint32_t color = pixels.Color(255, 255, 255);

  // je nach Temperaturbereich, Zahlen einfaerben
  if (temp <= 18) {
    color = pixels.Color(0, 0, 255);
  }

  if (temp >= 19 && temp < 25 ) {
    color = pixels.Color(0, 255, 0);
  }

  if (temp >= 26 && temp < 30 ) {
    color = pixels.Color(200, 100, 0);
  }

  if (temp >= 30 ) {
    color = pixels.Color(255, 0, 0);
  }


  String s = "";
  if (temp < 10) {
    s = s + "0";
  }
  s = s + String(temp);

  int dec0 = s.substring(0, 1).toInt();
  int dec1 = s.substring(1, 2).toInt();

  schreibeZahl(dec0, 0, color);
  schreibeZahl(dec1, 4, color);
}

void schreibeZahl(int dec, int offset, uint32_t color) {

  switch (dec) {
    case 0:
      zahl0k(color, offset, pixels);
      break;

    case 1:
      zahl1k(color, offset, pixels);
      break;

    case 2:
      zahl2k(color, offset, pixels);
      break;

    case 3:
      zahl3k(color, offset, pixels);
      break;

    case 4:
      zahl4k(color, offset, pixels);
      break;

    case 5:
      zahl5k(color, offset, pixels);
      break;

    case 6:
      zahl6k(color, offset, pixels);
      break;

    case 7:
      zahl7k(color, offset, pixels);
      break;

    case 8:
      zahl8k(color, offset, pixels);
      break;

    case 9:
      zahl9k(color, offset, pixels);
      break;
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
