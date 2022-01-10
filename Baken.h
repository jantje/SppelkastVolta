/*
 * Baken.h
 *
 *  Created on: 2022 Jan 2
 *      Author: jan
 */


#pragma once
#include "Arduino.h"

typedef enum
{
    bakenOff,bakenBlinkRed, bakenGreenOn
} BAKEN_STATE;

class Baken {
private:
	uint8_t myGreenPin;
	uint8_t myRedPin;
	uint8_t myRedLedSTate;
	unsigned long myblinkRedPreviousMillis;
	BAKEN_STATE myState=bakenBlinkRed;
	BAKEN_STATE myNewState=bakenOff;
	void switchToNewState();
public:
	Baken(uint8_t groenPin,uint8_t roodPin);
	virtual ~Baken();
	void setup();
	void loop();
	void blinkRed(){ myNewState=bakenBlinkRed;};
	void off(){ myNewState=bakenOff;};
	void green(){ myNewState=bakenGreenOn;};
};

