/*
 * Brains.cpp
 *
 *  Created on: 2022 Jan 2
 *      Author: jan
 */

#include "Brains.h"

Brains::Brains() {
	// TODO Auto-generated constructor stub

}

Brains::~Brains() {
	// TODO Auto-generated destructor stub
}

void Brains::setup() {
}

void Brains::loop() {
        baken.blinkRed(true);
        errors.blink(true);
}
