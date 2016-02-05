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

int maxSpeed = 255;
int currentSpeed = 0;

void setup() {
  pinMode(BRAKE_A, OUTPUT);
  pinMode(DIR_A, OUTPUT);

  Serial.begin(9600);

  start();
  go(20000); // 200000 milliseconds
  slow();
  pause();
}

void loop() {
}

// go forward, gradually increase speed
void start () {
  digitalWrite(BRAKE_A, LOW); // brake: LOW = disable motor brake
  digitalWrite(DIR_A, LOW); // direction: HIGH = forward
  for (int i = 0; i <= maxSpeed; i++) {
    currentSpeed = i;
    goSpeed(currentSpeed);
  }
}

void go (int time) { 
  goSpeed(currentSpeed);
  delay(time);
}

void slow () {
  while (currentSpeed>0) {
    currentSpeed--;
    goSpeed(currentSpeed);
  }
}

void goSpeed (int moveSpeed) {
  analogWrite(PWM_A, moveSpeed);
}

// brake
void pause() {
  digitalWrite(BRAKE_A, HIGH);
}
