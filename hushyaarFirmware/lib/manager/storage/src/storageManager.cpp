#include "storageManager.h"

StorageManager::StorageManager(){


    StorageManager::_factoryCredentials.manufactureId = "e351aac7-e0af-4418-8671-2b598944dbe2";
    StorageManager::_factoryCredentials.token1 = "token1";
    StorageManager::_factoryCredentials.token2 = "token2";

    StorageManager::_haveFactoryCredentials = true;



    StorageManager::_wifiCredentials.ssid = "xad";
    StorageManager::_wifiCredentials.password = "09122707748";
    // StorageManager::_wifiCredentials.ssid = "koochooloo2";
    // StorageManager::_wifiCredentials.password = "toopooloo999";

    StorageManager::_haveWiFiCredentials = false;

    StorageManager::_isAvailable = true;

    
    
}

FactoryCredentials StorageManager::getFactoryCredentials(){
    return StorageManager::_factoryCredentials; 
}

STORAGE_GET_FACTORY_CREDENTAILS_METHOD StorageManager::getFactoryCredentialsMethod(){
    return [&]() -> FactoryCredentials{
        return StorageManager::getFactoryCredentials();
    };
}

WifiCredentials StorageManager::getWifiCredentials(){
   return StorageManager::_wifiCredentials; 
}

STORAGE_GET_WIFI_CREDENTAILS_METHOD StorageManager::getWifiCredentialsMethod(){
    return [&]() -> WifiCredentials{
        return StorageManager::getWifiCredentials();
    };
}


void StorageManager::setMqttCredentilas(MqttCredentials mqttCredentials){
    StorageManager::_mqttCredentials = mqttCredentials;
}

bool StorageManager::isAvailable(){
    return StorageManager::_isAvailable;
}

bool StorageManager::haveFactoryCredentials(){
    return StorageManager::_haveFactoryCredentials;
}
bool StorageManager::haveWiFiCredentials(){
    return StorageManager::_haveWiFiCredentials;
}

bool StorageManager::haveMqttCredentials(){
    return StorageManager::_haveMqttCredentials;
}