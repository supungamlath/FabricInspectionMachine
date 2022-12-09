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

struct MotorControlPacket
{
    RotationDirection motor1dir;
    RotationDirection motor2dir;
    RotationDirection motor3dir;
    int motor1speed;
    int motor2speed;
    int motor3speed;
};