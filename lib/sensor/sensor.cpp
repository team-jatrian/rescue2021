#include "sensor.hpp"

sensor::sensor(uint8_t x, uint16_t y) : port{x}, threshold{y} {
  pinMode(x, INPUT);
}

bool sensor::read() {
  delay(1);
  /*buffer = 0;
  for (uint8_t i = 0; i < 10; i++) {
    buffer += ar(port);
  }
  buffer /= 10;*/
  if (analogRead(port) < threshold) {
    return true;
  }
  else {
    return false;
  }
}

uint16_t sensor::value() {
  return analogRead(port);
  //buffer = 0;
    /*for (uint8_t i = 0; i < 10; i++) {
    buffer += ar(port);
  }
  return (buffer / 10);*/
}

void sensor::debug() {
  Serial.print(port);
  Serial.print(": ");
  Serial.print(value());
  Serial.print("\t");
}
