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
            sketchyRoom();
            break;
        default:
            if (front.read() < 70){
                obstacle();
            }
            /*if (gyroStatus){
                if (rawZ() < -25){
                    speedDiff = 10;
                }
                else if (rawZ() > 6){
                    heber.write(60);
                    speedDiff = -10;
                }
                else {
                    heber.write(HEBER_NEUTRAL);
                    speedDiff = 0;
                }
            }*/
            if (L.value() > 800 && R.value() > 800){
                drv(0, 0, 500);
                sketchyRoom();
            }
            camGreen();
            driveLine();
            break;
  }       
}

void newRoom(){
    
}
