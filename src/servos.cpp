#include "servos.hpp"

Servo heber, kipper, camera;

void setupServos(){
    heber.attach(HEBER_P);
    kipper.attach(KIPPER_P);
    camera.attach(CAM_P);
    camera.write(CAM_NEUTRAL);
    delay(1000);
    camera.detach();
    heber.write(HEBER_NEUTRAL);
    kipper.write(KIPPER_NEUTRAL);
}

void armDown(){
    camera.write(CAM_NEUTRAL);
    delay(1500);
    heber.write(HEBER_DOWN);
    kipper.write(KIPPER_DOWN);
    delay(1500);
}

void armUp(){
    heber.write(HEBER_UP);
    kipper.write(KIPPER_UP);
    delay(1500);
    camera.write(CAM_UP);
    delay(1500);
}