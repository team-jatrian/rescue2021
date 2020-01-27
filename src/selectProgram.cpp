#include "selectProgram.h"

DIP ps(8, 7, 6, 5);

void selectProgram(){
    switch (ps.readProgram()) {
        case 1:
            debug();
            break;
        default:
            drive_line();
            break;
  }       
}