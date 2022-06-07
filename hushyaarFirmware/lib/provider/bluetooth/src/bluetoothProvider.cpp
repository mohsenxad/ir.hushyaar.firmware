#include "bluetoothProvider.h"

BluetoothProvider::BluetoothProvider(){

}

BluetoothProvider::BluetoothProvider(String bleUUID){
    BluetoothProvider::bleUUID = bleUUID;
    BluetoothProvider::_BLEDevice.init(BluetoothProvider::bleUUID.c_str());
}


void BluetoothProvider::start(){
    pServer = BluetoothProvider::_BLEDevice.createServer();
    // Create the BLE Service
    BLEService *pService = pServer->createService(SERVICE_UUID);

    // Create a BLE Characteristic
    pCharacteristic = pService->createCharacteristic(
                        CHARACTERISTIC_UUID,
                        BLECharacteristic::PROPERTY_READ   |
                        BLECharacteristic::PROPERTY_WRITE  |
                        BLECharacteristic::PROPERTY_NOTIFY |
                        BLECharacteristic::PROPERTY_INDICATE
                        );

    // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.descriptor.gatt.client_characteristic_configuration.xml
    // Create a BLE Descriptor
    pCharacteristic->addDescriptor(new BLE2902());

    // Start the service
    pService->start();

    // Start advertising
    BLEAdvertising *pAdvertising = BluetoothProvider::_BLEDevice.getAdvertising();
    pAdvertising->addServiceUUID(SERVICE_UUID);
    pAdvertising->setScanResponse(false);
    pAdvertising->setMinPreferred(0x0);  // set value to 0x00 to not advertise this parameter
    BluetoothProvider::_BLEDevice.startAdvertising();
}

void BluetoothProvider::scan(){
    pBLEScan = BluetoothProvider::_BLEDevice.getScan();
    pBLEScan->setInterval(100);
    pBLEScan->setWindow(99);
    foundDevices = pBLEScan->start(scanTime, false);
}