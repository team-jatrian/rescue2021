#include "line.hpp"

myPID line(double(0), 0, double(16), double(0), double(), double(0), double(-100));

const int8_t weights[5] = {-4, -2, 0, 2, 4};

void drive_line(){
    line.update(getDeviation());
    if (line.output > 0){
        drv(-abs(int(line.output)), /*abs(int(line.output))*/ 50);
    }
    
    else if (line.output < 0){
        drv(50 /*abs(int(line.output))*/, -abs(int(line.output)));
    }
    else {
        drv(50, 50);
    }
    //spn(int(line.output));
}

int8_t getDeviation(){
  uint8_t sensors[5] = {L.read(), LI.read(), M.read(), RI.read(), R.read()};
  int8_t buffer = 0;
  for (uint8_t i = 0; i < 5; i++) {
    buffer += sensors[i] * weights[i];
  }
  //spn(buffer);
  return buffer;
}