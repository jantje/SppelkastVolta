/*
 * Brains.h
 *
 *  Created on: 2022 Jan 2
 *      Author: jan
 */

#pragma once
#include "Arduino.h"
#include "Baken.h"
#include "ErrorRij.h"
#include "vragen.h"
#include "FastRunningMedian.h"
extern Baken baken;
extern ErrorRij errors;
extern Vragen vragenHoek;

typedef enum
{
    brainChekingBoard,brainShowingError, brainSolvingPuzzel,brainShowingResult
} BRAIN_STATE;

class Brains {
private:
    BRAIN_STATE myState=brainShowingError;
    BRAIN_STATE myNewState=brainChekingBoard;
    uint8_t myMainSwitchPin;
    uint8_t myAllarmPin;
    uint8_t mySuccessPin;
    uint8_t myAlarmPinState=LOW;
    uint8_t mySuccessPinState=LOW;
    unsigned long myLastSwitchRead;
    void loopCheckingBoard();
    void loopShowingError();
    void loopShowingResult();
    void loopSolvingPuzzle();
    unsigned long myLastStateChange;
    void switchToNewState();
    void setNewState(BRAIN_STATE newBoardState){myNewState=newBoardState;};
    FastRunningMedian<bool, 9, false> myMainSwitch;
    void turnAlarmOff();
    void turnAlarmOn();
    void turnSuccessOn();
    void turnSuccessOff();
public:
	Brains(uint8_t mainSwitchPin,uint8_t successPin,uint8_t allarmPin);
	virtual ~Brains();
	void setup();
	void loop();
};

