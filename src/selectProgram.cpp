#include "selectProgram.h"

DIP ps(8, 7, 6, 5);

void selectProgram(){
    switch (ps.readProgram()) {
        case 1:
            debug();
            break;
        case 15:
            driveDegrees(-90);
            drv(0, 0, 500);
            break;
        default:
            /*if (L.value() > 300 || R.value() > 300) || LI.value() > 300 || RI.value() > 300){
                room();
            }*/
            onUsRead(70);
            camGreen();
            drive_line();
            break;
  }       
}