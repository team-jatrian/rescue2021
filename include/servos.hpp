#ifndef SERVOS_H
#define SERVOS_H

#include <Arduino.h>
#include <Servo.h>


#define HEBER_P 20
#define KIPPER_P 21
#define CAM_P 13
#define HEBER_NEUTRAL 150
#define KIPPER_NEUTRAL 0
#define CAM_NEUTRAL 140

extern Servo heber, kipper, camera;

void setupServos();

#endif