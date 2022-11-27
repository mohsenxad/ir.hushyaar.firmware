#include <Adafruit_NeoPixel.h>
#include "pins_arduino.h"
#include <functional>


#define SIREN_FINISHED_CALL_BACK_METHOD std::function<void()>
#define NUMPIXELS 8

class WS2812BProvider{
    private:
        int _rgbPinNumber;
        Adafruit_NeoPixel _pixels;
        SIREN_FINISHED_CALL_BACK_METHOD _onSirenFinishedCallbackMethod;
    public:
        WS2812BProvider();
        WS2812BProvider(int rgbPinNumber);
        void setSirenFinishedCallbackMethod(SIREN_FINISHED_CALL_BACK_METHOD onSirenFinishedCallbackMethod);
        void SirenOn();
        void Off();
        void TorchOn();
};