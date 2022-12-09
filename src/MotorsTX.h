#pragma once

void initializeMotors();
void setMotorsDirection(RotationDirection direction);
void setMotorSpeed(int speed);
void stopMotors();
void sendMotorCommands();