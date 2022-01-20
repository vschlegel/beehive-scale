#include "Arduino.h"
#include "CubeCell_NeoPixel.h"

CubeCell_NeoPixel pixels(1, RGB, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(Vext,OUTPUT);
  digitalWrite(Vext,LOW);

  pixels.begin();
  pixels.clear();
}

void loop() {
    pixels.setPixelColor(0, pixels.Color(80, 80, 80));
    pixels.show();
    delay(20);
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.show();
    delay(2000);
}
