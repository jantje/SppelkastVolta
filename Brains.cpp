/*
 * Brains.cpp
 *
 *  Created on: 2022 Jan 2
 *      Author: jan
 */

#include "Brains.h"

Brains::Brains(uint8_t mainSwitchPin, uint8_t successPin, uint8_t allarmPin) {
    myMainSwitchPin = mainSwitchPin;
    myLastSwitchRead = 0;
    myAllarmPin = allarmPin;
    mySuccessPin = successPin;
    myLastStateChange = 0;

}

Brains::~Brains() {
    // TODO Auto-generated destructor stub
}

void Brains::setup() {
    pinMode(myMainSwitchPin, INPUT_PULLUP);
    pinMode(myAllarmPin, OUTPUT);
    pinMode(mySuccessPin, OUTPUT);
}

void Brains::loopCheckingBoard() {
    if (myMainSwitch.getMedian() == true) {
        myNewState = brainShowingError;
    }
}

void Brains::loopShowingError() {
    if (myMainSwitch.getMedian() == false) {
        turnAlarmOff();
        myNewState = brainSolvingPuzzel;
    }
}

void Brains::loopShowingResult() {
    if (mySuccessPinState == HIGH) {
        if (loopMillis - myLastStateChange > SUCCESS_TRIGGER_TIME) {
            turnSuccessOff();
        }
    }
    if (myAlarmPinState == HIGH) {
        if (loopMillis - myLastStateChange > ALARM_TRIGGER_TIME) {
            turnAlarmOff();
        }
    }
    if (loopMillis - myLastStateChange > SHOWING_RESULT_DURRATION) {
        if (myMoveToNextError) {
            myMoveToNextError = false;
            errors.nextError();
        }
        myNewState = brainShowingError;
    }
}

void Brains::loopSolvingPuzzle() {
    if (myMainSwitch.getMedian() == true) {
        myNewState = brainShowingResult;
    }
}

void Brains::switchToNewState() {
    myLastStateChange = loopMillis;
    myState = myNewState;

    switch (myNewState) {
    case brainChekingBoard:
        baken.off();
        errors.off();
        vragenHoek.pointDown();
        Serial.println("Brains switching to state board cheking");
        return;
    case brainShowingError:
        turnSuccessOff();
        turnAlarmOff();
        baken.blinkRed();
        errors.showErrorNumber();
        vragenHoek.off();
        Serial.println("Brains switching to state showing error.");
        return;
    case brainSolvingPuzzel:
        baken.off();
        errors.showErrorNumber();
        vragenHoek.showResult();
        Serial.println("Brains switching to state solving puzzle.");
        return;
    case brainShowingResult:
        if (vragenHoek.isSuccess()) {
            baken.green();
            vragenHoek.on();
            turnSuccessOn();
            myMoveToNextError = true;
        } else {
            turnAlarmOn();
        }

        Serial.println("Brains switching to state showing result");
        return;
    }
}

void Brains::loop() {
    if (myNewState != myState) {
        switchToNewState();
    }
    if (loopMillis - myLastSwitchRead > 15) {
        myLastSwitchRead = loopMillis;
        myMainSwitch.addValue(digitalRead(myMainSwitchPin) == LOW); // the switches must be standard open
    }
    switch (myState) {
    case brainChekingBoard:
        loopCheckingBoard();
        return;
    case brainShowingError:
        loopShowingError();
        return;
    case brainShowingResult:
        loopShowingResult();
        return;
    case brainSolvingPuzzel:
        loopSolvingPuzzle();
        return;
    }
}

void Brains::turnAlarmOn() {
    myAlarmPinState = HIGH;
    digitalWrite(myAllarmPin, myAlarmPinState);
}
void Brains::turnAlarmOff() {
    if (myAlarmPinState == HIGH) {
        myAlarmPinState = LOW;
        digitalWrite(myAllarmPin, myAlarmPinState);
    }
}

void Brains::turnSuccessOn() {
    mySuccessPinState = HIGH;
    digitalWrite(mySuccessPin, mySuccessPinState);
}
void Brains::turnSuccessOff() {
    if (mySuccessPinState == HIGH) {
        mySuccessPinState = LOW;
        digitalWrite(mySuccessPin, mySuccessPinState);
    }
}
