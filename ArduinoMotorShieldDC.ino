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


void setup() {
  pinMode(BRAKE_A, OUTPUT);
  pinMode(DIR_A, OUTPUT);
  
  pinMode(BRAKE_A, OUTPUT);
  pinMode(DIR_A, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  digitalWrite(BRAKE_A, LOW); // brake: LOW = disable motor brake
  digitalWrite(DIR_A, HIGH); // direction: HIGH = forward
  digitalWrite(BRAKE_B, LOW);
  digitalWrite(DIR_B, HIGH);

  analogWrite(PWM_A, 255); // motor speed
  analogWrite(PWM_B, 255); 

  delay(5000);
//  Serial.print("current consumption at full speed: ");
//  Serial.println(analogRead(SNS_A));

//  Serial.println("Start braking\n");
  // raising the brake pin the motor will stop faster than the stop by inertia
  digitalWrite(BRAKE_A, HIGH); 
  digitalWrite(BRAKE_B, HIGH);
  delay(5000);
  while(1);
}
