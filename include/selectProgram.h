#ifndef SELECT_PROGRAM_H
#define SELECT_PROGRAM_H

#include <Arduino.h>
#include "macros.h"
#include "CAM.hpp"
#include "DIP.hpp"
#include "line.hpp"
#include "us.hpp"
#include "obstacle.h"
#include "sensordebug.hpp"
#include "room.h"
#include "gyro.hpp"
#include "servos.hpp"

extern DIP ps;

void selectProgram();

#endif