/*
 * Vragen.h
 *
 *  Created on: 2021 Dec 30
 *      Author: jan
 */
#pragma once
#include "Arduino.h"
#include "Vraag.h"

#define NUM_QUESTIONS 4

class Vragen {
private:
	Vraag* myQuestions[NUM_QUESTIONS];

public:
	Vragen(Vraag* vraagA,Vraag* vraagB,Vraag* vraagC,Vraag* vraagD);
	virtual ~Vragen();
	void loop();
	void setup();
};

