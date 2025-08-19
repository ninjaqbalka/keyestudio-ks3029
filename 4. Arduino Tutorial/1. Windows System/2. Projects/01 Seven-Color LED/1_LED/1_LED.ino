
/*
  Keyestudio 4WD Mecanum Robot for Pico
  lesson 1
  Color LED
  http://www.keyestudio.com
*/
#include "MecanumCar_v2.h"
mecanumCar mecanumCar(20, 21);  //sda-->20,scl-->21

void setup() {
  mecanumCar.Init();//Configure seven-color LED pin mode for output

}

void loop() {
  mecanumCar.right_led(1);//Turn on the right seven-color LED 
  mecanumCar.left_led(1); //Turn on the left seven-color LED 
  delay(3000);            //Delay in 3000 ms
  mecanumCar.right_led(0); //Turn off the right seven-color LED
  mecanumCar.left_led(0);  //Turn off the left seven-color LED
  delay(1000);             //Delay in 1000 ms
}
