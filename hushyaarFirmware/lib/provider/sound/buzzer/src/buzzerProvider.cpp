#include "./buzzerProvider.h"
// int BuzzerProvider::buzzerPin = 13;

BuzzerProvider::BuzzerProvider(){
    BuzzerProvider::buzzerPin = 13;
    pinMode(BuzzerProvider::buzzerPin,OUTPUT);
    digitalWrite(BuzzerProvider::buzzerPin,LOW);
    
};

BuzzerProvider::BuzzerProvider(int _buzzerPin){
    BuzzerProvider::buzzerPin = _buzzerPin;
    pinMode(BuzzerProvider::buzzerPin,OUTPUT);
    digitalWrite(BuzzerProvider::buzzerPin,LOW);
}

void BuzzerProvider::Beep(){
    BuzzerProvider::On();
    vTaskDelay(700);
    BuzzerProvider::Off();
}

void BuzzerProvider::On(){
    digitalWrite(BuzzerProvider::buzzerPin,HIGH);
}

void BuzzerProvider::Off(){
    digitalWrite(BuzzerProvider::buzzerPin,LOW);
}

void BuzzerProvider::SirenOn(){

    for ( int duty_cycle = 10; duty_cycle < 15; duty_cycle++ ){
        BuzzerProvider::On();
        vTaskDelay(2000);
        BuzzerProvider::Off();
        vTaskDelay(1000);
    }
    

    BuzzerProvider::Off();
}

void BuzzerProvider::BootSucceed(){
    BuzzerProvider::On();
    vTaskDelay(700);
    BuzzerProvider::Off();
    vTaskDelay(100);
    BuzzerProvider::On();
    vTaskDelay(300);
    BuzzerProvider::Off();
}

void BuzzerProvider::Armed(){
    BuzzerProvider::On();
    vTaskDelay(200);
    BuzzerProvider::Off();
    vTaskDelay(50);
    BuzzerProvider::On();
    vTaskDelay(200);
    BuzzerProvider::Off();
}
