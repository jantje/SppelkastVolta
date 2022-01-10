/*
 * Vraag.h
 *
 *  Created on: 2021 Dec 30
 *      Author: jan
 */
#pragma once
#include "Arduino.h"
#include "globals.h"

typedef enum {
    questionOff, questionOn, QuestionShowingResult, questionSlave
} VRAAG_STATE;


class Vraag {
private:
	uint8_t myAnswerPins[NUM_ANSWERS];
	uint8_t myResultPin;
	uint8_t myLightPin;
	uint8_t myNewSelectedAnswer;
	uint8_t mySelectedAnswer;
	uint8_t myCurTestedPin;
	uint8_t myExpectedAnswer=0;
	char myID;
	unsigned long myLastAction; //rename to last blink
	uint8_t myCurLedState=LOW;
	uint8_t myNewLedState=LOW;
	VRAAG_STATE myState=QuestionShowingResult;
	VRAAG_STATE myNewState=questionOff;
    unsigned long myLastStateChange;
    void switchToNewState();
    void setNewState(VRAAG_STATE newState){myNewState=newState;};
public:
	Vraag(char questionID, uint8_t lightPin, uint8_t resultPin, uint8_t pin0, uint8_t pin1,
			uint8_t pin2, uint8_t pin3);
	void setup();
	void loop();
	virtual ~Vraag();
	uint8_t getSelectedAnswer() {
		return mySelectedAnswer;
	}
	void ledOn(){myNewLedState=HIGH;};
    void ledOff(){myNewLedState=LOW;};
    void showResult(uint8_t expectedAnswer){ myExpectedAnswer= expectedAnswer;myNewState=QuestionShowingResult;};
    void beSlave(){ myNewState=questionSlave;};
    void off(){ myNewState=questionOff;};
    void on(){ myNewState=questionOn;};
    boolean isSuccess(){ return mySelectedAnswer==myExpectedAnswer;}
};

