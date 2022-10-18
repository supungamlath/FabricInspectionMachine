#include <Arduino.h>
#include <Pins.h>
#include <Types.h>
#include <PWM.h>

const int maxSpeedStepDelay = 30;
const int minSpeedStepDelay = 1500;

void setMotorsDirection(RotationDirection direction)
{
    for (int motor = 0; motor < 3; motor++)
    {
        digitalWrite(dirPins[motor], direction); // Enables the motor to move in a particular direction
    }
}

void initializeMotors()
{
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
    int stepDelay = map(speed, 0, 1023, minSpeedStepDelay, maxSpeedStepDelay);
    for (int motor = 0; motor < 3; motor++)
    {
        // Serial.println(stepDelay);
        digitalWrite(stepPins[motor], HIGH);
        delayMicroseconds(stepDelay);
        digitalWrite(stepPins[motor], LOW);
        // delayMicroseconds(stepDelay);
    }
}

void stopMotors()
{
    for (int motor = 0; motor < 3; motor++)
    {
        digitalWrite(stepPins[motor], LOW);
    }
}
