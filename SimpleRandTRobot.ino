/*
 * The code first defines the pins of the servo motors and 
 * potentiometers. It reads the value of the potentiometer, 
 * scales it to use it with the servos and sets their 
 * position according to the scaled values.
 */
#include <Servo.h>

Servo RotateServo; 
Servo TiltServo; 

int RotatePot = A2;  
int valueR;   

int TiltPot = A0;  
int valueT;   

void setup()
{
  RotateServo.attach(9); 
  TiltServo.attach(10); 
}

void loop() 
{ 
  valueR = analogRead(RotatePot);            
  valueR = map(valueR, 0, 1023, 0, 180);     
  valueT = analogRead(TiltPot);            
  valueT = map(valueT, 0, 1023, 0, 180);
  RotateServo.write(valueR);                  
  TiltServo.write(valueT);
  delay(15);                           
} 

