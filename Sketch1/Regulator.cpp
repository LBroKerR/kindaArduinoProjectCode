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
	if (getDoFunction())//�ppen az el�bb nyitott vagy csukott
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
				setDoFunction(false); // z�rva van
				setWindowsStatus(false);
			}
		}
	}
	else // nyitva/z�rva van �ppen
	{
		if (!getWindowsStatus() && now > 0)
		{
			setDoFunction(true);// �ppen nyitni fog
		}
		else
		{
			if ( getWindowsStatus() &&  now < 0)
			{
				setDoFunction(true); // �ppen csukni fog
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

