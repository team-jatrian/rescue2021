#include "servos.hpp"

Servo heber, kipper, kamera;

void setupServos(){
    heber.attach(19);
    kipper.attach(20);
    kamera.attach(21);
    heber.write(0);
    kipper.write(0);
    kamera.write(0);
}

