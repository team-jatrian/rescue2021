#include "line.hpp"
#include "drv.hpp"
#include "sensors.hpp"

myPID line(double(0), 50, double(40), double(0), double(0), double(100), double(-100));

const int8_t weights[5] = {-2, -1, 0, 1, 2};

void drive_line(){
    line.update(getDeviation());
    if (line.output > 0){
        drv(abs(line.output), 100);
    }
    
    else if (line.output < 0){
        drv(100, abs(line.output));
    }
    else {
        drv(70, 70);
    }
    spn(line.output);
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