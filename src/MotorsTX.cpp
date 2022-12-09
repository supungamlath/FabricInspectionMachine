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
    Serial1.begin(115200);
}

void runMotors(int speed)
{
    int stepDelay = map(speed, 0, 1023, minSpeedStepDelay, maxSpeedStepDelay);
    Serial1.print("s:");
    Serial1.print(stepDelay);
}

void stopMotors()
{
    for (int motor = 0; motor < 3; motor++)
    {
        digitalWrite(stepPins[motor], LOW);
    }
}
