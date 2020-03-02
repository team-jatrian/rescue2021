#include <Arduino.h>
#include "macros.h"
#include "selectProgram.h"
#include "servos.hpp"
#include "gyro.hpp"
#include "drv.hpp"
#include "cam.hpp"

void setup(){
    //setupCam();
    CAM.begin(115200, SERIAL_8O2);
    setupServos();
    setupGyro();
    pinMode(SWITCH, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
}

void loop(){
    //selectProgram();
    rotate();
}

