#include "../../lib/manager/motionDetection/src/motionDetectionManager.h"
#include "../../lib/manager/sound/src/soundManager.h"
#include "../../lib/manager/beacon/src/beaconManager.h"

class ArmedProcess{
    private:
        MotionDetectionManager _motionDetectionManager;
        SoundManager _soundManager;
        BeaconManager _beaconManager;
        void taskSoundSirinOn(void *pvParameters);
        void taskPirScanning(void *pvParameters);
    public:
        ArmedProcess();
        void Start();
};