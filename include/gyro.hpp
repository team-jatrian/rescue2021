#ifndef GYRO_H
#define GYRO_H

#include <Arduino.h>
#include <macros.h>
#include <i2c_t3.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055_t3.h>
#include <utility/imumaths.h>

extern Adafruit_BNO055 bno;

void setupGyro();
int euler();

#endif