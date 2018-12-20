#include <Arduino.h>
#include "Fruler.h"

void FRuler::init()
{
	
	for(int i = 0; i <9 ; i++)
	{
		ser.angs[i] = angles[i];
	}
	//ser.rev = -1;
	ser.SerPin = 10;
	ser.init();
	ru.init(EchoPin,TrigPin,TimeOut);
}

int FRuler::mm()
	{
			return ru.mm();	
	}

void FRuler::setAngle(int a)
	{
		 
		 ser.setAngle(a);
	}

int FRuler::mm_avg()
{
	return ru.mm_avg();

}