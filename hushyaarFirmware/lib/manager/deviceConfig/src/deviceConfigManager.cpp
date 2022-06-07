#include "deviceConfigManager.h"

void handelGetDeviceConfig(AsyncWebServerRequest *request){
    request->send_P(200, "text/html", DEVICE_CONFIG_PAGE_HTML);
};

DeviceConfigManager::DeviceConfigManager(){
    
}

void DeviceConfigManager::start(){
    DeviceConfigManager::_asyncWebServerProvider.setRoute("/deviceConfig",HTTP_GET,handelGetDeviceConfig);
    DeviceConfigManager::_asyncWebServerProvider.start();
}

void DeviceConfigManager::stop(){
    
}
