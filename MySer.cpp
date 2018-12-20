#include <Arduino.h>
#include "MySer.h"

MySer::MySer()
{
    SerPin = 11;
}


void MySer::init()
{
    myservo.attach(SerPin); 
    setAngle(0);
}

void MySer::setAngle(int a)
{
   ang = a * rev;
   if(ang > 4)  ang =4;
   if(ang < -4) ang =-4;
   myservo.write(angs[a+4]);  
}