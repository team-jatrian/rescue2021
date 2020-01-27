#ifndef LINE_H
#define LINE_H

#include <Arduino.h>
#include <PID.hpp>
#include "macros.h"

extern myPID line;

void drive_line();
int8_t getDeviation();

extern uint8_t sensors[5];
extern const int8_t weights[5];

#endif