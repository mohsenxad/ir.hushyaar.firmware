#include <functional>
#include "../model/mqttCredentials.h"

#define  HTTP_MQTT_CREDENTIALS_CALL_BACK_METHOD std::function<void(MqttCredentials)>

class httpManager{
    private:
       HTTP_MQTT_CREDENTIALS_CALL_BACK_METHOD _onMqttCredentialsReceivedCallbackMethod;
       void getMqttCredentialsRecived();
    public:
        httpManager();
        httpManager(HTTP_MQTT_CREDENTIALS_CALL_BACK_METHOD onMqttCredentialsReceivedCallbackMethod);
        
        void getMqttCredentials();
};