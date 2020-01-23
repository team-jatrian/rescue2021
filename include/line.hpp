#include <Arduino.h>
#include <PID.hpp>
#include "macros.h"

myPID line(0, 50, 1, 1, 1);

void drive_line();
double getDeviation();