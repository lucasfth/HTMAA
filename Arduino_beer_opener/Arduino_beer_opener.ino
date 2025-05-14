// Beer opener

// Include the servo library:
#include "Servo.h"

// Create a new servo object:
Servo myservo;

#define RPMSensor 2
int pulseCount = 0;
unsigned long startTime;
int pulseTimer = 5;
int currentRPM = 0;


#define servoPin 9
#define CupholderButton 8
#define MotorActivatePin 7

void setup() {
  Serial.begin(9600); // open the serial port at 9600 bps:
  myservo.attach(servoPin);
  pinMode(RPMSensor,INPUT);
  //pinMode(RPMSensor,INPUT_PULLUP);
  //attachInterrupt(digitalPinToInterrupt(RPMSensor), countPulse, RISING); // or FALLING, depending on your sensor
  pinMode(CupholderButton,INPUT);
  pinMode(MotorActivatePin,OUTPUT);
}

void loop() {
  while(!getCupholderButtonStatus()){
    delay(1000);
    Serial.println("No beer detected");
  }
  if(getCupholderButtonStatus()){
    Serial.println("Beer detected, starting motor");
    digitalWrite(MotorActivatePin,HIGH);
    int rpm = getRPMSensorStatus();
    Serial.println("RPM is: " + String(rpm));
    while(rpm<500){
      rpm = getRPMSensorStatus();
      Serial.println("RPM is: " + String(rpm));    
    }
    Serial.println("RPM reached 500, pulling beer");
    pullBeerToWheel();
    delay(2000);
    Serial.println("Resetting");
    reset();
  }
}

int getRPMSensorStatus() {
  int pulseCount = 0;
  int previousState = LOW;
  int currentState;

  startTime = millis();

  while (millis() - startTime < 5000) {
    delay(1);
    currentState = digitalRead(RPMSensor);

    // Detect rising edge
    if (currentState == HIGH && previousState == LOW) {
      pulseCount++;
    }

    previousState = currentState;
  }

  // Calculate RPM
  currentRPM = (pulseCount * 60) / 5;
  return currentRPM;
}

void countPulse() {
  pulseCount++;
}

int getCupholderButtonStatus(){
  return digitalRead(CupholderButton);
}

void pullBeerToWheel(){
  myservo.write(30);
}

void reset(){
  //Beer
  myservo.write(70);
  while(getCupholderButtonStatus()){
    //Beer is still there
    Serial.println("Beer still in cupholder");
    delay(1000);
  }
}