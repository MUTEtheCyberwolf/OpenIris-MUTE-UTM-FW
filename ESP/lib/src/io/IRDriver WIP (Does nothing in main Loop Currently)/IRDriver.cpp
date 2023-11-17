#include <Arduino.h>
#include <pwmWrite.h>
#include "IRDriver.hpp"

// This stuff here currently does nothing don't worry

// Define the analog pin you want to read
const int analogPin = 32; // Change to the appropriate analog pin

// Define the PWM output pin
const int pwmPin = 2; // Change to the appropriate digital pin for PWM

// Define the interval for checking analog value (in milliseconds)
const unsigned long checkInterval = 60000; // 1 minute

// Define the reference table for analog values to corresponding values
const int referenceTable[][2] = {
    // Add your mapping here
    // Example: {analogValue, correspondingValue}
    {100, 0},
    {200, 1},
    {300, 2},
    {400, 3},
    {500, 4}
};

// Variable to store the current status bit
bool statusBit = false;


// Function to control PWM based on the matched value
void controlPWM(int matchedValue) {
    if (matchedValue >= 0) {
        analogWrite(pwmPin, matchedValue);
    } else {
        analogWrite(pwmPin, 0); // Turn off PWM
        statusBit = true;       // Update status bit
    }
}


int IRDriver::initialize() {
// Function to read analog value and match it to the reference table
    int analogValue = analogRead(analogPin);
    int matchedValue = -1;

    // Iterate through the reference table
    for (size_t i = 0; i < sizeof(referenceTable) / sizeof(referenceTable[0]); i++) {
        if (analogValue <= referenceTable[i][0]) {
            matchedValue = referenceTable[i][1];
            break;
        }
    }

    return matchedValue;
}
