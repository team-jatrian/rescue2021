#include "line.hpp"

myPID line(double(0), 0, double(16), double(0), double(), double(0), double(-100));

const int8_t weights[5] = {-4, -2, 0, 2, 4};

void driveLine(){
  line.update(getDeviation());
  if (abs(line.output) < 50){
    if (line.output > 0){
        drv(-50, 50);
    }
    else if (line.output < 0){
        drv(50, -50);
    }
    else {
        drv(50, 50);
    }
  }
  else {
    if (line.output > 0){
        drv(-abs(int(line.output)), /*abs(int(line.output))*/ 50);
    }
    else if (line.output < 0){
        drv(50 /*abs(int(line.output))*/, -abs(int(line.output)));
    }
    else {
        drv(50, 50);
    }
  }
}

int8_t getDeviation(){
  uint8_t sensors[5] = {L.read(), LI.read(), M.read(), RI.read(), R.read()};
  int8_t buffer = 0;
  for (uint8_t i = 0; i < 5; i++) {
    buffer += sensors[i] * weights[i];
  }
  return buffer;
}

void altLine(bool dir){
  if (L.read() && !R.read()){
    drv(-70, 70);
  }
  else if (R.read() && !L.read()){
    drv(70, -70);
  }
  else if (LI.read() && !RI.read()){
    drv(-50, 50);
  }
  else if (RI.read() && !LI.read()){
    drv(50,-50);
  }
  else {
    drv(50, 50);
  }
}