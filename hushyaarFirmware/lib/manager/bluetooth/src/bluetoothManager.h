#include "../../lib/provider/bluetooth/src/bluetoothProvider.h"


class BluetoothManager{
    private:
        String bleUUID;
        BluetoothProvider _bluetoothProvider;
    public:
        BluetoothManager();
        BluetoothManager(String bleUUID);
        void start();
        void scan();
};