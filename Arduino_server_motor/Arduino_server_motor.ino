/* Servo motor with Arduino example code. Position and sweep. More info: https://www.makerguides.com/ */

// Include the servo library:
#include "Servo.h"

// Create a new servo object:
Servo myservo;

// Define the servo pin:
#define servoPin 9

void setup() {
  // Attach the Servo variable to a pin:
  myservo.attach(servoPin);
}

void loop() {
  myservo.write(30);
  delay(1000);
  myservo.write(70);
  delay(1000);
/*  // Tell the servo to go to a particular angle:
  myservo.write(90);
  delay(1000);
  myservo.write(180);
  delay(1000);
  myservo.write(0);
  delay(1000);

  // Sweep from 0 to 180 degrees:
  for (int angle = 0; angle <= 180; angle += 1) {
    myservo.write(angle);
    delay(15);
  }

  // And back from 180 to 0 degrees:
  for (int angle = 180; angle >= 0; angle -= 1) {
    myservo.write(angle);
    delay(15);
  }
  delay(1000);
*/
}