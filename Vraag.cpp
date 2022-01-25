/*
 * Vraag.cpp
 *
 *  Created on: 2021 Dec 30
 *      Author: jan
 */

#include "Vraag.h"
#include "globals.h"

Vraag::~Vraag() {
    // TODO Auto-generated destructor stub
}

Vraag::Vraag(char questionID, uint8_t lightPin, uint8_t resultPin, uint8_t pin0, uint8_t pin1, uint8_t pin2, uint8_t pin3) {
    myAnswerPins[0] = pin0;
    myAnswerPins[1] = pin1;
    myAnswerPins[2] = pin2;
    myAnswerPins[3] = pin3;
    myResultPin = resultPin;
    myLightPin = lightPin;
    myID = questionID;
    mySelectedAnswer = myNewSelectedAnswer = 0;
    myCurTestedPin = 0;
    myLastAction = loopMillis;
    myLastStateChange = loopMillis;
}

void Vraag::setup() {
    int curPin;
    for (curPin = 0; curPin < NUM_ANSWERS; curPin++) {
        pinMode(myAnswerPins[curPin], OUTPUT);
        digitalWrite(myAnswerPins[curPin], LOW);
    }
    pinMode(myResultPin, INPUT);
    pinMode(myLightPin, OUTPUT);
    digitalWrite(myLightPin, HIGH);
    delay(SETUP_LIGHT_ON_TIME);
    digitalWrite(myLightPin, LOW);

}

void Vraag::loop() {
    if (myNewState != myState) {
        switchToNewState();
    }
    if (loopMillis - myLastAction > 10) {
        myLastAction = loopMillis;
        if (digitalRead(myResultPin) == HIGH) {
            myNewSelectedAnswer += 1 << (NUM_ANSWERS - 1 - myCurTestedPin);
        }

        digitalWrite(myAnswerPins[myCurTestedPin], LOW);
        if (++myCurTestedPin >= NUM_ANSWERS) {
            if (mySelectedAnswer != myNewSelectedAnswer) {
                Serial.print("Vraag ");
                Serial.print(myID);
                Serial.print(" new answer! expected = ");
                Serial.print(myExpectedAnswer);
                Serial.print(" actual = ");
                Serial.println(myNewSelectedAnswer);
            }
            myCurTestedPin = 0;
            mySelectedAnswer = myNewSelectedAnswer;
            myNewSelectedAnswer = 0;
        }
        digitalWrite(myAnswerPins[myCurTestedPin], HIGH);
    }
    switch (myState) {
    case QuestionShowingResult:
        if (mySelectedAnswer == myExpectedAnswer) {
            myNewLedState = HIGH;
        } else {
            myNewLedState = LOW;
        }

        break;
    case questionOff:
    case questionOn:
    case questionSlave:
        //nothing to do here
        break;
    }
    if (myCurLedState != myNewLedState) {
        myCurLedState = myNewLedState;
        digitalWrite(myLightPin, myCurLedState);
    }
}

void Vraag::switchToNewState() {
    myLastStateChange = loopMillis;
    myState = myNewState;
    myCurLedState = LOW;
    myNewLedState = LOW;

    switch (myNewState) {
    case questionOn:
        myCurLedState = HIGH;
        myNewLedState = HIGH;
        Serial.print("Vraag ");
        Serial.print(myID);
        Serial.println(" switching to state on");
        break;
    case questionOff:
        Serial.print("Vraag ");
        Serial.print(myID);
        Serial.println(" switching to state off");
        break;
    case QuestionShowingResult:
        Serial.print("Vraag ");
        Serial.print(myID);
        Serial.println(" switching to state Showing Result.");
        break;
    case questionSlave:
        Serial.print("Vraag ");
        Serial.print(myID);
        Serial.println(" switching to state slave");
        break;
    }
    digitalWrite(myLightPin, myCurLedState);
}
