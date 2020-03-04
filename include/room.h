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

#define IRFRONT A17

void sketchyRoom();
void room();
void selector(uint16_t);
void ball();
void turn(uint16_t);
void findZone();
void deliveroo();

#endif