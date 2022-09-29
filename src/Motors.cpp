#include <Arduino.h>
#include <Types.h>
#include <Pins.h>
#include <AccelStepper.h>

// Define the three steppers and the pins they use
AccelStepper leftStepper(AccelStepper::DRIVER, stepPins[0], dirPins[0]);
AccelStepper middleStepper(AccelStepper::DRIVER, stepPins[1], dirPins[1]);
AccelStepper rightStepper(AccelStepper::DRIVER, stepPins[2], dirPins[2]);

void initializeMotors()
{
    // Sets the pins as Outputs
    leftStepper.setMaxSpeed(1024);
    middleStepper.setMaxSpeed(1024);
    rightStepper.setMaxSpeed(1024);
}

void setMotorsSpeed(int speed)
{
    leftStepper.setSpeed(speed);
    middleStepper.setSpeed(speed);
    rightStepper.setSpeed(speed);
}

void runMotors()
{
    leftStepper.runSpeed();
    middleStepper.runSpeed();
    rightStepper.runSpeed();
}

void stopMotors()
{
    leftStepper.stop();
    middleStepper.stop();
    rightStepper.stop();
}
