#include <Arduino.h>
#include "macros.h"
#include "line.hpp"
#include "us.hpp"
#include "obstacle.h"

void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    pinMode(SWITCH, INPUT);
    CAM.begin(115200, SERIAL_8O2);
}

void loop(){
    if (char(CAM.read()) == '5'){
        while(1){drv(0, 0);};
    }
    if (front.read() < 45){
        obstacle();
    }
    drive_line();
}

