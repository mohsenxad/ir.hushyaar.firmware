#include "wifiManager.h"

WiFiManager::WiFiManager(){

}

WiFiManager::WiFiManager(
    STORAGE_GET_WIFI_CREDENTAILS_METHOD getWifiCredentialsMethod
){
    WiFiManager::_getWifiCredentialsMethod = getWifiCredentialsMethod;

    WiFiManager::_wifiProvider.getWIFI().onEvent([&](WiFiEvent_t event, WiFiEventInfo_t info){
        Serial.println("Connected To Wifi");
        WiFiManager::_connected = true;
        WiFiManager::_connecting = false;
        WiFiManager::_lastConnectionAttempError = NO_ERROR;
    }, SYSTEM_EVENT_STA_CONNECTED);

    WiFiManager::_wifiProvider.getWIFI().onEvent([&](WiFiEvent_t event, WiFiEventInfo_t info){
        Serial.println("Got IP");
        Serial.println(_wifiProvider.getWIFI().localIP());
        Serial.println(_wifiProvider.getWIFI().macAddress());
        this->_onWiFiConnectedCallbackMethod();
    }, SYSTEM_EVENT_STA_GOT_IP);


    WiFiManager::_wifiProvider.getWIFI().onEvent([&](WiFiEvent_t event, WiFiEventInfo_t info){
        Serial.println("Disconnecd From Wifi");
        WiFiManager::_connected = false;
        
        if(info.disconnected.reason == 201){
            //WIFI_REASON_NO_AP_FOUND = 201,
            Serial.println("SSID Not Found");
            WiFiManager::_lastConnectionAttempError = SSID_NOT_FOUND;
        }else if(info.disconnected.reason == 2){
             //WIFI_REASON_AUTH_EXPIRE = 2,
            Serial.println("Invalid Password");
            WiFiManager::_lastConnectionAttempError = PASSWORD_INCORECT;
        }else{
            Serial.println("Unknown error");
            Serial.println(info.disconnected.reason);
            WiFiManager::_lastConnectionAttempError = UNKNOWN;
        }

        if(!WiFiManager::_connecting){
            delay(1000);
            WiFiManager::connect();
        }

    }, SYSTEM_EVENT_STA_DISCONNECTED);
}

void WiFiManager::connect(){
    WiFiManager::_connected = false;
    WiFiManager::_connecting = true;
    WiFiManager::_wifiProvider.getWIFI().begin(
        WiFiManager::_getWifiCredentialsMethod().ssid.c_str(),
        WiFiManager::_getWifiCredentialsMethod().password.c_str()
    );
}

void WiFiManager::setOnWifiConnectedCallbackMethod(WIFI_CONNECTED_CALL_BACK_METHOD _onWiFiConnectedCallbackMethod){
    WiFiManager::_onWiFiConnectedCallbackMethod = _onWiFiConnectedCallbackMethod;
}

bool WiFiManager::isConnected(){
    return WiFiManager::_connected;
}

bool WiFiManager::isConnecting(){
    return WiFiManager::_connecting;
}