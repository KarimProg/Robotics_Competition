#include "Wire.h"	//Include the wire library for I2C communication.
#include <MPU6050_light.h> ////Include the `MPU6050_light` library for controlling the MPU6050 sensor.

MPU6050 mpu(Wire);	// initialize MPU6050 with the Wire library
unsigned long timer = 0;	// initialize a timer variable to be used for the loop function

void setup() {
  Serial.begin(9600);	// start serial communications with 9600 baud rate
  Wire.begin();		// start the I2C communication
  
  byte status = mpu.begin();	 // initialize the MPU6050, return 0 if successful
	// Prints the status of the MPU6050 sensor to the serial monitor.
  Serial.print(F("MPU6050 status: "));	
  Serial.println(status);	
  while(status!=0){ } // Stops the program if it could not connect to the MPU6050 sensor.
  
  Serial.println(F("Calculating offsets, do not move MPU6050")); //Prints a message to the serial monitor to inform the user about the calculating of offsets.
  delay(1000); //Delay waiting for the MPU6050 sensor to stabilize.
  // mpu.upsideDownMounting = true; // uncomment this line if the MPU6050 is mounted upside-down
  mpu.calcOffsets(); //Calculates the gyro and accelerometer offsets.
  Serial.println("Done!\n"); //Prints a message to the serial monitor to inform the user that the offsets calculation is complete.
}

void loop() {
  mpu.update(); //Update the MPU6050 measurements
  
  if((millis()-timer)>10) { //Checks if 10ms has passed.
	Serial.print("\tZ : ");
	Serial.println(mpu.getAngleZ()); // Get the angle measurement around the Z-axis and print it

	timer = millis();  // reset the timer
  }
}
