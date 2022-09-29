#pragma once

#include <Arduino.h>

// Motor Constants
const int stepPins[] = {2, 4, 3}; // X.STEP
const int dirPins[] = {5, 7, 6};  // X.DIR

// Joystick Constants
const int joystickXPin = A0;
const int joystickYPin = A1;

// Switch Constants
const int switchLeftPin = 12;
const int switchRightPin = 13;

// Speed Controller Constants
const int speedControllerPin = A3;
