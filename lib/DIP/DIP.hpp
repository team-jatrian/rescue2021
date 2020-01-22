#ifndef DIP_H
#define DIP_H

#include "Arduino.h"

class DIP {
  private:
    void setPins();
    uint8_t bit0, bit1, bit2, bit3;
  public:
    DIP(uint8_t, uint8_t, uint8_t, uint8_t);
    uint8_t readProgram();
};

#endif
