#include <Arduino.h>
#include <DRV8834.hpp>
#include "macros.h"

DRV8834 left(2, 23, 17), right(29, 26, 17); //(ENBL, PHASE, "STEPS")

void drv(int8_t, int8_t);
void drv(int8_t , int8_t , int32_t);


