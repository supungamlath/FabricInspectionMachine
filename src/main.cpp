#include <Arduino.h>
#include <Types.h>
#include <Pins.h>
#include <Motors.h>
#include <Joystick.h>
#include <SpeedController.h>
#include <Switch.h>

void setup()
{
  initializeMotors();
  initializeJoystick();
  initializeSwitch();
  initializeSpeedController();
  Serial.begin(9600);
}

void loop()
{
  //    ControllerPosition joystickPosition = getJoystickXPosition();
  ControllerPosition joystickPosition = ControllerPosition::MIDDLE;
  ControllerPosition switchPosition = getSwitchPosition();
  // Value from 0 to 1023
  int speed = getSpeedControllerReading();

  Serial.println("Speed ");
  Serial.println(speed);

  if (joystickPosition == LEFT || switchPosition == LEFT)
  {
    setMotorsSpeed(-1 * speed);
    runMotors();
  }
  else if (joystickPosition == RIGHT || switchPosition == RIGHT)
  {
    setMotorsSpeed(speed);
    runMotors();
  }
  else
  {
    stopMotors();
  }
}
