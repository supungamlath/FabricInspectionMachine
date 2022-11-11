#include <Arduino.h>
#include <Types.h>

int speed = 0;
RotationDirection dir = FORWARD;

void initializeBluetooth()
{
    Serial1.begin(9600); // Baud Rate for AT-command Mode.
}

// Send new speed and direction and to app via bluetooth
void writeBluetooth(int new_speed, RotationDirection new_dir)
{
    char str_speed[3];
    char str_direction[1];
    unsigned int cur = 0;
    BluetoothPacket type;

    char out_buffer[100];
    sprintf(out_buffer, "s%id%c", new_speed, new_dir);
    Serial1.write(out_buffer);
}

// Read speed, direction and position from app via bluetooth
void readBluetooth()
{
    int speed;
    int direction;
    int position;

    unsigned int cur = 0;
    char buffer[50];

    while (Serial1.available())
    {
        char c = Serial1.read();
        if (c == BluetoothPacket::START)
        { // Start of packet, set cursor to zero and clear buffer
            cur = 0;
            buffer[0] = '\0';
        }
        else if (c == BluetoothPacket::SPEED)
        {
            buffer[cur] = '\0';
            cur = 0;
            speed = atoi(buffer);
        }
        else if (c == BluetoothPacket::DIRECTION)
        {
            buffer[cur] = '\0';
            cur = 0;
            direction = atoi(buffer);
        }
        else if (c == BluetoothPacket::POSITION)
        {
            buffer[cur] = '\0';
            cur = 0;
            position = atoi(buffer);
        }
        else if (c == BluetoothPacket::END)
        {
            buffer[cur] = '\0';
            cur = 0;
        }
        else
        {
            buffer[cur] = c;
            cur++;
        }
    }
}