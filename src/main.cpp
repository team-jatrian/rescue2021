#include <Arduino.h>
#include "macros.h"
#include "drv.h"

void setup(){
    pinMode(SWITCH, INPUT);
}

void loop(){
    drv(70, 70);
}

