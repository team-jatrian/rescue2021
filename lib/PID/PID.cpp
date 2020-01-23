#include "PID.hpp"

myPID::myPID(double x , uint32_t y, double a, double b, double c, double max = 100, double min = -100) : setpoint{x}, minMicros{y}, Kp{a}, Ki{b}, Kd{c}, maxOutput{max}, minOutput{min} {};

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
    double iTerm = integral * Ki;
    if ((iTerm > maxOutput) || (iTerm < minOutput)){ //prevents windup in i term
        integral -= error * timeDiff;
    }
    derivative = (error - lastError) / timeDiff;
    if (integral < minOutput || integral > maxOutput)
    output = proportional * Kp + iTerm + (-Kd * derivative);
}
