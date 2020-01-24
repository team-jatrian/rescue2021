#include "line.hpp"
#include "drv.hpp"

myPID line(double(0), 50, double(1), double(1), double(1), double(100), double(-100));

void drive_line(){
    line.update(getDeviation());
    /*if (line.output < 0){
        drv(-line.output, 100);
    }
    
    else if (line.output > 0){
        drv(100, -line.output);
    }
    else {
        drv(70, 70);
    }*/
    spn(line.output);
}

double getDeviation(){
    //implementation here
    return 0;
}