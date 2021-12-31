/*
 * Vraag.cpp
 *
 *  Created on: 2021 Dec 30
 *      Author: jan
 */

#include "Vraag.h"
extern unsigned long loopMillis;

Vraag::~Vraag() {
	// TODO Auto-generated destructor stub
}

Vraag::Vraag(uint8_t lightPin,uint8_t resultPin, uint8_t pin0, uint8_t pin1, uint8_t pin2,
		uint8_t pin3) {
	myAnswerPins[0] = pin0;
	myAnswerPins[1] = pin1;
	myAnswerPins[2] = pin2;
	myAnswerPins[3] = pin3;
	myResultPin = resultPin;
	myLightPin=lightPin;
	mySelectedAnswer = myNewSelectedAnswer = 0;
	myCurTestedPin = 0;
	myLastAction = loopMillis;
}

void Vraag::setup() {
	int curPin;
	for (curPin = 0; curPin < NUM_ANSWERS; curPin++) {
		pinMode(myAnswerPins[curPin], OUTPUT);
		digitalWrite(myAnswerPins[curPin], LOW);
	}
	pinMode(myResultPin, INPUT);
}



void Vraag::loop() {
	if (loopMillis - myLastAction > 10) {
		myLastAction = loopMillis;
		if (digitalRead(myCurTestedPin) == HIGH) {
			myNewSelectedAnswer |= 1 << (NUM_ANSWERS - myCurTestedPin);
		}

		digitalWrite(myAnswerPins[myCurTestedPin], LOW);
		if (++myCurTestedPin >= NUM_ANSWERS) {

			myCurTestedPin = 0;
			mySelectedAnswer = myNewSelectedAnswer;
			myNewSelectedAnswer = 0;
		}
		digitalWrite(myAnswerPins[myCurTestedPin], HIGH);
	}
}
