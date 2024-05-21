/*
 Name:		Sketch1.ino
 Created:	10/10/2022 8:24:54 PM
 Author:	rabai, kiss
*/

// plusz hőszivattyú leddel, plusz gomb,plusz beállított érték
#include "PushButton.h"
#include "Regulator.h"
#include "temp.h"
#include "servo.h"
#include "LiquidCrystal.h"
Temperature sensors;
Regulator regulation;
Servos servo;
LiquidCrystal lcd(13, 12, A0, A3, A2, A1);//??
PushButton button;

void setup() {
	Serial.begin(9600);
	lcd.begin(16, 2);
	sensors.setInsideTemp(21.0);
	sensors.setpastTempDiff(0.0);
	regulation.preset();
	servo.preset();
	pinMode(4, INPUT_PULLUP);
	pinMode(2, OUTPUT);
	button.setPushed(false);
}



void loop() {
	//TO DO
	// H�m�rs�klet �rz�kel�s
	// azok k�l�mbs�gei
	// motoros ablak nyit�s
	// LCD
	sensors.temperature();
	//Inside: xy.z°C
	//Outside: ab.c°C
	lcd.clear();
	lcd.setCursor(1,0);
	lcd.print("Inside:");
	lcd.println(sensors.getdht1_temp());
	lcd.print("C");
	lcd.setCursor(2, 0);
	lcd.print("Outside:");
	lcd.println(sensors.getdht2_temp());
	lcd.print("C");
	lcd.setCursor(1, 0);
	//Serial.println(sensors.getdht1_temp());
	//Serial.println(sensors.getdht2_temp());
	if (digitalRead(12))
	{
		//Serial.print("asd");
		lcd.clear();
		if (!button.getPushed())
		{
			if (!regulation.getWindowsStatus())
			{
				servo.Close(); //Ha az ablak nyitva van, akkor zárom
				regulation.setWindowsStatus(true);
				button.setPushed(true);
				lcd.print("Window opening");
				//Serial.print("Ablak nyílik\n");
				delay(10);
			}
			else
			{
				servo.Open();  //ellenkező esetben nyitom 
				regulation.setWindowsStatus(false);
				button.setPushed(true);
				lcd.print("Window Closing");
				//Serial.print("Ablak Záródni\n");
				delay(10);
			}
		}
		else
		{
			button.setPushed(false);
		}
	}
	else
	{
		if (!button.getPushed())
		{
			regulation.DoFunction(sensors.getpastTempDiff(), sensors.getnowTempDiff());
			if (regulation.getDoFunction() && sensors.getdht1_temp()> sensors.getInsideTemp())//ha true,akkor nyitni fog/z�rni.
			{
				lcd.clear();
				if (!regulation.getWindowsStatus())
				{
					servo.Close(); //Ha az ablak nyitva van, akkor zárom
					lcd.print("Window opening");
					//Serial.print("Ablak nyílik\n");
					delay(10);
				}
				else
				{
					servo.Open();  //ellenkező esetben nyitom 
					lcd.print("Window Closing");
					//Serial.print("Ablak Záródni\n");
					delay(10);
				}
			}
		}
	}
	if (sensors.getdht1_temp() < sensors.getInsideTemp())
	{
		digitalWrite(13, HIGH);
		delay(10);
	}
	else
	{
		digitalWrite(13, LOW);
		delay(10);
	}
	sensors.setpastTempDiff(sensors.getnowTempDiff());
	delay(1000);
}