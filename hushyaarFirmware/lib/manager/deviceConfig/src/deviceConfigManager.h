#include "../../lib/provider/asyncWebServer/src/asyncWebServerProvider.h"
#include "html/DeviceConfigHtmlPage.h"

class DeviceConfigManager{
    private:
        AsyncWebServerProvider _asyncWebServerProvider;
    public:
        DeviceConfigManager();
        void start();
        void stop();
};