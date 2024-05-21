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
	dht DHT1/*külsõ*/, DHT2;/*belsõ*/
	int chk1, chk2;
	double pastTempDiff, nowTempDiff; // hõmérséklet külöbség.

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

