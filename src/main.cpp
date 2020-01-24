#include <Arduino.h>
#include "macros.h"
#include "line.hpp"
#include "us.hpp"
#include "obstacle.h"
#include "cam.hpp"

void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    pinMode(SWITCH, INPUT);
    CAM.begin(115200, SERIAL_8O2);
}

void loop(){
    spn(readString());
    /*
    if (front.read() < 45){
        obstacle();
    }
    drive_line();*/
}

