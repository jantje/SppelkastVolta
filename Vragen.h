/*
 * Vragen.h
 *
 *  Created on: 2021 Dec 30
 *      Author: jan
 */
#pragma once
#include "Arduino.h"
#include "Vraag.h"
#include "ErrorRij.h"
#include "globals.h"

extern ErrorRij errors;

typedef enum {
    vragenOff, vragenOn, showingResult, pointingDown
} VRAGEN_STATE;

class Vragen {
private:
    Vraag *myQuestions[NUM_QUESTIONS];
    VRAGEN_STATE myState = showingResult;
    VRAGEN_STATE myNewState = vragenOff;
    void switchToNewState();

public:
    Vragen(Vraag *vraagA, Vraag *vraagB, Vraag *vraagC, Vraag *vraagD);
    virtual ~Vragen();
    void loop();
    void setup();
    void pointDown() {
        myNewState = pointingDown;
    }
    void off() {
        myNewState = vragenOff;
    }
    void on() {
        myNewState = vragenOn;
    }
    void showResult() {
        myNewState = showingResult;
    }
    boolean isSuccess();
};

