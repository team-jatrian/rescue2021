#include "DIP.hpp"

DIP::DIP(uint8_t a, uint8_t b, uint8_t c, uint8_t d) : bit0{a}, bit1{b}, bit2{c}, bit3{d} {
  setPins();
}

void DIP::setPins() {
  pinMode(bit0, INPUT);
  pinMode(bit1, INPUT);
  pinMode(bit2, INPUT);
  pinMode(bit3, INPUT);
}

uint8_t DIP::readProgram() {
  uint8_t bitAdresses[4] = {bit0, bit1, bit2, bit3};
  uint8_t returnByte = 0;
  for (uint8_t i = 0; i < 4; i++) {
    bitWrite(returnByte, i, digitalRead(bitAdresses[i]));
  }
  return returnByte;
}