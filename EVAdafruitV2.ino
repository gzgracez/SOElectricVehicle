#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

 Adafruit_MotorShield AFMS = Adafruit_MotorShield();
 
 Adafruit_DCMotor *myMotor = AFMS.getMotor(1);
 Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);
 
void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");
  AFMS.begin();
  myMotor->setSpeed(255);
  myMotor2->setSpeed(255);
  go(5000);
  pause();
}
 
void loop() {
}

void go() {
  myMotor->setSpeed(255);
  myMotor2->setSpeed(255);
  Serial.print("tick");
  myMotor->run(FORWARD);
  myMotor2->run(FORWARD);
  delay(1000);
}

void go(int time) {
  myMotor->setSpeed(255);
  myMotor2->setSpeed(255);
  Serial.print("tick");
  myMotor->run(FORWARD);
  myMotor2->run(FORWARD);
  delay(time);
}

void pause(){
  myMotor->setSpeed(0);
  myMotor2->setSpeed(0);
  Serial.print("tick");
  myMotor->run(FORWARD);
  myMotor2->run(FORWARD);
  delay(1000);
}
  
