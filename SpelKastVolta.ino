#include "Arduino.h"
#include "Vraag.h"
#include "Vragen.h"
#include "Error.h"
#include "ErrorRij.h"
#include "Brains.h"
#include "Baken.h"


Vraag vraagA('A',38,A0,22,23,24,25);
Vraag vraagB('B',39,A1,26,27,28,29);
Vraag vraagC('C',40,A2,30,31,32,33);
Vraag vraagD('D',41,A3,34,35,36,37);
Vragen vragenHoek(&vraagA,&vraagB,&vraagC,&vraagD);

Error error1(42,4,8,1,2);
Error error2(43,2,4,8,1);
Error error3(44,8,1,2,4);
Error error4(45,1,2,4,8);

ErrorRij errors(&error1,&error2,&error3,&error4);

Baken baken(46,47);
#define S1_pin 48
#define answersAreRight 49
#define triggerAlarm 50

Brains brains(S1_pin,answersAreRight,triggerAlarm);



unsigned long loopMillis;
void waitForSerial(){
//    while ((Serial.availableForWrite()+1)<=SERIAL_TX_BUFFER_SIZE){
//        delay(200);
//    }
}

void setup()
{
    Serial.begin(14400);
    delay(1000);
    Serial.println("Starting Spel Volta");
    waitForSerial();
	loopMillis=millis();
	baken.setup();
	Serial.println("baken setup done");
	waitForSerial();
	errors.setup();
	Serial.println("Error setup done");
	waitForSerial();
	vragenHoek.setup();
	Serial.println("VragenHoek setup done");
	waitForSerial();
	brains.setup();
	Serial.println("Brain setup done");
	waitForSerial();
	Serial.println("Setup done");
}

void loop()
{
	loopMillis=millis();
	vragenHoek.loop();
	waitForSerial();
	errors.loop();
	waitForSerial();
	baken.loop();
	waitForSerial();
	brains.loop();
	waitForSerial();
}
