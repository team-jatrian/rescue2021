#include "cam.hpp"

String buffer = "";
char opcode = '0';

void centerOnLine(){
    //spn(opcode);
}

String readString(){
    while(1){
        char opcode = '0';
        if (CAM.available() > 0){
            opcode = CAM.read();
            if (opcode == '\n'){
                buffer = "";
                opcode = '0';
                return buffer;
            }
            buffer += opcode;
        }
    }
}