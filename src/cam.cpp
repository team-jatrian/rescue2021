#include "cam.hpp"

String buffer = "";
char opcode = '0';

char testReceive(){
    if (CAM.available() > 0){
        char opcode = CAM.read();
        spn(opcode);
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
    if (testReceive() == '5'){
        drv(0, 0, 1000);
        switch(testReceive()){
            case '1':
                driveOnlyInner('L');
                drv(70, 70, 300);
                drv(-70, 70, 400);
                while(!M.read()){
                    drv(-70, 70);
                }
                drv(0, 0, 1000);
                drv(70, 70, 100);
                CAM.clear();
                return;
            case '2':
                driveOnlyInner('R');
                drv(70, 70, 300);
                drv(70, -70, 400);
                while(!M.read()){
                    drv(70, -70);
                }
                drv(0, 0, 1000);
                drv(70, 70, 100);
                CAM.clear();
                return;
            case '3': 
                drv(-70, 70, 1700);
                CAM.clear();
                return;
            case '0':
                drv(70, 70, 500);
                CAM.clear();
                return;
            }
    }
}

void driveOnlyInner(char x){
    if (x == 'L'){
        while(1){
            if (L.read()){
                drv(0, 0, 50);
                return;
            }
            else if (LI.read()){
                drv(-50, 50);
            }
            else if (RI.read()){
                drv(50, -50);
            }
            else {
                drv(50, 50);
            }
        }
    }
    else {
        while(1){
            if (R.read()){
                drv(0, 0, 50);
                return;
            }
            else if (LI.read()){
                drv(-50, 50);
            }
            else if (RI.read()){
                drv(50, -50);
            }
            else {
                drv(50, 50);
            }
        }
    }
}