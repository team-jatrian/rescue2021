#include "gyro.hpp"

Adafruit_BNO055 bno = Adafruit_BNO055(-1, 0x28);

void setupGyro(){
    Wire.setSDA(34);
    Wire.setSCL(33);
    if(!bno.begin())
    {
        spn("bno not detected");
        while(1);
    }
    bno.setExtCrystalUse(true);
}

int euler(){
    imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
    return euler.x();
}