


#include <Arduino.h>
#include <functional>
#include <FreeRTOS.h>


// #include "../lib/manager/deviceConfig/src/deviceConfigManager.h"
// #include "../lib/manager/wifiConfig/src/wifiConfigManager.h"
// #include "../lib/manager/bluetooth/src/bluetoothManager.h"
#include "../lib/manager/log/src/logManager.h"
#include "../lib/manager/storage/src/storageManager.h"
#include "../lib/manager/wifi/src/wifiManager.h"

// how to remove this from main.cpp and move to providers
#include <AsyncTCP.h>
#include "ESPAsyncWebServer.h"
#include <WiFi.h>

// #define  STORAGE_GET_WIFI_SSID std::function<String()>
// #define  STORAGE_GET_WIFI_PASSWORD std::function<String()>
// #define  WIFI_CONNECTED_CALL_BACK_METHOD std::function<void(WiFiEvent_t event, WiFiEventInfo_t info)>



LogManager _logManager;
StorageManager _storageManager;

String getWifiSsid(){
  return _storageManager.getWifiSsid();
}


String getWifiPassword(){
  return _storageManager.getWifiPassword();
}

WiFiManager _wifiManager(getWifiSsid, getWifiPassword);
// // void setupCustomerWebServer(){
// //   DeviceConfigManager _deviceConfigManager;  
// //   _deviceConfigManager.start();
// // }

// void onWiFiConfigured(String ssid, String password){
//   _logManager.postSsidPassword(ssid, password);
// }

// // void setupWiFiConfigWebServer(void *pvParameters){
// //   WiFiConfigManager _wiFiConfigManager(onWiFiConfigured);  
// //   _wiFiConfigManager.start();
// // }

// void startBLE(){
//   BluetoothManager _bluetoothManager("Night");
//   _bluetoothManager.start();
// }





void WiFiStationConnected()
{
  _logManager.debug("Main:: WiFi connected in Call Back");
  _logManager.wifiConnected();
}

void connectToWifi(){
  _logManager.debug("Main:: Start Connecting Process");
  _wifiManager.setOnWifiConnectedCallbackMethod(WiFiStationConnected);
  _wifiManager.connect();
}


void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  //setupCustomerWebServer();
  //setupWiFiConfigWebServer();
  // startBLE();
  connectToWifi();
}



void loop(){}



