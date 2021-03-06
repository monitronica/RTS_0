/* 

*/
#include <Servo.h> 
 
Servo frontServo;  
Servo rearServo;  
/* Servo motors - global variables */
int centerPos = 90; 
int frontRightUp = 72;
int frontLeftUp = 108;
int backRightForward = 75;
int backLeftForward = 105;
int walkSpeed = 150; // How long to wait between steps in milliseconds
int centerTurnPos = 96;
int frontTurnRightUp = 81;
int frontTurnLeftUp = 99;
int backTurnRightForward = 81;
int backTurnLeftForward = 111;

/*global variables */
const int trigPin = 6;
const int echoPin = 7;
long int duration;
long distanceFront=0; //cm
int startAvoidanceDistance=20; 

int danger = 0; // no obstacle
int frontRight = 0;  // front right leg in low position
int slowMotion = 50;  // delay amount for moving forwards

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}

long distanceCm(){
  pinMode(trigPin, OUTPUT); 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT); 
  duration = pulseIn(echoPin, HIGH);

  return microsecondsToCentimeters(duration);
}

void moveForward()
{
  int frontPos = frontServo.read();  //checks frontServo position
  int rearPos = rearServo.read();  //checks rearServo position
  if (frontRight==0) {  // moves front right leg up
    for (; frontPos >= frontRightUp; frontPos--) {
      frontServo.write(frontPos);
      delay(slowMotion);
    }
    for (; rearPos <= backLeftForward; rearPos++) {
      rearServo.write(rearPos);
      delay(slowMotion);
    }
    frontRight = 1;
  } else {  // moves front left leg up
    for (; frontPos <= frontLeftUp; frontPos++) {
      frontServo.write(frontPos);
      delay(slowMotion);
    }
    for (; rearPos >= backRightForward; rearPos--) {
      rearServo.write(rearPos);
      delay(slowMotion);
    }
    frontRight = 0;
  }
}

void moveBackRight()
{
  frontServo.write(frontRightUp);
  rearServo.write(backRightForward-6);
  delay(125);
  frontServo.write(centerPos);
  rearServo.write(centerPos-6);
  delay(65);
  frontServo.write(frontLeftUp+9);
  rearServo.write(backLeftForward-6);
  delay(125);
  
  frontServo.write(centerPos);
  rearServo.write(centerPos);
  delay(65);
}

void moveTurnLeft()
{
  frontServo.write(frontTurnRightUp);
  rearServo.write(centerTurnPos);
  delay(65);
  rearServo.write(backTurnLeftForward);
  delay(125);
  frontServo.write(centerTurnPos);
  delay(65);
  frontServo.write(frontTurnLeftUp);
  rearServo.write(centerTurnPos);
  delay(65);
  rearServo.write(backTurnRightForward);
  delay(125);
  frontServo.write(centerTurnPos);
  delay(65);
}

void setup()
{
  frontServo.attach(9);
  rearServo.attach(10);
  pinMode(trigPin, OUTPUT);
}  

void loop()
{
  distanceFront=distanceCm();
  if (distanceFront > 1){ // Filters out any stray 0.00 error readings
    if (distanceFront<startAvoidanceDistance) {
      if (danger==0) {  // stops at first obstacle detection
        delay(1000);
        danger = 1;
      }
      for(int i=0; i<=8; i++) {
        moveBackRight();
        delay(walkSpeed);
      }
      for(int i=0; i<=10; i++) {
        distanceFront=distanceCm(); 
          if (distanceFront > 1){ // Filters out any stray 0.00 error readings
            if (distanceFront<startAvoidanceDistance) {
              moveBackRight();
              delay(walkSpeed);
          } else {
            danger = 0;
            moveTurnLeft();
      }
      }
      }
    } else {
      moveForward(); 
    } 
}
}

