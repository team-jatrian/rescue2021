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

void driveDegrees(int16_t angle){
    drv(0, 0, 200);
    double targetAngle = normAngle(getOrientation() - angle);
    if (angle < 0){
        while(angleTolerance(4, targetAngle)){
            drv(-70, 70);
        }
    }
    else {
        while(angleTolerance(4, targetAngle)){
            drv(70, -70);
        }
    } 
}

double getOrientation() {
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  if (euler.x() > 180.0){
    return euler.x() - 360.0;
  }
  else {
    return euler.x();
  }
}

double normAngle(double angle) {
  if (angle < -180.0){
    angle += 360.;
  }
  else if (angle > 180.0){
    angle -= 360.;
  }
  return angle;
}

boolean angleTolerance(double tolerance, double targetAngle) {
  double realAngle = normAngle(targetAngle - getOrientation());
  spn(abs(realAngle));
  return (abs(realAngle) > tolerance);
}