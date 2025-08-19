
/*
  Keyestudio 4WD Mecanum Robot for Pico
  lesson 2.1
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

  rgb.setPixelColor(0, 255, 0, 0);//The first LED is red
  rgb.setPixelColor(1, 0, 255, 0);//The second LED is green
  rgb.setPixelColor(2, 0, 0, 255);//The third LED is blue
  rgb.setPixelColor(3, 255, 255, 255);//The fourth LED is white
  rgb.show();    //Refresh display
}

void loop() {
}
