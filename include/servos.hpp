#ifndef SERVOS_H
#define SERVOS_H

#include <Arduino.h>
#include <Servo.h>

#define HEBER_NEUTRAL 0
#define KIPPER_NEUTRAL 0
#define CAM_NEUTRAL 0

extern Servo heber, kipper, camera;

void setupServos();

#endif