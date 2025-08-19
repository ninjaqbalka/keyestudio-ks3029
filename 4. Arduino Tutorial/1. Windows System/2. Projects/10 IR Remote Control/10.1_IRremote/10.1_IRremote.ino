
/*
  Keyestudio 4WD Mecanum Robot for Pico
  lesson 10.1
  IRremote
  http://www.keyestudio.com
*/

#include "ir.h"

IR IRreceive(6);//IR receiver is connected to GP6

void setup(){
}

void loop() {
  int key = IRreceive.getKey();
  if (key != -1) {
    Serial.println(key);
  }
}
