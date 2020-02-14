#ifndef SERVOS_H
#define SERVOS_H

#include <Arduino.h>
#include <Servo.h>

#define HEBER_P 20
#define KIPPER_P 21
#define CAM_P 13
#define CAM_NEUTRAL 100 
#define CAM_UP 70
#define HEBER_NEUTRAL 140 
#define HEBER_DOWN 0
#define HEBER_UP 120
#define KIPPER_NEUTRAL 30
#define KIPPER_DOWN 0
#define KIPPER_UP 110

extern Servo heber, kipper, camera;

void setupServos();
void armDown(), armUp();

#endif