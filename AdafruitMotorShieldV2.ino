#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
 
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);
int maxSpeed = 100;
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
    goSpeedForward(currentSpeed);
  }
}

void go(int time) {
  goSpeedForward(currentSpeed);
  delay(time);
}

void slow(){ 
  while (currentSpeed>0) {
    currentSpeed--;
    goSpeedForward(currentSpeed);
  }
}
  
void pause(){
  goSpeedForward(0);
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
