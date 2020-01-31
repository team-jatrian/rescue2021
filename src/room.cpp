#include "room.h"

void room(){
    align();
}

void align(){
    drv(-70, 70, 750);
    drv(-70, 70, 2000);
    STOP;
}