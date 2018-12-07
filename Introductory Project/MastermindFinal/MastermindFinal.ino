#include <Wire.h>

boolean __ardublockIsI2cReadOk;

void __ardublockI2cWriteData(int devAddr, int regAddr, int value)
{
  Wire.beginTransmission(devAddr);
  Wire.write(regAddr);
  Wire.write(value);
  Wire.endTransmission();
}

void __ardublockI2cWriteDataOne(int devAddr, int regAddr)
{
  Wire.beginTransmission(devAddr);
  Wire.write(regAddr);
  Wire.endTransmission();
}

int __ardublockI2cReadData(int devAddr, int regAddr)
{
  int data = 0;
  char b;
  Wire.beginTransmission(devAddr);
  Wire.write(regAddr);
  Wire.endTransmission();
  Wire.requestFrom(devAddr, 1);
  if (Wire.available() > 0)
  {
    __ardublockIsI2cReadOk = true;
    b = Wire.read();
    data = b;
  }
  else
  {
    __ardublockIsI2cReadOk = false;
  }
  return data;
}


void setup()
{
  Serial.begin(9600);
  Wire.begin();
  __ardublockIsI2cReadOk = false;
}

void loop()
{
  Serial.print("lets see if this works");
  Serial.print(" ");
  Serial.print( __ardublockIsI2cReadOk );
  Serial.print(" ");
  Serial.println();
  //Unable to dectect your Arduino version, using 1.0 in default
  __ardublockI2cWriteData( 9 , 5 , 3 );
}
