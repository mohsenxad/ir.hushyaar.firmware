#include <WString.h>
#include <functional>


#include "../model/mqttCredentials.h"
#include "../model/wifiCredentials.h"
#include "../model/factoryCredentials.h"

#define  EEPROM_SIZE 120
#define  STORAGE_GET_WIFI_CREDENTAILS_METHOD std::function<WifiCredentials()>
#define  STORAGE_GET_FACTORY_CREDENTAILS_METHOD std::function<FactoryCredentials()>

class StorageManager{
    private:
        bool _isAvailable;
        bool _haveFactoryCredentials;
        bool _haveWiFiCredentials;
        bool _haveMqttCredentials;
        FactoryCredentials _factoryCredentials;
        WifiCredentials _wifiCredentials;
        MqttCredentials _mqttCredentials;
        
    public:
        StorageManager();
        FactoryCredentials getFactoryCredentials();
        STORAGE_GET_FACTORY_CREDENTAILS_METHOD getFactoryCredentialsMethod();
        WifiCredentials getWifiCredentials();
        STORAGE_GET_WIFI_CREDENTAILS_METHOD getWifiCredentialsMethod();
        void setMqttCredentilas(MqttCredentials mqttCredentials);
        bool isAvailable();
        bool haveFactoryCredentials();
        bool haveWiFiCredentials();
        bool haveMqttCredentials();
        
};
