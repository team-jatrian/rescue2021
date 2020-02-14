#include "selectProgram.h"

DIP ps(8, 7, 6, 5);

void selectProgram(){
    switch (ps.readProgram()) {
        case 1:
            debug();
            break;
        case 3:
            armDown();
            armUp();
            deliveroo();
            break;
        case 6:
            heber.attach(HEBER_P);
            for (uint8_t i = 0; i <= 180; i += 30){
                heber.write(i);
                delay(1000);
            }
            heber.detach();
            break;
        case 13: //motor test
            drv(70, 70, 1000);
            drv(-70, 70, 1000);
            drv(70, -70, 1000);
            drv(-70, -70, 1000);
            break;
        case 15:
            room();
            break;
        default:
            if (front.read() < 70){
                obstacle();
            }
            if (L.value() > 800 && R.value() > 800){
                room();
            }
            camGreen();
            drive_line();
            break;
  }       
}
