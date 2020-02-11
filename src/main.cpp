#include <Arduino.h>
#include "macros.h"
#include "selectProgram.h"
#include "servos.hpp"
#include "gyro.hpp"

void setup(){
    setupServos();
    setupGyro();
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    pinMode(SWITCH, INPUT);
    CAM.begin(115200, SERIAL_8O2); 
}

void loop(){
    //spn(euler());
    selectProgram();
}

