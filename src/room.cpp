#include "room.h"

void room(){
    CAM.write(7);
    armUp();
    camera.attach(CAM_P);
    camera.write(CAM_UP);
    delay(1500);
    char dir = 'l';
    //align();
    rescue(dir);
}

char getDirection(){
    drv(70, 70, 200);
    driveDegrees(90);
    drv(0, 0, 200);
    if (front.read() < 250){
        driveDegrees(-90);
        drv(0, 0, 200);
        return 'l';
    }
    else {
        driveDegrees(-90);
        drv(0, 0, 200);
        return 'r';
    }
}

void align(){
    camera.write(60);
    drv(-70, 70, 1200);
    drv(0, 0, 200);
    drv(-70, -70, 3000);
    drv(0, 0, 200);
}

void rescue(char dir){
    for(uint8_t d = 100; d < 400; d += 20){
        for (uint8_t i = 0; i < 4; i++){
            while(1){
                if (front.read() < d){
                    drv(0, 0, 200);
                    CAM.clear();
                    spn(camReceive());
                    switch (camReceive()){
                        case '1':
                            drv(0, 0, 500);
                            armDown();
                            armUp();
                            CAM.clear(); 
                            break;  
                        case '6':
                            //STOP;
                        default:
                            drv(0, 0, 200);
                            if (dir == 'l'){
                                drv(70, -70, 600);
                                drv(0, 0, 100);
                                drv(-70, -70, 700); 
                            }
                            else {
                                drv(-70, 70, 600);
                                drv(0, 0, 100);
                                drv(-70, -70, 700); 
                            }
                            break;
                    }
                }
                drv(70, 70);
            }
        }
    }
}

void deliveroo(){
    camera.attach(CAM_P);
    camera.write(CAM_UP);
    delay(1500);
    drv(0, 0, 200);
    drv(-70, 70, 400);
    drv(70, 70, 500);
    drv(70, -70, 450);
    drv(70, 70, 500);
    drv(0, 0, 200);
    camera.write(CAM_NEUTRAL);
    heber.write(60);
    kipper.write(20);
    delay(1500);
    kipper.write(180);
    delay(1500);
    STOP;
}