#ifndef ROOM_H
#define ROOM_H

#include <Arduino.h>
#include "sensors.hpp"
#include "us.hpp"
#include "drv.hpp"
#include "macros.h"
#include "cam.hpp"
#include "gyro.hpp"
#include "servos.hpp"
#include "cam.hpp"

void room();
char getDirection();
void align();
void rescue(char);
void deliveroo();

#endif