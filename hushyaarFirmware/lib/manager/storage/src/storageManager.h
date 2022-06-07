#include <WString.h>

class StorageManager{
    private:
        String _wifiSsid;
        String _wifiPassword;
    public:
        StorageManager();
        String getWifiSsid();
        void setWifiSsid(String wifiSsid);
        String getWifiPassword();
        void setWifiPassword(String wifiPassword);
        void setWifiCredentials(String wifiSsid , String wifiPassword);
};
