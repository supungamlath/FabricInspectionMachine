#pragma once
#include <Arduino.h>

// Motor Pins
const int stepPins[] = {2, 3, 4};
const int dirPins[] = {5, 6, 7};

// Joystick Pins
const int joystickXPin = A0;
const int joystickYPin = A1;

// Switch Pins
const int switchLeftPin = 12;
const int switchRightPin = 13;

// Speed Controller Pins
const int speedControllerPin = A3;

// Rotary Encoder Pins
const int encoderDTPin = 51;  // DATA signal
const int encoderCLKPin = 50; // CLOCK signal