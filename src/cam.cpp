#include "cam.hpp"

bool camStatus = false;
String buffer = ""; 
char opcode = '0';

void setupCam(){
    CAM.begin(115200, SERIAL_8O2);
    pinMode(CAM_INTERRUPT, INPUT);
    //attachInterrupt(CAM_INTERRUPT, camISR, CHANGE);
    repeatMillis(10000){
        if (digitalRead(CAM_INTERRUPT)){
            break;
        }
    }
}

void camISR(){
    spn(digitalRead(CAM_INTERRUPT));
    /*
    if (digitalRead(CAM_INTERRUPT)){
        camStatus = true;
    }
    else {
        camStatus = false;
    }*/
}

char camReceive(){
    if (CAM.available() > 0){
        char opcode = CAM.read();
        return opcode;
    }
    return '\0';
}

String readString(){
    while(1){
        if (CAM.available() > 0){
            opcode = CAM.read();
            if (opcode == '\n'){
                opcode = '0';
                String output = buffer;
                buffer = "";   
                return output;
                }
            buffer += opcode;
        }  
    }
}

void camGreen(){
    if (camReceive() == '5'){
        drv(0, 0, 1000);
        CAM.clear();
        switch(camReceive()){
            case '1':
                driveOnlyInner('L');
                drv(50, 50, 300);  
                //driveDegrees(-80);
                drv(-50, 50, 700);
                drv(70, 70, 200);
                CAM.clear();
                return;
            case '2':
                driveOnlyInner('R');
                drv(50, 50, 300);
                drv(50, -50, 700);
                drv(70, 70, 200);
                CAM.clear();
                return;
            case '3': 
                drv(-50, 50, 1400);
                CAM.clear();
                return;
            case '0':
                driveOnlyInner('A');
                drv(70, 70, 300);
                CAM.clear();
                return;
            }
    }
}
