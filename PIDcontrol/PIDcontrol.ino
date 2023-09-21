#include <Servo.h>
#include <Wire.h>
#include <MPU6050_light.h>

#define FrontTrig     3
#define BackTrig      5
#define RightTrig     7
#define LeftTrig      12

#define FrontEcho     4
#define BackEcho      6
#define RightEcho     8
#define LeftEcho      13

#define A_speed  9   // PWM PIN!
#define IN1 A3
#define IN2 A2

#define B_speed  10   // PWM PIN!
#define IN3 A1
#define IN4 A0

Servo myservo;  // create servo object to control a servo

MPU6050 mpu(Wire);
unsigned long timer = 0;

int val;    // variable to read the value from the analog pin

double setpoint = 90;  // Setpoint for the servo position
double actualValue;    // Actual value (sensor reading)
double error;
double previousError = 0;
double integral = 0;
double derivative;
double output;

double Kp = 1;  // Proportional constant
double Ki = 0;  // Integral constant
double Kd = 0;  // Derivative constant

void setup() {
  
}

void loop() {
  uint16_t Front = Front_US();
  uint16_t Back = Back_US();
  uint16_t Right = Right_US();
  uint16_t Left = Left_US();

  val = 90; // Analog read or any other method to get the actual value

  // Compute PID output
  error = setpoint - actualValue;
  double P = Kp * error;
  integral += Ki * error;
  derivative = Kd * (error - previousError);
  output = P + integral + derivative;
  previousError = error;

  val += output;
  if (val < 0)
    val = 0;
  if (val > 180)
    val = 180;

  myservo.write(val);

}


/*
double setpoint = 90;  // Setpoint for the servo position
double actualValue;    // Actual value 
double error;
double previousError = 0;
double integral = 0;
double derivative;
double output;

double Kp = 1;
double Ki = 0;
double Kd = 0;
error = setpoint - actualValue;
double P = Kp * error;
integral += Ki * error;
derivative = Kd * (error - previousError);
output = P + integral + derivative;
previousError = error;
val += output;
if (val < 0)
   val = 0;
if (val > 180)
 val = 180;
  myservo.write(val);

int motorSpeed = output;
*/