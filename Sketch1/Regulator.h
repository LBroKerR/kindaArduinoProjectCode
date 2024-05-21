// Regulator.h

#ifndef _REGULATOR_h
#define _REGULATOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "temp.h"
#include "servo.h"
class Regulator
{
	bool doFunction; //true, ha éppen nyit- vagy csuk-ja az ablakot. false, ha zárt vagy nyitott az ablak, és nincs a bemeneten változás
	bool WindowsStatus; // true, ha nyitva van az ablak, false, ha zárva van


public:
	void DoFunction(double, double);
	void preset();
	void setWindowsStatus(bool);
	void setDoFunction(bool);

	bool getDoFunction();
	bool getWindowsStatus();

};

#endif

