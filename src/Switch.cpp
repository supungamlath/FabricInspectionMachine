#include <Arduino.h>
#include <Types.h>
#include <Pins.h>

void initializeSwitch()
{
    // Sets the two pins as Inputs
    pinMode(switchLeftPin, INPUT_PULLUP);
    pinMode(switchRightPin, INPUT_PULLUP);
}

ControllerPosition getSwitchPosition()
{
    int leftData = !digitalRead(switchLeftPin);
    int rightData = !digitalRead(switchRightPin);

    if (leftData)
    {
        return LEFT;
    }

    else if (rightData)
    {
        return RIGHT;
    }

    else
    {
        return MIDDLE;
    }
}
