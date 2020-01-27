#include "us.hpp"

PING28015 front(A8, 200); //(PIN, MINDIFF)

void onUsRead(uint16_t x){
    if (front.read() < x){
        obstacle();
    }
}


