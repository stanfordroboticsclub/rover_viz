
#define I2C2_SCL 19
#define I2C2_SDA 18

#include "SparkFunLSM6DS3.h"
#include "Wire.h"
#include "SPI.h"

LSM6DS3 SensorOne( I2C_MODE );
//LSM6DS3Sensor *AccGyr;

void setup() {
  Serial.begin(9600);
  delay(500);
  
  Wire.setSDA(I2C2_SDA);
  Wire.setSCL(I2C2_SCL);

  int stat = SensorOne.begin();
  Serial.println(stat);
  if (stat != 0) {
     Serial.println("Problem starting the sensor.");
  }
  else {
    Serial.println("Sensor started!");
  }
}

void loop() {
  Serial.print("\nAccelerometer:\n");
  Serial.print(" X1 = ");
  Serial.println(SensorOne.readFloatAccelX(), 4);
  Serial.print(" Y1 = ");
  Serial.println(SensorOne.readFloatAccelY(), 4);
  Serial.print(" Z1 = ");
  Serial.println(SensorOne.readFloatAccelZ(), 4);
}
