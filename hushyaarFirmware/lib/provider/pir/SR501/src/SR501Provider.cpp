#include "./SR501Provider.h"

SR501Provider::SR501Provider(){
    SR501Provider::pirPinNumber = 14;
    pinMode(SR501Provider::pirPinNumber, INPUT_PULLDOWN);
};

SR501Provider::SR501Provider(int _pinNumber){
    SR501Provider::pirPinNumber = _pinNumber;
    pinMode(SR501Provider::pirPinNumber, INPUT_PULLDOWN);
};

void SR501Provider::setHasMovmentCallbackMethod(
    PIR_HAS_MOVMENT_CALL_BACK_METHOD onRipHasMovmentCallbackMethod
){
    SR501Provider::_onRipHasMovmentCallbackMethod = onRipHasMovmentCallbackMethod;
}

void SR501Provider::Active(){
    SR501Provider::_isActive = true;
    while (SR501Provider::isActive()){
        bool isMoving = digitalRead(SR501Provider::pirPinNumber);
        if(isMoving){
            SR501Provider::_onRipHasMovmentCallbackMethod();
        }
    }
    
}

void SR501Provider::Deactive(){
    SR501Provider::_isActive = false;
}

bool SR501Provider::isActive(){
    return SR501Provider::_isActive;
}