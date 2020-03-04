#include "us.hpp"

PING28015 front(A8, 200), sideR(A17, 200); //(PIN, MINDIFF)

int readIR(uint8_t pin){
    return (2200/analogRead(pin));
}


