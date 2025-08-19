
/*
  Keyestudio 4WD Mecanum Robot for Pico
  lesson 5
  Line Tracking Sensor
  http://www.keyestudio.com
*/
/*******Define the pin of Line Tracking Sensor**********/
#define SensorLeft    16   //input pin of left sensor
#define SensorMiddle  17   //input pin of middle sensor
#define SensorRight   18   //input pin of right sensor


void setup() {
  /****All Line Tracking Sensor interface are set to input mode***/
  pinMode(SensorLeft, INPUT);
  pinMode(SensorMiddle, INPUT);
  pinMode(SensorRight, INPUT);

}

void loop() {
  uint8_t SL = digitalRead(SensorLeft); //Read the value of the left line tracking sensor
  uint8_t SM = digitalRead(SensorMiddle); //Read the value of the intermediate line tracking sensor
  uint8_t SR = digitalRead(SensorRight); //Read the value of the right line tracking sensor

  Serial.print("Left:");  //Serial port prints the information  
  Serial.print(SL);
  Serial.print("  Middle:");
  Serial.print(SM);
  Serial.print("  Right:");
  Serial.print(SR);
  Serial.println(); //Line feed
  delay(100);
}
