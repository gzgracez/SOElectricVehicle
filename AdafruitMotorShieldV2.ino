#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

 Adafruit_MotorShield AFMS = Adafruit_MotorShield();
 
 Adafruit_DCMotor *myMotor = AFMS.getMotor(1);
 Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);
 int maxSpeed = 150;
 int currentSpeed = 0;
 
void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");
  AFMS.begin();
  start();
  go(5000);
  slow();
  pause();
}
 
void loop() {
}

void start() {
  for (int i = 0; i<=maxSpeed; i++){
    currentSpeed = i;
    goSpeedBackward(currentSpeed);
  }
}

void go(int time) {
  goSpeedBackward(currentSpeed);
  delay(time);
}

void slow(){ 
  while (currentSpeed>0) {
    currentSpeed--;
    goSpeedBackward(currentSpeed);
  }
}
  
void pause(){
  goSpeedBackward(0);
  delay(1000);
}

void goSpeedForward(int moveSpeed) {
  myMotor->setSpeed(moveSpeed);
  myMotor2->setSpeed(moveSpeed);
  myMotor->run(FORWARD);
  myMotor2->run(FORWARD);
}

void goSpeedBackward(int moveSpeed) {
  myMotor->setSpeed(moveSpeed);
  myMotor2->setSpeed(moveSpeed);
  myMotor->run(BACKWARD);
  myMotor2->run(BACKWARD);
}
