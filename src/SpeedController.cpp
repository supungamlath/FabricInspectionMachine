#include <Arduino.h>
#include <Types.h>
#include <Pins.h>

void initializeSpeedController()
{
    // Sets the pin as Input
    pinMode(speedControllerPin, INPUT);
}

int getSpeedControllerReading()
{
    // ADC reading from 0 to 1023
    return analogRead(speedControllerPin);
}