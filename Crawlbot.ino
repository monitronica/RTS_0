/*
 * The code first defines the pins of the servo motors. 
 * Then it sets the signal pin to give out the pulses. 
 * The delay can be modified to set the speed of crawling.  
 */
#include <Servo.h>

int delayServo = 400;

Servo FrontServo;
Servo BackServo;

void setup() {

FrontServo.attach(9);
BackServo.attach(10); 

}

void loop() {

  FrontServo.write(120);
  BackServo.write(40);
  delay(delayServo);
  
  FrontServo.write(70);
  BackServo.write(140);
  delay(delayServo);

}
