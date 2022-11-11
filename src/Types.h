#pragma once
#include <Arduino.h>

enum ControllerPosition
{
    LEFT,
    MIDDLE,
    RIGHT
};

enum RotationDirection
{
    FORWARD = HIGH,
    BACKWARD = LOW
};

enum BluetoothPacket
{
    START = 's',
    SPEED = 'c',
    DIRECTION = 'd',
    POSITION = 'p',
    END = 'e'
};