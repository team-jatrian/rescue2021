#include "cam.hpp"

String buffer = ""; 
char opcode = '0';

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
        switch(camReceive()){
            case '1':
                driveOnlyInner('L');
                drv(50, 50, 300);  
                /*while(L.read()){
                    drv(50, 50);
                }*/
                drv(-70, 70, 400);
                while(!M.read()){
                    drv(-70, 70);
                }
                drv(70, 70, 200);
                CAM.clear();
                return;
            case '2':
                driveOnlyInner('R');
                drv(50, 50, 300);
                /*while(R.read()){
                    drv(50, 50);
                } */
                drv(70, -70, 300);
                while(!M.read()){
                    drv(70, -70);
                }
                drv(70, 70, 200);
                CAM.clear();
                return;
            case '3': 
                drv(-70, 70, 1500);
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

void driveOnlyInner(char x){
    if (x == 'L'){
        while(1){
            if (L.read()){
                drv(0, 0, 50);
                return;
            }
            else if (LI.read() && !RI.read()){
                drv(-50, 50);
            }
            else if (RI.read() && !LI.read()){
                drv(50, -50);
            }
            else {
                drv(50, 50);
            }
        }
    }
    else if (x == 'R') {
        while(1){
            if (R.read()){
                drv(0, 0, 50);
                return;
            }
            else if (LI.read() && !RI.read()){
                drv(-50, 50);
            }
            else if (RI.read() && !LI.read()){
                drv(50, -50);
            }
            else {
                drv(50, 50);
            }
        }
    }
    else {
        while(1){
            if (R.read() || L.read()){
                drv(0, 0, 50);
                return;
            }
            else if (LI.read() && !RI.read()){
                drv(-50, 50);
            }
            else if (RI.read() && !LI.read()){
                drv(50, -50);
            }
            else {
                drv(50, 50);
            }
        }
    }
}