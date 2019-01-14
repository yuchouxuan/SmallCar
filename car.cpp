
#include "car.h"
void Car::init()
{
   // TCCR4B = TCCR4B & B11111000 | B00000100; 
    mot.init();
    fru.init(26,27,18000);
    ser.init();
    fruS.init();

    setSpeed(0);
    setAngle(0);
    setFRAngle(0);
    delay(200);
}

Car::Car()
{}
void Car::setSpeed(int sp)
{
    int fx = 1;
    if(sp < 0 ) fx = -1;
    
    mot.setSpeed(0);
      if(sp == 0 ) return ;
    
    int speed = getSpeed();
    if(sp * speed < 0 ) return;

    if(speed == -32767)
    { mot.setSpeed(40*fx);return;}
    

    int dsp = abs(sp) -abs(speed);
    
    if( dsp > 0   )
      {
        if((abs(dsp) > abs(sp)/4 ))
          {mot.setSpeed(30*fx);}
        if((abs(dsp) > abs(sp)/2 ))
          {mot.setSpeed(80*fx);}
        if((abs(dsp) > abs(sp)*0.75))
          {mot.setSpeed(100*fx);}
      }
    else
    {
        mot.setSpeed(0);
    }

    


}
void Car::setAngle(int ag)
{ser.setAngle(ag);}

void Car::setFRAngle(int ag)
{fruS.setAngle(ag);}

int Car::Fmm()
{return fru.mm_avg3();}

int Car::getSpeed()
{
    int x = SpeedNow();
    if (x <= 10 && x >= -10)  return 0 ;
    
    return x;


}

int Car::SpeedNow()
{
    int sp1 = Fmm();
    if(sp1 < 0)
    {
      return -32767;
    }
    delay(50);
    
    return sp1 -Fmm() ; 
}

void Car::printInf()
{
  Serial.print(Fmm());
  Serial.print(":");
  Serial.println(getSpeed());

}