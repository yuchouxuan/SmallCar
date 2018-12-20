#include <Arduino.h>
#include "ruler.h"
ruler::ruler()
{
	TrigPin= 27;
    EchoPin =26;
	TimeOut=50000;
	return;

}

void ruler::init()
{
	pinMode(TrigPin, OUTPUT);
	pinMode(EchoPin, INPUT);
	return;

}

void ruler::init(int e, int t)
{
	TrigPin = t;
	EchoPin = e;
	pinMode(TrigPin, OUTPUT);
	pinMode(EchoPin, INPUT);
	return;

}

void ruler::init(int e, int t,int timeout)
{ 
  TrigPin = t;
	EchoPin = e;
	TimeOut = timeout;
	pinMode(TrigPin, OUTPUT);
	pinMode(EchoPin, INPUT);
	return;
}

int ruler::mm()
{
		digitalWrite(TrigPin, LOW); 
        delayMicroseconds(2); 
        digitalWrite(TrigPin, HIGH); 
        delayMicroseconds(10);
        digitalWrite(TrigPin, LOW); 
        return  pulseIn(EchoPin, HIGH,TimeOut) / 5.8;
}

int ruler::mm_avg()
{
	int mms[AVG];
	long sum = 0;
	int avg = 0;
	int mmd[AVG];

	for(int i = 0; i< AVG;i++ )
	{ 
		mms[i] = mm();
	    sum += mms[i]; 
	}
	avg = sum / AVG;
	sum = 0;
	for(int i = 0; i < AVG; i++)
	{
		mmd[i] = abs(avg-mms[i]);
		sum +=mmd[i];
	}

	avg = sum / AVG;
	sum = 0;
    int count=0;
	for(int i = 0; i < AVG; i++)
	{
		if(mmd[i]<=avg) 
		{ 
			sum+=mms[i];
			count++;
		}
	}

	return sum / count;
}