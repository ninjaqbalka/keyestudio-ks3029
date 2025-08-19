
/*
  Keyestudio 4WD Mecanum Robot for Pico
  lesson 10.2
  IRremote Control LED
  http://www.keyestudio.com
*/
#include "MecanumCar_v2.h"
mecanumCar mecanumCar(20, 21);  //sda-->20,scl-->21
#include "ir.h"

IR IRreceive(6);//IR receiver is connected to GP6
bool flag = true;

void setup(){
  mecanumCar.Init();//Initialize the motors and the seven-color LEDs
}

void loop() {
  int key = IRreceive.getKey();
  if (key == 64 && flag == true) {
    mecanumCar.right_led(1);
    mecanumCar.left_led(1);
    flag = false;
  }else if (key == 64 && flag == false) {
    mecanumCar.right_led(0);
    mecanumCar.left_led(0);
    flag = true;
  }
}
