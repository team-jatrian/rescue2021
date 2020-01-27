#ifndef US_H
#define US_H

#include <Arduino.h>
#include <PING28015.hpp>
#include "obstacle.h" 
#include "macros.h"

extern PING28015 front;

void onUsRead(uint16_t);

#endif

