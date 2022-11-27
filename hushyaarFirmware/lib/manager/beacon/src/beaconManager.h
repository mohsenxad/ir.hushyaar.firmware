#include "../../lib/provider/rgb/WS2812B/src/WS2812BProvider.h"

#define BEACON_PIN 13
class BeaconManager{
    private:
        WS2812BProvider _WS2812BProvider = WS2812BProvider(BEACON_PIN);
        bool _isSirenOn;
    public:
        BeaconManager();
        void On();
        void Off();
        void SirenOn();
        void SirenOff();
        void TorchOn();
        bool isSirenOn();
};