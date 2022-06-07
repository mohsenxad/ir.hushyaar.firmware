#include "bluetoothManager.h"

BluetoothManager::BluetoothManager(){
    
}

BluetoothManager::BluetoothManager(String bleUUID){
    BluetoothManager::bleUUID = bleUUID;
    _bluetoothProvider = BluetoothProvider(bleUUID);
}

void BluetoothManager::start(){
    BluetoothManager::_bluetoothProvider.start();
}

void BluetoothManager::scan(){
    
}