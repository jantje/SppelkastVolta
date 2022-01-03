/*
 * Baken.cpp
 *
 *  Created on: 2022 Jan 2
 *      Author: jan
 */

#include "Baken.h"
#include "globals.h"

Baken::Baken(uint8_t groenPin, uint8_t roodPin) {
    myGreenPin = groenPin;
    myRedPin = roodPin;
    myBlinkRed = false;
    mynewBlinkRed = false;
    myRedLedSTate = LOW;
    myblinkRedPreviousMillis = 0;
}

Baken::~Baken() {
}

void Baken::setup() {
    //set the pinmodes
    pinMode(myGreenPin, OUTPUT);
    pinMode(myRedPin, OUTPUT);
    //Do the startup blink
    digitalWrite(myRedPin, HIGH);
    delay(SETUP_LIGHT_ON_TIME);
    digitalWrite(myRedPin, LOW);
    digitalWrite(myGreenPin, HIGH);
    delay(SETUP_LIGHT_ON_TIME);
    digitalWrite(myGreenPin, LOW);
}

uint8_t calcLedState(unsigned long *previousMillis, uint16_t onTime, uint16_t interval) {
    if (loopMillis - *previousMillis <= onTime) {
        return HIGH;
    }
    if (loopMillis - *previousMillis <= interval) {
        return LOW;
    }
    (*previousMillis) += interval;
    return HIGH;
}

void Baken::loop() {
    if (mynewBlinkRed != myBlinkRed) {
        myBlinkRed = mynewBlinkRed;
        if (!myBlinkRed) {
            myRedLedSTate = LOW;
            digitalWrite(myRedPin, myRedLedSTate);
        }
        myblinkRedPreviousMillis = loopMillis;
    }
    if (myBlinkRed) {
        uint8_t newLedState = calcLedState(&myblinkRedPreviousMillis, BAKEN_ROOD_BLINK_ON_TIME, BAKEN_ROOD_BLINK_INTERVAL_TIME);
        if (newLedState != myRedLedSTate) {
            myRedLedSTate = newLedState;
            digitalWrite(myRedPin, myRedLedSTate);
        }
    }

}
