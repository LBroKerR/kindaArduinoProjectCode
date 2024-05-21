#include "servo.h"

void Servos::preset()
{
	setAngle(0);
	getMyServo1().attach(3); //11-ös pinre küldi ki a szervónak a jelet
	getMyServo2().attach(6);
	getMyServo1().write(180);
	getMyServo2().write(180);//alaphelyzetbe állítja a szervót
}

void Servos::setAngle(int param)
{
	angle = param;
}

int Servos::getAngle()
{
	return angle;
}


Servo Servos::getMyServo1()
{
	return MyServo1;
}

Servo Servos::getMyServo2()
{
	return MyServo2;
}

void Servos::Open()
{
	for(int angle=getAngle();angle !=180; angle++) //0-tól 180 fokig nyit fokonként
	{
		setAngle(angle);
		getMyServo1().write(angle);
		getMyServo2().write(angle);
		delay(15); //15 ms-ot vár mielőtt tovább fodulna
	}
}

void Servos::Close()
{
	for(int angle=getAngle(); angle !=0; angle--) //180 foktól 0 fokig forgat fokonként
	{
		setAngle(angle);
		getMyServo1().write(angle);
		getMyServo2().write(angle);
		delay(15);
	}
}