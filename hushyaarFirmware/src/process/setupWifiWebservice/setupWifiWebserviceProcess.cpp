#include "setupWifiWebserviceProcess.h"

void SetupWifiWebserviceProcess::onWiFiConfigured(String ssid, String password){
  Serial.println("SetupWifiWebserviceProcess:: onWiFiConfigured");
}


SetupWifiWebserviceProcess::SetupWifiWebserviceProcess(){
    Serial.println("SetupWifiWebserviceProcess:: setupWiFiConfigWebServer");
    WiFiConfigManager _wiFiConfigManager([&](String ssid, String password){
        SetupWifiWebserviceProcess::onWiFiConfigured(ssid, password);
    });  
    _wiFiConfigManager.start();
}

