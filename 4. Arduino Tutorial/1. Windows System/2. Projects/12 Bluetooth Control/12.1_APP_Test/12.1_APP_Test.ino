
/*
  Keyestudio 4WD Mecanum Robot for Pico
  lesson 12.1
  APP Test
  http://www.keyestudio.com
*/

char ble_val;
void setup() {
  Serial1.begin(9600);  //Set the baud rate to 9600
}

void loop() {
  if (Serial1.available())//If the receiving area is not empty
  {
    char ble_val = Serial1.read();//Read the data of the bluetooth
    Serial.println(ble_val);//The serial monitor prints the read data
  }
}
