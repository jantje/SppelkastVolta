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

#define NUM_ERROS 4

class ErrorRij {
	private:
	Error* myErrors[NUM_ERROS];
	uint8_t myCurrentError;
	boolean myBlink;
	boolean myNewBlink;
	unsigned long myblinkPreviousMillis;
public:
	ErrorRij(Error* err1,Error* err2,Error* err3,Error* err4);
	virtual ~ErrorRij();
	void setup();
	void loop();
	void blink(boolean blink){myNewBlink=blink;};
};
