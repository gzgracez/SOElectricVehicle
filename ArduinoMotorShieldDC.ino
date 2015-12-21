// Motorshield Input & Output: https://www.arduino.cc/en/Main/ArduinoMotorShieldR3
const int 
PWM_A   = 3,
DIR_A   = 12,
BRAKE_A = 9,
SNS_A   = A0,

PWM_B   = 11,
DIR_B   = 13,
BRAKE_B = 8,
SNS_B   = A1;

int maxSpeed = 200;
int currentSpeed = 0;


void setup() {
  pinMode(BRAKE_A, OUTPUT);
  pinMode(DIR_A, OUTPUT);
  
  pinMode(BRAKE_A, OUTPUT);
  pinMode(DIR_A, OUTPUT);

  Serial.begin(9600);

  start();
  go(5000);
  slow();
  pause();
}

void loop() {
//  digitalWrite(BRAKE_A, LOW); // brake: LOW = disable motor brake
//  digitalWrite(DIR_A, HIGH); // direction: HIGH = forward
//  digitalWrite(BRAKE_B, LOW);
//  digitalWrite(DIR_B, HIGH);
//
//  analogWrite(PWM_A, 255); // motor speed
//  analogWrite(PWM_B, 255); 
//
//  delay(5000);
////  Serial.print("current consumption at full speed: ");
////  Serial.println(analogRead(SNS_A));
//
////  Serial.println("Start braking\n");
//  // raising the brake pin the motor will stop faster than the stop by inertia
//  digitalWrite(BRAKE_A, HIGH); 
//  digitalWrite(BRAKE_B, HIGH);
//  delay(5000);
//  while(1);
}

// go forward, gradually increase speed
void start () {
  digitalWrite(BRAKE_A, LOW); // brake: LOW = disable motor brake
  digitalWrite(DIR_A, HIGH); // direction: HIGH = forward
  digitalWrite(BRAKE_B, LOW);
  digitalWrite(DIR_B, HIGH);
  for (int i = 0; i <= maxSpeed; i++) {
    currentSpeed = i;
    goSpeed(currentSpeed);
    Serial.println(currentSpeed);
  }
}

void go (int time) { 
  goSpeed(currentSpeed);
  Serial.println(currentSpeed); 
  delay(time);
}

void slow () {
  while (currentSpeed>0) {
    currentSpeed--;
    Serial.println(currentSpeed);
    goSpeed(currentSpeed);
  }
}

void goSpeed (int moveSpeed) {
  analogWrite(PWM_A, moveSpeed);
  analogWrite(PWM_B, moveSpeed);
}

// brake
void pause() {
  digitalWrite(BRAKE_A, HIGH); 
  digitalWrite(BRAKE_B, HIGH);
}
