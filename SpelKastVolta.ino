#include "Arduino.h"
#include "Vraag.h"
#include "Vragen.h"

#define toDecide 25

Vraag vraagA(38,toDecide,22,23,24,25);
Vraag vraagB(38,toDecide,22,23,24,25);
Vraag vraagC(38,toDecide,22,23,24,25);
Vraag vraagD(38,toDecide,22,23,24,25);
Vragen vragenHoek(&vraagA,&vraagB,&vraagC,&vraagD);
unsigned long loopMillis;

void setup()
{
	loopMillis=millis();
	vragenHoek.setup();
}

void loop()
{
	loopMillis=millis();
	vragenHoek.loop();
}
