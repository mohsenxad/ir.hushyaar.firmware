#include "hardwareSerialProvider.h"

HardwareSerialProvider::HardwareSerialProvider(){
    Serial.begin(115200);
}

void HardwareSerialProvider::print(char* message){
    Serial.println(message);
}

void HardwareSerialProvider::print(String message){
    Serial.printf(message.c_str());
}