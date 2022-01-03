/*
 * Baken.h
 *
 *  Created on: 2022 Jan 2
 *      Author: jan
 */


#pragma once
#include "Arduino.h"

class Baken {
private:
	uint8_t myGreenPin;
	uint8_t myRedPin;
	boolean myBlinkRed;
	boolean  mynewBlinkRed;
	uint8_t myRedLedSTate;
	unsigned long myblinkRedPreviousMillis;
public:
	Baken(uint8_t groenPin,uint8_t roodPin);
	virtual ~Baken();
	void setup();
	void loop();
	void blinkRed(boolean newBlinkRed){ mynewBlinkRed=newBlinkRed;};
};

