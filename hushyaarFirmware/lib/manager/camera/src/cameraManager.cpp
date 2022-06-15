#include "cameraManager.h"

CameraManager::CameraManager(){}

CameraManager::CameraManager
(
    CAMERA_SET_RESOLUTION_SUCCESS_CALL_BACK_METHOD onSetResolutionSuccessCallbackMethod,
    CAMERA_SET_RESOLUTION_FAIL_CALL_BACK_METHOD onSetResolutionFailCallbackMethod,
    CAMERA_CAPTURE_SUCCESS_CALL_BACK_METHOD onCaptureSucccessCallbacckMethod
){
    CameraManager::_onSetResolutionSuccessCallbackMethod = onSetResolutionSuccessCallbackMethod;
    CameraManager::_onSetResolutionFailCallbackMethod = onSetResolutionFailCallbackMethod;
    CameraManager::_onCaptureSucccessCallbacckMethod = onCaptureSucccessCallbacckMethod;

    CameraManager::_aiThinkerCameraProvider.setSetResultionCallBackMethods(
        CameraManager::_onSetResolutionSuccessCallbackMethod,
        CameraManager::_onSetResolutionFailCallbackMethod,
        CameraManager::_onCaptureSucccessCallbacckMethod
    );
}

void CameraManager::setResultion(CameraQuality cameraQuality){
    CameraManager::_aiThinkerCameraProvider.setResultion(cameraQuality);
}

void CameraManager::onResultionSet(){
    CameraManager::_onSetResolutionSuccessCallbackMethod();
}

void CameraManager::capture(){

}
