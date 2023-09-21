// Motor A is the MOTOR ON THE LEFT of the robot
#define A_speed  A0   // ANALOG PIN!
#define A_FORWARD  8
#define A_Backward  7

// Motor B is the MOTOR ON THE Right of the robot
#define B_speed  A2   // ANALOG PIN!
#define B_FORWARD  6
#define B_Backward  5

void setup() {
  pinMode(A_speed, OUTPUT);
  pinMode(A_FORWARD, OUTPUT);
  pinMode(A_Backward, OUTPUT);
  
  pinMode(B_speed, OUTPUT);
  pinMode(B_FORWARD, OUTPUT);
  pinMode(B_Backward, OUTPUT);
}

void loop() {
  moveForward(255);    //MAX SPEED OF THE MOTOR "255"
  delay(1000);
  stopMotors();

  moveBackward(255);
  delay(1000);
  stopMotors();

  turnLeft(120);
  delay(1000);
  stopMotors();

  turnRight(10);
  delay(1000);
  stopMotors();
}

void moveForward(int SPEED) {
  digitalWrite(A_FORWARD, HIGH);
  digitalWrite(A_Backward, LOW);
  digitalWrite(B_FORWARD, HIGH);
  digitalWrite(B_Backward, LOW);
  analogWrite(A_speed, SPEED);
  analogWrite(B_speed, SPEED);
}

void moveBackward(int SPEED) {
  digitalWrite(A_FORWARD, LOW);
  digitalWrite(A_Backward, HIGH);
  digitalWrite(B_FORWARD, LOW);
  digitalWrite(B_Backward, HIGH);
  analogWrite(A_speed, SPEED);
  analogWrite(B_speed, SPEED);
}

void stopMotors() {
  digitalWrite(A_FORWARD, LOW);
  digitalWrite(A_Backward, LOW);
  digitalWrite(B_FORWARD, LOW);
  digitalWrite(B_Backward, LOW);
  analogWrite(A_speed, 0);
  analogWrite(B_speed, 0);
}

void turnLeft(int SPEED) {
  digitalWrite(A_FORWARD, LOW);
  digitalWrite(A_Backward, HIGH);
  digitalWrite(B_FORWARD, HIGH);
  digitalWrite(B_FORWARD, LOW);
  analogWrite(A_speed, SPEED);
  analogWrite(B_speed, SPEED);
}

void turnRight(int SPEED) {
  digitalWrite(A_FORWARD, HIGH);
  digitalWrite(A_Backward, LOW);
  digitalWrite(B_FORWARD, LOW);
  digitalWrite(B_Backward, HIGH);
  analogWrite(A_speed, SPEED);
  analogWrite(B_speed, SPEED);
}