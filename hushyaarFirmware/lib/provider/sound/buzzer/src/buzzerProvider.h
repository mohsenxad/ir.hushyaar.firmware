#include "esp32-hal-gpio.h"

class BuzzerProvider{
    private:
        int buzzerPin;
        void On();
    public:
        BuzzerProvider();
        BuzzerProvider(int _buzzerPin);
        void Beep();
        void SirenOn();
        void Armed();
        void BootSucceed();
        void Off();
};