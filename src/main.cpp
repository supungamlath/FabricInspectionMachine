// @author - Supun Gamlath (supungamlath@outlook.com)

#include <Arduino.h>
#include <Types.h>
#include <MotorsTX.h>
#include <Joystick.h>
#include <SpeedController.h>
#include <Encoder.h>
#include <Switch.h>
#include <Wire.h>

void setup()
{
  initializeMotors();
  initializeJoystick();
  initializeSwitch();
  initializeSpeedController();
  // initializeBluetooth();
  Serial.begin(115200);
}

void loop()
{
  ControllerPosition switchPosition = getSwitchPosition();
  // // Value from 0 to 1023
  if (switchPosition == MIDDLE)
  {
    ControllerPosition joystickPosition = getJoystickXPosition();
    Serial.print(" Joystick ");
    Serial.println(joystickPosition);
    // int encoderReading = getEncoderReading();
    if (joystickPosition == LEFT)
    {
      setMotorsDirection(FORWARD);
      setMotorSpeed(100);
    }
    else if (joystickPosition == RIGHT)
    {
      setMotorsDirection(BACKWARD);
      setMotorSpeed(100);
    }
    else
    {
      stopMotors();
    }
  }
  else
  {
    int speed = getSpeedControllerReading();
    Serial.print("Speed ");
    Serial.println(speed);
    if (switchPosition == LEFT)
    {
      setMotorsDirection(BACKWARD);
      setMotorSpeed(speed);
    }
    else if (switchPosition == RIGHT)
    {
      setMotorsDirection(FORWARD);
      setMotorSpeed(speed);
    }
  }
  sendMotorCommands();
}