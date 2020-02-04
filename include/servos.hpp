#ifndef SERVOS_H
#define SERVOS_H

#include <Arduino.h>
#include <Servo.h>

extern Servo heber, kipper, kamera;

void setupServos();

#endif