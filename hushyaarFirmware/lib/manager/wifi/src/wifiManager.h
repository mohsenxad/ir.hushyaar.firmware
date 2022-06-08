#include "../provider/wifi/src/wifiProvider.h"
#include "wifiCredentials.h"

#define  STORAGE_GET_WIFI_CREDENTAILS_METHOD std::function<WifiCredentials()>
#define  STORAGE_GET_WIFI_PASSWORD std::function<String()>
#define  WIFI_CONNECTED_CALL_BACK_METHOD std::function<void()>



class WiFiManager{
    private:
        WifiProvider _wifiProvider;
        STORAGE_GET_WIFI_CREDENTAILS_METHOD _getWifiCredentialsMethod;
        WIFI_CONNECTED_CALL_BACK_METHOD _onWiFiConnectedCallbackMethod;
        bool _connected;
        bool _connecting;
    public:
        WiFiManager();
        WiFiManager(
            STORAGE_GET_WIFI_CREDENTAILS_METHOD getWifiCredentialsMethod
        );
        void setOnWifiConnectedCallbackMethod(
            WIFI_CONNECTED_CALL_BACK_METHOD _onWiFiConnectedCallbackMethod
        );
        void connect();
        void getSsidList();
        bool isConnected();
        bool isConnecting();

};