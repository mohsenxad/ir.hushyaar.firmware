#include "WS2812BProvider.h"

WS2812BProvider::WS2812BProvider(){
    WS2812BProvider::_rgbPinNumber = 2;
    WS2812BProvider::_pixels = Adafruit_NeoPixel(NUMPIXELS, WS2812BProvider::_rgbPinNumber, NEO_GRB + NEO_KHZ800);
    WS2812BProvider::_pixels.begin();
    Serial.print("WS2812BProvider: WS2812BProvider | End > _rgbPinNumber: ");
    Serial.println(WS2812BProvider::_rgbPinNumber);
}

WS2812BProvider::WS2812BProvider(int rgbPinNumber){
    WS2812BProvider::_rgbPinNumber = rgbPinNumber;
    WS2812BProvider::_pixels = Adafruit_NeoPixel(NUMPIXELS, WS2812BProvider::_rgbPinNumber, NEO_GRB + NEO_KHZ800);
    WS2812BProvider::_pixels.begin();
    Serial.print("WS2812BProvider: WS2812BProvider | End > _rgbPinNumber: ");
    Serial.println(WS2812BProvider::_rgbPinNumber);
}

void WS2812BProvider::setSirenFinishedCallbackMethod(
    SIREN_FINISHED_CALL_BACK_METHOD onSirenFinishedCallbackMethod
){
    WS2812BProvider::_onSirenFinishedCallbackMethod = onSirenFinishedCallbackMethod;
}

void WS2812BProvider::SirenOn(){
    Serial.println("WS2812BProvider: SirenOn | Start");
    for (int cycle = 1; cycle <=5; cycle++ ){
        for (int pixel_value = 10; pixel_value < 200; pixel_value++){
                for (int index = 0; index < NUMPIXELS; index++){
                    WS2812BProvider::_pixels.setPixelColor(index, WS2812BProvider::_pixels.Color(pixel_value,10,10));
                }
                WS2812BProvider::_pixels.show();
                vTaskDelay(3);
            }
            for (int pixel_value = 200; pixel_value > 10; pixel_value--){
                for (int index = 0; index < NUMPIXELS; index++){
                    WS2812BProvider::_pixels.setPixelColor(index, WS2812BProvider::_pixels.Color(pixel_value,10,10));
                }
                WS2812BProvider::_pixels.show();
                vTaskDelay(3);
            }
    }
    
    WS2812BProvider::_onSirenFinishedCallbackMethod();
    Serial.println("WS2812BProvider: SirenOn | End");
}

void WS2812BProvider::Off(){
    Serial.println("WS2812BProvider: Off | Start");
    for(int index = 0; index < NUMPIXELS; index++){
        WS2812BProvider::_pixels.setPixelColor(index, WS2812BProvider::_pixels.Color(0,0,0));
    }
    //WS2812BProvider::_pixels.clear();
    WS2812BProvider::_pixels.show();
    Serial.println("WS2812BProvider: Off | End");
}

void WS2812BProvider::TorchOn(){
    for(int index = 0; index < NUMPIXELS; index++){
        WS2812BProvider::_pixels.setPixelColor(index, WS2812BProvider::_pixels.Color(30,30,30));
    }
    WS2812BProvider::_pixels.show();
}