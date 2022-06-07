#include "../../../provider/asyncWebServer/src/asyncWebServerProvider.h"
#include "html/WiFiConfigHtmlPage.h"

#define  WIFI_CONFIGURED_CALLBACK_SIGNATURE std::function<void(String ssid, String password)>

class WiFiConfigManager{
    private:
        AsyncWebServerProvider _asyncWebServerProvider;
        void handelPostWiFiConfig(AsyncWebServerRequest *request);
        WIFI_CONFIGURED_CALLBACK_SIGNATURE _wifiConfiguredCallback;
    public:
        WiFiConfigManager();
        WiFiConfigManager(WIFI_CONFIGURED_CALLBACK_SIGNATURE wifiConfiguredCallback);
        void start();
        void stop();
};