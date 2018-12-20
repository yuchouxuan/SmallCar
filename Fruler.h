#ifndef _F_RULER_H__
#define _F_RULER_H__
#include "MySer.h"
#include "ruler.h"
class FRuler 
{    
    private:
    MySer ser;
    ruler ru;
    
    public:
    int serPin =10;
    int EchoPin =28;
    int TrigPin= 29;
    long TimeOut=1000000;
    //int angles[9]={20,50,60,70,90,110,130,150,180};
    int angles[9]={180,140,130,120,100,80,60,40,20};
    
        
    public:
    void setAngle(int a);
    int mm();
    void init();
    int mm_avg( );
};
#endif
