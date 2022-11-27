#include "beaconManager.h"

BeaconManager::BeaconManager(){
    BeaconManager::_WS2812BProvider.setSirenFinishedCallbackMethod(
        [&](){
            BeaconManager::SirenOff();
        }
    );
}

void BeaconManager::On(){

}

void BeaconManager::Off(){
    Serial.println("BeaconManager: Off | Start");
    BeaconManager::_WS2812BProvider.Off();
    Serial.println("BeaconManager: Off | End");
}

void BeaconManager::SirenOn(){
    Serial.println("BeaconManager: SirenOn | Start");
    BeaconManager::_isSirenOn = true;
    BeaconManager::_WS2812BProvider.SirenOn();
    Serial.println("BeaconManager: SirenOn | End");
}

void BeaconManager::SirenOff(){
    BeaconManager::_isSirenOn = false;
    BeaconManager::_WS2812BProvider.Off();
}

void BeaconManager::TorchOn(){
    BeaconManager::_WS2812BProvider.TorchOn();
}

bool BeaconManager::isSirenOn(){
    return BeaconManager::_isSirenOn;
}
