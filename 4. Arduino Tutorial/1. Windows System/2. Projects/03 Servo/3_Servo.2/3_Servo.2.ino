
/*
  Keyestudio 4WD Mecanum Robot for Pico
  lesson 3.2
  Servo
  http://www.keyestudio.com
*/
#include <Servo.h>
Servo myservo;    //Define an instance of a servo

void setup() {
  myservo.attach(2);    //The pin of the servo is connected to GPIO2
}

void loop() {
  for (uint8_t angle = 0; angle < 180; angle++)//From 0 to 180 degrees
  {
    myservo.write(angle); //Rotate to angle 
delay(15);  //Wait for a while 
  }
  for (uint8_t angle = 180; angle > 0; angle--)//From 0 to 180 degrees
  {
    myservo.write(angle); //Rotate to angle
    delay(15);
  }
}
