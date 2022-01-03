/*
 * Error.cpp
 *
 *  Created on: 2021 Dec 30
 *      Author: jan
 */

#include "Error.h"
#include "globals.h"

uint32_t getAnswer(uint8_t answer1, uint8_t answer2, uint8_t answer3,
		uint8_t answer4) {
	return (((((answer1<<8)+answer2)<<8)+answer3)<<8)+answer4;

}

Error::Error(uint8_t ledPin, uint32_t answers) {
	myLedPin=ledPin;
	myAnswers=answers;
	myCurLedState=LOW;
	myNewLedStae=LOW;
}

Error::~Error() {
}

void Error::loop() {
	if(myCurLedState!=myNewLedStae){
	digitalWrite(myLedPin, myNewLedStae);
	myCurLedState=myNewLedStae;
	}
}

void Error::setup() {
    //set the pinmode
	pinMode(myLedPin,OUTPUT);
	//blink the led
	digitalWrite(myLedPin, HIGH);
	delay(SETUP_LIGHT_ON_TIME);
	digitalWrite(myLedPin, myCurLedState);
}
