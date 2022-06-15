#ifndef WIFIPROVIDER_H
#define WIFIPROVIDER_H

#include <WiFi.h>

class WifiProvider{
    private:
        WiFiClass WIFI;
    public:
        WifiProvider();
        WiFiClass getWIFI();
};
#endif