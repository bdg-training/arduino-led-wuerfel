
void zahl0k(uint32_t color, int offset, Adafruit_NeoPixel & pixels) {
  
  ledOffsetOben(LED_V_2x1, offset, color, pixels);
  ledOffsetOben(LED_V_3x1, offset, color, pixels);
  ledOffsetOben(LED_V_4x1, offset, color, pixels);

  ledOffsetOben(LED_V_1x2, offset, color, pixels);
  ledOffsetOben(LED_V_5x2, offset, color, pixels);
  ledOffsetOben(LED_V_1x3, offset, color, pixels);
  ledOffsetOben(LED_V_5x3, offset, color, pixels);

  ledOffsetOben(LED_V_2x4, offset, color, pixels);
  ledOffsetOben(LED_V_3x4, offset, color, pixels);
  ledOffsetOben(LED_V_4x4, offset, color, pixels);
}


void zahl1k(uint32_t color, int offset, Adafruit_NeoPixel & pixels) {

  ledOffsetOben(LED_V_3x1, offset, color, pixels);

  ledOffsetOben(LED_V_2x2, offset, color, pixels);
  ledOffsetOben(LED_V_5x2, offset, color, pixels);

  ledOffsetOben(LED_V_1x3, offset, color, pixels);
  ledOffsetOben(LED_V_2x3, offset, color, pixels);
  ledOffsetOben(LED_V_3x3, offset, color, pixels);
  ledOffsetOben(LED_V_4x3, offset, color, pixels);
  ledOffsetOben(LED_V_5x3, offset, color, pixels);

  ledOffsetOben(LED_V_5x4, offset, color, pixels);
}
