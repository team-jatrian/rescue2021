#include <Arduino.h>
#include "macros.h"
#include <DRV8834.hpp>

DRV8834 left(2, 23, 17), right(29, 26, 17); //(ENBL, PHASE, "STEPS")
inline void drv(int8_t, int8_t);
inline void drv(int8_t , int8_t , int32_t);

void setup(){
    pinMode(SWITCH, INPUT);
}

void loop(){
    drv(70, 70);
}

inline void drv(int8_t x, int8_t y) {
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

inline void drv(int8_t x, int8_t y, int32_t z) {
  repeatMillis(z) {
    drv(x, y);
  }
}