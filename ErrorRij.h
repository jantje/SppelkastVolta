/*
 * ErrorRij.h
 *
 *  Created on: 2022 Jan 2
 *      Author: jan
 */

#pragma once
#include "Arduino.h"
#include "Error.h"
#include "globals.h"



typedef enum
{
    errorOff,errorShowError
} ERROR_STATE;

class ErrorRij {
	private:
	Error* myErrors[NUM_ERROS];
	uint8_t myCurrentError=0;
	ERROR_STATE myState=errorShowError;
	ERROR_STATE myNewState=errorOff;
	unsigned long myblinkPreviousMillis=0;
	void switchToNewState();
public:
	ErrorRij(Error* err1,Error* err2,Error* err3,Error* err4);
	virtual ~ErrorRij();
	void setup();
	void loop();
	void showErrorNumber(){myNewState=errorShowError;};
	void off(){myNewState=errorOff;};
	uint8_t getExpectedAnswer(uint8_t questionIndex);
	void nextError();
};
