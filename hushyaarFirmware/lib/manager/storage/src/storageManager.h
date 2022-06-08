#include <WString.h>
#include <functional>


#include "mqttCredentials/mqttCredentials.h"
#include "wifiCredentials/wifiCredentials.h"

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
