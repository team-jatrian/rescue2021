#include <Arduino.h>
#include "drv.h"

void setup(){
    setSwitch();
}

void loop(){
    drv(70, 70);
}

