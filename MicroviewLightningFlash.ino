
#include <Adafruit_GFX.h>
#include <Adafruit_NeoPixel.h>

#define PIN 6 
#define NUMPIXELS 40
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
  
int delayVal; //Delay between two lightning strikes
int lightningFlash; //Delay between the flashes
int flashes; //number of flashes
void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  flashes = random(1,4);
  for(int j=0; j<flashes; j++) {
    flash();
    flashOff();
  }
  delayVal = random(1000, 5000);
  delay(delayVal);
}

void flash() {
  
  for(int i=0; i < NUMPIXELS; i++) {
    strip.setPixelColor(i, strip.Color(177, 177, 177));
    strip.show();
  }
  lightningFlash = random(50, 200);
  delay(lightningFlash);
}

void flashOff() {
  for(int i=0; i < NUMPIXELS; i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 0));
    strip.show();
  }
  lightningFlash = random(50,200);
  delay(lightningFlash);
}

