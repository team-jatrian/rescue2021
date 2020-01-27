#ifndef DRV_H
#define DRV_H

#include <Arduino.h>
#include <DRV8834.hpp>
#include "macros.h"

extern DRV8834 left, right; 

void drv(int8_t, int8_t);
void drv(int8_t , int8_t , int32_t);

#endif
