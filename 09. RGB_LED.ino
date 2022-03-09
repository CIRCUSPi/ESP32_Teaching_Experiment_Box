#include <Adafruit_NeoPixel.h>

#define PIN        32
#define NUMPIXELS   4

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  pixels.begin();
}

void loop() {
  pixels.clear();
  Serial.println("red");
  for(int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(150, 0, 0));
  }
  pixels.show();
  delay(1000);

  pixels.clear();
  Serial.println("green");
  for(int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));
  }
  pixels.show();
  delay(1000);

  pixels.clear();
  Serial.println("blue");
  for(int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 150));
  }
  pixels.show();
  delay(1000);
}
