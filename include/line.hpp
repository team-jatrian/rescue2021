#ifndef LINE_H
#define LINE_H

#include <Arduino.h>
#include <PID.hpp>
#include "macros.h"
#include "drv.hpp"
#include "sensors.hpp"

extern myPID line;

void driveLine();
int8_t getDeviation();
void altDrive(bool);

extern uint8_t sensors[5];
extern const int8_t weights[5];

#endif