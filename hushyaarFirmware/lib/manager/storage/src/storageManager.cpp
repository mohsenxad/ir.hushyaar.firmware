#include "storageManager.h"

StorageManager::StorageManager(){
    // StorageManager::_wifiCredentials.set("xad","09122707748");
    // StorageManager::_wifiCredentials.set("koochooloo2","toopooloo999");

    StorageManager::_wifiCredentials.ssid = "xad";
    StorageManager::_wifiCredentials.password = "09122707748";

    // StorageManager::_wifiCredentials.ssid = "koochooloo2";
    // StorageManager::_wifiCredentials.password = "toopooloo999";
    
}

WifiCredentials StorageManager::getWifiCredentials(){
   return StorageManager::_wifiCredentials; 
}

STORAGE_GET_WIFI_CREDENTAILS_METHOD StorageManager::getWifiCredentialsMethod(){
    return [&]() -> WifiCredentials
    {
        return StorageManager::getWifiCredentials();
    };
}


void StorageManager::setMqttCredentilas(MqttCredentials mqttCredentials){
    StorageManager::_mqttCredentials = mqttCredentials;
}