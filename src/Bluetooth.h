struct BluetoothData
{
    int speed, direction, position;
};

void initializeBluetooth();
void writeBluetooth(int new_speed, RotationDirection new_dir);
BluetoothData readBluetooth();