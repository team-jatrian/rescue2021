#include <Arduino.h>
#include <PID.hpp>
#include "macros.h"

extern myPID line;

void drive_line();
double getDeviation();