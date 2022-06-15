#include "aiThinkerCameraProvider.h"

aiThinkerCameraProvider::aiThinkerCameraProvider(){}

void aiThinkerCameraProvider::setSetResultionCallBackMethods(
    CAMERA_SET_RESOLUTION_SUCCESS_CALL_BACK_METHOD onSetResolutionSuccessCallbackMethod,
    CAMERA_SET_RESOLUTION_FAIL_CALL_BACK_METHOD onSetResolutionFailCallbackMethod,
    CAMERA_CAPTURE_SUCCESS_CALL_BACK_METHOD onCaptureSucccessCallbacckMethod
){
    aiThinkerCameraProvider::_onSetResolutionSuccessCallbackMethod = onSetResolutionSuccessCallbackMethod;
    aiThinkerCameraProvider::_onSetResolutionFailCallbackMethod = onSetResolutionFailCallbackMethod;
    aiThinkerCameraProvider::_onCaptureSucccessCallbacckMethod = onCaptureSucccessCallbacckMethod;

    // while (!aiThinkerCameraProvider::_isInit){
    //     vTaskDelay(10000);
    //     Serial.println("try To Init");
    //     aiThinkerCameraProvider::init();
    // }
}

void aiThinkerCameraProvider::setResultion(CameraQuality cameraQuality){
    framesize_t quality;

    switch (cameraQuality){
        case CAMERA_QUALITY_VERY_LOW:  quality = FRAMESIZE_QQVGA;   break;
        case CAMERA_QUALITY_LOW:  quality = FRAMESIZE_QCIF;    break;
        case CAMERA_QUALITY_GOOD:  quality = FRAMESIZE_HQVGA;   break;
        case CAMERA_QUALITY_VERY_GOOD:  quality = FRAMESIZE_QVGA;    break;
        case CAMERA_QUALITY_LIGH:  quality = FRAMESIZE_CIF;     break;
        case CAMERA_QUALITY_VERY_LIGH:  quality = FRAMESIZE_VGA;     break;
        case CAMERA_QUALITY_PERFECT:  quality = FRAMESIZE_SVGA;    break;
        case CAMERA_QUALITY_MAX:  quality = FRAMESIZE_XGA;     break;
        
        default: quality = FRAMESIZE_XGA;     break;
    }
    
    sensor_t* sensor = esp_camera_sensor_get();

    if (sensor == nullptr) 
    {
        aiThinkerCameraProvider::_onSetResolutionFailCallbackMethod();
    }else{
        sensor->set_quality(sensor,quality);
        if(sensor->set_framesize(sensor,quality)!=0){
            aiThinkerCameraProvider::_onSetResolutionFailCallbackMethod();
        }else{
            aiThinkerCameraProvider::_onSetResolutionSuccessCallbackMethod();
        }
    }
   
}

void aiThinkerCameraProvider::init(){
    sensor_t* sensor = esp_camera_sensor_get();
    if (sensor == nullptr){
         Serial.println("sensor found");
    }
    camera_config_t config;
    config.ledc_channel = LEDC_CHANNEL_0;
    config.ledc_timer = LEDC_TIMER_0;
    config.pin_d0 = Y2_GPIO_NUM;
    config.pin_d1 = Y3_GPIO_NUM;
    config.pin_d2 = Y4_GPIO_NUM;
    config.pin_d3 = Y5_GPIO_NUM;
    config.pin_d4 = Y6_GPIO_NUM;
    config.pin_d5 = Y7_GPIO_NUM;
    config.pin_d6 = Y8_GPIO_NUM;
    config.pin_d7 = Y9_GPIO_NUM;
    config.pin_xclk = XCLK_GPIO_NUM;
    config.pin_pclk = PCLK_GPIO_NUM;
    config.pin_vsync = VSYNC_GPIO_NUM;
    config.pin_href = HREF_GPIO_NUM;
    config.pin_sscb_sda = SIOD_GPIO_NUM;
    config.pin_sscb_scl = SIOC_GPIO_NUM;
    config.pin_pwdn = PWDN_GPIO_NUM;
    config.pin_reset = RESET_GPIO_NUM;
    config.xclk_freq_hz = 15000000;
    config.pixel_format = PIXFORMAT_JPEG;

    
    if(psramFound()){
        Serial.println("PSRAM found");
        config.frame_size = FRAMESIZE_XGA;
        config.jpeg_quality = 15;  //0-63 lower number means higher quality
        config.fb_count = 2;
    }else {
        Serial.println("PSRAM Not found");
        config.frame_size = FRAMESIZE_CIF;
        config.jpeg_quality = 12;  //0-63 lower number means higher quality
        config.fb_count = 1;
    }

    Serial.println("Cam Config befor esp_camera_init");
    try
    {
        esp_err_t err = esp_camera_init(&config);
        if (err != ESP_OK) {
            Serial.printf("Camera init failed with error 0x%x", err);
            vTaskDelay(5000);
            // esp_camera_deinit();
            // delay(100);
            // ESP.restart();
        }else{
            aiThinkerCameraProvider::_isInit = true;
            Serial.printf("Camera init Success");
        }
    }
    catch(const std::exception& e)
    {
        Serial.printf(e.what());
    }
    
    
}

void aiThinkerCameraProvider::capture(){
    camera_fb_t * fb = esp_camera_fb_get();
    uint8_t* image_holder;
    image_holder = (uint8_t*)ps_malloc(fb->len);
    esp_camera_fb_return(fb);
    aiThinkerCameraProvider::_onCaptureSucccessCallbacckMethod(image_holder);
}