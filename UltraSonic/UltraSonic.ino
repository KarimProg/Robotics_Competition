// Test Here
// https://wokwi.com/projects/376388775617985537

#define FrontTrig     2
#define BackTrig      6
#define RightTrig     4
#define LeftTrig      8

#define FrontEcho     3
#define BackEcho      7
#define RightEcho     5
#define LeftEcho      9


uint16_t Front_US()
{
  digitalWrite(FrontTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(FrontTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(FrontTrig, LOW);

  uint16_t FrontTime    = pulseIn(FrontEcho, HIGH);

  return FrontTime * 0.034 / 2; //344 meter per second -> 0.000344 meter per micro second -> 0.0344 centimeter per micro second
}

uint16_t Back_US()
{
  digitalWrite(BackTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(BackTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(BackTrig, LOW);

  uint16_t BackTime    = pulseIn(BackEcho, HIGH);

  return BackTime * 0.034 / 2; //344 meter per second -> 0.000344 meter per micro second -> 0.0344 centimeter per micro second
}

uint16_t Right_US()
{
  digitalWrite(RightTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(RightTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(RightTrig, LOW);

  uint16_t RightTime    = pulseIn(RightEcho, HIGH);

  return RightTime * 0.034 / 2; //344 meter per second -> 0.000344 meter per micro second -> 0.0344 centimeter per micro second
}

uint16_t Left_US()
{
  digitalWrite(LeftTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(LeftTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(LeftTrig, LOW);

  uint16_t LeftTime    = pulseIn(LeftEcho, HIGH);

  return LeftTime * 0.034 / 2; //344 meter per second -> 0.000344 meter per micro second -> 0.0344 centimeter per micro second
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(FrontTrig, OUTPUT);
  pinMode(BackTrig, OUTPUT);
  pinMode(RightTrig, OUTPUT);
  pinMode(LeftTrig, OUTPUT);

  pinMode(FrontEcho, INPUT);
  pinMode(BackEcho, INPUT);
  pinMode(RightEcho, INPUT);
  pinMode(LeftEcho, INPUT);
}

void loop() {

  uint16_t Front = Front_US();
  uint16_t Back = Back_US();
  uint16_t Right = Right_US();
  uint16_t Left = Left_US();

  Serial.print("Front: ");
  Serial.println(Front);

  Serial.print("Back: ");
  Serial.println(Back);

  Serial.print("Right: ");
  Serial.println(Right);

  Serial.print("Left: ");
  Serial.println(Left);
}
