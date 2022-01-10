/*
 * globals.h
 *
 *  Created on: 2022 Jan 2
 *      Author: jan
 */

#pragma once
#include "Arduino.h"


#define NUM_ERROS 4
#define NUM_QUESTIONS 4
#define NUM_ANSWERS 4


//the time the lights need to turn on at boot time
#define SETUP_LIGHT_ON_TIME 300

#define BAKEN_ROOD_BLINK_ON_TIME 100
#define BAKEN_ROOD_BLINK_INTERVAL_TIME 300  //This is the sum of the on and off time

#define ERROR_BLINK_ON_TIME 200
#define ERROR_BLINK_INTERVAL_TIME 400  //This is the sum of the on and off time

#define ALARM_TRIGGER_TIME 500  //time to turn the alarm trigger on
#define SHOWING_RESULT_DURRATION  10000
#define SUCCESS_TRIGGER_TIME 1000

/*
 * method to calculate the new led state
 */
uint8_t calcLedState(unsigned long *previousMillis, uint16_t onTime, uint16_t interval) ;

extern unsigned long loopMillis;
