#include "./motionDetectionManager.h"

MotionDetectionManager::MotionDetectionManager(){}

void MotionDetectionManager::setHasMovmentCallbackMethod(
    HAS_MOVMENT_CALL_BACK_METHOD onHasMovmentCallbackMethod
){
    MotionDetectionManager::_onHasMovmentCallbackMethod = onHasMovmentCallbackMethod;
    MotionDetectionManager::_SR501Provider.setHasMovmentCallbackMethod(
        MotionDetectionManager::_onHasMovmentCallbackMethod
    );
}

void MotionDetectionManager::Active(){
    MotionDetectionManager::_SR501Provider.Active();
}

void MotionDetectionManager::Deactive(){
    MotionDetectionManager::_SR501Provider.Deactive();
}

bool MotionDetectionManager::isActive(){
    return MotionDetectionManager::_SR501Provider.isActive();
}