#include "servos.hpp"

Servo heber, kipper, camera;

void setupServos(){
    heber.attach(19);
    kipper.attach(20);
    camera.attach(21);
    heber.write(HEBER_NEUTRAL);
    kipper.write(KIPPER_NEUTRAL);
    camera.write(CAM_NEUTRAL);
    delay(100);
}

