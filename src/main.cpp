#include <Arduino.h>
#include "macros.h"
#include "selectProgram.h"

void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    pinMode(SWITCH, INPUT);
    CAM.begin(115200, SERIAL_8O2);
}

void loop(){
    selectProgram();
}

