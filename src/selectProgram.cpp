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
        case 15:
            room();
            break;
        default:
            if (front.read() < 70){
                obstacle();
            }
            if (camStatus){
                camGreen();
            }
            drive_line();
            break;
  }       
}
