#include <WString.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <WString.h>

#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

class BluetoothProvider{
    private:
        BLEDevice _BLEDevice;
        BLEScan* pBLEScan;
        BLEScanResults foundDevices;
        String bleUUID;
        BLEServer* pServer = NULL;
        BLECharacteristic* pCharacteristic = NULL;
        int scanTime = 5; //In seconds
    public:
        BluetoothProvider();
        BluetoothProvider(String bleUUID);
        void start();
        void scan();
};