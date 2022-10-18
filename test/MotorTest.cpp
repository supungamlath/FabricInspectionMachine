#include <Arduino.h>
#include <AccelStepper.h>

// Define the three steppers and the pins they use
// AccelStepper leftStepper(AccelStepper::DRIVER, stepPins[0], dirPins[0]);
AccelStepper middleStepper(AccelStepper::DRIVER, 4, 7);
// AccelStepper rightStepper(AccelStepper::DRIVER, stepPins[2], dirPins[2]);

void initializeMotors()
{
    // Set the max speed to match the max reading from ADC
    // leftStepper.setMaxSpeed(1023);
    // Set max acceleration same as Accelstepper example
    // leftStepper.setAcceleration(100);
    // middleStepper.setMaxSpeed(1023);
    middleStepper.setAcceleration(100);
    // rightStepper.setMaxSpeed(1023);
    // rightStepper.setAcceleration(100);
}

void setMotorsSpeed(int speed)
{
    // leftStepper.setSpeed(speed);
    middleStepper.setSpeed(speed);
    // rightStepper.setSpeed(speed);
}

void runMotors()
{
    // Motors will run when this function is called continously
    // leftStepper.run();
    middleStepper.run();
    // rightStepper.run();
}

void stopMotors()
{
    // leftStepper.stop();
    middleStepper.stop();
    // rightStepper.stop();
}

void setup()
{
    initializeMotors();
    setMotorsSpeed(100);
}

void loop()
{
    runMotors();
}
