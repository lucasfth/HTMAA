/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

#define LED 13
#define BTNOUT 11
#define BTNIN 12
bool blinking = false;
bool lastButtonState = HIGH; 
unsigned long previousMillis = 0;
const int blinkInterval = 500; 

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BTNOUT, OUTPUT);
  pinMode(BTNIN, INPUT);
  digitalWrite(BTNOUT, HIGH); 
}

void loop() {
  bool buttonState = digitalRead(BTNIN); 

  if (buttonState == HIGH && lastButtonState == LOW) {  
    blinking = !blinking;
    delay(50); 
  }
  
  lastButtonState = buttonState; 

  if (blinking) {
    unsigned long currentMillis = millis();  // Get current time
    if (currentMillis - previousMillis >= blinkInterval) {  
      previousMillis = currentMillis;  // Reset timer
      digitalWrite(LED, !digitalRead(LED));
    }
  } else {
    digitalWrite(LED, LOW);  
  }
}
