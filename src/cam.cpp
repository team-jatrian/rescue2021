#include "cam.hpp"

String buffer = "";
char opcode = '0';

void centerOnLine(){
    int32_t lineValue = readString().toInt();
    if (lineValue < 0){
        drv(70, -70);
    }
    else if (lineValue > 0){
        drv(-70, 70);
    }
    else {
        drv(0, 0);
    }
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