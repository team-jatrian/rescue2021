#include "servos.hpp"

Servo heber, kipper, camera;

void setupServos(){
    heber.attach(HEBER_P);
    kipper.attach(KIPPER_P);
    camera.attach(CAM_P);
    heber.write(HEBER_NEUTRAL);
    kipper.write(KIPPER_NEUTRAL);
    camera.write(CAM_NEUTRAL);
    delay(500);
    camera.detach();
}

