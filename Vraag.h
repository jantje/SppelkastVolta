/*
 * Vraag.h
 *
 *  Created on: 2021 Dec 30
 *      Author: jan
 */
#pragma once
#include "Arduino.h"
#define NUM_ANSWERS 4


class Vraag {
private:
	uint8_t myAnswerPins[NUM_ANSWERS];
	uint8_t myResultPin;
	uint8_t myLightPin;
	uint8_t myNewSelectedAnswer;
	uint8_t mySelectedAnswer;
	uint8_t myCurTestedPin;
	unsigned long myLastAction;
public:
	Vraag(uint8_t lightPin, uint8_t resultPin, uint8_t pin0, uint8_t pin1,
			uint8_t pin2, uint8_t pin3);
	void setup();
	void loop();
	virtual ~Vraag();
	uint8_t getSelectedAnswer() {
		return mySelectedAnswer;
	}
	;
};

