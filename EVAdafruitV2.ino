#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

 Adafruit_MotorShield AFMS = Adafruit_MotorShield();
 
 Adafruit_DCMotor *myMotor = AFMS.getMotor(1);
 Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);
 int maxSpeed = 200;
 int currentSpeed = 0;
 
void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");
  AFMS.begin();
  myMotor->setSpeed(currentSpeed);
  myMotor2->setSpeed(currentSpeed);
  go(5000);
  pause();
  start();
  go(5000);
  slow();
}
 
void loop() {
}

void goSpeed(int moveSpeed) {
  myMotor->setSpeed(moveSpeed);
  myMotor2->setSpeed(moveSpeed);
  myMotor->run(FORWARD);
  myMotor2->run(FORWARD);
//  delay(time);
}

void start() {
  for (int i = 0; i<=maxSpeed; i++){
    currentSpeed = i;
    goSpeed(currentSpeed);
  }
}

void go(int time) {
  goSpeed(currentSpeed);
  delay(time);
}

void slow(){ 
  while (currentSpeed>-1) {
    currentSpeed--;
    goSpeed(currentSpeed);
  }
  goSpeed(0);
}
  
void pause(){
  myMotor->setSpeed(0);
  myMotor2->setSpeed(0);
  Serial.print("tick");
  myMotor->run(FORWARD);
  myMotor2->run(FORWARD);
  delay(1000);
}
