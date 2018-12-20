
#ifndef _MOTER_H__
#define _MOTER_H__
class Moter 
{    
    public:
    int motA = 6;
    int motB = 7;
    int speed = 0;
   
        
    public:
    Moter(int pin1, int pin2);
    Moter();
    void init();
    void setSpeed(int sp);
   
};
#endif
