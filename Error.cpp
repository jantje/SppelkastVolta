/*
 * Error.cpp
 *
 *  Created on: 2021 Dec 30
 *      Author: jan
 */

#include "Error.h"
#include "globals.h"

Error::Error(uint8_t ledPin, uint8_t answer1, uint8_t answer2, uint8_t answer3, uint8_t answer4) {
    myLedPin = ledPin;
    myAnswer[0] = answer1;
    myAnswer[1] = answer2;
    myAnswer[2] = answer3;
    myAnswer[3] = answer4;
    myCurLedState = LOW;
    myNewLedStae = LOW;
}



Error::~Error() {
}

void Error::loop() {
    if (myCurLedState != myNewLedStae) {
        digitalWrite(myLedPin, myNewLedStae);
        myCurLedState = myNewLedStae;
    }
}

void Error::setup() {
    //set the pinmode
    pinMode(myLedPin, OUTPUT);
    //blink the led
    digitalWrite(myLedPin, HIGH);
    delay(SETUP_LIGHT_ON_TIME);
    digitalWrite(myLedPin, myCurLedState);
}


uint8_t Error::getExpectedAnswer(uint8_t questionIndex) {
    return myAnswer[questionIndex];
}
