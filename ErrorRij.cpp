/*
 * ErrorRij.cpp
 *
 *  Created on: 2022 Jan 2
 *      Author: jan
 */

#include "ErrorRij.h"

ErrorRij::ErrorRij(Error *err1, Error *err2, Error *err3, Error *err4) {
    myErrors[0] = err1;
    myErrors[1] = err2;
    myErrors[2] = err3;
    myErrors[3] = err4;
}

ErrorRij::~ErrorRij() {
}

void ErrorRij::setup() {
    for (int curError = 0; curError < NUM_ERROS; curError++) {
        myErrors[curError]->setup();
    }
}

void ErrorRij::loop() {
    if(myState!=myNewState){
        switchToNewState();
    }
    switch (myState){
    case errorOff:
        break;
    case errorShowError:
        uint8_t newLedState = calcLedState(&myblinkPreviousMillis, ERROR_BLINK_ON_TIME, ERROR_BLINK_INTERVAL_TIME);
        myErrors[myCurrentError]->setLedState(newLedState);
        break;
    }

    for (int curError = 0; curError < NUM_ERROS; curError++) {
        myErrors[curError]->loop();
    }
}

void ErrorRij::switchToNewState() {
    myState=myNewState;
    switch (myState){
    case errorOff:
        for (int curError = 0; curError < NUM_ERROS; curError++) {
            myErrors[curError]->setLedState(LOW);
        }
        Serial.println("ErrorRij switching to state off");
        return;
    case errorShowError:
        for (int curError = 0; curError < NUM_ERROS; curError++) {
            myErrors[curError]->setLedState(LOW);
        }
        myblinkPreviousMillis=loopMillis;
        myErrors[myCurrentError]->setLedState(HIGH);
        Serial.println("ErrorRij switching to state show error");
        return;
    }
}

uint8_t ErrorRij::getExpectedAnswer(uint8_t questionIndex) {
    return   myErrors[myCurrentError]->getExpectedAnswer(questionIndex);
}

void ErrorRij::nextError() {
    myCurrentError++;
    if(myCurrentError>=NUM_ERROS){
        myCurrentError=0;
    }
    Serial.print("ErrorRij switching to error ");
    Serial.println(myCurrentError);
}
