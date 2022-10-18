#include <Arduino.h>
#include <Pins.h>
#include <Types.h>
#include <PWM.h>

// const int maxSpeedStepDelay = 30;
// const int minSpeedStepDelay = 1500;
const int minFrequency = 500;
const int maxFrequency = 10000;

void setMotorsDirection(RotationDirection direction)
{
    for (int motor = 0; motor < 3; motor++)
    {
        digitalWrite(dirPins[motor], direction); // Enables the motor to move in a particular direction
    }
}

void initializeMotors()
{
    // Initialize all timers except for 0, to save time keeping functions
    InitTimers();

    // Sets the pins as Outputs
    for (int motor = 0; motor < 3; motor++)
    {
        pinMode(stepPins[motor], OUTPUT);
        pinMode(dirPins[motor], OUTPUT);
    }
    setMotorsDirection(FORWARD);
}

void runMotors(int speed)
{
    // int stepDelay = map(speed, 0, 1023, minSpeedStepDelay, maxSpeedStepDelay);
    int frequency = map(speed, 0, 1023, minFrequency, maxFrequency);
    SetPinFrequency(stepPins[1], frequency);
    SetPinFrequency(stepPins[2], frequency);
    for (int motor = 0; motor < 3; motor++)
    {
        // Serial.println(stepDelay);
        // digitalWrite(stepPins[motor], HIGH);
        // delayMicroseconds(stepDelay);
        // digitalWrite(stepPins[motor], LOW);
        // delayMicroseconds(stepDelay);

        // Set frequency of PWM pins
        // use this functions instead of analogWrite on 'initialized' pins
        pwmWrite(stepPins[motor], 127);
    }
}

void stopMotors()
{
    for (int motor = 0; motor < 3; motor++)
    {
        pwmWrite(stepPins[motor], 0);
        // digitalWrite(stepPins[motor], LOW);
    }
}
