#ifndef CAM_H
#define CAM_H

#include <Arduino.h>
#include "macros.h"
#include "drv.hpp"
#include "sensors.hpp"

#define CAM Serial4

char camReceive();
String readString();
void camGreen();

extern char opcode;
extern String buffer;

#endif 