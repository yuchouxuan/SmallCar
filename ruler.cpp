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
        
		return  pulseIn(EchoPin, HIGH,TimeOut) / 5.8 -1;
		

}
int ruler::mm_avg3()
{
	int dis[3] = {mm(),mm(),mm()};
	long sum =dis[0] + dis[1]+dis[2];
	sum -=min(dis[0],min(dis[1], dis[2]));
	sum -=max(dis[0],max(dis[1],dis[2]));
	return int(sum);
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