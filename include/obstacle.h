#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <Arduino.h>
#include <EEPROM.h>
#include "macros.h"
#include "drv.hpp"
#include "sensors.hpp"

void obstacle();
void writeAttempt(char);

#endif