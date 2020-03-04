#include "room.h"

void sketchyRoom(){
    camera.attach(CAM_P);
    camera.write(CAM_UP);
    for(uint16_t d = 60; d < 200; d += 30){
        for(uint8_t i = 0; i < 3; i++){
            while(front.read() > 80){
                drv(70, 70);
                if(L.read() || LI.read() || M.read()){
                    drv(70, 70, 300);
                    drv(-70, -70, 900);
                    drv(70, -70, 800);
                    drv(0, 0, 200);
                }
            }
            drv(0, 0, 200);
            drv(70, -70, 800);
            drv(0, 0, 200);
            drv(-70, -70, 400);         
        }
        drv(-70, -70, 600);
        drv(0, 0, 200);
        drv(70, -70, 800);
        drv(0, 0, 200);
        drv(-70, -70, 400);
    }   
}