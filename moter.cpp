
#include <Arduino.h>
#include "Moter.h"

void Moter::setSpeed(int sp)
{
	speed = sp;
	if (sp ==0)
  {
    analogWrite(motA, 0);
    analogWrite(motB, 0);
  }

  if (sp > 0)
  {
    if (sp > 255) sp = 255;
    analogWrite(motA, 0);
    analogWrite(motB, sp);
  }
  
  if (sp < 0)
  {
    if (sp < -255) sp = -255;
    analogWrite(motB, 0);
    analogWrite(motA, -sp);
  }
}



Moter::Moter()
{
   motA = 6;
   motB = 7;
}
Moter::Moter(int pin1,int pin2)
{
  motA = pin1;
  motB = pin2;
  setSpeed(0);
}
void Moter::init()
{
  
  setSpeed(0);
}