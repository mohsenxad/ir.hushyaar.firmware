#include <functional>
#include "../../lib/model/cameraQuality.h"
#include "../../lib/provider/camera/AIThinker/src/aiThinkerCameraProvider.h"

#define  CAMERA_SET_RESOLUTION_SUCCESS_CALL_BACK_METHOD std::function<void()>
#define  CAMERA_SET_RESOLUTION_FAIL_CALL_BACK_METHOD std::function<void()>
#define  CAMERA_CAPTURE_SUCCESS_CALL_BACK_METHOD std::function<void(uint8_t*)>

class CameraManager{
    private:
        bool _isCameraAvailable = false;
        aiThinkerCameraProvider _aiThinkerCameraProvider;
        CAMERA_SET_RESOLUTION_SUCCESS_CALL_BACK_METHOD _onSetResolutionSuccessCallbackMethod;
        CAMERA_SET_RESOLUTION_FAIL_CALL_BACK_METHOD _onSetResolutionFailCallbackMethod;
        CAMERA_CAPTURE_SUCCESS_CALL_BACK_METHOD _onCaptureSucccessCallbacckMethod;
        void onResultionSet();
    public:
        CameraManager();
        CameraManager(
            CAMERA_SET_RESOLUTION_SUCCESS_CALL_BACK_METHOD onSetResolutionSuccessCallbackMethod,
            CAMERA_SET_RESOLUTION_FAIL_CALL_BACK_METHOD onSetResolutionFailCallbackMethod,
            CAMERA_CAPTURE_SUCCESS_CALL_BACK_METHOD onCaptureSucccessCallbacckMethod
        );
        void setResultion(CameraQuality cameraQuality);
        void capture();
        
};