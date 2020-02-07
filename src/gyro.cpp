#include "gyro.hpp"

Adafruit_BNO055 bno = Adafruit_BNO055(-1, 0x28);

void setupGyro(){
    //pinMode(RST, OUTPUT);
    Wire.setSDA(SDA);
    Wire.setSCL(SCL);
    if(!bno.begin())
    {
        spn("bno not detected");
        while(1);
    }
    bno.setExtCrystalUse(true);
    /*digitalWrite(RST, LOW); //reset routine
    delayMicroseconds(30);
    digitalWrite(RST, HIGH);
    delay(700);*/
}

int euler(){  
    imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
    return euler.x();
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

int relativeAngle(int16_t fromAngle, int16_t addAngle){
    if (addAngle < 0){
        int16_t partialAngle = fromAngle + addAngle;
        if (partialAngle < 0){
            return (360 + partialAngle);
        }
        else {
            return partialAngle;
        }
    }
    if (addAngle > 0){
        int16_t theoreticalAngle = fromAngle + addAngle;
        if (theoreticalAngle > 360){
            return (theoreticalAngle - 360);
        }
        else {
            return theoreticalAngle;
        }
    }
    else {
        return (fromAngle + addAngle);
    }
    return 0;
}

