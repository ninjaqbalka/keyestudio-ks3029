
/*
  Keyestudio 4WD Mecanum Robot for Pico
  lesson 2.2
  WS2812
  http://www.keyestudio.com
*/
#include "rgb.h"
//Create a class called rgb to control rgb, there are four LEDs, and pins are connected to GP7 
RGB rgb(7, 4);  //rgb(pin, num);  num = 0-100

void setup() {
  rgb.setBrightness(100);  //rgb.setBrightness(0-255);
  delay(10);
  rgb.clear();  //Turn off all leds
  delay(10);

}

void loop() {
  uint8_t r = random(0, 255);
  uint8_t g = random(0, 255);
  uint8_t b = random(0, 255);
  for (uint8_t i = 0; i < 4; i++)
  {
    rgb.setPixelColor(i, r, g, b);//The color of the i +1 LED is random(r,g,b)
    rgb.show();    //Refresh display
    delay(100); //Wait for a while
  }
}
