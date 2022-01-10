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
    if(myNewState!=myState){
        switchToNewState();
    }
	for (int curQuestion = 0; curQuestion < NUM_ANSWERS; curQuestion++) {
		myQuestions[curQuestion]->loop();
	}
    switch(myState){
    case vragenOff:
    case vragenOn:
    case showingResult:
        //nothing to do
        return;
    case pointingDown:
        static long int myStartPointingDown=0;
        int ledsOn= (loopMillis - myStartPointingDown) / 1000;
        if(ledsOn<NUM_ANSWERS){
            for (int curQuestion = 0; curQuestion <= ledsOn; curQuestion++) {
                myQuestions[curQuestion]->ledOn();
            }
        }else{
            myStartPointingDown=loopMillis+1000;
            for (int curQuestion = 0; curQuestion < NUM_ANSWERS; curQuestion++) {
                            myQuestions[curQuestion]->ledOff();
                        }
        }
        return;
    }
}

void Vragen::switchToNewState() {
    myState=myNewState;

    switch(myState){
    case vragenOff:
        for (int curQuestion = 0; curQuestion < NUM_ANSWERS; curQuestion++) {
            myQuestions[curQuestion]->off();
        }
        Serial.println("Vragen switching to state off");
        return;
    case vragenOn:
        for (int curQuestion = 0; curQuestion < NUM_ANSWERS; curQuestion++) {
            myQuestions[curQuestion]->on();
        }
        Serial.println("Vragen switching to state on");
        return;
        case showingResult:
        for (int curQuestion = 0; curQuestion < NUM_ANSWERS; curQuestion++) {
            uint8_t expectedAnswer= errors.getExpectedAnswer(curQuestion);
            myQuestions[curQuestion]->showResult( expectedAnswer);
        }
        Serial.println("Vragen switching to showing result");
        return;
    case pointingDown:
        for (int curQuestion = 0; curQuestion < NUM_ANSWERS; curQuestion++) {
            myQuestions[curQuestion]->beSlave();
        }
        Serial.println("Vragen switching to pointing down");
        return;
    }
}

void Vragen::setup() {
	for (int curQuestion = 0; curQuestion < NUM_ANSWERS; curQuestion++) {
		myQuestions[curQuestion]->setup();
	}
}

boolean Vragen::isSuccess() {
    boolean ret = true;
    for (int curQuestion = 0; curQuestion < NUM_ANSWERS; curQuestion++) {
       ret = ret &&  myQuestions[curQuestion]->isSuccess();
    }
    return ret;
}
