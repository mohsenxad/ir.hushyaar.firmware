#include "wifiConfigManager.h"

void handelGetWiFiConfig(AsyncWebServerRequest *request){
    request->send_P(200, "text/html", WiFiConfigHtmlPage);
};

void WiFiConfigManager::handelPostWiFiConfig(AsyncWebServerRequest *request){
    String message;
    String _ssid;
    String _password;
    if (request->hasParam("ssid", true)) {
        _ssid = request->getParam("ssid", true)->value();
    } else {
        message = "No message sent";
    }

    if (request->hasParam("password", true)) {
        _password = request->getParam("password", true)->value();
    }
    request->send(200, "text/plain", "Hello, POST\n ssid:" + _ssid + " password: " + _password);
};

WiFiConfigManager::WiFiConfigManager(){

}

WiFiConfigManager::WiFiConfigManager(WIFI_CONFIGURED_CALLBACK_SIGNATURE wifiConfiguredCallback){
    _wifiConfiguredCallback = wifiConfiguredCallback;
}

void WiFiConfigManager::start(){
    WiFiConfigManager::_asyncWebServerProvider.setRoute("/wifiConfig",HTTP_GET,handelGetWiFiConfig);
    WiFiConfigManager::_asyncWebServerProvider.setRoute("/wifiConfig",HTTP_POST, [&](AsyncWebServerRequest *request){
        WiFiConfigManager::_wifiConfiguredCallback("asdf", "asdfdsfds");
        //WiFiConfigManager::handelPostWiFiConfig(request);
    });
    WiFiConfigManager::_asyncWebServerProvider.start();
}

void WiFiConfigManager::stop(){
    
}