#include <Arduino.h>
#include "../../lib/manager/wifiConfig/src/wifiConfigManager.h"
#include <functional>


class SetupWifiWebserviceProcess{
    private:
        void onWiFiConfigured(String ssid, String password);
    public:
        SetupWifiWebserviceProcess();
};