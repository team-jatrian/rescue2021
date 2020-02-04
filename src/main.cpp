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
    kamera.write(90);
}

void loop(){
    //selectProgram();
    kamera.write(0);
    delay(500);
    kamera.write(70);
    delay(500);
}

