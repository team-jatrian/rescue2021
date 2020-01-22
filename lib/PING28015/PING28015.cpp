#include "Arduino.h"
#include "PING28015.hpp"

PING28015::PING28015(uint8_t x, uint16_t y) : pin{x}, mindiff{y}{};

int16_t PING28015::read() {
      if (millis() - lastMillis < mindiff){
        return lastDistance;
      }
      // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
      // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
      pinMode(pin, OUTPUT);
      digitalWrite(pin, LOW);
      delayMicroseconds(2);
      digitalWrite(pin, HIGH);
      delayMicroseconds(15);
      digitalWrite(pin, LOW);
      delayMicroseconds(20);
      // The same pin is used to read the signal from the PING))): a HIGH
      // pulse whose duration is the time (in microseconds) from the sending
      // of the ping to the reception of its echo off of an object.
      pinMode(pin, INPUT);
      duration = pulseIn(pin, HIGH, 20000ul);
      mm = duration / 6; //microsecondsToCentimeters(duration);
      lastDistance = mm;
      lastMillis = millis();
      return mm;
    }
