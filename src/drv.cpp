#include "drv.hpp"

DRV8834 left(2, 23, 17), right(29, 26, 17); //(ENBL, PHASE, "STEPS")

void drv(int8_t x, int8_t y) {
  if (digitalRead(SWITCH)) {
    //delay(2);
    left.drive(x);
    right.drive(y);
  }
  
  else {
    left.drive(0);
    right.drive(0);
  }
}

void drv(int8_t x, int8_t y, int32_t z) {
  for(uint32_t tx = millis(); millis() < tx + z;) {
    drv(x, y);
  }
}