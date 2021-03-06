#include <Servo.h> 
 
Servo myservo;
Servo myservo2;// create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 90;    // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(9); 
  myservo2.attach(10);// attaches the servo on pin 9 to the servo object 
} 
 
void loop() 
{ 
                                   // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos'                      // waits 15ms for the servo to reach the position 
    myservo2.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                    // waits 15ms for the servo to reach the position 
  } 

