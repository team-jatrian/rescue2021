#ifndef CAM_H
#define CAM_H

#include <Arduino.h>
#include "macros.h"
#include "drv.hpp"
#include "sensors.hpp"
#include "gyro.hpp"

#define CAM Serial4
#define CAM_INTERRUPT 35

void setupCam();
char camReceive();
String readString();
void camGreen();
void driveDirection();

extern char opcode;
extern String buffer;

#endif 