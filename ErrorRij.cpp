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
    myCurrentError = 0;

    myBlink=false;
    myNewBlink=false;
    myblinkPreviousMillis=0;
}

ErrorRij::~ErrorRij() {
}

void ErrorRij::setup() {
    for (int curError = 0; curError < NUM_ERROS; curError++) {
        myErrors[curError]->setup();
    }
}

void ErrorRij::loop() {

    if (myNewBlink != myBlink) {
        myBlink = myNewBlink;
        if (!myBlink) {
            myErrors[myCurrentError]->setLedState(LOW);
        }
        myblinkPreviousMillis = loopMillis;
    }
    if (myBlink) {
        uint8_t newLedState = calcLedState(&myblinkPreviousMillis, ERROR_BLINK_ON_TIME, ERROR_BLINK_INTERVAL_TIME);
        myErrors[myCurrentError]->setLedState(newLedState);
    }

    for (int curError = 0; curError < NUM_ERROS; curError++) {
        myErrors[curError]->loop();
    }
}
