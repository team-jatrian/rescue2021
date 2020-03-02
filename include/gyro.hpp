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

void setupGyro();
void rotate();
double getRawX();

#endif