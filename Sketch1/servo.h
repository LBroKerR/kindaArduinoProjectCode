// Regulator.h

#ifndef _SERVOS_h
#define _SERVOS_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#include "Servo-1.1.8/Servo-1.1.8/src/Servo.h"

class Servos
{
	int angle;
	Servo MyServo1, MyServo2;
	int getAngle();
	void setAngle(int);
	Servo getMyServo1();
	Servo getMyServo2();
public:
	void preset();
	void Open();
	void Close();
};

#endif