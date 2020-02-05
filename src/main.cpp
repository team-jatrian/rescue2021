#include <Arduino.h>
#include "macros.h"
#include "selectProgram.h"
#include "servos.hpp"

void setup(){
    setupServos();
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    pinMode(SWITCH, INPUT);
    CAM.begin(115200, SERIAL_8O2);
    camera.write(90);
}

void loop(){
    //selectProgram();
    camera.write(0);
    delay(500);
    camera.write(70);
    delay(500);
}

