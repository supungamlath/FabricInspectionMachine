#include <Arduino.h>
#include <Types.h>
#include <Pins.h>

const int joystickMiddleReading = 512;
int joystickUpperReading = joystickMiddleReading + 20;
int joystickLowerReading = joystickMiddleReading - 20;

void initializeJoystick()
{
    // Sets the two pins as Inputs
    pinMode(joystickXPin, INPUT);
    pinMode(joystickYPin, INPUT);
}

ControllerPosition getJoystickXPosition()
{
    // ADC reading from 0 to 1023
    int x_data = analogRead(joystickXPin);

    if (x_data < joystickLowerReading)
    {
        return LEFT;
    }
    else if (x_data > joystickUpperReading)
    {
        return RIGHT;
    }
    return MIDDLE;
}
