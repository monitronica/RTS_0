/*
 * The code first defines the pins of the servo motors 
 * button and potentiometer. Reads the value of the button 
 * and pot, scales it to use it with the servos and 
 * sets their position according to the scaled values. 
 * Record and playback is controlled by button press.
 */
#include <Servo.h>
#include <EEPROM.h> //to store recorded valueues

float motion = 2000; //MUST be less than EEPROM.length()
float delayTime = 5; 

int StatusLed = 13;

Servo ServoLimb; 
Servo ServoLimb2; 

bool record_action = false;

void setup() {

 pinMode(StatusLed, OUTPUT); // we need status led
 pinMode(2, OUTPUT);  // servo motor pin
 ServoLimb.attach(9);
 ServoLimb2.attach(10);
 digitalWrite(2, HIGH);
 pinMode(StatusLed, OUTPUT); // status led
//Serial.println(EEPROM.length());

}
void loop() {
 if (record_action == true) {//record
   for (int i = 1; i <= motion; i++) {
     digitalWrite(StatusLed, HIGH); //light status led
     int value = map(analogRead(A0), 0, 1023, 0, 180);
     int value2 = map(analogRead(A2), 0, 1023, 0, 180);
     EEPROM.write(i, value);
     EEPROM.write(i, value2);
     //Serial.println(EEPROM.read(i));
     ServoLimb.write(value);
     ServoLimb2.write(value2);
     delay(delayTime);
   }
   digitalWrite(StatusLed, LOW); //turn off status led
   delay(1000);
   record_action = false;
 }
 else {
   for (int i = 1; i <= motion; i++) {
     if (digitalRead(2) == 0) {
       record_action = true;
       break;
     }
     int readvalue = EEPROM.read(i);
     int readvalue2 = EEPROM.read(i);
     ServoLimb.write(readvalue);
     ServoLimb2.write(readvalue2);
     //Serial.println(readvalue);
     delay(delayTime);
   }
   digitalWrite(StatusLed, HIGH); 
   delay(100);
   digitalWrite(StatusLed, LOW);
 }
}
