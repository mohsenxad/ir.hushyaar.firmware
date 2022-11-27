#include <Arduino.h>
#include <esp_log.h>
#include "../../lib/manager/sound/src/soundManager.h"

class BootProcess{
    private:
        SoundManager _soundManager;
    public:
        BootProcess();
        void Boot();
};