#ifndef SENSOR_H
#define SENSOR_H

#include "Arduino.h"

class sensor {
  private:
    uint8_t port;
    uint16_t buffer;

  public:
    uint16_t threshold;
    uint16_t value();
    bool read();
    void debug();
    sensor(uint8_t, uint16_t);
};

#endif