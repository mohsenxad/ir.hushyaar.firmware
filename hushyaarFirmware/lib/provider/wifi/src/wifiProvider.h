#include <WiFi.h>

class WifiProvider{
    private:
        WiFiClass WIFI;
    public:
        WifiProvider();
        WiFiClass getWIFI();
};