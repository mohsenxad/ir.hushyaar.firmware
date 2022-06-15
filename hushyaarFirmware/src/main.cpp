#include <Arduino.h>
#include <functional>
#include <FreeRTOS.h>



#include "../lib/manager/log/src/logManager.h"
#include "../lib/manager/storage/src/storageManager.h"
#include "../lib/manager/wifi/src/wifiManager.h"
#include "../lib/manager/http/src/httpManager.h"
#include "../lib/manager/camera/src/cameraManager.h"


#include "./process/setupFactoryWebservice/setupFactoryWebserviceProcess.h"
#include "./process/setupWifiWebservice/setupWifiWebserviceProcess.h"

// how to remove this from main.cpp and move to providers
#include <AsyncTCP.h>
#include "ESPAsyncWebServer.h"


LogManager _logManager;
StorageManager _storageManager;



WiFiManager _wifiManager(_storageManager.getWifiCredentialsMethod());

// void startBLE(){
//   BluetoothManager _bluetoothManager("Night");
//   _bluetoothManager.start();
// }







void MqttCredentilasReceived(MqttCredentials _mqttCredentials){
  //_logManager.debug(_mqttCredentials);
  _logManager.debug("Main:: Mqtt Credentilas Received in Call Back");
  _storageManager.setMqttCredentilas(_mqttCredentials);
}


httpManager _httpManager(MqttCredentilasReceived);

void WiFiStationConnected()
{
  _logManager.debug("Main:: WiFi connected in Call Back");
  _logManager.wifiConnected();
  _httpManager.getMqttCredentials();
}

void connectToWifi(){
  _logManager.debug("Main:: Start Connecting Process");
  _wifiManager.setOnWifiConnectedCallbackMethod(WiFiStationConnected);
  _wifiManager.connect();
}

void checkIsStorageAvaliable(){
  if(_storageManager.isAvailable()){
    if(!_storageManager.haveFactoryCredentials()){
      SetupFactoryWebserviceProcess _setupFactoryWebserviceProcess;
    }else if(!_storageManager.haveWiFiCredentials()){
      SetupWifiWebserviceProcess _setupWifiWebserviceProcess;
    }else{
      // try to connect to wifi
      connectToWifi();
    }
  }else{
    //processBootFailOnMemoryUnabalable();
  }
}

void CameraSetResolutionSuccess(){
  Serial.println("Main:: setResultion Success");
  _logManager.debug("Main:: Camera Set Resulution Success");
  checkIsStorageAvaliable();
}

void CameraSetResolutionFaile(){
  Serial.println("Main:: setResultion Faile");
  _logManager.debug("Main:: Camera Set Resulution Failed");
  //have to be remove after camera issue fix
  checkIsStorageAvaliable();
  
}



void CameraCaptured(uint8_t* imageData){
  Serial.println("Main:: Camera Captured Succeed");
  _logManager.debug("Main:: Camera Main:: Camera Captured Succeed");
}

CameraManager _cameraManager(CameraSetResolutionSuccess, CameraSetResolutionFaile, CameraCaptured);




void boot(){
  _cameraManager.setResultion(CAMERA_QUALITY_GOOD);
}

void setup() {
  Serial.begin(115200);
  Serial.println(ESP.getHeapSize());
  Serial.println(ESP.getFreeHeap());
  //Serial.println(ESP.getPsramSize());
  Serial.println(ESP.getFreePsram());
  delay(3000);
  // put your setup code here, to run once:
  //setupCustomerWebServer();
  //setupWiFiConfigWebServer();
  // startBLE();
  
  boot();
  
}



void loop(){
  //delay(2000);
  //_cameraManager.capture();
}



