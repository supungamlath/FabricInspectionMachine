#include <Arduino.h>
#include <Pins.h>
#include <Types.h>
#include <PWM.h>
#include "SerialTransfer.h"

SerialTransfer serialTransfer;
MotorControlPacket motorPacket;

void initializeMotors()
{
    Serial1.begin(115200);
    serialTransfer.begin(Serial1);
    motorPacket.motor1dir = FORWARD;
    motorPacket.motor2dir = FORWARD;
    motorPacket.motor3dir = FORWARD;
    motorPacket.motor1speed = 0;
    motorPacket.motor2speed = 0;
    motorPacket.motor3speed = 0;
}

void setMotorsDirection(RotationDirection direction)
{
    motorPacket.motor1dir = direction;
    motorPacket.motor2dir = direction;
    motorPacket.motor3dir = direction;
}

void setMotorSpeed(int speed)
{
    motorPacket.motor1speed = speed;
    motorPacket.motor2speed = speed;
    motorPacket.motor3speed = speed;
}

void stopMotors()
{
    setMotorSpeed(0);
}

void sendMotorCommands()
{
    serialTransfer.sendDatum(motorPacket);
}