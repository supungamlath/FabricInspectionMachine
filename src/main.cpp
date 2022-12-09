// @author - Supun Gamlath (supungamlath@outlook.com)

#include <Arduino.h>
#include <Types.h>
#include <MotorsTX.h>
#include <Joystick.h>
#include <SpeedController.h>
#include <Encoder.h>
#include <Switch.h>

void setup()
{
  initializeMotors();
  initializeJoystick();
  initializeSwitch();
  initializeSpeedController();
<<<<<<< Updated upstream
  // Serial.begin(115200);
=======
  initializeBluetooth();
  Serial.begin(115200);
>>>>>>> Stashed changes
}

void loop()
{
<<<<<<< Updated upstream
  // checkRotaryWithDebouncing();
  ControllerPosition joystickPosition = getJoystickXPosition();
  ControllerPosition switchPosition = getSwitchPosition();
  // Value from 0 to 1023
  int speed = getSpeedControllerReading();

  // Serial.print("Speed ");
  // Serial.print(speed);
  // Serial.print(" Joystick ");
  // Serial.println(joystickPosition);

  if (joystickPosition == LEFT || switchPosition == LEFT)
  {
    setMotorsDirection(BACKWARD);
    runMotors(speed);
  }
  else if (joystickPosition == RIGHT || switchPosition == RIGHT)
  {
    setMotorsDirection(FORWARD);
    runMotors(speed);
  }
  else
  {
    stopMotors();
=======
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
      runMotors(400);
    }
    else if (joystickPosition == RIGHT)
    {
      setMotorsDirection(BACKWARD);
      runMotors(400);
    }
    stopMotors();
  }
  else
  {
    int speed = getSpeedControllerReading();
    Serial.print("Speed ");
    Serial.print(speed);
    if (switchPosition == LEFT)
    {
      setMotorsDirection(BACKWARD);
      runMotors(speed);
    }
    else if (switchPosition == RIGHT)
    {
      setMotorsDirection(FORWARD);
      runMotors(speed);
    }
>>>>>>> Stashed changes
  }
}
