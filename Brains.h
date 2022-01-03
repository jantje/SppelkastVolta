/*
 * Brains.h
 *
 *  Created on: 2022 Jan 2
 *      Author: jan
 */

#pragma once
#include "Arduino.h"
#include "Baken.h"
#include "ErrorRij.h"
extern Baken baken;
extern ErrorRij errors;

class Brains {
public:
	Brains();
	virtual ~Brains();
	void setup();
	void loop();
};

