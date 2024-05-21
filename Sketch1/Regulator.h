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
	bool doFunction; //true, ha �ppen nyit- vagy csuk-ja az ablakot. false, ha z�rt vagy nyitott az ablak, �s nincs a bemeneten v�ltoz�s
	bool WindowsStatus; // true, ha nyitva van az ablak, false, ha z�rva van


public:
	void DoFunction(double, double);
	void preset();
	void setWindowsStatus(bool);
	void setDoFunction(bool);

	bool getDoFunction();
	bool getWindowsStatus();

};

#endif

