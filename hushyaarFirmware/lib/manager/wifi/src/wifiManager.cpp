#include "wifiManager.h"

WiFiManager::WiFiManager(){

}

WiFiManager::WiFiManager(
    STORAGE_GET_WIFI_SSID getWifiSsidMethod,
    STORAGE_GET_WIFI_PASSWORD getWifiPasswodMethod
){
    WiFiManager::_getWifiSsidMethod = getWifiSsidMethod;
    WiFiManager::_getWifiPasswodMethod = getWifiPasswodMethod;

    WiFiManager::_wifiProvider.getWIFI().onEvent([&](WiFiEvent_t event, WiFiEventInfo_t info){
        Serial.println("Connected To Wifi");
        WiFiManager::_connected = true;
        WiFiManager::_connecting = false;
        this->_onWiFiConnectedCallbackMethod();
    }, SYSTEM_EVENT_STA_CONNECTED);

    WiFiManager::_wifiProvider.getWIFI().onEvent([&](WiFiEvent_t event, WiFiEventInfo_t info){
        Serial.println("Disconnecd From Wifi");
        WiFiManager::_connected = false;
        if(!WiFiManager::_connecting){
            delay(1000);
            WiFiManager::connect();
        }
    }, SYSTEM_EVENT_STA_DISCONNECTED);
}

void WiFiManager::connect(){
    String wifiSsid = WiFiManager::_getWifiSsidMethod();
    String wifiPassword = WiFiManager::_getWifiPasswodMethod();
 

    WiFiManager::_connecting = true;
    WiFiManager::_wifiProvider.getWIFI().begin(wifiSsid.c_str(),wifiPassword.c_str());
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