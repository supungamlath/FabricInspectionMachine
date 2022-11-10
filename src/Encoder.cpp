#include <Arduino.h>
#include <Pins.h>

// Variables to debounce Rotary Encoder
unsigned long TimeOfLastDebounce = 0;
unsigned long DelayofDebounce = 1;

// Store previous Pins state
int PreviousCLK;
int PreviousDATA;

int posCounter = 0; // Store current counter value

void initializeEncoder()
{
    pinMode(encoderCLKPin, INPUT);
    pinMode(encoderDTPin, INPUT);
    // Put current pins state in variables
    PreviousCLK = digitalRead(encoderCLKPin);
    PreviousDATA = digitalRead(encoderDTPin);
}

// Check if Rotary Encoder was moved
void checkRotary()
{
    if ((PreviousCLK == 0) && (PreviousDATA == 1))
    {
        if ((digitalRead(encoderCLKPin) == 1) && (digitalRead(encoderDTPin) == 0))
        {
            posCounter++;
            Serial.println(posCounter);
        }
        if ((digitalRead(encoderCLKPin) == 1) && (digitalRead(encoderDTPin) == 1))
        {
            posCounter--;
            Serial.println(posCounter);
        }
    }

    if ((PreviousCLK == 1) && (PreviousDATA == 0))
    {
        if ((digitalRead(encoderCLKPin) == 0) && (digitalRead(encoderDTPin) == 1))
        {
            posCounter++;
            Serial.println(posCounter);
        }
        if ((digitalRead(encoderCLKPin) == 0) && (digitalRead(encoderDTPin) == 0))
        {
            posCounter--;
            Serial.println(posCounter);
        }
    }

    if ((PreviousCLK == 1) && (PreviousDATA == 1))
    {
        if ((digitalRead(encoderCLKPin) == 0) && (digitalRead(encoderDTPin) == 1))
        {
            posCounter++;
            Serial.println(posCounter);
        }
        if ((digitalRead(encoderCLKPin) == 0) && (digitalRead(encoderDTPin) == 0))
        {
            posCounter--;
            Serial.println(posCounter);
        }
    }

    if ((PreviousCLK == 0) && (PreviousDATA == 0))
    {
        if ((digitalRead(encoderCLKPin) == 1) && (digitalRead(encoderDTPin) == 0))
        {
            posCounter++;
            Serial.println(posCounter);
        }
        if ((digitalRead(encoderCLKPin) == 1) && (digitalRead(encoderDTPin) == 1))
        {
            posCounter--;
            Serial.println(posCounter);
        }
    }
}

void checkRotaryWithDebouncing()
{
    // If enough time has passed check the rotary encoder
    if ((millis() - TimeOfLastDebounce) > DelayofDebounce)
    {
        checkRotary(); // Rotary Encoder check routine below

        PreviousCLK = digitalRead(encoderCLKPin);
        PreviousDATA = digitalRead(encoderDTPin);

        TimeOfLastDebounce = millis(); // Set variable to current millis() timer
    }
}

int getEncoderReading()
{
    checkRotaryWithDebouncing();
    return posCounter;
}

void resetEncoderReading()
{
    posCounter = 0;
}