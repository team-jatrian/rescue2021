#include "gyro.hpp"

Adafruit_BNO055 bno = Adafruit_BNO055(-1, 0x28);

void setupGyro(){
    pinMode(RST, OUTPUT);
    digitalWrite(RST, LOW); //reset routine
    delayMicroseconds(30);
    digitalWrite(RST, HIGH);
    delay(800);
    Wire.setSDA(SDA);
    Wire.setSCL(SCL);
    if(!bno.begin())
    {
        spn("bno not detected");
        while(1);
    }
    bno.setExtCrystalUse(true);
}

void rotate(int16_t x){
  double destination, relativeX, origin = getRawX();
  if (x < 0){
    destination = 360 - x;
    while(1){
      relativeX = getRawX() - origin;
      if (relativeX > destination){
        drv(0, 0, 200);
        break;
      }
      drv(-70, 70);
    }
  }
  else {
    destination = x;
    while(1){
      relativeX = getRawX() - origin;
      if (relativeX < destination){
        drv(0, 0, 200);
        break;
      }
      drv(70, -70);
    }
  }
}

double getRawX(){
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  return euler.x();
}
