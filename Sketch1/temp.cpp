#include "temp.h"

void Temperature::setInsideTemp(double param)
{
	InsideTemp = param;
}

void Temperature::setpastTempDiff(double param)
{
	pastTempDiff = param;
}

double Temperature::getInsideTemp()
{
	return InsideTemp;
}

double Temperature::getpastTempDiff()
{
	return pastTempDiff;
}
void Temperature::setnowTempDiff()
{
	this->nowTempDiff = getdht1_temp()-getdht2_temp();
}
double Temperature::getnowTempDiff()
{
	return nowTempDiff;
}

void Temperature::temperature()
{
	chk1 = DHT1.read11(DHT11_PIN1);
	chk2 = DHT2.read11(DHT11_PIN2);
	setnowTempDiff();
}


double Temperature::getdht1_temp()//benti érzékelõ
{
	return	DHT1.temperature;
}

double Temperature::getdht2_temp()//kinti érzékelõ
{
	return  DHT2.temperature;
}
