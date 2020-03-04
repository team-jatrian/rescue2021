#include "gyro.hpp"

Adafruit_BNO055 bno = Adafruit_BNO055(-1, 0x28);

bool gyroStatus;

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
        gyroStatus = false;
    }
    bno.setExtCrystalUse(true);
    gyroStatus = true;
}

void rotateAbs(int16_t x){ //absolute x angle rotation
  drv(0, 0, 200);
  double relativeX, origin = getRawX();
  if (x > 180){
    while(1){
      relativeX = getRawX() - origin;
      if (relativeX <= x){
        drv(0, 0, 200);
        break;
      }
      drv(-70, 70);
    }
  }
  else {
    while(1){
      relativeX = getRawX() - origin;
      if (relativeX >= x){
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

