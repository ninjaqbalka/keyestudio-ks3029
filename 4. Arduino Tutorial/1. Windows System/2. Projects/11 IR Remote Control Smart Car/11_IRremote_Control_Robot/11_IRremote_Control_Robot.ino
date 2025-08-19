
/*
  Keyestudio 4WD Mecanum Robot for Pico
  lesson 11
  IRremote Control Robot
  http://www.keyestudio.com
*/
#include "MecanumCar_v2.h"
mecanumCar mecanumCar(20, 21);  //sda-->20,scl-->21

/****Introduce IR Remote Control header file***/
#include "ir.h"

IR IRreceive(6);//IR receiver is connected to GP6

void setup()
{
  mecanumCar.Init(); //Initialize the seven-color LED and motor drive
}

void loop() {
  int key = IRreceive.getKey();
  if (key != -1) {
    Serial.println(key);
    switch (key)
    {
      case 64: mecanumCar.Stop();       break;  //Stop
      case 70: mecanumCar.Advance();    break;  //Advance
      case 21: mecanumCar.Back();       break;  //Move back
      case 68: mecanumCar.Turn_Left();  break;  //Turn left
      case 67: mecanumCar.Turn_Right(); break;  //Turn right
    }
  }
}
