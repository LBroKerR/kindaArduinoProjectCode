// 
// 
// 

#include "Regulator.h"

void Regulator::setWindowsStatus(bool param)
{
	WindowsStatus = param;
}

void Regulator::setDoFunction(bool param)
{
	doFunction = param;
}

void Regulator::DoFunction(double past, double now)
{
	if (getDoFunction())//éppen az elöbb nyitott vagy csukott
	{
		if ( past> 0 &&  now> 0)
		{
			setDoFunction(false); //nyitva van
			setWindowsStatus(true);
		}
		else
		{
			if ( past < 0 &&  now < 0)
			{
				setDoFunction(false); // zárva van
				setWindowsStatus(false);
			}
		}
	}
	else // nyitva/zárva van éppen
	{
		if (!getWindowsStatus() && now > 0)
		{
			setDoFunction(true);// éppen nyitni fog
		}
		else
		{
			if ( getWindowsStatus() &&  now < 0)
			{
				setDoFunction(true); // éppen csukni fog
			}
		}
	}
}

void Regulator::preset()
{
	setDoFunction(false);
	setWindowsStatus(false);
}

bool Regulator::getDoFunction()
{
	return doFunction;
}

bool Regulator::getWindowsStatus()
{
	return WindowsStatus;
}

