#include "bootProcees.h"

BootProcess::BootProcess(){

}

void BootProcess::Boot(){
    Serial.println("BootProcess:: Boot Start");
    Serial.println(ESP.getHeapSize());
    Serial.println(ESP.getFreeHeap());
    //Serial.println(ESP.getPsramSize());
    Serial.println(ESP.getFreePsram());
    
    BootProcess::_soundManager.BootSucceed();
    Serial.println("BootProcess:: Boot Finished");
}