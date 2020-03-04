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

void room(){
    CAM.write(7);
    camera.attach(CAM_P);
    camera.write(CAM_UP);
    for(uint16_t d = 7; d < 25; d += 2){
        for(uint8_t i = 0; i < 4; i++){
            while(1){
                /*if (readIR(IRFRONT) < d){
                    while(readIR(IRFRONT) > 6){
                        drv(70, 70);
                    }
                    drv(0, 0, 500);
                    CAM.clear();
                    selector(d);
                    break;
                }
                else {
                    drv(70, 70);
                }*/
                if (camReceive() == '1'){
                    ball();
                }
                else if (readIR(IRFRONT) < 6){
                    drv(0, 0, 500); 
                    selector(d);
                }
                else { 
                    drv(70, 70);
                }
            }
        }
    }
}

void selector(uint16_t d){
    switch(camReceive()){
        case '\0':
            selector(d); 
        case '1': 
            ball();
            CAM.clear(); 
            break;
        default: 
            turn(d);
            CAM.clear();
            break;
    }
}

void ball(){
    switch(camReceive()){
        case '\0':
            ball();
        default: 
            spn("KUGEL");
            armDown();
            armUp();
            findZone();
            break;
    }
}

void turn(uint16_t d){
    while(readIR(IRFRONT) < d){
        drv(-70, -70);
    }
void align(){
    camera.write(60);
    drv(-70, 70, 1200);
    drv(0, 0, 200);
    drv(-70, 70, 650); 
    drv(0, 0, 200);
    drv(-70, -70, d*25);
}

void findZone(){
    drv(0, 0, 200);
    for(uint8_t i = 0; i < 4; i++){
        while(!(readIR(IRFRONT) > 6)){
            if (R.read() || RI.read() || M.read()){
                deliveroo();
                return;
            }
            drv(70, 70);
        }
        drv(0, 0, 200);
        drv(-70, 70, 650);
        drv(0, 0, 200);
        drv(-70, -70, 300);
        break;
    }
}

void deliveroo(){
    drv(0, 0, 200);
    drv(-70, -70, 300);
    drv(0, 0, 200);
    camera.write(CAM_NEUTRAL);
    delay(1000);
    heber.write(HEBER_DOWN);
    kipper.write(KIPPER_DOWN);
    delay(1500);
    heber.write(HEBER_UP);
    kipper.write(KIPPER_UP);
    delay(1500);
    camera.write(CAM_UP);
    delay(1000);
}