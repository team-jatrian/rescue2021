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
        CAM.clear();
        switch(camReceive()){
            case '1':
                driveOnlyInner('L');
                drv(50, 50, 300);  
                driveDegrees(-80);
                drv(70, 70, 200);
                CAM.clear();
                return;
            case '2':
                driveOnlyInner('R');
                drv(50, 50, 300);
                driveDegrees(80);
                drv(70, 70, 200);
                CAM.clear();
                return;
            case '3': 
                driveDegrees(180);
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
