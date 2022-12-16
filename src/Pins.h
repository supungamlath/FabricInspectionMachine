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
const int leftEncoderDTPin = 21;
const int leftEncoderCLKPin = 20;
const int middleEncoderDTPin = 3;
const int middleEncoderCLKPin = 5;
const int rightEncoderDTPin = 2;
const int rightEncoderCLKPin = 4;