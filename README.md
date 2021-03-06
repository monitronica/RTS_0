# RTS_2
***
## For circuit building instructions go to wiki
***
## Software
* Download the Arduino IDE 1.6.5: 
* https://www.arduino.cc/en/Main/OldSoftwareReleases#1.5.x
* Open Arduino IDE
* You need the servo library, go to > Sketch > Include Library > click Manage Libraries...
* in Library Manager search for Servo Build-In by Michael Margolis, Version 1.0.3 and click Install
* more info about library:
* https://www.arduino.cc/en/Reference/Servo&quot;
* Connect the Arduino board into the computer using the USB type A to B cable. 

![slika](https://user-images.githubusercontent.com/78903881/107699543-866bee00-6cb6-11eb-9bd0-829d3ff183cd.png)

* Once connected, open the Arduino IDE and go to Tools > Board: > then select the Arduino/Genuino Uno.

![slika](https://user-images.githubusercontent.com/78903881/107699922-0b570780-6cb7-11eb-94ec-9573d655d742.png)

* Open the sketch, go to File > Open > then select the sketch
* Click the Verify button to save and compile the sketch. This will also check if there are any errors in your program. Click the Upload button to install the program into the arduino uno board.

![slika](https://user-images.githubusercontent.com/78903881/107700395-b8ca1b00-6cb7-11eb-8b14-5799173de265.png)

## RTS_2_Testing
-----------------------------------------------------------------------------
## Crawling robot 
 * After the body of the robot is completed, test your arduino uno by powering it and let the servo motors move. Put the robot on the floor to test crawling.
-----------------------------------------------------------------------------
## Playback Robot  
* To use this circuit, you simply press the button to begin recording and input the desired information through a potentiometer. The board will repeat your recorded actions endlessly. Press the button again to record new actions. 
-----------------------------------------------------------------------------
## waka_waka
* Test your Arduino set-up by hovering your hand for about 8-13 cm away from the ultrasonic sensor. This should trigger it and let the servo motors move. Now, remove your hand away from the sensor, this should retract the servo motor back to its original angle.
-----------------------------------------------------------------------------

