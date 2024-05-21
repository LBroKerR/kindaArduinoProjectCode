// temp.h

#ifndef _TEMP_h
#define _TEMP_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <dht.h>

#define DHT11_PIN1 11
#define DHT11_PIN2 10
class Temperature 
{
	double InsideTemp;
	dht DHT1/*k�ls�*/, DHT2;/*bels�*/
	int chk1, chk2;
	double pastTempDiff, nowTempDiff; // h�m�rs�klet k�l�bs�g.

public:
	void setInsideTemp(double);
	void setpastTempDiff(double param);
	void setnowTempDiff();
	void temperature();

	double getInsideTemp();
	double getpastTempDiff();
	double getnowTempDiff();
	double getdht1_temp();
	double getdht2_temp();
};

#endif

