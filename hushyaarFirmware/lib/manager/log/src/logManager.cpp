#include "logManager.h"

const char* BOOT_SUCCESSED_MESSAGE = "boot succeed!";

LogManager::LogManager(){
    
}

void LogManager::bootSuccessed(){
    _hardwareProvider.print("boot succeed!");
}

void LogManager::postSsidPassword(String ssid, String password){
    char* message = "ssid password set \n ssid: ";
    _hardwareProvider.print(message);
}

void LogManager::wifiConnected(){
    char* message = "LogManager:: WiFi connected!";
    _hardwareProvider.print(message);
}

void LogManager::debug(char* message){
    _hardwareProvider.print(message);
}

void LogManager::debug(String message){
    _hardwareProvider.print(message);
}
