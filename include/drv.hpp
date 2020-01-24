#include <Arduino.h>
#include <DRV8834.hpp>
#include "macros.h"

extern DRV8834 left, right; //(ENBL, PHASE, "STEPS")

void drv(int8_t, int8_t);
void drv(int8_t , int8_t , int32_t);


