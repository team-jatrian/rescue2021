#include "PID.hpp"

myPID::myPID(double x , uint32_t y) : setpoint{x}, minMicros{y} {};

void myPID::update(double x){
    error = setpoint - x;
    timeDiff = (micros() - lastTime); //update Times
    if (timeDiff > minMicros) {calculateTerms();};
    lastError = error; //save for next iteration
    lastTime = micros();
}

void myPID::reset(){
    lastTime = 0;
    lastError = 0;
    integral = 0;
}


void myPID::calculateTerms(){
    proportional = error; 
    integral += error * timeDiff;
    derivative = (error - lastError) / timeDiff;
    output = proportional * Kp + integral * Ki + (-Kd * derivative);
}