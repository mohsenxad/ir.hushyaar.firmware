#include "ESPAsyncWebServer.h"
#include "../../wifi/src/wifiProvider.h"

class AsyncWebServerProvider{
    private:
        WifiProvider _wifiProvider;
        AsyncWebServer *_server = new AsyncWebServer(80);
    public:
        AsyncWebServerProvider();
        void setRoute(const char* uri, WebRequestMethodComposite method, ArRequestHandlerFunction onRequest);
        void start();
};