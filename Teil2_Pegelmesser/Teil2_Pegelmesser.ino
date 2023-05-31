// Adafruit_NeoPixel Bibliothek installieren
// Board: Arduino Nano (Old Bootloader)

#include <Adafruit_NeoPixel.h>
#include "LED.h"

#define LED_PIN     3
#define NUMPIXELS   320
#define BRIGHTNESS  10 // (0..255)

int alterPegel;
unsigned long startZeit;

Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

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

  int pegel = analogRead(A1);
  //Serial.println(pegel);

  if (pegel > alterPegel) {
    alterPegel = pegel;
    startZeit = millis();
  }

  pixels.clear();

  if (alterPegel < 300) {

    level_0();

  } else if (alterPegel < 320) {

    level_1();

  } else if (alterPegel < 340) {

    level_2();

  } else if (alterPegel < 360) {

    level_3();

  } else if (alterPegel < 390) {

    level_4();

  } else if (alterPegel < 420) {

    level_5();

  } else if (alterPegel < 440) {

    level_6();

  } else {

    level_7();
  }

  pixels.show();

  if (millis() > startZeit + 50) {
    alterPegel = 0;
  }
}

void level_0() {

  // gruen
  uint32_t color = pixels.Color(0, 255, 0);

  reihe('V', 8, color, pixels);
  reihe('R', 8, color, pixels);
  reihe('H', 8, color, pixels);
  reihe('L', 8, color, pixels);
}

void level_1() {

  level_0();

  // gruen
  uint32_t color = pixels.Color(0, 255, 0);

  reihe('V', 7, color, pixels);
  reihe('R', 7, color, pixels);
  reihe('H', 7, color, pixels);
  reihe('L', 7, color, pixels);
}

void level_2() {

  level_1();

  // gruen
  uint32_t color = pixels.Color(0, 255, 0);

  reihe('V', 6, color, pixels);
  reihe('R', 6, color, pixels);
  reihe('H', 6, color, pixels);
  reihe('L', 6, color, pixels);
}

void level_3() {

  level_2();

  // gelb
  uint32_t color = pixels.Color(150, 150, 0);

  reihe('V', 5, color, pixels);
  reihe('R', 5, color, pixels);
  reihe('H', 5, color, pixels);
  reihe('L', 5, color, pixels);
}

void level_4() {

  level_3();

  // gelb
  uint32_t color = pixels.Color(150, 150, 0);

  reihe('V', 4, color, pixels);
  reihe('R', 4, color, pixels);
  reihe('H', 4, color, pixels);
  reihe('L', 4, color, pixels);
}

void level_5() {

  level_4();

  // orange
  uint32_t color = pixels.Color(255, 80, 0);

  reihe('V', 3, color, pixels);
  reihe('R', 3, color, pixels);
  reihe('H', 3, color, pixels);
  reihe('L', 3, color, pixels);
}

void level_6() {

  level_5();

  // orange
  uint32_t color = pixels.Color(255, 80, 0);

  reihe('V', 2, color, pixels);
  reihe('R', 2, color, pixels);
  reihe('H', 2, color, pixels);
  reihe('L', 2, color, pixels);
}

void level_7() {

  level_6();

  // rot
  uint32_t color = pixels.Color(255, 0, 0);

  reihe('V', 1, color, pixels);
  reihe('R', 1, color, pixels);
  reihe('H', 1, color, pixels);
  reihe('L', 1, color, pixels);
}
