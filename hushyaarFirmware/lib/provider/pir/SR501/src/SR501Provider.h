#include "esp32-hal-gpio.h"
#include <functional>

#define  PIR_HAS_MOVMENT_CALL_BACK_METHOD std::function<void()>

class SR501Provider{
    private:
        int pirPinNumber;
        bool _isActive;
        PIR_HAS_MOVMENT_CALL_BACK_METHOD _onRipHasMovmentCallbackMethod;
    public:
        SR501Provider();
        SR501Provider(int _pinNumber);
        void setHasMovmentCallbackMethod(PIR_HAS_MOVMENT_CALL_BACK_METHOD onRipHasMovmentCallbackMethod);
        void Active();
        void Deactive();
        bool isActive();
};