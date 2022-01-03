/*
 * Error.h
 *
 *  Created on: 2021 Dec 30
 *      Author: jan
 */

#pragma once
#include "Arduino.h"
uint32_t getAnswer(uint8_t answer1, uint8_t answer2, uint8_t answer3,
		uint8_t answer4);

class Error {
private:
	uint8_t myLedPin;
	uint8_t myCurLedState;
	uint8_t myNewLedStae;
	uint32_t myAnswers;
public:
	/**
	 * answers is the binary concatenatination of all the answers
Created by the getAnswer method
	 */
	Error(uint8_t ledPin, uint32_t answers);
	virtual ~Error();
	void loop();
	void setup();
	void setLedState(uint8_t newLedState){myNewLedStae=newLedState;};
};

