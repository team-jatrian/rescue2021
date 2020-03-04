#ifndef GYRO_H
#define GYRO_H

#include <Arduino.h>
#include <macros.h>
#include <drv.hpp>
#include <i2c_t3.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055_t3.h>
#include <utility/imumaths.h>

#define SCL 33 
#define SDA 34
#define RST 30

extern Adafruit_BNO055 bno;
extern bool gyroStatus;

void setupGyro();
void driveDegrees(int16_t);
int relativeAngle(int16_t, int16_t);
double getOrientation();
double normAngle(double);
boolean angleTolerance(double, double);
int rawZ();
void rotateAbs(int16_t);
double getRawX();

extern bool gyroStatus;

#endif