#include <SHTSensor.h>
#include "SparkFunLSM6DS3.h"
#include "Wire.h"
#include "SPI.h"

#define I2C_SCL 19
#define I2C_SDA 18


LSM6DS3 accGyro(I2C_MODE);
SHTSensor moistureSensor;

void setup() {                                                                
  Serial.begin(9600);
  delay(500);
  
  Wire.setSDA(I2C_SDA);
  Wire.setSCL(I2C_SCL);

  int gyroStat = accGyro.begin();
  Serial.println("Gyro Initialization Status: " + gyroStat);
  if (gyroStat != 0) {
     Serial.println("Problem starting the LSM6DS3.");
  }
  else {
    Serial.println("LSM6DS3 started!");
  }

  moistureSensor.init();
}

void loop() {
  moistureSensor.readSample();

  Serial.print("Humidity: ");
  Serial.print(moistureSensor.getHumidity(), 2);
  Serial.print("\tTemperature: ");
  Serial.print(moistureSensor.getTemperature(), 2);
  Serial.println();
  /*
  Serial.print("\nAccelerometer:\n");
  Serial.print(" X1 = ");
  Serial.println(SensorOne.readFloatAccelX(), 4);
  Serial.print(" Y1 = ");
  Serial.println(SensorOne.readFloatAccelY(), 4);
  Serial.print(" Z1 = ");
  Serial.println(SensorOne.readFloatAccelZ(), 4);
  */
}
