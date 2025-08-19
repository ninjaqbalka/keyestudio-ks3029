
/*
  Keyestudio 4WD Mecanum Robot for Pico
  lesson 7
  Ultrasonic sensor
  http://www.keyestudio.com
*/
/*******Ultrasonic Sensor interface*****/
#define EchoPin  4  //ECHO to GPIO4
#define TrigPin  3  //TRIG to GPIO3

void setup() {
  pinMode(EchoPin, INPUT);    //The ECHO pin is set to input mode
  pinMode(TrigPin, OUTPUT);   //The TRIG pin is set to output mode
}

void loop() {
  float distance = get_distance();  //Get the distance and save in the distance variable 
  Serial.print("ditance:");
  Serial.print(distance);
  Serial.println("cm");
  delay(100);
}

float get_distance(void) {    //Ultrasonic detects the distance
  float dis;
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH); //Give the TRIG a high level of at least 10 µ s to trigger
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  dis = pulseIn(EchoPin, HIGH) /58.2;  //Work out the distance
  delay(50);
  return dis;
}
