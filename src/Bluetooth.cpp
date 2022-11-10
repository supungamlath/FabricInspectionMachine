#include <Arduino.h>
#include <Types.h>

int speed = 0;
RotationDirection dir = FORWARD;

void initializeBluetooth()
{
    Serial1.begin(9600); // Baud Rate for AT-command Mode.
}

// Send new speed and direction and to app via bluetooth
void readWriteBluetooth(int new_speed, RotationDirection new_dir)
{
    char str_speed[3];
    char str_direction[1];
    unsigned int cur = 0;
    BluetoothData type;

    while (Serial1.available())
    {
        char c = Serial1.read();
        if (c == BluetoothData::SPEED)
        {
            type = BluetoothData::SPEED;
            cur = 0;
        }
        else if (c == BluetoothData::DIRECTION)
        {
            type = BluetoothData::DIRECTION;
            cur = 0;
        }
        else
        {
            if (type == BluetoothData::SPEED)
            {
                str_speed[cur] = c;
                c++;
            }
            else if (type == BluetoothData::DIRECTION)
            {
                str_direction[cur] = c;
                c++;
            }
        }
    }
    speed = 0;
    dir = FORWARD;

    char out_buffer[100];
    sprintf(out_buffer, "s%id%c", new_speed, new_dir);
    Serial1.write(out_buffer);
}
int getRemoteSpeed()
{
    return speed;
}

RotationDirection getRemoteDirection()
{
    return dir;
}