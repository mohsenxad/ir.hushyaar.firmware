#include "setupFactoryWebserviceProcess.h"

SetupFactoryWebserviceProcess::SetupFactoryWebserviceProcess(){
    Serial.println("SetupFactoryWebserviceProcess:: SetupFactoryWebserviceProcess initization");
    DeviceConfigManager _deviceConfigManager;  
    _deviceConfigManager.start();
}