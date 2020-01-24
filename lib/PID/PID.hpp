#ifndef PID_H
#define PID_H

#include "Arduino.h"

class myPID {
    public:
        double output;
        double setpoint;
        uint32_t minMicros;
        double Kp, Ki, Kd;
        myPID(double, uint32_t, double, double, double, double, double);
        void update(double), reset();
    private:
        double error, lastError;
        double timeDiff, lastTime = 0;
        double proportional, integral = 0, derivative;
        double maxOutput, minOutput;
        void calculateTerms();
};

#endif