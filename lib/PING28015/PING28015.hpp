#ifndef PING28015_H
#define PING28015_H

#include "Arduino.h"

class PING28015 {
  private:
    int64_t duration;
    int32_t mm;
    uint8_t pin;
    uint32_t lastMillis = 0;
    uint32_t lastDistance = 0;

  public:
    PING28015(uint8_t, uint16_t);
    uint16_t read();
	uint16_t mindiff = 300;

};

#endif