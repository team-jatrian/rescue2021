#ifndef US_H
#define US_H

#include <Arduino.h>
#include <PING28015.hpp>
#include "macros.h"

extern PING28015 front, sideR;

int readIR(uint8_t);

#endif

