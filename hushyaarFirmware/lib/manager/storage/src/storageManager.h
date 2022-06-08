#include <WString.h>
#include <functional>


#include "mqttCredentials.h"
#include "wifiCredentials.h"

#define  STORAGE_GET_WIFI_CREDENTAILS_METHOD std::function<WifiCredentials()>

class StorageManager{
    private:
        WifiCredentials _wifiCredentials;
        MqttCredentials _mqttCredentials;
        
    public:
        StorageManager();
        WifiCredentials getWifiCredentials();
        STORAGE_GET_WIFI_CREDENTAILS_METHOD getWifiCredentialsMethod();
        void setMqttCredentilas(MqttCredentials mqttCredentials);
        
};
