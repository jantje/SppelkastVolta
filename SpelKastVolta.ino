#include "Arduino.h"
#include "Vraag.h"
#include "Vragen.h"
#include "Error.h"
#include "ErrorRij.h"
#include "Brains.h"
#include "Baken.h"


Vraag vraagA(38,A1,22,23,24,25);
Vraag vraagB(39,A2,26,27,28,29);
Vraag vraagC(40,A3,30,31,32,33);
Vraag vraagD(41,A4,34,35,36,37);
Vragen vragenHoek(&vraagA,&vraagB,&vraagC,&vraagD);

Error error1(42,getAnswer(4,8,1,2));
Error error2(43,getAnswer(2,4,8,1));
Error error3(44,getAnswer(8,1,2,4));
Error error4(45,getAnswer(1,2,4,8));

ErrorRij errors(&error1,&error2,&error3,&error4);

Baken baken(46,47);
#define S1_pin 48
#define answersAreRight 49
#define newError 50

Brains brains;



unsigned long loopMillis;

void setup()
{
	loopMillis=millis();
	baken.setup();
	errors.setup();
	vragenHoek.setup();

	brains.setup();
}

void loop()
{
	loopMillis=millis();
	vragenHoek.loop();
	errors.loop();
	baken.loop();
	brains.loop();
}
