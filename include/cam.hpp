#ifndef CAM_H
#define CAM_H

#include <Arduino.h>
#include "macros.h"
#include "drv.hpp"

void testReceive();
void centerOnLine();
String readString();

extern char opcode;
extern String buffer;

#endif