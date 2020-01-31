#include "selectProgram.h"

DIP ps(8, 7, 6, 5);

void selectProgram(){
    switch (ps.readProgram()) {
        case 1:
            debug();
            break;
        case 15:
            driveOnlyInner('L');
            drv(70, 70, 200);
            drv(-70, 70, 400);
            while(!L.read()){
                drv(-70, 70);
            }
            drv(0, 0, 1000);
            drv(70, 70, 200);
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