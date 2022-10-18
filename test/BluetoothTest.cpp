#include <Arduino.h>

void setup()
{
    Serial.begin(9600);
    Serial1.begin(38400); // Baud Rate for AT-command Mode.
    Serial.println("***AT commands mode***");
}
void loop()
{
    // from bluetooth to Terminal.
    if (Serial1.available())
        Serial.write(Serial1.read());
    // from termial to bluetooth
    if (Serial.available())
        Serial1.write(Serial.read());
}