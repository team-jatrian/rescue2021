#include "drv.hpp"

DRV8834 left(2, 23, 17), right(29, 26, 17); //(ENBL, PHASE, "STEPS")

void drv(int8_t x, int8_t y) {
  if (digitalRead(SWITCH)) {
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

void driveOnlyInner(char x){
    if (x == 'L'){
        while(1){
            if (L.read()){
                drv(0, 0, 50);
                return;
            }
            else if (LI.read() && !RI.read()){
                drv(-50, 50);
            }
            else if (RI.read() && !LI.read()){
                drv(50, -50);
            }
            else {
                drv(50, 50);
            }
        }
    }
    else if (x == 'R') {
        while(1){
            if (R.read()){
                drv(0, 0, 50);
                return;
            }
            else if (LI.read() && !RI.read()){
                drv(-50, 50);
            }
            else if (RI.read() && !LI.read()){
                drv(50, -50);
            }
            else {
                drv(50, 50);
            }
        }
    }
    else {
        while(1){
            if (R.read() || L.read()){
                drv(0, 0, 50);
                return;
            }
            else if (LI.read() && !RI.read()){
                drv(-50, 50);
            }
            else if (RI.read() && !LI.read()){
                drv(50, -50);
            }
            else {
                drv(50, 50);
            }
        }
    }
}