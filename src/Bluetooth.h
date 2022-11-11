struct BluetoothData
{
    int speed, position;
    RotationDirection direction;
};

void initializeBluetooth();
void writeBluetooth(int new_speed, RotationDirection new_dir);
BluetoothData readBluetooth();