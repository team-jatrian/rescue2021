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
    imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
    drv(0, 0, 50);
    int16_t destination = relativeAngle(euler.x(), angle);
    if (angle < 0){
        while(1){
            imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
            if (int(euler.x()) == destination){
                return;
            }
            drv(-50, 50);
        }
        return;
    }
    else if (angle > 0){
        while(1){
            imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
            if (int(euler.x()) == destination){
                return;
            }
            drv(50, -50);
        }
        return;
    }
    else {
        return;
     }
}

int relativeAngle(int16_t from, int16_t to){
    int16_t targetAngle = from + to;
    if (targetAngle < 0){
        return 360 + targetAngle;
    }
    else if (targetAngle > 360){
        return targetAngle - 360;
    }
    else {
        return targetAngle;
    }
}
    

