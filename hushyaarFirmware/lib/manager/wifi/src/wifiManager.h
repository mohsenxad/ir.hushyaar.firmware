#include "../provider/wifi/src/wifiProvider.h"

#define  STORAGE_GET_WIFI_SSID std::function<String()>
#define  STORAGE_GET_WIFI_PASSWORD std::function<String()>
#define  WIFI_CONNECTED_CALL_BACK_METHOD std::function<void()>



class WiFiManager{
    private:
        WifiProvider _wifiProvider;
        STORAGE_GET_WIFI_SSID _getWifiSsidMethod;
        STORAGE_GET_WIFI_PASSWORD _getWifiPasswodMethod;
        WIFI_CONNECTED_CALL_BACK_METHOD _onWiFiConnectedCallbackMethod;
        bool _connected;
        bool _connecting;
        //wiFiConnectedCallbackMethod _onWiFiConnectedCallbackMethod;
        //void WiFiStationConnected(system_event_t *sys_event, wifi_prov_event_t *prov_event);
    public:
        WiFiManager();
        WiFiManager(
            STORAGE_GET_WIFI_SSID getWifiSsidMethod,
            STORAGE_GET_WIFI_PASSWORD getWifiPasswodMethod
        );
        void setOnWifiConnectedCallbackMethod(WIFI_CONNECTED_CALL_BACK_METHOD _onWiFiConnectedCallbackMethod);
        //WiFiManager(String (*getWifiSsidMethod)(), String (*getWifiPasswodMethod)());
        void connect();
        void getSsidList();
        bool isConnected();
        bool isConnecting();

};