#include "armedProcess.h"

typedef void (*TaskFunction_t)( void * );

ArmedProcess::ArmedProcess(){
    Serial.println("ArmedProcess:: ArmedProcess initization");
}

void ArmedProcess::taskSoundSirinOn(void *pvParameters){
  (void) pvParameters;
  ArmedProcess::_soundManager.SirenOn();
}

void ArmedProcess::taskPirScanning(void *pvParameters){
  (void) pvParameters;
  ArmedProcess::_motionDetectionManager.Active();
}

void ArmedProcess::Start(){
    Serial.println("ArmedProcess:: Start Start");
    ArmedProcess::_beaconManager.Off();
    ArmedProcess::_motionDetectionManager.setHasMovmentCallbackMethod(
        [&](){
            Serial.println("ArmedProcess:: ArmedProcess setHasMovmentCallbackMethod call");

            // if(ArmedProcess::_beaconManager.)
            
            // static TaskHandle_t sound_task = NULL;
            // xTaskCreatePinnedToCore(
            //     this->taskSoundSirinOn
            //     ,  "Request Token from the server"
            //     ,  1024  // Stack size
            //     ,  NULL
            //     ,  2  // Priority
            //     ,  &sound_task 
            //     ,  1
            // );

            // static TaskHandle_t beacon_task = NULL;
            // xTaskCreatePinnedToCore(
            //     [&](void *pvParameters) {
            //         Serial.println("ArmedProcess:: ArmedProcess Sound");
            //     }
            //     ,  "Request Token from the server"
            //     ,  1024  // Stack size
            //     ,  NULL
            //     ,  2  // Priority
            //     ,  &sound_task 
            //     ,  1
            // );
            ArmedProcess::_beaconManager.SirenOn();
            ArmedProcess::_soundManager.SirenOn();
        }
    );

    

    //static TaskHandle_t pir_scanning_task = NULL;
    // xTaskCreatePinnedToCore(
    //     this->taskPirScanning
    //     ,  "taskPirScanning"
    //     ,  1024  // Stack size
    //     ,  NULL
    //     ,  2  // Priority
    //     ,  &pir_scanning_task 
    //     ,  1
    // );
    ArmedProcess::_motionDetectionManager.Active();
    ArmedProcess::_soundManager.Armed();
    Serial.println("ArmedProcess:: Start End");
}
