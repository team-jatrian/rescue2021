#include <Arduino.h>
#include "macros.h"
#include "drv.hpp"
#include "line.hpp"
#include "sensors.hpp"
#include "sensordebug.hpp"

void setup(){
    pinMode(SWITCH, INPUT);
}

void loop(){
    drive_line();
}

