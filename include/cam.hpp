#ifndef CAM_H
#define CAM_H

#include <Arduino.h>
#include "macros.h"
#include "drv.hpp"
#include "sensors.hpp"

char testReceive();
String readString();
void camGreen();
void driveOnlyInner(char);

extern char opcode;
extern String buffer;

#endif