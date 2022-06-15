#ifndef MQTTCREDENTIALS_H
#define MQTTCREDENTIALS_H

#include "WString.h"

struct MqttCredentials{
    String host;
    int port;
    String protocol;
    String username;
    String password;
    String token;
};
#endif