#ifndef PID_H
#define PID_H

#include "Arduino.h"

class myPID {
    public:
        double Kp, Ki, Kd;
        double output;
        double setpoint;
        uint32_t minMicros;
        myPID(double, uint32_t, double, double, double);
        void update(double), reset();
    private:
        double error, lastError;
        double timeDiff, lastTime = 0;
        double proportional, integral = 0, derivative;
        void calculateTerms(), update(double);
};

#endif