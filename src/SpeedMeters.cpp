#include <Arduino.h>
#include <Pins.h>
#include <Encoder.h>

Encoder leftEncoder(leftEncoderDTPin, leftEncoderCLKPin);
Encoder middleEncoder(middleEncoderDTPin, middleEncoderCLKPin);
Encoder rightEncoder(rightEncoderDTPin, rightEncoderCLKPin);

void initializeSpeedMeters()
{
    leftEncoder.write(0);
    middleEncoder.write(0);
    rightEncoder.write(0);
}

// Check if Rotary Encoder was moved
void checkReadings()
{
    long newLeft, newMiddle, newRight;
    newLeft = leftEncoder.read();
    newMiddle = middleEncoder.read();
    newRight = rightEncoder.read();
    Serial.print("Left = ");
    Serial.print(newLeft);
    Serial.print(", Middle = ");
    Serial.print(newMiddle);
    Serial.print(", Right = ");
    Serial.print(newRight);
    Serial.println();
}