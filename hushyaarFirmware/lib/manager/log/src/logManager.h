#include "../provider/hardwareSerial/src/hardwareSerialProvider.h"


class LogManager{
    private:
        HardwareSerialProvider _hardwareProvider;
    public:
        LogManager();
        void bootSuccessed();
        void postSsidPassword(String ssid, String password);
        void wifiConnected();
        void debug(char* message);
        void debug(String message);
};