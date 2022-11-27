
#include "./soundManager.h"

SoundManager::SoundManager(){};

void SoundManager::Beep(){
    SoundManager::buzzerProvider.Beep();
}

void SoundManager::Off(){
    SoundManager::buzzerProvider.Off();
}

void SoundManager::SirenOn(){
    SoundManager::buzzerProvider.SirenOn();
}

void SoundManager::Armed(){
    SoundManager::buzzerProvider.Armed();
}

void SoundManager::BootSucceed(){
    SoundManager::buzzerProvider.BootSucceed();
}