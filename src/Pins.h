#pragma once
#include <Arduino.h>

// Joystick Pins
const int joystickXPin = A0;
const int joystickYPin = A1;

// Switch Pins
const int switchLeftPin = 8;
const int switchRightPin = 9;

// Speed Controller Pins
const int speedControllerPin = A2;

// Rotary Encoder Pins
const int encoderDTPin = 51;  // DATA signal
const int encoderCLKPin = 50; // CLOCK signal