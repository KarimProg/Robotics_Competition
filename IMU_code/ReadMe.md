
# MPU6050 Gyroscope and Accelerometer

This code uses the `MPU6050_light` library to interface with an MPU6050 gyroscope and accelerometer. 

**The MPU6050** sensor is a 6-axis accelerometer and gyroscope that can be used to measure motion, orientation, and vibration.

## Table of Content
- [MPU6050 Gyroscope and Accelerometer](#mpu6050-gyroscope-and-accelerometer)
  - [Table of Content](#table-of-content)
  - [Usage](#usage)
  - [Setup](#setup)
    - [Calibration](#calibration)
  - [Loop](#loop)

## Usage

Make sure the MPU6050 is calibrated before running the code to get accurate measurements. The `setup` function in the code calculates the gyro and accelerometer offsets. 

To mount the MPU6050 upside down, uncomment the line `mpu.upsideDownMounting = true;` 

Once the device is calibrated, open the serial monitor at 9600 baud rate and observe the angle measurements around the Z-axis.

## Setup

The `Wire` library and `MPU6050_light` library are included at the beginning of the code:

```c++
#include "Wire.h"       
#include <MPU6050_light.h>   
```

An instance of the `MPU6050` object is created, using the `Wire` object as a parameter:

```c++
MPU6050 mpu(Wire); 
unsigned long timer = 0; 
```

The `setup` function initializes the serial communication, the `Wire` library, and the MPU6050 device. It then calls the `calcOffsets` function to calculate gyro and accelerometer offsets:

```c++
void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while(status!=0){ } 
  
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);

  mpu.calcOffsets(); 
  Serial.println("Done!\n");
}
```
### Calibration

To ensure accurate readings from the sensor, it is important to calibrate it. The code includes a calibration function that calculates offsets for the gyro and accelerometer. To calibrate the sensor, follow these steps:
1. Upload the code to your Arduino board.
2. Open the serial monitor (Tools > Serial Monitor).
3. Wait for the "Calculating offsets, do not move MPU6050" message to appear.
4. Keep the sensor still and do not move it during calibration.
5. After a few seconds, the calibration will be complete and the "Done!" message will appear.

## Loop

The `loop` function updates the MPU6050 object and prints the angle around the Z-axis every 10ms:

```c++
void loop() {
  mpu.update();
  
  if((millis()-timer)>10) { 
  Serial.print("\tZ : ");
  Serial.println(mpu.getAngleZ());

  timer = millis();  
  }
}
```
