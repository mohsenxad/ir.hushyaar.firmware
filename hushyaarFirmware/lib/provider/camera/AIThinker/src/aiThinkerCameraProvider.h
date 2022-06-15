#include <Arduino.h>
#include <functional>
#include "pins_arduino.h"
#include "esp_camera.h"
#include "../../../../model/cameraQuality.h"

#define  CAMERA_SET_RESOLUTION_SUCCESS_CALL_BACK_METHOD std::function<void()>
#define  CAMERA_SET_RESOLUTION_FAIL_CALL_BACK_METHOD std::function<void()>
#define  CAMERA_CAPTURE_SUCCESS_CALL_BACK_METHOD std::function<void(uint8_t*)>

// CAMERA_MODEL_AI_THINKER
#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27

#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22

class aiThinkerCameraProvider{
    private:
        bool _isInit  = false;
        void init();
        CAMERA_SET_RESOLUTION_SUCCESS_CALL_BACK_METHOD _onSetResolutionSuccessCallbackMethod;
        CAMERA_SET_RESOLUTION_FAIL_CALL_BACK_METHOD _onSetResolutionFailCallbackMethod;
        CAMERA_CAPTURE_SUCCESS_CALL_BACK_METHOD _onCaptureSucccessCallbacckMethod;
    public:
        aiThinkerCameraProvider();
        void setResultion(CameraQuality cameraQuality);
        void setSetResultionCallBackMethods(
            CAMERA_SET_RESOLUTION_SUCCESS_CALL_BACK_METHOD onSetResolutionSuccessCallbackMethod,
            CAMERA_SET_RESOLUTION_FAIL_CALL_BACK_METHOD onSetResolutionFailCallbackMethod,
            CAMERA_CAPTURE_SUCCESS_CALL_BACK_METHOD onCaptureSucccessCallbacckMethod
        );
        
        void capture();

};