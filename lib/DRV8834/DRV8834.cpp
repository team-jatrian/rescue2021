#include "DRV8834.hpp"

DRV8834::DRV8834(uint8_t x, uint8_t y, uint8_t z) : ENBL{x}, PHASE{y}, steps{z} {
  initPins();
}

void DRV8834::altDrive(int8_t x){
  mappedSpeed = map(x, -100, 100, -255, 255);
  digitalWrite(PHASE, x < 0);
  analogWrite(ENBL, abs(mappedSpeed));
}

void DRV8834::initPins() {
  pinMode(ENBL, OUTPUT);
  pinMode(PHASE, OUTPUT);
}

void DRV8834::drive(int16_t x) {
  mappedSpeed = map(x, -100, 100, -255, 255);
  newSpeed(); setPhase();
  analogWrite(ENBL, abs(speed));
}

void DRV8834::newSpeed() {
  if (speed < mappedSpeed) {
    speed += steps;
  }
  if (speed > mappedSpeed) {
    speed -= steps;
  }
}

void DRV8834::setPhase() {
  if (speed < 0) {
    digitalWrite(PHASE, HIGH);
  }
  if (speed > 0) {
    digitalWrite(PHASE, LOW);
  }
}

