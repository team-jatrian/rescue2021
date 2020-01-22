#ifndef DRV8834_H
#define DRV8834_H

#include "Arduino.h"

class DRV8834 {
  private:
    int16_t mappedSpeed;
    int16_t speed = 0;

    void setPhase();
    void newSpeed();
    void initPins();

  public:
    uint8_t ENBL;
    uint8_t PHASE;
    uint8_t steps = 17;

    void drive(int16_t);
    DRV8834(uint8_t, uint8_t, uint8_t);
};

#endif