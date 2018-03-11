#include <LSM6DS3Sensor.h>
#include <LSM6DS3_ACC_GYRO_Driver.h>

#define I2C2_SDA 0 # TODO figure out what this should be
#define I2C2_SCL 1 # TODO ^

TwoWire *dev_i2c;
LSM6DS3Sensor *AccGyr;

void setup() {
  SerialPort.begin(9600);
  
  dev_i2c = new TwoWire(I2C2_SDA, I2C2_SCL);  
  dev_i2c->begin();

  AccGyr = new LSM6DS3Sensor(dev_i2c);  
  AccGyr->Enable_X();  
  AccGyr->Enable_G();  
}

void loop() {
  // put your main code here, to run repeatedly:
  int32_t accelerometer[3];
  int32_t gyroscope[3];
  AccGyr->Get_X_Axes(accelerometer);
  AccGyr->Get_G_Axes(gyroscope);

  SerialPort.print("| Acc[mg]: ");
  SerialPort.print(accelerometer[0]);
  SerialPort.print(" ");
  SerialPort.print(accelerometer[1]);
  SerialPort.print(" ");
  SerialPort.print(accelerometer[2]);
  SerialPort.print(" | Gyr[mdps]: ");
  SerialPort.print(gyroscope[0]);
  SerialPort.print(" ");
  SerialPort.print(gyroscope[1]);
  SerialPort.print(" ");
  SerialPort.print(gyroscope[2]);
  SerialPort.println(" |");
}
