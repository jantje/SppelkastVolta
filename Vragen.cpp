/*
 * Vragen.cpp
 *
 *  Created on: 2021 Dec 30
 *      Author: jan
 */

#include "Vragen.h"

Vragen::Vragen(Vraag* vraagA, Vraag* vraagB, Vraag* vraagC, Vraag* vraagD) {
	myQuestions[0]=vraagA;
	myQuestions[1]=vraagB;
	myQuestions[2]=vraagC;
	myQuestions[3]=vraagD;
}

Vragen::~Vragen() {
	// TODO Auto-generated destructor stub
}

void Vragen::loop() {
	for (int curQuestion = 0; curQuestion < NUM_ANSWERS; curQuestion++) {
		myQuestions[curQuestion]->loop();
	}
}

void Vragen::setup() {
	for (int curQuestion = 0; curQuestion < NUM_ANSWERS; curQuestion++) {
		myQuestions[curQuestion]->setup();
	}
}
