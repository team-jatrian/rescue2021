#include "line.hpp"
#include "drv.hpp"

void drive_line(){
    line.update(getDeviation());
    if (line.output < 0){
        drv(-line.output, 100);
    }
    
    else if (line.output > 0){
        drv(100, -line.output);
    }
    else {
        drv(70, 70);
    }
}

double getDeviation(){
    //implementation here
}