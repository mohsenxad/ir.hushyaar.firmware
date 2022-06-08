#include "httpManager.h"

httpManager::httpManager(){}

httpManager::httpManager(HTTP_MQTT_CREDENTIALS_CALL_BACK_METHOD onMqttCredentialsReceivedCallbackMethod){
    httpManager::_onMqttCredentialsReceivedCallbackMethod = onMqttCredentialsReceivedCallbackMethod;
}

void httpManager::getMqttCredentials(){
    MqttCredentials _mqttCredentials;
    _mqttCredentials.host = "mqtt.hushyaar.ir";
    _mqttCredentials.port = 1773;
    _mqttCredentials.protocol = "mqtt";
    _mqttCredentials.username = "mnasdfkjoiupoasdfkj@#42";
    _mqttCredentials.password = "fasDFASDlkjhasdfAsdfhkj124";
    _mqttCredentials.token = "d7406bde-8100-4af9-b75b-c3e5a811f01d";
    httpManager::_onMqttCredentialsReceivedCallbackMethod(_mqttCredentials);
}

void httpManager::getMqttCredentialsRecived(){

}