// PushButton.h

#ifndef _PUSHBUTTON_h
#define _PUSHBUTTON_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class PushButton
{
	bool pushed;

 public:
	 void setPushed(bool);
	 bool getPushed();
};


#endif

