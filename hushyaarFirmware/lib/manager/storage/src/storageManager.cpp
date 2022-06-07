#include "storageManager.h"

StorageManager::StorageManager(){
    //StorageManager::setWifiSsid("xad");
    //StorageManager::setWifiPassword("09122707748");
    StorageManager::setWifiSsid("koochooloo2");
    StorageManager::setWifiPassword("toopooloo999");
}

String StorageManager::getWifiSsid(){
    return StorageManager::_wifiSsid;
}

void StorageManager::setWifiSsid(String wifiSsid){
    StorageManager::_wifiSsid = wifiSsid;
}

String StorageManager::getWifiPassword(){
    return StorageManager::_wifiPassword;
}

void StorageManager::setWifiPassword(String wifiPassword){
    StorageManager::_wifiPassword = wifiPassword;
}

void StorageManager::setWifiCredentials(String wifiSsid , String wifiPassword){
    StorageManager::setWifiSsid(wifiSsid);
    StorageManager::setWifiPassword(wifiPassword);
}