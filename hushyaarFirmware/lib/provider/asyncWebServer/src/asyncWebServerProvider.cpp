#include "asyncWebServerProvider.h"

AsyncWebServerProvider::AsyncWebServerProvider(){
    AsyncWebServerProvider::_wifiProvider.getWIFI().softAP("hushyaar");
}


void AsyncWebServerProvider::setRoute(const char* uri, WebRequestMethodComposite method, ArRequestHandlerFunction onRequest){
    AsyncWebServerProvider::_server->on(uri,method, onRequest);
}

void AsyncWebServerProvider::start(){
    AsyncWebServerProvider::_server->begin();
}