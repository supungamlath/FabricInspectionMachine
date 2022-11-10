// @author - Supun Gamlath (supungamlath@outlook.com)

#include <Arduino.h>
#include <Types.h>
#include <Motors.h>
#include <Joystick.h>
#include <SpeedController.h>
#include <Encoder.h>
#include <Switch.h>
#include <Bluetooth.h>

void setup()
{
  initializeMotors();
  initializeJoystick();
  initializeSwitch();
  initializeSpeedController();
  initializeBluetooth();
  // Serial.begin(115200);
}

void loop()
{
  int encoderReading = getEncoderReading();
  // ControllerPosition joystickPosition = getJoystickXPosition();
  // ControllerPosition switchPosition = getSwitchPosition();
  // Value from 0 to 1023
  // int speed = getSpeedControllerReading();

  // Serial.print("Speed ");
  // Serial.print(speed);
  // Serial.print(" Joystick ");
  // Serial.println(joystickPosition);

  // if (joystickPosition == LEFT || switchPosition == LEFT)
  // {
  //   setMotorsDirection(BACKWARD);
  //   runMotors(speed);
  // }
  // else if (joystickPosition == RIGHT || switchPosition == RIGHT)
  // {
  //   setMotorsDirection(FORWARD);
  //   runMotors(speed);
  // }
  // else
  // {
  //   stopMotors();
  // }

  // checkBT();
}
