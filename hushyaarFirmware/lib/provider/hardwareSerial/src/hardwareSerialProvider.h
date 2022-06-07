#include <Arduino.h>

class HardwareSerialProvider{
    public:
        HardwareSerialProvider();
        void print(char* message);
        void print(String message);
};